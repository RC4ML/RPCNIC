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
    class alignas(8) M2 : public M_base
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
    
        inline void set_f3(string val){
            f3 = val;
        }
        inline string& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M2->f1: " << f1 << std::endl;
            fout << "M2->f2: " << f2 << std::endl;
            fout << "M2->f3: " << f3 << std::endl;
        }
    
        ~M2(){
        }
    
        M2(){
        }
    
    private:
        alignas(8) string f1;
        alignas(8) string f2;
        alignas(8) string f3;
    };


    inline void set_f1(string val){
        f1 = val;
    }
    inline string& get_f1(){
        return f1;
    }

    inline M2* mutable_f2(){
        f2 = new M2();
        return f2;
    }
    inline M2*& get_f2(){
        return f2;
    }

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
        return f3;
    }

    inline void set_f4(float val){
        f4 = val;
    }
    inline float& get_f4(){
        return f4;
    }

    inline void set_f5(float val){
        f5 = val;
    }
    inline float& get_f5(){
        return f5;
    }

    inline void set_f6(uint32_t val){
        f6 = val;
    }
    inline uint32_t& get_f6(){
        return f6;
    }

    inline void set_f7(int64_t val){
        f7 = val;
    }
    inline int64_t& get_f7(){
        return f7;
    }

    inline void set_f8(int32_t val){
        f8 = val;
    }
    inline int32_t& get_f8(){
        return f8;
    }

    inline void set_f9(int64_t val){
        f9 = val;
    }
    inline int64_t& get_f9(){
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

    inline void print_message(std::ofstream &fout){
        fout << "M1->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M1->f3: " << f3 << std::endl;
        fout << "M1->f4: " << f4 << std::endl;
        fout << "M1->f5: " << f5 << std::endl;
        fout << "M1->f6: " << f6 << std::endl;
        fout << "M1->f7: " << f7 << std::endl;
        fout << "M1->f8: " << f8 << std::endl;
        fout << "M1->f9: " << f9 << std::endl;
        fout << "M1->f10: " << f10 << std::endl;
        fout << "M1->f11: " << f11 << std::endl;
    }

    ~M1(){
        if(f2 != nullptr)
            delete f2;
    }

    M1(){
       f2 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) M2* f2;
    alignas(8) string f3;
    alignas(8) float f4;
    alignas(8) float f5;
    alignas(8) uint32_t f6;
    alignas(8) int64_t f7;
    alignas(8) int32_t f8;
    alignas(8) int64_t f9;
    alignas(8) bool f10;
    alignas(8) int64_t f11;
};


