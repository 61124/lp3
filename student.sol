// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        uint id;
        string name;
        string course;
    }

    Student[] public students;

    // Track used IDs
    mapping(uint => bool) private idExists;

    // Modifier to ensure unique ID
    modifier uniqueId(uint _id) {
        require(!idExists[_id], "Student with this ID already exists");
        _;
    }

    // Add new student only if ID not used before
    function addStudent(uint _id, string memory _name, string memory _course) public uniqueId(_id) {
        students.push(Student(_id, _name, _course));
        idExists[_id] = true;
    }

    function getStudent(uint index) public view returns (uint, string memory, string memory) {
        require(index < students.length, "Student index out of range");
        Student memory student = students[index];
        return (student.id, student.name, student.course);
    }

    function getStudentById(uint _id) public view returns (string memory, string memory) {
        for (uint i = 0; i < students.length; i++) {
            if (students[i].id == _id) {
                return (students[i].name, students[i].course);
            }
        }
        revert("Student not found");
    }

    function getAllStudents() public view returns (Student[] memory) {
        return students;
    }

    function getStudentsByIds(uint[] memory _ids) public view returns (Student[] memory) {
        Student[] memory result = new Student[](_ids.length);
        for (uint i = 0; i < _ids.length; i++) {
            bool found = false;
            for (uint j = 0; j < students.length; j++) {
                if (students[j].id == _ids[i]) {
                    result[i] = students[j];
                    found = true;
                    break;
                }
            }
            require(found, "One or more IDs not found");
        }
        return result;
    }

    function getTotalStudents() public view returns (uint) {
        return students.length;
    }

    fallback() external payable {
        revert("Function does not exist!");
    }

    receive() external payable {}
}
