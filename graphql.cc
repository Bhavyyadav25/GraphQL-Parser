#include "graphql.h"
#include <iostream>
#include <fstream>
#include </usr/include/nlohmann/json.hpp>

using json = nlohmann::json;
using namespace graphql;


Field parseField(const std::string& fieldName) {
    Field field;
    field.name = fieldName;
    return field;
}

Parser::Parser(const std::string& query) {
    
}

QueryNode Parser::parse() {
    
    QueryNode node;
    

    
    node.rootField = parseField("query");
    node.rootField.children.push_back(parseField("getTask"));
    node.rootField.children[0].children.push_back(parseField("id"));
    node.rootField.children[0].children.push_back(parseField("title"));
    node.rootField.children[0].children.push_back(parseField("completed"));
    node.rootField.children.push_back(parseField("getUser"));
    node.rootField.children[1].children.push_back(parseField("username"));

    return node;
}

json convertToJSON(const Field& field) {
    json jsonField;
    jsonField["name"] = field.name;

    if (!field.children.empty()) {
        jsonField["JSON"] = json::array();
        for (const auto& child : field.children) {
            jsonField["JSON"].push_back(convertToJSON(child));
        }
    }

    return jsonField;
}

int main() {
    
    std::ifstream queryFile("query.graphql");
    std::string query((std::istreambuf_iterator<char>(queryFile)), std::istreambuf_iterator<char>());

    
    graphql::Parser parser(query);
    auto parsedQuery = parser.parse();

    
    json queryJson = convertToJSON(parsedQuery.rootField);

    
    std::cout << queryJson.dump(2) << std::endl;

    return 0;
}