class alignas(8) M3 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 8,
        E1_CONST_2 = 108,
        E1_CONST_3 = 110,
        E1_CONST_4 = 16,
        E1_CONST_5 = 123,
    };
    
    class alignas(8) M4 : public M_base
    {
    public:
        inline void set_f1(float val){
            f1 = val;
        }
        inline float& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
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
        alignas(8) float f1;
        alignas(8) int32_t f2;
    };


    inline void set_f1(uint32_t val){
        f1 = val;
    }
    inline uint32_t& get_f1(){
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

    inline void set_f4(float val){
        f4 = val;
    }
    inline float& get_f4(){
        return f4;
    }

    inline void set_f5(float val){
        f5 = val;
    }
    inline float& get_f5(){
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

    inline void set_f8(E1 val){
        f8 = val;
    }
    inline E1& get_f8(){
        return f8;
    }

    inline M4* mutable_f9(){
        f9 = new M4();
        return f9;
    }
    inline M4*& get_f9(){
        return f9;
    }

    inline void set_f10(float val){
        f10 = val;
    }
    inline float& get_f10(){
        return f10;
    }

    inline void set_f11(string val){
        f11 = val;
    }
    inline string& get_f11(){
        return f11;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M3->f1: " << f1 << std::endl;
        fout << "M3->f2: " << f2 << std::endl;
        fout << "M3->f3: " << f3 << std::endl;
        fout << "M3->f4: " << f4 << std::endl;
        fout << "M3->f5: " << f5 << std::endl;
        fout << "M3->f6: " << f6 << std::endl;
        fout << "M3->f7: " << f7 << std::endl;
        fout << "M3->f8: " << f8 << std::endl;
        if(f9 != nullptr)
            f9->print_message(fout);
        fout << "M3->f10: " << f10 << std::endl;
        fout << "M3->f11: " << f11 << std::endl;
    }

    ~M3(){
        if(f9 != nullptr)
            delete f9;
    }

    M3(){
       f9 = nullptr;
    }

private:
    alignas(8) uint32_t f1;
    alignas(8) int32_t f2;
    alignas(8) string f3;
    alignas(8) float f4;
    alignas(8) float f5;
    alignas(8) string f6;
    alignas(8) string f7;
    alignas(8) E1 f8;
    alignas(8) M4* f9;
    alignas(8) float f10;
    alignas(8) string f11;
};


class alignas(8) M5 : public M_base
{
public:
    class alignas(8) M6 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
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
        alignas(8) int32_t f1;
    };


    class alignas(8) M7 : public M_base
    {
    public:
        class alignas(8) M8 : public M_base
        {
        public:
            inline void set_f1(bool val){
                f1 = val;
            }
            inline bool& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M8->f1: " << f1 << std::endl;
            }
        
            ~M8(){
            }
        
            M8(){
            }
        
        private:
            alignas(8) bool f1;
        };


        inline M8* mutable_f1(){
            f1 = new M8();
            return f1;
        }
        inline M8*& get_f1(){
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
            fout << "M7->f2: " << f2 << std::endl;
        }
    
        ~M7(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M7(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M8* f1;
        alignas(8) string f2;
    };


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

    inline void set_f3(float val){
        f3 = val;
    }
    inline float& get_f3(){
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

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
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

    inline void set_f9(int64_t val){
        f9 = val;
    }
    inline int64_t& get_f9(){
        return f9;
    }

    inline void set_f10(float val){
        f10 = val;
    }
    inline float& get_f10(){
        return f10;
    }

    inline void set_f11(bool val){
        f11 = val;
    }
    inline bool& get_f11(){
        return f11;
    }

    inline M6* mutable_f12(){
        f12 = new M6();
        return f12;
    }
    inline M6*& get_f12(){
        return f12;
    }

    inline void set_f13(int32_t val){
        f13 = val;
    }
    inline int32_t& get_f13(){
        return f13;
    }

    inline M7* mutable_f14(){
        f14 = new M7();
        return f14;
    }
    inline M7*& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M5->f1: " << f1 << std::endl;
        fout << "M5->f2: " << f2 << std::endl;
        fout << "M5->f3: " << f3 << std::endl;
        fout << "M5->f4: " << f4 << std::endl;
        fout << "M5->f5: " << f5 << std::endl;
        fout << "M5->f6: " << f6 << std::endl;
        fout << "M5->f7: " << f7 << std::endl;
        fout << "M5->f8: " << f8 << std::endl;
        fout << "M5->f9: " << f9 << std::endl;
        fout << "M5->f10: " << f10 << std::endl;
        fout << "M5->f11: " << f11 << std::endl;
        if(f12 != nullptr)
            f12->print_message(fout);
        fout << "M5->f13: " << f13 << std::endl;
        if(f14 != nullptr)
            f14->print_message(fout);
    }

    ~M5(){
        if(f12 != nullptr)
            delete f12;
        if(f14 != nullptr)
            delete f14;
    }

    M5(){
       f12 = nullptr;
       f14 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int32_t f2;
    alignas(8) float f3;
    alignas(8) int32_t f4;
    alignas(8) bool f5;
    alignas(8) int64_t f6;
    alignas(8) int32_t f7;
    alignas(8) int64_t f8;
    alignas(8) int64_t f9;
    alignas(8) float f10;
    alignas(8) bool f11;
    alignas(8) M6* f12;
    alignas(8) int32_t f13;
    alignas(8) M7* f14;
};


class alignas(8) M9 : public M_base
{
public:
    class alignas(8) M10 : public M_base
    {
    public:
        class alignas(8) M11 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void set_f2(float val){
                f2 = val;
            }
            inline float& get_f2(){
                return f2;
            }
        
            inline void set_f3(float val){
                f3 = val;
            }
            inline float& get_f3(){
                return f3;
            }
        
            inline void set_f4(int32_t val){
                f4 = val;
            }
            inline int32_t& get_f4(){
                return f4;
            }
        
            inline void set_f5(int32_t val){
                f5 = val;
            }
            inline int32_t& get_f5(){
                return f5;
            }
        
            inline void set_f6(float val){
                f6 = val;
            }
            inline float& get_f6(){
                return f6;
            }
        
            inline void set_f7(bool val){
                f7 = val;
            }
            inline bool& get_f7(){
                return f7;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M11->f1: " << f1 << std::endl;
                fout << "M11->f2: " << f2 << std::endl;
                fout << "M11->f3: " << f3 << std::endl;
                fout << "M11->f4: " << f4 << std::endl;
                fout << "M11->f5: " << f5 << std::endl;
                fout << "M11->f6: " << f6 << std::endl;
                fout << "M11->f7: " << f7 << std::endl;
            }
        
            ~M11(){
            }
        
            M11(){
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) float f2;
            alignas(8) float f3;
            alignas(8) int32_t f4;
            alignas(8) int32_t f5;
            alignas(8) float f6;
            alignas(8) bool f7;
        };


        inline M11* mutable_f1(){
            f1 = new M11();
            return f1;
        }
        inline M11*& get_f1(){
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
            fout << "M10->f2: " << f2 << std::endl;
        }
    
        ~M10(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M10(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M11* f1;
        alignas(8) uint64_t f2;
    };


    class alignas(8) M12 : public M_base
    {
    public:
        inline void add_f1(int32_t val){
            f1.push_back(val);
        }
        inline int32_t& get_f1(int idx){
            return f1[idx];
        }
    
        inline void add_f2(int32_t val){
            f2.push_back(val);
        }
        inline int32_t& get_f2(int idx){
            return f2[idx];
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
    
        inline void set_f5(float val){
            f5 = val;
        }
        inline float& get_f5(){
            return f5;
        }
    
        inline void set_f6(int32_t val){
            f6 = val;
        }
        inline int32_t& get_f6(){
            return f6;
        }
    
        inline void set_f7(bool val){
            f7 = val;
        }
        inline bool& get_f7(){
            return f7;
        }
    
        inline void print_message(std::ofstream &fout){
            for(auto &f1_val : f1){
                fout << "M12->f1: " << f1_val << std::endl;
            }
            for(auto &f2_val : f2){
                fout << "M12->f2: " << f2_val << std::endl;
            }
            fout << "M12->f3: " << f3 << std::endl;
            fout << "M12->f4: " << f4 << std::endl;
            fout << "M12->f5: " << f5 << std::endl;
            fout << "M12->f6: " << f6 << std::endl;
            fout << "M12->f7: " << f7 << std::endl;
        }
    
        ~M12(){
        }
    
        M12(){
        }
    
    private:
        alignas(8) std::vector<int32_t> f1;
        alignas(8) std::vector<int32_t> f2;
        alignas(8) string f3;
        alignas(8) int32_t f4;
        alignas(8) float f5;
        alignas(8) int32_t f6;
        alignas(8) bool f7;
    };


    inline void add_f1(uint32_t val){
        f1.push_back(val);
    }
    inline uint32_t& get_f1(int idx){
        return f1[idx];
    }

    inline M10* mutable_f2(){
        f2 = new M10();
        return f2;
    }
    inline M10*& get_f2(){
        return f2;
    }

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
        return f3;
    }

    inline void set_f4(float val){
        f4 = val;
    }
    inline float& get_f4(){
        return f4;
    }

    inline M12* mutable_f5(){
        f5 = new M12();
        return f5;
    }
    inline M12*& get_f5(){
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

    inline void set_f8(int32_t val){
        f8 = val;
    }
    inline int32_t& get_f8(){
        return f8;
    }

    inline void set_f9(float val){
        f9 = val;
    }
    inline float& get_f9(){
        return f9;
    }

    inline void set_f10(bool val){
        f10 = val;
    }
    inline bool& get_f10(){
        return f10;
    }

    inline void set_f11(float val){
        f11 = val;
    }
    inline float& get_f11(){
        return f11;
    }

    inline void set_f12(int64_t val){
        f12 = val;
    }
    inline int64_t& get_f12(){
        return f12;
    }

    inline void set_f13(float val){
        f13 = val;
    }
    inline float& get_f13(){
        return f13;
    }

    inline void set_f14(int64_t val){
        f14 = val;
    }
    inline int64_t& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        for(auto &f1_val : f1){
            fout << "M9->f1: " << f1_val << std::endl;
        }
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M9->f3: " << f3 << std::endl;
        fout << "M9->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        fout << "M9->f6: " << f6 << std::endl;
        fout << "M9->f7: " << f7 << std::endl;
        fout << "M9->f8: " << f8 << std::endl;
        fout << "M9->f9: " << f9 << std::endl;
        fout << "M9->f10: " << f10 << std::endl;
        fout << "M9->f11: " << f11 << std::endl;
        fout << "M9->f12: " << f12 << std::endl;
        fout << "M9->f13: " << f13 << std::endl;
        fout << "M9->f14: " << f14 << std::endl;
    }

    ~M9(){
        if(f2 != nullptr)
            delete f2;
        if(f5 != nullptr)
            delete f5;
    }

    M9(){
       f2 = nullptr;
       f5 = nullptr;
    }

private:
    alignas(8) std::vector<uint32_t> f1;
    alignas(8) M10* f2;
    alignas(8) string f3;
    alignas(8) float f4;
    alignas(8) M12* f5;
    alignas(8) int32_t f6;
    alignas(8) string f7;
    alignas(8) int32_t f8;
    alignas(8) float f9;
    alignas(8) bool f10;
    alignas(8) float f11;
    alignas(8) int64_t f12;
    alignas(8) float f13;
    alignas(8) int64_t f14;
};


class alignas(8) M13 : public M_base
{
public:
    class alignas(8) M14 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M14->f1: " << f1 << std::endl;
        }
    
        ~M14(){
        }
    
        M14(){
        }
    
    private:
        alignas(8) int32_t f1;
    };


    inline void set_f1(float val){
        f1 = val;
    }
    inline float& get_f1(){
        return f1;
    }

    inline M14* mutable_f2(){
        f2 = new M14();
        return f2;
    }
    inline M14*& get_f2(){
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

    inline void set_f7(bool val){
        f7 = val;
    }
    inline bool& get_f7(){
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

    inline void print_message(std::ofstream &fout){
        fout << "M13->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M13->f3: " << f3 << std::endl;
        fout << "M13->f4: " << f4 << std::endl;
        fout << "M13->f5: " << f5 << std::endl;
        fout << "M13->f6: " << f6 << std::endl;
        fout << "M13->f7: " << f7 << std::endl;
        fout << "M13->f8: " << f8 << std::endl;
        fout << "M13->f9: " << f9 << std::endl;
    }

    ~M13(){
        if(f2 != nullptr)
            delete f2;
    }

    M13(){
       f2 = nullptr;
    }

private:
    alignas(8) float f1;
    alignas(8) M14* f2;
    alignas(8) int32_t f3;
    alignas(8) string f4;
    alignas(8) string f5;
    alignas(8) string f6;
    alignas(8) bool f7;
    alignas(8) int64_t f8;
    alignas(8) int32_t f9;
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
    
        inline void print_message(std::ofstream &fout){
            fout << "M16->f1: " << f1 << std::endl;
        }
    
        ~M16(){
        }
    
        M16(){
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

    inline M16* mutable_f2(){
        f2 = new M16();
        return f2;
    }
    inline M16*& get_f2(){
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

    inline void set_f5(uint32_t val){
        f5 = val;
    }
    inline uint32_t& get_f5(){
        return f5;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M15->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M15->f3: " << f3 << std::endl;
        fout << "M15->f4: " << f4 << std::endl;
        fout << "M15->f5: " << f5 << std::endl;
    }

    ~M15(){
        if(f2 != nullptr)
            delete f2;
    }

    M15(){
       f2 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) M16* f2;
    alignas(8) int32_t f3;
    alignas(8) int32_t f4;
    alignas(8) uint32_t f5;
};


class alignas(8) M17 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 96,
        E1_CONST_2 = 12,
        E1_CONST_3 = 46,
        E1_CONST_4 = 85,
        E1_CONST_5 = 4662,
    };
    
    class alignas(8) M18 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 99,
            E1_CONST_2 = 37,
            E1_CONST_3 = 72,
            E1_CONST_4 = 10,
            E1_CONST_5 = 76,
        };
        
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
    
        inline void set_f5(E1 val){
            f5 = val;
        }
        inline E1& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M18->f1: " << f1 << std::endl;
            fout << "M18->f2: " << f2 << std::endl;
            fout << "M18->f3: " << f3 << std::endl;
            fout << "M18->f4: " << f4 << std::endl;
            fout << "M18->f5: " << f5 << std::endl;
        }
    
        ~M18(){
        }
    
        M18(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) int32_t f2;
        alignas(8) int32_t f3;
        alignas(8) int32_t f4;
        alignas(8) E1 f5;
    };


    inline void set_f1(uint64_t val){
        f1 = val;
    }
    inline uint64_t& get_f1(){
        return f1;
    }

    inline void set_f2(float val){
        f2 = val;
    }
    inline float& get_f2(){
        return f2;
    }

    inline void set_f3(E1 val){
        f3 = val;
    }
    inline E1& get_f3(){
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

    inline void set_f6(bool val){
        f6 = val;
    }
    inline bool& get_f6(){
        return f6;
    }

    inline void set_f7(string val){
        f7 = val;
    }
    inline string& get_f7(){
        return f7;
    }

    inline M18* mutable_f8(){
        f8 = new M18();
        return f8;
    }
    inline M18*& get_f8(){
        return f8;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M17->f1: " << f1 << std::endl;
        fout << "M17->f2: " << f2 << std::endl;
        fout << "M17->f3: " << f3 << std::endl;
        for(auto &f4_val : f4){
            fout << "M17->f4: " << f4_val << std::endl;
        }
        fout << "M17->f5: " << f5 << std::endl;
        fout << "M17->f6: " << f6 << std::endl;
        fout << "M17->f7: " << f7 << std::endl;
        if(f8 != nullptr)
            f8->print_message(fout);
    }

    ~M17(){
        if(f8 != nullptr)
            delete f8;
    }

    M17(){
       f8 = nullptr;
    }

private:
    alignas(8) uint64_t f1;
    alignas(8) float f2;
    alignas(8) E1 f3;
    alignas(8) std::vector<string> f4;
    alignas(8) string f5;
    alignas(8) bool f6;
    alignas(8) string f7;
    alignas(8) M18* f8;
};


class alignas(8) M19 : public M_base
{
public:
    class alignas(8) M20 : public M_base
    {
    public:
        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M20->f1: " << f1 << std::endl;
        }
    
        ~M20(){
        }
    
        M20(){
        }
    
    private:
        alignas(8) string f1;
    };


    class alignas(8) M21 : public M_base
    {
    public:
        class alignas(8) M22 : public M_base
        {
        public:
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
        
            inline void set_f5(uint32_t val){
                f5 = val;
            }
            inline uint32_t& get_f5(){
                return f5;
            }
        
            inline void set_f6(bool val){
                f6 = val;
            }
            inline bool& get_f6(){
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
                fout << "M22->f1: " << f1 << std::endl;
                fout << "M22->f2: " << f2 << std::endl;
                fout << "M22->f3: " << f3 << std::endl;
                fout << "M22->f4: " << f4 << std::endl;
                fout << "M22->f5: " << f5 << std::endl;
                fout << "M22->f6: " << f6 << std::endl;
                fout << "M22->f7: " << f7 << std::endl;
                fout << "M22->f8: " << f8 << std::endl;
            }
        
            ~M22(){
            }
        
            M22(){
            }
        
        private:
            alignas(8) string f1;
            alignas(8) int32_t f2;
            alignas(8) int64_t f3;
            alignas(8) int32_t f4;
            alignas(8) uint32_t f5;
            alignas(8) bool f6;
            alignas(8) string f7;
            alignas(8) int64_t f8;
        };


        inline M22* mutable_f1(){
            f1 = new M22();
            return f1;
        }
        inline M22*& get_f1(){
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
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M21->f2: " << f2 << std::endl;
            fout << "M21->f3: " << f3 << std::endl;
        }
    
        ~M21(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M21(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M22* f1;
        alignas(8) int64_t f2;
        alignas(8) string f3;
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

    inline void set_f5(int32_t val){
        f5 = val;
    }
    inline int32_t& get_f5(){
        return f5;
    }

    inline M20* mutable_f6(){
        f6 = new M20();
        return f6;
    }
    inline M20*& get_f6(){
        return f6;
    }

    inline void set_f7(int32_t val){
        f7 = val;
    }
    inline int32_t& get_f7(){
        return f7;
    }

    inline void set_f8(uint64_t val){
        f8 = val;
    }
    inline uint64_t& get_f8(){
        return f8;
    }

    inline void set_f9(int64_t val){
        f9 = val;
    }
    inline int64_t& get_f9(){
        return f9;
    }

    inline M21* mutable_f10(){
        f10 = new M21();
        return f10;
    }
    inline M21*& get_f10(){
        return f10;
    }

    inline void set_f11(float val){
        f11 = val;
    }
    inline float& get_f11(){
        return f11;
    }

    inline void set_f12(float val){
        f12 = val;
    }
    inline float& get_f12(){
        return f12;
    }

    inline void set_f13(string val){
        f13 = val;
    }
    inline string& get_f13(){
        return f13;
    }

    inline void set_f14(int32_t val){
        f14 = val;
    }
    inline int32_t& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M19->f1: " << f1 << std::endl;
        fout << "M19->f2: " << f2 << std::endl;
        fout << "M19->f3: " << f3 << std::endl;
        fout << "M19->f4: " << f4 << std::endl;
        fout << "M19->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        fout << "M19->f7: " << f7 << std::endl;
        fout << "M19->f8: " << f8 << std::endl;
        fout << "M19->f9: " << f9 << std::endl;
        if(f10 != nullptr)
            f10->print_message(fout);
        fout << "M19->f11: " << f11 << std::endl;
        fout << "M19->f12: " << f12 << std::endl;
        fout << "M19->f13: " << f13 << std::endl;
        fout << "M19->f14: " << f14 << std::endl;
    }

    ~M19(){
        if(f6 != nullptr)
            delete f6;
        if(f10 != nullptr)
            delete f10;
    }

    M19(){
       f6 = nullptr;
       f10 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) bool f2;
    alignas(8) string f3;
    alignas(8) bool f4;
    alignas(8) int32_t f5;
    alignas(8) M20* f6;
    alignas(8) int32_t f7;
    alignas(8) uint64_t f8;
    alignas(8) int64_t f9;
    alignas(8) M21* f10;
    alignas(8) float f11;
    alignas(8) float f12;
    alignas(8) string f13;
    alignas(8) int32_t f14;
};


class alignas(8) M23 : public M_base
{
public:
    class alignas(8) M24 : public M_base
    {
    public:
        inline void set_f1(float val){
            f1 = val;
        }
        inline float& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint64_t val){
            f2 = val;
        }
        inline uint64_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(uint64_t val){
            f3 = val;
        }
        inline uint64_t& get_f3(){
            return f3;
        }
    
        inline void set_f4(int32_t val){
            f4 = val;
        }
        inline int32_t& get_f4(){
            return f4;
        }
    
        inline void set_f5(float val){
            f5 = val;
        }
        inline float& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M24->f1: " << f1 << std::endl;
            fout << "M24->f2: " << f2 << std::endl;
            fout << "M24->f3: " << f3 << std::endl;
            fout << "M24->f4: " << f4 << std::endl;
            fout << "M24->f5: " << f5 << std::endl;
        }
    
        ~M24(){
        }
    
        M24(){
        }
    
    private:
        alignas(8) float f1;
        alignas(8) uint64_t f2;
        alignas(8) uint64_t f3;
        alignas(8) int32_t f4;
        alignas(8) float f5;
    };


    inline M24* mutable_f1(){
        f1 = new M24();
        return f1;
    }
    inline M24*& get_f1(){
        return f1;
    }

    inline void set_f2(double val){
        f2 = val;
    }
    inline double& get_f2(){
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

    inline void set_f7(int32_t val){
        f7 = val;
    }
    inline int32_t& get_f7(){
        return f7;
    }

    inline void set_f8(int32_t val){
        f8 = val;
    }
    inline int32_t& get_f8(){
        return f8;
    }

    inline void set_f9(float val){
        f9 = val;
    }
    inline float& get_f9(){
        return f9;
    }

    inline void set_f10(int32_t val){
        f10 = val;
    }
    inline int32_t& get_f10(){
        return f10;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        fout << "M23->f2: " << f2 << std::endl;
        fout << "M23->f3: " << f3 << std::endl;
        fout << "M23->f4: " << f4 << std::endl;
        fout << "M23->f5: " << f5 << std::endl;
        fout << "M23->f6: " << f6 << std::endl;
        fout << "M23->f7: " << f7 << std::endl;
        fout << "M23->f8: " << f8 << std::endl;
        fout << "M23->f9: " << f9 << std::endl;
        fout << "M23->f10: " << f10 << std::endl;
    }

    ~M23(){
        if(f1 != nullptr)
            delete f1;
    }

    M23(){
       f1 = nullptr;
    }

private:
    alignas(8) M24* f1;
    alignas(8) double f2;
    alignas(8) string f3;
    alignas(8) bool f4;
    alignas(8) int64_t f5;
    alignas(8) string f6;
    alignas(8) int32_t f7;
    alignas(8) int32_t f8;
    alignas(8) float f9;
    alignas(8) int32_t f10;
};


class alignas(8) M25 : public M_base
{
public:
    class alignas(8) M26 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(float val){
            f2 = val;
        }
        inline float& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M26->f1: " << f1 << std::endl;
            fout << "M26->f2: " << f2 << std::endl;
        }
    
        ~M26(){
        }
    
        M26(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) float f2;
    };


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

    inline void set_f5(int32_t val){
        f5 = val;
    }
    inline int32_t& get_f5(){
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

    inline void set_f10(double val){
        f10 = val;
    }
    inline double& get_f10(){
        return f10;
    }

    inline void set_f11(bool val){
        f11 = val;
    }
    inline bool& get_f11(){
        return f11;
    }

    inline M26* mutable_f12(){
        f12 = new M26();
        return f12;
    }
    inline M26*& get_f12(){
        return f12;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M25->f1: " << f1 << std::endl;
        fout << "M25->f2: " << f2 << std::endl;
        fout << "M25->f3: " << f3 << std::endl;
        fout << "M25->f4: " << f4 << std::endl;
        fout << "M25->f5: " << f5 << std::endl;
        fout << "M25->f6: " << f6 << std::endl;
        fout << "M25->f7: " << f7 << std::endl;
        fout << "M25->f8: " << f8 << std::endl;
        fout << "M25->f9: " << f9 << std::endl;
        fout << "M25->f10: " << f10 << std::endl;
        fout << "M25->f11: " << f11 << std::endl;
        if(f12 != nullptr)
            f12->print_message(fout);
    }

    ~M25(){
        if(f12 != nullptr)
            delete f12;
    }

    M25(){
       f12 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) int32_t f2;
    alignas(8) string f3;
    alignas(8) int32_t f4;
    alignas(8) int32_t f5;
    alignas(8) int32_t f6;
    alignas(8) string f7;
    alignas(8) int32_t f8;
    alignas(8) int32_t f9;
    alignas(8) double f10;
    alignas(8) bool f11;
    alignas(8) M26* f12;
};

