#include "parser.h"

omfl::argument omfl::argument::Get(const std::string &arg) {
    argument tmp;
    return tmp;
}

bool omfl::argument::IsInt() const {
    return IsInt_;
}

int omfl::argument::AsInt() const {
    return 0;
}

int omfl::argument::AsIntOrDefault(int key) const {
    return 0;
}

bool omfl::argument::IsFloat() const {
    return IsFloat_;
}

float omfl::argument::AsFloat() const {
    return 0;
}

float omfl::argument::AsFloatOrDefault(float key) const {
    return 0;
}

bool omfl::argument::IsString() const {
    return IsString_;
}

std::string omfl::argument::AsString() const {
    return std::string();
}

std::string omfl::argument::AsStringOrDefault(const std::string &key) const {
    return std::string();
}

bool omfl::argument::IsArray() const {
    return IsArray_;
}

const omfl::argument &omfl::argument::operator[](size_t index) const {
    argument tmp;
    return tmp;
}

bool omfl::argument::IsBool() const {
    return IsBool_;
}

bool omfl::argument::AsBool() const {
    return false;
}

omfl::argument::argument(const omfl::argument& argument1) {

}

int omfl::getArgumentType(const std::string &arg) {
    if ((arg[0] <= '9' && arg[0] >= '0') || arg[0] == '+' || arg[0] == '-') {
        int DotCount = 0;
        for (int i = 1; i < arg.length(); ++i) {
            if ((arg[i] <= '9' && arg[i] >= '0') || arg[i] == '.') {
                if (arg[i] == '.' && !(arg[i - 1] <= '9' && arg[i - 1] >= '0')) {
                    return -1;
                }
                if (arg[i] == '.') {
                    DotCount += 1;
                }
            } else {
                return -1;
            }
        }
        if (DotCount == 0) {
            return 1;
        } else if (DotCount == 1) {
            return 2;
        } else {
            return -1;
        }
    } else if (arg[0] == '"') {
        if (arg[arg.length() - 1] == '"') {
            return 3;
        } else {
            return -1;
        }
    } else if (arg[0] == '[') {
        if (arg[arg.length() - 1] == ']') {
            return 4;
        } else {
            return -1;
        }
    } else if (arg == "true" || arg == "false") {
        return 5;
    } else
        return -1;
}

/*
 * 1 - int
 * 2 - float
 * 3 - string
 * 4 - array
 * 5 - bool
 * -1 - not valid
 */

omfl::argument omfl::parser::Get(const std::string &key) const {
    return omfl::argument();
}




omfl::parser omfl::parse(const std::string &str) {
    omfl::parser prs;
    std::stringstream fin(str);
    std::string line;
    while(getline(fin, line)){
        delete_spaces(line);
        if(line[0] == '['){
            std::string section;
            for (int i = 1; i < line.length(); ++i) {
                if(line[i] == '.'){
                    for (int j = 0; j < prs.primary_section.size(); ++j) {
                        if(prs.primary_section[i].GetName() == section){
                            argument *newArg = new argument(section);

                        } else {

                        }
                    }
                }
                section.push_back(line[i]);
            }

        }
    }
    vector<std::string> tokens;
    split_string(str, '=', tokens, 1);

    return prs;
}

omfl::parser omfl::parse(const std::filesystem::path &path) {
    return omfl::parser();
}

void omfl::split_string(const std::string &str, char c, vector<std::string> &result, size_t n) {
    std::stringstream line(str);
    std::string s;
    if (n == 0) {
        while (getline(line, s, c)) {
            result.push_back(s);
        }
    } else {
        bool f = true;
        for (int i = 0; i < n; ++i) {
            getline(line, s, c);
            result.push_back(s);
            if(line.eof())
                return;
        }
        getline(line, s, '\0');
        result.push_back(s);
    }
}

void omfl::delete_spaces(std::string &str) {
    size_t beg = 0;
    size_t end = str.length() - 1;
    for (beg; str[beg] == ' '; ++beg);
    for (end; str[end] == ' '; --end);
    str = str.substr(beg, end - beg + 1);
}
