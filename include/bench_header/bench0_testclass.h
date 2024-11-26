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
        E1_CONST_1 = 10,
        E1_CONST_2 = 13,
        E1_CONST_3 = 26,
        E1_CONST_4 = 59,
        E1_CONST_5 = 28,
    };
    
    enum E2 {
        E2_CONST_1 = 9,
        E2_CONST_2 = 44,
        E2_CONST_3 = 110,
        E2_CONST_4 = 29,
        E2_CONST_5 = 95,
    };
    
    class alignas(8) M2 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
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
    
        inline void set_f4(int64_t val){
            f4 = val;
        }
        inline int64_t& get_f4(){
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
    
        inline void set_f8(int64_t val){
            f8 = val;
        }
        inline int64_t& get_f8(){
            return f8;
        }
    
        inline void set_f9(string val){
            f9 = val;
        }
        inline string& get_f9(){
            return f9;
        }
    
        inline void set_f10(int64_t val){
            f10 = val;
        }
        inline int64_t& get_f10(){
            return f10;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M2->f1: " << f1 << std::endl;
            fout << "M2->f2: " << f2 << std::endl;
            fout << "M2->f3: " << f3 << std::endl;
            fout << "M2->f4: " << f4 << std::endl;
            fout << "M2->f5: " << f5 << std::endl;
            fout << "M2->f6: " << f6 << std::endl;
            fout << "M2->f7: " << f7 << std::endl;
            fout << "M2->f8: " << f8 << std::endl;
            fout << "M2->f9: " << f9 << std::endl;
            fout << "M2->f10: " << f10 << std::endl;
        }
    
        ~M2(){
        }
    
        M2(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) string f2;
        alignas(8) int64_t f3;
        alignas(8) int64_t f4;
        alignas(8) string f5;
        alignas(8) string f6;
        alignas(8) string f7;
        alignas(8) int64_t f8;
        alignas(8) string f9;
        alignas(8) int64_t f10;
    };


    class alignas(8) M3 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M3->f1: " << f1 << std::endl;
        }
    
        ~M3(){
        }
    
        M3(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    class alignas(8) M4 : public M_base
    {
    public:
        class alignas(8) M5 : public M_base
        {
        public:
            inline void set_f1(int64_t val){
                f1 = val;
            }
            inline int64_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M5->f1: " << f1 << std::endl;
            }
        
            ~M5(){
            }
        
            M5(){
            }
        
        private:
            alignas(8) int64_t f1;
        };


        class alignas(8) M6 : public M_base
        {
        public:
            inline void set_f1(int64_t val){
                f1 = val;
            }
            inline int64_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M6->f1: " << f1 << std::endl;
            }
        
            ~M6(){
            }
        
            M6(){
            }
        
        private:
            alignas(8) int64_t f1;
        };


        inline M5* mutable_f1(){
            f1 = new M5();
            return f1;
        }
        inline M5*& get_f1(){
            return f1;
        }
    
        inline M6* mutable_f2(){
            f2 = new M6();
            return f2;
        }
        inline M6*& get_f2(){
            return f2;
        }
    
        inline void set_f3(int64_t val){
            f3 = val;
        }
        inline int64_t& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M4->f3: " << f3 << std::endl;
        }
    
        ~M4(){
            if(f1 != nullptr)
                delete f1;
            if(f2 != nullptr)
                delete f2;
        }
    
        M4(){
           f1 = nullptr;
           f2 = nullptr;
        }
    
    private:
        alignas(8) M5* f1;
        alignas(8) M6* f2;
        alignas(8) int64_t f3;
    };


    class alignas(8) M7 : public M_base
    {
    public:
        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline void set_f2(string val){
            f2 = val;
        }
        inline string& get_f2(){
            return f2;
        }
    
        inline void set_f3(bool val){
            f3 = val;
        }
        inline bool& get_f3(){
            return f3;
        }
    
        inline void set_f4(bool val){
            f4 = val;
        }
        inline bool& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M7->f1: " << f1 << std::endl;
            fout << "M7->f2: " << f2 << std::endl;
            fout << "M7->f3: " << f3 << std::endl;
            fout << "M7->f4: " << f4 << std::endl;
        }
    
        ~M7(){
        }
    
        M7(){
        }
    
    private:
        alignas(8) string f1;
        alignas(8) string f2;
        alignas(8) bool f3;
        alignas(8) bool f4;
    };


    class alignas(8) M8 : public M_base
    {
    public:
        class alignas(8) M9 : public M_base
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
        
            inline void add_f3(string val){
                f3.push_back(val);
            }
            inline string& get_f3(int idx){
                return f3[idx];
            }
        
            inline void set_f4(string val){
                f4 = val;
            }
            inline string& get_f4(){
                return f4;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M9->f1: " << f1 << std::endl;
                fout << "M9->f2: " << f2 << std::endl;
                for(auto &f3_val : f3){
                    fout << "M9->f3: " << f3_val << std::endl;
                }
                fout << "M9->f4: " << f4 << std::endl;
            }
        
            ~M9(){
            }
        
            M9(){
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) bool f2;
            alignas(8) std::vector<string> f3;
            alignas(8) string f4;
        };


        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline M9* mutable_f2(){
            f2 = new M9();
            return f2;
        }
        inline M9*& get_f2(){
            return f2;
        }
    
        inline void set_f3(bool val){
            f3 = val;
        }
        inline bool& get_f3(){
            return f3;
        }
    
        inline void set_f4(uint64_t val){
            f4 = val;
        }
        inline uint64_t& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M8->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M8->f3: " << f3 << std::endl;
            fout << "M8->f4: " << f4 << std::endl;
        }
    
        ~M8(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M8(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) M9* f2;
        alignas(8) bool f3;
        alignas(8) uint64_t f4;
    };


    inline M2* mutable_f1(){
        f1 = new M2();
        return f1;
    }
    inline M2*& get_f1(){
        return f1;
    }

    inline void set_f2(E1 val){
        f2 = val;
    }
    inline E1& get_f2(){
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

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline M3* mutable_f6(){
        f6 = new M3();
        return f6;
    }
    inline M3*& get_f6(){
        return f6;
    }

    inline void set_f7(int64_t val){
        f7 = val;
    }
    inline int64_t& get_f7(){
        return f7;
    }

    inline void set_f8(int64_t val){
        f8 = val;
    }
    inline int64_t& get_f8(){
        return f8;
    }

    inline void set_f9(int32_t val){
        f9 = val;
    }
    inline int32_t& get_f9(){
        return f9;
    }

    inline void set_f10(bool val){
        f10 = val;
    }
    inline bool& get_f10(){
        return f10;
    }

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
        return f11;
    }

    inline void set_f12(E2 val){
        f12 = val;
    }
    inline E2& get_f12(){
        return f12;
    }

    inline M4* mutable_f13(){
        f13 = new M4();
        return f13;
    }
    inline M4*& get_f13(){
        return f13;
    }

    inline void set_f14(uint64_t val){
        f14 = val;
    }
    inline uint64_t& get_f14(){
        return f14;
    }

    inline void set_f15(double val){
        f15 = val;
    }
    inline double& get_f15(){
        return f15;
    }

    inline M7* mutable_f16(){
        f16 = new M7();
        return f16;
    }
    inline M7*& get_f16(){
        return f16;
    }

    inline M8* mutable_f17(){
        f17 = new M8();
        return f17;
    }
    inline M8*& get_f17(){
        return f17;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        fout << "M1->f2: " << f2 << std::endl;
        fout << "M1->f3: " << f3 << std::endl;
        fout << "M1->f4: " << f4 << std::endl;
        fout << "M1->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        fout << "M1->f7: " << f7 << std::endl;
        fout << "M1->f8: " << f8 << std::endl;
        fout << "M1->f9: " << f9 << std::endl;
        fout << "M1->f10: " << f10 << std::endl;
        fout << "M1->f11: " << f11 << std::endl;
        fout << "M1->f12: " << f12 << std::endl;
        if(f13 != nullptr)
            f13->print_message(fout);
        fout << "M1->f14: " << f14 << std::endl;
        fout << "M1->f15: " << f15 << std::endl;
        if(f16 != nullptr)
            f16->print_message(fout);
        if(f17 != nullptr)
            f17->print_message(fout);
    }

    ~M1(){
        if(f1 != nullptr)
            delete f1;
        if(f6 != nullptr)
            delete f6;
        if(f13 != nullptr)
            delete f13;
        if(f16 != nullptr)
            delete f16;
        if(f17 != nullptr)
            delete f17;
    }

    M1(){
       f1 = nullptr;
       f6 = nullptr;
       f13 = nullptr;
       f16 = nullptr;
       f17 = nullptr;
    }

