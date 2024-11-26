#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include "../config.h"

using namespace std;

class alignas(8) M_base
{
    public:
        inline void set_metadata_ptr(Metadata* ptr){
            metadata_ptr = ptr;
        }
        inline Metadata* get_metadata_ptr(){
            return metadata_ptr;
        }
        virtual ~M_base() = default;
    
    private:
        Metadata* metadata_ptr;
};

class alignas(8) M1 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 35,
        E1_CONST_2 = 7,
        E1_CONST_3 = 77,
        E1_CONST_4 = 15,
        E1_CONST_5 = 53,
    };
    
    class alignas(8) M2 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(string val){
            f2 = val;
        }
        inline string& get_f2(){
            return f2;
        }
    
        inline void set_f3(int64_t val){
            f3 = val;
        }
        inline int64_t& get_f3(){
            return f3;
        }
    
        inline void set_f4(string val){
            f4 = val;
        }
        inline string& get_f4(){
            return f4;
        }
    
        inline void set_f5(string val){
            f5 = val;
        }
        inline string& get_f5(){
            return f5;
        }
    
        inline void set_f6(string val){
            f6 = val;
        }
        inline string& get_f6(){
            return f6;
        }
    
        inline void set_f7(string val){
            f7 = val;
        }
        inline string& get_f7(){
            return f7;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M2->f1: " << f1 << std::endl;
            fout << "M2->f2: " << f2 << std::endl;
            fout << "M2->f3: " << f3 << std::endl;
            fout << "M2->f4: " << f4 << std::endl;
            fout << "M2->f5: " << f5 << std::endl;
            fout << "M2->f6: " << f6 << std::endl;
            fout << "M2->f7: " << f7 << std::endl;
        }
    
        ~M2(){
        }
    
        M2(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) string f2;
        alignas(8) int64_t f3;
        alignas(8) string f4;
        alignas(8) string f5;
        alignas(8) string f6;
        alignas(8) string f7;
    };


    inline void set_f1(string val){
        f1 = val;
    }
    inline string& get_f1(){
        return f1;
    }

    inline void set_f2(bool val){
        f2 = val;
    }
    inline bool& get_f2(){
        return f2;
    }

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
        return f3;
    }

    inline void set_f4(bool val){
        f4 = val;
    }
    inline bool& get_f4(){
        return f4;
    }

    inline void set_f5(string val){
        f5 = val;
    }
    inline string& get_f5(){
        return f5;
    }

    inline void set_f6(int32_t val){
        f6 = val;
    }
    inline int32_t& get_f6(){
        return f6;
    }

    inline M2* mutable_f7(){
        f7 = new M2();
        return f7;
    }
    inline M2*& get_f7(){
        return f7;
    }

    inline void set_f8(int32_t val){
        f8 = val;
    }
    inline int32_t& get_f8(){
        return f8;
    }

    inline void set_f9(E1 val){
        f9 = val;
    }
    inline E1& get_f9(){
        return f9;
    }

    inline void set_f10(string val){
        f10 = val;
    }
    inline string& get_f10(){
        return f10;
    }

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
        return f11;
    }

    inline void set_f12(string val){
        f12 = val;
    }
    inline string& get_f12(){
        return f12;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M1->f1: " << f1 << std::endl;
        fout << "M1->f2: " << f2 << std::endl;
        fout << "M1->f3: " << f3 << std::endl;
        fout << "M1->f4: " << f4 << std::endl;
        fout << "M1->f5: " << f5 << std::endl;
        fout << "M1->f6: " << f6 << std::endl;
        if(f7 != nullptr)
            f7->print_message(fout);
        fout << "M1->f8: " << f8 << std::endl;
        fout << "M1->f9: " << f9 << std::endl;
        fout << "M1->f10: " << f10 << std::endl;
        fout << "M1->f11: " << f11 << std::endl;
        fout << "M1->f12: " << f12 << std::endl;
    }

    ~M1(){
        if(f7 != nullptr)
            delete f7;
    }

    M1(){
       f7 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) bool f2;
    alignas(8) string f3;
    alignas(8) bool f4;
    alignas(8) string f5;
    alignas(8) int32_t f6;
    alignas(8) M2* f7;
    alignas(8) int32_t f8;
    alignas(8) E1 f9;
    alignas(8) string f10;
    alignas(8) int64_t f11;
    alignas(8) string f12;
};


