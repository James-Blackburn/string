#ifndef _LIB_STRING
#define _LIB_STRING

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

namespace lib{

    class string{
    public:
        typedef size_t size_type;
        typedef char* iterator;
    private:
        char* internal_string;
        size_type string_length;
        size_type get_string_length(const char*);
        void reallocate(const char*);
        void reallocate(const string&);
    public:
        string();
        string(const char*);
        string(const string&);
        ~string();
        inline size_type size() const;
        inline iterator begin();
        inline iterator end();
        inline char& front();
        inline char& back();
        inline const iterator cbegin() const;
        inline const iterator cend() const;
        inline void operator=(const char*);
        inline void operator=(const string&);
        inline char& operator[](size_type);
        inline friend std::ostream& operator<<(std::ostream&, string&);
    };

    string::string() :
        internal_string(nullptr),string_length(0){
    }

    string::string(const char* _string){
        reallocate(_string);
    }

    string::string(const string& _string){
        reallocate(_string);
    }

    string::~string(){
        delete[] internal_string;
    }

    string::size_type string::get_string_length(const char* _string){
        size_type _string_length = 0;
        while (_string[_string_length]!='\0'){
            ++_string_length;
        }
        return _string_length;
    }

    void string::reallocate(const char* _string){
        string_length = get_string_length(_string);
        internal_string = new char[string_length+1];
        for (size_type i=0; i<string_length; i++){
            internal_string[i] = _string[i];
        }
        internal_string[string_length] = '\0';
    }

    void string::reallocate(const string& _string){
        string_length = _string.string_length;
        internal_string = new char[string_length+1];
        for (size_type i=0; i<string_length; i++){
            internal_string[i] = _string.internal_string[i];
        }
        internal_string[string_length] = '\0';
    }

    inline string::iterator string::begin(){
        return internal_string;
    }

    inline string::iterator string::end(){
        return internal_string+string_length;
    }

    inline const string::iterator string::cbegin() const{
        return internal_string;
    }

    inline const string::iterator string::cend() const{
        return internal_string+string_length;
    }

    inline char& string::front(){
        return internal_string[0];
    }

    inline char& string::back(){
        return internal_string[string_length-1];
    }

    inline string::size_type string::size() const{
        return string_length;
    }

    inline char& string::operator[](size_type position){
        return internal_string[position];
    }

    inline void string::operator=(const char* _string){
        reallocate(_string);
    }

    inline void string::operator=(const string& _string){
        reallocate(_string);
    }

    inline std::ostream& operator<<(std::ostream& out, string& str){
        return out << str.internal_string;
    }
}
#endif // _LIB_STRING INCLUDED