private:
    alignas(8) M2* f1;
    alignas(8) E1 f2;
    alignas(8) int64_t f3;
    alignas(8) int32_t f4;
    alignas(8) int64_t f5;
    alignas(8) M3* f6;
    alignas(8) int64_t f7;
    alignas(8) int64_t f8;
    alignas(8) int32_t f9;
    alignas(8) bool f10;
    alignas(8) int64_t f11;
    alignas(8) E2 f12;
    alignas(8) M4* f13;
    alignas(8) uint64_t f14;
    alignas(8) double f15;
    alignas(8) M7* f16;
    alignas(8) M8* f17;
};


class alignas(8) M10 : public M_base
{
public:
    class alignas(8) M11 : public M_base
    {
    public:
        class alignas(8) M12 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void set_f2(int32_t val){
                f2 = val;
            }
            inline int32_t& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M12->f1: " << f1 << std::endl;
                fout << "M12->f2: " << f2 << std::endl;
            }
        
            ~M12(){
            }
        
            M12(){
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) int32_t f2;
        };


        inline M12* mutable_f1(){
            f1 = new M12();
            return f1;
        }
        inline M12*& get_f1(){
            return f1;
        }
    
        inline void set_f2(string val){
            f2 = val;
        }
        inline string& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M11->f2: " << f2 << std::endl;
        }
    
        ~M11(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M11(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M12* f1;
        alignas(8) string f2;
    };


    class alignas(8) M13 : public M_base
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
    
        inline void set_f4(int32_t val){
            f4 = val;
        }
        inline int32_t& get_f4(){
            return f4;
        }
    
        inline void set_f5(bool val){
            f5 = val;
        }
        inline bool& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M13->f1: " << f1 << std::endl;
            fout << "M13->f2: " << f2 << std::endl;
            fout << "M13->f3: " << f3 << std::endl;
            fout << "M13->f4: " << f4 << std::endl;
            fout << "M13->f5: " << f5 << std::endl;
        }
    
        ~M13(){
        }
    
        M13(){
        }
    
    private:
        alignas(8) string f1;
        alignas(8) int64_t f2;
        alignas(8) int32_t f3;
        alignas(8) int32_t f4;
        alignas(8) bool f5;
    };


    class alignas(8) M14 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(double val){
            f2 = val;
        }
        inline double& get_f2(){
            return f2;
        }
    
        inline void set_f3(bool val){
            f3 = val;
        }
        inline bool& get_f3(){
            return f3;
        }
    
        inline void set_f4(int64_t val){
            f4 = val;
        }
        inline int64_t& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M14->f1: " << f1 << std::endl;
            fout << "M14->f2: " << f2 << std::endl;
            fout << "M14->f3: " << f3 << std::endl;
            fout << "M14->f4: " << f4 << std::endl;
        }
    
        ~M14(){
        }
    
        M14(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) double f2;
        alignas(8) bool f3;
        alignas(8) int64_t f4;
    };


    inline void set_f1(int32_t val){
        f1 = val;
    }
    inline int32_t& get_f1(){
        return f1;
    }

    inline M11* mutable_f2(){
        f2 = new M11();
        return f2;
    }
    inline M11*& get_f2(){
        return f2;
    }

    inline M13* mutable_f3(){
        f3 = new M13();
        return f3;
    }
    inline M13*& get_f3(){
        return f3;
    }

    inline void set_f4(int64_t val){
        f4 = val;
    }
    inline int64_t& get_f4(){
        return f4;
    }

    inline M14* mutable_f5(){
        f5 = new M14();
        return f5;
    }
    inline M14*& get_f5(){
        return f5;
    }

    inline void set_f6(string val){
        f6 = val;
    }
    inline string& get_f6(){
        return f6;
    }

    inline void set_f7(uint64_t val){
        f7 = val;
    }
    inline uint64_t& get_f7(){
        return f7;
    }

    inline void set_f8(int64_t val){
        f8 = val;
    }
    inline int64_t& get_f8(){
        return f8;
    }

    inline void set_f9(int32_t val){
        f9 = val;
    }
    inline int32_t& get_f9(){
        return f9;
    }

    inline void set_f10(int64_t val){
        f10 = val;
    }
    inline int64_t& get_f10(){
        return f10;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M10->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        if(f3 != nullptr)
            f3->print_message(fout);
        fout << "M10->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        fout << "M10->f6: " << f6 << std::endl;
        fout << "M10->f7: " << f7 << std::endl;
        fout << "M10->f8: " << f8 << std::endl;
        fout << "M10->f9: " << f9 << std::endl;
        fout << "M10->f10: " << f10 << std::endl;
    }

    ~M10(){
        if(f2 != nullptr)
            delete f2;
        if(f3 != nullptr)
            delete f3;
        if(f5 != nullptr)
            delete f5;
    }

    M10(){
       f2 = nullptr;
       f3 = nullptr;
       f5 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) M11* f2;
    alignas(8) M13* f3;
    alignas(8) int64_t f4;
    alignas(8) M14* f5;
    alignas(8) string f6;
    alignas(8) uint64_t f7;
    alignas(8) int64_t f8;
    alignas(8) int32_t f9;
    alignas(8) int64_t f10;
};


class alignas(8) M15 : public M_base
{
public:
    class alignas(8) M16 : public M_base
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
    
        inline void add_f3(string val){
            f3.push_back(val);
        }
        inline string& get_f3(int idx){
            return f3[idx];
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
    
        inline void set_f6(string val){
            f6 = val;
        }
        inline string& get_f6(){
            return f6;
        }
    
        inline void set_f7(int64_t val){
            f7 = val;
        }
        inline int64_t& get_f7(){
            return f7;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M16->f1: " << f1 << std::endl;
            fout << "M16->f2: " << f2 << std::endl;
            for(auto &f3_val : f3){
                fout << "M16->f3: " << f3_val << std::endl;
            }
            fout << "M16->f4: " << f4 << std::endl;
            fout << "M16->f5: " << f5 << std::endl;
            fout << "M16->f6: " << f6 << std::endl;
            fout << "M16->f7: " << f7 << std::endl;
        }
    
        ~M16(){
        }
    
        M16(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) string f2;
        alignas(8) std::vector<string> f3;
        alignas(8) string f4;
        alignas(8) int64_t f5;
        alignas(8) string f6;
        alignas(8) int64_t f7;
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M18->f1: " << f1 << std::endl;
            }
        
            ~M18(){
            }
        
            M18(){
            }
        
        private:
            alignas(8) string f1;
        };


        class alignas(8) M19 : public M_base
        {
        public:
            inline void set_f1(int64_t val){
                f1 = val;
            }
            inline int64_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M19->f1: " << f1 << std::endl;
            }
        
            ~M19(){
            }
        
            M19(){
            }
        
        private:
            alignas(8) int64_t f1;
        };


        inline M18* mutable_f1(){
            f1 = new M18();
            return f1;
        }
        inline M18*& get_f1(){
            return f1;
        }
    
        inline M19* mutable_f2(){
            f2 = new M19();
            return f2;
        }
        inline M19*& get_f2(){
            return f2;
        }
    
        inline void set_f3(int64_t val){
            f3 = val;
        }
        inline int64_t& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M17->f3: " << f3 << std::endl;
        }
    
        ~M17(){
            if(f1 != nullptr)
                delete f1;
            if(f2 != nullptr)
                delete f2;
        }
    
        M17(){
           f1 = nullptr;
           f2 = nullptr;
        }
    
    private:
        alignas(8) M18* f1;
        alignas(8) M19* f2;
        alignas(8) int64_t f3;
    };


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

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
        return f6;
    }

    inline void set_f7(bool val){
        f7 = val;
    }
    inline bool& get_f7(){
        return f7;
    }

    inline void set_f8(string val){
        f8 = val;
    }
    inline string& get_f8(){
        return f8;
    }

    inline M16* mutable_f9(){
        f9 = new M16();
        return f9;
    }
    inline M16*& get_f9(){
        return f9;
    }

    inline M17* mutable_f10(){
        f10 = new M17();
        return f10;
    }
    inline M17*& get_f10(){
        return f10;
    }

    inline void set_f11(string val){
        f11 = val;
    }
    inline string& get_f11(){
        return f11;
    }

    inline M20* mutable_f12(){
        f12 = new M20();
        return f12;
    }
    inline M20*& get_f12(){
        return f12;
    }

    inline void set_f13(bool val){
        f13 = val;
    }
    inline bool& get_f13(){
        return f13;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M15->f1: " << f1 << std::endl;
        fout << "M15->f2: " << f2 << std::endl;
        fout << "M15->f3: " << f3 << std::endl;
        fout << "M15->f4: " << f4 << std::endl;
        fout << "M15->f5: " << f5 << std::endl;
        fout << "M15->f6: " << f6 << std::endl;
        fout << "M15->f7: " << f7 << std::endl;
        fout << "M15->f8: " << f8 << std::endl;
        if(f9 != nullptr)
            f9->print_message(fout);
        if(f10 != nullptr)
            f10->print_message(fout);
        fout << "M15->f11: " << f11 << std::endl;
        if(f12 != nullptr)
            f12->print_message(fout);
        fout << "M15->f13: " << f13 << std::endl;
    }

    ~M15(){
        if(f9 != nullptr)
            delete f9;
        if(f10 != nullptr)
            delete f10;
        if(f12 != nullptr)
            delete f12;
    }

    M15(){
       f9 = nullptr;
       f10 = nullptr;
       f12 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) int32_t f2;
    alignas(8) string f3;
    alignas(8) bool f4;
    alignas(8) string f5;
    alignas(8) int64_t f6;
    alignas(8) bool f7;
    alignas(8) string f8;
    alignas(8) M16* f9;
    alignas(8) M17* f10;
    alignas(8) string f11;
    alignas(8) M20* f12;
    alignas(8) bool f13;
};


