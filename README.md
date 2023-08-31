# GraphQL-Parser
A simple GraphQL parser written in C++. This parser can parse GraphQL queries and convert them to JSON.

#Features
-Parsing GraphQL queries
-Converting GraphQL queries to JSON
-Handling errors
-Handling nested queries
-Handling variables

#Requirements
-C++11 compiler
-nlohmann/json library

#Installation

git clone [https://github.com/[your-username]/graphql-parser](https://github.com/Bhavyyadav25/GraphQL-Parser).git
cd GraphQL-Parser
cmake .
make

#Usage
./graphql-parser <query.graphql>

This will parse the GraphQL query in query.graphql and print the JSON representation of the query to the console.

#Example

query {
  getTask(id: "0x3") {
    id
    title
    completed
  }
  getUser(username: "dgraphlabs") {
    username
  }
}

This is a valid GraphQL query that can be parsed by the parser. The output of the parser will be the following JSON:

{
  "JSON": [
    {
      "JSON": [
        {
          "name": "id"
        },
        {
          "name": "title"
        },
        {
          "name": "completed"
        }
      ],
      "name": "getTask"
    },
    {
      "JSON": [
        {
          "name": "username"
        }
      ],
      "name": "getUser"
    }
  ],
  "name": "query"
}

#Documentation
The documentation for the parser can be found in the README.md: README.md file.

#Contributing
Contributions are welcome! Please open an issue or submit a pull request if you have any improvements or bug fixes.

#License
The parser is licensed under the MIT License. See the LICENSE: LICENSE file for more information.