class alignas(8) M3 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 69,
        E1_CONST_2 = 122,
        E1_CONST_3 = 10,
        E1_CONST_4 = 9754,
        E1_CONST_5 = 27,
    };
    
    enum E2 {
        E2_CONST_1 = 9,
        E2_CONST_2 = 42,
        E2_CONST_3 = 81,
        E2_CONST_4 = 50,
        E2_CONST_5 = 31,
    };
    
    class alignas(8) M4 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint64_t val){
            f2 = val;
        }
        inline uint64_t& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M4->f1: " << f1 << std::endl;
            fout << "M4->f2: " << f2 << std::endl;
        }
    
        ~M4(){
        }
    
        M4(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) uint64_t f2;
    };


    class alignas(8) M5 : public M_base
    {
    public:
        inline void add_f1(int32_t val){
            f1.push_back(val);
        }
        inline int32_t& get_f1(int idx){
            return f1[idx];
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            for(auto &f1_val : f1){
                fout << "M5->f1: " << f1_val << std::endl;
            }
            fout << "M5->f2: " << f2 << std::endl;
        }
    
        ~M5(){
        }
    
        M5(){
        }
    
    private:
        alignas(8) std::vector<int32_t> f1;
        alignas(8) int32_t f2;
    };


    class alignas(8) M6 : public M_base
    {
    public:
        inline void set_f1(bool val){
            f1 = val;
        }
        inline bool& get_f1(){
            return f1;
        }
    
        inline void set_f2(bool val){
            f2 = val;
        }
        inline bool& get_f2(){
            return f2;
        }
    
        inline void set_f3(int64_t val){
            f3 = val;
        }
        inline int64_t& get_f3(){
            return f3;
        }
    
        inline void set_f4(int32_t val){
            f4 = val;
        }
        inline int32_t& get_f4(){
            return f4;
        }
    
        inline void set_f5(uint64_t val){
            f5 = val;
        }
        inline uint64_t& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M6->f1: " << f1 << std::endl;
            fout << "M6->f2: " << f2 << std::endl;
            fout << "M6->f3: " << f3 << std::endl;
            fout << "M6->f4: " << f4 << std::endl;
            fout << "M6->f5: " << f5 << std::endl;
        }
    
        ~M6(){
        }
    
        M6(){
        }
    
    private:
        alignas(8) bool f1;
        alignas(8) bool f2;
        alignas(8) int64_t f3;
        alignas(8) int32_t f4;
        alignas(8) uint64_t f5;
    };


    inline void set_f1(int64_t val){
        f1 = val;
    }
    inline int64_t& get_f1(){
        return f1;
    }

    inline void set_f2(bool val){
        f2 = val;
    }
    inline bool& get_f2(){
        return f2;
    }

    inline void set_f3(E1 val){
        f3 = val;
    }
    inline E1& get_f3(){
        return f3;
    }

    inline void set_f4(string val){
        f4 = val;
    }
    inline string& get_f4(){
        return f4;
    }

    inline void set_f5(string val){
        f5 = val;
    }
    inline string& get_f5(){
        return f5;
    }

    inline M4* mutable_f6(){
        f6 = new M4();
        return f6;
    }
    inline M4*& get_f6(){
        return f6;
    }

    inline void set_f7(string val){
        f7 = val;
    }
    inline string& get_f7(){
        return f7;
    }

    inline void set_f8(E2 val){
        f8 = val;
    }
    inline E2& get_f8(){
        return f8;
    }

    inline void set_f9(int32_t val){
        f9 = val;
    }
    inline int32_t& get_f9(){
        return f9;
    }

    inline void set_f10(int32_t val){
        f10 = val;
    }
    inline int32_t& get_f10(){
        return f10;
    }

    inline M5* mutable_f11(){
        f11 = new M5();
        return f11;
    }
    inline M5*& get_f11(){
        return f11;
    }

    inline void set_f12(int64_t val){
        f12 = val;
    }
    inline int64_t& get_f12(){
        return f12;
    }

    inline void set_f13(int64_t val){
        f13 = val;
    }
    inline int64_t& get_f13(){
        return f13;
    }

    inline M6* mutable_f14(){
        f14 = new M6();
        return f14;
    }
    inline M6*& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M3->f1: " << f1 << std::endl;
        fout << "M3->f2: " << f2 << std::endl;
        fout << "M3->f3: " << f3 << std::endl;
        fout << "M3->f4: " << f4 << std::endl;
        fout << "M3->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        fout << "M3->f7: " << f7 << std::endl;
        fout << "M3->f8: " << f8 << std::endl;
        fout << "M3->f9: " << f9 << std::endl;
        fout << "M3->f10: " << f10 << std::endl;
        if(f11 != nullptr)
            f11->print_message(fout);
        fout << "M3->f12: " << f12 << std::endl;
        fout << "M3->f13: " << f13 << std::endl;
        if(f14 != nullptr)
            f14->print_message(fout);
    }

    ~M3(){
        if(f6 != nullptr)
            delete f6;
        if(f11 != nullptr)
            delete f11;
        if(f14 != nullptr)
            delete f14;
    }

    M3(){
       f6 = nullptr;
       f11 = nullptr;
       f14 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) bool f2;
    alignas(8) E1 f3;
    alignas(8) string f4;
    alignas(8) string f5;
    alignas(8) M4* f6;
    alignas(8) string f7;
    alignas(8) E2 f8;
    alignas(8) int32_t f9;
    alignas(8) int32_t f10;
    alignas(8) M5* f11;
    alignas(8) int64_t f12;
    alignas(8) int64_t f13;
    alignas(8) M6* f14;
};