M_base* createMessage(int temp_class_id) {
    switch (temp_class_id) {
        case 13:
            return new M13();
        case 14:
            return new M13::M14();
        case 15:
            return new M15();
        case 16:
            return new M15::M16();
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
        case 22:
            return new M19::M21::M22();
        case 1:
            return new M1();
        case 2:
            return new M1::M2();
        case 23:
            return new M23();
        case 24:
            return new M23::M24();
        case 25:
            return new M25();
        case 26:
            return new M25::M26();
        case 3:
            return new M3();
        case 4:
            return new M3::M4();
        case 5:
            return new M5();
        case 7:
            return new M5::M7();
        case 8:
            return new M5::M7::M8();
        case 6:
            return new M5::M6();
        case 9:
            return new M9();
        case 12:
            return new M9::M12();
        case 10:
            return new M9::M10();
        case 11:
            return new M9::M10::M11();
        default:
            throw std::invalid_argument("Invalid class id");
    }
}

size_t getMessageSize(int temp_class_id) {
    switch (temp_class_id) {
        case 13:
            return sizeof(M13);
        case 14:
            return sizeof(M13::M14);
        case 15:
            return sizeof(M15);
        case 16:
            return sizeof(M15::M16);
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
        case 22:
            return sizeof(M19::M21::M22);
        case 1:
            return sizeof(M1);
        case 2:
            return sizeof(M1::M2);
        case 23:
            return sizeof(M23);
        case 24:
            return sizeof(M23::M24);
        case 25:
            return sizeof(M25);
        case 26:
            return sizeof(M25::M26);
        case 3:
            return sizeof(M3);
        case 4:
            return sizeof(M3::M4);
        case 5:
            return sizeof(M5);
        case 7:
            return sizeof(M5::M7);
        case 8:
            return sizeof(M5::M7::M8);
        case 6:
            return sizeof(M5::M6);
        case 9:
            return sizeof(M9);
        case 12:
            return sizeof(M9::M12);
        case 10:
            return sizeof(M9::M10);
        case 11:
            return sizeof(M9::M10::M11);
        default:
            return 0;
    }
}