class alignas(8) M21 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 68,
        E1_CONST_2 = 43,
        E1_CONST_3 = 78,
        E1_CONST_4 = 79,
        E1_CONST_5 = 56,
    };
    
    class alignas(8) M22 : public M_base
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
    
        inline void set_f7(int64_t val){
            f7 = val;
        }
        inline int64_t& get_f7(){
            return f7;
        }
    
        inline void add_f8(string val){
            f8.push_back(val);
        }
        inline string& get_f8(int idx){
            return f8[idx];
        }
    
        inline void set_f9(string val){
            f9 = val;
        }
        inline string& get_f9(){
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
            fout << "M22->f1: " << f1 << std::endl;
            fout << "M22->f2: " << f2 << std::endl;
            fout << "M22->f3: " << f3 << std::endl;
            fout << "M22->f4: " << f4 << std::endl;
            fout << "M22->f5: " << f5 << std::endl;
            fout << "M22->f6: " << f6 << std::endl;
            fout << "M22->f7: " << f7 << std::endl;
            for(auto &f8_val : f8){
                fout << "M22->f8: " << f8_val << std::endl;
            }
            fout << "M22->f9: " << f9 << std::endl;
            fout << "M22->f10: " << f10 << std::endl;
            fout << "M22->f11: " << f11 << std::endl;
            fout << "M22->f12: " << f12 << std::endl;
        }
    
        ~M22(){
        }
    
        M22(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
        alignas(8) int32_t f3;
        alignas(8) int64_t f4;
        alignas(8) int64_t f5;
        alignas(8) int32_t f6;
        alignas(8) int64_t f7;
        alignas(8) std::vector<string> f8;
        alignas(8) string f9;
        alignas(8) string f10;
        alignas(8) int64_t f11;
        alignas(8) string f12;
    };


    class alignas(8) M23 : public M_base
    {
    public:
        class alignas(8) M24 : public M_base
        {
        public:
            inline void set_f1(string val){
                f1 = val;
            }
            inline string& get_f1(){
                return f1;
            }
        
            inline void set_f2(string val){
                f2 = val;
            }
            inline string& get_f2(){
                return f2;
            }
        
            inline void set_f3(bool val){
                f3 = val;
            }
            inline bool& get_f3(){
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
        
            inline void set_f6(uint64_t val){
                f6 = val;
            }
            inline uint64_t& get_f6(){
                return f6;
            }
        
            inline void set_f7(int64_t val){
                f7 = val;
            }
            inline int64_t& get_f7(){
                return f7;
            }
        
            inline void set_f8(int64_t val){
                f8 = val;
            }
            inline int64_t& get_f8(){
                return f8;
            }
        
            inline void set_f9(string val){
                f9 = val;
            }
            inline string& get_f9(){
                return f9;
            }
        
            inline void set_f10(int64_t val){
                f10 = val;
            }
            inline int64_t& get_f10(){
                return f10;
            }
        
            inline void set_f11(int64_t val){
                f11 = val;
            }
            inline int64_t& get_f11(){
                return f11;
            }
        
            inline void set_f12(uint64_t val){
                f12 = val;
            }
            inline uint64_t& get_f12(){
                return f12;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M24->f1: " << f1 << std::endl;
                fout << "M24->f2: " << f2 << std::endl;
                fout << "M24->f3: " << f3 << std::endl;
                fout << "M24->f4: " << f4 << std::endl;
                fout << "M24->f5: " << f5 << std::endl;
                fout << "M24->f6: " << f6 << std::endl;
                fout << "M24->f7: " << f7 << std::endl;
                fout << "M24->f8: " << f8 << std::endl;
                fout << "M24->f9: " << f9 << std::endl;
                fout << "M24->f10: " << f10 << std::endl;
                fout << "M24->f11: " << f11 << std::endl;
                fout << "M24->f12: " << f12 << std::endl;
            }
        
            ~M24(){
            }
        
            M24(){
            }
        
        private:
            alignas(8) string f1;
            alignas(8) string f2;
            alignas(8) bool f3;
            alignas(8) string f4;
            alignas(8) string f5;
            alignas(8) uint64_t f6;
            alignas(8) int64_t f7;
            alignas(8) int64_t f8;
            alignas(8) string f9;
            alignas(8) int64_t f10;
            alignas(8) int64_t f11;
            alignas(8) uint64_t f12;
        };


        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline M24* mutable_f2(){
            f2 = new M24();
            return f2;
        }
        inline M24*& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M23->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
        }
    
        ~M23(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M23(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) M24* f2;
    };


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

    inline M22* mutable_f5(){
        f5 = new M22();
        return f5;
    }
    inline M22*& get_f5(){
        return f5;
    }

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
        return f6;
    }

    inline M23* mutable_f7(){
        f7 = new M23();
        return f7;
    }
    inline M23*& get_f7(){
        return f7;
    }

    inline void set_f8(string val){
        f8 = val;
    }
    inline string& get_f8(){
        return f8;
    }

    inline void set_f9(E1 val){
        f9 = val;
    }
    inline E1& get_f9(){
        return f9;
    }

    inline void set_f10(int64_t val){
        f10 = val;
    }
    inline int64_t& get_f10(){
        return f10;
    }

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
        return f11;
    }

    inline void set_f12(int32_t val){
        f12 = val;
    }
    inline int32_t& get_f12(){
        return f12;
    }

    inline void add_f13(string val){
        f13.push_back(val);
    }
    inline string& get_f13(int idx){
        return f13[idx];
    }

    inline void set_f14(string val){
        f14 = val;
    }
    inline string& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M21->f1: " << f1 << std::endl;
        fout << "M21->f2: " << f2 << std::endl;
        fout << "M21->f3: " << f3 << std::endl;
        fout << "M21->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        fout << "M21->f6: " << f6 << std::endl;
        if(f7 != nullptr)
            f7->print_message(fout);
        fout << "M21->f8: " << f8 << std::endl;
        fout << "M21->f9: " << f9 << std::endl;
        fout << "M21->f10: " << f10 << std::endl;
        fout << "M21->f11: " << f11 << std::endl;
        fout << "M21->f12: " << f12 << std::endl;
        for(auto &f13_val : f13){
            fout << "M21->f13: " << f13_val << std::endl;
        }
        fout << "M21->f14: " << f14 << std::endl;
    }

    ~M21(){
        if(f5 != nullptr)
            delete f5;
        if(f7 != nullptr)
            delete f7;
    }

    M21(){
       f5 = nullptr;
       f7 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) int64_t f3;
    alignas(8) string f4;
    alignas(8) M22* f5;
    alignas(8) int64_t f6;
    alignas(8) M23* f7;
    alignas(8) string f8;
    alignas(8) E1 f9;
    alignas(8) int64_t f10;
    alignas(8) int64_t f11;
    alignas(8) int32_t f12;
    alignas(8) std::vector<string> f13;
    alignas(8) string f14;
};


