// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BloodBank {

    struct BloodInfo {
        string location;
        uint stock;
        bool exists;
    }

    // Mapping blood type => details
    mapping(string => BloodInfo) private bloodData;

    // Add a new blood type with initial location & stock
    function addBloodType(string memory _bloodType, string memory _location, uint _initialStock) public {
        require(!bloodData[_bloodType].exists, "Blood type already exists");
        bloodData[_bloodType] = BloodInfo(_location, _initialStock, true);
    }

    // Get the location of a blood type
    function getLocation(string memory _bloodType) public view returns (string memory) {
        require(bloodData[_bloodType].exists, "Blood type not found");
        return bloodData[_bloodType].location;
    }

    // Set / Change the location for a blood type
    function setLocation(string memory _bloodType, string memory _newLocation) public {
        require(bloodData[_bloodType].exists, "Blood type not found");
        bloodData[_bloodType].location = _newLocation;
    }

    // Get current stock of a blood type
    function getStock(string memory _bloodType) public view returns (uint) {
        require(bloodData[_bloodType].exists, "Blood type not found");
        return bloodData[_bloodType].stock;
    }

    // Set the stock to a specific number
    function setStock(string memory _bloodType, uint _newStock) public {
        require(bloodData[_bloodType].exists, "Blood type not found");
        bloodData[_bloodType].stock = _newStock;
    }

    // Increase stock by given amount
    function increaseStock(string memory _bloodType, uint _amount) public {
        require(bloodData[_bloodType].exists, "Blood type not found");
        bloodData[_bloodType].stock += _amount;
    }

    // Decrease stock by given amount
    function decreaseStock(string memory _bloodType, uint _amount) public {
        require(bloodData[_bloodType].exists, "Blood type not found");
        require(bloodData[_bloodType].stock >= _amount, "Not enough stock available");
        bloodData[_bloodType].stock -= _amount;
    }
}