class alignas(8) M7 : public M_base
{
public:
    class alignas(8) M8 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(bool val){
            f2 = val;
        }
        inline bool& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M8->f1: " << f1 << std::endl;
            fout << "M8->f2: " << f2 << std::endl;
        }
    
        ~M8(){
        }
    
        M8(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) bool f2;
    };


    inline void set_f1(string val){
        f1 = val;
    }
    inline string& get_f1(){
        return f1;
    }

    inline void set_f2(int32_t val){
        f2 = val;
    }
    inline int32_t& get_f2(){
        return f2;
    }

    inline M8* mutable_f3(){
        f3 = new M8();
        return f3;
    }
    inline M8*& get_f3(){
        return f3;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M7->f1: " << f1 << std::endl;
        fout << "M7->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
    }

    ~M7(){
        if(f3 != nullptr)
            delete f3;
    }

    M7(){
       f3 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) int32_t f2;
    alignas(8) M8* f3;
};


class alignas(8) M9 : public M_base
{
public:
    class alignas(8) M10 : public M_base
    {
    public:
        inline void set_f1(bool val){
            f1 = val;
        }
        inline bool& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(int32_t val){
            f3 = val;
        }
        inline int32_t& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M10->f1: " << f1 << std::endl;
            fout << "M10->f2: " << f2 << std::endl;
            fout << "M10->f3: " << f3 << std::endl;
        }
    
        ~M10(){
        }
    
        M10(){
        }
    
    private:
        alignas(8) bool f1;
        alignas(8) int32_t f2;
        alignas(8) int32_t f3;
    };


    inline void set_f1(int32_t val){
        f1 = val;
    }
    inline int32_t& get_f1(){
        return f1;
    }

    inline void set_f2(string val){
        f2 = val;
    }
    inline string& get_f2(){
        return f2;
    }

    inline void add_f3(int32_t val){
        f3.push_back(val);
    }
    inline int32_t& get_f3(int idx){
        return f3[idx];
    }

    inline M10* mutable_f4(){
        f4 = new M10();
        return f4;
    }
    inline M10*& get_f4(){
        return f4;
    }

    inline void set_f5(int32_t val){
        f5 = val;
    }
    inline int32_t& get_f5(){
        return f5;
    }

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
        return f6;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M9->f1: " << f1 << std::endl;
        fout << "M9->f2: " << f2 << std::endl;
        for(auto &f3_val : f3){
            fout << "M9->f3: " << f3_val << std::endl;
        }
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M9->f5: " << f5 << std::endl;
        fout << "M9->f6: " << f6 << std::endl;
    }

    ~M9(){
        if(f4 != nullptr)
            delete f4;
    }

    M9(){
       f4 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) string f2;
    alignas(8) std::vector<int32_t> f3;
    alignas(8) M10* f4;
    alignas(8) int32_t f5;
    alignas(8) int64_t f6;
};