class alignas(8) M25 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 74,
        E1_CONST_2 = 79,
        E1_CONST_3 = 18,
        E1_CONST_4 = 116,
        E1_CONST_5 = 55,
    };
    
    class alignas(8) M26 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 65,
            E1_CONST_2 = 8,
            E1_CONST_3 = 78,
            E1_CONST_4 = 110,
            E1_CONST_5 = 87,
        };
        
        class alignas(8) M27 : public M_base
        {
        public:
            inline void set_f1(string val){
                f1 = val;
            }
            inline string& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M27->f1: " << f1 << std::endl;
            }
        
            ~M27(){
            }
        
            M27(){
            }
        
        private:
            alignas(8) string f1;
        };


        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(E1 val){
            f2 = val;
        }
        inline E1& get_f2(){
            return f2;
        }
    
        inline M27* mutable_f3(){
            f3 = new M27();
            return f3;
        }
        inline M27*& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M26->f1: " << f1 << std::endl;
            fout << "M26->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M26(){
            if(f3 != nullptr)
                delete f3;
        }
    
        M26(){
           f3 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) E1 f2;
        alignas(8) M27* f3;
    };


    class alignas(8) M28 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 37,
            E1_CONST_2 = 43,
            E1_CONST_3 = 76,
            E1_CONST_4 = 26,
            E1_CONST_5 = 91,
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
        
            inline void set_f2(int64_t val){
                f2 = val;
            }
            inline int64_t& get_f2(){
                return f2;
            }
        
            inline void set_f3(int64_t val){
                f3 = val;
            }
            inline int64_t& get_f3(){
                return f3;
            }
        
            inline void set_f4(bool val){
                f4 = val;
            }
            inline bool& get_f4(){
                return f4;
            }
        
            inline void set_f5(bool val){
                f5 = val;
            }
            inline bool& get_f5(){
                return f5;
            }
        
            inline void set_f6(int64_t val){
                f6 = val;
            }
            inline int64_t& get_f6(){
                return f6;
            }
        
            inline void set_f7(int64_t val){
                f7 = val;
            }
            inline int64_t& get_f7(){
                return f7;
            }
        
            inline void set_f8(bool val){
                f8 = val;
            }
            inline bool& get_f8(){
                return f8;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M29->f1: " << f1 << std::endl;
                fout << "M29->f2: " << f2 << std::endl;
                fout << "M29->f3: " << f3 << std::endl;
                fout << "M29->f4: " << f4 << std::endl;
                fout << "M29->f5: " << f5 << std::endl;
                fout << "M29->f6: " << f6 << std::endl;
                fout << "M29->f7: " << f7 << std::endl;
                fout << "M29->f8: " << f8 << std::endl;
            }
        
            ~M29(){
            }
        
            M29(){
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int64_t f2;
            alignas(8) int64_t f3;
            alignas(8) bool f4;
            alignas(8) bool f5;
            alignas(8) int64_t f6;
            alignas(8) int64_t f7;
            alignas(8) bool f8;
        };


        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline M29* mutable_f2(){
            f2 = new M29();
            return f2;
        }
        inline M29*& get_f2(){
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
    
        inline void set_f5(int64_t val){
            f5 = val;
        }
        inline int64_t& get_f5(){
            return f5;
        }
    
        inline void set_f6(string val){
            f6 = val;
        }
        inline string& get_f6(){
            return f6;
        }
    
        inline void set_f7(E1 val){
            f7 = val;
        }
        inline E1& get_f7(){
            return f7;
        }
    
        inline void set_f8(int32_t val){
            f8 = val;
        }
        inline int32_t& get_f8(){
            return f8;
        }
    
        inline void set_f9(string val){
            f9 = val;
        }
        inline string& get_f9(){
            return f9;
        }
    
        inline void set_f10(bool val){
            f10 = val;
        }
        inline bool& get_f10(){
            return f10;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M28->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M28->f3: " << f3 << std::endl;
            fout << "M28->f4: " << f4 << std::endl;
            fout << "M28->f5: " << f5 << std::endl;
            fout << "M28->f6: " << f6 << std::endl;
            fout << "M28->f7: " << f7 << std::endl;
            fout << "M28->f8: " << f8 << std::endl;
            fout << "M28->f9: " << f9 << std::endl;
            fout << "M28->f10: " << f10 << std::endl;
        }
    
        ~M28(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M28(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) M29* f2;
        alignas(8) int64_t f3;
        alignas(8) int64_t f4;
        alignas(8) int64_t f5;
        alignas(8) string f6;
        alignas(8) E1 f7;
        alignas(8) int32_t f8;
        alignas(8) string f9;
        alignas(8) bool f10;
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

    inline M26* mutable_f6(){
        f6 = new M26();
        return f6;
    }
    inline M26*& get_f6(){
        return f6;
    }

    inline void set_f7(bool val){
        f7 = val;
    }
    inline bool& get_f7(){
        return f7;
    }

    inline void set_f8(string val){
        f8 = val;
    }
    inline string& get_f8(){
        return f8;
    }

    inline void set_f9(string val){
        f9 = val;
    }
    inline string& get_f9(){
        return f9;
    }

    inline void set_f10(string val){
        f10 = val;
    }
    inline string& get_f10(){
        return f10;
    }

    inline void set_f11(bool val){
        f11 = val;
    }
    inline bool& get_f11(){
        return f11;
    }

    inline M28* mutable_f12(){
        f12 = new M28();
        return f12;
    }
    inline M28*& get_f12(){
        return f12;
    }

    inline void set_f13(E1 val){
        f13 = val;
    }
    inline E1& get_f13(){
        return f13;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M25->f1: " << f1 << std::endl;
        fout << "M25->f2: " << f2 << std::endl;
        fout << "M25->f3: " << f3 << std::endl;
        fout << "M25->f4: " << f4 << std::endl;
        fout << "M25->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        fout << "M25->f7: " << f7 << std::endl;
        fout << "M25->f8: " << f8 << std::endl;
        fout << "M25->f9: " << f9 << std::endl;
        fout << "M25->f10: " << f10 << std::endl;
        fout << "M25->f11: " << f11 << std::endl;
        if(f12 != nullptr)
            f12->print_message(fout);
        fout << "M25->f13: " << f13 << std::endl;
    }

    ~M25(){
        if(f6 != nullptr)
            delete f6;
        if(f12 != nullptr)
            delete f12;
    }

    M25(){
       f6 = nullptr;
       f12 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) int64_t f2;
    alignas(8) int64_t f3;
    alignas(8) double f4;
    alignas(8) string f5;
    alignas(8) M26* f6;
    alignas(8) bool f7;
    alignas(8) string f8;
    alignas(8) string f9;
    alignas(8) string f10;
    alignas(8) bool f11;
    alignas(8) M28* f12;
    alignas(8) E1 f13;
};


class alignas(8) M30 : public M_base
{
public:
    class alignas(8) M31 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M31->f1: " << f1 << std::endl;
        }
    
        ~M31(){
        }
    
        M31(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    class alignas(8) M32 : public M_base
    {
    public:
        class alignas(8) M33 : public M_base
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
        
            inline void set_f5(string val){
                f5 = val;
            }
            inline string& get_f5(){
                return f5;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M33->f1: " << f1 << std::endl;
                fout << "M33->f2: " << f2 << std::endl;
                fout << "M33->f3: " << f3 << std::endl;
                fout << "M33->f4: " << f4 << std::endl;
                fout << "M33->f5: " << f5 << std::endl;
            }
        
            ~M33(){
            }
        
            M33(){
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int64_t f2;
            alignas(8) int64_t f3;
            alignas(8) int32_t f4;
            alignas(8) string f5;
        };


        inline M33* mutable_f1(){
            f1 = new M33();
            return f1;
        }
        inline M33*& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint64_t val){
            f2 = val;
        }
        inline uint64_t& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M32->f2: " << f2 << std::endl;
        }
    
        ~M32(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M32(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M33* f1;
        alignas(8) uint64_t f2;
    };


    class alignas(8) M34 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M34->f1: " << f1 << std::endl;
        }
    
        ~M34(){
        }
    
        M34(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    class alignas(8) M35 : public M_base
    {
    public:
        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline void set_f2(string val){
            f2 = val;
        }
        inline string& get_f2(){
            return f2;
        }
    
        inline void set_f3(int32_t val){
            f3 = val;
        }
        inline int32_t& get_f3(){
            return f3;
        }
    
        inline void add_f4(string val){
            f4.push_back(val);
        }
        inline string& get_f4(int idx){
            return f4[idx];
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
    
        inline void set_f8(string val){
            f8 = val;
        }
        inline string& get_f8(){
            return f8;
        }
    
        inline void set_f9(string val){
            f9 = val;
        }
        inline string& get_f9(){
            return f9;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M35->f1: " << f1 << std::endl;
            fout << "M35->f2: " << f2 << std::endl;
            fout << "M35->f3: " << f3 << std::endl;
            for(auto &f4_val : f4){
                fout << "M35->f4: " << f4_val << std::endl;
            }
            fout << "M35->f5: " << f5 << std::endl;
            fout << "M35->f6: " << f6 << std::endl;
            fout << "M35->f7: " << f7 << std::endl;
            fout << "M35->f8: " << f8 << std::endl;
            fout << "M35->f9: " << f9 << std::endl;
        }
    
        ~M35(){
        }
    
        M35(){
        }
    
    private:
        alignas(8) string f1;
        alignas(8) string f2;
        alignas(8) int32_t f3;
        alignas(8) std::vector<string> f4;
        alignas(8) string f5;
        alignas(8) string f6;
        alignas(8) string f7;
        alignas(8) string f8;
        alignas(8) string f9;
    };


    inline M31* mutable_f1(){
        f1 = new M31();
        return f1;
    }
    inline M31*& get_f1(){
        return f1;
    }

    inline M32* mutable_f2(){
        f2 = new M32();
        return f2;
    }
    inline M32*& get_f2(){
        return f2;
    }

    inline M34* mutable_f3(){
        f3 = new M34();
        return f3;
    }
    inline M34*& get_f3(){
        return f3;
    }

    inline void set_f4(bool val){
        f4 = val;
    }
    inline bool& get_f4(){
        return f4;
    }

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline void set_f6(bool val){
        f6 = val;
    }
    inline bool& get_f6(){
        return f6;
    }

    inline void add_f7(string val){
        f7.push_back(val);
    }
    inline string& get_f7(int idx){
        return f7[idx];
    }

    inline void set_f8(int64_t val){
        f8 = val;
    }
    inline int64_t& get_f8(){
        return f8;
    }

    inline void set_f9(string val){
        f9 = val;
    }
    inline string& get_f9(){
        return f9;
    }

    inline void set_f10(int64_t val){
        f10 = val;
    }
    inline int64_t& get_f10(){
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

    inline void set_f13(string val){
        f13 = val;
    }
    inline string& get_f13(){
        return f13;
    }

    inline M35* mutable_f14(){
        f14 = new M35();
        return f14;
    }
    inline M35*& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        if(f2 != nullptr)
            f2->print_message(fout);
        if(f3 != nullptr)
            f3->print_message(fout);
        fout << "M30->f4: " << f4 << std::endl;
        fout << "M30->f5: " << f5 << std::endl;
        fout << "M30->f6: " << f6 << std::endl;
        for(auto &f7_val : f7){
            fout << "M30->f7: " << f7_val << std::endl;
        }
        fout << "M30->f8: " << f8 << std::endl;
        fout << "M30->f9: " << f9 << std::endl;
        fout << "M30->f10: " << f10 << std::endl;
        fout << "M30->f11: " << f11 << std::endl;
        fout << "M30->f12: " << f12 << std::endl;
        fout << "M30->f13: " << f13 << std::endl;
        if(f14 != nullptr)
            f14->print_message(fout);
    }

    ~M30(){
        if(f1 != nullptr)
            delete f1;
        if(f2 != nullptr)
            delete f2;
        if(f3 != nullptr)
            delete f3;
        if(f14 != nullptr)
            delete f14;
    }

    M30(){
       f1 = nullptr;
       f2 = nullptr;
       f3 = nullptr;
       f14 = nullptr;
    }

private:
    alignas(8) M31* f1;
    alignas(8) M32* f2;
    alignas(8) M34* f3;
    alignas(8) bool f4;
    alignas(8) int64_t f5;
    alignas(8) bool f6;
    alignas(8) std::vector<string> f7;
    alignas(8) int64_t f8;
    alignas(8) string f9;
    alignas(8) int64_t f10;
    alignas(8) int64_t f11;
    alignas(8) string f12;
    alignas(8) string f13;
    alignas(8) M35* f14;
};


class alignas(8) M36 : public M_base
{
public:
    class alignas(8) M37 : public M_base
    {
    public:
        class alignas(8) M38 : public M_base
        {
        public:
            inline void set_f1(bool val){
                f1 = val;
            }
            inline bool& get_f1(){
                return f1;
            }
        
            inline void set_f2(int64_t val){
                f2 = val;
            }
            inline int64_t& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M38->f1: " << f1 << std::endl;
                fout << "M38->f2: " << f2 << std::endl;
            }
        
            ~M38(){
            }
        
            M38(){
            }
        
        private:
            alignas(8) bool f1;
            alignas(8) int64_t f2;
        };


        class alignas(8) M39 : public M_base
        {
        public:
            inline void set_f1(double val){
                f1 = val;
            }
            inline double& get_f1(){
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
        
            inline void set_f4(int64_t val){
                f4 = val;
            }
            inline int64_t& get_f4(){
                return f4;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M39->f1: " << f1 << std::endl;
                fout << "M39->f2: " << f2 << std::endl;
                fout << "M39->f3: " << f3 << std::endl;
                fout << "M39->f4: " << f4 << std::endl;
            }
        
            ~M39(){
            }
        
            M39(){
            }
        
        private:
            alignas(8) double f1;
            alignas(8) int64_t f2;
            alignas(8) string f3;
            alignas(8) int64_t f4;
        };


        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline M38* mutable_f2(){
            f2 = new M38();
            return f2;
        }
        inline M38*& get_f2(){
            return f2;
        }
    
        inline M39* mutable_f3(){
            f3 = new M39();
            return f3;
        }
        inline M39*& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M37->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M37(){
            if(f2 != nullptr)
                delete f2;
            if(f3 != nullptr)
                delete f3;
        }
    
        M37(){
           f2 = nullptr;
           f3 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) M38* f2;
        alignas(8) M39* f3;
    };


    class alignas(8) M40 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 67,
            E1_CONST_2 = 38,
            E1_CONST_3 = 10155,
            E1_CONST_4 = 78,
            E1_CONST_5 = 15,
        };
        
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(string val){
            f2 = val;
        }
        inline string& get_f2(){
            return f2;
        }
    
        inline void set_f3(string val){
            f3 = val;
        }
        inline string& get_f3(){
            return f3;
        }
    
        inline void set_f4(int32_t val){
            f4 = val;
        }
        inline int32_t& get_f4(){
            return f4;
        }
    
        inline void set_f5(uint32_t val){
            f5 = val;
        }
        inline uint32_t& get_f5(){
            return f5;
        }
    
        inline void set_f6(E1 val){
            f6 = val;
        }
        inline E1& get_f6(){
            return f6;
        }
    
        inline void set_f7(int64_t val){
            f7 = val;
        }
        inline int64_t& get_f7(){
            return f7;
        }
    
        inline void set_f8(int64_t val){
            f8 = val;
        }
        inline int64_t& get_f8(){
            return f8;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M40->f1: " << f1 << std::endl;
            fout << "M40->f2: " << f2 << std::endl;
            fout << "M40->f3: " << f3 << std::endl;
            fout << "M40->f4: " << f4 << std::endl;
            fout << "M40->f5: " << f5 << std::endl;
            fout << "M40->f6: " << f6 << std::endl;
            fout << "M40->f7: " << f7 << std::endl;
            fout << "M40->f8: " << f8 << std::endl;
        }
    
        ~M40(){
        }
    
        M40(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) string f2;
        alignas(8) string f3;
        alignas(8) int32_t f4;
        alignas(8) uint32_t f5;
        alignas(8) E1 f6;
        alignas(8) int64_t f7;
        alignas(8) int64_t f8;
    };


    class alignas(8) M41 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
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
    
        inline void set_f5(bool val){
            f5 = val;
        }
        inline bool& get_f5(){
            return f5;
        }
    
        inline void set_f6(int32_t val){
            f6 = val;
        }
        inline int32_t& get_f6(){
            return f6;
        }
    
        inline void set_f7(string val){
            f7 = val;
        }
        inline string& get_f7(){
            return f7;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M41->f1: " << f1 << std::endl;
            fout << "M41->f2: " << f2 << std::endl;
            fout << "M41->f3: " << f3 << std::endl;
            fout << "M41->f4: " << f4 << std::endl;
            fout << "M41->f5: " << f5 << std::endl;
            fout << "M41->f6: " << f6 << std::endl;
            fout << "M41->f7: " << f7 << std::endl;
        }
    
        ~M41(){
        }
    
        M41(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) string f2;
        alignas(8) int64_t f3;
        alignas(8) string f4;
        alignas(8) bool f5;
        alignas(8) int32_t f6;
        alignas(8) string f7;
    };


    inline void set_f1(int64_t val){
        f1 = val;
    }
    inline int64_t& get_f1(){
        return f1;
    }

    inline M37* mutable_f2(){
        f2 = new M37();
        return f2;
    }
    inline M37*& get_f2(){
        return f2;
    }

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
        return f3;
    }

    inline void set_f4(int32_t val){
        f4 = val;
    }
    inline int32_t& get_f4(){
        return f4;
    }

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline void set_f6(bool val){
        f6 = val;
    }
    inline bool& get_f6(){
        return f6;
    }

    inline void set_f7(int64_t val){
        f7 = val;
    }
    inline int64_t& get_f7(){
        return f7;
    }

    inline M40* mutable_f8(){
        f8 = new M40();
        return f8;
    }
    inline M40*& get_f8(){
        return f8;
    }

    inline void set_f9(double val){
        f9 = val;
    }
    inline double& get_f9(){
        return f9;
    }

    inline void set_f10(bool val){
        f10 = val;
    }
    inline bool& get_f10(){
        return f10;
    }

    inline void set_f11(double val){
        f11 = val;
    }
    inline double& get_f11(){
        return f11;
    }

    inline void set_f12(int64_t val){
        f12 = val;
    }
    inline int64_t& get_f12(){
        return f12;
    }

    inline M41* mutable_f13(){
        f13 = new M41();
        return f13;
    }
    inline M41*& get_f13(){
        return f13;
    }

    inline void set_f14(int64_t val){
        f14 = val;
    }
    inline int64_t& get_f14(){
        return f14;
    }

    inline void set_f15(uint64_t val){
        f15 = val;
    }
    inline uint64_t& get_f15(){
        return f15;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M36->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M36->f3: " << f3 << std::endl;
        fout << "M36->f4: " << f4 << std::endl;
        fout << "M36->f5: " << f5 << std::endl;
        fout << "M36->f6: " << f6 << std::endl;
        fout << "M36->f7: " << f7 << std::endl;
        if(f8 != nullptr)
            f8->print_message(fout);
        fout << "M36->f9: " << f9 << std::endl;
        fout << "M36->f10: " << f10 << std::endl;
        fout << "M36->f11: " << f11 << std::endl;
        fout << "M36->f12: " << f12 << std::endl;
        if(f13 != nullptr)
            f13->print_message(fout);
        fout << "M36->f14: " << f14 << std::endl;
        fout << "M36->f15: " << f15 << std::endl;
    }

    ~M36(){
        if(f2 != nullptr)
            delete f2;
        if(f8 != nullptr)
            delete f8;
        if(f13 != nullptr)
            delete f13;
    }

    M36(){
       f2 = nullptr;
       f8 = nullptr;
       f13 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) M37* f2;
    alignas(8) string f3;
    alignas(8) int32_t f4;
    alignas(8) int64_t f5;
    alignas(8) bool f6;
    alignas(8) int64_t f7;
    alignas(8) M40* f8;
    alignas(8) double f9;
    alignas(8) bool f10;
    alignas(8) double f11;
    alignas(8) int64_t f12;
    alignas(8) M41* f13;
    alignas(8) int64_t f14;
    alignas(8) uint64_t f15;
};


