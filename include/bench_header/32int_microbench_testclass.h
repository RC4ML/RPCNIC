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

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
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

    inline void set_f14(int64_t val){
        f14 = val;
    }
    inline int64_t& get_f14(){
        return f14;
    }

    inline void set_f15(int64_t val){
        f15 = val;
    }
    inline int64_t& get_f15(){
        return f15;
    }

    inline void set_f16(int64_t val){
        f16 = val;
    }
    inline int64_t& get_f16(){
        return f16;
    }

    inline void set_f17(int64_t val){
        f17 = val;
    }
    inline int64_t& get_f17(){
        return f17;
    }

    inline void set_f18(int64_t val){
        f18 = val;
    }
    inline int64_t& get_f18(){
        return f18;
    }

    inline void set_f19(int64_t val){
        f19 = val;
    }
    inline int64_t& get_f19(){
        return f19;
    }

    inline void set_f20(int64_t val){
        f20 = val;
    }
    inline int64_t& get_f20(){
        return f20;
    }

    inline void set_f21(int64_t val){
        f21 = val;
    }
    inline int64_t& get_f21(){
        return f21;
    }

    inline void set_f22(int64_t val){
        f22 = val;
    }
    inline int64_t& get_f22(){
        return f22;
    }

    inline void set_f23(int64_t val){
        f23 = val;
    }
    inline int64_t& get_f23(){
        return f23;
    }

    inline void set_f24(int64_t val){
        f24 = val;
    }
    inline int64_t& get_f24(){
        return f24;
    }

    inline void set_f25(int64_t val){
        f25 = val;
    }
    inline int64_t& get_f25(){
        return f25;
    }

    inline void set_f26(int64_t val){
        f26 = val;
    }
    inline int64_t& get_f26(){
        return f26;
    }

    inline void set_f27(int64_t val){
        f27 = val;
    }
    inline int64_t& get_f27(){
        return f27;
    }

    inline void set_f28(int64_t val){
        f28 = val;
    }
    inline int64_t& get_f28(){
        return f28;
    }

    inline void set_f29(int64_t val){
        f29 = val;
    }
    inline int64_t& get_f29(){
        return f29;
    }

    inline void set_f30(int64_t val){
        f30 = val;
    }
    inline int64_t& get_f30(){
        return f30;
    }

    inline void set_f31(int64_t val){
        f31 = val;
    }
    inline int64_t& get_f31(){
        return f31;
    }

    inline void set_f32(int64_t val){
        f32 = val;
    }
    inline int64_t& get_f32(){
        return f32;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M1->f1: " << f1 << std::endl;
        fout << "M1->f2: " << f2 << std::endl;
        fout << "M1->f3: " << f3 << std::endl;
        fout << "M1->f4: " << f4 << std::endl;
        fout << "M1->f5: " << f5 << std::endl;
        fout << "M1->f6: " << f6 << std::endl;
        fout << "M1->f7: " << f7 << std::endl;
        fout << "M1->f8: " << f8 << std::endl;
        fout << "M1->f9: " << f9 << std::endl;
        fout << "M1->f10: " << f10 << std::endl;
        fout << "M1->f11: " << f11 << std::endl;
        fout << "M1->f12: " << f12 << std::endl;
        fout << "M1->f13: " << f13 << std::endl;
        fout << "M1->f14: " << f14 << std::endl;
        fout << "M1->f15: " << f15 << std::endl;
        fout << "M1->f16: " << f16 << std::endl;
        fout << "M1->f17: " << f17 << std::endl;
        fout << "M1->f18: " << f18 << std::endl;
        fout << "M1->f19: " << f19 << std::endl;
        fout << "M1->f20: " << f20 << std::endl;
        fout << "M1->f21: " << f21 << std::endl;
        fout << "M1->f22: " << f22 << std::endl;
        fout << "M1->f23: " << f23 << std::endl;
        fout << "M1->f24: " << f24 << std::endl;
        fout << "M1->f25: " << f25 << std::endl;
        fout << "M1->f26: " << f26 << std::endl;
        fout << "M1->f27: " << f27 << std::endl;
        fout << "M1->f28: " << f28 << std::endl;
        fout << "M1->f29: " << f29 << std::endl;
        fout << "M1->f30: " << f30 << std::endl;
        fout << "M1->f31: " << f31 << std::endl;
        fout << "M1->f32: " << f32 << std::endl;
    }

    ~M1(){
    }

    M1(){
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) int64_t f3;
    alignas(8) int64_t f4;
    alignas(8) int64_t f5;
    alignas(8) int64_t f6;
    alignas(8) int64_t f7;
    alignas(8) int64_t f8;
    alignas(8) int64_t f9;
    alignas(8) int64_t f10;
    alignas(8) int64_t f11;
    alignas(8) int64_t f12;
    alignas(8) int64_t f13;
    alignas(8) int64_t f14;
    alignas(8) int64_t f15;
    alignas(8) int64_t f16;
    alignas(8) int64_t f17;
    alignas(8) int64_t f18;
    alignas(8) int64_t f19;
    alignas(8) int64_t f20;
    alignas(8) int64_t f21;
    alignas(8) int64_t f22;
    alignas(8) int64_t f23;
    alignas(8) int64_t f24;
    alignas(8) int64_t f25;
    alignas(8) int64_t f26;
    alignas(8) int64_t f27;
    alignas(8) int64_t f28;
    alignas(8) int64_t f29;
    alignas(8) int64_t f30;
    alignas(8) int64_t f31;
    alignas(8) int64_t f32;
};


class alignas(8) M2 : public M_base
{
public:
    class alignas(8) M3 : public M_base
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
    
