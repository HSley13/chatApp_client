db.students.insertOne(
    {
        name: "Larry",
        age: 32,
        gpa: 2.8,
        fullTime: false,
        registerDate: new Date(),
        graduationDate: null,
        courses: [
            "Biology",
            "Chemistry",
            "Calculus"
        ],
        address: {
            street: "123 Fake St.",
            city: "Bikini Bottom",
            zip: 12345
        }
    }
)