class alignas(8) M42 : public M_base
{
public:
    class alignas(8) M43 : public M_base
    {
    public:
        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
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
    
        inline void add_f4(string val){
            f4.push_back(val);
        }
        inline string& get_f4(int idx){
            return f4[idx];
        }
    
        inline void set_f5(int64_t val){
            f5 = val;
        }
        inline int64_t& get_f5(){
            return f5;
        }
    
        inline void set_f6(int64_t val){
            f6 = val;
        }
        inline int64_t& get_f6(){
            return f6;
        }
    
        inline void set_f7(int64_t val){
            f7 = val;
        }
        inline int64_t& get_f7(){
            return f7;
        }
    
        inline void set_f8(string val){
            f8 = val;
        }
        inline string& get_f8(){
            return f8;
        }
    
        inline void set_f9(int64_t val){
            f9 = val;
        }
        inline int64_t& get_f9(){
            return f9;
        }
    
        inline void set_f10(int64_t val){
            f10 = val;
        }
        inline int64_t& get_f10(){
            return f10;
        }
    
        inline void set_f11(string val){
            f11 = val;
        }
        inline string& get_f11(){
            return f11;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M43->f1: " << f1 << std::endl;
            fout << "M43->f2: " << f2 << std::endl;
            fout << "M43->f3: " << f3 << std::endl;
            for(auto &f4_val : f4){
                fout << "M43->f4: " << f4_val << std::endl;
            }
            fout << "M43->f5: " << f5 << std::endl;
            fout << "M43->f6: " << f6 << std::endl;
            fout << "M43->f7: " << f7 << std::endl;
            fout << "M43->f8: " << f8 << std::endl;
            fout << "M43->f9: " << f9 << std::endl;
            fout << "M43->f10: " << f10 << std::endl;
            fout << "M43->f11: " << f11 << std::endl;
        }
    