        inline void set_f11(int64_t val){
            f11 = val;
        }
        inline int64_t& get_f11(){
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
    
        inline void set_f14(int64_t val){
            f14 = val;
        }
        inline int64_t& get_f14(){
            return f14;
        }
    
        inline void set_f15(int64_t val){
            f15 = val;
        }
        inline int64_t& get_f15(){
            return f15;
        }
    
        inline void set_f16(int64_t val){
            f16 = val;
        }
        inline int64_t& get_f16(){
            return f16;
        }
    
        inline void set_f17(int64_t val){
            f17 = val;
        }
        inline int64_t& get_f17(){
            return f17;
        }
    
        inline void set_f18(int64_t val){
            f18 = val;
        }
        inline int64_t& get_f18(){
            return f18;
        }
    
        inline void set_f19(int64_t val){
            f19 = val;
        }
        inline int64_t& get_f19(){
            return f19;
        }
    
        inline void set_f20(int64_t val){
            f20 = val;
        }
        inline int64_t& get_f20(){
            return f20;
        }
    
        inline void set_f21(int64_t val){
            f21 = val;
        }
        inline int64_t& get_f21(){
            return f21;
        }
    
        inline void set_f22(int64_t val){
            f22 = val;
        }
        inline int64_t& get_f22(){
            return f22;
        }
    
        inline void set_f23(int64_t val){
            f23 = val;
        }
        inline int64_t& get_f23(){
            return f23;
        }
    
        inline void set_f24(int64_t val){
            f24 = val;
        }
        inline int64_t& get_f24(){
            return f24;
        }
    
        inline void set_f25(int64_t val){
            f25 = val;
        }
        inline int64_t& get_f25(){
            return f25;
        }
    
        inline void set_f26(int64_t val){
            f26 = val;
        }
        inline int64_t& get_f26(){
            return f26;
        }
    
        inline void set_f27(int64_t val){
            f27 = val;
        }
        inline int64_t& get_f27(){
            return f27;
        }
    
        inline void set_f28(int64_t val){
            f28 = val;
        }
        inline int64_t& get_f28(){
            return f28;
        }
    
        inline void set_f29(int64_t val){
            f29 = val;
        }
        inline int64_t& get_f29(){
            return f29;
        }
    
        inline void set_f30(int64_t val){
            f30 = val;
        }
        inline int64_t& get_f30(){
            return f30;
        }
    
        inline void set_f31(int64_t val){
            f31 = val;
        }
        inline int64_t& get_f31(){
            return f31;
        }
    
        inline void set_f32(int64_t val){
            f32 = val;
        }
        inline int64_t& get_f32(){
            return f32;
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
            fout << "M3->f9: " << f9 << std::endl;
            fout << "M3->f10: " << f10 << std::endl;
            fout << "M3->f11: " << f11 << std::endl;
            fout << "M3->f12: " << f12 << std::endl;
            fout << "M3->f13: " << f13 << std::endl;
            fout << "M3->f14: " << f14 << std::endl;
            fout << "M3->f15: " << f15 << std::endl;
            fout << "M3->f16: " << f16 << std::endl;
            fout << "M3->f17: " << f17 << std::endl;
            fout << "M3->f18: " << f18 << std::endl;
            fout << "M3->f19: " << f19 << std::endl;
            fout << "M3->f20: " << f20 << std::endl;
            fout << "M3->f21: " << f21 << std::endl;
            fout << "M3->f22: " << f22 << std::endl;
            fout << "M3->f23: " << f23 << std::endl;
            fout << "M3->f24: " << f24 << std::endl;
            fout << "M3->f25: " << f25 << std::endl;
            fout << "M3->f26: " << f26 << std::endl;
            fout << "M3->f27: " << f27 << std::endl;
            fout << "M3->f28: " << f28 << std::endl;
            fout << "M3->f29: " << f29 << std::endl;
            fout << "M3->f30: " << f30 << std::endl;
            fout << "M3->f31: " << f31 << std::endl;
            fout << "M3->f32: " << f32 << std::endl;
        }
    
        ~M3(){
        }
    
        M3(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
        alignas(8) int64_t f3;
        alignas(8) int64_t f4;
        alignas(8) int64_t f5;
        alignas(8) int64_t f6;
        alignas(8) int64_t f7;
        alignas(8) int64_t f8;
        alignas(8) int64_t f9;
        alignas(8) int64_t f10;
        alignas(8) int64_t f11;
        alignas(8) int64_t f12;
        alignas(8) int64_t f13;
        alignas(8) int64_t f14;
        alignas(8) int64_t f15;
        alignas(8) int64_t f16;
        alignas(8) int64_t f17;
        alignas(8) int64_t f18;
        alignas(8) int64_t f19;
        alignas(8) int64_t f20;
        alignas(8) int64_t f21;
        alignas(8) int64_t f22;
        alignas(8) int64_t f23;
        alignas(8) int64_t f24;
        alignas(8) int64_t f25;
        alignas(8) int64_t f26;
        alignas(8) int64_t f27;
        alignas(8) int64_t f28;
        alignas(8) int64_t f29;
        alignas(8) int64_t f30;
        alignas(8) int64_t f31;
        alignas(8) int64_t f32;
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

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
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

    inline void set_f14(int64_t val){
        f14 = val;
    }
    inline int64_t& get_f14(){
        return f14;
    }

    inline void set_f15(int64_t val){
        f15 = val;
    }
    inline int64_t& get_f15(){
        return f15;
    }

    inline void set_f16(int64_t val){
        f16 = val;
    }
    inline int64_t& get_f16(){
        return f16;
    }

    inline void set_f17(int64_t val){
        f17 = val;
    }
    inline int64_t& get_f17(){
        return f17;
    }

    inline void set_f18(int64_t val){
        f18 = val;
    }
    inline int64_t& get_f18(){
        return f18;
    }

    inline void set_f19(int64_t val){
        f19 = val;
    }
    inline int64_t& get_f19(){
        return f19;
    }

    inline void set_f20(int64_t val){
        f20 = val;
    }
    inline int64_t& get_f20(){
        return f20;
    }

    inline void set_f21(int64_t val){
        f21 = val;
    }
    inline int64_t& get_f21(){
        return f21;
    }

    inline void set_f22(int64_t val){
        f22 = val;
    }
    inline int64_t& get_f22(){
        return f22;
    }

    inline void set_f23(int64_t val){
        f23 = val;
    }
    inline int64_t& get_f23(){
        return f23;
    }

    inline void set_f24(int64_t val){
        f24 = val;
    }
    inline int64_t& get_f24(){
        return f24;
    }

    inline void set_f25(int64_t val){
        f25 = val;
    }
    inline int64_t& get_f25(){
        return f25;
    }

    inline void set_f26(int64_t val){
        f26 = val;
    }
    inline int64_t& get_f26(){
        return f26;
    }

    inline void set_f27(int64_t val){
        f27 = val;
    }
    inline int64_t& get_f27(){
        return f27;
    }

    inline void set_f28(int64_t val){
        f28 = val;
    }
    inline int64_t& get_f28(){
        return f28;
    }

    inline void set_f29(int64_t val){
        f29 = val;
    }
    inline int64_t& get_f29(){
        return f29;
    }

    inline void set_f30(int64_t val){
        f30 = val;
    }
    inline int64_t& get_f30(){
        return f30;
    }

    inline void set_f31(int64_t val){
        f31 = val;
    }
    inline int64_t& get_f31(){
        return f31;
    }

    inline void set_f32(int64_t val){
        f32 = val;
    }
    inline int64_t& get_f32(){
        return f32;
    }

    inline M3* mutable_f33(){
        f33 = new M3();
        return f33;
    }
    inline M3*& get_f33(){
        return f33;
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
        fout << "M2->f11: " << f11 << std::endl;
        fout << "M2->f12: " << f12 << std::endl;
        fout << "M2->f13: " << f13 << std::endl;
        fout << "M2->f14: " << f14 << std::endl;
        fout << "M2->f15: " << f15 << std::endl;
        fout << "M2->f16: " << f16 << std::endl;
        fout << "M2->f17: " << f17 << std::endl;
        fout << "M2->f18: " << f18 << std::endl;
        fout << "M2->f19: " << f19 << std::endl;
        fout << "M2->f20: " << f20 << std::endl;
        fout << "M2->f21: " << f21 << std::endl;
        fout << "M2->f22: " << f22 << std::endl;
        fout << "M2->f23: " << f23 << std::endl;
        fout << "M2->f24: " << f24 << std::endl;
        fout << "M2->f25: " << f25 << std::endl;
        fout << "M2->f26: " << f26 << std::endl;
        fout << "M2->f27: " << f27 << std::endl;
        fout << "M2->f28: " << f28 << std::endl;
        fout << "M2->f29: " << f29 << std::endl;
        fout << "M2->f30: " << f30 << std::endl;
        fout << "M2->f31: " << f31 << std::endl;
        fout << "M2->f32: " << f32 << std::endl;
        if(f33 != nullptr)
            f33->print_message(fout);
    }

    ~M2(){
        if(f33 != nullptr)
            delete f33;
    }

    M2(){
       f33 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) int64_t f3;
    alignas(8) int64_t f4;
    alignas(8) int64_t f5;
    alignas(8) int64_t f6;
    alignas(8) int64_t f7;
    alignas(8) int64_t f8;
    alignas(8) int64_t f9;
    alignas(8) int64_t f10;
    alignas(8) int64_t f11;
    alignas(8) int64_t f12;
    alignas(8) int64_t f13;
    alignas(8) int64_t f14;
    alignas(8) int64_t f15;
    alignas(8) int64_t f16;
    alignas(8) int64_t f17;
    alignas(8) int64_t f18;
    alignas(8) int64_t f19;
    alignas(8) int64_t f20;
    alignas(8) int64_t f21;
    alignas(8) int64_t f22;
    alignas(8) int64_t f23;
    alignas(8) int64_t f24;
    alignas(8) int64_t f25;
    alignas(8) int64_t f26;
    alignas(8) int64_t f27;
    alignas(8) int64_t f28;
    alignas(8) int64_t f29;
    alignas(8) int64_t f30;
    alignas(8) int64_t f31;
    alignas(8) int64_t f32;
    alignas(8) M3* f33;
};


class alignas(8) M4 : public M_base
{
public:
    class alignas(8) M5 : public M_base
    {
    public:
        class alignas(8) M6 : public M_base
        {
        public:
            class alignas(8) M7 : public M_base
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
            
                inline void set_f11(int64_t val){
                    f11 = val;
                }
                inline int64_t& get_f11(){
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
            
                inline void set_f14(int64_t val){
                    f14 = val;
                }
                inline int64_t& get_f14(){
                    return f14;
                }
            
                inline void set_f15(int64_t val){
                    f15 = val;
                }
                inline int64_t& get_f15(){
                    return f15;
                }
            
                inline void set_f16(int64_t val){
                    f16 = val;
                }
                inline int64_t& get_f16(){
                    return f16;
                }
            
                inline void set_f17(int64_t val){
                    f17 = val;
                }
                inline int64_t& get_f17(){
                    return f17;
                }
            
                inline void set_f18(int64_t val){
                    f18 = val;
                }
                inline int64_t& get_f18(){
                    return f18;
                }
            
                inline void set_f19(int64_t val){
                    f19 = val;
                }
                inline int64_t& get_f19(){
                    return f19;
                }
            
                inline void set_f20(int64_t val){
                    f20 = val;
                }
                inline int64_t& get_f20(){
                    return f20;
                }
            
                inline void set_f21(int64_t val){
                    f21 = val;
                }
                inline int64_t& get_f21(){
                    return f21;
                }
            
                inline void set_f22(int64_t val){
                    f22 = val;
                }
                inline int64_t& get_f22(){
                    return f22;
                }
            
                inline void set_f23(int64_t val){
                    f23 = val;
                }
                inline int64_t& get_f23(){
                    return f23;
                }
            
                inline void set_f24(int64_t val){
                    f24 = val;
                }
                inline int64_t& get_f24(){
                    return f24;
                }
            
                inline void set_f25(int64_t val){
                    f25 = val;
                }
                inline int64_t& get_f25(){
                    return f25;
                }
            
                inline void set_f26(int64_t val){
                    f26 = val;
                }
                inline int64_t& get_f26(){
                    return f26;
                }
            
                inline void set_f27(int64_t val){
                    f27 = val;
                }
                inline int64_t& get_f27(){
                    return f27;
                }
            
                inline void set_f28(int64_t val){
                    f28 = val;
                }
                inline int64_t& get_f28(){
                    return f28;
                }
            
                inline void set_f29(int64_t val){
                    f29 = val;
                }
                inline int64_t& get_f29(){
                    return f29;
                }
            
                inline void set_f30(int64_t val){
                    f30 = val;
                }
                inline int64_t& get_f30(){
                    return f30;
                }
            
                inline void set_f31(int64_t val){
                    f31 = val;
                }
                inline int64_t& get_f31(){
                    return f31;
                }
            
                inline void set_f32(int64_t val){
                    f32 = val;
                }
                inline int64_t& get_f32(){
                    return f32;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M7->f1: " << f1 << std::endl;
                    fout << "M7->f2: " << f2 << std::endl;
                    fout << "M7->f3: " << f3 << std::endl;
                    fout << "M7->f4: " << f4 << std::endl;
                    fout << "M7->f5: " << f5 << std::endl;
                    fout << "M7->f6: " << f6 << std::endl;
                    fout << "M7->f7: " << f7 << std::endl;
                    fout << "M7->f8: " << f8 << std::endl;
                    fout << "M7->f9: " << f9 << std::endl;
                    fout << "M7->f10: " << f10 << std::endl;
                    fout << "M7->f11: " << f11 << std::endl;
                    fout << "M7->f12: " << f12 << std::endl;
                    fout << "M7->f13: " << f13 << std::endl;
                    fout << "M7->f14: " << f14 << std::endl;
                    fout << "M7->f15: " << f15 << std::endl;
                    fout << "M7->f16: " << f16 << std::endl;
                    fout << "M7->f17: " << f17 << std::endl;
                    fout << "M7->f18: " << f18 << std::endl;
                    fout << "M7->f19: " << f19 << std::endl;
                    fout << "M7->f20: " << f20 << std::endl;
                    fout << "M7->f21: " << f21 << std::endl;
                    fout << "M7->f22: " << f22 << std::endl;
                    fout << "M7->f23: " << f23 << std::endl;
                    fout << "M7->f24: " << f24 << std::endl;
                    fout << "M7->f25: " << f25 << std::endl;
                    fout << "M7->f26: " << f26 << std::endl;
                    fout << "M7->f27: " << f27 << std::endl;
                    fout << "M7->f28: " << f28 << std::endl;
                    fout << "M7->f29: " << f29 << std::endl;
                    fout << "M7->f30: " << f30 << std::endl;
                    fout << "M7->f31: " << f31 << std::endl;
                    fout << "M7->f32: " << f32 << std::endl;
                }
            
                ~M7(){
                }
            
                M7(){
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) int64_t f2;
                alignas(8) int64_t f3;
                alignas(8) int64_t f4;
                alignas(8) int64_t f5;
                alignas(8) int64_t f6;
                alignas(8) int64_t f7;
                alignas(8) int64_t f8;
                alignas(8) int64_t f9;
                alignas(8) int64_t f10;
                alignas(8) int64_t f11;
                alignas(8) int64_t f12;
                alignas(8) int64_t f13;
                alignas(8) int64_t f14;
                alignas(8) int64_t f15;
                alignas(8) int64_t f16;
                alignas(8) int64_t f17;
                alignas(8) int64_t f18;
                alignas(8) int64_t f19;
                alignas(8) int64_t f20;
                alignas(8) int64_t f21;
                alignas(8) int64_t f22;
                alignas(8) int64_t f23;
                alignas(8) int64_t f24;
                alignas(8) int64_t f25;
                alignas(8) int64_t f26;
                alignas(8) int64_t f27;
                alignas(8) int64_t f28;
                alignas(8) int64_t f29;
                alignas(8) int64_t f30;
                alignas(8) int64_t f31;
                alignas(8) int64_t f32;
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
        
            inline void set_f11(int64_t val){
                f11 = val;
            }
            inline int64_t& get_f11(){
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
        
            inline void set_f14(int64_t val){
                f14 = val;
            }
            inline int64_t& get_f14(){
                return f14;
            }
        
            inline void set_f15(int64_t val){
                f15 = val;
            }
            inline int64_t& get_f15(){
                return f15;
            }
        
            inline void set_f16(int64_t val){
                f16 = val;
            }
            inline int64_t& get_f16(){
                return f16;
            }
        
            inline void set_f17(int64_t val){
                f17 = val;
            }
            inline int64_t& get_f17(){
                return f17;
            }
        
            inline void set_f18(int64_t val){
                f18 = val;
            }
            inline int64_t& get_f18(){
                return f18;
            }
        
            inline void set_f19(int64_t val){
                f19 = val;
            }
            inline int64_t& get_f19(){
                return f19;
            }
        
            inline void set_f20(int64_t val){
                f20 = val;
            }
            inline int64_t& get_f20(){
                return f20;
            }
        
            inline void set_f21(int64_t val){
                f21 = val;
            }
            inline int64_t& get_f21(){
                return f21;
            }
        
            inline void set_f22(int64_t val){
                f22 = val;
            }
            inline int64_t& get_f22(){
                return f22;
            }
        
            inline void set_f23(int64_t val){
                f23 = val;
            }
            inline int64_t& get_f23(){
                return f23;
            }
        
            inline void set_f24(int64_t val){
                f24 = val;
            }
            inline int64_t& get_f24(){
                return f24;
            }
        
            inline void set_f25(int64_t val){
                f25 = val;
            }
            inline int64_t& get_f25(){
                return f25;
            }
        
            inline void set_f26(int64_t val){
                f26 = val;
            }
            inline int64_t& get_f26(){
                return f26;
            }
        
            inline void set_f27(int64_t val){
                f27 = val;
            }
            inline int64_t& get_f27(){
                return f27;
            }
        
            inline void set_f28(int64_t val){
                f28 = val;
            }
            inline int64_t& get_f28(){
                return f28;
            }
        
            inline void set_f29(int64_t val){
                f29 = val;
            }
            inline int64_t& get_f29(){
                return f29;
            }
        
            inline void set_f30(int64_t val){
                f30 = val;
            }
            inline int64_t& get_f30(){
                return f30;
            }
        
            inline void set_f31(int64_t val){
                f31 = val;
            }
            inline int64_t& get_f31(){
                return f31;
            }
        
            inline void set_f32(int64_t val){
                f32 = val;
            }
            inline int64_t& get_f32(){
                return f32;
            }
        
            inline M7* mutable_f33(){
                f33 = new M7();
                return f33;
            }
            inline M7*& get_f33(){
                return f33;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M6->f1: " << f1 << std::endl;
                fout << "M6->f2: " << f2 << std::endl;
                fout << "M6->f3: " << f3 << std::endl;
                fout << "M6->f4: " << f4 << std::endl;
                fout << "M6->f5: " << f5 << std::endl;
                fout << "M6->f6: " << f6 << std::endl;
                fout << "M6->f7: " << f7 << std::endl;
                fout << "M6->f8: " << f8 << std::endl;
                fout << "M6->f9: " << f9 << std::endl;
                fout << "M6->f10: " << f10 << std::endl;
                fout << "M6->f11: " << f11 << std::endl;
                fout << "M6->f12: " << f12 << std::endl;
                fout << "M6->f13: " << f13 << std::endl;
                fout << "M6->f14: " << f14 << std::endl;
                fout << "M6->f15: " << f15 << std::endl;
                fout << "M6->f16: " << f16 << std::endl;
                fout << "M6->f17: " << f17 << std::endl;
                fout << "M6->f18: " << f18 << std::endl;
                fout << "M6->f19: " << f19 << std::endl;
                fout << "M6->f20: " << f20 << std::endl;
                fout << "M6->f21: " << f21 << std::endl;
                fout << "M6->f22: " << f22 << std::endl;
                fout << "M6->f23: " << f23 << std::endl;
                fout << "M6->f24: " << f24 << std::endl;
                fout << "M6->f25: " << f25 << std::endl;
                fout << "M6->f26: " << f26 << std::endl;
                fout << "M6->f27: " << f27 << std::endl;
                fout << "M6->f28: " << f28 << std::endl;
                fout << "M6->f29: " << f29 << std::endl;
                fout << "M6->f30: " << f30 << std::endl;
                fout << "M6->f31: " << f31 << std::endl;
                fout << "M6->f32: " << f32 << std::endl;
                if(f33 != nullptr)
                    f33->print_message(fout);
            }
        
            ~M6(){
                if(f33 != nullptr)
                    delete f33;
            }
        
            M6(){
               f33 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int64_t f2;
            alignas(8) int64_t f3;
            alignas(8) int64_t f4;
            alignas(8) int64_t f5;
            alignas(8) int64_t f6;
            alignas(8) int64_t f7;
            alignas(8) int64_t f8;
            alignas(8) int64_t f9;
            alignas(8) int64_t f10;
            alignas(8) int64_t f11;
            alignas(8) int64_t f12;
            alignas(8) int64_t f13;
            alignas(8) int64_t f14;
            alignas(8) int64_t f15;
            alignas(8) int64_t f16;
            alignas(8) int64_t f17;
            alignas(8) int64_t f18;
            alignas(8) int64_t f19;
            alignas(8) int64_t f20;
            alignas(8) int64_t f21;
            alignas(8) int64_t f22;
            alignas(8) int64_t f23;
            alignas(8) int64_t f24;
            alignas(8) int64_t f25;
            alignas(8) int64_t f26;
            alignas(8) int64_t f27;
            alignas(8) int64_t f28;
            alignas(8) int64_t f29;
            alignas(8) int64_t f30;
            alignas(8) int64_t f31;
            alignas(8) int64_t f32;
            alignas(8) M7* f33;
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
    
        inline void set_f11(int64_t val){
            f11 = val;
        }
        inline int64_t& get_f11(){
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
    
        inline void set_f14(int64_t val){
            f14 = val;
        }
        inline int64_t& get_f14(){
            return f14;
        }
    
        inline void set_f15(int64_t val){
            f15 = val;
        }
        inline int64_t& get_f15(){
            return f15;
        }
    
        inline void set_f16(int64_t val){
            f16 = val;
        }
        inline int64_t& get_f16(){
            return f16;
        }
    
        inline void set_f17(int64_t val){
            f17 = val;
        }
        inline int64_t& get_f17(){
            return f17;
        }
    
        inline void set_f18(int64_t val){
            f18 = val;
        }
        inline int64_t& get_f18(){
            return f18;
        }
    
        inline void set_f19(int64_t val){
            f19 = val;
        }
        inline int64_t& get_f19(){
            return f19;
        }
    
        inline void set_f20(int64_t val){
            f20 = val;
        }
        inline int64_t& get_f20(){
            return f20;
        }
    
        inline void set_f21(int64_t val){
            f21 = val;
        }
        inline int64_t& get_f21(){
            return f21;
        }
    
        inline void set_f22(int64_t val){
            f22 = val;
        }
        inline int64_t& get_f22(){
            return f22;
        }
    
        inline void set_f23(int64_t val){
            f23 = val;
        }
        inline int64_t& get_f23(){
            return f23;
        }
    
        inline void set_f24(int64_t val){
            f24 = val;
        }
        inline int64_t& get_f24(){
            return f24;
        }
    
        inline void set_f25(int64_t val){
            f25 = val;
        }
        inline int64_t& get_f25(){
            return f25;
        }
    
        inline void set_f26(int64_t val){
            f26 = val;
        }
        inline int64_t& get_f26(){
            return f26;
        }
    
        inline void set_f27(int64_t val){
            f27 = val;
        }
        inline int64_t& get_f27(){
            return f27;
        }
    
        inline void set_f28(int64_t val){
            f28 = val;
        }
        inline int64_t& get_f28(){
            return f28;
        }
    
        inline void set_f29(int64_t val){
            f29 = val;
        }
        inline int64_t& get_f29(){
            return f29;
        }
    
        inline void set_f30(int64_t val){
            f30 = val;
        }
        inline int64_t& get_f30(){
            return f30;
        }
    
        inline void set_f31(int64_t val){
            f31 = val;
        }
        inline int64_t& get_f31(){
            return f31;
        }
    
        inline void set_f32(int64_t val){
            f32 = val;
        }
        inline int64_t& get_f32(){
            return f32;
        }
    
        inline M6* mutable_f33(){
            f33 = new M6();
            return f33;
        }
        inline M6*& get_f33(){
            return f33;
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
            fout << "M5->f12: " << f12 << std::endl;
            fout << "M5->f13: " << f13 << std::endl;
            fout << "M5->f14: " << f14 << std::endl;
            fout << "M5->f15: " << f15 << std::endl;
            fout << "M5->f16: " << f16 << std::endl;
            fout << "M5->f17: " << f17 << std::endl;
            fout << "M5->f18: " << f18 << std::endl;
            fout << "M5->f19: " << f19 << std::endl;
            fout << "M5->f20: " << f20 << std::endl;
            fout << "M5->f21: " << f21 << std::endl;
            fout << "M5->f22: " << f22 << std::endl;
            fout << "M5->f23: " << f23 << std::endl;
            fout << "M5->f24: " << f24 << std::endl;
            fout << "M5->f25: " << f25 << std::endl;
            fout << "M5->f26: " << f26 << std::endl;
            fout << "M5->f27: " << f27 << std::endl;
            fout << "M5->f28: " << f28 << std::endl;
            fout << "M5->f29: " << f29 << std::endl;
            fout << "M5->f30: " << f30 << std::endl;
            fout << "M5->f31: " << f31 << std::endl;
            fout << "M5->f32: " << f32 << std::endl;
            if(f33 != nullptr)
                f33->print_message(fout);
        }
    
        ~M5(){
            if(f33 != nullptr)
                delete f33;
        }
    
        M5(){
           f33 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
        alignas(8) int64_t f3;
        alignas(8) int64_t f4;
        alignas(8) int64_t f5;
        alignas(8) int64_t f6;
        alignas(8) int64_t f7;
        alignas(8) int64_t f8;
        alignas(8) int64_t f9;
        alignas(8) int64_t f10;
        alignas(8) int64_t f11;
        alignas(8) int64_t f12;
        alignas(8) int64_t f13;
        alignas(8) int64_t f14;
        alignas(8) int64_t f15;
        alignas(8) int64_t f16;
        alignas(8) int64_t f17;
        alignas(8) int64_t f18;
        alignas(8) int64_t f19;
        alignas(8) int64_t f20;
        alignas(8) int64_t f21;
        alignas(8) int64_t f22;
        alignas(8) int64_t f23;
        alignas(8) int64_t f24;
        alignas(8) int64_t f25;
        alignas(8) int64_t f26;
        alignas(8) int64_t f27;
        alignas(8) int64_t f28;
        alignas(8) int64_t f29;
        alignas(8) int64_t f30;
        alignas(8) int64_t f31;
        alignas(8) int64_t f32;
        alignas(8) M6* f33;
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

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
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

    inline void set_f14(int64_t val){
        f14 = val;
    }
    inline int64_t& get_f14(){
        return f14;
    }

    inline void set_f15(int64_t val){
        f15 = val;
    }
    inline int64_t& get_f15(){
        return f15;
    }

    inline void set_f16(int64_t val){
        f16 = val;
    }
    inline int64_t& get_f16(){
        return f16;
    }

    inline void set_f17(int64_t val){
        f17 = val;
    }
    inline int64_t& get_f17(){
        return f17;
    }

    inline void set_f18(int64_t val){
        f18 = val;
    }
    inline int64_t& get_f18(){
        return f18;
    }

    inline void set_f19(int64_t val){
        f19 = val;
    }
    inline int64_t& get_f19(){
        return f19;
    }

    inline void set_f20(int64_t val){
        f20 = val;
    }
    inline int64_t& get_f20(){
        return f20;
    }

    inline void set_f21(int64_t val){
        f21 = val;
    }
    inline int64_t& get_f21(){
        return f21;
    }

    inline void set_f22(int64_t val){
        f22 = val;
    }
    inline int64_t& get_f22(){
        return f22;
    }

    inline void set_f23(int64_t val){
        f23 = val;
    }
    inline int64_t& get_f23(){
        return f23;
    }

    inline void set_f24(int64_t val){
        f24 = val;
    }
    inline int64_t& get_f24(){
        return f24;
    }

    inline void set_f25(int64_t val){
        f25 = val;
    }
    inline int64_t& get_f25(){
        return f25;
    }

    inline void set_f26(int64_t val){
        f26 = val;
    }
    inline int64_t& get_f26(){
        return f26;
    }

    inline void set_f27(int64_t val){
        f27 = val;
    }
    inline int64_t& get_f27(){
        return f27;
    }

    inline void set_f28(int64_t val){
        f28 = val;
    }
    inline int64_t& get_f28(){
        return f28;
    }

    inline void set_f29(int64_t val){
        f29 = val;
    }
    inline int64_t& get_f29(){
        return f29;
    }

    inline void set_f30(int64_t val){
        f30 = val;
    }
    inline int64_t& get_f30(){
        return f30;
    }

    inline void set_f31(int64_t val){
        f31 = val;
    }
    inline int64_t& get_f31(){
        return f31;
    }

    inline void set_f32(int64_t val){
        f32 = val;
    }
    inline int64_t& get_f32(){
        return f32;
    }

    inline M5* mutable_f33(){
        f33 = new M5();
        return f33;
    }
    inline M5*& get_f33(){
        return f33;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M4->f1: " << f1 << std::endl;
        fout << "M4->f2: " << f2 << std::endl;
        fout << "M4->f3: " << f3 << std::endl;
        fout << "M4->f4: " << f4 << std::endl;
        fout << "M4->f5: " << f5 << std::endl;
        fout << "M4->f6: " << f6 << std::endl;
        fout << "M4->f7: " << f7 << std::endl;
        fout << "M4->f8: " << f8 << std::endl;
        fout << "M4->f9: " << f9 << std::endl;
        fout << "M4->f10: " << f10 << std::endl;
        fout << "M4->f11: " << f11 << std::endl;
        fout << "M4->f12: " << f12 << std::endl;
        fout << "M4->f13: " << f13 << std::endl;
        fout << "M4->f14: " << f14 << std::endl;
        fout << "M4->f15: " << f15 << std::endl;
        fout << "M4->f16: " << f16 << std::endl;
        fout << "M4->f17: " << f17 << std::endl;
        fout << "M4->f18: " << f18 << std::endl;
        fout << "M4->f19: " << f19 << std::endl;
        fout << "M4->f20: " << f20 << std::endl;
        fout << "M4->f21: " << f21 << std::endl;
        fout << "M4->f22: " << f22 << std::endl;
        fout << "M4->f23: " << f23 << std::endl;
        fout << "M4->f24: " << f24 << std::endl;
        fout << "M4->f25: " << f25 << std::endl;
        fout << "M4->f26: " << f26 << std::endl;
        fout << "M4->f27: " << f27 << std::endl;
        fout << "M4->f28: " << f28 << std::endl;
        fout << "M4->f29: " << f29 << std::endl;
        fout << "M4->f30: " << f30 << std::endl;
        fout << "M4->f31: " << f31 << std::endl;
        fout << "M4->f32: " << f32 << std::endl;
        if(f33 != nullptr)
            f33->print_message(fout);
    }

    ~M4(){
        if(f33 != nullptr)
            delete f33;
    }

    M4(){
       f33 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) int64_t f3;
    alignas(8) int64_t f4;
    alignas(8) int64_t f5;
    alignas(8) int64_t f6;
    alignas(8) int64_t f7;
    alignas(8) int64_t f8;
    alignas(8) int64_t f9;
    alignas(8) int64_t f10;
    alignas(8) int64_t f11;
    alignas(8) int64_t f12;
    alignas(8) int64_t f13;
    alignas(8) int64_t f14;
    alignas(8) int64_t f15;
    alignas(8) int64_t f16;
    alignas(8) int64_t f17;
    alignas(8) int64_t f18;
    alignas(8) int64_t f19;
    alignas(8) int64_t f20;
    alignas(8) int64_t f21;
    alignas(8) int64_t f22;
    alignas(8) int64_t f23;
    alignas(8) int64_t f24;
    alignas(8) int64_t f25;
    alignas(8) int64_t f26;
    alignas(8) int64_t f27;
    alignas(8) int64_t f28;
    alignas(8) int64_t f29;
    alignas(8) int64_t f30;
    alignas(8) int64_t f31;
    alignas(8) int64_t f32;
    alignas(8) M5* f33;
};


class alignas(8) M8 : public M_base
{
public:
    class alignas(8) M9 : public M_base
    {
    public:
        class alignas(8) M10 : public M_base
        {
        public:
            class alignas(8) M11 : public M_base
            {
            public:
                class alignas(8) M12 : public M_base
                {
                public:
                    class alignas(8) M13 : public M_base
                    {
                    public:
                        class alignas(8) M14 : public M_base
                        {
                        public:
                            class alignas(8) M15 : public M_base
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
                            
                                inline void set_f11(int64_t val){
                                    f11 = val;
                                }
                                inline int64_t& get_f11(){
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
                            
                                inline void set_f14(int64_t val){
                                    f14 = val;
                                }
                                inline int64_t& get_f14(){
                                    return f14;
                                }
                            
                                inline void set_f15(int64_t val){
                                    f15 = val;
                                }
                                inline int64_t& get_f15(){
                                    return f15;
                                }
                            
                                inline void set_f16(int64_t val){
                                    f16 = val;
                                }
                                inline int64_t& get_f16(){
                                    return f16;
                                }
                            
                                inline void set_f17(int64_t val){
                                    f17 = val;
                                }
                                inline int64_t& get_f17(){
                                    return f17;
                                }
                            
                                inline void set_f18(int64_t val){
                                    f18 = val;
                                }
                                inline int64_t& get_f18(){
                                    return f18;
                                }
                            
                                inline void set_f19(int64_t val){
                                    f19 = val;
                                }
                                inline int64_t& get_f19(){
                                    return f19;
                                }
                            
                                inline void set_f20(int64_t val){
                                    f20 = val;
                                }
                                inline int64_t& get_f20(){
                                    return f20;
                                }
                            
                                inline void set_f21(int64_t val){
                                    f21 = val;
                                }
                                inline int64_t& get_f21(){
                                    return f21;
                                }
                            
                                inline void set_f22(int64_t val){
                                    f22 = val;
                                }
                                inline int64_t& get_f22(){
                                    return f22;
                                }
                            
                                inline void set_f23(int64_t val){
                                    f23 = val;
                                }
                                inline int64_t& get_f23(){
                                    return f23;
                                }
                            
                                inline void set_f24(int64_t val){
                                    f24 = val;
                                }
                                inline int64_t& get_f24(){
                                    return f24;
                                }
                            
                                inline void set_f25(int64_t val){
                                    f25 = val;
                                }
                                inline int64_t& get_f25(){
                                    return f25;
                                }
                            
                                inline void set_f26(int64_t val){
                                    f26 = val;
                                }
                                inline int64_t& get_f26(){
                                    return f26;
                                }
                            
                                inline void set_f27(int64_t val){
                                    f27 = val;
                                }
                                inline int64_t& get_f27(){
                                    return f27;
                                }
                            
                                inline void set_f28(int64_t val){
                                    f28 = val;
                                }
                                inline int64_t& get_f28(){
                                    return f28;
                                }
                            
                                inline void set_f29(int64_t val){
                                    f29 = val;
                                }
                                inline int64_t& get_f29(){
                                    return f29;
                                }
                            
                                inline void set_f30(int64_t val){
                                    f30 = val;
                                }
                                inline int64_t& get_f30(){
                                    return f30;
                                }
                            
                                inline void set_f31(int64_t val){
                                    f31 = val;
                                }
                                inline int64_t& get_f31(){
                                    return f31;
                                }
                            
                                inline void set_f32(int64_t val){
                                    f32 = val;
                                }
                                inline int64_t& get_f32(){
                                    return f32;
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
                                    fout << "M15->f9: " << f9 << std::endl;
                                    fout << "M15->f10: " << f10 << std::endl;
                                    fout << "M15->f11: " << f11 << std::endl;
                                    fout << "M15->f12: " << f12 << std::endl;
                                    fout << "M15->f13: " << f13 << std::endl;
                                    fout << "M15->f14: " << f14 << std::endl;
                                    fout << "M15->f15: " << f15 << std::endl;
                                    fout << "M15->f16: " << f16 << std::endl;
                                    fout << "M15->f17: " << f17 << std::endl;
                                    fout << "M15->f18: " << f18 << std::endl;
                                    fout << "M15->f19: " << f19 << std::endl;
                                    fout << "M15->f20: " << f20 << std::endl;
                                    fout << "M15->f21: " << f21 << std::endl;
                                    fout << "M15->f22: " << f22 << std::endl;
                                    fout << "M15->f23: " << f23 << std::endl;
                                    fout << "M15->f24: " << f24 << std::endl;
                                    fout << "M15->f25: " << f25 << std::endl;
                                    fout << "M15->f26: " << f26 << std::endl;
                                    fout << "M15->f27: " << f27 << std::endl;
                                    fout << "M15->f28: " << f28 << std::endl;
                                    fout << "M15->f29: " << f29 << std::endl;
                                    fout << "M15->f30: " << f30 << std::endl;
                                    fout << "M15->f31: " << f31 << std::endl;
                                    fout << "M15->f32: " << f32 << std::endl;
                                }
                            
                                ~M15(){
                                }
                            
                                M15(){
                                }
                            
                            private:
                                alignas(8) int64_t f1;
                                alignas(8) int64_t f2;
                                alignas(8) int64_t f3;
                                alignas(8) int64_t f4;
                                alignas(8) int64_t f5;
                                alignas(8) int64_t f6;
                                alignas(8) int64_t f7;
                                alignas(8) int64_t f8;
                                alignas(8) int64_t f9;
                                alignas(8) int64_t f10;
                                alignas(8) int64_t f11;
                                alignas(8) int64_t f12;
                                alignas(8) int64_t f13;
                                alignas(8) int64_t f14;
                                alignas(8) int64_t f15;
                                alignas(8) int64_t f16;
                                alignas(8) int64_t f17;
                                alignas(8) int64_t f18;
                                alignas(8) int64_t f19;
                                alignas(8) int64_t f20;
                                alignas(8) int64_t f21;
                                alignas(8) int64_t f22;
                                alignas(8) int64_t f23;
                                alignas(8) int64_t f24;
                                alignas(8) int64_t f25;
                                alignas(8) int64_t f26;
                                alignas(8) int64_t f27;
                                alignas(8) int64_t f28;
                                alignas(8) int64_t f29;
                                alignas(8) int64_t f30;
                                alignas(8) int64_t f31;
                                alignas(8) int64_t f32;
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
                        
                            inline void set_f11(int64_t val){
                                f11 = val;
                            }
                            inline int64_t& get_f11(){
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
                        
                            inline void set_f14(int64_t val){
                                f14 = val;
                            }
                            inline int64_t& get_f14(){
                                return f14;
                            }
                        
                            inline void set_f15(int64_t val){
                                f15 = val;
                            }
                            inline int64_t& get_f15(){
                                return f15;
                            }
                        
                            inline void set_f16(int64_t val){
                                f16 = val;
                            }
                            inline int64_t& get_f16(){
                                return f16;
                            }
                        
                            inline void set_f17(int64_t val){
                                f17 = val;
                            }
                            inline int64_t& get_f17(){
                                return f17;
                            }
                        
                            inline void set_f18(int64_t val){
                                f18 = val;
                            }
                            inline int64_t& get_f18(){
                                return f18;
                            }
                        
                            inline void set_f19(int64_t val){
                                f19 = val;
                            }
                            inline int64_t& get_f19(){
                                return f19;
                            }
                        
                            inline void set_f20(int64_t val){
                                f20 = val;
                            }
                            inline int64_t& get_f20(){
                                return f20;
                            }
                        
                            inline void set_f21(int64_t val){
                                f21 = val;
                            }
                            inline int64_t& get_f21(){
                                return f21;
                            }
                        
                            inline void set_f22(int64_t val){
                                f22 = val;
                            }
                            inline int64_t& get_f22(){
                                return f22;
                            }
                        
                            inline void set_f23(int64_t val){
                                f23 = val;
                            }
                            inline int64_t& get_f23(){
                                return f23;
                            }
                        
                            inline void set_f24(int64_t val){
                                f24 = val;
                            }
                            inline int64_t& get_f24(){
                                return f24;
                            }
                        
                            inline void set_f25(int64_t val){
                                f25 = val;
                            }
                            inline int64_t& get_f25(){
                                return f25;
                            }
                        
                            inline void set_f26(int64_t val){
                                f26 = val;
                            }
                            inline int64_t& get_f26(){
                                return f26;
                            }
                        
                            inline void set_f27(int64_t val){
                                f27 = val;
                            }
                            inline int64_t& get_f27(){
                                return f27;
                            }
                        
                            inline void set_f28(int64_t val){
                                f28 = val;
                            }
                            inline int64_t& get_f28(){
                                return f28;
                            }
                        
                            inline void set_f29(int64_t val){
                                f29 = val;
                            }
                            inline int64_t& get_f29(){
                                return f29;
                            }
                        
                            inline void set_f30(int64_t val){
                                f30 = val;
                            }
                            inline int64_t& get_f30(){
                                return f30;
                            }
                        
                            inline void set_f31(int64_t val){
                                f31 = val;
                            }
                            inline int64_t& get_f31(){
                                return f31;
                            }
                        
                            inline void set_f32(int64_t val){
                                f32 = val;
                            }
                            inline int64_t& get_f32(){
                                return f32;
                            }
                        
                            inline M15* mutable_f33(){
                                f33 = new M15();
                                return f33;
                            }
                            inline M15*& get_f33(){
                                return f33;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M14->f1: " << f1 << std::endl;
                                fout << "M14->f2: " << f2 << std::endl;
                                fout << "M14->f3: " << f3 << std::endl;
                                fout << "M14->f4: " << f4 << std::endl;
                                fout << "M14->f5: " << f5 << std::endl;
                                fout << "M14->f6: " << f6 << std::endl;
                                fout << "M14->f7: " << f7 << std::endl;
                                fout << "M14->f8: " << f8 << std::endl;
                                fout << "M14->f9: " << f9 << std::endl;
                                fout << "M14->f10: " << f10 << std::endl;
                                fout << "M14->f11: " << f11 << std::endl;
                                fout << "M14->f12: " << f12 << std::endl;
                                fout << "M14->f13: " << f13 << std::endl;
                                fout << "M14->f14: " << f14 << std::endl;
                                fout << "M14->f15: " << f15 << std::endl;
                                fout << "M14->f16: " << f16 << std::endl;
                                fout << "M14->f17: " << f17 << std::endl;
                                fout << "M14->f18: " << f18 << std::endl;
                                fout << "M14->f19: " << f19 << std::endl;
                                fout << "M14->f20: " << f20 << std::endl;
                                fout << "M14->f21: " << f21 << std::endl;
                                fout << "M14->f22: " << f22 << std::endl;
                                fout << "M14->f23: " << f23 << std::endl;
                                fout << "M14->f24: " << f24 << std::endl;
                                fout << "M14->f25: " << f25 << std::endl;
                                fout << "M14->f26: " << f26 << std::endl;
                                fout << "M14->f27: " << f27 << std::endl;
                                fout << "M14->f28: " << f28 << std::endl;
                                fout << "M14->f29: " << f29 << std::endl;
                                fout << "M14->f30: " << f30 << std::endl;
                                fout << "M14->f31: " << f31 << std::endl;
                                fout << "M14->f32: " << f32 << std::endl;
                                if(f33 != nullptr)
                                    f33->print_message(fout);
                            }
                        
                            ~M14(){
                                if(f33 != nullptr)
                                    delete f33;
                            }
                        
                            M14(){
                               f33 = nullptr;
                            }
                        
                        private:
                            alignas(8) int64_t f1;
                            alignas(8) int64_t f2;
                            alignas(8) int64_t f3;
                            alignas(8) int64_t f4;
                            alignas(8) int64_t f5;
                            alignas(8) int64_t f6;
                            alignas(8) int64_t f7;
                            alignas(8) int64_t f8;
                            alignas(8) int64_t f9;
                            alignas(8) int64_t f10;
                            alignas(8) int64_t f11;
                            alignas(8) int64_t f12;
                            alignas(8) int64_t f13;
                            alignas(8) int64_t f14;
                            alignas(8) int64_t f15;
                            alignas(8) int64_t f16;
                            alignas(8) int64_t f17;
                            alignas(8) int64_t f18;
                            alignas(8) int64_t f19;
                            alignas(8) int64_t f20;
                            alignas(8) int64_t f21;
                            alignas(8) int64_t f22;
                            alignas(8) int64_t f23;
                            alignas(8) int64_t f24;
                            alignas(8) int64_t f25;
                            alignas(8) int64_t f26;
                            alignas(8) int64_t f27;
                            alignas(8) int64_t f28;
                            alignas(8) int64_t f29;
                            alignas(8) int64_t f30;
                            alignas(8) int64_t f31;
                            alignas(8) int64_t f32;
                            alignas(8) M15* f33;
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
                    
                        inline void set_f11(int64_t val){
                            f11 = val;
                        }
                        inline int64_t& get_f11(){
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
                    
                        inline void set_f14(int64_t val){
                            f14 = val;
                        }
                        inline int64_t& get_f14(){
                            return f14;
                        }
                    
                        inline void set_f15(int64_t val){
                            f15 = val;
                        }
                        inline int64_t& get_f15(){
                            return f15;
                        }
                    
                        inline void set_f16(int64_t val){
                            f16 = val;
                        }
                        inline int64_t& get_f16(){
                            return f16;
                        }
                    
                        inline void set_f17(int64_t val){
                            f17 = val;
                        }
                        inline int64_t& get_f17(){
                            return f17;
                        }
                    
                        inline void set_f18(int64_t val){
                            f18 = val;
                        }
                        inline int64_t& get_f18(){
                            return f18;
                        }
                    
                        inline void set_f19(int64_t val){
                            f19 = val;
                        }
                        inline int64_t& get_f19(){
                            return f19;
                        }
                    
                        inline void set_f20(int64_t val){
                            f20 = val;
                        }
                        inline int64_t& get_f20(){
                            return f20;
                        }
                    
                        inline void set_f21(int64_t val){
                            f21 = val;
                        }
                        inline int64_t& get_f21(){
                            return f21;
                        }
                    
                        inline void set_f22(int64_t val){
                            f22 = val;
                        }
                        inline int64_t& get_f22(){
                            return f22;
                        }
                    
                        inline void set_f23(int64_t val){
                            f23 = val;
                        }
                        inline int64_t& get_f23(){
                            return f23;
                        }
                    
                        inline void set_f24(int64_t val){
                            f24 = val;
                        }
                        inline int64_t& get_f24(){
                            return f24;
                        }
                    
                        inline void set_f25(int64_t val){
                            f25 = val;
                        }
                        inline int64_t& get_f25(){
                            return f25;
                        }
                    
                        inline void set_f26(int64_t val){
                            f26 = val;
                        }
                        inline int64_t& get_f26(){
                            return f26;
                        }
                    
                        inline void set_f27(int64_t val){
                            f27 = val;
                        }
                        inline int64_t& get_f27(){
                            return f27;
                        }
                    
                        inline void set_f28(int64_t val){
                            f28 = val;
                        }
                        inline int64_t& get_f28(){
                            return f28;
                        }
                    
                        inline void set_f29(int64_t val){
                            f29 = val;
                        }
                        inline int64_t& get_f29(){
                            return f29;
                        }
                    
                        inline void set_f30(int64_t val){
                            f30 = val;
                        }
                        inline int64_t& get_f30(){
                            return f30;
                        }
                    
                        inline void set_f31(int64_t val){
                            f31 = val;
                        }
                        inline int64_t& get_f31(){
                            return f31;
                        }
                    
                        inline void set_f32(int64_t val){
                            f32 = val;
                        }
                        inline int64_t& get_f32(){
                            return f32;
                        }
                    
                        inline M14* mutable_f33(){
                            f33 = new M14();
                            return f33;
                        }
                        inline M14*& get_f33(){
                            return f33;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M13->f1: " << f1 << std::endl;
                            fout << "M13->f2: " << f2 << std::endl;
                            fout << "M13->f3: " << f3 << std::endl;
                            fout << "M13->f4: " << f4 << std::endl;
                            fout << "M13->f5: " << f5 << std::endl;
                            fout << "M13->f6: " << f6 << std::endl;
                            fout << "M13->f7: " << f7 << std::endl;
                            fout << "M13->f8: " << f8 << std::endl;
                            fout << "M13->f9: " << f9 << std::endl;
                            fout << "M13->f10: " << f10 << std::endl;
                            fout << "M13->f11: " << f11 << std::endl;
                            fout << "M13->f12: " << f12 << std::endl;
                            fout << "M13->f13: " << f13 << std::endl;
                            fout << "M13->f14: " << f14 << std::endl;
                            fout << "M13->f15: " << f15 << std::endl;
                            fout << "M13->f16: " << f16 << std::endl;
                            fout << "M13->f17: " << f17 << std::endl;
                            fout << "M13->f18: " << f18 << std::endl;
                            fout << "M13->f19: " << f19 << std::endl;
                            fout << "M13->f20: " << f20 << std::endl;
                            fout << "M13->f21: " << f21 << std::endl;
                            fout << "M13->f22: " << f22 << std::endl;
                            fout << "M13->f23: " << f23 << std::endl;
                            fout << "M13->f24: " << f24 << std::endl;
                            fout << "M13->f25: " << f25 << std::endl;
                            fout << "M13->f26: " << f26 << std::endl;
                            fout << "M13->f27: " << f27 << std::endl;
                            fout << "M13->f28: " << f28 << std::endl;
                            fout << "M13->f29: " << f29 << std::endl;
                            fout << "M13->f30: " << f30 << std::endl;
                            fout << "M13->f31: " << f31 << std::endl;
                            fout << "M13->f32: " << f32 << std::endl;
                            if(f33 != nullptr)
                                f33->print_message(fout);
                        }
                    
                        ~M13(){
                            if(f33 != nullptr)
                                delete f33;
                        }
                    
                        M13(){
                           f33 = nullptr;
                        }
                    
                    private:
                        alignas(8) int64_t f1;
                        alignas(8) int64_t f2;
                        alignas(8) int64_t f3;
                        alignas(8) int64_t f4;
                        alignas(8) int64_t f5;
                        alignas(8) int64_t f6;
                        alignas(8) int64_t f7;
                        alignas(8) int64_t f8;
                        alignas(8) int64_t f9;
                        alignas(8) int64_t f10;
                        alignas(8) int64_t f11;
                        alignas(8) int64_t f12;
                        alignas(8) int64_t f13;
                        alignas(8) int64_t f14;
                        alignas(8) int64_t f15;
                        alignas(8) int64_t f16;
                        alignas(8) int64_t f17;
                        alignas(8) int64_t f18;
                        alignas(8) int64_t f19;
                        alignas(8) int64_t f20;
                        alignas(8) int64_t f21;
                        alignas(8) int64_t f22;
                        alignas(8) int64_t f23;
                        alignas(8) int64_t f24;
                        alignas(8) int64_t f25;
                        alignas(8) int64_t f26;
                        alignas(8) int64_t f27;
                        alignas(8) int64_t f28;
                        alignas(8) int64_t f29;
                        alignas(8) int64_t f30;
                        alignas(8) int64_t f31;
                        alignas(8) int64_t f32;
                        alignas(8) M14* f33;
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
                
                    inline void set_f11(int64_t val){
                        f11 = val;
                    }
                    inline int64_t& get_f11(){
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
                
                    inline void set_f14(int64_t val){
                        f14 = val;
                    }
                    inline int64_t& get_f14(){
                        return f14;
                    }
                
                    inline void set_f15(int64_t val){
                        f15 = val;
                    }
                    inline int64_t& get_f15(){
                        return f15;
                    }
                
                    inline void set_f16(int64_t val){
                        f16 = val;
                    }
                    inline int64_t& get_f16(){
                        return f16;
                    }
                
                    inline void set_f17(int64_t val){
                        f17 = val;
                    }
                    inline int64_t& get_f17(){
                        return f17;
                    }
                
                    inline void set_f18(int64_t val){
                        f18 = val;
                    }
                    inline int64_t& get_f18(){
                        return f18;
                    }
                
                    inline void set_f19(int64_t val){
                        f19 = val;
                    }
                    inline int64_t& get_f19(){
                        return f19;
                    }
                
                    inline void set_f20(int64_t val){
                        f20 = val;
                    }
                    inline int64_t& get_f20(){
                        return f20;
                    }
                
                    inline void set_f21(int64_t val){
                        f21 = val;
                    }
                    inline int64_t& get_f21(){
                        return f21;
                    }
                
                    inline void set_f22(int64_t val){
                        f22 = val;
                    }
                    inline int64_t& get_f22(){
                        return f22;
                    }
                
                    inline void set_f23(int64_t val){
                        f23 = val;
                    }
                    inline int64_t& get_f23(){
                        return f23;
                    }
                
                    inline void set_f24(int64_t val){
                        f24 = val;
                    }
                    inline int64_t& get_f24(){
                        return f24;
                    }
                
                    inline void set_f25(int64_t val){
                        f25 = val;
                    }
                    inline int64_t& get_f25(){
                        return f25;
                    }
                
                    inline void set_f26(int64_t val){
                        f26 = val;
                    }
                    inline int64_t& get_f26(){
                        return f26;
                    }
                
                    inline void set_f27(int64_t val){
                        f27 = val;
                    }
                    inline int64_t& get_f27(){
                        return f27;
                    }
                
                    inline void set_f28(int64_t val){
                        f28 = val;
                    }
                    inline int64_t& get_f28(){
                        return f28;
                    }
                
                    inline void set_f29(int64_t val){
                        f29 = val;
                    }
                    inline int64_t& get_f29(){
                        return f29;
                    }
                
                    inline void set_f30(int64_t val){
                        f30 = val;
                    }
                    inline int64_t& get_f30(){
                        return f30;
                    }
                
                    inline void set_f31(int64_t val){
                        f31 = val;
                    }
                    inline int64_t& get_f31(){
                        return f31;
                    }
                
                    inline void set_f32(int64_t val){
                        f32 = val;
                    }
                    inline int64_t& get_f32(){
                        return f32;
                    }
                
                    inline M13* mutable_f33(){
                        f33 = new M13();
                        return f33;
                    }
                    inline M13*& get_f33(){
                        return f33;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M12->f1: " << f1 << std::endl;
                        fout << "M12->f2: " << f2 << std::endl;
                        fout << "M12->f3: " << f3 << std::endl;
                        fout << "M12->f4: " << f4 << std::endl;
                        fout << "M12->f5: " << f5 << std::endl;
                        fout << "M12->f6: " << f6 << std::endl;
                        fout << "M12->f7: " << f7 << std::endl;
                        fout << "M12->f8: " << f8 << std::endl;
                        fout << "M12->f9: " << f9 << std::endl;
                        fout << "M12->f10: " << f10 << std::endl;
                        fout << "M12->f11: " << f11 << std::endl;
                        fout << "M12->f12: " << f12 << std::endl;
                        fout << "M12->f13: " << f13 << std::endl;
                        fout << "M12->f14: " << f14 << std::endl;
                        fout << "M12->f15: " << f15 << std::endl;
                        fout << "M12->f16: " << f16 << std::endl;
                        fout << "M12->f17: " << f17 << std::endl;
                        fout << "M12->f18: " << f18 << std::endl;
                        fout << "M12->f19: " << f19 << std::endl;
                        fout << "M12->f20: " << f20 << std::endl;
                        fout << "M12->f21: " << f21 << std::endl;
                        fout << "M12->f22: " << f22 << std::endl;
                        fout << "M12->f23: " << f23 << std::endl;
                        fout << "M12->f24: " << f24 << std::endl;
                        fout << "M12->f25: " << f25 << std::endl;
                        fout << "M12->f26: " << f26 << std::endl;
                        fout << "M12->f27: " << f27 << std::endl;
                        fout << "M12->f28: " << f28 << std::endl;
                        fout << "M12->f29: " << f29 << std::endl;
                        fout << "M12->f30: " << f30 << std::endl;
                        fout << "M12->f31: " << f31 << std::endl;
                        fout << "M12->f32: " << f32 << std::endl;
                        if(f33 != nullptr)
                            f33->print_message(fout);
                    }
                
                    ~M12(){
                        if(f33 != nullptr)
                            delete f33;
                    }
                
                    M12(){
                       f33 = nullptr;
                    }
                
                private:
                    alignas(8) int64_t f1;
                    alignas(8) int64_t f2;
                    alignas(8) int64_t f3;
                    alignas(8) int64_t f4;
                    alignas(8) int64_t f5;
                    alignas(8) int64_t f6;
                    alignas(8) int64_t f7;
                    alignas(8) int64_t f8;
                    alignas(8) int64_t f9;
                    alignas(8) int64_t f10;
                    alignas(8) int64_t f11;
                    alignas(8) int64_t f12;
                    alignas(8) int64_t f13;
                    alignas(8) int64_t f14;
                    alignas(8) int64_t f15;
                    alignas(8) int64_t f16;
                    alignas(8) int64_t f17;
                    alignas(8) int64_t f18;
                    alignas(8) int64_t f19;
                    alignas(8) int64_t f20;
                    alignas(8) int64_t f21;
                    alignas(8) int64_t f22;
                    alignas(8) int64_t f23;
                    alignas(8) int64_t f24;
                    alignas(8) int64_t f25;
                    alignas(8) int64_t f26;
                    alignas(8) int64_t f27;
                    alignas(8) int64_t f28;
                    alignas(8) int64_t f29;
                    alignas(8) int64_t f30;
                    alignas(8) int64_t f31;
                    alignas(8) int64_t f32;
                    alignas(8) M13* f33;
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
            
                inline void set_f11(int64_t val){
                    f11 = val;
                }
                inline int64_t& get_f11(){
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
            
                inline void set_f14(int64_t val){
                    f14 = val;
                }
                inline int64_t& get_f14(){
                    return f14;
                }
            
                inline void set_f15(int64_t val){
                    f15 = val;
                }
                inline int64_t& get_f15(){
                    return f15;
                }
            
                inline void set_f16(int64_t val){
                    f16 = val;
                }
                inline int64_t& get_f16(){
                    return f16;
                }
            
                inline void set_f17(int64_t val){
                    f17 = val;
                }
                inline int64_t& get_f17(){
                    return f17;
                }
            
                inline void set_f18(int64_t val){
                    f18 = val;
                }
                inline int64_t& get_f18(){
                    return f18;
                }
            
                inline void set_f19(int64_t val){
                    f19 = val;
                }
                inline int64_t& get_f19(){
                    return f19;
                }
            
                inline void set_f20(int64_t val){
                    f20 = val;
                }
                inline int64_t& get_f20(){
                    return f20;
                }
            
                inline void set_f21(int64_t val){
                    f21 = val;
                }
                inline int64_t& get_f21(){
                    return f21;
                }
            
                inline void set_f22(int64_t val){
                    f22 = val;
                }
                inline int64_t& get_f22(){
                    return f22;
                }
            
                inline void set_f23(int64_t val){
                    f23 = val;
                }
                inline int64_t& get_f23(){
                    return f23;
                }
            
                inline void set_f24(int64_t val){
                    f24 = val;
                }
                inline int64_t& get_f24(){
                    return f24;
                }
            
                inline void set_f25(int64_t val){
                    f25 = val;
                }
                inline int64_t& get_f25(){
                    return f25;
                }
            
                inline void set_f26(int64_t val){
                    f26 = val;
                }
                inline int64_t& get_f26(){
                    return f26;
                }
            
                inline void set_f27(int64_t val){
                    f27 = val;
                }
                inline int64_t& get_f27(){
                    return f27;
                }
            
                inline void set_f28(int64_t val){
                    f28 = val;
                }
                inline int64_t& get_f28(){
                    return f28;
                }
            
                inline void set_f29(int64_t val){
                    f29 = val;
                }
                inline int64_t& get_f29(){
                    return f29;
                }
            
                inline void set_f30(int64_t val){
                    f30 = val;
                }
                inline int64_t& get_f30(){
                    return f30;
                }
            
                inline void set_f31(int64_t val){
                    f31 = val;
                }
                inline int64_t& get_f31(){
                    return f31;
                }
            
                inline void set_f32(int64_t val){
                    f32 = val;
                }
                inline int64_t& get_f32(){
                    return f32;
                }
            
                inline M12* mutable_f33(){
                    f33 = new M12();
                    return f33;
                }
                inline M12*& get_f33(){
                    return f33;
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
                    fout << "M11->f10: " << f10 << std::endl;
                    fout << "M11->f11: " << f11 << std::endl;
                    fout << "M11->f12: " << f12 << std::endl;
                    fout << "M11->f13: " << f13 << std::endl;
                    fout << "M11->f14: " << f14 << std::endl;
                    fout << "M11->f15: " << f15 << std::endl;
                    fout << "M11->f16: " << f16 << std::endl;
                    fout << "M11->f17: " << f17 << std::endl;
                    fout << "M11->f18: " << f18 << std::endl;
                    fout << "M11->f19: " << f19 << std::endl;
                    fout << "M11->f20: " << f20 << std::endl;
                    fout << "M11->f21: " << f21 << std::endl;
                    fout << "M11->f22: " << f22 << std::endl;
                    fout << "M11->f23: " << f23 << std::endl;
                    fout << "M11->f24: " << f24 << std::endl;
                    fout << "M11->f25: " << f25 << std::endl;
                    fout << "M11->f26: " << f26 << std::endl;
                    fout << "M11->f27: " << f27 << std::endl;
                    fout << "M11->f28: " << f28 << std::endl;
                    fout << "M11->f29: " << f29 << std::endl;
                    fout << "M11->f30: " << f30 << std::endl;
                    fout << "M11->f31: " << f31 << std::endl;
                    fout << "M11->f32: " << f32 << std::endl;
                    if(f33 != nullptr)
                        f33->print_message(fout);
                }
            
                ~M11(){
                    if(f33 != nullptr)
                        delete f33;
                }
            
                M11(){
                   f33 = nullptr;
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) int64_t f2;
                alignas(8) int64_t f3;
                alignas(8) int64_t f4;
                alignas(8) int64_t f5;
                alignas(8) int64_t f6;
                alignas(8) int64_t f7;
                alignas(8) int64_t f8;
                alignas(8) int64_t f9;
                alignas(8) int64_t f10;
                alignas(8) int64_t f11;
                alignas(8) int64_t f12;
                alignas(8) int64_t f13;
                alignas(8) int64_t f14;
                alignas(8) int64_t f15;
                alignas(8) int64_t f16;
                alignas(8) int64_t f17;
                alignas(8) int64_t f18;
                alignas(8) int64_t f19;
                alignas(8) int64_t f20;
                alignas(8) int64_t f21;
                alignas(8) int64_t f22;
                alignas(8) int64_t f23;
                alignas(8) int64_t f24;
                alignas(8) int64_t f25;
                alignas(8) int64_t f26;
                alignas(8) int64_t f27;
                alignas(8) int64_t f28;
                alignas(8) int64_t f29;
                alignas(8) int64_t f30;
                alignas(8) int64_t f31;
                alignas(8) int64_t f32;
                alignas(8) M12* f33;
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
        
            inline void set_f11(int64_t val){
                f11 = val;
            }
            inline int64_t& get_f11(){
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
        
            inline void set_f14(int64_t val){
                f14 = val;
            }
            inline int64_t& get_f14(){
                return f14;
            }
        
            inline void set_f15(int64_t val){
                f15 = val;
            }
            inline int64_t& get_f15(){
                return f15;
            }
        
            inline void set_f16(int64_t val){
                f16 = val;
            }
            inline int64_t& get_f16(){
                return f16;
            }
        
            inline void set_f17(int64_t val){
                f17 = val;
            }
            inline int64_t& get_f17(){
                return f17;
            }
        
            inline void set_f18(int64_t val){
                f18 = val;
            }
            inline int64_t& get_f18(){
                return f18;
            }
        
            inline void set_f19(int64_t val){
                f19 = val;
            }
            inline int64_t& get_f19(){
                return f19;
            }
        
            inline void set_f20(int64_t val){
                f20 = val;
            }
            inline int64_t& get_f20(){
                return f20;
            }
        
            inline void set_f21(int64_t val){
                f21 = val;
            }
            inline int64_t& get_f21(){
                return f21;
            }
        
            inline void set_f22(int64_t val){
                f22 = val;
            }
            inline int64_t& get_f22(){
                return f22;
            }
        
            inline void set_f23(int64_t val){
                f23 = val;
            }
            inline int64_t& get_f23(){
                return f23;
            }
        
            inline void set_f24(int64_t val){
                f24 = val;
            }
            inline int64_t& get_f24(){
                return f24;
            }
        
            inline void set_f25(int64_t val){
                f25 = val;
            }
            inline int64_t& get_f25(){
                return f25;
            }
        
            inline void set_f26(int64_t val){
                f26 = val;
            }
            inline int64_t& get_f26(){
                return f26;
            }
        
            inline void set_f27(int64_t val){
                f27 = val;
            }
            inline int64_t& get_f27(){
                return f27;
            }
        
            inline void set_f28(int64_t val){
                f28 = val;
            }
            inline int64_t& get_f28(){
                return f28;
            }
        
            inline void set_f29(int64_t val){
                f29 = val;
            }
            inline int64_t& get_f29(){
                return f29;
            }
        
            inline void set_f30(int64_t val){
                f30 = val;
            }
            inline int64_t& get_f30(){
                return f30;
            }
        
            inline void set_f31(int64_t val){
                f31 = val;
            }
            inline int64_t& get_f31(){
                return f31;
            }
        
            inline void set_f32(int64_t val){
                f32 = val;
            }
            inline int64_t& get_f32(){
                return f32;
            }
        
            inline M11* mutable_f33(){
                f33 = new M11();
                return f33;
            }
            inline M11*& get_f33(){
                return f33;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M10->f1: " << f1 << std::endl;
                fout << "M10->f2: " << f2 << std::endl;
                fout << "M10->f3: " << f3 << std::endl;
                fout << "M10->f4: " << f4 << std::endl;
                fout << "M10->f5: " << f5 << std::endl;
                fout << "M10->f6: " << f6 << std::endl;
                fout << "M10->f7: " << f7 << std::endl;
                fout << "M10->f8: " << f8 << std::endl;
                fout << "M10->f9: " << f9 << std::endl;
                fout << "M10->f10: " << f10 << std::endl;
                fout << "M10->f11: " << f11 << std::endl;
                fout << "M10->f12: " << f12 << std::endl;
                fout << "M10->f13: " << f13 << std::endl;
                fout << "M10->f14: " << f14 << std::endl;
                fout << "M10->f15: " << f15 << std::endl;
                fout << "M10->f16: " << f16 << std::endl;
                fout << "M10->f17: " << f17 << std::endl;
                fout << "M10->f18: " << f18 << std::endl;
                fout << "M10->f19: " << f19 << std::endl;
                fout << "M10->f20: " << f20 << std::endl;
                fout << "M10->f21: " << f21 << std::endl;
                fout << "M10->f22: " << f22 << std::endl;
                fout << "M10->f23: " << f23 << std::endl;
                fout << "M10->f24: " << f24 << std::endl;
                fout << "M10->f25: " << f25 << std::endl;
                fout << "M10->f26: " << f26 << std::endl;
                fout << "M10->f27: " << f27 << std::endl;
                fout << "M10->f28: " << f28 << std::endl;
                fout << "M10->f29: " << f29 << std::endl;
                fout << "M10->f30: " << f30 << std::endl;
                fout << "M10->f31: " << f31 << std::endl;
                fout << "M10->f32: " << f32 << std::endl;
                if(f33 != nullptr)
                    f33->print_message(fout);
            }
        
            ~M10(){
                if(f33 != nullptr)
                    delete f33;
            }
        
            M10(){
               f33 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int64_t f2;
            alignas(8) int64_t f3;
            alignas(8) int64_t f4;
            alignas(8) int64_t f5;
            alignas(8) int64_t f6;
            alignas(8) int64_t f7;
            alignas(8) int64_t f8;
            alignas(8) int64_t f9;
            alignas(8) int64_t f10;
            alignas(8) int64_t f11;
            alignas(8) int64_t f12;
            alignas(8) int64_t f13;
            alignas(8) int64_t f14;
            alignas(8) int64_t f15;
            alignas(8) int64_t f16;
            alignas(8) int64_t f17;
            alignas(8) int64_t f18;
            alignas(8) int64_t f19;
            alignas(8) int64_t f20;
            alignas(8) int64_t f21;
            alignas(8) int64_t f22;
            alignas(8) int64_t f23;
            alignas(8) int64_t f24;
            alignas(8) int64_t f25;
            alignas(8) int64_t f26;
            alignas(8) int64_t f27;
            alignas(8) int64_t f28;
            alignas(8) int64_t f29;
            alignas(8) int64_t f30;
            alignas(8) int64_t f31;
            alignas(8) int64_t f32;
            alignas(8) M11* f33;
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
    
        inline void set_f11(int64_t val){
            f11 = val;
        }
        inline int64_t& get_f11(){
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
    
        inline void set_f14(int64_t val){
            f14 = val;
        }
        inline int64_t& get_f14(){
            return f14;
        }
    
        inline void set_f15(int64_t val){
            f15 = val;
        }
        inline int64_t& get_f15(){
            return f15;
        }
    
        inline void set_f16(int64_t val){
            f16 = val;
        }
        inline int64_t& get_f16(){
            return f16;
        }
    
        inline void set_f17(int64_t val){
            f17 = val;
        }
        inline int64_t& get_f17(){
            return f17;
        }
    
        inline void set_f18(int64_t val){
            f18 = val;
        }
        inline int64_t& get_f18(){
            return f18;
        }
    
        inline void set_f19(int64_t val){
            f19 = val;
        }
        inline int64_t& get_f19(){
            return f19;
        }
    
        inline void set_f20(int64_t val){
            f20 = val;
        }
        inline int64_t& get_f20(){
            return f20;
        }
    
        inline void set_f21(int64_t val){
            f21 = val;
        }
        inline int64_t& get_f21(){
            return f21;
        }
    
        inline void set_f22(int64_t val){
            f22 = val;
        }
        inline int64_t& get_f22(){
            return f22;
        }
    
        inline void set_f23(int64_t val){
            f23 = val;
        }
        inline int64_t& get_f23(){
            return f23;
        }
    
        inline void set_f24(int64_t val){
            f24 = val;
        }
        inline int64_t& get_f24(){
            return f24;
        }
    
        inline void set_f25(int64_t val){
            f25 = val;
        }
        inline int64_t& get_f25(){
            return f25;
        }
    
        inline void set_f26(int64_t val){
            f26 = val;
        }
        inline int64_t& get_f26(){
            return f26;
        }
    
        inline void set_f27(int64_t val){
            f27 = val;
        }
        inline int64_t& get_f27(){
            return f27;
        }
    
        inline void set_f28(int64_t val){
            f28 = val;
        }
        inline int64_t& get_f28(){
            return f28;
        }
    
        inline void set_f29(int64_t val){
            f29 = val;
        }
        inline int64_t& get_f29(){
            return f29;
        }
    
        inline void set_f30(int64_t val){
            f30 = val;
        }
        inline int64_t& get_f30(){
            return f30;
        }
    
        inline void set_f31(int64_t val){
            f31 = val;
        }
        inline int64_t& get_f31(){
            return f31;
        }
    
        inline void set_f32(int64_t val){
            f32 = val;
        }
        inline int64_t& get_f32(){
            return f32;
        }
    
        inline M10* mutable_f33(){
            f33 = new M10();
            return f33;
        }
        inline M10*& get_f33(){
            return f33;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M9->f1: " << f1 << std::endl;
            fout << "M9->f2: " << f2 << std::endl;
            fout << "M9->f3: " << f3 << std::endl;
            fout << "M9->f4: " << f4 << std::endl;
            fout << "M9->f5: " << f5 << std::endl;
            fout << "M9->f6: " << f6 << std::endl;
            fout << "M9->f7: " << f7 << std::endl;
            fout << "M9->f8: " << f8 << std::endl;
            fout << "M9->f9: " << f9 << std::endl;
            fout << "M9->f10: " << f10 << std::endl;
            fout << "M9->f11: " << f11 << std::endl;
            fout << "M9->f12: " << f12 << std::endl;
            fout << "M9->f13: " << f13 << std::endl;
            fout << "M9->f14: " << f14 << std::endl;
            fout << "M9->f15: " << f15 << std::endl;
            fout << "M9->f16: " << f16 << std::endl;
            fout << "M9->f17: " << f17 << std::endl;
            fout << "M9->f18: " << f18 << std::endl;
            fout << "M9->f19: " << f19 << std::endl;
            fout << "M9->f20: " << f20 << std::endl;
            fout << "M9->f21: " << f21 << std::endl;
            fout << "M9->f22: " << f22 << std::endl;
            fout << "M9->f23: " << f23 << std::endl;
            fout << "M9->f24: " << f24 << std::endl;
            fout << "M9->f25: " << f25 << std::endl;
            fout << "M9->f26: " << f26 << std::endl;
            fout << "M9->f27: " << f27 << std::endl;
            fout << "M9->f28: " << f28 << std::endl;
            fout << "M9->f29: " << f29 << std::endl;
            fout << "M9->f30: " << f30 << std::endl;
            fout << "M9->f31: " << f31 << std::endl;
            fout << "M9->f32: " << f32 << std::endl;
            if(f33 != nullptr)
                f33->print_message(fout);
        }
    
        ~M9(){
            if(f33 != nullptr)
                delete f33;
        }
    
        M9(){
           f33 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
        alignas(8) int64_t f3;
        alignas(8) int64_t f4;
        alignas(8) int64_t f5;
        alignas(8) int64_t f6;
        alignas(8) int64_t f7;
        alignas(8) int64_t f8;
        alignas(8) int64_t f9;
        alignas(8) int64_t f10;
        alignas(8) int64_t f11;
        alignas(8) int64_t f12;
        alignas(8) int64_t f13;
        alignas(8) int64_t f14;
        alignas(8) int64_t f15;
        alignas(8) int64_t f16;
        alignas(8) int64_t f17;
        alignas(8) int64_t f18;
        alignas(8) int64_t f19;
        alignas(8) int64_t f20;
        alignas(8) int64_t f21;
        alignas(8) int64_t f22;
        alignas(8) int64_t f23;
        alignas(8) int64_t f24;
        alignas(8) int64_t f25;
        alignas(8) int64_t f26;
        alignas(8) int64_t f27;
        alignas(8) int64_t f28;
        alignas(8) int64_t f29;
        alignas(8) int64_t f30;
        alignas(8) int64_t f31;
        alignas(8) int64_t f32;
        alignas(8) M10* f33;
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

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
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

    inline void set_f14(int64_t val){
        f14 = val;
    }
    inline int64_t& get_f14(){
        return f14;
    }

    inline void set_f15(int64_t val){
        f15 = val;
    }
    inline int64_t& get_f15(){
        return f15;
    }

    inline void set_f16(int64_t val){
        f16 = val;
    }
    inline int64_t& get_f16(){
        return f16;
    }

    inline void set_f17(int64_t val){
        f17 = val;
    }
    inline int64_t& get_f17(){
        return f17;
    }

    inline void set_f18(int64_t val){
        f18 = val;
    }
    inline int64_t& get_f18(){
        return f18;
    }

    inline void set_f19(int64_t val){
        f19 = val;
    }
    inline int64_t& get_f19(){
        return f19;
    }

    inline void set_f20(int64_t val){
        f20 = val;
    }
    inline int64_t& get_f20(){
        return f20;
    }

    inline void set_f21(int64_t val){
        f21 = val;
    }
    inline int64_t& get_f21(){
        return f21;
    }

    inline void set_f22(int64_t val){
        f22 = val;
    }
    inline int64_t& get_f22(){
        return f22;
    }

    inline void set_f23(int64_t val){
        f23 = val;
    }
    inline int64_t& get_f23(){
        return f23;
    }

    inline void set_f24(int64_t val){
        f24 = val;
    }
    inline int64_t& get_f24(){
        return f24;
    }

    inline void set_f25(int64_t val){
        f25 = val;
    }
    inline int64_t& get_f25(){
        return f25;
    }

    inline void set_f26(int64_t val){
        f26 = val;
    }
    inline int64_t& get_f26(){
        return f26;
    }

    inline void set_f27(int64_t val){
        f27 = val;
    }
    inline int64_t& get_f27(){
        return f27;
    }

    inline void set_f28(int64_t val){
        f28 = val;
    }
    inline int64_t& get_f28(){
        return f28;
    }

    inline void set_f29(int64_t val){
        f29 = val;
    }
    inline int64_t& get_f29(){
        return f29;
    }

    inline void set_f30(int64_t val){
        f30 = val;
    }
    inline int64_t& get_f30(){
        return f30;
    }

    inline void set_f31(int64_t val){
        f31 = val;
    }
    inline int64_t& get_f31(){
        return f31;
    }

    inline void set_f32(int64_t val){
        f32 = val;
    }
    inline int64_t& get_f32(){
        return f32;
    }

    inline M9* mutable_f33(){
        f33 = new M9();
        return f33;
    }
    inline M9*& get_f33(){
        return f33;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M8->f1: " << f1 << std::endl;
        fout << "M8->f2: " << f2 << std::endl;
        fout << "M8->f3: " << f3 << std::endl;
        fout << "M8->f4: " << f4 << std::endl;
        fout << "M8->f5: " << f5 << std::endl;
        fout << "M8->f6: " << f6 << std::endl;
        fout << "M8->f7: " << f7 << std::endl;
        fout << "M8->f8: " << f8 << std::endl;
        fout << "M8->f9: " << f9 << std::endl;
        fout << "M8->f10: " << f10 << std::endl;
        fout << "M8->f11: " << f11 << std::endl;
        fout << "M8->f12: " << f12 << std::endl;
        fout << "M8->f13: " << f13 << std::endl;
        fout << "M8->f14: " << f14 << std::endl;
        fout << "M8->f15: " << f15 << std::endl;
        fout << "M8->f16: " << f16 << std::endl;
        fout << "M8->f17: " << f17 << std::endl;
        fout << "M8->f18: " << f18 << std::endl;
        fout << "M8->f19: " << f19 << std::endl;
        fout << "M8->f20: " << f20 << std::endl;
        fout << "M8->f21: " << f21 << std::endl;
        fout << "M8->f22: " << f22 << std::endl;
        fout << "M8->f23: " << f23 << std::endl;
        fout << "M8->f24: " << f24 << std::endl;
        fout << "M8->f25: " << f25 << std::endl;
        fout << "M8->f26: " << f26 << std::endl;
        fout << "M8->f27: " << f27 << std::endl;
        fout << "M8->f28: " << f28 << std::endl;
        fout << "M8->f29: " << f29 << std::endl;
        fout << "M8->f30: " << f30 << std::endl;
        fout << "M8->f31: " << f31 << std::endl;
        fout << "M8->f32: " << f32 << std::endl;
        if(f33 != nullptr)
            f33->print_message(fout);
    }

    ~M8(){
        if(f33 != nullptr)
            delete f33;
    }

    M8(){
       f33 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) int64_t f3;
    alignas(8) int64_t f4;
    alignas(8) int64_t f5;
    alignas(8) int64_t f6;
    alignas(8) int64_t f7;
    alignas(8) int64_t f8;
    alignas(8) int64_t f9;
    alignas(8) int64_t f10;
    alignas(8) int64_t f11;
    alignas(8) int64_t f12;
    alignas(8) int64_t f13;
    alignas(8) int64_t f14;
    alignas(8) int64_t f15;
    alignas(8) int64_t f16;
    alignas(8) int64_t f17;
    alignas(8) int64_t f18;
    alignas(8) int64_t f19;
    alignas(8) int64_t f20;
    alignas(8) int64_t f21;
    alignas(8) int64_t f22;
    alignas(8) int64_t f23;
    alignas(8) int64_t f24;
    alignas(8) int64_t f25;
    alignas(8) int64_t f26;
    alignas(8) int64_t f27;
    alignas(8) int64_t f28;
    alignas(8) int64_t f29;
    alignas(8) int64_t f30;
    alignas(8) int64_t f31;
    alignas(8) int64_t f32;
    alignas(8) M9* f33;
};


class alignas(8) M16 : public M_base
{
public:
    class alignas(8) M17 : public M_base
    {
    public:
        class alignas(8) M18 : public M_base
        {
        public:
            class alignas(8) M19 : public M_base
            {
            public:
                class alignas(8) M20 : public M_base
                {
                public:
                    class alignas(8) M21 : public M_base
                    {
                    public:
                        class alignas(8) M22 : public M_base
                        {
                        public:
                            class alignas(8) M23 : public M_base
                            {
                            public:
                                class alignas(8) M24 : public M_base
                                {
                                public:
                                    class alignas(8) M25 : public M_base
                                    {
                                    public:
                                        class alignas(8) M26 : public M_base
                                        {
                                        public:
                                            class alignas(8) M27 : public M_base
                                            {
                                            public:
                                                class alignas(8) M28 : public M_base
                                                {
                                                public:
                                                    class alignas(8) M29 : public M_base
                                                    {
                                                    public:
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
                                                            
                                                                inline void set_f11(int64_t val){
                                                                    f11 = val;
                                                                }
                                                                inline int64_t& get_f11(){
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
                                                            
                                                                inline void set_f14(int64_t val){
                                                                    f14 = val;
                                                                }
                                                                inline int64_t& get_f14(){
                                                                    return f14;
                                                                }
                                                            
                                                                inline void set_f15(int64_t val){
                                                                    f15 = val;
                                                                }
                                                                inline int64_t& get_f15(){
                                                                    return f15;
                                                                }
                                                            
                                                                inline void set_f16(int64_t val){
                                                                    f16 = val;
                                                                }
                                                                inline int64_t& get_f16(){
                                                                    return f16;
                                                                }
                                                            
                                                                inline void set_f17(int64_t val){
                                                                    f17 = val;
                                                                }
                                                                inline int64_t& get_f17(){
                                                                    return f17;
                                                                }
                                                            
                                                                inline void set_f18(int64_t val){
                                                                    f18 = val;
                                                                }
                                                                inline int64_t& get_f18(){
                                                                    return f18;
                                                                }
                                                            
                                                                inline void set_f19(int64_t val){
                                                                    f19 = val;
                                                                }
                                                                inline int64_t& get_f19(){
                                                                    return f19;
                                                                }
                                                            
                                                                inline void set_f20(int64_t val){
                                                                    f20 = val;
                                                                }
                                                                inline int64_t& get_f20(){
                                                                    return f20;
                                                                }
                                                            
                                                                inline void set_f21(int64_t val){
                                                                    f21 = val;
                                                                }
                                                                inline int64_t& get_f21(){
                                                                    return f21;
                                                                }
                                                            
                                                                inline void set_f22(int64_t val){
                                                                    f22 = val;
                                                                }
                                                                inline int64_t& get_f22(){
                                                                    return f22;
                                                                }
                                                            
                                                                inline void set_f23(int64_t val){
                                                                    f23 = val;
                                                                }
                                                                inline int64_t& get_f23(){
                                                                    return f23;
                                                                }
                                                            
                                                                inline void set_f24(int64_t val){
                                                                    f24 = val;
                                                                }
                                                                inline int64_t& get_f24(){
                                                                    return f24;
                                                                }
                                                            
                                                                inline void set_f25(int64_t val){
                                                                    f25 = val;
                                                                }
                                                                inline int64_t& get_f25(){
                                                                    return f25;
                                                                }
                                                            
                                                                inline void set_f26(int64_t val){
                                                                    f26 = val;
                                                                }
                                                                inline int64_t& get_f26(){
                                                                    return f26;
                                                                }
                                                            
                                                                inline void set_f27(int64_t val){
                                                                    f27 = val;
                                                                }
                                                                inline int64_t& get_f27(){
                                                                    return f27;
                                                                }
                                                            
                                                                inline void set_f28(int64_t val){
                                                                    f28 = val;
                                                                }
                                                                inline int64_t& get_f28(){
                                                                    return f28;
                                                                }
                                                            
                                                                inline void set_f29(int64_t val){
                                                                    f29 = val;
                                                                }
                                                                inline int64_t& get_f29(){
                                                                    return f29;
                                                                }
                                                            
                                                                inline void set_f30(int64_t val){
                                                                    f30 = val;
                                                                }
                                                                inline int64_t& get_f30(){
                                                                    return f30;
                                                                }
                                                            
                                                                inline void set_f31(int64_t val){
                                                                    f31 = val;
                                                                }
                                                                inline int64_t& get_f31(){
                                                                    return f31;
                                                                }
                                                            
                                                                inline void set_f32(int64_t val){
                                                                    f32 = val;
                                                                }
                                                                inline int64_t& get_f32(){
                                                                    return f32;
                                                                }
                                                            
                                                                inline void print_message(std::ofstream &fout){
                                                                    fout << "M31->f1: " << f1 << std::endl;
                                                                    fout << "M31->f2: " << f2 << std::endl;
                                                                    fout << "M31->f3: " << f3 << std::endl;
                                                                    fout << "M31->f4: " << f4 << std::endl;
                                                                    fout << "M31->f5: " << f5 << std::endl;
                                                                    fout << "M31->f6: " << f6 << std::endl;
                                                                    fout << "M31->f7: " << f7 << std::endl;
                                                                    fout << "M31->f8: " << f8 << std::endl;
                                                                    fout << "M31->f9: " << f9 << std::endl;
                                                                    fout << "M31->f10: " << f10 << std::endl;
                                                                    fout << "M31->f11: " << f11 << std::endl;
                                                                    fout << "M31->f12: " << f12 << std::endl;
                                                                    fout << "M31->f13: " << f13 << std::endl;
                                                                    fout << "M31->f14: " << f14 << std::endl;
                                                                    fout << "M31->f15: " << f15 << std::endl;
                                                                    fout << "M31->f16: " << f16 << std::endl;
                                                                    fout << "M31->f17: " << f17 << std::endl;
                                                                    fout << "M31->f18: " << f18 << std::endl;
                                                                    fout << "M31->f19: " << f19 << std::endl;
                                                                    fout << "M31->f20: " << f20 << std::endl;
                                                                    fout << "M31->f21: " << f21 << std::endl;
                                                                    fout << "M31->f22: " << f22 << std::endl;
                                                                    fout << "M31->f23: " << f23 << std::endl;
                                                                    fout << "M31->f24: " << f24 << std::endl;
                                                                    fout << "M31->f25: " << f25 << std::endl;
                                                                    fout << "M31->f26: " << f26 << std::endl;
                                                                    fout << "M31->f27: " << f27 << std::endl;
                                                                    fout << "M31->f28: " << f28 << std::endl;
                                                                    fout << "M31->f29: " << f29 << std::endl;
                                                                    fout << "M31->f30: " << f30 << std::endl;
                                                                    fout << "M31->f31: " << f31 << std::endl;
                                                                    fout << "M31->f32: " << f32 << std::endl;
                                                                }
                                                            
                                                                ~M31(){
                                                                }
                                                            
                                                                M31(){
                                                                }
                                                            
                                                            private:
                                                                alignas(8) int64_t f1;
                                                                alignas(8) int64_t f2;
                                                                alignas(8) int64_t f3;
                                                                alignas(8) int64_t f4;
                                                                alignas(8) int64_t f5;
                                                                alignas(8) int64_t f6;
                                                                alignas(8) int64_t f7;
                                                                alignas(8) int64_t f8;
                                                                alignas(8) int64_t f9;
                                                                alignas(8) int64_t f10;
                                                                alignas(8) int64_t f11;
                                                                alignas(8) int64_t f12;
                                                                alignas(8) int64_t f13;
                                                                alignas(8) int64_t f14;
                                                                alignas(8) int64_t f15;
                                                                alignas(8) int64_t f16;
                                                                alignas(8) int64_t f17;
                                                                alignas(8) int64_t f18;
                                                                alignas(8) int64_t f19;
                                                                alignas(8) int64_t f20;
                                                                alignas(8) int64_t f21;
                                                                alignas(8) int64_t f22;
                                                                alignas(8) int64_t f23;
                                                                alignas(8) int64_t f24;
                                                                alignas(8) int64_t f25;
                                                                alignas(8) int64_t f26;
                                                                alignas(8) int64_t f27;
                                                                alignas(8) int64_t f28;
                                                                alignas(8) int64_t f29;
                                                                alignas(8) int64_t f30;
                                                                alignas(8) int64_t f31;
                                                                alignas(8) int64_t f32;
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
                                                        
                                                            inline void set_f11(int64_t val){
                                                                f11 = val;
                                                            }
                                                            inline int64_t& get_f11(){
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
                                                        
                                                            inline void set_f14(int64_t val){
                                                                f14 = val;
                                                            }
                                                            inline int64_t& get_f14(){
                                                                return f14;
                                                            }
                                                        
                                                            inline void set_f15(int64_t val){
                                                                f15 = val;
                                                            }
                                                            inline int64_t& get_f15(){
                                                                return f15;
                                                            }
                                                        
                                                            inline void set_f16(int64_t val){
                                                                f16 = val;
                                                            }
                                                            inline int64_t& get_f16(){
                                                                return f16;
                                                            }
                                                        
                                                            inline void set_f17(int64_t val){
                                                                f17 = val;
                                                            }
                                                            inline int64_t& get_f17(){
                                                                return f17;
                                                            }
                                                        
                                                            inline void set_f18(int64_t val){
                                                                f18 = val;
                                                            }
                                                            inline int64_t& get_f18(){
                                                                return f18;
                                                            }
                                                        
                                                            inline void set_f19(int64_t val){
                                                                f19 = val;
                                                            }
                                                            inline int64_t& get_f19(){
                                                                return f19;
                                                            }
                                                        
                                                            inline void set_f20(int64_t val){
                                                                f20 = val;
                                                            }
                                                            inline int64_t& get_f20(){
                                                                return f20;
                                                            }
                                                        
                                                            inline void set_f21(int64_t val){
                                                                f21 = val;
                                                            }
                                                            inline int64_t& get_f21(){
                                                                return f21;
                                                            }
                                                        
                                                            inline void set_f22(int64_t val){
                                                                f22 = val;
                                                            }
                                                            inline int64_t& get_f22(){
                                                                return f22;
                                                            }
                                                        
                                                            inline void set_f23(int64_t val){
                                                                f23 = val;
                                                            }
                                                            inline int64_t& get_f23(){
                                                                return f23;
                                                            }
                                                        
                                                            inline void set_f24(int64_t val){
                                                                f24 = val;
                                                            }
                                                            inline int64_t& get_f24(){
                                                                return f24;
                                                            }
                                                        
                                                            inline void set_f25(int64_t val){
                                                                f25 = val;
                                                            }
                                                            inline int64_t& get_f25(){
                                                                return f25;
                                                            }
                                                        
                                                            inline void set_f26(int64_t val){
                                                                f26 = val;
                                                            }
                                                            inline int64_t& get_f26(){
                                                                return f26;
                                                            }
                                                        
                                                            inline void set_f27(int64_t val){
                                                                f27 = val;
                                                            }
                                                            inline int64_t& get_f27(){
                                                                return f27;
                                                            }
                                                        
                                                            inline void set_f28(int64_t val){
                                                                f28 = val;
                                                            }
                                                            inline int64_t& get_f28(){
                                                                return f28;
                                                            }
                                                        
                                                            inline void set_f29(int64_t val){
                                                                f29 = val;
                                                            }
                                                            inline int64_t& get_f29(){
                                                                return f29;
                                                            }
                                                        
                                                            inline void set_f30(int64_t val){
                                                                f30 = val;
                                                            }
                                                            inline int64_t& get_f30(){
                                                                return f30;
                                                            }
                                                        
                                                            inline void set_f31(int64_t val){
                                                                f31 = val;
                                                            }
                                                            inline int64_t& get_f31(){
                                                                return f31;
                                                            }
                                                        
                                                            inline void set_f32(int64_t val){
                                                                f32 = val;
                                                            }
                                                            inline int64_t& get_f32(){
                                                                return f32;
                                                            }
                                                        
                                                            inline M31* mutable_f33(){
                                                                f33 = new M31();
                                                                return f33;
                                                            }
                                                            inline M31*& get_f33(){
                                                                return f33;
                                                            }
                                                        
                                                            inline void print_message(std::ofstream &fout){
                                                                fout << "M30->f1: " << f1 << std::endl;
                                                                fout << "M30->f2: " << f2 << std::endl;
                                                                fout << "M30->f3: " << f3 << std::endl;
                                                                fout << "M30->f4: " << f4 << std::endl;
                                                                fout << "M30->f5: " << f5 << std::endl;
                                                                fout << "M30->f6: " << f6 << std::endl;
                                                                fout << "M30->f7: " << f7 << std::endl;
                                                                fout << "M30->f8: " << f8 << std::endl;
                                                                fout << "M30->f9: " << f9 << std::endl;
                                                                fout << "M30->f10: " << f10 << std::endl;
                                                                fout << "M30->f11: " << f11 << std::endl;
                                                                fout << "M30->f12: " << f12 << std::endl;
                                                                fout << "M30->f13: " << f13 << std::endl;
                                                                fout << "M30->f14: " << f14 << std::endl;
                                                                fout << "M30->f15: " << f15 << std::endl;
                                                                fout << "M30->f16: " << f16 << std::endl;
                                                                fout << "M30->f17: " << f17 << std::endl;
                                                                fout << "M30->f18: " << f18 << std::endl;
                                                                fout << "M30->f19: " << f19 << std::endl;
                                                                fout << "M30->f20: " << f20 << std::endl;
                                                                fout << "M30->f21: " << f21 << std::endl;
                                                                fout << "M30->f22: " << f22 << std::endl;
                                                                fout << "M30->f23: " << f23 << std::endl;
                                                                fout << "M30->f24: " << f24 << std::endl;
                                                                fout << "M30->f25: " << f25 << std::endl;
                                                                fout << "M30->f26: " << f26 << std::endl;
                                                                fout << "M30->f27: " << f27 << std::endl;
                                                                fout << "M30->f28: " << f28 << std::endl;
                                                                fout << "M30->f29: " << f29 << std::endl;
                                                                fout << "M30->f30: " << f30 << std::endl;
                                                                fout << "M30->f31: " << f31 << std::endl;
                                                                fout << "M30->f32: " << f32 << std::endl;
                                                                if(f33 != nullptr)
                                                                    f33->print_message(fout);
                                                            }
                                                        
                                                            ~M30(){
                                                                if(f33 != nullptr)
                                                                    delete f33;
                                                            }
                                                        
                                                            M30(){
                                                               f33 = nullptr;
                                                            }
                                                        
                                                        private:
                                                            alignas(8) int64_t f1;
                                                            alignas(8) int64_t f2;
                                                            alignas(8) int64_t f3;
                                                            alignas(8) int64_t f4;
                                                            alignas(8) int64_t f5;
                                                            alignas(8) int64_t f6;
                                                            alignas(8) int64_t f7;
                                                            alignas(8) int64_t f8;
                                                            alignas(8) int64_t f9;
                                                            alignas(8) int64_t f10;
                                                            alignas(8) int64_t f11;
                                                            alignas(8) int64_t f12;
                                                            alignas(8) int64_t f13;
                                                            alignas(8) int64_t f14;
                                                            alignas(8) int64_t f15;
                                                            alignas(8) int64_t f16;
                                                            alignas(8) int64_t f17;
                                                            alignas(8) int64_t f18;
                                                            alignas(8) int64_t f19;
                                                            alignas(8) int64_t f20;
                                                            alignas(8) int64_t f21;
                                                            alignas(8) int64_t f22;
                                                            alignas(8) int64_t f23;
                                                            alignas(8) int64_t f24;
                                                            alignas(8) int64_t f25;
                                                            alignas(8) int64_t f26;
                                                            alignas(8) int64_t f27;
                                                            alignas(8) int64_t f28;
                                                            alignas(8) int64_t f29;
                                                            alignas(8) int64_t f30;
                                                            alignas(8) int64_t f31;
                                                            alignas(8) int64_t f32;
                                                            alignas(8) M31* f33;
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
                                                    
                                                        inline void set_f11(int64_t val){
                                                            f11 = val;
                                                        }
                                                        inline int64_t& get_f11(){
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
                                                    
                                                        inline void set_f14(int64_t val){
                                                            f14 = val;
                                                        }
                                                        inline int64_t& get_f14(){
                                                            return f14;
                                                        }
                                                    
                                                        inline void set_f15(int64_t val){
                                                            f15 = val;
                                                        }
                                                        inline int64_t& get_f15(){
                                                            return f15;
                                                        }
                                                    
                                                        inline void set_f16(int64_t val){
                                                            f16 = val;
                                                        }
                                                        inline int64_t& get_f16(){
                                                            return f16;
                                                        }
                                                    
                                                        inline void set_f17(int64_t val){
                                                            f17 = val;
                                                        }
                                                        inline int64_t& get_f17(){
                                                            return f17;
                                                        }
                                                    
                                                        inline void set_f18(int64_t val){
                                                            f18 = val;
                                                        }
                                                        inline int64_t& get_f18(){
                                                            return f18;
                                                        }
                                                    
                                                        inline void set_f19(int64_t val){
                                                            f19 = val;
                                                        }
                                                        inline int64_t& get_f19(){
                                                            return f19;
                                                        }
                                                    
                                                        inline void set_f20(int64_t val){
                                                            f20 = val;
                                                        }
                                                        inline int64_t& get_f20(){
                                                            return f20;
                                                        }
                                                    
                                                        inline void set_f21(int64_t val){
                                                            f21 = val;
                                                        }
                                                        inline int64_t& get_f21(){
                                                            return f21;
                                                        }
                                                    
                                                        inline void set_f22(int64_t val){
                                                            f22 = val;
                                                        }
                                                        inline int64_t& get_f22(){
                                                            return f22;
                                                        }
                                                    
                                                        inline void set_f23(int64_t val){
                                                            f23 = val;
                                                        }
                                                        inline int64_t& get_f23(){
                                                            return f23;
                                                        }
                                                    
                                                        inline void set_f24(int64_t val){
                                                            f24 = val;
                                                        }
                                                        inline int64_t& get_f24(){
                                                            return f24;
                                                        }
                                                    
                                                        inline void set_f25(int64_t val){
                                                            f25 = val;
                                                        }
                                                        inline int64_t& get_f25(){
                                                            return f25;
                                                        }
                                                    
                                                        inline void set_f26(int64_t val){
                                                            f26 = val;
                                                        }
                                                        inline int64_t& get_f26(){
                                                            return f26;
                                                        }
                                                    
                                                        inline void set_f27(int64_t val){
                                                            f27 = val;
                                                        }
                                                        inline int64_t& get_f27(){
                                                            return f27;
                                                        }
                                                    
                                                        inline void set_f28(int64_t val){
                                                            f28 = val;
                                                        }
                                                        inline int64_t& get_f28(){
                                                            return f28;
                                                        }
                                                    
                                                        inline void set_f29(int64_t val){
                                                            f29 = val;
                                                        }
                                                        inline int64_t& get_f29(){
                                                            return f29;
                                                        }
                                                    
                                                        inline void set_f30(int64_t val){
                                                            f30 = val;
                                                        }
                                                        inline int64_t& get_f30(){
                                                            return f30;
                                                        }
                                                    
                                                        inline void set_f31(int64_t val){
                                                            f31 = val;
                                                        }
                                                        inline int64_t& get_f31(){
                                                            return f31;
                                                        }
                                                    
                                                        inline void set_f32(int64_t val){
                                                            f32 = val;
                                                        }
                                                        inline int64_t& get_f32(){
                                                            return f32;
                                                        }
                                                    
                                                        inline M30* mutable_f33(){
                                                            f33 = new M30();
                                                            return f33;
                                                        }
                                                        inline M30*& get_f33(){
                                                            return f33;
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
                                                            fout << "M29->f9: " << f9 << std::endl;
                                                            fout << "M29->f10: " << f10 << std::endl;
                                                            fout << "M29->f11: " << f11 << std::endl;
                                                            fout << "M29->f12: " << f12 << std::endl;
                                                            fout << "M29->f13: " << f13 << std::endl;
                                                            fout << "M29->f14: " << f14 << std::endl;
                                                            fout << "M29->f15: " << f15 << std::endl;
                                                            fout << "M29->f16: " << f16 << std::endl;
                                                            fout << "M29->f17: " << f17 << std::endl;
                                                            fout << "M29->f18: " << f18 << std::endl;
                                                            fout << "M29->f19: " << f19 << std::endl;
                                                            fout << "M29->f20: " << f20 << std::endl;
                                                            fout << "M29->f21: " << f21 << std::endl;
                                                            fout << "M29->f22: " << f22 << std::endl;
                                                            fout << "M29->f23: " << f23 << std::endl;
                                                            fout << "M29->f24: " << f24 << std::endl;
                                                            fout << "M29->f25: " << f25 << std::endl;
                                                            fout << "M29->f26: " << f26 << std::endl;
                                                            fout << "M29->f27: " << f27 << std::endl;
                                                            fout << "M29->f28: " << f28 << std::endl;
                                                            fout << "M29->f29: " << f29 << std::endl;
                                                            fout << "M29->f30: " << f30 << std::endl;
                                                            fout << "M29->f31: " << f31 << std::endl;
                                                            fout << "M29->f32: " << f32 << std::endl;
                                                            if(f33 != nullptr)
                                                                f33->print_message(fout);
                                                        }
                                                    
                                                        ~M29(){
                                                            if(f33 != nullptr)
                                                                delete f33;
                                                        }
                                                    
                                                        M29(){
                                                           f33 = nullptr;
                                                        }
                                                    
                                                    private:
                                                        alignas(8) int64_t f1;
                                                        alignas(8) int64_t f2;
                                                        alignas(8) int64_t f3;
                                                        alignas(8) int64_t f4;
                                                        alignas(8) int64_t f5;
                                                        alignas(8) int64_t f6;
                                                        alignas(8) int64_t f7;
                                                        alignas(8) int64_t f8;
                                                        alignas(8) int64_t f9;
                                                        alignas(8) int64_t f10;
                                                        alignas(8) int64_t f11;
                                                        alignas(8) int64_t f12;
                                                        alignas(8) int64_t f13;
                                                        alignas(8) int64_t f14;
                                                        alignas(8) int64_t f15;
                                                        alignas(8) int64_t f16;
                                                        alignas(8) int64_t f17;
                                                        alignas(8) int64_t f18;
                                                        alignas(8) int64_t f19;
                                                        alignas(8) int64_t f20;
                                                        alignas(8) int64_t f21;
                                                        alignas(8) int64_t f22;
                                                        alignas(8) int64_t f23;
                                                        alignas(8) int64_t f24;
                                                        alignas(8) int64_t f25;
                                                        alignas(8) int64_t f26;
                                                        alignas(8) int64_t f27;
                                                        alignas(8) int64_t f28;
                                                        alignas(8) int64_t f29;
                                                        alignas(8) int64_t f30;
                                                        alignas(8) int64_t f31;
                                                        alignas(8) int64_t f32;
                                                        alignas(8) M30* f33;
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
                                                
                                                    inline void set_f11(int64_t val){
                                                        f11 = val;
                                                    }
                                                    inline int64_t& get_f11(){
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
                                                
                                                    inline void set_f14(int64_t val){
                                                        f14 = val;
                                                    }
                                                    inline int64_t& get_f14(){
                                                        return f14;
                                                    }
                                                
                                                    inline void set_f15(int64_t val){
                                                        f15 = val;
                                                    }
                                                    inline int64_t& get_f15(){
                                                        return f15;
                                                    }
                                                
                                                    inline void set_f16(int64_t val){
                                                        f16 = val;
                                                    }
                                                    inline int64_t& get_f16(){
                                                        return f16;
                                                    }
                                                
                                                    inline void set_f17(int64_t val){
                                                        f17 = val;
                                                    }
                                                    inline int64_t& get_f17(){
                                                        return f17;
                                                    }
                                                
                                                    inline void set_f18(int64_t val){
                                                        f18 = val;
                                                    }
                                                    inline int64_t& get_f18(){
                                                        return f18;
                                                    }
                                                
                                                    inline void set_f19(int64_t val){
                                                        f19 = val;
                                                    }
                                                    inline int64_t& get_f19(){
                                                        return f19;
                                                    }
                                                
                                                    inline void set_f20(int64_t val){
                                                        f20 = val;
                                                    }
                                                    inline int64_t& get_f20(){
                                                        return f20;
                                                    }
                                                
                                                    inline void set_f21(int64_t val){
                                                        f21 = val;
                                                    }
                                                    inline int64_t& get_f21(){
                                                        return f21;
                                                    }
                                                
                                                    inline void set_f22(int64_t val){
                                                        f22 = val;
                                                    }
                                                    inline int64_t& get_f22(){
                                                        return f22;
                                                    }
                                                
                                                    inline void set_f23(int64_t val){
                                                        f23 = val;
                                                    }
                                                    inline int64_t& get_f23(){
                                                        return f23;
                                                    }
                                                
                                                    inline void set_f24(int64_t val){
                                                        f24 = val;
                                                    }
                                                    inline int64_t& get_f24(){
                                                        return f24;
                                                    }
                                                
                                                    inline void set_f25(int64_t val){
                                                        f25 = val;
                                                    }
                                                    inline int64_t& get_f25(){
                                                        return f25;
                                                    }
                                                
                                                    inline void set_f26(int64_t val){
                                                        f26 = val;
                                                    }
                                                    inline int64_t& get_f26(){
                                                        return f26;
                                                    }
                                                
                                                    inline void set_f27(int64_t val){
                                                        f27 = val;
                                                    }
                                                    inline int64_t& get_f27(){
                                                        return f27;
                                                    }
                                                
                                                    inline void set_f28(int64_t val){
                                                        f28 = val;
                                                    }
                                                    inline int64_t& get_f28(){
                                                        return f28;
                                                    }
                                                
                                                    inline void set_f29(int64_t val){
                                                        f29 = val;
                                                    }
                                                    inline int64_t& get_f29(){
                                                        return f29;
                                                    }
                                                
                                                    inline void set_f30(int64_t val){
                                                        f30 = val;
                                                    }
                                                    inline int64_t& get_f30(){
                                                        return f30;
                                                    }
                                                
                                                    inline void set_f31(int64_t val){
                                                        f31 = val;
                                                    }
                                                    inline int64_t& get_f31(){
                                                        return f31;
                                                    }
                                                
                                                    inline void set_f32(int64_t val){
                                                        f32 = val;
                                                    }
                                                    inline int64_t& get_f32(){
                                                        return f32;
                                                    }
                                                
                                                    inline M29* mutable_f33(){
                                                        f33 = new M29();
                                                        return f33;
                                                    }
                                                    inline M29*& get_f33(){
                                                        return f33;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M28->f1: " << f1 << std::endl;
                                                        fout << "M28->f2: " << f2 << std::endl;
                                                        fout << "M28->f3: " << f3 << std::endl;
                                                        fout << "M28->f4: " << f4 << std::endl;
                                                        fout << "M28->f5: " << f5 << std::endl;
                                                        fout << "M28->f6: " << f6 << std::endl;
                                                        fout << "M28->f7: " << f7 << std::endl;
                                                        fout << "M28->f8: " << f8 << std::endl;
                                                        fout << "M28->f9: " << f9 << std::endl;
                                                        fout << "M28->f10: " << f10 << std::endl;
                                                        fout << "M28->f11: " << f11 << std::endl;
                                                        fout << "M28->f12: " << f12 << std::endl;
                                                        fout << "M28->f13: " << f13 << std::endl;
                                                        fout << "M28->f14: " << f14 << std::endl;
                                                        fout << "M28->f15: " << f15 << std::endl;
                                                        fout << "M28->f16: " << f16 << std::endl;
                                                        fout << "M28->f17: " << f17 << std::endl;
                                                        fout << "M28->f18: " << f18 << std::endl;
                                                        fout << "M28->f19: " << f19 << std::endl;
                                                        fout << "M28->f20: " << f20 << std::endl;
                                                        fout << "M28->f21: " << f21 << std::endl;
                                                        fout << "M28->f22: " << f22 << std::endl;
                                                        fout << "M28->f23: " << f23 << std::endl;
                                                        fout << "M28->f24: " << f24 << std::endl;
                                                        fout << "M28->f25: " << f25 << std::endl;
                                                        fout << "M28->f26: " << f26 << std::endl;
                                                        fout << "M28->f27: " << f27 << std::endl;
                                                        fout << "M28->f28: " << f28 << std::endl;
                                                        fout << "M28->f29: " << f29 << std::endl;
                                                        fout << "M28->f30: " << f30 << std::endl;
                                                        fout << "M28->f31: " << f31 << std::endl;
                                                        fout << "M28->f32: " << f32 << std::endl;
                                                        if(f33 != nullptr)
                                                            f33->print_message(fout);
                                                    }
                                                
                                                    ~M28(){
                                                        if(f33 != nullptr)
                                                            delete f33;
                                                    }
                                                
                                                    M28(){
                                                       f33 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) int64_t f1;
                                                    alignas(8) int64_t f2;
                                                    alignas(8) int64_t f3;
                                                    alignas(8) int64_t f4;
                                                    alignas(8) int64_t f5;
                                                    alignas(8) int64_t f6;
                                                    alignas(8) int64_t f7;
                                                    alignas(8) int64_t f8;
                                                    alignas(8) int64_t f9;
                                                    alignas(8) int64_t f10;
                                                    alignas(8) int64_t f11;
                                                    alignas(8) int64_t f12;
                                                    alignas(8) int64_t f13;
                                                    alignas(8) int64_t f14;
                                                    alignas(8) int64_t f15;
                                                    alignas(8) int64_t f16;
                                                    alignas(8) int64_t f17;
                                                    alignas(8) int64_t f18;
                                                    alignas(8) int64_t f19;
                                                    alignas(8) int64_t f20;
                                                    alignas(8) int64_t f21;
                                                    alignas(8) int64_t f22;
                                                    alignas(8) int64_t f23;
                                                    alignas(8) int64_t f24;
                                                    alignas(8) int64_t f25;
                                                    alignas(8) int64_t f26;
                                                    alignas(8) int64_t f27;
                                                    alignas(8) int64_t f28;
                                                    alignas(8) int64_t f29;
                                                    alignas(8) int64_t f30;
                                                    alignas(8) int64_t f31;
                                                    alignas(8) int64_t f32;
                                                    alignas(8) M29* f33;
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
                                            
                                                inline void set_f11(int64_t val){
                                                    f11 = val;
                                                }
                                                inline int64_t& get_f11(){
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
                                            
                                                inline void set_f14(int64_t val){
                                                    f14 = val;
                                                }
                                                inline int64_t& get_f14(){
                                                    return f14;
                                                }
                                            
                                                inline void set_f15(int64_t val){
                                                    f15 = val;
                                                }
                                                inline int64_t& get_f15(){
                                                    return f15;
                                                }
                                            
                                                inline void set_f16(int64_t val){
                                                    f16 = val;
                                                }
                                                inline int64_t& get_f16(){
                                                    return f16;
                                                }
                                            
                                                inline void set_f17(int64_t val){
                                                    f17 = val;
                                                }
                                                inline int64_t& get_f17(){
                                                    return f17;
                                                }
                                            
                                                inline void set_f18(int64_t val){
                                                    f18 = val;
                                                }
                                                inline int64_t& get_f18(){
                                                    return f18;
                                                }
                                            
                                                inline void set_f19(int64_t val){
                                                    f19 = val;
                                                }
                                                inline int64_t& get_f19(){
                                                    return f19;
                                                }
                                            
                                                inline void set_f20(int64_t val){
                                                    f20 = val;
                                                }
                                                inline int64_t& get_f20(){
                                                    return f20;
                                                }
                                            
                                                inline void set_f21(int64_t val){
                                                    f21 = val;
                                                }
                                                inline int64_t& get_f21(){
                                                    return f21;
                                                }
                                            
                                                inline void set_f22(int64_t val){
                                                    f22 = val;
                                                }
                                                inline int64_t& get_f22(){
                                                    return f22;
                                                }
                                            
                                                inline void set_f23(int64_t val){
                                                    f23 = val;
                                                }
                                                inline int64_t& get_f23(){
                                                    return f23;
                                                }
                                            
                                                inline void set_f24(int64_t val){
                                                    f24 = val;
                                                }
                                                inline int64_t& get_f24(){
                                                    return f24;
                                                }
                                            
                                                inline void set_f25(int64_t val){
                                                    f25 = val;
                                                }
                                                inline int64_t& get_f25(){
                                                    return f25;
                                                }
                                            
                                                inline void set_f26(int64_t val){
                                                    f26 = val;
                                                }
                                                inline int64_t& get_f26(){
                                                    return f26;
                                                }
                                            
                                                inline void set_f27(int64_t val){
                                                    f27 = val;
                                                }
                                                inline int64_t& get_f27(){
                                                    return f27;
                                                }
                                            
                                                inline void set_f28(int64_t val){
                                                    f28 = val;
                                                }
                                                inline int64_t& get_f28(){
                                                    return f28;
                                                }
                                            
                                                inline void set_f29(int64_t val){
                                                    f29 = val;
                                                }
                                                inline int64_t& get_f29(){
                                                    return f29;
                                                }
                                            
                                                inline void set_f30(int64_t val){
                                                    f30 = val;
                                                }
                                                inline int64_t& get_f30(){
                                                    return f30;
                                                }
                                            
                                                inline void set_f31(int64_t val){
                                                    f31 = val;
                                                }
                                                inline int64_t& get_f31(){
                                                    return f31;
                                                }
                                            
                                                inline void set_f32(int64_t val){
                                                    f32 = val;
                                                }
                                                inline int64_t& get_f32(){
                                                    return f32;
                                                }
                                            
                                                inline M28* mutable_f33(){
                                                    f33 = new M28();
                                                    return f33;
                                                }
                                                inline M28*& get_f33(){
                                                    return f33;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    fout << "M27->f1: " << f1 << std::endl;
                                                    fout << "M27->f2: " << f2 << std::endl;
                                                    fout << "M27->f3: " << f3 << std::endl;
                                                    fout << "M27->f4: " << f4 << std::endl;
                                                    fout << "M27->f5: " << f5 << std::endl;
                                                    fout << "M27->f6: " << f6 << std::endl;
                                                    fout << "M27->f7: " << f7 << std::endl;
                                                    fout << "M27->f8: " << f8 << std::endl;
                                                    fout << "M27->f9: " << f9 << std::endl;
                                                    fout << "M27->f10: " << f10 << std::endl;
                                                    fout << "M27->f11: " << f11 << std::endl;
                                                    fout << "M27->f12: " << f12 << std::endl;
                                                    fout << "M27->f13: " << f13 << std::endl;
                                                    fout << "M27->f14: " << f14 << std::endl;
                                                    fout << "M27->f15: " << f15 << std::endl;
                                                    fout << "M27->f16: " << f16 << std::endl;
                                                    fout << "M27->f17: " << f17 << std::endl;
                                                    fout << "M27->f18: " << f18 << std::endl;
                                                    fout << "M27->f19: " << f19 << std::endl;
                                                    fout << "M27->f20: " << f20 << std::endl;
                                                    fout << "M27->f21: " << f21 << std::endl;
                                                    fout << "M27->f22: " << f22 << std::endl;
                                                    fout << "M27->f23: " << f23 << std::endl;
                                                    fout << "M27->f24: " << f24 << std::endl;
                                                    fout << "M27->f25: " << f25 << std::endl;
                                                    fout << "M27->f26: " << f26 << std::endl;
                                                    fout << "M27->f27: " << f27 << std::endl;
                                                    fout << "M27->f28: " << f28 << std::endl;
                                                    fout << "M27->f29: " << f29 << std::endl;
                                                    fout << "M27->f30: " << f30 << std::endl;
                                                    fout << "M27->f31: " << f31 << std::endl;
                                                    fout << "M27->f32: " << f32 << std::endl;
                                                    if(f33 != nullptr)
                                                        f33->print_message(fout);
                                                }
                                            
                                                ~M27(){
                                                    if(f33 != nullptr)
                                                        delete f33;
                                                }
                                            
                                                M27(){
                                                   f33 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) int64_t f1;
                                                alignas(8) int64_t f2;
                                                alignas(8) int64_t f3;
                                                alignas(8) int64_t f4;
                                                alignas(8) int64_t f5;
                                                alignas(8) int64_t f6;
                                                alignas(8) int64_t f7;
                                                alignas(8) int64_t f8;
                                                alignas(8) int64_t f9;
                                                alignas(8) int64_t f10;
                                                alignas(8) int64_t f11;
                                                alignas(8) int64_t f12;
                                                alignas(8) int64_t f13;
                                                alignas(8) int64_t f14;
                                                alignas(8) int64_t f15;
                                                alignas(8) int64_t f16;
                                                alignas(8) int64_t f17;
                                                alignas(8) int64_t f18;
                                                alignas(8) int64_t f19;
                                                alignas(8) int64_t f20;
                                                alignas(8) int64_t f21;
                                                alignas(8) int64_t f22;
                                                alignas(8) int64_t f23;
                                                alignas(8) int64_t f24;
                                                alignas(8) int64_t f25;
                                                alignas(8) int64_t f26;
                                                alignas(8) int64_t f27;
                                                alignas(8) int64_t f28;
                                                alignas(8) int64_t f29;
                                                alignas(8) int64_t f30;
                                                alignas(8) int64_t f31;
                                                alignas(8) int64_t f32;
                                                alignas(8) M28* f33;
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
                                        
                                            inline void set_f11(int64_t val){
                                                f11 = val;
                                            }
                                            inline int64_t& get_f11(){
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
                                        
                                            inline void set_f14(int64_t val){
                                                f14 = val;
                                            }
                                            inline int64_t& get_f14(){
                                                return f14;
                                            }
                                        
                                            inline void set_f15(int64_t val){
                                                f15 = val;
                                            }
                                            inline int64_t& get_f15(){
                                                return f15;
                                            }
                                        
                                            inline void set_f16(int64_t val){
                                                f16 = val;
                                            }
                                            inline int64_t& get_f16(){
                                                return f16;
                                            }
                                        
                                            inline void set_f17(int64_t val){
                                                f17 = val;
                                            }
                                            inline int64_t& get_f17(){
                                                return f17;
                                            }
                                        
                                            inline void set_f18(int64_t val){
                                                f18 = val;
                                            }
                                            inline int64_t& get_f18(){
                                                return f18;
                                            }
                                        
                                            inline void set_f19(int64_t val){
                                                f19 = val;
                                            }
                                            inline int64_t& get_f19(){
                                                return f19;
                                            }
                                        
                                            inline void set_f20(int64_t val){
                                                f20 = val;
                                            }
                                            inline int64_t& get_f20(){
                                                return f20;
                                            }
                                        
                                            inline void set_f21(int64_t val){
                                                f21 = val;
                                            }
                                            inline int64_t& get_f21(){
                                                return f21;
                                            }
                                        
                                            inline void set_f22(int64_t val){
                                                f22 = val;
                                            }
                                            inline int64_t& get_f22(){
                                                return f22;
                                            }
                                        
                                            inline void set_f23(int64_t val){
                                                f23 = val;
                                            }
                                            inline int64_t& get_f23(){
                                                return f23;
                                            }
                                        
                                            inline void set_f24(int64_t val){
                                                f24 = val;
                                            }
                                            inline int64_t& get_f24(){
                                                return f24;
                                            }
                                        
                                            inline void set_f25(int64_t val){
                                                f25 = val;
                                            }
                                            inline int64_t& get_f25(){
                                                return f25;
                                            }
                                        
                                            inline void set_f26(int64_t val){
                                                f26 = val;
                                            }
                                            inline int64_t& get_f26(){
                                                return f26;
                                            }
                                        
                                            inline void set_f27(int64_t val){
                                                f27 = val;
                                            }
                                            inline int64_t& get_f27(){
                                                return f27;
                                            }
                                        
                                            inline void set_f28(int64_t val){
                                                f28 = val;
                                            }
                                            inline int64_t& get_f28(){
                                                return f28;
                                            }
                                        
                                            inline void set_f29(int64_t val){
                                                f29 = val;
                                            }
                                            inline int64_t& get_f29(){
                                                return f29;
                                            }
                                        
                                            inline void set_f30(int64_t val){
                                                f30 = val;
                                            }
                                            inline int64_t& get_f30(){
                                                return f30;
                                            }
                                        
                                            inline void set_f31(int64_t val){
                                                f31 = val;
                                            }
                                            inline int64_t& get_f31(){
                                                return f31;
                                            }
                                        
                                            inline void set_f32(int64_t val){
                                                f32 = val;
                                            }
                                            inline int64_t& get_f32(){
                                                return f32;
                                            }
                                        
                                            inline M27* mutable_f33(){
                                                f33 = new M27();
                                                return f33;
                                            }
                                            inline M27*& get_f33(){
                                                return f33;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M26->f1: " << f1 << std::endl;
                                                fout << "M26->f2: " << f2 << std::endl;
                                                fout << "M26->f3: " << f3 << std::endl;
                                                fout << "M26->f4: " << f4 << std::endl;
                                                fout << "M26->f5: " << f5 << std::endl;
                                                fout << "M26->f6: " << f6 << std::endl;
                                                fout << "M26->f7: " << f7 << std::endl;
                                                fout << "M26->f8: " << f8 << std::endl;
                                                fout << "M26->f9: " << f9 << std::endl;
                                                fout << "M26->f10: " << f10 << std::endl;
                                                fout << "M26->f11: " << f11 << std::endl;
                                                fout << "M26->f12: " << f12 << std::endl;
                                                fout << "M26->f13: " << f13 << std::endl;
                                                fout << "M26->f14: " << f14 << std::endl;
                                                fout << "M26->f15: " << f15 << std::endl;
                                                fout << "M26->f16: " << f16 << std::endl;
                                                fout << "M26->f17: " << f17 << std::endl;
                                                fout << "M26->f18: " << f18 << std::endl;
                                                fout << "M26->f19: " << f19 << std::endl;
                                                fout << "M26->f20: " << f20 << std::endl;
                                                fout << "M26->f21: " << f21 << std::endl;
                                                fout << "M26->f22: " << f22 << std::endl;
                                                fout << "M26->f23: " << f23 << std::endl;
                                                fout << "M26->f24: " << f24 << std::endl;
                                                fout << "M26->f25: " << f25 << std::endl;
                                                fout << "M26->f26: " << f26 << std::endl;
                                                fout << "M26->f27: " << f27 << std::endl;
                                                fout << "M26->f28: " << f28 << std::endl;
                                                fout << "M26->f29: " << f29 << std::endl;
                                                fout << "M26->f30: " << f30 << std::endl;
                                                fout << "M26->f31: " << f31 << std::endl;
                                                fout << "M26->f32: " << f32 << std::endl;
                                                if(f33 != nullptr)
                                                    f33->print_message(fout);
                                            }
                                        
                                            ~M26(){
                                                if(f33 != nullptr)
                                                    delete f33;
                                            }
                                        
                                            M26(){
                                               f33 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) int64_t f1;
                                            alignas(8) int64_t f2;
                                            alignas(8) int64_t f3;
                                            alignas(8) int64_t f4;
                                            alignas(8) int64_t f5;
                                            alignas(8) int64_t f6;
                                            alignas(8) int64_t f7;
                                            alignas(8) int64_t f8;
                                            alignas(8) int64_t f9;
                                            alignas(8) int64_t f10;
                                            alignas(8) int64_t f11;
                                            alignas(8) int64_t f12;
                                            alignas(8) int64_t f13;
                                            alignas(8) int64_t f14;
                                            alignas(8) int64_t f15;
                                            alignas(8) int64_t f16;
                                            alignas(8) int64_t f17;
                                            alignas(8) int64_t f18;
                                            alignas(8) int64_t f19;
                                            alignas(8) int64_t f20;
                                            alignas(8) int64_t f21;
                                            alignas(8) int64_t f22;
                                            alignas(8) int64_t f23;
                                            alignas(8) int64_t f24;
                                            alignas(8) int64_t f25;
                                            alignas(8) int64_t f26;
                                            alignas(8) int64_t f27;
                                            alignas(8) int64_t f28;
                                            alignas(8) int64_t f29;
                                            alignas(8) int64_t f30;
                                            alignas(8) int64_t f31;
                                            alignas(8) int64_t f32;
                                            alignas(8) M27* f33;
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
                                    
                                        inline void set_f11(int64_t val){
                                            f11 = val;
                                        }
                                        inline int64_t& get_f11(){
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
                                    
                                        inline void set_f14(int64_t val){
                                            f14 = val;
                                        }
                                        inline int64_t& get_f14(){
                                            return f14;
                                        }
                                    
                                        inline void set_f15(int64_t val){
                                            f15 = val;
                                        }
                                        inline int64_t& get_f15(){
                                            return f15;
                                        }
                                    
                                        inline void set_f16(int64_t val){
                                            f16 = val;
                                        }
                                        inline int64_t& get_f16(){
                                            return f16;
                                        }
                                    
                                        inline void set_f17(int64_t val){
                                            f17 = val;
                                        }
                                        inline int64_t& get_f17(){
                                            return f17;
                                        }
                                    
                                        inline void set_f18(int64_t val){
                                            f18 = val;
                                        }
                                        inline int64_t& get_f18(){
                                            return f18;
                                        }
                                    
                                        inline void set_f19(int64_t val){
                                            f19 = val;
                                        }
                                        inline int64_t& get_f19(){
                                            return f19;
                                        }
                                    
                                        inline void set_f20(int64_t val){
                                            f20 = val;
                                        }
                                        inline int64_t& get_f20(){
                                            return f20;
                                        }
                                    
                                        inline void set_f21(int64_t val){
                                            f21 = val;
                                        }
                                        inline int64_t& get_f21(){
                                            return f21;
                                        }
                                    
                                        inline void set_f22(int64_t val){
                                            f22 = val;
                                        }
                                        inline int64_t& get_f22(){
                                            return f22;
                                        }
                                    
                                        inline void set_f23(int64_t val){
                                            f23 = val;
                                        }
                                        inline int64_t& get_f23(){
                                            return f23;
                                        }
                                    
                                        inline void set_f24(int64_t val){
                                            f24 = val;
                                        }
                                        inline int64_t& get_f24(){
                                            return f24;
                                        }
                                    
                                        inline void set_f25(int64_t val){
                                            f25 = val;
                                        }
                                        inline int64_t& get_f25(){
                                            return f25;
                                        }
                                    
                                        inline void set_f26(int64_t val){
                                            f26 = val;
                                        }
                                        inline int64_t& get_f26(){
                                            return f26;
                                        }
                                    
                                        inline void set_f27(int64_t val){
                                            f27 = val;
                                        }
                                        inline int64_t& get_f27(){
                                            return f27;
                                        }
                                    
                                        inline void set_f28(int64_t val){
                                            f28 = val;
                                        }
                                        inline int64_t& get_f28(){
                                            return f28;
                                        }
                                    
                                        inline void set_f29(int64_t val){
                                            f29 = val;
                                        }
                                        inline int64_t& get_f29(){
                                            return f29;
                                        }
                                    
                                        inline void set_f30(int64_t val){
                                            f30 = val;
                                        }
                                        inline int64_t& get_f30(){
                                            return f30;
                                        }
                                    
                                        inline void set_f31(int64_t val){
                                            f31 = val;
                                        }
                                        inline int64_t& get_f31(){
                                            return f31;
                                        }
                                    
                                        inline void set_f32(int64_t val){
                                            f32 = val;
                                        }
                                        inline int64_t& get_f32(){
                                            return f32;
                                        }
                                    
                                        inline M26* mutable_f33(){
                                            f33 = new M26();
                                            return f33;
                                        }
                                        inline M26*& get_f33(){
                                            return f33;
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
                                            fout << "M25->f12: " << f12 << std::endl;
                                            fout << "M25->f13: " << f13 << std::endl;
                                            fout << "M25->f14: " << f14 << std::endl;
                                            fout << "M25->f15: " << f15 << std::endl;
                                            fout << "M25->f16: " << f16 << std::endl;
                                            fout << "M25->f17: " << f17 << std::endl;
                                            fout << "M25->f18: " << f18 << std::endl;
                                            fout << "M25->f19: " << f19 << std::endl;
                                            fout << "M25->f20: " << f20 << std::endl;
                                            fout << "M25->f21: " << f21 << std::endl;
                                            fout << "M25->f22: " << f22 << std::endl;
                                            fout << "M25->f23: " << f23 << std::endl;
                                            fout << "M25->f24: " << f24 << std::endl;
                                            fout << "M25->f25: " << f25 << std::endl;
                                            fout << "M25->f26: " << f26 << std::endl;
                                            fout << "M25->f27: " << f27 << std::endl;
                                            fout << "M25->f28: " << f28 << std::endl;
                                            fout << "M25->f29: " << f29 << std::endl;
                                            fout << "M25->f30: " << f30 << std::endl;
                                            fout << "M25->f31: " << f31 << std::endl;
                                            fout << "M25->f32: " << f32 << std::endl;
                                            if(f33 != nullptr)
                                                f33->print_message(fout);
                                        }
                                    
                                        ~M25(){
                                            if(f33 != nullptr)
                                                delete f33;
                                        }
                                    
                                        M25(){
                                           f33 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) int64_t f1;
                                        alignas(8) int64_t f2;
                                        alignas(8) int64_t f3;
                                        alignas(8) int64_t f4;
                                        alignas(8) int64_t f5;
                                        alignas(8) int64_t f6;
                                        alignas(8) int64_t f7;
                                        alignas(8) int64_t f8;
                                        alignas(8) int64_t f9;
                                        alignas(8) int64_t f10;
                                        alignas(8) int64_t f11;
                                        alignas(8) int64_t f12;
                                        alignas(8) int64_t f13;
                                        alignas(8) int64_t f14;
                                        alignas(8) int64_t f15;
                                        alignas(8) int64_t f16;
                                        alignas(8) int64_t f17;
                                        alignas(8) int64_t f18;
                                        alignas(8) int64_t f19;
                                        alignas(8) int64_t f20;
                                        alignas(8) int64_t f21;
                                        alignas(8) int64_t f22;
                                        alignas(8) int64_t f23;
                                        alignas(8) int64_t f24;
                                        alignas(8) int64_t f25;
                                        alignas(8) int64_t f26;
                                        alignas(8) int64_t f27;
                                        alignas(8) int64_t f28;
                                        alignas(8) int64_t f29;
                                        alignas(8) int64_t f30;
                                        alignas(8) int64_t f31;
                                        alignas(8) int64_t f32;
                                        alignas(8) M26* f33;
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
                                
                                    inline void set_f11(int64_t val){
                                        f11 = val;
                                    }
                                    inline int64_t& get_f11(){
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
                                
                                    inline void set_f14(int64_t val){
                                        f14 = val;
                                    }
                                    inline int64_t& get_f14(){
                                        return f14;
                                    }
                                
                                    inline void set_f15(int64_t val){
                                        f15 = val;
                                    }
                                    inline int64_t& get_f15(){
                                        return f15;
                                    }
                                
                                    inline void set_f16(int64_t val){
                                        f16 = val;
                                    }
                                    inline int64_t& get_f16(){
                                        return f16;
                                    }
                                
                                    inline void set_f17(int64_t val){
                                        f17 = val;
                                    }
                                    inline int64_t& get_f17(){
                                        return f17;
                                    }
                                
                                    inline void set_f18(int64_t val){
                                        f18 = val;
                                    }
                                    inline int64_t& get_f18(){
                                        return f18;
                                    }
                                
                                    inline void set_f19(int64_t val){
                                        f19 = val;
                                    }
                                    inline int64_t& get_f19(){
                                        return f19;
                                    }
                                
                                    inline void set_f20(int64_t val){
                                        f20 = val;
                                    }
                                    inline int64_t& get_f20(){
                                        return f20;
                                    }
                                
                                    inline void set_f21(int64_t val){
                                        f21 = val;
                                    }
                                    inline int64_t& get_f21(){
                                        return f21;
                                    }
                                
                                    inline void set_f22(int64_t val){
                                        f22 = val;
                                    }
                                    inline int64_t& get_f22(){
                                        return f22;
                                    }
                                
                                    inline void set_f23(int64_t val){
                                        f23 = val;
                                    }
                                    inline int64_t& get_f23(){
                                        return f23;
                                    }
                                
                                    inline void set_f24(int64_t val){
                                        f24 = val;
                                    }
                                    inline int64_t& get_f24(){
                                        return f24;
                                    }
                                
                                    inline void set_f25(int64_t val){
                                        f25 = val;
                                    }
                                    inline int64_t& get_f25(){
                                        return f25;
                                    }
                                
                                    inline void set_f26(int64_t val){
                                        f26 = val;
                                    }
                                    inline int64_t& get_f26(){
                                        return f26;
                                    }
                                
                                    inline void set_f27(int64_t val){
                                        f27 = val;
                                    }
                                    inline int64_t& get_f27(){
                                        return f27;
                                    }
                                
                                    inline void set_f28(int64_t val){
                                        f28 = val;
                                    }
                                    inline int64_t& get_f28(){
                                        return f28;
                                    }
                                
                                    inline void set_f29(int64_t val){
                                        f29 = val;
                                    }
                                    inline int64_t& get_f29(){
                                        return f29;
                                    }
                                
                                    inline void set_f30(int64_t val){
                                        f30 = val;
                                    }
                                    inline int64_t& get_f30(){
                                        return f30;
                                    }
                                
                                    inline void set_f31(int64_t val){
                                        f31 = val;
                                    }
                                    inline int64_t& get_f31(){
                                        return f31;
                                    }
                                
                                    inline void set_f32(int64_t val){
                                        f32 = val;
                                    }
                                    inline int64_t& get_f32(){
                                        return f32;
                                    }
                                
                                    inline M25* mutable_f33(){
                                        f33 = new M25();
                                        return f33;
                                    }
                                    inline M25*& get_f33(){
                                        return f33;
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
                                        fout << "M24->f13: " << f13 << std::endl;
                                        fout << "M24->f14: " << f14 << std::endl;
                                        fout << "M24->f15: " << f15 << std::endl;
                                        fout << "M24->f16: " << f16 << std::endl;
                                        fout << "M24->f17: " << f17 << std::endl;
                                        fout << "M24->f18: " << f18 << std::endl;
                                        fout << "M24->f19: " << f19 << std::endl;
                                        fout << "M24->f20: " << f20 << std::endl;
                                        fout << "M24->f21: " << f21 << std::endl;
                                        fout << "M24->f22: " << f22 << std::endl;
                                        fout << "M24->f23: " << f23 << std::endl;
                                        fout << "M24->f24: " << f24 << std::endl;
                                        fout << "M24->f25: " << f25 << std::endl;
                                        fout << "M24->f26: " << f26 << std::endl;
                                        fout << "M24->f27: " << f27 << std::endl;
                                        fout << "M24->f28: " << f28 << std::endl;
                                        fout << "M24->f29: " << f29 << std::endl;
                                        fout << "M24->f30: " << f30 << std::endl;
                                        fout << "M24->f31: " << f31 << std::endl;
                                        fout << "M24->f32: " << f32 << std::endl;
                                        if(f33 != nullptr)
                                            f33->print_message(fout);
                                    }
                                
                                    ~M24(){
                                        if(f33 != nullptr)
                                            delete f33;
                                    }
                                
                                    M24(){
                                       f33 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) int64_t f1;
                                    alignas(8) int64_t f2;
                                    alignas(8) int64_t f3;
                                    alignas(8) int64_t f4;
                                    alignas(8) int64_t f5;
                                    alignas(8) int64_t f6;
                                    alignas(8) int64_t f7;
                                    alignas(8) int64_t f8;
                                    alignas(8) int64_t f9;
                                    alignas(8) int64_t f10;
                                    alignas(8) int64_t f11;
                                    alignas(8) int64_t f12;
                                    alignas(8) int64_t f13;
                                    alignas(8) int64_t f14;
                                    alignas(8) int64_t f15;
                                    alignas(8) int64_t f16;
                                    alignas(8) int64_t f17;
                                    alignas(8) int64_t f18;
                                    alignas(8) int64_t f19;
                                    alignas(8) int64_t f20;
                                    alignas(8) int64_t f21;
                                    alignas(8) int64_t f22;
                                    alignas(8) int64_t f23;
                                    alignas(8) int64_t f24;
                                    alignas(8) int64_t f25;
                                    alignas(8) int64_t f26;
                                    alignas(8) int64_t f27;
                                    alignas(8) int64_t f28;
                                    alignas(8) int64_t f29;
                                    alignas(8) int64_t f30;
                                    alignas(8) int64_t f31;
                                    alignas(8) int64_t f32;
                                    alignas(8) M25* f33;
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
                            
                                inline void set_f11(int64_t val){
                                    f11 = val;
                                }
                                inline int64_t& get_f11(){
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
                            
                                inline void set_f14(int64_t val){
                                    f14 = val;
                                }
                                inline int64_t& get_f14(){
                                    return f14;
                                }
                            
                                inline void set_f15(int64_t val){
                                    f15 = val;
                                }
                                inline int64_t& get_f15(){
                                    return f15;
                                }
                            
                                inline void set_f16(int64_t val){
                                    f16 = val;
                                }
                                inline int64_t& get_f16(){
                                    return f16;
                                }
                            
                                inline void set_f17(int64_t val){
                                    f17 = val;
                                }
                                inline int64_t& get_f17(){
                                    return f17;
                                }
                            
                                inline void set_f18(int64_t val){
                                    f18 = val;
                                }
                                inline int64_t& get_f18(){
                                    return f18;
                                }
                            
                                inline void set_f19(int64_t val){
                                    f19 = val;
                                }
                                inline int64_t& get_f19(){
                                    return f19;
                                }
                            
                                inline void set_f20(int64_t val){
                                    f20 = val;
                                }
                                inline int64_t& get_f20(){
                                    return f20;
                                }
                            
                                inline void set_f21(int64_t val){
                                    f21 = val;
                                }
                                inline int64_t& get_f21(){
                                    return f21;
                                }
                            
                                inline void set_f22(int64_t val){
                                    f22 = val;
                                }
                                inline int64_t& get_f22(){
                                    return f22;
                                }
                            
                                inline void set_f23(int64_t val){
                                    f23 = val;
                                }
                                inline int64_t& get_f23(){
                                    return f23;
                                }
                            
                                inline void set_f24(int64_t val){
                                    f24 = val;
                                }
                                inline int64_t& get_f24(){
                                    return f24;
                                }
                            
                                inline void set_f25(int64_t val){
                                    f25 = val;
                                }
                                inline int64_t& get_f25(){
                                    return f25;
                                }
                            
                                inline void set_f26(int64_t val){
                                    f26 = val;
                                }
                                inline int64_t& get_f26(){
                                    return f26;
                                }
                            
                                inline void set_f27(int64_t val){
                                    f27 = val;
                                }
                                inline int64_t& get_f27(){
                                    return f27;
                                }
                            
                                inline void set_f28(int64_t val){
                                    f28 = val;
                                }
                                inline int64_t& get_f28(){
                                    return f28;
                                }
                            
                                inline void set_f29(int64_t val){
                                    f29 = val;
                                }
                                inline int64_t& get_f29(){
                                    return f29;
                                }
                            
                                inline void set_f30(int64_t val){
                                    f30 = val;
                                }
                                inline int64_t& get_f30(){
                                    return f30;
                                }
                            
                                inline void set_f31(int64_t val){
                                    f31 = val;
                                }
                                inline int64_t& get_f31(){
                                    return f31;
                                }
                            
                                inline void set_f32(int64_t val){
                                    f32 = val;
                                }
                                inline int64_t& get_f32(){
                                    return f32;
                                }
                            
                                inline M24* mutable_f33(){
                                    f33 = new M24();
                                    return f33;
                                }
                                inline M24*& get_f33(){
                                    return f33;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M23->f1: " << f1 << std::endl;
                                    fout << "M23->f2: " << f2 << std::endl;
                                    fout << "M23->f3: " << f3 << std::endl;
                                    fout << "M23->f4: " << f4 << std::endl;
                                    fout << "M23->f5: " << f5 << std::endl;
                                    fout << "M23->f6: " << f6 << std::endl;
                                    fout << "M23->f7: " << f7 << std::endl;
                                    fout << "M23->f8: " << f8 << std::endl;
                                    fout << "M23->f9: " << f9 << std::endl;
                                    fout << "M23->f10: " << f10 << std::endl;
                                    fout << "M23->f11: " << f11 << std::endl;
                                    fout << "M23->f12: " << f12 << std::endl;
                                    fout << "M23->f13: " << f13 << std::endl;
                                    fout << "M23->f14: " << f14 << std::endl;
                                    fout << "M23->f15: " << f15 << std::endl;
                                    fout << "M23->f16: " << f16 << std::endl;
                                    fout << "M23->f17: " << f17 << std::endl;
                                    fout << "M23->f18: " << f18 << std::endl;
                                    fout << "M23->f19: " << f19 << std::endl;
                                    fout << "M23->f20: " << f20 << std::endl;
                                    fout << "M23->f21: " << f21 << std::endl;
                                    fout << "M23->f22: " << f22 << std::endl;
                                    fout << "M23->f23: " << f23 << std::endl;
                                    fout << "M23->f24: " << f24 << std::endl;
                                    fout << "M23->f25: " << f25 << std::endl;
                                    fout << "M23->f26: " << f26 << std::endl;
                                    fout << "M23->f27: " << f27 << std::endl;
                                    fout << "M23->f28: " << f28 << std::endl;
                                    fout << "M23->f29: " << f29 << std::endl;
                                    fout << "M23->f30: " << f30 << std::endl;
                                    fout << "M23->f31: " << f31 << std::endl;
                                    fout << "M23->f32: " << f32 << std::endl;
                                    if(f33 != nullptr)
                                        f33->print_message(fout);
                                }
                            
                                ~M23(){
                                    if(f33 != nullptr)
                                        delete f33;
                                }
                            
                                M23(){
                                   f33 = nullptr;
                                }
                            
                            private:
                                alignas(8) int64_t f1;
                                alignas(8) int64_t f2;
                                alignas(8) int64_t f3;
                                alignas(8) int64_t f4;
                                alignas(8) int64_t f5;
                                alignas(8) int64_t f6;
                                alignas(8) int64_t f7;
                                alignas(8) int64_t f8;
                                alignas(8) int64_t f9;
                                alignas(8) int64_t f10;
                                alignas(8) int64_t f11;
                                alignas(8) int64_t f12;
                                alignas(8) int64_t f13;
                                alignas(8) int64_t f14;
                                alignas(8) int64_t f15;
                                alignas(8) int64_t f16;
                                alignas(8) int64_t f17;
                                alignas(8) int64_t f18;
                                alignas(8) int64_t f19;
                                alignas(8) int64_t f20;
                                alignas(8) int64_t f21;
                                alignas(8) int64_t f22;
                                alignas(8) int64_t f23;
                                alignas(8) int64_t f24;
                                alignas(8) int64_t f25;
                                alignas(8) int64_t f26;
                                alignas(8) int64_t f27;
                                alignas(8) int64_t f28;
                                alignas(8) int64_t f29;
                                alignas(8) int64_t f30;
                                alignas(8) int64_t f31;
                                alignas(8) int64_t f32;
                                alignas(8) M24* f33;
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
                        
                            inline void set_f11(int64_t val){
                                f11 = val;
                            }
                            inline int64_t& get_f11(){
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
                        
                            inline void set_f14(int64_t val){
                                f14 = val;
                            }
                            inline int64_t& get_f14(){
                                return f14;
                            }
                        
                            inline void set_f15(int64_t val){
                                f15 = val;
                            }
                            inline int64_t& get_f15(){
                                return f15;
                            }
                        
                            inline void set_f16(int64_t val){
                                f16 = val;
                            }
                            inline int64_t& get_f16(){
                                return f16;
                            }
                        
                            inline void set_f17(int64_t val){
                                f17 = val;
                            }
                            inline int64_t& get_f17(){
                                return f17;
                            }
                        
                            inline void set_f18(int64_t val){
                                f18 = val;
                            }
                            inline int64_t& get_f18(){
                                return f18;
                            }
                        
                            inline void set_f19(int64_t val){
                                f19 = val;
                            }
                            inline int64_t& get_f19(){
                                return f19;
                            }
                        
                            inline void set_f20(int64_t val){
                                f20 = val;
                            }
                            inline int64_t& get_f20(){
                                return f20;
                            }
                        
                            inline void set_f21(int64_t val){
                                f21 = val;
                            }
                            inline int64_t& get_f21(){
                                return f21;
                            }
                        
                            inline void set_f22(int64_t val){
                                f22 = val;
                            }
                            inline int64_t& get_f22(){
                                return f22;
                            }
                        
                            inline void set_f23(int64_t val){
                                f23 = val;
                            }
                            inline int64_t& get_f23(){
                                return f23;
                            }
                        
                            inline void set_f24(int64_t val){
                                f24 = val;
                            }
                            inline int64_t& get_f24(){
                                return f24;
                            }
                        
                            inline void set_f25(int64_t val){
                                f25 = val;
                            }
                            inline int64_t& get_f25(){
                                return f25;
                            }
                        
                            inline void set_f26(int64_t val){
                                f26 = val;
                            }
                            inline int64_t& get_f26(){
                                return f26;
                            }
                        
                            inline void set_f27(int64_t val){
                                f27 = val;
                            }
                            inline int64_t& get_f27(){
                                return f27;
                            }
                        
                            inline void set_f28(int64_t val){
                                f28 = val;
                            }
                            inline int64_t& get_f28(){
                                return f28;
                            }
                        
                            inline void set_f29(int64_t val){
                                f29 = val;
                            }
                            inline int64_t& get_f29(){
                                return f29;
                            }
                        
                            inline void set_f30(int64_t val){
                                f30 = val;
                            }
                            inline int64_t& get_f30(){
                                return f30;
                            }
                        
                            inline void set_f31(int64_t val){
                                f31 = val;
                            }
                            inline int64_t& get_f31(){
                                return f31;
                            }
                        
                            inline void set_f32(int64_t val){
                                f32 = val;
                            }
                            inline int64_t& get_f32(){
                                return f32;
                            }
                        
                            inline M23* mutable_f33(){
                                f33 = new M23();
                                return f33;
                            }
                            inline M23*& get_f33(){
                                return f33;
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
                                fout << "M22->f9: " << f9 << std::endl;
                                fout << "M22->f10: " << f10 << std::endl;
                                fout << "M22->f11: " << f11 << std::endl;
                                fout << "M22->f12: " << f12 << std::endl;
                                fout << "M22->f13: " << f13 << std::endl;
                                fout << "M22->f14: " << f14 << std::endl;
                                fout << "M22->f15: " << f15 << std::endl;
                                fout << "M22->f16: " << f16 << std::endl;
                                fout << "M22->f17: " << f17 << std::endl;
                                fout << "M22->f18: " << f18 << std::endl;
                                fout << "M22->f19: " << f19 << std::endl;
                                fout << "M22->f20: " << f20 << std::endl;
                                fout << "M22->f21: " << f21 << std::endl;
                                fout << "M22->f22: " << f22 << std::endl;
                                fout << "M22->f23: " << f23 << std::endl;
                                fout << "M22->f24: " << f24 << std::endl;
                                fout << "M22->f25: " << f25 << std::endl;
                                fout << "M22->f26: " << f26 << std::endl;
                                fout << "M22->f27: " << f27 << std::endl;
                                fout << "M22->f28: " << f28 << std::endl;
                                fout << "M22->f29: " << f29 << std::endl;
                                fout << "M22->f30: " << f30 << std::endl;
                                fout << "M22->f31: " << f31 << std::endl;
                                fout << "M22->f32: " << f32 << std::endl;
                                if(f33 != nullptr)
                                    f33->print_message(fout);
                            }
                        
                            ~M22(){
                                if(f33 != nullptr)
                                    delete f33;
                            }
                        
                            M22(){
                               f33 = nullptr;
                            }
                        
                        private:
                            alignas(8) int64_t f1;
                            alignas(8) int64_t f2;
                            alignas(8) int64_t f3;
                            alignas(8) int64_t f4;
                            alignas(8) int64_t f5;
                            alignas(8) int64_t f6;
                            alignas(8) int64_t f7;
                            alignas(8) int64_t f8;
                            alignas(8) int64_t f9;
                            alignas(8) int64_t f10;
                            alignas(8) int64_t f11;
                            alignas(8) int64_t f12;
                            alignas(8) int64_t f13;
                            alignas(8) int64_t f14;
                            alignas(8) int64_t f15;
                            alignas(8) int64_t f16;
                            alignas(8) int64_t f17;
                            alignas(8) int64_t f18;
                            alignas(8) int64_t f19;
                            alignas(8) int64_t f20;
                            alignas(8) int64_t f21;
                            alignas(8) int64_t f22;
                            alignas(8) int64_t f23;
                            alignas(8) int64_t f24;
                            alignas(8) int64_t f25;
                            alignas(8) int64_t f26;
                            alignas(8) int64_t f27;
                            alignas(8) int64_t f28;
                            alignas(8) int64_t f29;
                            alignas(8) int64_t f30;
                            alignas(8) int64_t f31;
                            alignas(8) int64_t f32;
                            alignas(8) M23* f33;
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
                    
                        inline void set_f11(int64_t val){
                            f11 = val;
                        }
                        inline int64_t& get_f11(){
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
                    
                        inline void set_f14(int64_t val){
                            f14 = val;
                        }
                        inline int64_t& get_f14(){
                            return f14;
                        }
                    
                        inline void set_f15(int64_t val){
                            f15 = val;
                        }
                        inline int64_t& get_f15(){
                            return f15;
                        }
                    
                        inline void set_f16(int64_t val){
                            f16 = val;
                        }
                        inline int64_t& get_f16(){
                            return f16;
                        }
                    
                        inline void set_f17(int64_t val){
                            f17 = val;
                        }
                        inline int64_t& get_f17(){
                            return f17;
                        }
                    
                        inline void set_f18(int64_t val){
                            f18 = val;
                        }
                        inline int64_t& get_f18(){
                            return f18;
                        }
                    
                        inline void set_f19(int64_t val){
                            f19 = val;
                        }
                        inline int64_t& get_f19(){
                            return f19;
                        }
                    
                        inline void set_f20(int64_t val){
                            f20 = val;
                        }
                        inline int64_t& get_f20(){
                            return f20;
                        }
                    
                        inline void set_f21(int64_t val){
                            f21 = val;
                        }
                        inline int64_t& get_f21(){
                            return f21;
                        }
                    
                        inline void set_f22(int64_t val){
                            f22 = val;
                        }
                        inline int64_t& get_f22(){
                            return f22;
                        }
                    
                        inline void set_f23(int64_t val){
                            f23 = val;
                        }
                        inline int64_t& get_f23(){
                            return f23;
                        }
                    
                        inline void set_f24(int64_t val){
                            f24 = val;
                        }
                        inline int64_t& get_f24(){
                            return f24;
                        }
                    
                        inline void set_f25(int64_t val){
                            f25 = val;
                        }
                        inline int64_t& get_f25(){
                            return f25;
                        }
                    
                        inline void set_f26(int64_t val){
                            f26 = val;
                        }
                        inline int64_t& get_f26(){
                            return f26;
                        }
                    
                        inline void set_f27(int64_t val){
                            f27 = val;
                        }
                        inline int64_t& get_f27(){
                            return f27;
                        }
                    
                        inline void set_f28(int64_t val){
                            f28 = val;
                        }
                        inline int64_t& get_f28(){
                            return f28;
                        }
                    
                        inline void set_f29(int64_t val){
                            f29 = val;
                        }
                        inline int64_t& get_f29(){
                            return f29;
                        }
                    
                        inline void set_f30(int64_t val){
                            f30 = val;
                        }
                        inline int64_t& get_f30(){
                            return f30;
                        }
                    
                        inline void set_f31(int64_t val){
                            f31 = val;
                        }
                        inline int64_t& get_f31(){
                            return f31;
                        }
                    
                        inline void set_f32(int64_t val){
                            f32 = val;
                        }
                        inline int64_t& get_f32(){
                            return f32;
                        }
                    
                        inline M22* mutable_f33(){
                            f33 = new M22();
                            return f33;
                        }
                        inline M22*& get_f33(){
                            return f33;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M21->f1: " << f1 << std::endl;
                            fout << "M21->f2: " << f2 << std::endl;
                            fout << "M21->f3: " << f3 << std::endl;
                            fout << "M21->f4: " << f4 << std::endl;
                            fout << "M21->f5: " << f5 << std::endl;
                            fout << "M21->f6: " << f6 << std::endl;
                            fout << "M21->f7: " << f7 << std::endl;
                            fout << "M21->f8: " << f8 << std::endl;
                            fout << "M21->f9: " << f9 << std::endl;
                            fout << "M21->f10: " << f10 << std::endl;
                            fout << "M21->f11: " << f11 << std::endl;
                            fout << "M21->f12: " << f12 << std::endl;
                            fout << "M21->f13: " << f13 << std::endl;
                            fout << "M21->f14: " << f14 << std::endl;
                            fout << "M21->f15: " << f15 << std::endl;
                            fout << "M21->f16: " << f16 << std::endl;
                            fout << "M21->f17: " << f17 << std::endl;
                            fout << "M21->f18: " << f18 << std::endl;
                            fout << "M21->f19: " << f19 << std::endl;
                            fout << "M21->f20: " << f20 << std::endl;
                            fout << "M21->f21: " << f21 << std::endl;
                            fout << "M21->f22: " << f22 << std::endl;
                            fout << "M21->f23: " << f23 << std::endl;
                            fout << "M21->f24: " << f24 << std::endl;
                            fout << "M21->f25: " << f25 << std::endl;
                            fout << "M21->f26: " << f26 << std::endl;
                            fout << "M21->f27: " << f27 << std::endl;
                            fout << "M21->f28: " << f28 << std::endl;
                            fout << "M21->f29: " << f29 << std::endl;
                            fout << "M21->f30: " << f30 << std::endl;
                            fout << "M21->f31: " << f31 << std::endl;
                            fout << "M21->f32: " << f32 << std::endl;
                            if(f33 != nullptr)
                                f33->print_message(fout);
                        }
                    
                        ~M21(){
                            if(f33 != nullptr)
                                delete f33;
                        }
                    
                        M21(){
                           f33 = nullptr;
                        }
                    
                    private:
                        alignas(8) int64_t f1;
                        alignas(8) int64_t f2;
                        alignas(8) int64_t f3;
                        alignas(8) int64_t f4;
                        alignas(8) int64_t f5;
                        alignas(8) int64_t f6;
                        alignas(8) int64_t f7;
                        alignas(8) int64_t f8;
                        alignas(8) int64_t f9;
                        alignas(8) int64_t f10;
                        alignas(8) int64_t f11;
                        alignas(8) int64_t f12;
                        alignas(8) int64_t f13;
                        alignas(8) int64_t f14;
                        alignas(8) int64_t f15;
                        alignas(8) int64_t f16;
                        alignas(8) int64_t f17;
                        alignas(8) int64_t f18;
                        alignas(8) int64_t f19;
                        alignas(8) int64_t f20;
                        alignas(8) int64_t f21;
                        alignas(8) int64_t f22;
                        alignas(8) int64_t f23;
                        alignas(8) int64_t f24;
                        alignas(8) int64_t f25;
                        alignas(8) int64_t f26;
                        alignas(8) int64_t f27;
                        alignas(8) int64_t f28;
                        alignas(8) int64_t f29;
                        alignas(8) int64_t f30;
                        alignas(8) int64_t f31;
                        alignas(8) int64_t f32;
                        alignas(8) M22* f33;
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
                
                    inline void set_f11(int64_t val){
                        f11 = val;
                    }
                    inline int64_t& get_f11(){
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
                
                    inline void set_f14(int64_t val){
                        f14 = val;
                    }
                    inline int64_t& get_f14(){
                        return f14;
                    }
                
                    inline void set_f15(int64_t val){
                        f15 = val;
                    }
                    inline int64_t& get_f15(){
                        return f15;
                    }
                
                    inline void set_f16(int64_t val){
                        f16 = val;
                    }
                    inline int64_t& get_f16(){
                        return f16;
                    }
                
                    inline void set_f17(int64_t val){
                        f17 = val;
                    }
                    inline int64_t& get_f17(){
                        return f17;
                    }
                
                    inline void set_f18(int64_t val){
                        f18 = val;
                    }
                    inline int64_t& get_f18(){
                        return f18;
                    }
                
                    inline void set_f19(int64_t val){
                        f19 = val;
                    }
                    inline int64_t& get_f19(){
                        return f19;
                    }
                
                    inline void set_f20(int64_t val){
                        f20 = val;
                    }
                    inline int64_t& get_f20(){
                        return f20;
                    }
                
                    inline void set_f21(int64_t val){
                        f21 = val;
                    }
                    inline int64_t& get_f21(){
                        return f21;
                    }
                
                    inline void set_f22(int64_t val){
                        f22 = val;
                    }
                    inline int64_t& get_f22(){
                        return f22;
                    }
                
                    inline void set_f23(int64_t val){
                        f23 = val;
                    }
                    inline int64_t& get_f23(){
                        return f23;
                    }
                
                    inline void set_f24(int64_t val){
                        f24 = val;
                    }
                    inline int64_t& get_f24(){
                        return f24;
                    }
                
                    inline void set_f25(int64_t val){
                        f25 = val;
                    }
                    inline int64_t& get_f25(){
                        return f25;
                    }
                
                    inline void set_f26(int64_t val){
                        f26 = val;
                    }
                    inline int64_t& get_f26(){
                        return f26;
                    }
                
                    inline void set_f27(int64_t val){
                        f27 = val;
                    }
                    inline int64_t& get_f27(){
                        return f27;
                    }
                
                    inline void set_f28(int64_t val){
                        f28 = val;
                    }
                    inline int64_t& get_f28(){
                        return f28;
                    }
                
                    inline void set_f29(int64_t val){
                        f29 = val;
                    }
                    inline int64_t& get_f29(){
                        return f29;
                    }
                
                    inline void set_f30(int64_t val){
                        f30 = val;
                    }
                    inline int64_t& get_f30(){
                        return f30;
                    }
                
                    inline void set_f31(int64_t val){
                        f31 = val;
                    }
                    inline int64_t& get_f31(){
                        return f31;
                    }
                
                    inline void set_f32(int64_t val){
                        f32 = val;
                    }
                    inline int64_t& get_f32(){
                        return f32;
                    }
                
                    inline M21* mutable_f33(){
                        f33 = new M21();
                        return f33;
                    }
                    inline M21*& get_f33(){
                        return f33;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M20->f1: " << f1 << std::endl;
                        fout << "M20->f2: " << f2 << std::endl;
                        fout << "M20->f3: " << f3 << std::endl;
                        fout << "M20->f4: " << f4 << std::endl;
                        fout << "M20->f5: " << f5 << std::endl;
                        fout << "M20->f6: " << f6 << std::endl;
                        fout << "M20->f7: " << f7 << std::endl;
                        fout << "M20->f8: " << f8 << std::endl;
                        fout << "M20->f9: " << f9 << std::endl;
                        fout << "M20->f10: " << f10 << std::endl;
                        fout << "M20->f11: " << f11 << std::endl;
                        fout << "M20->f12: " << f12 << std::endl;
                        fout << "M20->f13: " << f13 << std::endl;
                        fout << "M20->f14: " << f14 << std::endl;
                        fout << "M20->f15: " << f15 << std::endl;
                        fout << "M20->f16: " << f16 << std::endl;
                        fout << "M20->f17: " << f17 << std::endl;
                        fout << "M20->f18: " << f18 << std::endl;
                        fout << "M20->f19: " << f19 << std::endl;
                        fout << "M20->f20: " << f20 << std::endl;
                        fout << "M20->f21: " << f21 << std::endl;
                        fout << "M20->f22: " << f22 << std::endl;
                        fout << "M20->f23: " << f23 << std::endl;
                        fout << "M20->f24: " << f24 << std::endl;
                        fout << "M20->f25: " << f25 << std::endl;
                        fout << "M20->f26: " << f26 << std::endl;
                        fout << "M20->f27: " << f27 << std::endl;
                        fout << "M20->f28: " << f28 << std::endl;
                        fout << "M20->f29: " << f29 << std::endl;
                        fout << "M20->f30: " << f30 << std::endl;
                        fout << "M20->f31: " << f31 << std::endl;
                        fout << "M20->f32: " << f32 << std::endl;
                        if(f33 != nullptr)
                            f33->print_message(fout);
                    }
                
                    ~M20(){
                        if(f33 != nullptr)
                            delete f33;
                    }
                
                    M20(){
                       f33 = nullptr;
                    }
                
                private:
                    alignas(8) int64_t f1;
                    alignas(8) int64_t f2;
                    alignas(8) int64_t f3;
                    alignas(8) int64_t f4;
                    alignas(8) int64_t f5;
                    alignas(8) int64_t f6;
                    alignas(8) int64_t f7;
                    alignas(8) int64_t f8;
                    alignas(8) int64_t f9;
                    alignas(8) int64_t f10;
                    alignas(8) int64_t f11;
                    alignas(8) int64_t f12;
                    alignas(8) int64_t f13;
                    alignas(8) int64_t f14;
                    alignas(8) int64_t f15;
                    alignas(8) int64_t f16;
                    alignas(8) int64_t f17;
                    alignas(8) int64_t f18;
                    alignas(8) int64_t f19;
                    alignas(8) int64_t f20;
                    alignas(8) int64_t f21;
                    alignas(8) int64_t f22;
                    alignas(8) int64_t f23;
                    alignas(8) int64_t f24;
                    alignas(8) int64_t f25;
                    alignas(8) int64_t f26;
                    alignas(8) int64_t f27;
                    alignas(8) int64_t f28;
                    alignas(8) int64_t f29;
                    alignas(8) int64_t f30;
                    alignas(8) int64_t f31;
                    alignas(8) int64_t f32;
                    alignas(8) M21* f33;
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
            
                inline void set_f11(int64_t val){
                    f11 = val;
                }
                inline int64_t& get_f11(){
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
            
                inline void set_f14(int64_t val){
                    f14 = val;
                }
                inline int64_t& get_f14(){
                    return f14;
                }
            
                inline void set_f15(int64_t val){
                    f15 = val;
                }
                inline int64_t& get_f15(){
                    return f15;
                }
            
                inline void set_f16(int64_t val){
                    f16 = val;
                }
                inline int64_t& get_f16(){
                    return f16;
                }
            
                inline void set_f17(int64_t val){
                    f17 = val;
                }
                inline int64_t& get_f17(){
                    return f17;
                }
            
                inline void set_f18(int64_t val){
                    f18 = val;
                }
                inline int64_t& get_f18(){
                    return f18;
                }
            
                inline void set_f19(int64_t val){
                    f19 = val;
                }
                inline int64_t& get_f19(){
                    return f19;
                }
            
                inline void set_f20(int64_t val){
                    f20 = val;
                }
                inline int64_t& get_f20(){
                    return f20;
                }
            
                inline void set_f21(int64_t val){
                    f21 = val;
                }
                inline int64_t& get_f21(){
                    return f21;
                }
            
                inline void set_f22(int64_t val){
                    f22 = val;
                }
                inline int64_t& get_f22(){
                    return f22;
                }
            
                inline void set_f23(int64_t val){
                    f23 = val;
                }
                inline int64_t& get_f23(){
                    return f23;
                }
            
                inline void set_f24(int64_t val){
                    f24 = val;
                }
                inline int64_t& get_f24(){
                    return f24;
                }
            
                inline void set_f25(int64_t val){
                    f25 = val;
                }
                inline int64_t& get_f25(){
                    return f25;
                }
            
                inline void set_f26(int64_t val){
                    f26 = val;
                }
                inline int64_t& get_f26(){
                    return f26;
                }
            
                inline void set_f27(int64_t val){
                    f27 = val;
                }
                inline int64_t& get_f27(){
                    return f27;
                }
            
                inline void set_f28(int64_t val){
                    f28 = val;
                }
                inline int64_t& get_f28(){
                    return f28;
                }
            
                inline void set_f29(int64_t val){
                    f29 = val;
                }
                inline int64_t& get_f29(){
                    return f29;
                }
            
                inline void set_f30(int64_t val){
                    f30 = val;
                }
                inline int64_t& get_f30(){
                    return f30;
                }
            
                inline void set_f31(int64_t val){
                    f31 = val;
                }
                inline int64_t& get_f31(){
                    return f31;
                }
            
                inline void set_f32(int64_t val){
                    f32 = val;
                }
                inline int64_t& get_f32(){
                    return f32;
                }
            
                inline M20* mutable_f33(){
                    f33 = new M20();
                    return f33;
                }
                inline M20*& get_f33(){
                    return f33;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M19->f1: " << f1 << std::endl;
                    fout << "M19->f2: " << f2 << std::endl;
                    fout << "M19->f3: " << f3 << std::endl;
                    fout << "M19->f4: " << f4 << std::endl;
                    fout << "M19->f5: " << f5 << std::endl;
                    fout << "M19->f6: " << f6 << std::endl;
                    fout << "M19->f7: " << f7 << std::endl;
                    fout << "M19->f8: " << f8 << std::endl;
                    fout << "M19->f9: " << f9 << std::endl;
                    fout << "M19->f10: " << f10 << std::endl;
                    fout << "M19->f11: " << f11 << std::endl;
                    fout << "M19->f12: " << f12 << std::endl;
                    fout << "M19->f13: " << f13 << std::endl;
                    fout << "M19->f14: " << f14 << std::endl;
                    fout << "M19->f15: " << f15 << std::endl;
                    fout << "M19->f16: " << f16 << std::endl;
                    fout << "M19->f17: " << f17 << std::endl;
                    fout << "M19->f18: " << f18 << std::endl;
                    fout << "M19->f19: " << f19 << std::endl;
                    fout << "M19->f20: " << f20 << std::endl;
                    fout << "M19->f21: " << f21 << std::endl;
                    fout << "M19->f22: " << f22 << std::endl;
                    fout << "M19->f23: " << f23 << std::endl;
                    fout << "M19->f24: " << f24 << std::endl;
                    fout << "M19->f25: " << f25 << std::endl;
                    fout << "M19->f26: " << f26 << std::endl;
                    fout << "M19->f27: " << f27 << std::endl;
                    fout << "M19->f28: " << f28 << std::endl;
                    fout << "M19->f29: " << f29 << std::endl;
                    fout << "M19->f30: " << f30 << std::endl;
                    fout << "M19->f31: " << f31 << std::endl;
                    fout << "M19->f32: " << f32 << std::endl;
                    if(f33 != nullptr)
                        f33->print_message(fout);
                }
            
                ~M19(){
                    if(f33 != nullptr)
                        delete f33;
                }
            
                M19(){
                   f33 = nullptr;
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) int64_t f2;
                alignas(8) int64_t f3;
                alignas(8) int64_t f4;
                alignas(8) int64_t f5;
                alignas(8) int64_t f6;
                alignas(8) int64_t f7;
                alignas(8) int64_t f8;
                alignas(8) int64_t f9;
                alignas(8) int64_t f10;
                alignas(8) int64_t f11;
                alignas(8) int64_t f12;
                alignas(8) int64_t f13;
                alignas(8) int64_t f14;
                alignas(8) int64_t f15;
                alignas(8) int64_t f16;
                alignas(8) int64_t f17;
                alignas(8) int64_t f18;
                alignas(8) int64_t f19;
                alignas(8) int64_t f20;
                alignas(8) int64_t f21;
                alignas(8) int64_t f22;
                alignas(8) int64_t f23;
                alignas(8) int64_t f24;
                alignas(8) int64_t f25;
                alignas(8) int64_t f26;
                alignas(8) int64_t f27;
                alignas(8) int64_t f28;
                alignas(8) int64_t f29;
                alignas(8) int64_t f30;
                alignas(8) int64_t f31;
                alignas(8) int64_t f32;
                alignas(8) M20* f33;
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
        
            inline void set_f11(int64_t val){
                f11 = val;
            }
            inline int64_t& get_f11(){
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
        
            inline void set_f14(int64_t val){
                f14 = val;
            }
            inline int64_t& get_f14(){
                return f14;
            }
        
            inline void set_f15(int64_t val){
                f15 = val;
            }
            inline int64_t& get_f15(){
                return f15;
            }
        
            inline void set_f16(int64_t val){
                f16 = val;
            }
            inline int64_t& get_f16(){
                return f16;
            }
        
            inline void set_f17(int64_t val){
                f17 = val;
            }
            inline int64_t& get_f17(){
                return f17;
            }
        
            inline void set_f18(int64_t val){
                f18 = val;
            }
            inline int64_t& get_f18(){
                return f18;
            }
        
            inline void set_f19(int64_t val){
                f19 = val;
            }
            inline int64_t& get_f19(){
                return f19;
            }
        
            inline void set_f20(int64_t val){
                f20 = val;
            }
            inline int64_t& get_f20(){
                return f20;
            }
        
            inline void set_f21(int64_t val){
                f21 = val;
            }
            inline int64_t& get_f21(){
                return f21;
            }
        
            inline void set_f22(int64_t val){
                f22 = val;
            }
            inline int64_t& get_f22(){
                return f22;
            }
        
            inline void set_f23(int64_t val){
                f23 = val;
            }
            inline int64_t& get_f23(){
                return f23;
            }
        
            inline void set_f24(int64_t val){
                f24 = val;
            }
            inline int64_t& get_f24(){
                return f24;
            }
        
            inline void set_f25(int64_t val){
                f25 = val;
            }
            inline int64_t& get_f25(){
                return f25;
            }
        
            inline void set_f26(int64_t val){
                f26 = val;
            }
            inline int64_t& get_f26(){
                return f26;
            }
        
            inline void set_f27(int64_t val){
                f27 = val;
            }
            inline int64_t& get_f27(){
                return f27;
            }
        
            inline void set_f28(int64_t val){
                f28 = val;
            }
            inline int64_t& get_f28(){
                return f28;
            }
        
            inline void set_f29(int64_t val){
                f29 = val;
            }
            inline int64_t& get_f29(){
                return f29;
            }
        
            inline void set_f30(int64_t val){
                f30 = val;
            }
            inline int64_t& get_f30(){
                return f30;
            }
        
            inline void set_f31(int64_t val){
                f31 = val;
            }
            inline int64_t& get_f31(){
                return f31;
            }
        
            inline void set_f32(int64_t val){
                f32 = val;
            }
            inline int64_t& get_f32(){
                return f32;
            }
        
            inline M19* mutable_f33(){
                f33 = new M19();
                return f33;
            }
            inline M19*& get_f33(){
                return f33;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M18->f1: " << f1 << std::endl;
                fout << "M18->f2: " << f2 << std::endl;
                fout << "M18->f3: " << f3 << std::endl;
                fout << "M18->f4: " << f4 << std::endl;
                fout << "M18->f5: " << f5 << std::endl;
                fout << "M18->f6: " << f6 << std::endl;
                fout << "M18->f7: " << f7 << std::endl;
                fout << "M18->f8: " << f8 << std::endl;
                fout << "M18->f9: " << f9 << std::endl;
                fout << "M18->f10: " << f10 << std::endl;
                fout << "M18->f11: " << f11 << std::endl;
                fout << "M18->f12: " << f12 << std::endl;
                fout << "M18->f13: " << f13 << std::endl;
                fout << "M18->f14: " << f14 << std::endl;
                fout << "M18->f15: " << f15 << std::endl;
                fout << "M18->f16: " << f16 << std::endl;
                fout << "M18->f17: " << f17 << std::endl;
                fout << "M18->f18: " << f18 << std::endl;
                fout << "M18->f19: " << f19 << std::endl;
                fout << "M18->f20: " << f20 << std::endl;
                fout << "M18->f21: " << f21 << std::endl;
                fout << "M18->f22: " << f22 << std::endl;
                fout << "M18->f23: " << f23 << std::endl;
                fout << "M18->f24: " << f24 << std::endl;
                fout << "M18->f25: " << f25 << std::endl;
                fout << "M18->f26: " << f26 << std::endl;
                fout << "M18->f27: " << f27 << std::endl;
                fout << "M18->f28: " << f28 << std::endl;
                fout << "M18->f29: " << f29 << std::endl;
                fout << "M18->f30: " << f30 << std::endl;
                fout << "M18->f31: " << f31 << std::endl;
                fout << "M18->f32: " << f32 << std::endl;
                if(f33 != nullptr)
                    f33->print_message(fout);
            }
        
            ~M18(){
                if(f33 != nullptr)
                    delete f33;
            }
        
            M18(){
               f33 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int64_t f2;
            alignas(8) int64_t f3;
            alignas(8) int64_t f4;
            alignas(8) int64_t f5;
            alignas(8) int64_t f6;
            alignas(8) int64_t f7;
            alignas(8) int64_t f8;
            alignas(8) int64_t f9;
            alignas(8) int64_t f10;
            alignas(8) int64_t f11;
            alignas(8) int64_t f12;
            alignas(8) int64_t f13;
            alignas(8) int64_t f14;
            alignas(8) int64_t f15;
            alignas(8) int64_t f16;
            alignas(8) int64_t f17;
            alignas(8) int64_t f18;
            alignas(8) int64_t f19;
            alignas(8) int64_t f20;
            alignas(8) int64_t f21;
            alignas(8) int64_t f22;
            alignas(8) int64_t f23;
            alignas(8) int64_t f24;
            alignas(8) int64_t f25;
            alignas(8) int64_t f26;
            alignas(8) int64_t f27;
            alignas(8) int64_t f28;
            alignas(8) int64_t f29;
            alignas(8) int64_t f30;
            alignas(8) int64_t f31;
            alignas(8) int64_t f32;
            alignas(8) M19* f33;
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
    
        inline void set_f11(int64_t val){
            f11 = val;
        }
        inline int64_t& get_f11(){
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
    
        inline void set_f14(int64_t val){
            f14 = val;
        }
        inline int64_t& get_f14(){
            return f14;
        }
    
        inline void set_f15(int64_t val){
            f15 = val;
        }
        inline int64_t& get_f15(){
            return f15;
        }
    
        inline void set_f16(int64_t val){
            f16 = val;
        }
        inline int64_t& get_f16(){
            return f16;
        }
    
        inline void set_f17(int64_t val){
            f17 = val;
        }
        inline int64_t& get_f17(){
            return f17;
        }
    
        inline void set_f18(int64_t val){
            f18 = val;
        }
        inline int64_t& get_f18(){
            return f18;
        }
    
        inline void set_f19(int64_t val){
            f19 = val;
        }
        inline int64_t& get_f19(){
            return f19;
        }
    
        inline void set_f20(int64_t val){
            f20 = val;
        }
        inline int64_t& get_f20(){
            return f20;
        }
    
        inline void set_f21(int64_t val){
            f21 = val;
        }
        inline int64_t& get_f21(){
            return f21;
        }
    
        inline void set_f22(int64_t val){
            f22 = val;
        }
        inline int64_t& get_f22(){
            return f22;
        }
    
        inline void set_f23(int64_t val){
            f23 = val;
        }
        inline int64_t& get_f23(){
            return f23;
        }
    
        inline void set_f24(int64_t val){
            f24 = val;
        }
        inline int64_t& get_f24(){
            return f24;
        }
    
        inline void set_f25(int64_t val){
            f25 = val;
        }
        inline int64_t& get_f25(){
            return f25;
        }
    
        inline void set_f26(int64_t val){
            f26 = val;
        }
        inline int64_t& get_f26(){
            return f26;
        }
    
        inline void set_f27(int64_t val){
            f27 = val;
        }
        inline int64_t& get_f27(){
            return f27;
        }
    
        inline void set_f28(int64_t val){
            f28 = val;
        }
        inline int64_t& get_f28(){
            return f28;
        }
    
        inline void set_f29(int64_t val){
            f29 = val;
        }
        inline int64_t& get_f29(){
            return f29;
        }
    
        inline void set_f30(int64_t val){
            f30 = val;
        }
        inline int64_t& get_f30(){
            return f30;
        }
    
        inline void set_f31(int64_t val){
            f31 = val;
        }
        inline int64_t& get_f31(){
            return f31;
        }
    
        inline void set_f32(int64_t val){
            f32 = val;
        }
        inline int64_t& get_f32(){
            return f32;
        }
    
        inline M18* mutable_f33(){
            f33 = new M18();
            return f33;
        }
        inline M18*& get_f33(){
            return f33;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M17->f1: " << f1 << std::endl;
            fout << "M17->f2: " << f2 << std::endl;
            fout << "M17->f3: " << f3 << std::endl;
            fout << "M17->f4: " << f4 << std::endl;
            fout << "M17->f5: " << f5 << std::endl;
            fout << "M17->f6: " << f6 << std::endl;
            fout << "M17->f7: " << f7 << std::endl;
            fout << "M17->f8: " << f8 << std::endl;
            fout << "M17->f9: " << f9 << std::endl;
            fout << "M17->f10: " << f10 << std::endl;
            fout << "M17->f11: " << f11 << std::endl;
            fout << "M17->f12: " << f12 << std::endl;
            fout << "M17->f13: " << f13 << std::endl;
            fout << "M17->f14: " << f14 << std::endl;
            fout << "M17->f15: " << f15 << std::endl;
            fout << "M17->f16: " << f16 << std::endl;
            fout << "M17->f17: " << f17 << std::endl;
            fout << "M17->f18: " << f18 << std::endl;
            fout << "M17->f19: " << f19 << std::endl;
            fout << "M17->f20: " << f20 << std::endl;
            fout << "M17->f21: " << f21 << std::endl;
            fout << "M17->f22: " << f22 << std::endl;
            fout << "M17->f23: " << f23 << std::endl;
            fout << "M17->f24: " << f24 << std::endl;
            fout << "M17->f25: " << f25 << std::endl;
            fout << "M17->f26: " << f26 << std::endl;
            fout << "M17->f27: " << f27 << std::endl;
            fout << "M17->f28: " << f28 << std::endl;
            fout << "M17->f29: " << f29 << std::endl;
            fout << "M17->f30: " << f30 << std::endl;
            fout << "M17->f31: " << f31 << std::endl;
            fout << "M17->f32: " << f32 << std::endl;
            if(f33 != nullptr)
                f33->print_message(fout);
        }
    
        ~M17(){
            if(f33 != nullptr)
                delete f33;
        }
    
        M17(){
           f33 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
        alignas(8) int64_t f3;
        alignas(8) int64_t f4;
        alignas(8) int64_t f5;
        alignas(8) int64_t f6;
        alignas(8) int64_t f7;
        alignas(8) int64_t f8;
        alignas(8) int64_t f9;
        alignas(8) int64_t f10;
        alignas(8) int64_t f11;
        alignas(8) int64_t f12;
        alignas(8) int64_t f13;
        alignas(8) int64_t f14;
        alignas(8) int64_t f15;
        alignas(8) int64_t f16;
        alignas(8) int64_t f17;
        alignas(8) int64_t f18;
        alignas(8) int64_t f19;
        alignas(8) int64_t f20;
        alignas(8) int64_t f21;
        alignas(8) int64_t f22;
        alignas(8) int64_t f23;
        alignas(8) int64_t f24;
        alignas(8) int64_t f25;
        alignas(8) int64_t f26;
        alignas(8) int64_t f27;
        alignas(8) int64_t f28;
        alignas(8) int64_t f29;
        alignas(8) int64_t f30;
        alignas(8) int64_t f31;
        alignas(8) int64_t f32;
        alignas(8) M18* f33;
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

    inline void set_f11(int64_t val){
        f11 = val;
    }
    inline int64_t& get_f11(){
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

    inline void set_f14(int64_t val){
        f14 = val;
    }
    inline int64_t& get_f14(){
        return f14;
    }

    inline void set_f15(int64_t val){
        f15 = val;
    }
    inline int64_t& get_f15(){
        return f15;
    }

    inline void set_f16(int64_t val){
        f16 = val;
    }
    inline int64_t& get_f16(){
        return f16;
    }

    inline void set_f17(int64_t val){
        f17 = val;
    }
    inline int64_t& get_f17(){
        return f17;
    }

    inline void set_f18(int64_t val){
        f18 = val;
    }
    inline int64_t& get_f18(){
        return f18;
    }

    inline void set_f19(int64_t val){
        f19 = val;
    }
    inline int64_t& get_f19(){
        return f19;
    }

    inline void set_f20(int64_t val){
        f20 = val;
    }
    inline int64_t& get_f20(){
        return f20;
    }

    inline void set_f21(int64_t val){
        f21 = val;
    }
    inline int64_t& get_f21(){
        return f21;
    }

    inline void set_f22(int64_t val){
        f22 = val;
    }
    inline int64_t& get_f22(){
        return f22;
    }

    inline void set_f23(int64_t val){
        f23 = val;
    }
    inline int64_t& get_f23(){
        return f23;
    }

    inline void set_f24(int64_t val){
        f24 = val;
    }
    inline int64_t& get_f24(){
        return f24;
    }

    inline void set_f25(int64_t val){
        f25 = val;
    }
    inline int64_t& get_f25(){
        return f25;
    }

    inline void set_f26(int64_t val){
        f26 = val;
    }
    inline int64_t& get_f26(){
        return f26;
    }

    inline void set_f27(int64_t val){
        f27 = val;
    }
    inline int64_t& get_f27(){
        return f27;
    }

    inline void set_f28(int64_t val){
        f28 = val;
    }
    inline int64_t& get_f28(){
        return f28;
    }

    inline void set_f29(int64_t val){
        f29 = val;
    }
    inline int64_t& get_f29(){
        return f29;
    }

    inline void set_f30(int64_t val){
        f30 = val;
    }
    inline int64_t& get_f30(){
        return f30;
    }

    inline void set_f31(int64_t val){
        f31 = val;
    }
    inline int64_t& get_f31(){
        return f31;
    }

    inline void set_f32(int64_t val){
        f32 = val;
    }
    inline int64_t& get_f32(){
        return f32;
    }

    inline M17* mutable_f33(){
        f33 = new M17();
        return f33;
    }
    inline M17*& get_f33(){
        return f33;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M16->f1: " << f1 << std::endl;
        fout << "M16->f2: " << f2 << std::endl;
        fout << "M16->f3: " << f3 << std::endl;
        fout << "M16->f4: " << f4 << std::endl;
        fout << "M16->f5: " << f5 << std::endl;
        fout << "M16->f6: " << f6 << std::endl;
        fout << "M16->f7: " << f7 << std::endl;
        fout << "M16->f8: " << f8 << std::endl;
        fout << "M16->f9: " << f9 << std::endl;
        fout << "M16->f10: " << f10 << std::endl;
        fout << "M16->f11: " << f11 << std::endl;
        fout << "M16->f12: " << f12 << std::endl;
        fout << "M16->f13: " << f13 << std::endl;
        fout << "M16->f14: " << f14 << std::endl;
        fout << "M16->f15: " << f15 << std::endl;
        fout << "M16->f16: " << f16 << std::endl;
        fout << "M16->f17: " << f17 << std::endl;
        fout << "M16->f18: " << f18 << std::endl;
        fout << "M16->f19: " << f19 << std::endl;
        fout << "M16->f20: " << f20 << std::endl;
        fout << "M16->f21: " << f21 << std::endl;
        fout << "M16->f22: " << f22 << std::endl;
        fout << "M16->f23: " << f23 << std::endl;
        fout << "M16->f24: " << f24 << std::endl;
        fout << "M16->f25: " << f25 << std::endl;
        fout << "M16->f26: " << f26 << std::endl;
        fout << "M16->f27: " << f27 << std::endl;
        fout << "M16->f28: " << f28 << std::endl;
        fout << "M16->f29: " << f29 << std::endl;
        fout << "M16->f30: " << f30 << std::endl;
        fout << "M16->f31: " << f31 << std::endl;
        fout << "M16->f32: " << f32 << std::endl;
        if(f33 != nullptr)
            f33->print_message(fout);
    }

    ~M16(){
        if(f33 != nullptr)
            delete f33;
    }

    M16(){
       f33 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) int64_t f3;
    alignas(8) int64_t f4;
    alignas(8) int64_t f5;
    alignas(8) int64_t f6;
    alignas(8) int64_t f7;
    alignas(8) int64_t f8;
    alignas(8) int64_t f9;
    alignas(8) int64_t f10;
    alignas(8) int64_t f11;
    alignas(8) int64_t f12;
    alignas(8) int64_t f13;
    alignas(8) int64_t f14;
    alignas(8) int64_t f15;
    alignas(8) int64_t f16;
    alignas(8) int64_t f17;
    alignas(8) int64_t f18;
    alignas(8) int64_t f19;
    alignas(8) int64_t f20;
    alignas(8) int64_t f21;
    alignas(8) int64_t f22;
    alignas(8) int64_t f23;
    alignas(8) int64_t f24;
    alignas(8) int64_t f25;
    alignas(8) int64_t f26;
    alignas(8) int64_t f27;
    alignas(8) int64_t f28;
    alignas(8) int64_t f29;
    alignas(8) int64_t f30;
    alignas(8) int64_t f31;
    alignas(8) int64_t f32;
    alignas(8) M17* f33;
};

M_base* createMessage(int temp_class_id) {
    switch (temp_class_id) {
        case 1:
            return new M1();
        case 2:
            return new M2();
        case 3:
            return new M2::M3();
        case 4:
            return new M4();
        case 5:
            return new M4::M5();
        case 6:
            return new M4::M5::M6();
        case 7:
            return new M4::M5::M6::M7();
        case 8:
            return new M8();
        case 9:
            return new M8::M9();
        case 10:
            return new M8::M9::M10();
        case 11:
            return new M8::M9::M10::M11();
        case 12:
            return new M8::M9::M10::M11::M12();
        case 13:
            return new M8::M9::M10::M11::M12::M13();
        case 14:
            return new M8::M9::M10::M11::M12::M13::M14();
        case 15:
            return new M8::M9::M10::M11::M12::M13::M14::M15();
        case 16:
            return new M16();
        case 17:
            return new M16::M17();
        case 18:
            return new M16::M17::M18();
        case 19:
            return new M16::M17::M18::M19();
        case 20:
            return new M16::M17::M18::M19::M20();
        case 21:
            return new M16::M17::M18::M19::M20::M21();
        case 22:
            return new M16::M17::M18::M19::M20::M21::M22();
        case 23:
            return new M16::M17::M18::M19::M20::M21::M22::M23();
        case 24:
            return new M16::M17::M18::M19::M20::M21::M22::M23::M24();
        case 25:
            return new M16::M17::M18::M19::M20::M21::M22::M23::M24::M25();
        case 26:
            return new M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26();
        case 27:
            return new M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27();
        case 28:
            return new M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27::M28();
        case 29:
            return new M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27::M28::M29();
        case 30:
            return new M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27::M28::M29::M30();
        case 31:
            return new M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27::M28::M29::M30::M31();
        default:
            throw std::invalid_argument("Invalid class id");
    }
}

size_t getMessageSize(int temp_class_id) {
    switch (temp_class_id) {
        case 1:
            return sizeof(M1);
        case 2:
            return sizeof(M2);
        case 3:
            return sizeof(M2::M3);
        case 4:
            return sizeof(M4);
        case 5:
            return sizeof(M4::M5);
        case 6:
            return sizeof(M4::M5::M6);
        case 7:
            return sizeof(M4::M5::M6::M7);
        case 8:
            return sizeof(M8);
        case 9:
            return sizeof(M8::M9);
        case 10:
            return sizeof(M8::M9::M10);
        case 11:
            return sizeof(M8::M9::M10::M11);
        case 12:
            return sizeof(M8::M9::M10::M11::M12);
        case 13:
            return sizeof(M8::M9::M10::M11::M12::M13);
        case 14:
            return sizeof(M8::M9::M10::M11::M12::M13::M14);
        case 15:
            return sizeof(M8::M9::M10::M11::M12::M13::M14::M15);
        case 16:
            return sizeof(M16);
        case 17:
            return sizeof(M16::M17);
        case 18:
            return sizeof(M16::M17::M18);
        case 19:
            return sizeof(M16::M17::M18::M19);
        case 20:
            return sizeof(M16::M17::M18::M19::M20);
        case 21:
            return sizeof(M16::M17::M18::M19::M20::M21);
        case 22:
            return sizeof(M16::M17::M18::M19::M20::M21::M22);
        case 23:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23);
        case 24:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23::M24);
        case 25:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23::M24::M25);
        case 26:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26);
        case 27:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27);
        case 28:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27::M28);
        case 29:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27::M28::M29);
        case 30:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27::M28::M29::M30);
        case 31:
            return sizeof(M16::M17::M18::M19::M20::M21::M22::M23::M24::M25::M26::M27::M28::M29::M30::M31);
        default:
            return 0;
    }
}