class alignas(8) M11 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 67,
        E1_CONST_2 = 100,
        E1_CONST_3 = 108,
        E1_CONST_4 = 88,
        E1_CONST_5 = 91,
    };
    
    enum E2 {
        E2_CONST_1 = 69,
        E2_CONST_2 = 10,
        E2_CONST_3 = 86,
        E2_CONST_4 = 126,
        E2_CONST_5 = 94,
    };
    
    class alignas(8) M12 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 5,
            E1_CONST_2 = 78,
            E1_CONST_3 = 21,
            E1_CONST_4 = 121,
            E1_CONST_5 = 57,
        };
        
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(bool val){
            f2 = val;
        }
        inline bool& get_f2(){
            return f2;
        }
    
        inline void set_f3(E1 val){
            f3 = val;
        }
        inline E1& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M12->f1: " << f1 << std::endl;
            fout << "M12->f2: " << f2 << std::endl;
            fout << "M12->f3: " << f3 << std::endl;
        }
    
        ~M12(){
        }
    
        M12(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) bool f2;
        alignas(8) E1 f3;
    };


    class alignas(8) M13 : public M_base
    {
    public:
        inline void set_f1(uint64_t val){
            f1 = val;
        }
        inline uint64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint64_t val){
            f2 = val;
        }
        inline uint64_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(string val){
            f3 = val;
        }
        inline string& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M13->f1: " << f1 << std::endl;
            fout << "M13->f2: " << f2 << std::endl;
            fout << "M13->f3: " << f3 << std::endl;
        }
    
        ~M13(){
        }
    
        M13(){
        }
    
    private:
        alignas(8) uint64_t f1;
        alignas(8) uint64_t f2;
        alignas(8) string f3;
    };


    inline void set_f1(int32_t val){
        f1 = val;
    }
    inline int32_t& get_f1(){
        return f1;
    }

    inline void set_f2(int64_t val){
        f2 = val;
    }
    inline int64_t& get_f2(){
        return f2;
    }

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
        return f3;
    }

    inline void set_f4(string val){
        f4 = val;
    }
    inline string& get_f4(){
        return f4;
    }

    inline void set_f5(E1 val){
        f5 = val;
    }
    inline E1& get_f5(){
        return f5;
    }

    inline void set_f6(string val){
        f6 = val;
    }
    inline string& get_f6(){
        return f6;
    }

    inline void set_f7(E2 val){
        f7 = val;
    }
    inline E2& get_f7(){
        return f7;
    }

    inline void set_f8(int32_t val){
        f8 = val;
    }
    inline int32_t& get_f8(){
        return f8;
    }

    inline void set_f9(int32_t val){
        f9 = val;
    }
    inline int32_t& get_f9(){
        return f9;
    }

    inline M12* mutable_f10(){
        f10 = new M12();
        return f10;
    }
    inline M12*& get_f10(){
        return f10;
    }

    inline void set_f11(uint64_t val){
        f11 = val;
    }
    inline uint64_t& get_f11(){
        return f11;
    }

    inline M13* mutable_f12(){
        f12 = new M13();
        return f12;
    }
    inline M13*& get_f12(){
        return f12;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M11->f1: " << f1 << std::endl;
        fout << "M11->f2: " << f2 << std::endl;
        fout << "M11->f3: " << f3 << std::endl;
        fout << "M11->f4: " << f4 << std::endl;
        fout << "M11->f5: " << f5 << std::endl;
        fout << "M11->f6: " << f6 << std::endl;
        fout << "M11->f7: " << f7 << std::endl;
        fout << "M11->f8: " << f8 << std::endl;
        fout << "M11->f9: " << f9 << std::endl;
        if(f10 != nullptr)
            f10->print_message(fout);
        fout << "M11->f11: " << f11 << std::endl;
        if(f12 != nullptr)
            f12->print_message(fout);
    }

    ~M11(){
        if(f10 != nullptr)
            delete f10;
        if(f12 != nullptr)
            delete f12;
    }

    M11(){
       f10 = nullptr;
       f12 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) int64_t f2;
    alignas(8) string f3;
    alignas(8) string f4;
    alignas(8) E1 f5;
    alignas(8) string f6;
    alignas(8) E2 f7;
    alignas(8) int32_t f8;
    alignas(8) int32_t f9;
    alignas(8) M12* f10;
    alignas(8) uint64_t f11;
    alignas(8) M13* f12;
};


class alignas(8) M14 : public M_base
{
public:
    class alignas(8) M15 : public M_base
    {
    public:
        inline void add_f1(uint64_t val){
            f1.push_back(val);
        }
        inline uint64_t& get_f1(int idx){
            return f1[idx];
        }
    
        inline void print_message(std::ofstream &fout){
            for(auto &f1_val : f1){
                fout << "M15->f1: " << f1_val << std::endl;
            }
        }
    
        ~M15(){
        }
    
        M15(){
        }
    
    private:
        alignas(8) std::vector<uint64_t> f1;
    };