        ~M43(){
        }
    
        M43(){
        }
    
    private:
        alignas(8) string f1;
        alignas(8) string f2;
        alignas(8) int64_t f3;
        alignas(8) std::vector<string> f4;
        alignas(8) int64_t f5;
        alignas(8) int64_t f6;
        alignas(8) int64_t f7;
        alignas(8) string f8;
        alignas(8) int64_t f9;
        alignas(8) int64_t f10;
        alignas(8) string f11;
    };


    class alignas(8) M44 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 37,
            E1_CONST_2 = 49,
            E1_CONST_3 = 88,
            E1_CONST_4 = 120,
            E1_CONST_5 = 125,
        };
        
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(E1 val){
            f2 = val;
        }
        inline E1& get_f2(){
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
    
        inline void set_f7(int32_t val){
            f7 = val;
        }
        inline int32_t& get_f7(){
            return f7;
        }
    
        inline void set_f8(int64_t val){
            f8 = val;
        }
        inline int64_t& get_f8(){
            return f8;
        }
    
        inline void set_f9(string val){
            f9 = val;
        }
        inline string& get_f9(){
            return f9;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M44->f1: " << f1 << std::endl;
            fout << "M44->f2: " << f2 << std::endl;
            fout << "M44->f3: " << f3 << std::endl;
            fout << "M44->f4: " << f4 << std::endl;
            fout << "M44->f5: " << f5 << std::endl;
            fout << "M44->f6: " << f6 << std::endl;
            fout << "M44->f7: " << f7 << std::endl;
            fout << "M44->f8: " << f8 << std::endl;
            fout << "M44->f9: " << f9 << std::endl;
        }
    
        ~M44(){
        }
    
        M44(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) E1 f2;
        alignas(8) int64_t f3;
        alignas(8) int64_t f4;
        alignas(8) string f5;
        alignas(8) int32_t f6;
        alignas(8) int32_t f7;
        alignas(8) int64_t f8;
        alignas(8) string f9;
    };


    class alignas(8) M45 : public M_base
    {
    public:
        class alignas(8) M46 : public M_base
        {
        public:
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
        
            inline void set_f3(int64_t val){
                f3 = val;
            }
            inline int64_t& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M46->f1: " << f1 << std::endl;
                fout << "M46->f2: " << f2 << std::endl;
                fout << "M46->f3: " << f3 << std::endl;
            }
        
            ~M46(){
            }
        
            M46(){
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) int64_t f2;
            alignas(8) int64_t f3;
        };


        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline M46* mutable_f2(){
            f2 = new M46();
            return f2;
        }
        inline M46*& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M45->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
        }
    
        ~M45(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M45(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) M46* f2;
    };


    class alignas(8) M47 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M47->f1: " << f1 << std::endl;
        }
    
        ~M47(){
        }
    
        M47(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    inline void set_f1(string val){
        f1 = val;
    }
    inline string& get_f1(){
        return f1;
    }

    inline void set_f2(string val){
        f2 = val;
    }
    inline string& get_f2(){
        return f2;
    }

    inline void set_f3(uint64_t val){
        f3 = val;
    }
    inline uint64_t& get_f3(){
        return f3;
    }

    inline void set_f4(int64_t val){
        f4 = val;
    }
    inline int64_t& get_f4(){
        return f4;
    }

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
        return f6;
    }

    inline M43* mutable_f7(){
        f7 = new M43();
        return f7;
    }
    inline M43*& get_f7(){
        return f7;
    }

    inline void set_f8(int64_t val){
        f8 = val;
    }
    inline int64_t& get_f8(){
        return f8;
    }

    inline M44* mutable_f9(){
        f9 = new M44();
        return f9;
    }
    inline M44*& get_f9(){
        return f9;
    }

    inline M45* mutable_f10(){
        f10 = new M45();
        return f10;
    }
    inline M45*& get_f10(){
        return f10;
    }

    inline void set_f11(double val){
        f11 = val;
    }
    inline double& get_f11(){
        return f11;
    }

    inline void set_f12(bool val){
        f12 = val;
    }
    inline bool& get_f12(){
        return f12;
    }

    inline void set_f13(string val){
        f13 = val;
    }
    inline string& get_f13(){
        return f13;
    }

    inline M47* mutable_f14(){
        f14 = new M47();
        return f14;
    }
    inline M47*& get_f14(){
        return f14;
    }

    inline void set_f15(int64_t val){
        f15 = val;
    }
    inline int64_t& get_f15(){
        return f15;
    }

    inline void set_f16(string val){
        f16 = val;
    }
    inline string& get_f16(){
        return f16;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M42->f1: " << f1 << std::endl;
        fout << "M42->f2: " << f2 << std::endl;
        fout << "M42->f3: " << f3 << std::endl;
        fout << "M42->f4: " << f4 << std::endl;
        fout << "M42->f5: " << f5 << std::endl;
        fout << "M42->f6: " << f6 << std::endl;
        if(f7 != nullptr)
            f7->print_message(fout);
        fout << "M42->f8: " << f8 << std::endl;
        if(f9 != nullptr)
            f9->print_message(fout);
        if(f10 != nullptr)
            f10->print_message(fout);
        fout << "M42->f11: " << f11 << std::endl;
        fout << "M42->f12: " << f12 << std::endl;
        fout << "M42->f13: " << f13 << std::endl;
        if(f14 != nullptr)
            f14->print_message(fout);
        fout << "M42->f15: " << f15 << std::endl;
        fout << "M42->f16: " << f16 << std::endl;
    }

    ~M42(){
        if(f7 != nullptr)
            delete f7;
        if(f9 != nullptr)
            delete f9;
        if(f10 != nullptr)
            delete f10;
        if(f14 != nullptr)
            delete f14;
    }

    M42(){
       f7 = nullptr;
       f9 = nullptr;
       f10 = nullptr;
       f14 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) string f2;
    alignas(8) uint64_t f3;
    alignas(8) int64_t f4;
    alignas(8) int64_t f5;
    alignas(8) int64_t f6;
    alignas(8) M43* f7;
    alignas(8) int64_t f8;
    alignas(8) M44* f9;
    alignas(8) M45* f10;
    alignas(8) double f11;
    alignas(8) bool f12;
    alignas(8) string f13;
    alignas(8) M47* f14;
    alignas(8) int64_t f15;
    alignas(8) string f16;
};


