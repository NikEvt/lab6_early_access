#include <iostream>
#include <filesystem>
#include <sstream>
#include "vector.h"
namespace omfl {
    int getArgumentType(const std::string& arg);
    void delete_spaces(std::string& str);
    void split_string(const std::string& str, char c, vector<std::string>& result, size_t n);

    class argument{
    public:
        std::string name;

        argument Get(const std::string& arg);

        bool IsInt() const;

        int AsInt() const;

        int AsIntOrDefault(int key) const;

        bool IsFloat() const;

        float AsFloat() const;

        float AsFloatOrDefault(float key) const;

        bool IsString() const;

        std::string AsString() const;

        std::string AsStringOrDefault(const std::string &key) const;

        bool IsArray() const;

        const argument& operator[](size_t index) const;

        bool IsBool() const;

        bool AsBool() const;

    private:
        bool IsValid_ = true;
        bool IsInt_ = false;
        bool IsFloat_ = false;
        bool IsString_ = false;
        bool IsArray_ = false;
        bool IsBool_ = false;
    };

    class parser {
    public:
        bool IsValid = true;

        bool valid() const{
            return IsValid;
        }
        argument Get(const std::string& key) const;

        parser() = default;

        parser(parser &other){
            this->IsValid = other.IsValid;
            this->primary_section = other.primary_section;
        }
        parser& operator=(parser&& other){
            this->IsValid = other.IsValid;
            this->primary_section = other.primary_section;
        }
        argument primary_section;



    };

    parser parse(const std::string& str);

    parser parse(const std::filesystem::path& path);

}