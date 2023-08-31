#ifndef GRAPHQL_H
#define GRAPHQL_H

#include <string>
#include <vector>
#include <map>

namespace graphql {

    struct Field {
        std::string name;
        std::vector<Field> children;
    };

    class QueryNode {
    public:
        std::string operationName;
        Field rootField;
    };

    class Parser {
    public:
        Parser(const std::string& query);
        QueryNode parse();
    };

} 

#endif 