class alignas(8) M48 : public M_base
{
public:
    class alignas(8) M49 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M49->f1: " << f1 << std::endl;
        }
    
        ~M49(){
        }
    
        M49(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    class alignas(8) M50 : public M_base
    {
    public:
        class alignas(8) M51 : public M_base
        {
        public:
            inline void set_f1(string val){
                f1 = val;
            }
            inline string& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M51->f1: " << f1 << std::endl;
            }
        
            ~M51(){
            }
        
            M51(){
            }
        
        private:
            alignas(8) string f1;
        };


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
    
        inline M51* mutable_f3(){
            f3 = new M51();
            return f3;
        }
        inline M51*& get_f3(){
            return f3;
        }
    
        inline void set_f4(int64_t val){
            f4 = val;
        }
        inline int64_t& get_f4(){
            return f4;
        }
    
        inline void add_f5(string val){
            f5.push_back(val);
        }
        inline string& get_f5(int idx){
            return f5[idx];
        }
    
        inline void set_f6(int64_t val){
            f6 = val;
        }
        inline int64_t& get_f6(){
            return f6;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M50->f1: " << f1 << std::endl;
            fout << "M50->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
            fout << "M50->f4: " << f4 << std::endl;
            for(auto &f5_val : f5){
                fout << "M50->f5: " << f5_val << std::endl;
            }
            fout << "M50->f6: " << f6 << std::endl;
        }
    
        ~M50(){
            if(f3 != nullptr)
                delete f3;
        }
    
        M50(){
           f3 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) int64_t f2;
        alignas(8) M51* f3;
        alignas(8) int64_t f4;
        alignas(8) std::vector<string> f5;
        alignas(8) int64_t f6;
    };


    inline void set_f1(string val){
        f1 = val;
    }
    inline string& get_f1(){
        return f1;
    }

    inline void set_f2(double val){
        f2 = val;
    }
    inline double& get_f2(){
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

    inline M49* mutable_f5(){
        f5 = new M49();
        return f5;
    }
    inline M49*& get_f5(){
        return f5;
    }

    inline M50* mutable_f6(){
        f6 = new M50();
        return f6;
    }
    inline M50*& get_f6(){
        return f6;
    }

    inline void set_f7(string val){
        f7 = val;
    }
    inline string& get_f7(){
        return f7;
    }

    inline void set_f8(int64_t val){
        f8 = val;
    }
    inline int64_t& get_f8(){
        return f8;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M48->f1: " << f1 << std::endl;
        fout << "M48->f2: " << f2 << std::endl;
        fout << "M48->f3: " << f3 << std::endl;
        fout << "M48->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        if(f6 != nullptr)
            f6->print_message(fout);
        fout << "M48->f7: " << f7 << std::endl;
        fout << "M48->f8: " << f8 << std::endl;
    }

    ~M48(){
        if(f5 != nullptr)
            delete f5;
        if(f6 != nullptr)
            delete f6;
    }

    M48(){
       f5 = nullptr;
       f6 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) double f2;
    alignas(8) int64_t f3;
    alignas(8) string f4;
    alignas(8) M49* f5;
    alignas(8) M50* f6;
    alignas(8) string f7;
    alignas(8) int64_t f8;
};


class alignas(8) M52 : public M_base
{
public:
    class alignas(8) M53 : public M_base
    {
    public:
        inline void set_f1(uint64_t val){
            f1 = val;
        }
        inline uint64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M53->f1: " << f1 << std::endl;
        }
    
        ~M53(){
        }
    
        M53(){
        }
    