    class alignas(8) M16 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(double val){
            f2 = val;
        }
        inline double& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M16->f1: " << f1 << std::endl;
            fout << "M16->f2: " << f2 << std::endl;
        }
    
        ~M16(){
        }
    
        M16(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) double f2;
    };


    inline M15* mutable_f1(){
        f1 = new M15();
        return f1;
    }
    inline M15*& get_f1(){
        return f1;
    }

    inline void add_f2(int32_t val){
        f2.push_back(val);
    }
    inline int32_t& get_f2(int idx){
        return f2[idx];
    }

    inline M16* mutable_f3(){
        f3 = new M16();
        return f3;
    }
    inline M16*& get_f3(){
        return f3;
    }

    inline void set_f4(string val){
        f4 = val;
    }
    inline string& get_f4(){
        return f4;
    }

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        for(auto &f2_val : f2){
            fout << "M14->f2: " << f2_val << std::endl;
        }
        if(f3 != nullptr)
            f3->print_message(fout);
        fout << "M14->f4: " << f4 << std::endl;
        fout << "M14->f5: " << f5 << std::endl;
    }

    ~M14(){
        if(f1 != nullptr)
            delete f1;
        if(f3 != nullptr)
            delete f3;
    }

    M14(){
       f1 = nullptr;
       f3 = nullptr;
    }

private:
    alignas(8) M15* f1;
    alignas(8) std::vector<int32_t> f2;
    alignas(8) M16* f3;
    alignas(8) string f4;
    alignas(8) int64_t f5;
};


class alignas(8) M17 : public M_base
{
public:
    class alignas(8) M18 : public M_base
    {
    public:
        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline void set_f2(int64_t val){
            f2 = val;
        }
        inline int64_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(int32_t val){
            f3 = val;
        }
        inline int32_t& get_f3(){
            return f3;
        }
    
        inline void set_f4(string val){
            f4 = val;
        }
        inline string& get_f4(){
            return f4;
        }
    
        inline void set_f5(int64_t val){
            f5 = val;
        }
        inline int64_t& get_f5(){
            return f5;
        }
    
        inline void set_f6(int32_t val){
            f6 = val;
        }
        inline int32_t& get_f6(){
            return f6;
        }
    
        inline void set_f7(int32_t val){
            f7 = val;
        }
        inline int32_t& get_f7(){
            return f7;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M18->f1: " << f1 << std::endl;
            fout << "M18->f2: " << f2 << std::endl;
            fout << "M18->f3: " << f3 << std::endl;
            fout << "M18->f4: " << f4 << std::endl;
            fout << "M18->f5: " << f5 << std::endl;
            fout << "M18->f6: " << f6 << std::endl;
            fout << "M18->f7: " << f7 << std::endl;
        }
    
        ~M18(){
        }
    
        M18(){
        }
    
    private:
        alignas(8) string f1;
        alignas(8) int64_t f2;
        alignas(8) int32_t f3;
        alignas(8) string f4;
        alignas(8) int64_t f5;
        alignas(8) int32_t f6;
        alignas(8) int32_t f7;
    };


    inline M18* mutable_f1(){
        f1 = new M18();
        return f1;
    }
    inline M18*& get_f1(){
        return f1;
    }

    inline void add_f2(int32_t val){
        f2.push_back(val);
    }
    inline int32_t& get_f2(int idx){
        return f2[idx];
    }

    inline void set_f3(int64_t val){
        f3 = val;
    }
    inline int64_t& get_f3(){
        return f3;
    }

    inline void set_f4(double val){
        f4 = val;
    }
    inline double& get_f4(){
        return f4;
    }

    inline void set_f5(string val){
        f5 = val;
    }
    inline string& get_f5(){
        return f5;
    }

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
        return f6;
    }

    inline void set_f7(string val){
        f7 = val;
    }
    inline string& get_f7(){
        return f7;
    }

    inline void add_f8(int32_t val){
        f8.push_back(val);
    }
    inline int32_t& get_f8(int idx){
        return f8[idx];
    }

    inline void set_f9(int64_t val){
        f9 = val;
    }
    inline int64_t& get_f9(){
        return f9;
    }

    inline void set_f10(string val){
        f10 = val;
    }
    inline string& get_f10(){
        return f10;
    }

    inline void set_f11(int32_t val){
        f11 = val;
    }
    inline int32_t& get_f11(){
        return f11;
    }

    inline void set_f12(string val){
        f12 = val;
    }
    inline string& get_f12(){
        return f12;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        for(auto &f2_val : f2){
            fout << "M17->f2: " << f2_val << std::endl;
        }
        fout << "M17->f3: " << f3 << std::endl;
        fout << "M17->f4: " << f4 << std::endl;
        fout << "M17->f5: " << f5 << std::endl;
        fout << "M17->f6: " << f6 << std::endl;
        fout << "M17->f7: " << f7 << std::endl;
        for(auto &f8_val : f8){
            fout << "M17->f8: " << f8_val << std::endl;
        }
        fout << "M17->f9: " << f9 << std::endl;
        fout << "M17->f10: " << f10 << std::endl;
        fout << "M17->f11: " << f11 << std::endl;
        fout << "M17->f12: " << f12 << std::endl;
    }

    ~M17(){
        if(f1 != nullptr)
            delete f1;
    }

    M17(){
       f1 = nullptr;
    }

private:
    alignas(8) M18* f1;
    alignas(8) std::vector<int32_t> f2;
    alignas(8) int64_t f3;
    alignas(8) double f4;
    alignas(8) string f5;
    alignas(8) int64_t f6;
    alignas(8) string f7;
    alignas(8) std::vector<int32_t> f8;
    alignas(8) int64_t f9;
    alignas(8) string f10;
    alignas(8) int32_t f11;
    alignas(8) string f12;
};


class alignas(8) M19 : public M_base
{
public:
    class alignas(8) M20 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(int64_t val){
            f2 = val;
        }
        inline int64_t& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M20->f1: " << f1 << std::endl;
            fout << "M20->f2: " << f2 << std::endl;
        }
    
        ~M20(){
        }
    
        M20(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
    };


    class alignas(8) M21 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(bool val){
            f2 = val;
        }
        inline bool& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M21->f1: " << f1 << std::endl;
            fout << "M21->f2: " << f2 << std::endl;
        }
    
        ~M21(){
        }
    
        M21(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) bool f2;
    };


    inline void set_f1(int32_t val){
        f1 = val;
    }
    inline int32_t& get_f1(){
        return f1;
    }

    inline M20* mutable_f2(){
        f2 = new M20();
        return f2;
    }
    inline M20*& get_f2(){
        return f2;
    }

    inline void set_f3(int64_t val){
        f3 = val;
    }
    inline int64_t& get_f3(){
        return f3;
    }

    inline void set_f4(int64_t val){
        f4 = val;
    }
    inline int64_t& get_f4(){
        return f4;
    }

    inline void set_f5(uint64_t val){
        f5 = val;
    }
    inline uint64_t& get_f5(){
        return f5;
    }

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
        return f6;
    }

    inline void set_f7(string val){
        f7 = val;
    }
    inline string& get_f7(){
        return f7;
    }

    inline M21* mutable_f8(){
        f8 = new M21();
        return f8;
    }
    inline M21*& get_f8(){
        return f8;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M19->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M19->f3: " << f3 << std::endl;
        fout << "M19->f4: " << f4 << std::endl;
        fout << "M19->f5: " << f5 << std::endl;
        fout << "M19->f6: " << f6 << std::endl;
        fout << "M19->f7: " << f7 << std::endl;
        if(f8 != nullptr)
            f8->print_message(fout);
    }

    ~M19(){
        if(f2 != nullptr)
            delete f2;
        if(f8 != nullptr)
            delete f8;
    }

    M19(){
       f2 = nullptr;
       f8 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) M20* f2;
    alignas(8) int64_t f3;
    alignas(8) int64_t f4;
    alignas(8) uint64_t f5;
    alignas(8) int64_t f6;
    alignas(8) string f7;
    alignas(8) M21* f8;
};


class alignas(8) M22 : public M_base
{
public:
    class alignas(8) M23 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(bool val){
            f2 = val;
        }
        inline bool& get_f2(){
            return f2;
        }
    