    private:
        alignas(8) uint64_t f1;
    };


    class alignas(8) M54 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint64_t val){
            f2 = val;
        }
        inline uint64_t& get_f2(){
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
    
        inline void set_f5(int64_t val){
            f5 = val;
        }
        inline int64_t& get_f5(){
            return f5;
        }
    
        inline void set_f6(string val){
            f6 = val;
        }
        inline string& get_f6(){
            return f6;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M54->f1: " << f1 << std::endl;
            fout << "M54->f2: " << f2 << std::endl;
            fout << "M54->f3: " << f3 << std::endl;
            fout << "M54->f4: " << f4 << std::endl;
            fout << "M54->f5: " << f5 << std::endl;
            fout << "M54->f6: " << f6 << std::endl;
        }
    
        ~M54(){
        }
    
        M54(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) uint64_t f2;
        alignas(8) int64_t f3;
        alignas(8) int64_t f4;
        alignas(8) int64_t f5;
        alignas(8) string f6;
    };


    class alignas(8) M55 : public M_base
    {
    public:
        inline void set_f1(int64_t val){
            f1 = val;
        }
        inline int64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M55->f1: " << f1 << std::endl;
        }
    
        ~M55(){
        }
    
        M55(){
        }
    
    private:
        alignas(8) int64_t f1;
    };


    class alignas(8) M56 : public M_base
    {
    public:
        class alignas(8) M57 : public M_base
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
        
            inline void set_f3(string val){
                f3 = val;
            }
            inline string& get_f3(){
                return f3;
            }
        
            inline void set_f4(int64_t val){
                f4 = val;
            }
            inline int64_t& get_f4(){
                return f4;
            }
        
            inline void set_f5(int64_t val){
                f5 = val;
            }
            inline int64_t& get_f5(){
                return f5;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M57->f1: " << f1 << std::endl;
                fout << "M57->f2: " << f2 << std::endl;
                fout << "M57->f3: " << f3 << std::endl;
                fout << "M57->f4: " << f4 << std::endl;
                fout << "M57->f5: " << f5 << std::endl;
            }
        
            ~M57(){
            }
        
            M57(){
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int32_t f2;
            alignas(8) string f3;
            alignas(8) int64_t f4;
            alignas(8) int64_t f5;
        };


        inline M57* mutable_f1(){
            f1 = new M57();
            return f1;
        }
        inline M57*& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M56->f2: " << f2 << std::endl;
        }
    
        ~M56(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M56(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M57* f1;
        alignas(8) int32_t f2;
    };


    inline void set_f1(int64_t val){
        f1 = val;
    }
    inline int64_t& get_f1(){
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

    inline void set_f4(int32_t val){
        f4 = val;
    }
    inline int32_t& get_f4(){
        return f4;
    }

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
        return f6;
    }

    inline void set_f7(uint64_t val){
        f7 = val;
    }
    inline uint64_t& get_f7(){
        return f7;
    }

    inline M53* mutable_f8(){
        f8 = new M53();
        return f8;
    }
    inline M53*& get_f8(){
        return f8;
    }

    inline M54* mutable_f9(){
        f9 = new M54();
        return f9;
    }
    inline M54*& get_f9(){
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

    inline M55* mutable_f12(){
        f12 = new M55();
        return f12;
    }
    inline M55*& get_f12(){
        return f12;
    }

    inline M56* mutable_f13(){
        f13 = new M56();
        return f13;
    }
    inline M56*& get_f13(){
        return f13;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M52->f1: " << f1 << std::endl;
        fout << "M52->f2: " << f2 << std::endl;
        fout << "M52->f3: " << f3 << std::endl;
        fout << "M52->f4: " << f4 << std::endl;
        fout << "M52->f5: " << f5 << std::endl;
        fout << "M52->f6: " << f6 << std::endl;
        fout << "M52->f7: " << f7 << std::endl;
        if(f8 != nullptr)
            f8->print_message(fout);
        if(f9 != nullptr)
            f9->print_message(fout);
        fout << "M52->f10: " << f10 << std::endl;
        fout << "M52->f11: " << f11 << std::endl;
        if(f12 != nullptr)
            f12->print_message(fout);
        if(f13 != nullptr)
            f13->print_message(fout);
    }

    ~M52(){
        if(f8 != nullptr)
            delete f8;
        if(f9 != nullptr)
            delete f9;
        if(f12 != nullptr)
            delete f12;
        if(f13 != nullptr)
            delete f13;
    }

    M52(){
       f8 = nullptr;
       f9 = nullptr;
       f12 = nullptr;
       f13 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) string f2;
    alignas(8) int64_t f3;
    alignas(8) int32_t f4;
    alignas(8) int64_t f5;
    alignas(8) int64_t f6;
    alignas(8) uint64_t f7;
    alignas(8) M53* f8;
    alignas(8) M54* f9;
    alignas(8) string f10;
    alignas(8) int64_t f11;
    alignas(8) M55* f12;
    alignas(8) M56* f13;
};

M_base* createMessage(int temp_class_id) {
    switch (temp_class_id) {
        case 10:
            return new M10();
        case 13:
            return new M10::M13();
        case 14:
            return new M10::M14();
        case 11:
            return new M10::M11();
        case 12:
            return new M10::M11::M12();
        case 15:
            return new M15();
        case 20:
            return new M15::M20();
        case 17:
            return new M15::M17();
        case 19:
            return new M15::M17::M19();
        case 18:
            return new M15::M17::M18();
        case 16:
            return new M15::M16();
        case 1:
            return new M1();
        case 3:
            return new M1::M3();
        case 7:
            return new M1::M7();
        case 4:
            return new M1::M4();
        case 5:
            return new M1::M4::M5();
        case 6:
            return new M1::M4::M6();
        case 2:
            return new M1::M2();
        case 8:
            return new M1::M8();
        case 9:
            return new M1::M8::M9();
        case 21:
            return new M21();
        case 22:
            return new M21::M22();
        case 23:
            return new M21::M23();
        case 24:
            return new M21::M23::M24();
        case 25:
            return new M25();
        case 26:
            return new M25::M26();
        case 27:
            return new M25::M26::M27();
        case 28:
            return new M25::M28();
        case 29:
            return new M25::M28::M29();
        case 30:
            return new M30();
        case 34:
            return new M30::M34();
        case 32:
            return new M30::M32();
        case 33:
            return new M30::M32::M33();
        case 35:
            return new M30::M35();
        case 31:
            return new M30::M31();
        case 36:
            return new M36();
        case 41:
            return new M36::M41();
        case 40:
            return new M36::M40();
        case 37:
            return new M36::M37();
        case 39:
            return new M36::M37::M39();
        case 38:
            return new M36::M37::M38();
        case 42:
            return new M42();
        case 47:
            return new M42::M47();
        case 44:
            return new M42::M44();
        case 43:
            return new M42::M43();
        case 45:
            return new M42::M45();
        case 46:
            return new M42::M45::M46();
        case 48:
            return new M48();
        case 50:
            return new M48::M50();
        case 51:
            return new M48::M50::M51();
        case 49:
            return new M48::M49();
        case 52:
            return new M52();
        case 56:
            return new M52::M56();
        case 57:
            return new M52::M56::M57();
        case 53:
            return new M52::M53();
        case 55:
            return new M52::M55();
        case 54:
            return new M52::M54();
        default:
            throw std::invalid_argument("Invalid class id");
    }
}

size_t getMessageSize(int temp_class_id) {
    switch (temp_class_id) {
        case 10:
            return sizeof(M10);
        case 13:
            return sizeof(M10::M13);
        case 14:
            return sizeof(M10::M14);
        case 11:
            return sizeof(M10::M11);
        case 12:
            return sizeof(M10::M11::M12);
        case 15:
            return sizeof(M15);
        case 20:
            return sizeof(M15::M20);
        case 17:
            return sizeof(M15::M17);
        case 19:
            return sizeof(M15::M17::M19);
        case 18:
            return sizeof(M15::M17::M18);
        case 16:
            return sizeof(M15::M16);
        case 1:
            return sizeof(M1);
        case 3:
            return sizeof(M1::M3);
        case 7:
            return sizeof(M1::M7);
        case 4:
            return sizeof(M1::M4);
        case 5:
            return sizeof(M1::M4::M5);
        case 6:
            return sizeof(M1::M4::M6);
        case 2:
            return sizeof(M1::M2);
        case 8:
            return sizeof(M1::M8);
        case 9:
            return sizeof(M1::M8::M9);
        case 21:
            return sizeof(M21);
        case 22:
            return sizeof(M21::M22);
        case 23:
            return sizeof(M21::M23);
        case 24:
            return sizeof(M21::M23::M24);
        case 25:
            return sizeof(M25);
        case 26:
            return sizeof(M25::M26);
        case 27:
            return sizeof(M25::M26::M27);
        case 28:
            return sizeof(M25::M28);
        case 29:
            return sizeof(M25::M28::M29);
        case 30:
            return sizeof(M30);
        case 34:
            return sizeof(M30::M34);
        case 32:
            return sizeof(M30::M32);
        case 33:
            return sizeof(M30::M32::M33);
        case 35:
            return sizeof(M30::M35);
        case 31:
            return sizeof(M30::M31);
        case 36:
            return sizeof(M36);
        case 41:
            return sizeof(M36::M41);
        case 40:
            return sizeof(M36::M40);
        case 37:
            return sizeof(M36::M37);
        case 39:
            return sizeof(M36::M37::M39);
        case 38:
            return sizeof(M36::M37::M38);
        case 42:
            return sizeof(M42);
        case 47:
            return sizeof(M42::M47);
        case 44:
            return sizeof(M42::M44);
        case 43:
            return sizeof(M42::M43);
        case 45:
            return sizeof(M42::M45);
        case 46:
            return sizeof(M42::M45::M46);
        case 48:
            return sizeof(M48);
        case 50:
            return sizeof(M48::M50);
        case 51:
            return sizeof(M48::M50::M51);
        case 49:
            return sizeof(M48::M49);
        case 52:
            return sizeof(M52);
        case 56:
            return sizeof(M52::M56);
        case 57:
            return sizeof(M52::M56::M57);
        case 53:
            return sizeof(M52::M53);
        case 55:
            return sizeof(M52::M55);
        case 54:
            return sizeof(M52::M54);
        default:
            return 0;
    }
}