        inline void set_f3(uint64_t val){
            f3 = val;
        }
        inline uint64_t& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M23->f1: " << f1 << std::endl;
            fout << "M23->f2: " << f2 << std::endl;
            fout << "M23->f3: " << f3 << std::endl;
        }
    
        ~M23(){
        }
    
        M23(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) bool f2;
        alignas(8) uint64_t f3;
    };


    class alignas(8) M24 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M24->f1: " << f1 << std::endl;
        }
    
        ~M24(){
        }
    
        M24(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    class alignas(8) M25 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M25->f1: " << f1 << std::endl;
        }
    
        ~M25(){
        }
    
        M25(){
        }
    
    private:
        alignas(8) int32_t f1;
    };


    inline void set_f1(int32_t val){
        f1 = val;
    }
    inline int32_t& get_f1(){
        return f1;
    }

    inline void set_f2(string val){
        f2 = val;
    }
    inline string& get_f2(){
        return f2;
    }

    inline void set_f3(int64_t val){
        f3 = val;
    }
    inline int64_t& get_f3(){
        return f3;
    }

    inline M23* mutable_f4(){
        f4 = new M23();
        return f4;
    }
    inline M23*& get_f4(){
        return f4;
    }

    inline void set_f5(string val){
        f5 = val;
    }
    inline string& get_f5(){
        return f5;
    }

    inline void set_f6(uint64_t val){
        f6 = val;
    }
    inline uint64_t& get_f6(){
        return f6;
    }

    inline M24* mutable_f7(){
        f7 = new M24();
        return f7;
    }
    inline M24*& get_f7(){
        return f7;
    }

    inline M25* mutable_f8(){
        f8 = new M25();
        return f8;
    }
    inline M25*& get_f8(){
        return f8;
    }

    inline void set_f9(int32_t val){
        f9 = val;
    }
    inline int32_t& get_f9(){
        return f9;
    }

    inline void set_f10(int32_t val){
        f10 = val;
    }
    inline int32_t& get_f10(){
        return f10;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M22->f1: " << f1 << std::endl;
        fout << "M22->f2: " << f2 << std::endl;
        fout << "M22->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M22->f5: " << f5 << std::endl;
        fout << "M22->f6: " << f6 << std::endl;
        if(f7 != nullptr)
            f7->print_message(fout);
        if(f8 != nullptr)
            f8->print_message(fout);
        fout << "M22->f9: " << f9 << std::endl;
        fout << "M22->f10: " << f10 << std::endl;
    }

    ~M22(){
        if(f4 != nullptr)
            delete f4;
        if(f7 != nullptr)
            delete f7;
        if(f8 != nullptr)
            delete f8;
    }

    M22(){
       f4 = nullptr;
       f7 = nullptr;
       f8 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) string f2;
    alignas(8) int64_t f3;
    alignas(8) M23* f4;
    alignas(8) string f5;
    alignas(8) uint64_t f6;
    alignas(8) M24* f7;
    alignas(8) M25* f8;
    alignas(8) int32_t f9;
    alignas(8) int32_t f10;
};


class alignas(8) M26 : public M_base
{
public:
    class alignas(8) M27 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M27->f1: " << f1 << std::endl;
            fout << "M27->f2: " << f2 << std::endl;
        }
    
        ~M27(){
        }
    
        M27(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int32_t f2;
    };


    class alignas(8) M28 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M28->f1: " << f1 << std::endl;
        }
    
        ~M28(){
        }
    
        M28(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    class alignas(8) M29 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M29->f1: " << f1 << std::endl;
            fout << "M29->f2: " << f2 << std::endl;
        }
    
        ~M29(){
        }
    
        M29(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int32_t f2;
    };


    class alignas(8) M30 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M30->f1: " << f1 << std::endl;
        }
    
        ~M30(){
        }
    
        M30(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    inline void set_f1(int32_t val){
        f1 = val;
    }
    inline int32_t& get_f1(){
        return f1;
    }

    inline void set_f2(double val){
        f2 = val;
    }
    inline double& get_f2(){
        return f2;
    }

    inline void set_f3(int32_t val){
        f3 = val;
    }
    inline int32_t& get_f3(){
        return f3;
    }

    inline void set_f4(int64_t val){
        f4 = val;
    }
    inline int64_t& get_f4(){
        return f4;
    }

    inline M27* mutable_f5(){
        f5 = new M27();
        return f5;
    }
    inline M27*& get_f5(){
        return f5;
    }

    inline void set_f6(string val){
        f6 = val;
    }
    inline string& get_f6(){
        return f6;
    }

    inline M28* mutable_f7(){
        f7 = new M28();
        return f7;
    }
    inline M28*& get_f7(){
        return f7;
    }

    inline void set_f8(bool val){
        f8 = val;
    }
    inline bool& get_f8(){
        return f8;
    }

    inline M29* mutable_f9(){
        f9 = new M29();
        return f9;
    }
    inline M29*& get_f9(){
        return f9;
    }

    inline void set_f10(int32_t val){
        f10 = val;
    }
    inline int32_t& get_f10(){
        return f10;
    }

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
        return f11;
    }

    inline void set_f12(double val){
        f12 = val;
    }
    inline double& get_f12(){
        return f12;
    }

    inline M30* mutable_f13(){
        f13 = new M30();
        return f13;
    }
    inline M30*& get_f13(){
        return f13;
    }

    inline void add_f14(int32_t val){
        f14.push_back(val);
    }
    inline int32_t& get_f14(int idx){
        return f14[idx];
    }

    inline void print_message(std::ofstream &fout){
        fout << "M26->f1: " << f1 << std::endl;
        fout << "M26->f2: " << f2 << std::endl;
        fout << "M26->f3: " << f3 << std::endl;
        fout << "M26->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        fout << "M26->f6: " << f6 << std::endl;
        if(f7 != nullptr)
            f7->print_message(fout);
        fout << "M26->f8: " << f8 << std::endl;
        if(f9 != nullptr)
            f9->print_message(fout);
        fout << "M26->f10: " << f10 << std::endl;
        fout << "M26->f11: " << f11 << std::endl;
        fout << "M26->f12: " << f12 << std::endl;
        if(f13 != nullptr)
            f13->print_message(fout);
        for(auto &f14_val : f14){
            fout << "M26->f14: " << f14_val << std::endl;
        }
    }

    ~M26(){
        if(f5 != nullptr)
            delete f5;
        if(f7 != nullptr)
            delete f7;
        if(f9 != nullptr)
            delete f9;
        if(f13 != nullptr)
            delete f13;
    }

    M26(){
       f5 = nullptr;
       f7 = nullptr;
       f9 = nullptr;
       f13 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) double f2;
    alignas(8) int32_t f3;
    alignas(8) int64_t f4;
    alignas(8) M27* f5;
    alignas(8) string f6;
    alignas(8) M28* f7;
    alignas(8) bool f8;
    alignas(8) M29* f9;
    alignas(8) int32_t f10;
    alignas(8) int64_t f11;
    alignas(8) double f12;
    alignas(8) M30* f13;
    alignas(8) std::vector<int32_t> f14;
};

M_base* createMessage(int temp_class_id) {
    switch (temp_class_id) {
        case 11:
            return new M11();
        case 12:
            return new M11::M12();
        case 13:
            return new M11::M13();
        case 14:
            return new M14();
        case 16:
            return new M14::M16();
        case 15:
            return new M14::M15();
        case 17:
            return new M17();
        case 18:
            return new M17::M18();
        case 19:
            return new M19();
        case 20:
            return new M19::M20();
        case 21:
            return new M19::M21();
        case 1:
            return new M1();
        case 2:
            return new M1::M2();
        case 22:
            return new M22();
        case 24:
            return new M22::M24();
        case 23:
            return new M22::M23();
        case 25:
            return new M22::M25();
        case 26:
            return new M26();
        case 30:
            return new M26::M30();
        case 27:
            return new M26::M27();
        case 29:
            return new M26::M29();
        case 28:
            return new M26::M28();
        case 3:
            return new M3();
        case 5:
            return new M3::M5();
        case 4:
            return new M3::M4();
        case 6:
            return new M3::M6();
        case 7:
            return new M7();
        case 8:
            return new M7::M8();
        case 9:
            return new M9();
        case 10:
            return new M9::M10();
        default:
            throw std::invalid_argument("Invalid class id");
    }
}

size_t getMessageSize(int temp_class_id) {
    switch (temp_class_id) {
        case 11:
            return sizeof(M11);
        case 12:
            return sizeof(M11::M12);
        case 13:
            return sizeof(M11::M13);
        case 14:
            return sizeof(M14);
        case 16:
            return sizeof(M14::M16);
        case 15:
            return sizeof(M14::M15);
        case 17:
            return sizeof(M17);
        case 18:
            return sizeof(M17::M18);
        case 19:
            return sizeof(M19);
        case 20:
            return sizeof(M19::M20);
        case 21:
            return sizeof(M19::M21);
        case 1:
            return sizeof(M1);
        case 2:
            return sizeof(M1::M2);
        case 22:
            return sizeof(M22);
        case 24:
            return sizeof(M22::M24);
        case 23:
            return sizeof(M22::M23);
        case 25:
            return sizeof(M22::M25);
        case 26:
            return sizeof(M26);
        case 30:
            return sizeof(M26::M30);
        case 27:
            return sizeof(M26::M27);
        case 29:
            return sizeof(M26::M29);
        case 28:
            return sizeof(M26::M28);
        case 3:
            return sizeof(M3);
        case 5:
            return sizeof(M3::M5);
        case 4:
            return sizeof(M3::M4);
        case 6:
            return sizeof(M3::M6);
        case 7:
            return sizeof(M7);
        case 8:
            return sizeof(M7::M8);
        case 9:
            return sizeof(M9);
        case 10:
            return sizeof(M9::M10);
        default:
            return 0;
    }
}
