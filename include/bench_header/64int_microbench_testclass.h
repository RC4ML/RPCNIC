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

    inline void set_f33(int64_t val){
        f33 = val;
    }
    inline int64_t& get_f33(){
        return f33;
    }

    inline void set_f34(int64_t val){
        f34 = val;
    }
    inline int64_t& get_f34(){
        return f34;
    }

    inline void set_f35(int64_t val){
        f35 = val;
    }
    inline int64_t& get_f35(){
        return f35;
    }

    inline void set_f36(int64_t val){
        f36 = val;
    }
    inline int64_t& get_f36(){
        return f36;
    }

    inline void set_f37(int64_t val){
        f37 = val;
    }
    inline int64_t& get_f37(){
        return f37;
    }

    inline void set_f38(int64_t val){
        f38 = val;
    }
    inline int64_t& get_f38(){
        return f38;
    }

    inline void set_f39(int64_t val){
        f39 = val;
    }
    inline int64_t& get_f39(){
        return f39;
    }

    inline void set_f40(int64_t val){
        f40 = val;
    }
    inline int64_t& get_f40(){
        return f40;
    }

    inline void set_f41(int64_t val){
        f41 = val;
    }
    inline int64_t& get_f41(){
        return f41;
    }

    inline void set_f42(int64_t val){
        f42 = val;
    }
    inline int64_t& get_f42(){
        return f42;
    }

    inline void set_f43(int64_t val){
        f43 = val;
    }
    inline int64_t& get_f43(){
        return f43;
    }

    inline void set_f44(int64_t val){
        f44 = val;
    }
    inline int64_t& get_f44(){
        return f44;
    }

    inline void set_f45(int64_t val){
        f45 = val;
    }
    inline int64_t& get_f45(){
        return f45;
    }

    inline void set_f46(int64_t val){
        f46 = val;
    }
    inline int64_t& get_f46(){
        return f46;
    }

    inline void set_f47(int64_t val){
        f47 = val;
    }
    inline int64_t& get_f47(){
        return f47;
    }

    inline void set_f48(int64_t val){
        f48 = val;
    }
    inline int64_t& get_f48(){
        return f48;
    }

    inline void set_f49(int64_t val){
        f49 = val;
    }
    inline int64_t& get_f49(){
        return f49;
    }

    inline void set_f50(int64_t val){
        f50 = val;
    }
    inline int64_t& get_f50(){
        return f50;
    }

    inline void set_f51(int64_t val){
        f51 = val;
    }
    inline int64_t& get_f51(){
        return f51;
    }

    inline void set_f52(int64_t val){
        f52 = val;
    }
    inline int64_t& get_f52(){
        return f52;
    }

    inline void set_f53(int64_t val){
        f53 = val;
    }
    inline int64_t& get_f53(){
        return f53;
    }

    inline void set_f54(int64_t val){
        f54 = val;
    }
    inline int64_t& get_f54(){
        return f54;
    }

    inline void set_f55(int64_t val){
        f55 = val;
    }
    inline int64_t& get_f55(){
        return f55;
    }

    inline void set_f56(int64_t val){
        f56 = val;
    }
    inline int64_t& get_f56(){
        return f56;
    }

    inline void set_f57(int64_t val){
        f57 = val;
    }
    inline int64_t& get_f57(){
        return f57;
    }

    inline void set_f58(int64_t val){
        f58 = val;
    }
    inline int64_t& get_f58(){
        return f58;
    }

    inline void set_f59(int64_t val){
        f59 = val;
    }
    inline int64_t& get_f59(){
        return f59;
    }

    inline void set_f60(int64_t val){
        f60 = val;
    }
    inline int64_t& get_f60(){
        return f60;
    }

    inline void set_f61(int64_t val){
        f61 = val;
    }
    inline int64_t& get_f61(){
        return f61;
    }

    inline void set_f62(int64_t val){
        f62 = val;
    }
    inline int64_t& get_f62(){
        return f62;
    }

    inline void set_f63(int64_t val){
        f63 = val;
    }
    inline int64_t& get_f63(){
        return f63;
    }

    inline void set_f64(int64_t val){
        f64 = val;
    }
    inline int64_t& get_f64(){
        return f64;
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
        fout << "M1->f33: " << f33 << std::endl;
        fout << "M1->f34: " << f34 << std::endl;
        fout << "M1->f35: " << f35 << std::endl;
        fout << "M1->f36: " << f36 << std::endl;
        fout << "M1->f37: " << f37 << std::endl;
        fout << "M1->f38: " << f38 << std::endl;
        fout << "M1->f39: " << f39 << std::endl;
        fout << "M1->f40: " << f40 << std::endl;
        fout << "M1->f41: " << f41 << std::endl;
        fout << "M1->f42: " << f42 << std::endl;
        fout << "M1->f43: " << f43 << std::endl;
        fout << "M1->f44: " << f44 << std::endl;
        fout << "M1->f45: " << f45 << std::endl;
        fout << "M1->f46: " << f46 << std::endl;
        fout << "M1->f47: " << f47 << std::endl;
        fout << "M1->f48: " << f48 << std::endl;
        fout << "M1->f49: " << f49 << std::endl;
        fout << "M1->f50: " << f50 << std::endl;
        fout << "M1->f51: " << f51 << std::endl;
        fout << "M1->f52: " << f52 << std::endl;
        fout << "M1->f53: " << f53 << std::endl;
        fout << "M1->f54: " << f54 << std::endl;
        fout << "M1->f55: " << f55 << std::endl;
        fout << "M1->f56: " << f56 << std::endl;
        fout << "M1->f57: " << f57 << std::endl;
        fout << "M1->f58: " << f58 << std::endl;
        fout << "M1->f59: " << f59 << std::endl;
        fout << "M1->f60: " << f60 << std::endl;
        fout << "M1->f61: " << f61 << std::endl;
        fout << "M1->f62: " << f62 << std::endl;
        fout << "M1->f63: " << f63 << std::endl;
        fout << "M1->f64: " << f64 << std::endl;
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
    alignas(8) int64_t f33;
    alignas(8) int64_t f34;
    alignas(8) int64_t f35;
    alignas(8) int64_t f36;
    alignas(8) int64_t f37;
    alignas(8) int64_t f38;
    alignas(8) int64_t f39;
    alignas(8) int64_t f40;
    alignas(8) int64_t f41;
    alignas(8) int64_t f42;
    alignas(8) int64_t f43;
    alignas(8) int64_t f44;
    alignas(8) int64_t f45;
    alignas(8) int64_t f46;
    alignas(8) int64_t f47;
    alignas(8) int64_t f48;
    alignas(8) int64_t f49;
    alignas(8) int64_t f50;
    alignas(8) int64_t f51;
    alignas(8) int64_t f52;
    alignas(8) int64_t f53;
    alignas(8) int64_t f54;
    alignas(8) int64_t f55;
    alignas(8) int64_t f56;
    alignas(8) int64_t f57;
    alignas(8) int64_t f58;
    alignas(8) int64_t f59;
    alignas(8) int64_t f60;
    alignas(8) int64_t f61;
    alignas(8) int64_t f62;
    alignas(8) int64_t f63;
    alignas(8) int64_t f64;
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
    
        inline void set_f33(int64_t val){
            f33 = val;
        }
        inline int64_t& get_f33(){
            return f33;
        }
    
        inline void set_f34(int64_t val){
            f34 = val;
        }
        inline int64_t& get_f34(){
            return f34;
        }
    
        inline void set_f35(int64_t val){
            f35 = val;
        }
        inline int64_t& get_f35(){
            return f35;
        }
    
        inline void set_f36(int64_t val){
            f36 = val;
        }
        inline int64_t& get_f36(){
            return f36;
        }
    
        inline void set_f37(int64_t val){
            f37 = val;
        }
        inline int64_t& get_f37(){
            return f37;
        }
    
        inline void set_f38(int64_t val){
            f38 = val;
        }
        inline int64_t& get_f38(){
            return f38;
        }
    
        inline void set_f39(int64_t val){
            f39 = val;
        }
        inline int64_t& get_f39(){
            return f39;
        }
    
        inline void set_f40(int64_t val){
            f40 = val;
        }
        inline int64_t& get_f40(){
            return f40;
        }
    
        inline void set_f41(int64_t val){
            f41 = val;
        }
        inline int64_t& get_f41(){
            return f41;
        }
    
        inline void set_f42(int64_t val){
            f42 = val;
        }
        inline int64_t& get_f42(){
            return f42;
        }
    
        inline void set_f43(int64_t val){
            f43 = val;
        }
        inline int64_t& get_f43(){
            return f43;
        }
    
        inline void set_f44(int64_t val){
            f44 = val;
        }
        inline int64_t& get_f44(){
            return f44;
        }
    
        inline void set_f45(int64_t val){
            f45 = val;
        }
        inline int64_t& get_f45(){
            return f45;
        }
    
        inline void set_f46(int64_t val){
            f46 = val;
        }
        inline int64_t& get_f46(){
            return f46;
        }
    
        inline void set_f47(int64_t val){
            f47 = val;
        }
        inline int64_t& get_f47(){
            return f47;
        }
    
        inline void set_f48(int64_t val){
            f48 = val;
        }
        inline int64_t& get_f48(){
            return f48;
        }
    
        inline void set_f49(int64_t val){
            f49 = val;
        }
        inline int64_t& get_f49(){
            return f49;
        }
    
        inline void set_f50(int64_t val){
            f50 = val;
        }
        inline int64_t& get_f50(){
            return f50;
        }
    
        inline void set_f51(int64_t val){
            f51 = val;
        }
        inline int64_t& get_f51(){
            return f51;
        }
    
        inline void set_f52(int64_t val){
            f52 = val;
        }
        inline int64_t& get_f52(){
            return f52;
        }
    
        inline void set_f53(int64_t val){
            f53 = val;
        }
        inline int64_t& get_f53(){
            return f53;
        }
    
        inline void set_f54(int64_t val){
            f54 = val;
        }
        inline int64_t& get_f54(){
            return f54;
        }
    
        inline void set_f55(int64_t val){
            f55 = val;
        }
        inline int64_t& get_f55(){
            return f55;
        }
    
        inline void set_f56(int64_t val){
            f56 = val;
        }
        inline int64_t& get_f56(){
            return f56;
        }
    
        inline void set_f57(int64_t val){
            f57 = val;
        }
        inline int64_t& get_f57(){
            return f57;
        }
    
        inline void set_f58(int64_t val){
            f58 = val;
        }
        inline int64_t& get_f58(){
            return f58;
        }
    
        inline void set_f59(int64_t val){
            f59 = val;
        }
        inline int64_t& get_f59(){
            return f59;
        }
    
        inline void set_f60(int64_t val){
            f60 = val;
        }
        inline int64_t& get_f60(){
            return f60;
        }
    
        inline void set_f61(int64_t val){
            f61 = val;
        }
        inline int64_t& get_f61(){
            return f61;
        }
    
        inline void set_f62(int64_t val){
            f62 = val;
        }
        inline int64_t& get_f62(){
            return f62;
        }
    
        inline void set_f63(int64_t val){
            f63 = val;
        }
        inline int64_t& get_f63(){
            return f63;
        }
    
        inline void set_f64(int64_t val){
            f64 = val;
        }
        inline int64_t& get_f64(){
            return f64;
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
            fout << "M3->f33: " << f33 << std::endl;
            fout << "M3->f34: " << f34 << std::endl;
            fout << "M3->f35: " << f35 << std::endl;
            fout << "M3->f36: " << f36 << std::endl;
            fout << "M3->f37: " << f37 << std::endl;
            fout << "M3->f38: " << f38 << std::endl;
            fout << "M3->f39: " << f39 << std::endl;
            fout << "M3->f40: " << f40 << std::endl;
            fout << "M3->f41: " << f41 << std::endl;
            fout << "M3->f42: " << f42 << std::endl;
            fout << "M3->f43: " << f43 << std::endl;
            fout << "M3->f44: " << f44 << std::endl;
            fout << "M3->f45: " << f45 << std::endl;
            fout << "M3->f46: " << f46 << std::endl;
            fout << "M3->f47: " << f47 << std::endl;
            fout << "M3->f48: " << f48 << std::endl;
            fout << "M3->f49: " << f49 << std::endl;
            fout << "M3->f50: " << f50 << std::endl;
            fout << "M3->f51: " << f51 << std::endl;
            fout << "M3->f52: " << f52 << std::endl;
            fout << "M3->f53: " << f53 << std::endl;
            fout << "M3->f54: " << f54 << std::endl;
            fout << "M3->f55: " << f55 << std::endl;
            fout << "M3->f56: " << f56 << std::endl;
            fout << "M3->f57: " << f57 << std::endl;
            fout << "M3->f58: " << f58 << std::endl;
            fout << "M3->f59: " << f59 << std::endl;
            fout << "M3->f60: " << f60 << std::endl;
            fout << "M3->f61: " << f61 << std::endl;
            fout << "M3->f62: " << f62 << std::endl;
            fout << "M3->f63: " << f63 << std::endl;
            fout << "M3->f64: " << f64 << std::endl;
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
        alignas(8) int64_t f33;
        alignas(8) int64_t f34;
        alignas(8) int64_t f35;
        alignas(8) int64_t f36;
        alignas(8) int64_t f37;
        alignas(8) int64_t f38;
        alignas(8) int64_t f39;
        alignas(8) int64_t f40;
        alignas(8) int64_t f41;
        alignas(8) int64_t f42;
        alignas(8) int64_t f43;
        alignas(8) int64_t f44;
        alignas(8) int64_t f45;
        alignas(8) int64_t f46;
        alignas(8) int64_t f47;
        alignas(8) int64_t f48;
        alignas(8) int64_t f49;
        alignas(8) int64_t f50;
        alignas(8) int64_t f51;
        alignas(8) int64_t f52;
        alignas(8) int64_t f53;
        alignas(8) int64_t f54;
        alignas(8) int64_t f55;
        alignas(8) int64_t f56;
        alignas(8) int64_t f57;
        alignas(8) int64_t f58;
        alignas(8) int64_t f59;
        alignas(8) int64_t f60;
        alignas(8) int64_t f61;
        alignas(8) int64_t f62;
        alignas(8) int64_t f63;
        alignas(8) int64_t f64;
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

    inline void set_f33(int64_t val){
        f33 = val;
    }
    inline int64_t& get_f33(){
        return f33;
    }

    inline void set_f34(int64_t val){
        f34 = val;
    }
    inline int64_t& get_f34(){
        return f34;
    }

    inline void set_f35(int64_t val){
        f35 = val;
    }
    inline int64_t& get_f35(){
        return f35;
    }

    inline void set_f36(int64_t val){
        f36 = val;
    }
    inline int64_t& get_f36(){
        return f36;
    }

    inline void set_f37(int64_t val){
        f37 = val;
    }
    inline int64_t& get_f37(){
        return f37;
    }

    inline void set_f38(int64_t val){
        f38 = val;
    }
    inline int64_t& get_f38(){
        return f38;
    }

    inline void set_f39(int64_t val){
        f39 = val;
    }
    inline int64_t& get_f39(){
        return f39;
    }

    inline void set_f40(int64_t val){
        f40 = val;
    }
    inline int64_t& get_f40(){
        return f40;
    }

    inline void set_f41(int64_t val){
        f41 = val;
    }
    inline int64_t& get_f41(){
        return f41;
    }

    inline void set_f42(int64_t val){
        f42 = val;
    }
    inline int64_t& get_f42(){
        return f42;
    }

    inline void set_f43(int64_t val){
        f43 = val;
    }
    inline int64_t& get_f43(){
        return f43;
    }

    inline void set_f44(int64_t val){
        f44 = val;
    }
    inline int64_t& get_f44(){
        return f44;
    }

    inline void set_f45(int64_t val){
        f45 = val;
    }
    inline int64_t& get_f45(){
        return f45;
    }

    inline void set_f46(int64_t val){
        f46 = val;
    }
    inline int64_t& get_f46(){
        return f46;
    }

    inline void set_f47(int64_t val){
        f47 = val;
    }
    inline int64_t& get_f47(){
        return f47;
    }

    inline void set_f48(int64_t val){
        f48 = val;
    }
    inline int64_t& get_f48(){
        return f48;
    }

    inline void set_f49(int64_t val){
        f49 = val;
    }
    inline int64_t& get_f49(){
        return f49;
    }

    inline void set_f50(int64_t val){
        f50 = val;
    }
    inline int64_t& get_f50(){
        return f50;
    }

    inline void set_f51(int64_t val){
        f51 = val;
    }
    inline int64_t& get_f51(){
        return f51;
    }

    inline void set_f52(int64_t val){
        f52 = val;
    }
    inline int64_t& get_f52(){
        return f52;
    }

    inline void set_f53(int64_t val){
        f53 = val;
    }
    inline int64_t& get_f53(){
        return f53;
    }

    inline void set_f54(int64_t val){
        f54 = val;
    }
    inline int64_t& get_f54(){
        return f54;
    }

    inline void set_f55(int64_t val){
        f55 = val;
    }
    inline int64_t& get_f55(){
        return f55;
    }

    inline void set_f56(int64_t val){
        f56 = val;
    }
    inline int64_t& get_f56(){
        return f56;
    }

    inline void set_f57(int64_t val){
        f57 = val;
    }
    inline int64_t& get_f57(){
        return f57;
    }

    inline void set_f58(int64_t val){
        f58 = val;
    }
    inline int64_t& get_f58(){
        return f58;
    }

    inline void set_f59(int64_t val){
        f59 = val;
    }
    inline int64_t& get_f59(){
        return f59;
    }

    inline void set_f60(int64_t val){
        f60 = val;
    }
    inline int64_t& get_f60(){
        return f60;
    }

    inline void set_f61(int64_t val){
        f61 = val;
    }
    inline int64_t& get_f61(){
        return f61;
    }

    inline void set_f62(int64_t val){
        f62 = val;
    }
    inline int64_t& get_f62(){
        return f62;
    }

    inline void set_f63(int64_t val){
        f63 = val;
    }
    inline int64_t& get_f63(){
        return f63;
    }

    inline void set_f64(int64_t val){
        f64 = val;
    }
    inline int64_t& get_f64(){
        return f64;
    }

    inline M3* mutable_f65(){
        f65 = new M3();
        return f65;
    }
    inline M3*& get_f65(){
        return f65;
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
        fout << "M2->f33: " << f33 << std::endl;
        fout << "M2->f34: " << f34 << std::endl;
        fout << "M2->f35: " << f35 << std::endl;
        fout << "M2->f36: " << f36 << std::endl;
        fout << "M2->f37: " << f37 << std::endl;
        fout << "M2->f38: " << f38 << std::endl;
        fout << "M2->f39: " << f39 << std::endl;
        fout << "M2->f40: " << f40 << std::endl;
        fout << "M2->f41: " << f41 << std::endl;
        fout << "M2->f42: " << f42 << std::endl;
        fout << "M2->f43: " << f43 << std::endl;
        fout << "M2->f44: " << f44 << std::endl;
        fout << "M2->f45: " << f45 << std::endl;
        fout << "M2->f46: " << f46 << std::endl;
        fout << "M2->f47: " << f47 << std::endl;
        fout << "M2->f48: " << f48 << std::endl;
        fout << "M2->f49: " << f49 << std::endl;
        fout << "M2->f50: " << f50 << std::endl;
        fout << "M2->f51: " << f51 << std::endl;
        fout << "M2->f52: " << f52 << std::endl;
        fout << "M2->f53: " << f53 << std::endl;
        fout << "M2->f54: " << f54 << std::endl;
        fout << "M2->f55: " << f55 << std::endl;
        fout << "M2->f56: " << f56 << std::endl;
        fout << "M2->f57: " << f57 << std::endl;
        fout << "M2->f58: " << f58 << std::endl;
        fout << "M2->f59: " << f59 << std::endl;
        fout << "M2->f60: " << f60 << std::endl;
        fout << "M2->f61: " << f61 << std::endl;
        fout << "M2->f62: " << f62 << std::endl;
        fout << "M2->f63: " << f63 << std::endl;
        fout << "M2->f64: " << f64 << std::endl;
        if(f65 != nullptr)
            f65->print_message(fout);
    }

    ~M2(){
        if(f65 != nullptr)
            delete f65;
    }

    M2(){
       f65 = nullptr;
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
    alignas(8) int64_t f33;
    alignas(8) int64_t f34;
    alignas(8) int64_t f35;
    alignas(8) int64_t f36;
    alignas(8) int64_t f37;
    alignas(8) int64_t f38;
    alignas(8) int64_t f39;
    alignas(8) int64_t f40;
    alignas(8) int64_t f41;
    alignas(8) int64_t f42;
    alignas(8) int64_t f43;
    alignas(8) int64_t f44;
    alignas(8) int64_t f45;
    alignas(8) int64_t f46;
    alignas(8) int64_t f47;
    alignas(8) int64_t f48;
    alignas(8) int64_t f49;
    alignas(8) int64_t f50;
    alignas(8) int64_t f51;
    alignas(8) int64_t f52;
    alignas(8) int64_t f53;
    alignas(8) int64_t f54;
    alignas(8) int64_t f55;
    alignas(8) int64_t f56;
    alignas(8) int64_t f57;
    alignas(8) int64_t f58;
    alignas(8) int64_t f59;
    alignas(8) int64_t f60;
    alignas(8) int64_t f61;
    alignas(8) int64_t f62;
    alignas(8) int64_t f63;
    alignas(8) int64_t f64;
    alignas(8) M3* f65;
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
            
                inline void set_f33(int64_t val){
                    f33 = val;
                }
                inline int64_t& get_f33(){
                    return f33;
                }
            
                inline void set_f34(int64_t val){
                    f34 = val;
                }
                inline int64_t& get_f34(){
                    return f34;
                }
            
                inline void set_f35(int64_t val){
                    f35 = val;
                }
                inline int64_t& get_f35(){
                    return f35;
                }
            
                inline void set_f36(int64_t val){
                    f36 = val;
                }
                inline int64_t& get_f36(){
                    return f36;
                }
            
                inline void set_f37(int64_t val){
                    f37 = val;
                }
                inline int64_t& get_f37(){
                    return f37;
                }
            
                inline void set_f38(int64_t val){
                    f38 = val;
                }
                inline int64_t& get_f38(){
                    return f38;
                }
            
                inline void set_f39(int64_t val){
                    f39 = val;
                }
                inline int64_t& get_f39(){
                    return f39;
                }
            
                inline void set_f40(int64_t val){
                    f40 = val;
                }
                inline int64_t& get_f40(){
                    return f40;
                }
            
                inline void set_f41(int64_t val){
                    f41 = val;
                }
                inline int64_t& get_f41(){
                    return f41;
                }
            
                inline void set_f42(int64_t val){
                    f42 = val;
                }
                inline int64_t& get_f42(){
                    return f42;
                }
            
                inline void set_f43(int64_t val){
                    f43 = val;
                }
                inline int64_t& get_f43(){
                    return f43;
                }
            
                inline void set_f44(int64_t val){
                    f44 = val;
                }
                inline int64_t& get_f44(){
                    return f44;
                }
            
                inline void set_f45(int64_t val){
                    f45 = val;
                }
                inline int64_t& get_f45(){
                    return f45;
                }
            
                inline void set_f46(int64_t val){
                    f46 = val;
                }
                inline int64_t& get_f46(){
                    return f46;
                }
            
                inline void set_f47(int64_t val){
                    f47 = val;
                }
                inline int64_t& get_f47(){
                    return f47;
                }
            
                inline void set_f48(int64_t val){
                    f48 = val;
                }
                inline int64_t& get_f48(){
                    return f48;
                }
            
                inline void set_f49(int64_t val){
                    f49 = val;
                }
                inline int64_t& get_f49(){
                    return f49;
                }
            
                inline void set_f50(int64_t val){
                    f50 = val;
                }
                inline int64_t& get_f50(){
                    return f50;
                }
            
                inline void set_f51(int64_t val){
                    f51 = val;
                }
                inline int64_t& get_f51(){
                    return f51;
                }
            
                inline void set_f52(int64_t val){
                    f52 = val;
                }
                inline int64_t& get_f52(){
                    return f52;
                }
            
                inline void set_f53(int64_t val){
                    f53 = val;
                }
                inline int64_t& get_f53(){
                    return f53;
                }
            
                inline void set_f54(int64_t val){
                    f54 = val;
                }
                inline int64_t& get_f54(){
                    return f54;
                }
            
                inline void set_f55(int64_t val){
                    f55 = val;
                }
                inline int64_t& get_f55(){
                    return f55;
                }
            
                inline void set_f56(int64_t val){
                    f56 = val;
                }
                inline int64_t& get_f56(){
                    return f56;
                }
            
                inline void set_f57(int64_t val){
                    f57 = val;
                }
                inline int64_t& get_f57(){
                    return f57;
                }
            
                inline void set_f58(int64_t val){
                    f58 = val;
                }
                inline int64_t& get_f58(){
                    return f58;
                }
            
                inline void set_f59(int64_t val){
                    f59 = val;
                }
                inline int64_t& get_f59(){
                    return f59;
                }
            
                inline void set_f60(int64_t val){
                    f60 = val;
                }
                inline int64_t& get_f60(){
                    return f60;
                }
            
                inline void set_f61(int64_t val){
                    f61 = val;
                }
                inline int64_t& get_f61(){
                    return f61;
                }
            
                inline void set_f62(int64_t val){
                    f62 = val;
                }
                inline int64_t& get_f62(){
                    return f62;
                }
            
                inline void set_f63(int64_t val){
                    f63 = val;
                }
                inline int64_t& get_f63(){
                    return f63;
                }
            
                inline void set_f64(int64_t val){
                    f64 = val;
                }
                inline int64_t& get_f64(){
                    return f64;
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
                    fout << "M7->f33: " << f33 << std::endl;
                    fout << "M7->f34: " << f34 << std::endl;
                    fout << "M7->f35: " << f35 << std::endl;
                    fout << "M7->f36: " << f36 << std::endl;
                    fout << "M7->f37: " << f37 << std::endl;
                    fout << "M7->f38: " << f38 << std::endl;
                    fout << "M7->f39: " << f39 << std::endl;
                    fout << "M7->f40: " << f40 << std::endl;
                    fout << "M7->f41: " << f41 << std::endl;
                    fout << "M7->f42: " << f42 << std::endl;
                    fout << "M7->f43: " << f43 << std::endl;
                    fout << "M7->f44: " << f44 << std::endl;
                    fout << "M7->f45: " << f45 << std::endl;
                    fout << "M7->f46: " << f46 << std::endl;
                    fout << "M7->f47: " << f47 << std::endl;
                    fout << "M7->f48: " << f48 << std::endl;
                    fout << "M7->f49: " << f49 << std::endl;
                    fout << "M7->f50: " << f50 << std::endl;
                    fout << "M7->f51: " << f51 << std::endl;
                    fout << "M7->f52: " << f52 << std::endl;
                    fout << "M7->f53: " << f53 << std::endl;
                    fout << "M7->f54: " << f54 << std::endl;
                    fout << "M7->f55: " << f55 << std::endl;
                    fout << "M7->f56: " << f56 << std::endl;
                    fout << "M7->f57: " << f57 << std::endl;
                    fout << "M7->f58: " << f58 << std::endl;
                    fout << "M7->f59: " << f59 << std::endl;
                    fout << "M7->f60: " << f60 << std::endl;
                    fout << "M7->f61: " << f61 << std::endl;
                    fout << "M7->f62: " << f62 << std::endl;
                    fout << "M7->f63: " << f63 << std::endl;
                    fout << "M7->f64: " << f64 << std::endl;
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
                alignas(8) int64_t f33;
                alignas(8) int64_t f34;
                alignas(8) int64_t f35;
                alignas(8) int64_t f36;
                alignas(8) int64_t f37;
                alignas(8) int64_t f38;
                alignas(8) int64_t f39;
                alignas(8) int64_t f40;
                alignas(8) int64_t f41;
                alignas(8) int64_t f42;
                alignas(8) int64_t f43;
                alignas(8) int64_t f44;
                alignas(8) int64_t f45;
                alignas(8) int64_t f46;
                alignas(8) int64_t f47;
                alignas(8) int64_t f48;
                alignas(8) int64_t f49;
                alignas(8) int64_t f50;
                alignas(8) int64_t f51;
                alignas(8) int64_t f52;
                alignas(8) int64_t f53;
                alignas(8) int64_t f54;
                alignas(8) int64_t f55;
                alignas(8) int64_t f56;
                alignas(8) int64_t f57;
                alignas(8) int64_t f58;
                alignas(8) int64_t f59;
                alignas(8) int64_t f60;
                alignas(8) int64_t f61;
                alignas(8) int64_t f62;
                alignas(8) int64_t f63;
                alignas(8) int64_t f64;
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
        
            inline void set_f33(int64_t val){
                f33 = val;
            }
            inline int64_t& get_f33(){
                return f33;
            }
        
            inline void set_f34(int64_t val){
                f34 = val;
            }
            inline int64_t& get_f34(){
                return f34;
            }
        
            inline void set_f35(int64_t val){
                f35 = val;
            }
            inline int64_t& get_f35(){
                return f35;
            }
        
            inline void set_f36(int64_t val){
                f36 = val;
            }
            inline int64_t& get_f36(){
                return f36;
            }
        
            inline void set_f37(int64_t val){
                f37 = val;
            }
            inline int64_t& get_f37(){
                return f37;
            }
        
            inline void set_f38(int64_t val){
                f38 = val;
            }
            inline int64_t& get_f38(){
                return f38;
            }
        
            inline void set_f39(int64_t val){
                f39 = val;
            }
            inline int64_t& get_f39(){
                return f39;
            }
        
            inline void set_f40(int64_t val){
                f40 = val;
            }
            inline int64_t& get_f40(){
                return f40;
            }
        
            inline void set_f41(int64_t val){
                f41 = val;
            }
            inline int64_t& get_f41(){
                return f41;
            }
        
            inline void set_f42(int64_t val){
                f42 = val;
            }
            inline int64_t& get_f42(){
                return f42;
            }
        
            inline void set_f43(int64_t val){
                f43 = val;
            }
            inline int64_t& get_f43(){
                return f43;
            }
        
            inline void set_f44(int64_t val){
                f44 = val;
            }
            inline int64_t& get_f44(){
                return f44;
            }
        
            inline void set_f45(int64_t val){
                f45 = val;
            }
            inline int64_t& get_f45(){
                return f45;
            }
        
            inline void set_f46(int64_t val){
                f46 = val;
            }
            inline int64_t& get_f46(){
                return f46;
            }
        
            inline void set_f47(int64_t val){
                f47 = val;
            }
            inline int64_t& get_f47(){
                return f47;
            }
        
            inline void set_f48(int64_t val){
                f48 = val;
            }
            inline int64_t& get_f48(){
                return f48;
            }
        
            inline void set_f49(int64_t val){
                f49 = val;
            }
            inline int64_t& get_f49(){
                return f49;
            }
        
            inline void set_f50(int64_t val){
                f50 = val;
            }
            inline int64_t& get_f50(){
                return f50;
            }
        
            inline void set_f51(int64_t val){
                f51 = val;
            }
            inline int64_t& get_f51(){
                return f51;
            }
        
            inline void set_f52(int64_t val){
                f52 = val;
            }
            inline int64_t& get_f52(){
                return f52;
            }
        
            inline void set_f53(int64_t val){
                f53 = val;
            }
            inline int64_t& get_f53(){
                return f53;
            }
        
            inline void set_f54(int64_t val){
                f54 = val;
            }
            inline int64_t& get_f54(){
                return f54;
            }
        
            inline void set_f55(int64_t val){
                f55 = val;
            }
            inline int64_t& get_f55(){
                return f55;
            }
        
            inline void set_f56(int64_t val){
                f56 = val;
            }
            inline int64_t& get_f56(){
                return f56;
            }
        
            inline void set_f57(int64_t val){
                f57 = val;
            }
            inline int64_t& get_f57(){
                return f57;
            }
        
            inline void set_f58(int64_t val){
                f58 = val;
            }
            inline int64_t& get_f58(){
                return f58;
            }
        
            inline void set_f59(int64_t val){
                f59 = val;
            }
            inline int64_t& get_f59(){
                return f59;
            }
        
            inline void set_f60(int64_t val){
                f60 = val;
            }
            inline int64_t& get_f60(){
                return f60;
            }
        
            inline void set_f61(int64_t val){
                f61 = val;
            }
            inline int64_t& get_f61(){
                return f61;
            }
        
            inline void set_f62(int64_t val){
                f62 = val;
            }
            inline int64_t& get_f62(){
                return f62;
            }
        
            inline void set_f63(int64_t val){
                f63 = val;
            }
            inline int64_t& get_f63(){
                return f63;
            }
        
            inline void set_f64(int64_t val){
                f64 = val;
            }
            inline int64_t& get_f64(){
                return f64;
            }
        
            inline M7* mutable_f65(){
                f65 = new M7();
                return f65;
            }
            inline M7*& get_f65(){
                return f65;
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
                fout << "M6->f33: " << f33 << std::endl;
                fout << "M6->f34: " << f34 << std::endl;
                fout << "M6->f35: " << f35 << std::endl;
                fout << "M6->f36: " << f36 << std::endl;
                fout << "M6->f37: " << f37 << std::endl;
                fout << "M6->f38: " << f38 << std::endl;
                fout << "M6->f39: " << f39 << std::endl;
                fout << "M6->f40: " << f40 << std::endl;
                fout << "M6->f41: " << f41 << std::endl;
                fout << "M6->f42: " << f42 << std::endl;
                fout << "M6->f43: " << f43 << std::endl;
                fout << "M6->f44: " << f44 << std::endl;
                fout << "M6->f45: " << f45 << std::endl;
                fout << "M6->f46: " << f46 << std::endl;
                fout << "M6->f47: " << f47 << std::endl;
                fout << "M6->f48: " << f48 << std::endl;
                fout << "M6->f49: " << f49 << std::endl;
                fout << "M6->f50: " << f50 << std::endl;
                fout << "M6->f51: " << f51 << std::endl;
                fout << "M6->f52: " << f52 << std::endl;
                fout << "M6->f53: " << f53 << std::endl;
                fout << "M6->f54: " << f54 << std::endl;
                fout << "M6->f55: " << f55 << std::endl;
                fout << "M6->f56: " << f56 << std::endl;
                fout << "M6->f57: " << f57 << std::endl;
                fout << "M6->f58: " << f58 << std::endl;
                fout << "M6->f59: " << f59 << std::endl;
                fout << "M6->f60: " << f60 << std::endl;
                fout << "M6->f61: " << f61 << std::endl;
                fout << "M6->f62: " << f62 << std::endl;
                fout << "M6->f63: " << f63 << std::endl;
                fout << "M6->f64: " << f64 << std::endl;
                if(f65 != nullptr)
                    f65->print_message(fout);
            }
        
            ~M6(){
                if(f65 != nullptr)
                    delete f65;
            }
        
            M6(){
               f65 = nullptr;
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
            alignas(8) int64_t f33;
            alignas(8) int64_t f34;
            alignas(8) int64_t f35;
            alignas(8) int64_t f36;
            alignas(8) int64_t f37;
            alignas(8) int64_t f38;
            alignas(8) int64_t f39;
            alignas(8) int64_t f40;
            alignas(8) int64_t f41;
            alignas(8) int64_t f42;
            alignas(8) int64_t f43;
            alignas(8) int64_t f44;
            alignas(8) int64_t f45;
            alignas(8) int64_t f46;
            alignas(8) int64_t f47;
            alignas(8) int64_t f48;
            alignas(8) int64_t f49;
            alignas(8) int64_t f50;
            alignas(8) int64_t f51;
            alignas(8) int64_t f52;
            alignas(8) int64_t f53;
            alignas(8) int64_t f54;
            alignas(8) int64_t f55;
            alignas(8) int64_t f56;
            alignas(8) int64_t f57;
            alignas(8) int64_t f58;
            alignas(8) int64_t f59;
            alignas(8) int64_t f60;
            alignas(8) int64_t f61;
            alignas(8) int64_t f62;
            alignas(8) int64_t f63;
            alignas(8) int64_t f64;
            alignas(8) M7* f65;
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
    
        inline void set_f33(int64_t val){
            f33 = val;
        }
        inline int64_t& get_f33(){
            return f33;
        }
    
        inline void set_f34(int64_t val){
            f34 = val;
        }
        inline int64_t& get_f34(){
            return f34;
        }
    
        inline void set_f35(int64_t val){
            f35 = val;
        }
        inline int64_t& get_f35(){
            return f35;
        }
    
        inline void set_f36(int64_t val){
            f36 = val;
        }
        inline int64_t& get_f36(){
            return f36;
        }
    
        inline void set_f37(int64_t val){
            f37 = val;
        }
        inline int64_t& get_f37(){
            return f37;
        }
    
        inline void set_f38(int64_t val){
            f38 = val;
        }
        inline int64_t& get_f38(){
            return f38;
        }
    
        inline void set_f39(int64_t val){
            f39 = val;
        }
        inline int64_t& get_f39(){
            return f39;
        }
    
        inline void set_f40(int64_t val){
            f40 = val;
        }
        inline int64_t& get_f40(){
            return f40;
        }
    
        inline void set_f41(int64_t val){
            f41 = val;
        }
        inline int64_t& get_f41(){
            return f41;
        }
    
        inline void set_f42(int64_t val){
            f42 = val;
        }
        inline int64_t& get_f42(){
            return f42;
        }
    
        inline void set_f43(int64_t val){
            f43 = val;
        }
        inline int64_t& get_f43(){
            return f43;
        }
    
        inline void set_f44(int64_t val){
            f44 = val;
        }
        inline int64_t& get_f44(){
            return f44;
        }
    
        inline void set_f45(int64_t val){
            f45 = val;
        }
        inline int64_t& get_f45(){
            return f45;
        }
    
        inline void set_f46(int64_t val){
            f46 = val;
        }
        inline int64_t& get_f46(){
            return f46;
        }
    
        inline void set_f47(int64_t val){
            f47 = val;
        }
        inline int64_t& get_f47(){
            return f47;
        }
    
        inline void set_f48(int64_t val){
            f48 = val;
        }
        inline int64_t& get_f48(){
            return f48;
        }
    
        inline void set_f49(int64_t val){
            f49 = val;
        }
        inline int64_t& get_f49(){
            return f49;
        }
    
        inline void set_f50(int64_t val){
            f50 = val;
        }
        inline int64_t& get_f50(){
            return f50;
        }
    
        inline void set_f51(int64_t val){
            f51 = val;
        }
        inline int64_t& get_f51(){
            return f51;
        }
    
        inline void set_f52(int64_t val){
            f52 = val;
        }
        inline int64_t& get_f52(){
            return f52;
        }
    
        inline void set_f53(int64_t val){
            f53 = val;
        }
        inline int64_t& get_f53(){
            return f53;
        }
    
        inline void set_f54(int64_t val){
            f54 = val;
        }
        inline int64_t& get_f54(){
            return f54;
        }
    
        inline void set_f55(int64_t val){
            f55 = val;
        }
        inline int64_t& get_f55(){
            return f55;
        }
    
        inline void set_f56(int64_t val){
            f56 = val;
        }
        inline int64_t& get_f56(){
            return f56;
        }
    
        inline void set_f57(int64_t val){
            f57 = val;
        }
        inline int64_t& get_f57(){
            return f57;
        }
    
        inline void set_f58(int64_t val){
            f58 = val;
        }
        inline int64_t& get_f58(){
            return f58;
        }
    
        inline void set_f59(int64_t val){
            f59 = val;
        }
        inline int64_t& get_f59(){
            return f59;
        }
    
        inline void set_f60(int64_t val){
            f60 = val;
        }
        inline int64_t& get_f60(){
            return f60;
        }
    
        inline void set_f61(int64_t val){
            f61 = val;
        }
        inline int64_t& get_f61(){
            return f61;
        }
    
        inline void set_f62(int64_t val){
            f62 = val;
        }
        inline int64_t& get_f62(){
            return f62;
        }
    
        inline void set_f63(int64_t val){
            f63 = val;
        }
        inline int64_t& get_f63(){
            return f63;
        }
    
        inline void set_f64(int64_t val){
            f64 = val;
        }
        inline int64_t& get_f64(){
            return f64;
        }
    
        inline M6* mutable_f65(){
            f65 = new M6();
            return f65;
        }
        inline M6*& get_f65(){
            return f65;
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
            fout << "M5->f33: " << f33 << std::endl;
            fout << "M5->f34: " << f34 << std::endl;
            fout << "M5->f35: " << f35 << std::endl;
            fout << "M5->f36: " << f36 << std::endl;
            fout << "M5->f37: " << f37 << std::endl;
            fout << "M5->f38: " << f38 << std::endl;
            fout << "M5->f39: " << f39 << std::endl;
            fout << "M5->f40: " << f40 << std::endl;
            fout << "M5->f41: " << f41 << std::endl;
            fout << "M5->f42: " << f42 << std::endl;
            fout << "M5->f43: " << f43 << std::endl;
            fout << "M5->f44: " << f44 << std::endl;
            fout << "M5->f45: " << f45 << std::endl;
            fout << "M5->f46: " << f46 << std::endl;
            fout << "M5->f47: " << f47 << std::endl;
            fout << "M5->f48: " << f48 << std::endl;
            fout << "M5->f49: " << f49 << std::endl;
            fout << "M5->f50: " << f50 << std::endl;
            fout << "M5->f51: " << f51 << std::endl;
            fout << "M5->f52: " << f52 << std::endl;
            fout << "M5->f53: " << f53 << std::endl;
            fout << "M5->f54: " << f54 << std::endl;
            fout << "M5->f55: " << f55 << std::endl;
            fout << "M5->f56: " << f56 << std::endl;
            fout << "M5->f57: " << f57 << std::endl;
            fout << "M5->f58: " << f58 << std::endl;
            fout << "M5->f59: " << f59 << std::endl;
            fout << "M5->f60: " << f60 << std::endl;
            fout << "M5->f61: " << f61 << std::endl;
            fout << "M5->f62: " << f62 << std::endl;
            fout << "M5->f63: " << f63 << std::endl;
            fout << "M5->f64: " << f64 << std::endl;
            if(f65 != nullptr)
                f65->print_message(fout);
        }
    
        ~M5(){
            if(f65 != nullptr)
                delete f65;
        }
    
        M5(){
           f65 = nullptr;
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
        alignas(8) int64_t f33;
        alignas(8) int64_t f34;
        alignas(8) int64_t f35;
        alignas(8) int64_t f36;
        alignas(8) int64_t f37;
        alignas(8) int64_t f38;
        alignas(8) int64_t f39;
        alignas(8) int64_t f40;
        alignas(8) int64_t f41;
        alignas(8) int64_t f42;
        alignas(8) int64_t f43;
        alignas(8) int64_t f44;
        alignas(8) int64_t f45;
        alignas(8) int64_t f46;
        alignas(8) int64_t f47;
        alignas(8) int64_t f48;
        alignas(8) int64_t f49;
        alignas(8) int64_t f50;
        alignas(8) int64_t f51;
        alignas(8) int64_t f52;
        alignas(8) int64_t f53;
        alignas(8) int64_t f54;
        alignas(8) int64_t f55;
        alignas(8) int64_t f56;
        alignas(8) int64_t f57;
        alignas(8) int64_t f58;
        alignas(8) int64_t f59;
        alignas(8) int64_t f60;
        alignas(8) int64_t f61;
        alignas(8) int64_t f62;
        alignas(8) int64_t f63;
        alignas(8) int64_t f64;
        alignas(8) M6* f65;
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

    inline void set_f33(int64_t val){
        f33 = val;
    }
    inline int64_t& get_f33(){
        return f33;
    }

    inline void set_f34(int64_t val){
        f34 = val;
    }
    inline int64_t& get_f34(){
        return f34;
    }

    inline void set_f35(int64_t val){
        f35 = val;
    }
    inline int64_t& get_f35(){
        return f35;
    }

    inline void set_f36(int64_t val){
        f36 = val;
    }
    inline int64_t& get_f36(){
        return f36;
    }

    inline void set_f37(int64_t val){
        f37 = val;
    }
    inline int64_t& get_f37(){
        return f37;
    }

    inline void set_f38(int64_t val){
        f38 = val;
    }
    inline int64_t& get_f38(){
        return f38;
    }

    inline void set_f39(int64_t val){
        f39 = val;
    }
    inline int64_t& get_f39(){
        return f39;
    }

    inline void set_f40(int64_t val){
        f40 = val;
    }
    inline int64_t& get_f40(){
        return f40;
    }

    inline void set_f41(int64_t val){
        f41 = val;
    }
    inline int64_t& get_f41(){
        return f41;
    }

    inline void set_f42(int64_t val){
        f42 = val;
    }
    inline int64_t& get_f42(){
        return f42;
    }

    inline void set_f43(int64_t val){
        f43 = val;
    }
    inline int64_t& get_f43(){
        return f43;
    }

    inline void set_f44(int64_t val){
        f44 = val;
    }
    inline int64_t& get_f44(){
        return f44;
    }

    inline void set_f45(int64_t val){
        f45 = val;
    }
    inline int64_t& get_f45(){
        return f45;
    }

    inline void set_f46(int64_t val){
        f46 = val;
    }
    inline int64_t& get_f46(){
        return f46;
    }

    inline void set_f47(int64_t val){
        f47 = val;
    }
    inline int64_t& get_f47(){
        return f47;
    }

    inline void set_f48(int64_t val){
        f48 = val;
    }
    inline int64_t& get_f48(){
        return f48;
    }

    inline void set_f49(int64_t val){
        f49 = val;
    }
    inline int64_t& get_f49(){
        return f49;
    }

    inline void set_f50(int64_t val){
        f50 = val;
    }
    inline int64_t& get_f50(){
        return f50;
    }

    inline void set_f51(int64_t val){
        f51 = val;
    }
    inline int64_t& get_f51(){
        return f51;
    }

    inline void set_f52(int64_t val){
        f52 = val;
    }
    inline int64_t& get_f52(){
        return f52;
    }

    inline void set_f53(int64_t val){
        f53 = val;
    }
    inline int64_t& get_f53(){
        return f53;
    }

    inline void set_f54(int64_t val){
        f54 = val;
    }
    inline int64_t& get_f54(){
        return f54;
    }

    inline void set_f55(int64_t val){
        f55 = val;
    }
    inline int64_t& get_f55(){
        return f55;
    }

    inline void set_f56(int64_t val){
        f56 = val;
    }
    inline int64_t& get_f56(){
        return f56;
    }

    inline void set_f57(int64_t val){
        f57 = val;
    }
    inline int64_t& get_f57(){
        return f57;
    }

    inline void set_f58(int64_t val){
        f58 = val;
    }
    inline int64_t& get_f58(){
        return f58;
    }

    inline void set_f59(int64_t val){
        f59 = val;
    }
    inline int64_t& get_f59(){
        return f59;
    }

    inline void set_f60(int64_t val){
        f60 = val;
    }
    inline int64_t& get_f60(){
        return f60;
    }

    inline void set_f61(int64_t val){
        f61 = val;
    }
    inline int64_t& get_f61(){
        return f61;
    }

    inline void set_f62(int64_t val){
        f62 = val;
    }
    inline int64_t& get_f62(){
        return f62;
    }

    inline void set_f63(int64_t val){
        f63 = val;
    }
    inline int64_t& get_f63(){
        return f63;
    }

    inline void set_f64(int64_t val){
        f64 = val;
    }
    inline int64_t& get_f64(){
        return f64;
    }

    inline M5* mutable_f65(){
        f65 = new M5();
        return f65;
    }
    inline M5*& get_f65(){
        return f65;
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
        fout << "M4->f33: " << f33 << std::endl;
        fout << "M4->f34: " << f34 << std::endl;
        fout << "M4->f35: " << f35 << std::endl;
        fout << "M4->f36: " << f36 << std::endl;
        fout << "M4->f37: " << f37 << std::endl;
        fout << "M4->f38: " << f38 << std::endl;
        fout << "M4->f39: " << f39 << std::endl;
        fout << "M4->f40: " << f40 << std::endl;
        fout << "M4->f41: " << f41 << std::endl;
        fout << "M4->f42: " << f42 << std::endl;
        fout << "M4->f43: " << f43 << std::endl;
        fout << "M4->f44: " << f44 << std::endl;
        fout << "M4->f45: " << f45 << std::endl;
        fout << "M4->f46: " << f46 << std::endl;
        fout << "M4->f47: " << f47 << std::endl;
        fout << "M4->f48: " << f48 << std::endl;
        fout << "M4->f49: " << f49 << std::endl;
        fout << "M4->f50: " << f50 << std::endl;
        fout << "M4->f51: " << f51 << std::endl;
        fout << "M4->f52: " << f52 << std::endl;
        fout << "M4->f53: " << f53 << std::endl;
        fout << "M4->f54: " << f54 << std::endl;
        fout << "M4->f55: " << f55 << std::endl;
        fout << "M4->f56: " << f56 << std::endl;
        fout << "M4->f57: " << f57 << std::endl;
        fout << "M4->f58: " << f58 << std::endl;
        fout << "M4->f59: " << f59 << std::endl;
        fout << "M4->f60: " << f60 << std::endl;
        fout << "M4->f61: " << f61 << std::endl;
        fout << "M4->f62: " << f62 << std::endl;
        fout << "M4->f63: " << f63 << std::endl;
        fout << "M4->f64: " << f64 << std::endl;
        if(f65 != nullptr)
            f65->print_message(fout);
    }

    ~M4(){
        if(f65 != nullptr)
            delete f65;
    }

    M4(){
       f65 = nullptr;
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
    alignas(8) int64_t f33;
    alignas(8) int64_t f34;
    alignas(8) int64_t f35;
    alignas(8) int64_t f36;
    alignas(8) int64_t f37;
    alignas(8) int64_t f38;
    alignas(8) int64_t f39;
    alignas(8) int64_t f40;
    alignas(8) int64_t f41;
    alignas(8) int64_t f42;
    alignas(8) int64_t f43;
    alignas(8) int64_t f44;
    alignas(8) int64_t f45;
    alignas(8) int64_t f46;
    alignas(8) int64_t f47;
    alignas(8) int64_t f48;
    alignas(8) int64_t f49;
    alignas(8) int64_t f50;
    alignas(8) int64_t f51;
    alignas(8) int64_t f52;
    alignas(8) int64_t f53;
    alignas(8) int64_t f54;
    alignas(8) int64_t f55;
    alignas(8) int64_t f56;
    alignas(8) int64_t f57;
    alignas(8) int64_t f58;
    alignas(8) int64_t f59;
    alignas(8) int64_t f60;
    alignas(8) int64_t f61;
    alignas(8) int64_t f62;
    alignas(8) int64_t f63;
    alignas(8) int64_t f64;
    alignas(8) M5* f65;
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
                            
                                inline void set_f33(int64_t val){
                                    f33 = val;
                                }
                                inline int64_t& get_f33(){
                                    return f33;
                                }
                            
                                inline void set_f34(int64_t val){
                                    f34 = val;
                                }
                                inline int64_t& get_f34(){
                                    return f34;
                                }
                            
                                inline void set_f35(int64_t val){
                                    f35 = val;
                                }
                                inline int64_t& get_f35(){
                                    return f35;
                                }
                            
                                inline void set_f36(int64_t val){
                                    f36 = val;
                                }
                                inline int64_t& get_f36(){
                                    return f36;
                                }
                            
                                inline void set_f37(int64_t val){
                                    f37 = val;
                                }
                                inline int64_t& get_f37(){
                                    return f37;
                                }
                            
                                inline void set_f38(int64_t val){
                                    f38 = val;
                                }
                                inline int64_t& get_f38(){
                                    return f38;
                                }
                            
                                inline void set_f39(int64_t val){
                                    f39 = val;
                                }
                                inline int64_t& get_f39(){
                                    return f39;
                                }
                            
                                inline void set_f40(int64_t val){
                                    f40 = val;
                                }
                                inline int64_t& get_f40(){
                                    return f40;
                                }
                            
                                inline void set_f41(int64_t val){
                                    f41 = val;
                                }
                                inline int64_t& get_f41(){
                                    return f41;
                                }
                            
                                inline void set_f42(int64_t val){
                                    f42 = val;
                                }
                                inline int64_t& get_f42(){
                                    return f42;
                                }
                            
                                inline void set_f43(int64_t val){
                                    f43 = val;
                                }
                                inline int64_t& get_f43(){
                                    return f43;
                                }
                            
                                inline void set_f44(int64_t val){
                                    f44 = val;
                                }
                                inline int64_t& get_f44(){
                                    return f44;
                                }
                            
                                inline void set_f45(int64_t val){
                                    f45 = val;
                                }
                                inline int64_t& get_f45(){
                                    return f45;
                                }
                            
                                inline void set_f46(int64_t val){
                                    f46 = val;
                                }
                                inline int64_t& get_f46(){
                                    return f46;
                                }
                            
                                inline void set_f47(int64_t val){
                                    f47 = val;
                                }
                                inline int64_t& get_f47(){
                                    return f47;
                                }
                            
                                inline void set_f48(int64_t val){
                                    f48 = val;
                                }
                                inline int64_t& get_f48(){
                                    return f48;
                                }
                            
                                inline void set_f49(int64_t val){
                                    f49 = val;
                                }
                                inline int64_t& get_f49(){
                                    return f49;
                                }
                            
                                inline void set_f50(int64_t val){
                                    f50 = val;
                                }
                                inline int64_t& get_f50(){
                                    return f50;
                                }
                            
                                inline void set_f51(int64_t val){
                                    f51 = val;
                                }
                                inline int64_t& get_f51(){
                                    return f51;
                                }
                            
                                inline void set_f52(int64_t val){
                                    f52 = val;
                                }
                                inline int64_t& get_f52(){
                                    return f52;
                                }
                            
                                inline void set_f53(int64_t val){
                                    f53 = val;
                                }
                                inline int64_t& get_f53(){
                                    return f53;
                                }
                            
                                inline void set_f54(int64_t val){
                                    f54 = val;
                                }
                                inline int64_t& get_f54(){
                                    return f54;
                                }
                            
                                inline void set_f55(int64_t val){
                                    f55 = val;
                                }
                                inline int64_t& get_f55(){
                                    return f55;
                                }
                            
                                inline void set_f56(int64_t val){
                                    f56 = val;
                                }
                                inline int64_t& get_f56(){
                                    return f56;
                                }
                            
                                inline void set_f57(int64_t val){
                                    f57 = val;
                                }
                                inline int64_t& get_f57(){
                                    return f57;
                                }
                            
                                inline void set_f58(int64_t val){
                                    f58 = val;
                                }
                                inline int64_t& get_f58(){
                                    return f58;
                                }
                            
                                inline void set_f59(int64_t val){
                                    f59 = val;
                                }
                                inline int64_t& get_f59(){
                                    return f59;
                                }
                            
                                inline void set_f60(int64_t val){
                                    f60 = val;
                                }
                                inline int64_t& get_f60(){
                                    return f60;
                                }
                            
                                inline void set_f61(int64_t val){
                                    f61 = val;
                                }
                                inline int64_t& get_f61(){
                                    return f61;
                                }
                            
                                inline void set_f62(int64_t val){
                                    f62 = val;
                                }
                                inline int64_t& get_f62(){
                                    return f62;
                                }
                            
                                inline void set_f63(int64_t val){
                                    f63 = val;
                                }
                                inline int64_t& get_f63(){
                                    return f63;
                                }
                            
                                inline void set_f64(int64_t val){
                                    f64 = val;
                                }
                                inline int64_t& get_f64(){
                                    return f64;
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
                                    fout << "M15->f33: " << f33 << std::endl;
                                    fout << "M15->f34: " << f34 << std::endl;
                                    fout << "M15->f35: " << f35 << std::endl;
                                    fout << "M15->f36: " << f36 << std::endl;
                                    fout << "M15->f37: " << f37 << std::endl;
                                    fout << "M15->f38: " << f38 << std::endl;
                                    fout << "M15->f39: " << f39 << std::endl;
                                    fout << "M15->f40: " << f40 << std::endl;
                                    fout << "M15->f41: " << f41 << std::endl;
                                    fout << "M15->f42: " << f42 << std::endl;
                                    fout << "M15->f43: " << f43 << std::endl;
                                    fout << "M15->f44: " << f44 << std::endl;
                                    fout << "M15->f45: " << f45 << std::endl;
                                    fout << "M15->f46: " << f46 << std::endl;
                                    fout << "M15->f47: " << f47 << std::endl;
                                    fout << "M15->f48: " << f48 << std::endl;
                                    fout << "M15->f49: " << f49 << std::endl;
                                    fout << "M15->f50: " << f50 << std::endl;
                                    fout << "M15->f51: " << f51 << std::endl;
                                    fout << "M15->f52: " << f52 << std::endl;
                                    fout << "M15->f53: " << f53 << std::endl;
                                    fout << "M15->f54: " << f54 << std::endl;
                                    fout << "M15->f55: " << f55 << std::endl;
                                    fout << "M15->f56: " << f56 << std::endl;
                                    fout << "M15->f57: " << f57 << std::endl;
                                    fout << "M15->f58: " << f58 << std::endl;
                                    fout << "M15->f59: " << f59 << std::endl;
                                    fout << "M15->f60: " << f60 << std::endl;
                                    fout << "M15->f61: " << f61 << std::endl;
                                    fout << "M15->f62: " << f62 << std::endl;
                                    fout << "M15->f63: " << f63 << std::endl;
                                    fout << "M15->f64: " << f64 << std::endl;
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
                                alignas(8) int64_t f33;
                                alignas(8) int64_t f34;
                                alignas(8) int64_t f35;
                                alignas(8) int64_t f36;
                                alignas(8) int64_t f37;
                                alignas(8) int64_t f38;
                                alignas(8) int64_t f39;
                                alignas(8) int64_t f40;
                                alignas(8) int64_t f41;
                                alignas(8) int64_t f42;
                                alignas(8) int64_t f43;
                                alignas(8) int64_t f44;
                                alignas(8) int64_t f45;
                                alignas(8) int64_t f46;
                                alignas(8) int64_t f47;
                                alignas(8) int64_t f48;
                                alignas(8) int64_t f49;
                                alignas(8) int64_t f50;
                                alignas(8) int64_t f51;
                                alignas(8) int64_t f52;
                                alignas(8) int64_t f53;
                                alignas(8) int64_t f54;
                                alignas(8) int64_t f55;
                                alignas(8) int64_t f56;
                                alignas(8) int64_t f57;
                                alignas(8) int64_t f58;
                                alignas(8) int64_t f59;
                                alignas(8) int64_t f60;
                                alignas(8) int64_t f61;
                                alignas(8) int64_t f62;
                                alignas(8) int64_t f63;
                                alignas(8) int64_t f64;
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
                        
                            inline void set_f33(int64_t val){
                                f33 = val;
                            }
                            inline int64_t& get_f33(){
                                return f33;
                            }
                        
                            inline void set_f34(int64_t val){
                                f34 = val;
                            }
                            inline int64_t& get_f34(){
                                return f34;
                            }
                        
                            inline void set_f35(int64_t val){
                                f35 = val;
                            }
                            inline int64_t& get_f35(){
                                return f35;
                            }
                        
                            inline void set_f36(int64_t val){
                                f36 = val;
                            }
                            inline int64_t& get_f36(){
                                return f36;
                            }
                        
                            inline void set_f37(int64_t val){
                                f37 = val;
                            }
                            inline int64_t& get_f37(){
                                return f37;
                            }
                        
                            inline void set_f38(int64_t val){
                                f38 = val;
                            }
                            inline int64_t& get_f38(){
                                return f38;
                            }
                        
                            inline void set_f39(int64_t val){
                                f39 = val;
                            }
                            inline int64_t& get_f39(){
                                return f39;
                            }
                        
                            inline void set_f40(int64_t val){
                                f40 = val;
                            }
                            inline int64_t& get_f40(){
                                return f40;
                            }
                        
                            inline void set_f41(int64_t val){
                                f41 = val;
                            }
                            inline int64_t& get_f41(){
                                return f41;
                            }
                        
                            inline void set_f42(int64_t val){
                                f42 = val;
                            }
                            inline int64_t& get_f42(){
                                return f42;
                            }
                        
                            inline void set_f43(int64_t val){
                                f43 = val;
                            }
                            inline int64_t& get_f43(){
                                return f43;
                            }
                        
                            inline void set_f44(int64_t val){
                                f44 = val;
                            }
                            inline int64_t& get_f44(){
                                return f44;
                            }
                        
                            inline void set_f45(int64_t val){
                                f45 = val;
                            }
                            inline int64_t& get_f45(){
                                return f45;
                            }
                        
                            inline void set_f46(int64_t val){
                                f46 = val;
                            }
                            inline int64_t& get_f46(){
                                return f46;
                            }
                        
                            inline void set_f47(int64_t val){
                                f47 = val;
                            }
                            inline int64_t& get_f47(){
                                return f47;
                            }
                        
                            inline void set_f48(int64_t val){
                                f48 = val;
                            }
                            inline int64_t& get_f48(){
                                return f48;
                            }
                        
                            inline void set_f49(int64_t val){
                                f49 = val;
                            }
                            inline int64_t& get_f49(){
                                return f49;
                            }
                        
                            inline void set_f50(int64_t val){
                                f50 = val;
                            }
                            inline int64_t& get_f50(){
                                return f50;
                            }
                        
                            inline void set_f51(int64_t val){
                                f51 = val;
                            }
                            inline int64_t& get_f51(){
                                return f51;
                            }
                        
                            inline void set_f52(int64_t val){
                                f52 = val;
                            }
                            inline int64_t& get_f52(){
                                return f52;
                            }
                        
                            inline void set_f53(int64_t val){
                                f53 = val;
                            }
                            inline int64_t& get_f53(){
                                return f53;
                            }
                        
                            inline void set_f54(int64_t val){
                                f54 = val;
                            }
                            inline int64_t& get_f54(){
                                return f54;
                            }
                        
                            inline void set_f55(int64_t val){
                                f55 = val;
                            }
                            inline int64_t& get_f55(){
                                return f55;
                            }
                        
                            inline void set_f56(int64_t val){
                                f56 = val;
                            }
                            inline int64_t& get_f56(){
                                return f56;
                            }
                        
                            inline void set_f57(int64_t val){
                                f57 = val;
                            }
                            inline int64_t& get_f57(){
                                return f57;
                            }
                        
                            inline void set_f58(int64_t val){
                                f58 = val;
                            }
                            inline int64_t& get_f58(){
                                return f58;
                            }
                        
                            inline void set_f59(int64_t val){
                                f59 = val;
                            }
                            inline int64_t& get_f59(){
                                return f59;
                            }
                        
                            inline void set_f60(int64_t val){
                                f60 = val;
                            }
                            inline int64_t& get_f60(){
                                return f60;
                            }
                        
                            inline void set_f61(int64_t val){
                                f61 = val;
                            }
                            inline int64_t& get_f61(){
                                return f61;
                            }
                        
                            inline void set_f62(int64_t val){
                                f62 = val;
                            }
                            inline int64_t& get_f62(){
                                return f62;
                            }
                        
                            inline void set_f63(int64_t val){
                                f63 = val;
                            }
                            inline int64_t& get_f63(){
                                return f63;
                            }
                        
                            inline void set_f64(int64_t val){
                                f64 = val;
                            }
                            inline int64_t& get_f64(){
                                return f64;
                            }
                        
                            inline M15* mutable_f65(){
                                f65 = new M15();
                                return f65;
                            }
                            inline M15*& get_f65(){
                                return f65;
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
                                fout << "M14->f33: " << f33 << std::endl;
                                fout << "M14->f34: " << f34 << std::endl;
                                fout << "M14->f35: " << f35 << std::endl;
                                fout << "M14->f36: " << f36 << std::endl;
                                fout << "M14->f37: " << f37 << std::endl;
                                fout << "M14->f38: " << f38 << std::endl;
                                fout << "M14->f39: " << f39 << std::endl;
                                fout << "M14->f40: " << f40 << std::endl;
                                fout << "M14->f41: " << f41 << std::endl;
                                fout << "M14->f42: " << f42 << std::endl;
                                fout << "M14->f43: " << f43 << std::endl;
                                fout << "M14->f44: " << f44 << std::endl;
                                fout << "M14->f45: " << f45 << std::endl;
                                fout << "M14->f46: " << f46 << std::endl;
                                fout << "M14->f47: " << f47 << std::endl;
                                fout << "M14->f48: " << f48 << std::endl;
                                fout << "M14->f49: " << f49 << std::endl;
                                fout << "M14->f50: " << f50 << std::endl;
                                fout << "M14->f51: " << f51 << std::endl;
                                fout << "M14->f52: " << f52 << std::endl;
                                fout << "M14->f53: " << f53 << std::endl;
                                fout << "M14->f54: " << f54 << std::endl;
                                fout << "M14->f55: " << f55 << std::endl;
                                fout << "M14->f56: " << f56 << std::endl;
                                fout << "M14->f57: " << f57 << std::endl;
                                fout << "M14->f58: " << f58 << std::endl;
                                fout << "M14->f59: " << f59 << std::endl;
                                fout << "M14->f60: " << f60 << std::endl;
                                fout << "M14->f61: " << f61 << std::endl;
                                fout << "M14->f62: " << f62 << std::endl;
                                fout << "M14->f63: " << f63 << std::endl;
                                fout << "M14->f64: " << f64 << std::endl;
                                if(f65 != nullptr)
                                    f65->print_message(fout);
                            }
                        
                            ~M14(){
                                if(f65 != nullptr)
                                    delete f65;
                            }
                        
                            M14(){
                               f65 = nullptr;
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
                            alignas(8) int64_t f33;
                            alignas(8) int64_t f34;
                            alignas(8) int64_t f35;
                            alignas(8) int64_t f36;
                            alignas(8) int64_t f37;
                            alignas(8) int64_t f38;
                            alignas(8) int64_t f39;
                            alignas(8) int64_t f40;
                            alignas(8) int64_t f41;
                            alignas(8) int64_t f42;
                            alignas(8) int64_t f43;
                            alignas(8) int64_t f44;
                            alignas(8) int64_t f45;
                            alignas(8) int64_t f46;
                            alignas(8) int64_t f47;
                            alignas(8) int64_t f48;
                            alignas(8) int64_t f49;
                            alignas(8) int64_t f50;
                            alignas(8) int64_t f51;
                            alignas(8) int64_t f52;
                            alignas(8) int64_t f53;
                            alignas(8) int64_t f54;
                            alignas(8) int64_t f55;
                            alignas(8) int64_t f56;
                            alignas(8) int64_t f57;
                            alignas(8) int64_t f58;
                            alignas(8) int64_t f59;
                            alignas(8) int64_t f60;
                            alignas(8) int64_t f61;
                            alignas(8) int64_t f62;
                            alignas(8) int64_t f63;
                            alignas(8) int64_t f64;
                            alignas(8) M15* f65;
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
                    
                        inline void set_f33(int64_t val){
                            f33 = val;
                        }
                        inline int64_t& get_f33(){
                            return f33;
                        }
                    
                        inline void set_f34(int64_t val){
                            f34 = val;
                        }
                        inline int64_t& get_f34(){
                            return f34;
                        }
                    
                        inline void set_f35(int64_t val){
                            f35 = val;
                        }
                        inline int64_t& get_f35(){
                            return f35;
                        }
                    
                        inline void set_f36(int64_t val){
                            f36 = val;
                        }
                        inline int64_t& get_f36(){
                            return f36;
                        }
                    
                        inline void set_f37(int64_t val){
                            f37 = val;
                        }
                        inline int64_t& get_f37(){
                            return f37;
                        }
                    
                        inline void set_f38(int64_t val){
                            f38 = val;
                        }
                        inline int64_t& get_f38(){
                            return f38;
                        }
                    
                        inline void set_f39(int64_t val){
                            f39 = val;
                        }
                        inline int64_t& get_f39(){
                            return f39;
                        }
                    
                        inline void set_f40(int64_t val){
                            f40 = val;
                        }
                        inline int64_t& get_f40(){
                            return f40;
                        }
                    
                        inline void set_f41(int64_t val){
                            f41 = val;
                        }
                        inline int64_t& get_f41(){
                            return f41;
                        }
                    
                        inline void set_f42(int64_t val){
                            f42 = val;
                        }
                        inline int64_t& get_f42(){
                            return f42;
                        }
                    
                        inline void set_f43(int64_t val){
                            f43 = val;
                        }
                        inline int64_t& get_f43(){
                            return f43;
                        }
                    
                        inline void set_f44(int64_t val){
                            f44 = val;
                        }
                        inline int64_t& get_f44(){
                            return f44;
                        }
                    
                        inline void set_f45(int64_t val){
                            f45 = val;
                        }
                        inline int64_t& get_f45(){
                            return f45;
                        }
                    
                        inline void set_f46(int64_t val){
                            f46 = val;
                        }
                        inline int64_t& get_f46(){
                            return f46;
                        }
                    
                        inline void set_f47(int64_t val){
                            f47 = val;
                        }
                        inline int64_t& get_f47(){
                            return f47;
                        }
                    
                        inline void set_f48(int64_t val){
                            f48 = val;
                        }
                        inline int64_t& get_f48(){
                            return f48;
                        }
                    
                        inline void set_f49(int64_t val){
                            f49 = val;
                        }
                        inline int64_t& get_f49(){
                            return f49;
                        }
                    
                        inline void set_f50(int64_t val){
                            f50 = val;
                        }
                        inline int64_t& get_f50(){
                            return f50;
                        }
                    
                        inline void set_f51(int64_t val){
                            f51 = val;
                        }
                        inline int64_t& get_f51(){
                            return f51;
                        }
                    
                        inline void set_f52(int64_t val){
                            f52 = val;
                        }
                        inline int64_t& get_f52(){
                            return f52;
                        }
                    
                        inline void set_f53(int64_t val){
                            f53 = val;
                        }
                        inline int64_t& get_f53(){
                            return f53;
                        }
                    
                        inline void set_f54(int64_t val){
                            f54 = val;
                        }
                        inline int64_t& get_f54(){
                            return f54;
                        }
                    
                        inline void set_f55(int64_t val){
                            f55 = val;
                        }
                        inline int64_t& get_f55(){
                            return f55;
                        }
                    
                        inline void set_f56(int64_t val){
                            f56 = val;
                        }
                        inline int64_t& get_f56(){
                            return f56;
                        }
                    
                        inline void set_f57(int64_t val){
                            f57 = val;
                        }
                        inline int64_t& get_f57(){
                            return f57;
                        }
                    
                        inline void set_f58(int64_t val){
                            f58 = val;
                        }
                        inline int64_t& get_f58(){
                            return f58;
                        }
                    
                        inline void set_f59(int64_t val){
                            f59 = val;
                        }
                        inline int64_t& get_f59(){
                            return f59;
                        }
                    
                        inline void set_f60(int64_t val){
                            f60 = val;
                        }
                        inline int64_t& get_f60(){
                            return f60;
                        }
                    
                        inline void set_f61(int64_t val){
                            f61 = val;
                        }
                        inline int64_t& get_f61(){
                            return f61;
                        }
                    
                        inline void set_f62(int64_t val){
                            f62 = val;
                        }
                        inline int64_t& get_f62(){
                            return f62;
                        }
                    
                        inline void set_f63(int64_t val){
                            f63 = val;
                        }
                        inline int64_t& get_f63(){
                            return f63;
                        }
                    
                        inline void set_f64(int64_t val){
                            f64 = val;
                        }
                        inline int64_t& get_f64(){
                            return f64;
                        }
                    
                        inline M14* mutable_f65(){
                            f65 = new M14();
                            return f65;
                        }
                        inline M14*& get_f65(){
                            return f65;
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
                            fout << "M13->f33: " << f33 << std::endl;
                            fout << "M13->f34: " << f34 << std::endl;
                            fout << "M13->f35: " << f35 << std::endl;
                            fout << "M13->f36: " << f36 << std::endl;
                            fout << "M13->f37: " << f37 << std::endl;
                            fout << "M13->f38: " << f38 << std::endl;
                            fout << "M13->f39: " << f39 << std::endl;
                            fout << "M13->f40: " << f40 << std::endl;
                            fout << "M13->f41: " << f41 << std::endl;
                            fout << "M13->f42: " << f42 << std::endl;
                            fout << "M13->f43: " << f43 << std::endl;
                            fout << "M13->f44: " << f44 << std::endl;
                            fout << "M13->f45: " << f45 << std::endl;
                            fout << "M13->f46: " << f46 << std::endl;
                            fout << "M13->f47: " << f47 << std::endl;
                            fout << "M13->f48: " << f48 << std::endl;
                            fout << "M13->f49: " << f49 << std::endl;
                            fout << "M13->f50: " << f50 << std::endl;
                            fout << "M13->f51: " << f51 << std::endl;
                            fout << "M13->f52: " << f52 << std::endl;
                            fout << "M13->f53: " << f53 << std::endl;
                            fout << "M13->f54: " << f54 << std::endl;
                            fout << "M13->f55: " << f55 << std::endl;
                            fout << "M13->f56: " << f56 << std::endl;
                            fout << "M13->f57: " << f57 << std::endl;
                            fout << "M13->f58: " << f58 << std::endl;
                            fout << "M13->f59: " << f59 << std::endl;
                            fout << "M13->f60: " << f60 << std::endl;
                            fout << "M13->f61: " << f61 << std::endl;
                            fout << "M13->f62: " << f62 << std::endl;
                            fout << "M13->f63: " << f63 << std::endl;
                            fout << "M13->f64: " << f64 << std::endl;
                            if(f65 != nullptr)
                                f65->print_message(fout);
                        }
                    
                        ~M13(){
                            if(f65 != nullptr)
                                delete f65;
                        }
                    
                        M13(){
                           f65 = nullptr;
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
                        alignas(8) int64_t f33;
                        alignas(8) int64_t f34;
                        alignas(8) int64_t f35;
                        alignas(8) int64_t f36;
                        alignas(8) int64_t f37;
                        alignas(8) int64_t f38;
                        alignas(8) int64_t f39;
                        alignas(8) int64_t f40;
                        alignas(8) int64_t f41;
                        alignas(8) int64_t f42;
                        alignas(8) int64_t f43;
                        alignas(8) int64_t f44;
                        alignas(8) int64_t f45;
                        alignas(8) int64_t f46;
                        alignas(8) int64_t f47;
                        alignas(8) int64_t f48;
                        alignas(8) int64_t f49;
                        alignas(8) int64_t f50;
                        alignas(8) int64_t f51;
                        alignas(8) int64_t f52;
                        alignas(8) int64_t f53;
                        alignas(8) int64_t f54;
                        alignas(8) int64_t f55;
                        alignas(8) int64_t f56;
                        alignas(8) int64_t f57;
                        alignas(8) int64_t f58;
                        alignas(8) int64_t f59;
                        alignas(8) int64_t f60;
                        alignas(8) int64_t f61;
                        alignas(8) int64_t f62;
                        alignas(8) int64_t f63;
                        alignas(8) int64_t f64;
                        alignas(8) M14* f65;
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
                
                    inline void set_f33(int64_t val){
                        f33 = val;
                    }
                    inline int64_t& get_f33(){
                        return f33;
                    }
                
                    inline void set_f34(int64_t val){
                        f34 = val;
                    }
                    inline int64_t& get_f34(){
                        return f34;
                    }
                
                    inline void set_f35(int64_t val){
                        f35 = val;
                    }
                    inline int64_t& get_f35(){
                        return f35;
                    }
                
                    inline void set_f36(int64_t val){
                        f36 = val;
                    }
                    inline int64_t& get_f36(){
                        return f36;
                    }
                
                    inline void set_f37(int64_t val){
                        f37 = val;
                    }
                    inline int64_t& get_f37(){
                        return f37;
                    }
                
                    inline void set_f38(int64_t val){
                        f38 = val;
                    }
                    inline int64_t& get_f38(){
                        return f38;
                    }
                
                    inline void set_f39(int64_t val){
                        f39 = val;
                    }
                    inline int64_t& get_f39(){
                        return f39;
                    }
                
                    inline void set_f40(int64_t val){
                        f40 = val;
                    }
                    inline int64_t& get_f40(){
                        return f40;
                    }
                
                    inline void set_f41(int64_t val){
                        f41 = val;
                    }
                    inline int64_t& get_f41(){
                        return f41;
                    }
                
                    inline void set_f42(int64_t val){
                        f42 = val;
                    }
                    inline int64_t& get_f42(){
                        return f42;
                    }
                
                    inline void set_f43(int64_t val){
                        f43 = val;
                    }
                    inline int64_t& get_f43(){
                        return f43;
                    }
                
                    inline void set_f44(int64_t val){
                        f44 = val;
                    }
                    inline int64_t& get_f44(){
                        return f44;
                    }
                
                    inline void set_f45(int64_t val){
                        f45 = val;
                    }
                    inline int64_t& get_f45(){
                        return f45;
                    }
                
                    inline void set_f46(int64_t val){
                        f46 = val;
                    }
                    inline int64_t& get_f46(){
                        return f46;
                    }
                
                    inline void set_f47(int64_t val){
                        f47 = val;
                    }
                    inline int64_t& get_f47(){
                        return f47;
                    }
                
                    inline void set_f48(int64_t val){
                        f48 = val;
                    }
                    inline int64_t& get_f48(){
                        return f48;
                    }
                
                    inline void set_f49(int64_t val){
                        f49 = val;
                    }
                    inline int64_t& get_f49(){
                        return f49;
                    }
                
                    inline void set_f50(int64_t val){
                        f50 = val;
                    }
                    inline int64_t& get_f50(){
                        return f50;
                    }
                
                    inline void set_f51(int64_t val){
                        f51 = val;
                    }
                    inline int64_t& get_f51(){
                        return f51;
                    }
                
                    inline void set_f52(int64_t val){
                        f52 = val;
                    }
                    inline int64_t& get_f52(){
                        return f52;
                    }
                
                    inline void set_f53(int64_t val){
                        f53 = val;
                    }
                    inline int64_t& get_f53(){
                        return f53;
                    }
                
                    inline void set_f54(int64_t val){
                        f54 = val;
                    }
                    inline int64_t& get_f54(){
                        return f54;
                    }
                
                    inline void set_f55(int64_t val){
                        f55 = val;
                    }
                    inline int64_t& get_f55(){
                        return f55;
                    }
                
                    inline void set_f56(int64_t val){
                        f56 = val;
                    }
                    inline int64_t& get_f56(){
                        return f56;
                    }
                
                    inline void set_f57(int64_t val){
                        f57 = val;
                    }
                    inline int64_t& get_f57(){
                        return f57;
                    }
                
                    inline void set_f58(int64_t val){
                        f58 = val;
                    }
                    inline int64_t& get_f58(){
                        return f58;
                    }
                
                    inline void set_f59(int64_t val){
                        f59 = val;
                    }
                    inline int64_t& get_f59(){
                        return f59;
                    }
                
                    inline void set_f60(int64_t val){
                        f60 = val;
                    }
                    inline int64_t& get_f60(){
                        return f60;
                    }
                
                    inline void set_f61(int64_t val){
                        f61 = val;
                    }
                    inline int64_t& get_f61(){
                        return f61;
                    }
                
                    inline void set_f62(int64_t val){
                        f62 = val;
                    }
                    inline int64_t& get_f62(){
                        return f62;
                    }
                
                    inline void set_f63(int64_t val){
                        f63 = val;
                    }
                    inline int64_t& get_f63(){
                        return f63;
                    }
                
                    inline void set_f64(int64_t val){
                        f64 = val;
                    }
                    inline int64_t& get_f64(){
                        return f64;
                    }
                
                    inline M13* mutable_f65(){
                        f65 = new M13();
                        return f65;
                    }
                    inline M13*& get_f65(){
                        return f65;
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
                        fout << "M12->f33: " << f33 << std::endl;
                        fout << "M12->f34: " << f34 << std::endl;
                        fout << "M12->f35: " << f35 << std::endl;
                        fout << "M12->f36: " << f36 << std::endl;
                        fout << "M12->f37: " << f37 << std::endl;
                        fout << "M12->f38: " << f38 << std::endl;
                        fout << "M12->f39: " << f39 << std::endl;
                        fout << "M12->f40: " << f40 << std::endl;
                        fout << "M12->f41: " << f41 << std::endl;
                        fout << "M12->f42: " << f42 << std::endl;
                        fout << "M12->f43: " << f43 << std::endl;
                        fout << "M12->f44: " << f44 << std::endl;
                        fout << "M12->f45: " << f45 << std::endl;
                        fout << "M12->f46: " << f46 << std::endl;
                        fout << "M12->f47: " << f47 << std::endl;
                        fout << "M12->f48: " << f48 << std::endl;
                        fout << "M12->f49: " << f49 << std::endl;
                        fout << "M12->f50: " << f50 << std::endl;
                        fout << "M12->f51: " << f51 << std::endl;
                        fout << "M12->f52: " << f52 << std::endl;
                        fout << "M12->f53: " << f53 << std::endl;
                        fout << "M12->f54: " << f54 << std::endl;
                        fout << "M12->f55: " << f55 << std::endl;
                        fout << "M12->f56: " << f56 << std::endl;
                        fout << "M12->f57: " << f57 << std::endl;
                        fout << "M12->f58: " << f58 << std::endl;
                        fout << "M12->f59: " << f59 << std::endl;
                        fout << "M12->f60: " << f60 << std::endl;
                        fout << "M12->f61: " << f61 << std::endl;
                        fout << "M12->f62: " << f62 << std::endl;
                        fout << "M12->f63: " << f63 << std::endl;
                        fout << "M12->f64: " << f64 << std::endl;
                        if(f65 != nullptr)
                            f65->print_message(fout);
                    }
                
                    ~M12(){
                        if(f65 != nullptr)
                            delete f65;
                    }
                
                    M12(){
                       f65 = nullptr;
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
                    alignas(8) int64_t f33;
                    alignas(8) int64_t f34;
                    alignas(8) int64_t f35;
                    alignas(8) int64_t f36;
                    alignas(8) int64_t f37;
                    alignas(8) int64_t f38;
                    alignas(8) int64_t f39;
                    alignas(8) int64_t f40;
                    alignas(8) int64_t f41;
                    alignas(8) int64_t f42;
                    alignas(8) int64_t f43;
                    alignas(8) int64_t f44;
                    alignas(8) int64_t f45;
                    alignas(8) int64_t f46;
                    alignas(8) int64_t f47;
                    alignas(8) int64_t f48;
                    alignas(8) int64_t f49;
                    alignas(8) int64_t f50;
                    alignas(8) int64_t f51;
                    alignas(8) int64_t f52;
                    alignas(8) int64_t f53;
                    alignas(8) int64_t f54;
                    alignas(8) int64_t f55;
                    alignas(8) int64_t f56;
                    alignas(8) int64_t f57;
                    alignas(8) int64_t f58;
                    alignas(8) int64_t f59;
                    alignas(8) int64_t f60;
                    alignas(8) int64_t f61;
                    alignas(8) int64_t f62;
                    alignas(8) int64_t f63;
                    alignas(8) int64_t f64;
                    alignas(8) M13* f65;
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
            
                inline void set_f33(int64_t val){
                    f33 = val;
                }
                inline int64_t& get_f33(){
                    return f33;
                }
            
                inline void set_f34(int64_t val){
                    f34 = val;
                }
                inline int64_t& get_f34(){
                    return f34;
                }
            
                inline void set_f35(int64_t val){
                    f35 = val;
                }
                inline int64_t& get_f35(){
                    return f35;
                }
            
                inline void set_f36(int64_t val){
                    f36 = val;
                }
                inline int64_t& get_f36(){
                    return f36;
                }
            
                inline void set_f37(int64_t val){
                    f37 = val;
                }
                inline int64_t& get_f37(){
                    return f37;
                }
            
                inline void set_f38(int64_t val){
                    f38 = val;
                }
                inline int64_t& get_f38(){
                    return f38;
                }
            
                inline void set_f39(int64_t val){
                    f39 = val;
                }
                inline int64_t& get_f39(){
                    return f39;
                }
            
                inline void set_f40(int64_t val){
                    f40 = val;
                }
                inline int64_t& get_f40(){
                    return f40;
                }
            
                inline void set_f41(int64_t val){
                    f41 = val;
                }
                inline int64_t& get_f41(){
                    return f41;
                }
            
                inline void set_f42(int64_t val){
                    f42 = val;
                }
                inline int64_t& get_f42(){
                    return f42;
                }
            
                inline void set_f43(int64_t val){
                    f43 = val;
                }
                inline int64_t& get_f43(){
                    return f43;
                }
            
                inline void set_f44(int64_t val){
                    f44 = val;
                }
                inline int64_t& get_f44(){
                    return f44;
                }
            
                inline void set_f45(int64_t val){
                    f45 = val;
                }
                inline int64_t& get_f45(){
                    return f45;
                }
            
                inline void set_f46(int64_t val){
                    f46 = val;
                }
                inline int64_t& get_f46(){
                    return f46;
                }
            
                inline void set_f47(int64_t val){
                    f47 = val;
                }
                inline int64_t& get_f47(){
                    return f47;
                }
            
                inline void set_f48(int64_t val){
                    f48 = val;
                }
                inline int64_t& get_f48(){
                    return f48;
                }
            
                inline void set_f49(int64_t val){
                    f49 = val;
                }
                inline int64_t& get_f49(){
                    return f49;
                }
            
                inline void set_f50(int64_t val){
                    f50 = val;
                }
                inline int64_t& get_f50(){
                    return f50;
                }
            
                inline void set_f51(int64_t val){
                    f51 = val;
                }
                inline int64_t& get_f51(){
                    return f51;
                }
            
                inline void set_f52(int64_t val){
                    f52 = val;
                }
                inline int64_t& get_f52(){
                    return f52;
                }
            
                inline void set_f53(int64_t val){
                    f53 = val;
                }
                inline int64_t& get_f53(){
                    return f53;
                }
            
                inline void set_f54(int64_t val){
                    f54 = val;
                }
                inline int64_t& get_f54(){
                    return f54;
                }
            
                inline void set_f55(int64_t val){
                    f55 = val;
                }
                inline int64_t& get_f55(){
                    return f55;
                }
            
                inline void set_f56(int64_t val){
                    f56 = val;
                }
                inline int64_t& get_f56(){
                    return f56;
                }
            
                inline void set_f57(int64_t val){
                    f57 = val;
                }
                inline int64_t& get_f57(){
                    return f57;
                }
            
                inline void set_f58(int64_t val){
                    f58 = val;
                }
                inline int64_t& get_f58(){
                    return f58;
                }
            
                inline void set_f59(int64_t val){
                    f59 = val;
                }
                inline int64_t& get_f59(){
                    return f59;
                }
            
                inline void set_f60(int64_t val){
                    f60 = val;
                }
                inline int64_t& get_f60(){
                    return f60;
                }
            
                inline void set_f61(int64_t val){
                    f61 = val;
                }
                inline int64_t& get_f61(){
                    return f61;
                }
            
                inline void set_f62(int64_t val){
                    f62 = val;
                }
                inline int64_t& get_f62(){
                    return f62;
                }
            
                inline void set_f63(int64_t val){
                    f63 = val;
                }
                inline int64_t& get_f63(){
                    return f63;
                }
            
                inline void set_f64(int64_t val){
                    f64 = val;
                }
                inline int64_t& get_f64(){
                    return f64;
                }
            
                inline M12* mutable_f65(){
                    f65 = new M12();
                    return f65;
                }
                inline M12*& get_f65(){
                    return f65;
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
                    fout << "M11->f33: " << f33 << std::endl;
                    fout << "M11->f34: " << f34 << std::endl;
                    fout << "M11->f35: " << f35 << std::endl;
                    fout << "M11->f36: " << f36 << std::endl;
                    fout << "M11->f37: " << f37 << std::endl;
                    fout << "M11->f38: " << f38 << std::endl;
                    fout << "M11->f39: " << f39 << std::endl;
                    fout << "M11->f40: " << f40 << std::endl;
                    fout << "M11->f41: " << f41 << std::endl;
                    fout << "M11->f42: " << f42 << std::endl;
                    fout << "M11->f43: " << f43 << std::endl;
                    fout << "M11->f44: " << f44 << std::endl;
                    fout << "M11->f45: " << f45 << std::endl;
                    fout << "M11->f46: " << f46 << std::endl;
                    fout << "M11->f47: " << f47 << std::endl;
                    fout << "M11->f48: " << f48 << std::endl;
                    fout << "M11->f49: " << f49 << std::endl;
                    fout << "M11->f50: " << f50 << std::endl;
                    fout << "M11->f51: " << f51 << std::endl;
                    fout << "M11->f52: " << f52 << std::endl;
                    fout << "M11->f53: " << f53 << std::endl;
                    fout << "M11->f54: " << f54 << std::endl;
                    fout << "M11->f55: " << f55 << std::endl;
                    fout << "M11->f56: " << f56 << std::endl;
                    fout << "M11->f57: " << f57 << std::endl;
                    fout << "M11->f58: " << f58 << std::endl;
                    fout << "M11->f59: " << f59 << std::endl;
                    fout << "M11->f60: " << f60 << std::endl;
                    fout << "M11->f61: " << f61 << std::endl;
                    fout << "M11->f62: " << f62 << std::endl;
                    fout << "M11->f63: " << f63 << std::endl;
                    fout << "M11->f64: " << f64 << std::endl;
                    if(f65 != nullptr)
                        f65->print_message(fout);
                }
            
                ~M11(){
                    if(f65 != nullptr)
                        delete f65;
                }
            
                M11(){
                   f65 = nullptr;
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
                alignas(8) int64_t f33;
                alignas(8) int64_t f34;
                alignas(8) int64_t f35;
                alignas(8) int64_t f36;
                alignas(8) int64_t f37;
                alignas(8) int64_t f38;
                alignas(8) int64_t f39;
                alignas(8) int64_t f40;
                alignas(8) int64_t f41;
                alignas(8) int64_t f42;
                alignas(8) int64_t f43;
                alignas(8) int64_t f44;
                alignas(8) int64_t f45;
                alignas(8) int64_t f46;
                alignas(8) int64_t f47;
                alignas(8) int64_t f48;
                alignas(8) int64_t f49;
                alignas(8) int64_t f50;
                alignas(8) int64_t f51;
                alignas(8) int64_t f52;
                alignas(8) int64_t f53;
                alignas(8) int64_t f54;
                alignas(8) int64_t f55;
                alignas(8) int64_t f56;
                alignas(8) int64_t f57;
                alignas(8) int64_t f58;
                alignas(8) int64_t f59;
                alignas(8) int64_t f60;
                alignas(8) int64_t f61;
                alignas(8) int64_t f62;
                alignas(8) int64_t f63;
                alignas(8) int64_t f64;
                alignas(8) M12* f65;
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
        
            inline void set_f33(int64_t val){
                f33 = val;
            }
            inline int64_t& get_f33(){
                return f33;
            }
        
            inline void set_f34(int64_t val){
                f34 = val;
            }
            inline int64_t& get_f34(){
                return f34;
            }
        
            inline void set_f35(int64_t val){
                f35 = val;
            }
            inline int64_t& get_f35(){
                return f35;
            }
        
            inline void set_f36(int64_t val){
                f36 = val;
            }
            inline int64_t& get_f36(){
                return f36;
            }
        
            inline void set_f37(int64_t val){
                f37 = val;
            }
            inline int64_t& get_f37(){
                return f37;
            }
        
            inline void set_f38(int64_t val){
                f38 = val;
            }
            inline int64_t& get_f38(){
                return f38;
            }
        
            inline void set_f39(int64_t val){
                f39 = val;
            }
            inline int64_t& get_f39(){
                return f39;
            }
        
            inline void set_f40(int64_t val){
                f40 = val;
            }
            inline int64_t& get_f40(){
                return f40;
            }
        
            inline void set_f41(int64_t val){
                f41 = val;
            }
            inline int64_t& get_f41(){
                return f41;
            }
        
            inline void set_f42(int64_t val){
                f42 = val;
            }
            inline int64_t& get_f42(){
                return f42;
            }
        
            inline void set_f43(int64_t val){
                f43 = val;
            }
            inline int64_t& get_f43(){
                return f43;
            }
        
            inline void set_f44(int64_t val){
                f44 = val;
            }
            inline int64_t& get_f44(){
                return f44;
            }
        
            inline void set_f45(int64_t val){
                f45 = val;
            }
            inline int64_t& get_f45(){
                return f45;
            }
        
            inline void set_f46(int64_t val){
                f46 = val;
            }
            inline int64_t& get_f46(){
                return f46;
            }
        
            inline void set_f47(int64_t val){
                f47 = val;
            }
            inline int64_t& get_f47(){
                return f47;
            }
        
            inline void set_f48(int64_t val){
                f48 = val;
            }
            inline int64_t& get_f48(){
                return f48;
            }
        
            inline void set_f49(int64_t val){
                f49 = val;
            }
            inline int64_t& get_f49(){
                return f49;
            }
        
            inline void set_f50(int64_t val){
                f50 = val;
            }
            inline int64_t& get_f50(){
                return f50;
            }
        
            inline void set_f51(int64_t val){
                f51 = val;
            }
            inline int64_t& get_f51(){
                return f51;
            }
        
            inline void set_f52(int64_t val){
                f52 = val;
            }
            inline int64_t& get_f52(){
                return f52;
            }
        
            inline void set_f53(int64_t val){
                f53 = val;
            }
            inline int64_t& get_f53(){
                return f53;
            }
        
            inline void set_f54(int64_t val){
                f54 = val;
            }
            inline int64_t& get_f54(){
                return f54;
            }
        
            inline void set_f55(int64_t val){
                f55 = val;
            }
            inline int64_t& get_f55(){
                return f55;
            }
        
            inline void set_f56(int64_t val){
                f56 = val;
            }
            inline int64_t& get_f56(){
                return f56;
            }
        
            inline void set_f57(int64_t val){
                f57 = val;
            }
            inline int64_t& get_f57(){
                return f57;
            }
        
            inline void set_f58(int64_t val){
                f58 = val;
            }
            inline int64_t& get_f58(){
                return f58;
            }
        
            inline void set_f59(int64_t val){
                f59 = val;
            }
            inline int64_t& get_f59(){
                return f59;
            }
        
            inline void set_f60(int64_t val){
                f60 = val;
            }
            inline int64_t& get_f60(){
                return f60;
            }
        
            inline void set_f61(int64_t val){
                f61 = val;
            }
            inline int64_t& get_f61(){
                return f61;
            }
        
            inline void set_f62(int64_t val){
                f62 = val;
            }
            inline int64_t& get_f62(){
                return f62;
            }
        
            inline void set_f63(int64_t val){
                f63 = val;
            }
            inline int64_t& get_f63(){
                return f63;
            }
        
            inline void set_f64(int64_t val){
                f64 = val;
            }
            inline int64_t& get_f64(){
                return f64;
            }
        
            inline M11* mutable_f65(){
                f65 = new M11();
                return f65;
            }
            inline M11*& get_f65(){
                return f65;
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
                fout << "M10->f33: " << f33 << std::endl;
                fout << "M10->f34: " << f34 << std::endl;
                fout << "M10->f35: " << f35 << std::endl;
                fout << "M10->f36: " << f36 << std::endl;
                fout << "M10->f37: " << f37 << std::endl;
                fout << "M10->f38: " << f38 << std::endl;
                fout << "M10->f39: " << f39 << std::endl;
                fout << "M10->f40: " << f40 << std::endl;
                fout << "M10->f41: " << f41 << std::endl;
                fout << "M10->f42: " << f42 << std::endl;
                fout << "M10->f43: " << f43 << std::endl;
                fout << "M10->f44: " << f44 << std::endl;
                fout << "M10->f45: " << f45 << std::endl;
                fout << "M10->f46: " << f46 << std::endl;
                fout << "M10->f47: " << f47 << std::endl;
                fout << "M10->f48: " << f48 << std::endl;
                fout << "M10->f49: " << f49 << std::endl;
                fout << "M10->f50: " << f50 << std::endl;
                fout << "M10->f51: " << f51 << std::endl;
                fout << "M10->f52: " << f52 << std::endl;
                fout << "M10->f53: " << f53 << std::endl;
                fout << "M10->f54: " << f54 << std::endl;
                fout << "M10->f55: " << f55 << std::endl;
                fout << "M10->f56: " << f56 << std::endl;
                fout << "M10->f57: " << f57 << std::endl;
                fout << "M10->f58: " << f58 << std::endl;
                fout << "M10->f59: " << f59 << std::endl;
                fout << "M10->f60: " << f60 << std::endl;
                fout << "M10->f61: " << f61 << std::endl;
                fout << "M10->f62: " << f62 << std::endl;
                fout << "M10->f63: " << f63 << std::endl;
                fout << "M10->f64: " << f64 << std::endl;
                if(f65 != nullptr)
                    f65->print_message(fout);
            }
        
            ~M10(){
                if(f65 != nullptr)
                    delete f65;
            }
        
            M10(){
               f65 = nullptr;
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
            alignas(8) int64_t f33;
            alignas(8) int64_t f34;
            alignas(8) int64_t f35;
            alignas(8) int64_t f36;
            alignas(8) int64_t f37;
            alignas(8) int64_t f38;
            alignas(8) int64_t f39;
            alignas(8) int64_t f40;
            alignas(8) int64_t f41;
            alignas(8) int64_t f42;
            alignas(8) int64_t f43;
            alignas(8) int64_t f44;
            alignas(8) int64_t f45;
            alignas(8) int64_t f46;
            alignas(8) int64_t f47;
            alignas(8) int64_t f48;
            alignas(8) int64_t f49;
            alignas(8) int64_t f50;
            alignas(8) int64_t f51;
            alignas(8) int64_t f52;
            alignas(8) int64_t f53;
            alignas(8) int64_t f54;
            alignas(8) int64_t f55;
            alignas(8) int64_t f56;
            alignas(8) int64_t f57;
            alignas(8) int64_t f58;
            alignas(8) int64_t f59;
            alignas(8) int64_t f60;
            alignas(8) int64_t f61;
            alignas(8) int64_t f62;
            alignas(8) int64_t f63;
            alignas(8) int64_t f64;
            alignas(8) M11* f65;
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
    
        inline void set_f33(int64_t val){
            f33 = val;
        }
        inline int64_t& get_f33(){
            return f33;
        }
    
        inline void set_f34(int64_t val){
            f34 = val;
        }
        inline int64_t& get_f34(){
            return f34;
        }
    
        inline void set_f35(int64_t val){
            f35 = val;
        }
        inline int64_t& get_f35(){
            return f35;
        }
    
        inline void set_f36(int64_t val){
            f36 = val;
        }
        inline int64_t& get_f36(){
            return f36;
        }
    
        inline void set_f37(int64_t val){
            f37 = val;
        }
        inline int64_t& get_f37(){
            return f37;
        }
    
        inline void set_f38(int64_t val){
            f38 = val;
        }
        inline int64_t& get_f38(){
            return f38;
        }
    
        inline void set_f39(int64_t val){
            f39 = val;
        }
        inline int64_t& get_f39(){
            return f39;
        }
    
        inline void set_f40(int64_t val){
            f40 = val;
        }
        inline int64_t& get_f40(){
            return f40;
        }
    
        inline void set_f41(int64_t val){
            f41 = val;
        }
        inline int64_t& get_f41(){
            return f41;
        }
    
        inline void set_f42(int64_t val){
            f42 = val;
        }
        inline int64_t& get_f42(){
            return f42;
        }
    
        inline void set_f43(int64_t val){
            f43 = val;
        }
        inline int64_t& get_f43(){
            return f43;
        }
    
        inline void set_f44(int64_t val){
            f44 = val;
        }
        inline int64_t& get_f44(){
            return f44;
        }
    
        inline void set_f45(int64_t val){
            f45 = val;
        }
        inline int64_t& get_f45(){
            return f45;
        }
    
        inline void set_f46(int64_t val){
            f46 = val;
        }
        inline int64_t& get_f46(){
            return f46;
        }
    
        inline void set_f47(int64_t val){
            f47 = val;
        }
        inline int64_t& get_f47(){
            return f47;
        }
    
        inline void set_f48(int64_t val){
            f48 = val;
        }
        inline int64_t& get_f48(){
            return f48;
        }
    
        inline void set_f49(int64_t val){
            f49 = val;
        }
        inline int64_t& get_f49(){
            return f49;
        }
    
        inline void set_f50(int64_t val){
            f50 = val;
        }
        inline int64_t& get_f50(){
            return f50;
        }
    
        inline void set_f51(int64_t val){
            f51 = val;
        }
        inline int64_t& get_f51(){
            return f51;
        }
    
        inline void set_f52(int64_t val){
            f52 = val;
        }
        inline int64_t& get_f52(){
            return f52;
        }
    
        inline void set_f53(int64_t val){
            f53 = val;
        }
        inline int64_t& get_f53(){
            return f53;
        }
    
        inline void set_f54(int64_t val){
            f54 = val;
        }
        inline int64_t& get_f54(){
            return f54;
        }
    
        inline void set_f55(int64_t val){
            f55 = val;
        }
        inline int64_t& get_f55(){
            return f55;
        }
    
        inline void set_f56(int64_t val){
            f56 = val;
        }
        inline int64_t& get_f56(){
            return f56;
        }
    
        inline void set_f57(int64_t val){
            f57 = val;
        }
        inline int64_t& get_f57(){
            return f57;
        }
    
        inline void set_f58(int64_t val){
            f58 = val;
        }
        inline int64_t& get_f58(){
            return f58;
        }
    
        inline void set_f59(int64_t val){
            f59 = val;
        }
        inline int64_t& get_f59(){
            return f59;
        }
    
        inline void set_f60(int64_t val){
            f60 = val;
        }
        inline int64_t& get_f60(){
            return f60;
        }
    
        inline void set_f61(int64_t val){
            f61 = val;
        }
        inline int64_t& get_f61(){
            return f61;
        }
    
        inline void set_f62(int64_t val){
            f62 = val;
        }
        inline int64_t& get_f62(){
            return f62;
        }
    
        inline void set_f63(int64_t val){
            f63 = val;
        }
        inline int64_t& get_f63(){
            return f63;
        }
    
        inline void set_f64(int64_t val){
            f64 = val;
        }
        inline int64_t& get_f64(){
            return f64;
        }
    
        inline M10* mutable_f65(){
            f65 = new M10();
            return f65;
        }
        inline M10*& get_f65(){
            return f65;
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
            fout << "M9->f33: " << f33 << std::endl;
            fout << "M9->f34: " << f34 << std::endl;
            fout << "M9->f35: " << f35 << std::endl;
            fout << "M9->f36: " << f36 << std::endl;
            fout << "M9->f37: " << f37 << std::endl;
            fout << "M9->f38: " << f38 << std::endl;
            fout << "M9->f39: " << f39 << std::endl;
            fout << "M9->f40: " << f40 << std::endl;
            fout << "M9->f41: " << f41 << std::endl;
            fout << "M9->f42: " << f42 << std::endl;
            fout << "M9->f43: " << f43 << std::endl;
            fout << "M9->f44: " << f44 << std::endl;
            fout << "M9->f45: " << f45 << std::endl;
            fout << "M9->f46: " << f46 << std::endl;
            fout << "M9->f47: " << f47 << std::endl;
            fout << "M9->f48: " << f48 << std::endl;
            fout << "M9->f49: " << f49 << std::endl;
            fout << "M9->f50: " << f50 << std::endl;
            fout << "M9->f51: " << f51 << std::endl;
            fout << "M9->f52: " << f52 << std::endl;
            fout << "M9->f53: " << f53 << std::endl;
            fout << "M9->f54: " << f54 << std::endl;
            fout << "M9->f55: " << f55 << std::endl;
            fout << "M9->f56: " << f56 << std::endl;
            fout << "M9->f57: " << f57 << std::endl;
            fout << "M9->f58: " << f58 << std::endl;
            fout << "M9->f59: " << f59 << std::endl;
            fout << "M9->f60: " << f60 << std::endl;
            fout << "M9->f61: " << f61 << std::endl;
            fout << "M9->f62: " << f62 << std::endl;
            fout << "M9->f63: " << f63 << std::endl;
            fout << "M9->f64: " << f64 << std::endl;
            if(f65 != nullptr)
                f65->print_message(fout);
        }
    
        ~M9(){
            if(f65 != nullptr)
                delete f65;
        }
    
        M9(){
           f65 = nullptr;
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
        alignas(8) int64_t f33;
        alignas(8) int64_t f34;
        alignas(8) int64_t f35;
        alignas(8) int64_t f36;
        alignas(8) int64_t f37;
        alignas(8) int64_t f38;
        alignas(8) int64_t f39;
        alignas(8) int64_t f40;
        alignas(8) int64_t f41;
        alignas(8) int64_t f42;
        alignas(8) int64_t f43;
        alignas(8) int64_t f44;
        alignas(8) int64_t f45;
        alignas(8) int64_t f46;
        alignas(8) int64_t f47;
        alignas(8) int64_t f48;
        alignas(8) int64_t f49;
        alignas(8) int64_t f50;
        alignas(8) int64_t f51;
        alignas(8) int64_t f52;
        alignas(8) int64_t f53;
        alignas(8) int64_t f54;
        alignas(8) int64_t f55;
        alignas(8) int64_t f56;
        alignas(8) int64_t f57;
        alignas(8) int64_t f58;
        alignas(8) int64_t f59;
        alignas(8) int64_t f60;
        alignas(8) int64_t f61;
        alignas(8) int64_t f62;
        alignas(8) int64_t f63;
        alignas(8) int64_t f64;
        alignas(8) M10* f65;
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

    inline void set_f33(int64_t val){
        f33 = val;
    }
    inline int64_t& get_f33(){
        return f33;
    }

    inline void set_f34(int64_t val){
        f34 = val;
    }
    inline int64_t& get_f34(){
        return f34;
    }

    inline void set_f35(int64_t val){
        f35 = val;
    }
    inline int64_t& get_f35(){
        return f35;
    }

    inline void set_f36(int64_t val){
        f36 = val;
    }
    inline int64_t& get_f36(){
        return f36;
    }

    inline void set_f37(int64_t val){
        f37 = val;
    }
    inline int64_t& get_f37(){
        return f37;
    }

    inline void set_f38(int64_t val){
        f38 = val;
    }
    inline int64_t& get_f38(){
        return f38;
    }

    inline void set_f39(int64_t val){
        f39 = val;
    }
    inline int64_t& get_f39(){
        return f39;
    }

    inline void set_f40(int64_t val){
        f40 = val;
    }
    inline int64_t& get_f40(){
        return f40;
    }

    inline void set_f41(int64_t val){
        f41 = val;
    }
    inline int64_t& get_f41(){
        return f41;
    }

    inline void set_f42(int64_t val){
        f42 = val;
    }
    inline int64_t& get_f42(){
        return f42;
    }

    inline void set_f43(int64_t val){
        f43 = val;
    }
    inline int64_t& get_f43(){
        return f43;
    }

    inline void set_f44(int64_t val){
        f44 = val;
    }
    inline int64_t& get_f44(){
        return f44;
    }

    inline void set_f45(int64_t val){
        f45 = val;
    }
    inline int64_t& get_f45(){
        return f45;
    }

    inline void set_f46(int64_t val){
        f46 = val;
    }
    inline int64_t& get_f46(){
        return f46;
    }

    inline void set_f47(int64_t val){
        f47 = val;
    }
    inline int64_t& get_f47(){
        return f47;
    }

    inline void set_f48(int64_t val){
        f48 = val;
    }
    inline int64_t& get_f48(){
        return f48;
    }

    inline void set_f49(int64_t val){
        f49 = val;
    }
    inline int64_t& get_f49(){
        return f49;
    }

    inline void set_f50(int64_t val){
        f50 = val;
    }
    inline int64_t& get_f50(){
        return f50;
    }

    inline void set_f51(int64_t val){
        f51 = val;
    }
    inline int64_t& get_f51(){
        return f51;
    }

    inline void set_f52(int64_t val){
        f52 = val;
    }
    inline int64_t& get_f52(){
        return f52;
    }

    inline void set_f53(int64_t val){
        f53 = val;
    }
    inline int64_t& get_f53(){
        return f53;
    }

    inline void set_f54(int64_t val){
        f54 = val;
    }
    inline int64_t& get_f54(){
        return f54;
    }

    inline void set_f55(int64_t val){
        f55 = val;
    }
    inline int64_t& get_f55(){
        return f55;
    }

    inline void set_f56(int64_t val){
        f56 = val;
    }
    inline int64_t& get_f56(){
        return f56;
    }

    inline void set_f57(int64_t val){
        f57 = val;
    }
    inline int64_t& get_f57(){
        return f57;
    }

    inline void set_f58(int64_t val){
        f58 = val;
    }
    inline int64_t& get_f58(){
        return f58;
    }

    inline void set_f59(int64_t val){
        f59 = val;
    }
    inline int64_t& get_f59(){
        return f59;
    }

    inline void set_f60(int64_t val){
        f60 = val;
    }
    inline int64_t& get_f60(){
        return f60;
    }

    inline void set_f61(int64_t val){
        f61 = val;
    }
    inline int64_t& get_f61(){
        return f61;
    }

    inline void set_f62(int64_t val){
        f62 = val;
    }
    inline int64_t& get_f62(){
        return f62;
    }

    inline void set_f63(int64_t val){
        f63 = val;
    }
    inline int64_t& get_f63(){
        return f63;
    }

    inline void set_f64(int64_t val){
        f64 = val;
    }
    inline int64_t& get_f64(){
        return f64;
    }

    inline M9* mutable_f65(){
        f65 = new M9();
        return f65;
    }
    inline M9*& get_f65(){
        return f65;
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
        fout << "M8->f33: " << f33 << std::endl;
        fout << "M8->f34: " << f34 << std::endl;
        fout << "M8->f35: " << f35 << std::endl;
        fout << "M8->f36: " << f36 << std::endl;
        fout << "M8->f37: " << f37 << std::endl;
        fout << "M8->f38: " << f38 << std::endl;
        fout << "M8->f39: " << f39 << std::endl;
        fout << "M8->f40: " << f40 << std::endl;
        fout << "M8->f41: " << f41 << std::endl;
        fout << "M8->f42: " << f42 << std::endl;
        fout << "M8->f43: " << f43 << std::endl;
        fout << "M8->f44: " << f44 << std::endl;
        fout << "M8->f45: " << f45 << std::endl;
        fout << "M8->f46: " << f46 << std::endl;
        fout << "M8->f47: " << f47 << std::endl;
        fout << "M8->f48: " << f48 << std::endl;
        fout << "M8->f49: " << f49 << std::endl;
        fout << "M8->f50: " << f50 << std::endl;
        fout << "M8->f51: " << f51 << std::endl;
        fout << "M8->f52: " << f52 << std::endl;
        fout << "M8->f53: " << f53 << std::endl;
        fout << "M8->f54: " << f54 << std::endl;
        fout << "M8->f55: " << f55 << std::endl;
        fout << "M8->f56: " << f56 << std::endl;
        fout << "M8->f57: " << f57 << std::endl;
        fout << "M8->f58: " << f58 << std::endl;
        fout << "M8->f59: " << f59 << std::endl;
        fout << "M8->f60: " << f60 << std::endl;
        fout << "M8->f61: " << f61 << std::endl;
        fout << "M8->f62: " << f62 << std::endl;
        fout << "M8->f63: " << f63 << std::endl;
        fout << "M8->f64: " << f64 << std::endl;
        if(f65 != nullptr)
            f65->print_message(fout);
    }

    ~M8(){
        if(f65 != nullptr)
            delete f65;
    }

    M8(){
       f65 = nullptr;
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
    alignas(8) int64_t f33;
    alignas(8) int64_t f34;
    alignas(8) int64_t f35;
    alignas(8) int64_t f36;
    alignas(8) int64_t f37;
    alignas(8) int64_t f38;
    alignas(8) int64_t f39;
    alignas(8) int64_t f40;
    alignas(8) int64_t f41;
    alignas(8) int64_t f42;
    alignas(8) int64_t f43;
    alignas(8) int64_t f44;
    alignas(8) int64_t f45;
    alignas(8) int64_t f46;
    alignas(8) int64_t f47;
    alignas(8) int64_t f48;
    alignas(8) int64_t f49;
    alignas(8) int64_t f50;
    alignas(8) int64_t f51;
    alignas(8) int64_t f52;
    alignas(8) int64_t f53;
    alignas(8) int64_t f54;
    alignas(8) int64_t f55;
    alignas(8) int64_t f56;
    alignas(8) int64_t f57;
    alignas(8) int64_t f58;
    alignas(8) int64_t f59;
    alignas(8) int64_t f60;
    alignas(8) int64_t f61;
    alignas(8) int64_t f62;
    alignas(8) int64_t f63;
    alignas(8) int64_t f64;
    alignas(8) M9* f65;
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
                                                            
                                                                inline void set_f33(int64_t val){
                                                                    f33 = val;
                                                                }
                                                                inline int64_t& get_f33(){
                                                                    return f33;
                                                                }
                                                            
                                                                inline void set_f34(int64_t val){
                                                                    f34 = val;
                                                                }
                                                                inline int64_t& get_f34(){
                                                                    return f34;
                                                                }
                                                            
                                                                inline void set_f35(int64_t val){
                                                                    f35 = val;
                                                                }
                                                                inline int64_t& get_f35(){
                                                                    return f35;
                                                                }
                                                            
                                                                inline void set_f36(int64_t val){
                                                                    f36 = val;
                                                                }
                                                                inline int64_t& get_f36(){
                                                                    return f36;
                                                                }
                                                            
                                                                inline void set_f37(int64_t val){
                                                                    f37 = val;
                                                                }
                                                                inline int64_t& get_f37(){
                                                                    return f37;
                                                                }
                                                            
                                                                inline void set_f38(int64_t val){
                                                                    f38 = val;
                                                                }
                                                                inline int64_t& get_f38(){
                                                                    return f38;
                                                                }
                                                            
                                                                inline void set_f39(int64_t val){
                                                                    f39 = val;
                                                                }
                                                                inline int64_t& get_f39(){
                                                                    return f39;
                                                                }
                                                            
                                                                inline void set_f40(int64_t val){
                                                                    f40 = val;
                                                                }
                                                                inline int64_t& get_f40(){
                                                                    return f40;
                                                                }
                                                            
                                                                inline void set_f41(int64_t val){
                                                                    f41 = val;
                                                                }
                                                                inline int64_t& get_f41(){
                                                                    return f41;
                                                                }
                                                            
                                                                inline void set_f42(int64_t val){
                                                                    f42 = val;
                                                                }
                                                                inline int64_t& get_f42(){
                                                                    return f42;
                                                                }
                                                            
                                                                inline void set_f43(int64_t val){
                                                                    f43 = val;
                                                                }
                                                                inline int64_t& get_f43(){
                                                                    return f43;
                                                                }
                                                            
                                                                inline void set_f44(int64_t val){
                                                                    f44 = val;
                                                                }
                                                                inline int64_t& get_f44(){
                                                                    return f44;
                                                                }
                                                            
                                                                inline void set_f45(int64_t val){
                                                                    f45 = val;
                                                                }
                                                                inline int64_t& get_f45(){
                                                                    return f45;
                                                                }
                                                            
                                                                inline void set_f46(int64_t val){
                                                                    f46 = val;
                                                                }
                                                                inline int64_t& get_f46(){
                                                                    return f46;
                                                                }
                                                            
                                                                inline void set_f47(int64_t val){
                                                                    f47 = val;
                                                                }
                                                                inline int64_t& get_f47(){
                                                                    return f47;
                                                                }
                                                            
                                                                inline void set_f48(int64_t val){
                                                                    f48 = val;
                                                                }
                                                                inline int64_t& get_f48(){
                                                                    return f48;
                                                                }
                                                            
                                                                inline void set_f49(int64_t val){
                                                                    f49 = val;
                                                                }
                                                                inline int64_t& get_f49(){
                                                                    return f49;
                                                                }
                                                            
                                                                inline void set_f50(int64_t val){
                                                                    f50 = val;
                                                                }
                                                                inline int64_t& get_f50(){
                                                                    return f50;
                                                                }
                                                            
                                                                inline void set_f51(int64_t val){
                                                                    f51 = val;
                                                                }
                                                                inline int64_t& get_f51(){
                                                                    return f51;
                                                                }
                                                            
                                                                inline void set_f52(int64_t val){
                                                                    f52 = val;
                                                                }
                                                                inline int64_t& get_f52(){
                                                                    return f52;
                                                                }
                                                            
                                                                inline void set_f53(int64_t val){
                                                                    f53 = val;
                                                                }
                                                                inline int64_t& get_f53(){
                                                                    return f53;
                                                                }
                                                            
                                                                inline void set_f54(int64_t val){
                                                                    f54 = val;
                                                                }
                                                                inline int64_t& get_f54(){
                                                                    return f54;
                                                                }
                                                            
                                                                inline void set_f55(int64_t val){
                                                                    f55 = val;
                                                                }
                                                                inline int64_t& get_f55(){
                                                                    return f55;
                                                                }
                                                            
                                                                inline void set_f56(int64_t val){
                                                                    f56 = val;
                                                                }
                                                                inline int64_t& get_f56(){
                                                                    return f56;
                                                                }
                                                            
                                                                inline void set_f57(int64_t val){
                                                                    f57 = val;
                                                                }
                                                                inline int64_t& get_f57(){
                                                                    return f57;
                                                                }
                                                            
                                                                inline void set_f58(int64_t val){
                                                                    f58 = val;
                                                                }
                                                                inline int64_t& get_f58(){
                                                                    return f58;
                                                                }
                                                            
                                                                inline void set_f59(int64_t val){
                                                                    f59 = val;
                                                                }
                                                                inline int64_t& get_f59(){
                                                                    return f59;
                                                                }
                                                            
                                                                inline void set_f60(int64_t val){
                                                                    f60 = val;
                                                                }
                                                                inline int64_t& get_f60(){
                                                                    return f60;
                                                                }
                                                            
                                                                inline void set_f61(int64_t val){
                                                                    f61 = val;
                                                                }
                                                                inline int64_t& get_f61(){
                                                                    return f61;
                                                                }
                                                            
                                                                inline void set_f62(int64_t val){
                                                                    f62 = val;
                                                                }
                                                                inline int64_t& get_f62(){
                                                                    return f62;
                                                                }
                                                            
                                                                inline void set_f63(int64_t val){
                                                                    f63 = val;
                                                                }
                                                                inline int64_t& get_f63(){
                                                                    return f63;
                                                                }
                                                            
                                                                inline void set_f64(int64_t val){
                                                                    f64 = val;
                                                                }
                                                                inline int64_t& get_f64(){
                                                                    return f64;
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
                                                                    fout << "M31->f33: " << f33 << std::endl;
                                                                    fout << "M31->f34: " << f34 << std::endl;
                                                                    fout << "M31->f35: " << f35 << std::endl;
                                                                    fout << "M31->f36: " << f36 << std::endl;
                                                                    fout << "M31->f37: " << f37 << std::endl;
                                                                    fout << "M31->f38: " << f38 << std::endl;
                                                                    fout << "M31->f39: " << f39 << std::endl;
                                                                    fout << "M31->f40: " << f40 << std::endl;
                                                                    fout << "M31->f41: " << f41 << std::endl;
                                                                    fout << "M31->f42: " << f42 << std::endl;
                                                                    fout << "M31->f43: " << f43 << std::endl;
                                                                    fout << "M31->f44: " << f44 << std::endl;
                                                                    fout << "M31->f45: " << f45 << std::endl;
                                                                    fout << "M31->f46: " << f46 << std::endl;
                                                                    fout << "M31->f47: " << f47 << std::endl;
                                                                    fout << "M31->f48: " << f48 << std::endl;
                                                                    fout << "M31->f49: " << f49 << std::endl;
                                                                    fout << "M31->f50: " << f50 << std::endl;
                                                                    fout << "M31->f51: " << f51 << std::endl;
                                                                    fout << "M31->f52: " << f52 << std::endl;
                                                                    fout << "M31->f53: " << f53 << std::endl;
                                                                    fout << "M31->f54: " << f54 << std::endl;
                                                                    fout << "M31->f55: " << f55 << std::endl;
                                                                    fout << "M31->f56: " << f56 << std::endl;
                                                                    fout << "M31->f57: " << f57 << std::endl;
                                                                    fout << "M31->f58: " << f58 << std::endl;
                                                                    fout << "M31->f59: " << f59 << std::endl;
                                                                    fout << "M31->f60: " << f60 << std::endl;
                                                                    fout << "M31->f61: " << f61 << std::endl;
                                                                    fout << "M31->f62: " << f62 << std::endl;
                                                                    fout << "M31->f63: " << f63 << std::endl;
                                                                    fout << "M31->f64: " << f64 << std::endl;
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
                                                                alignas(8) int64_t f33;
                                                                alignas(8) int64_t f34;
                                                                alignas(8) int64_t f35;
                                                                alignas(8) int64_t f36;
                                                                alignas(8) int64_t f37;
                                                                alignas(8) int64_t f38;
                                                                alignas(8) int64_t f39;
                                                                alignas(8) int64_t f40;
                                                                alignas(8) int64_t f41;
                                                                alignas(8) int64_t f42;
                                                                alignas(8) int64_t f43;
                                                                alignas(8) int64_t f44;
                                                                alignas(8) int64_t f45;
                                                                alignas(8) int64_t f46;
                                                                alignas(8) int64_t f47;
                                                                alignas(8) int64_t f48;
                                                                alignas(8) int64_t f49;
                                                                alignas(8) int64_t f50;
                                                                alignas(8) int64_t f51;
                                                                alignas(8) int64_t f52;
                                                                alignas(8) int64_t f53;
                                                                alignas(8) int64_t f54;
                                                                alignas(8) int64_t f55;
                                                                alignas(8) int64_t f56;
                                                                alignas(8) int64_t f57;
                                                                alignas(8) int64_t f58;
                                                                alignas(8) int64_t f59;
                                                                alignas(8) int64_t f60;
                                                                alignas(8) int64_t f61;
                                                                alignas(8) int64_t f62;
                                                                alignas(8) int64_t f63;
                                                                alignas(8) int64_t f64;
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
                                                        
                                                            inline void set_f33(int64_t val){
                                                                f33 = val;
                                                            }
                                                            inline int64_t& get_f33(){
                                                                return f33;
                                                            }
                                                        
                                                            inline void set_f34(int64_t val){
                                                                f34 = val;
                                                            }
                                                            inline int64_t& get_f34(){
                                                                return f34;
                                                            }
                                                        
                                                            inline void set_f35(int64_t val){
                                                                f35 = val;
                                                            }
                                                            inline int64_t& get_f35(){
                                                                return f35;
                                                            }
                                                        
                                                            inline void set_f36(int64_t val){
                                                                f36 = val;
                                                            }
                                                            inline int64_t& get_f36(){
                                                                return f36;
                                                            }
                                                        
                                                            inline void set_f37(int64_t val){
                                                                f37 = val;
                                                            }
                                                            inline int64_t& get_f37(){
                                                                return f37;
                                                            }
                                                        
                                                            inline void set_f38(int64_t val){
                                                                f38 = val;
                                                            }
                                                            inline int64_t& get_f38(){
                                                                return f38;
                                                            }
                                                        
                                                            inline void set_f39(int64_t val){
                                                                f39 = val;
                                                            }
                                                            inline int64_t& get_f39(){
                                                                return f39;
                                                            }
                                                        
                                                            inline void set_f40(int64_t val){
                                                                f40 = val;
                                                            }
                                                            inline int64_t& get_f40(){
                                                                return f40;
                                                            }
                                                        
                                                            inline void set_f41(int64_t val){
                                                                f41 = val;
                                                            }
                                                            inline int64_t& get_f41(){
                                                                return f41;
                                                            }
                                                        
                                                            inline void set_f42(int64_t val){
                                                                f42 = val;
                                                            }
                                                            inline int64_t& get_f42(){
                                                                return f42;
                                                            }
                                                        
                                                            inline void set_f43(int64_t val){
                                                                f43 = val;
                                                            }
                                                            inline int64_t& get_f43(){
                                                                return f43;
                                                            }
                                                        
                                                            inline void set_f44(int64_t val){
                                                                f44 = val;
                                                            }
                                                            inline int64_t& get_f44(){
                                                                return f44;
                                                            }
                                                        
                                                            inline void set_f45(int64_t val){
                                                                f45 = val;
                                                            }
                                                            inline int64_t& get_f45(){
                                                                return f45;
                                                            }
                                                        
                                                            inline void set_f46(int64_t val){
                                                                f46 = val;
                                                            }
                                                            inline int64_t& get_f46(){
                                                                return f46;
                                                            }
                                                        
                                                            inline void set_f47(int64_t val){
                                                                f47 = val;
                                                            }
                                                            inline int64_t& get_f47(){
                                                                return f47;
                                                            }
                                                        
                                                            inline void set_f48(int64_t val){
                                                                f48 = val;
                                                            }
                                                            inline int64_t& get_f48(){
                                                                return f48;
                                                            }
                                                        
                                                            inline void set_f49(int64_t val){
                                                                f49 = val;
                                                            }
                                                            inline int64_t& get_f49(){
                                                                return f49;
                                                            }
                                                        
                                                            inline void set_f50(int64_t val){
                                                                f50 = val;
                                                            }
                                                            inline int64_t& get_f50(){
                                                                return f50;
                                                            }
                                                        
                                                            inline void set_f51(int64_t val){
                                                                f51 = val;
                                                            }
                                                            inline int64_t& get_f51(){
                                                                return f51;
                                                            }
                                                        
                                                            inline void set_f52(int64_t val){
                                                                f52 = val;
                                                            }
                                                            inline int64_t& get_f52(){
                                                                return f52;
                                                            }
                                                        
                                                            inline void set_f53(int64_t val){
                                                                f53 = val;
                                                            }
                                                            inline int64_t& get_f53(){
                                                                return f53;
                                                            }
                                                        
                                                            inline void set_f54(int64_t val){
                                                                f54 = val;
                                                            }
                                                            inline int64_t& get_f54(){
                                                                return f54;
                                                            }
                                                        
                                                            inline void set_f55(int64_t val){
                                                                f55 = val;
                                                            }
                                                            inline int64_t& get_f55(){
                                                                return f55;
                                                            }
                                                        
                                                            inline void set_f56(int64_t val){
                                                                f56 = val;
                                                            }
                                                            inline int64_t& get_f56(){
                                                                return f56;
                                                            }
                                                        
                                                            inline void set_f57(int64_t val){
                                                                f57 = val;
                                                            }
                                                            inline int64_t& get_f57(){
                                                                return f57;
                                                            }
                                                        
                                                            inline void set_f58(int64_t val){
                                                                f58 = val;
                                                            }
                                                            inline int64_t& get_f58(){
                                                                return f58;
                                                            }
                                                        
                                                            inline void set_f59(int64_t val){
                                                                f59 = val;
                                                            }
                                                            inline int64_t& get_f59(){
                                                                return f59;
                                                            }
                                                        
                                                            inline void set_f60(int64_t val){
                                                                f60 = val;
                                                            }
                                                            inline int64_t& get_f60(){
                                                                return f60;
                                                            }
                                                        
                                                            inline void set_f61(int64_t val){
                                                                f61 = val;
                                                            }
                                                            inline int64_t& get_f61(){
                                                                return f61;
                                                            }
                                                        
                                                            inline void set_f62(int64_t val){
                                                                f62 = val;
                                                            }
                                                            inline int64_t& get_f62(){
                                                                return f62;
                                                            }
                                                        
                                                            inline void set_f63(int64_t val){
                                                                f63 = val;
                                                            }
                                                            inline int64_t& get_f63(){
                                                                return f63;
                                                            }
                                                        
                                                            inline void set_f64(int64_t val){
                                                                f64 = val;
                                                            }
                                                            inline int64_t& get_f64(){
                                                                return f64;
                                                            }
                                                        
                                                            inline M31* mutable_f65(){
                                                                f65 = new M31();
                                                                return f65;
                                                            }
                                                            inline M31*& get_f65(){
                                                                return f65;
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
                                                                fout << "M30->f33: " << f33 << std::endl;
                                                                fout << "M30->f34: " << f34 << std::endl;
                                                                fout << "M30->f35: " << f35 << std::endl;
                                                                fout << "M30->f36: " << f36 << std::endl;
                                                                fout << "M30->f37: " << f37 << std::endl;
                                                                fout << "M30->f38: " << f38 << std::endl;
                                                                fout << "M30->f39: " << f39 << std::endl;
                                                                fout << "M30->f40: " << f40 << std::endl;
                                                                fout << "M30->f41: " << f41 << std::endl;
                                                                fout << "M30->f42: " << f42 << std::endl;
                                                                fout << "M30->f43: " << f43 << std::endl;
                                                                fout << "M30->f44: " << f44 << std::endl;
                                                                fout << "M30->f45: " << f45 << std::endl;
                                                                fout << "M30->f46: " << f46 << std::endl;
                                                                fout << "M30->f47: " << f47 << std::endl;
                                                                fout << "M30->f48: " << f48 << std::endl;
                                                                fout << "M30->f49: " << f49 << std::endl;
                                                                fout << "M30->f50: " << f50 << std::endl;
                                                                fout << "M30->f51: " << f51 << std::endl;
                                                                fout << "M30->f52: " << f52 << std::endl;
                                                                fout << "M30->f53: " << f53 << std::endl;
                                                                fout << "M30->f54: " << f54 << std::endl;
                                                                fout << "M30->f55: " << f55 << std::endl;
                                                                fout << "M30->f56: " << f56 << std::endl;
                                                                fout << "M30->f57: " << f57 << std::endl;
                                                                fout << "M30->f58: " << f58 << std::endl;
                                                                fout << "M30->f59: " << f59 << std::endl;
                                                                fout << "M30->f60: " << f60 << std::endl;
                                                                fout << "M30->f61: " << f61 << std::endl;
                                                                fout << "M30->f62: " << f62 << std::endl;
                                                                fout << "M30->f63: " << f63 << std::endl;
                                                                fout << "M30->f64: " << f64 << std::endl;
                                                                if(f65 != nullptr)
                                                                    f65->print_message(fout);
                                                            }
                                                        
                                                            ~M30(){
                                                                if(f65 != nullptr)
                                                                    delete f65;
                                                            }
                                                        
                                                            M30(){
                                                               f65 = nullptr;
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
                                                            alignas(8) int64_t f33;
                                                            alignas(8) int64_t f34;
                                                            alignas(8) int64_t f35;
                                                            alignas(8) int64_t f36;
                                                            alignas(8) int64_t f37;
                                                            alignas(8) int64_t f38;
                                                            alignas(8) int64_t f39;
                                                            alignas(8) int64_t f40;
                                                            alignas(8) int64_t f41;
                                                            alignas(8) int64_t f42;
                                                            alignas(8) int64_t f43;
                                                            alignas(8) int64_t f44;
                                                            alignas(8) int64_t f45;
                                                            alignas(8) int64_t f46;
                                                            alignas(8) int64_t f47;
                                                            alignas(8) int64_t f48;
                                                            alignas(8) int64_t f49;
                                                            alignas(8) int64_t f50;
                                                            alignas(8) int64_t f51;
                                                            alignas(8) int64_t f52;
                                                            alignas(8) int64_t f53;
                                                            alignas(8) int64_t f54;
                                                            alignas(8) int64_t f55;
                                                            alignas(8) int64_t f56;
                                                            alignas(8) int64_t f57;
                                                            alignas(8) int64_t f58;
                                                            alignas(8) int64_t f59;
                                                            alignas(8) int64_t f60;
                                                            alignas(8) int64_t f61;
                                                            alignas(8) int64_t f62;
                                                            alignas(8) int64_t f63;
                                                            alignas(8) int64_t f64;
                                                            alignas(8) M31* f65;
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
                                                    
                                                        inline void set_f33(int64_t val){
                                                            f33 = val;
                                                        }
                                                        inline int64_t& get_f33(){
                                                            return f33;
                                                        }
                                                    
                                                        inline void set_f34(int64_t val){
                                                            f34 = val;
                                                        }
                                                        inline int64_t& get_f34(){
                                                            return f34;
                                                        }
                                                    
                                                        inline void set_f35(int64_t val){
                                                            f35 = val;
                                                        }
                                                        inline int64_t& get_f35(){
                                                            return f35;
                                                        }
                                                    
                                                        inline void set_f36(int64_t val){
                                                            f36 = val;
                                                        }
                                                        inline int64_t& get_f36(){
                                                            return f36;
                                                        }
                                                    
                                                        inline void set_f37(int64_t val){
                                                            f37 = val;
                                                        }
                                                        inline int64_t& get_f37(){
                                                            return f37;
                                                        }
                                                    
                                                        inline void set_f38(int64_t val){
                                                            f38 = val;
                                                        }
                                                        inline int64_t& get_f38(){
                                                            return f38;
                                                        }
                                                    
                                                        inline void set_f39(int64_t val){
                                                            f39 = val;
                                                        }
                                                        inline int64_t& get_f39(){
                                                            return f39;
                                                        }
                                                    
                                                        inline void set_f40(int64_t val){
                                                            f40 = val;
                                                        }
                                                        inline int64_t& get_f40(){
                                                            return f40;
                                                        }
                                                    
                                                        inline void set_f41(int64_t val){
                                                            f41 = val;
                                                        }
                                                        inline int64_t& get_f41(){
                                                            return f41;
                                                        }
                                                    
                                                        inline void set_f42(int64_t val){
                                                            f42 = val;
                                                        }
                                                        inline int64_t& get_f42(){
                                                            return f42;
                                                        }
                                                    
                                                        inline void set_f43(int64_t val){
                                                            f43 = val;
                                                        }
                                                        inline int64_t& get_f43(){
                                                            return f43;
                                                        }
                                                    
                                                        inline void set_f44(int64_t val){
                                                            f44 = val;
                                                        }
                                                        inline int64_t& get_f44(){
                                                            return f44;
                                                        }
                                                    
                                                        inline void set_f45(int64_t val){
                                                            f45 = val;
                                                        }
                                                        inline int64_t& get_f45(){
                                                            return f45;
                                                        }
                                                    
                                                        inline void set_f46(int64_t val){
                                                            f46 = val;
                                                        }
                                                        inline int64_t& get_f46(){
                                                            return f46;
                                                        }
                                                    
                                                        inline void set_f47(int64_t val){
                                                            f47 = val;
                                                        }
                                                        inline int64_t& get_f47(){
                                                            return f47;
                                                        }
                                                    
                                                        inline void set_f48(int64_t val){
                                                            f48 = val;
                                                        }
                                                        inline int64_t& get_f48(){
                                                            return f48;
                                                        }
                                                    
                                                        inline void set_f49(int64_t val){
                                                            f49 = val;
                                                        }
                                                        inline int64_t& get_f49(){
                                                            return f49;
                                                        }
                                                    
                                                        inline void set_f50(int64_t val){
                                                            f50 = val;
                                                        }
                                                        inline int64_t& get_f50(){
                                                            return f50;
                                                        }
                                                    
                                                        inline void set_f51(int64_t val){
                                                            f51 = val;
                                                        }
                                                        inline int64_t& get_f51(){
                                                            return f51;
                                                        }
                                                    
                                                        inline void set_f52(int64_t val){
                                                            f52 = val;
                                                        }
                                                        inline int64_t& get_f52(){
                                                            return f52;
                                                        }
                                                    
                                                        inline void set_f53(int64_t val){
                                                            f53 = val;
                                                        }
                                                        inline int64_t& get_f53(){
                                                            return f53;
                                                        }
                                                    
                                                        inline void set_f54(int64_t val){
                                                            f54 = val;
                                                        }
                                                        inline int64_t& get_f54(){
                                                            return f54;
                                                        }
                                                    
                                                        inline void set_f55(int64_t val){
                                                            f55 = val;
                                                        }
                                                        inline int64_t& get_f55(){
                                                            return f55;
                                                        }
                                                    
                                                        inline void set_f56(int64_t val){
                                                            f56 = val;
                                                        }
                                                        inline int64_t& get_f56(){
                                                            return f56;
                                                        }
                                                    
                                                        inline void set_f57(int64_t val){
                                                            f57 = val;
                                                        }
                                                        inline int64_t& get_f57(){
                                                            return f57;
                                                        }
                                                    
                                                        inline void set_f58(int64_t val){
                                                            f58 = val;
                                                        }
                                                        inline int64_t& get_f58(){
                                                            return f58;
                                                        }
                                                    
                                                        inline void set_f59(int64_t val){
                                                            f59 = val;
                                                        }
                                                        inline int64_t& get_f59(){
                                                            return f59;
                                                        }
                                                    
                                                        inline void set_f60(int64_t val){
                                                            f60 = val;
                                                        }
                                                        inline int64_t& get_f60(){
                                                            return f60;
                                                        }
                                                    
                                                        inline void set_f61(int64_t val){
                                                            f61 = val;
                                                        }
                                                        inline int64_t& get_f61(){
                                                            return f61;
                                                        }
                                                    
                                                        inline void set_f62(int64_t val){
                                                            f62 = val;
                                                        }
                                                        inline int64_t& get_f62(){
                                                            return f62;
                                                        }
                                                    
                                                        inline void set_f63(int64_t val){
                                                            f63 = val;
                                                        }
                                                        inline int64_t& get_f63(){
                                                            return f63;
                                                        }
                                                    
                                                        inline void set_f64(int64_t val){
                                                            f64 = val;
                                                        }
                                                        inline int64_t& get_f64(){
                                                            return f64;
                                                        }
                                                    
                                                        inline M30* mutable_f65(){
                                                            f65 = new M30();
                                                            return f65;
                                                        }
                                                        inline M30*& get_f65(){
                                                            return f65;
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
                                                            fout << "M29->f33: " << f33 << std::endl;
                                                            fout << "M29->f34: " << f34 << std::endl;
                                                            fout << "M29->f35: " << f35 << std::endl;
                                                            fout << "M29->f36: " << f36 << std::endl;
                                                            fout << "M29->f37: " << f37 << std::endl;
                                                            fout << "M29->f38: " << f38 << std::endl;
                                                            fout << "M29->f39: " << f39 << std::endl;
                                                            fout << "M29->f40: " << f40 << std::endl;
                                                            fout << "M29->f41: " << f41 << std::endl;
                                                            fout << "M29->f42: " << f42 << std::endl;
                                                            fout << "M29->f43: " << f43 << std::endl;
                                                            fout << "M29->f44: " << f44 << std::endl;
                                                            fout << "M29->f45: " << f45 << std::endl;
                                                            fout << "M29->f46: " << f46 << std::endl;
                                                            fout << "M29->f47: " << f47 << std::endl;
                                                            fout << "M29->f48: " << f48 << std::endl;
                                                            fout << "M29->f49: " << f49 << std::endl;
                                                            fout << "M29->f50: " << f50 << std::endl;
                                                            fout << "M29->f51: " << f51 << std::endl;
                                                            fout << "M29->f52: " << f52 << std::endl;
                                                            fout << "M29->f53: " << f53 << std::endl;
                                                            fout << "M29->f54: " << f54 << std::endl;
                                                            fout << "M29->f55: " << f55 << std::endl;
                                                            fout << "M29->f56: " << f56 << std::endl;
                                                            fout << "M29->f57: " << f57 << std::endl;
                                                            fout << "M29->f58: " << f58 << std::endl;
                                                            fout << "M29->f59: " << f59 << std::endl;
                                                            fout << "M29->f60: " << f60 << std::endl;
                                                            fout << "M29->f61: " << f61 << std::endl;
                                                            fout << "M29->f62: " << f62 << std::endl;
                                                            fout << "M29->f63: " << f63 << std::endl;
                                                            fout << "M29->f64: " << f64 << std::endl;
                                                            if(f65 != nullptr)
                                                                f65->print_message(fout);
                                                        }
                                                    
                                                        ~M29(){
                                                            if(f65 != nullptr)
                                                                delete f65;
                                                        }
                                                    
                                                        M29(){
                                                           f65 = nullptr;
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
                                                        alignas(8) int64_t f33;
                                                        alignas(8) int64_t f34;
                                                        alignas(8) int64_t f35;
                                                        alignas(8) int64_t f36;
                                                        alignas(8) int64_t f37;
                                                        alignas(8) int64_t f38;
                                                        alignas(8) int64_t f39;
                                                        alignas(8) int64_t f40;
                                                        alignas(8) int64_t f41;
                                                        alignas(8) int64_t f42;
                                                        alignas(8) int64_t f43;
                                                        alignas(8) int64_t f44;
                                                        alignas(8) int64_t f45;
                                                        alignas(8) int64_t f46;
                                                        alignas(8) int64_t f47;
                                                        alignas(8) int64_t f48;
                                                        alignas(8) int64_t f49;
                                                        alignas(8) int64_t f50;
                                                        alignas(8) int64_t f51;
                                                        alignas(8) int64_t f52;
                                                        alignas(8) int64_t f53;
                                                        alignas(8) int64_t f54;
                                                        alignas(8) int64_t f55;
                                                        alignas(8) int64_t f56;
                                                        alignas(8) int64_t f57;
                                                        alignas(8) int64_t f58;
                                                        alignas(8) int64_t f59;
                                                        alignas(8) int64_t f60;
                                                        alignas(8) int64_t f61;
                                                        alignas(8) int64_t f62;
                                                        alignas(8) int64_t f63;
                                                        alignas(8) int64_t f64;
                                                        alignas(8) M30* f65;
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
                                                
                                                    inline void set_f33(int64_t val){
                                                        f33 = val;
                                                    }
                                                    inline int64_t& get_f33(){
                                                        return f33;
                                                    }
                                                
                                                    inline void set_f34(int64_t val){
                                                        f34 = val;
                                                    }
                                                    inline int64_t& get_f34(){
                                                        return f34;
                                                    }
                                                
                                                    inline void set_f35(int64_t val){
                                                        f35 = val;
                                                    }
                                                    inline int64_t& get_f35(){
                                                        return f35;
                                                    }
                                                
                                                    inline void set_f36(int64_t val){
                                                        f36 = val;
                                                    }
                                                    inline int64_t& get_f36(){
                                                        return f36;
                                                    }
                                                
                                                    inline void set_f37(int64_t val){
                                                        f37 = val;
                                                    }
                                                    inline int64_t& get_f37(){
                                                        return f37;
                                                    }
                                                
                                                    inline void set_f38(int64_t val){
                                                        f38 = val;
                                                    }
                                                    inline int64_t& get_f38(){
                                                        return f38;
                                                    }
                                                
                                                    inline void set_f39(int64_t val){
                                                        f39 = val;
                                                    }
                                                    inline int64_t& get_f39(){
                                                        return f39;
                                                    }
                                                
                                                    inline void set_f40(int64_t val){
                                                        f40 = val;
                                                    }
                                                    inline int64_t& get_f40(){
                                                        return f40;
                                                    }
                                                
                                                    inline void set_f41(int64_t val){
                                                        f41 = val;
                                                    }
                                                    inline int64_t& get_f41(){
                                                        return f41;
                                                    }
                                                
                                                    inline void set_f42(int64_t val){
                                                        f42 = val;
                                                    }
                                                    inline int64_t& get_f42(){
                                                        return f42;
                                                    }
                                                
                                                    inline void set_f43(int64_t val){
                                                        f43 = val;
                                                    }
                                                    inline int64_t& get_f43(){
                                                        return f43;
                                                    }
                                                
                                                    inline void set_f44(int64_t val){
                                                        f44 = val;
                                                    }
                                                    inline int64_t& get_f44(){
                                                        return f44;
                                                    }
                                                
                                                    inline void set_f45(int64_t val){
                                                        f45 = val;
                                                    }
                                                    inline int64_t& get_f45(){
                                                        return f45;
                                                    }
                                                
                                                    inline void set_f46(int64_t val){
                                                        f46 = val;
                                                    }
                                                    inline int64_t& get_f46(){
                                                        return f46;
                                                    }
                                                
                                                    inline void set_f47(int64_t val){
                                                        f47 = val;
                                                    }
                                                    inline int64_t& get_f47(){
                                                        return f47;
                                                    }
                                                
                                                    inline void set_f48(int64_t val){
                                                        f48 = val;
                                                    }
                                                    inline int64_t& get_f48(){
                                                        return f48;
                                                    }
                                                
                                                    inline void set_f49(int64_t val){
                                                        f49 = val;
                                                    }
                                                    inline int64_t& get_f49(){
                                                        return f49;
                                                    }
                                                
                                                    inline void set_f50(int64_t val){
                                                        f50 = val;
                                                    }
                                                    inline int64_t& get_f50(){
                                                        return f50;
                                                    }
                                                
                                                    inline void set_f51(int64_t val){
                                                        f51 = val;
                                                    }
                                                    inline int64_t& get_f51(){
                                                        return f51;
                                                    }
                                                
                                                    inline void set_f52(int64_t val){
                                                        f52 = val;
                                                    }
                                                    inline int64_t& get_f52(){
                                                        return f52;
                                                    }
                                                
                                                    inline void set_f53(int64_t val){
                                                        f53 = val;
                                                    }
                                                    inline int64_t& get_f53(){
                                                        return f53;
                                                    }
                                                
                                                    inline void set_f54(int64_t val){
                                                        f54 = val;
                                                    }
                                                    inline int64_t& get_f54(){
                                                        return f54;
                                                    }
                                                
                                                    inline void set_f55(int64_t val){
                                                        f55 = val;
                                                    }
                                                    inline int64_t& get_f55(){
                                                        return f55;
                                                    }
                                                
                                                    inline void set_f56(int64_t val){
                                                        f56 = val;
                                                    }
                                                    inline int64_t& get_f56(){
                                                        return f56;
                                                    }
                                                
                                                    inline void set_f57(int64_t val){
                                                        f57 = val;
                                                    }
                                                    inline int64_t& get_f57(){
                                                        return f57;
                                                    }
                                                
                                                    inline void set_f58(int64_t val){
                                                        f58 = val;
                                                    }
                                                    inline int64_t& get_f58(){
                                                        return f58;
                                                    }
                                                
                                                    inline void set_f59(int64_t val){
                                                        f59 = val;
                                                    }
                                                    inline int64_t& get_f59(){
                                                        return f59;
                                                    }
                                                
                                                    inline void set_f60(int64_t val){
                                                        f60 = val;
                                                    }
                                                    inline int64_t& get_f60(){
                                                        return f60;
                                                    }
                                                
                                                    inline void set_f61(int64_t val){
                                                        f61 = val;
                                                    }
                                                    inline int64_t& get_f61(){
                                                        return f61;
                                                    }
                                                
                                                    inline void set_f62(int64_t val){
                                                        f62 = val;
                                                    }
                                                    inline int64_t& get_f62(){
                                                        return f62;
                                                    }
                                                
                                                    inline void set_f63(int64_t val){
                                                        f63 = val;
                                                    }
                                                    inline int64_t& get_f63(){
                                                        return f63;
                                                    }
                                                
                                                    inline void set_f64(int64_t val){
                                                        f64 = val;
                                                    }
                                                    inline int64_t& get_f64(){
                                                        return f64;
                                                    }
                                                
                                                    inline M29* mutable_f65(){
                                                        f65 = new M29();
                                                        return f65;
                                                    }
                                                    inline M29*& get_f65(){
                                                        return f65;
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
                                                        fout << "M28->f33: " << f33 << std::endl;
                                                        fout << "M28->f34: " << f34 << std::endl;
                                                        fout << "M28->f35: " << f35 << std::endl;
                                                        fout << "M28->f36: " << f36 << std::endl;
                                                        fout << "M28->f37: " << f37 << std::endl;
                                                        fout << "M28->f38: " << f38 << std::endl;
                                                        fout << "M28->f39: " << f39 << std::endl;
                                                        fout << "M28->f40: " << f40 << std::endl;
                                                        fout << "M28->f41: " << f41 << std::endl;
                                                        fout << "M28->f42: " << f42 << std::endl;
                                                        fout << "M28->f43: " << f43 << std::endl;
                                                        fout << "M28->f44: " << f44 << std::endl;
                                                        fout << "M28->f45: " << f45 << std::endl;
                                                        fout << "M28->f46: " << f46 << std::endl;
                                                        fout << "M28->f47: " << f47 << std::endl;
                                                        fout << "M28->f48: " << f48 << std::endl;
                                                        fout << "M28->f49: " << f49 << std::endl;
                                                        fout << "M28->f50: " << f50 << std::endl;
                                                        fout << "M28->f51: " << f51 << std::endl;
                                                        fout << "M28->f52: " << f52 << std::endl;
                                                        fout << "M28->f53: " << f53 << std::endl;
                                                        fout << "M28->f54: " << f54 << std::endl;
                                                        fout << "M28->f55: " << f55 << std::endl;
                                                        fout << "M28->f56: " << f56 << std::endl;
                                                        fout << "M28->f57: " << f57 << std::endl;
                                                        fout << "M28->f58: " << f58 << std::endl;
                                                        fout << "M28->f59: " << f59 << std::endl;
                                                        fout << "M28->f60: " << f60 << std::endl;
                                                        fout << "M28->f61: " << f61 << std::endl;
                                                        fout << "M28->f62: " << f62 << std::endl;
                                                        fout << "M28->f63: " << f63 << std::endl;
                                                        fout << "M28->f64: " << f64 << std::endl;
                                                        if(f65 != nullptr)
                                                            f65->print_message(fout);
                                                    }
                                                
                                                    ~M28(){
                                                        if(f65 != nullptr)
                                                            delete f65;
                                                    }
                                                
                                                    M28(){
                                                       f65 = nullptr;
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
                                                    alignas(8) int64_t f33;
                                                    alignas(8) int64_t f34;
                                                    alignas(8) int64_t f35;
                                                    alignas(8) int64_t f36;
                                                    alignas(8) int64_t f37;
                                                    alignas(8) int64_t f38;
                                                    alignas(8) int64_t f39;
                                                    alignas(8) int64_t f40;
                                                    alignas(8) int64_t f41;
                                                    alignas(8) int64_t f42;
                                                    alignas(8) int64_t f43;
                                                    alignas(8) int64_t f44;
                                                    alignas(8) int64_t f45;
                                                    alignas(8) int64_t f46;
                                                    alignas(8) int64_t f47;
                                                    alignas(8) int64_t f48;
                                                    alignas(8) int64_t f49;
                                                    alignas(8) int64_t f50;
                                                    alignas(8) int64_t f51;
                                                    alignas(8) int64_t f52;
                                                    alignas(8) int64_t f53;
                                                    alignas(8) int64_t f54;
                                                    alignas(8) int64_t f55;
                                                    alignas(8) int64_t f56;
                                                    alignas(8) int64_t f57;
                                                    alignas(8) int64_t f58;
                                                    alignas(8) int64_t f59;
                                                    alignas(8) int64_t f60;
                                                    alignas(8) int64_t f61;
                                                    alignas(8) int64_t f62;
                                                    alignas(8) int64_t f63;
                                                    alignas(8) int64_t f64;
                                                    alignas(8) M29* f65;
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
                                            
                                                inline void set_f33(int64_t val){
                                                    f33 = val;
                                                }
                                                inline int64_t& get_f33(){
                                                    return f33;
                                                }
                                            
                                                inline void set_f34(int64_t val){
                                                    f34 = val;
                                                }
                                                inline int64_t& get_f34(){
                                                    return f34;
                                                }
                                            
                                                inline void set_f35(int64_t val){
                                                    f35 = val;
                                                }
                                                inline int64_t& get_f35(){
                                                    return f35;
                                                }
                                            
                                                inline void set_f36(int64_t val){
                                                    f36 = val;
                                                }
                                                inline int64_t& get_f36(){
                                                    return f36;
                                                }
                                            
                                                inline void set_f37(int64_t val){
                                                    f37 = val;
                                                }
                                                inline int64_t& get_f37(){
                                                    return f37;
                                                }
                                            
                                                inline void set_f38(int64_t val){
                                                    f38 = val;
                                                }
                                                inline int64_t& get_f38(){
                                                    return f38;
                                                }
                                            
                                                inline void set_f39(int64_t val){
                                                    f39 = val;
                                                }
                                                inline int64_t& get_f39(){
                                                    return f39;
                                                }
                                            
                                                inline void set_f40(int64_t val){
                                                    f40 = val;
                                                }
                                                inline int64_t& get_f40(){
                                                    return f40;
                                                }
                                            
                                                inline void set_f41(int64_t val){
                                                    f41 = val;
                                                }
                                                inline int64_t& get_f41(){
                                                    return f41;
                                                }
                                            
                                                inline void set_f42(int64_t val){
                                                    f42 = val;
                                                }
                                                inline int64_t& get_f42(){
                                                    return f42;
                                                }
                                            
                                                inline void set_f43(int64_t val){
                                                    f43 = val;
                                                }
                                                inline int64_t& get_f43(){
                                                    return f43;
                                                }
                                            
                                                inline void set_f44(int64_t val){
                                                    f44 = val;
                                                }
                                                inline int64_t& get_f44(){
                                                    return f44;
                                                }
                                            
                                                inline void set_f45(int64_t val){
                                                    f45 = val;
                                                }
                                                inline int64_t& get_f45(){
                                                    return f45;
                                                }
                                            
                                                inline void set_f46(int64_t val){
                                                    f46 = val;
                                                }
                                                inline int64_t& get_f46(){
                                                    return f46;
                                                }
                                            
                                                inline void set_f47(int64_t val){
                                                    f47 = val;
                                                }
                                                inline int64_t& get_f47(){
                                                    return f47;
                                                }
                                            
                                                inline void set_f48(int64_t val){
                                                    f48 = val;
                                                }
                                                inline int64_t& get_f48(){
                                                    return f48;
                                                }
                                            
                                                inline void set_f49(int64_t val){
                                                    f49 = val;
                                                }
                                                inline int64_t& get_f49(){
                                                    return f49;
                                                }
                                            
                                                inline void set_f50(int64_t val){
                                                    f50 = val;
                                                }
                                                inline int64_t& get_f50(){
                                                    return f50;
                                                }
                                            
                                                inline void set_f51(int64_t val){
                                                    f51 = val;
                                                }
                                                inline int64_t& get_f51(){
                                                    return f51;
                                                }
                                            
                                                inline void set_f52(int64_t val){
                                                    f52 = val;
                                                }
                                                inline int64_t& get_f52(){
                                                    return f52;
                                                }
                                            
                                                inline void set_f53(int64_t val){
                                                    f53 = val;
                                                }
                                                inline int64_t& get_f53(){
                                                    return f53;
                                                }
                                            
                                                inline void set_f54(int64_t val){
                                                    f54 = val;
                                                }
                                                inline int64_t& get_f54(){
                                                    return f54;
                                                }
                                            
                                                inline void set_f55(int64_t val){
                                                    f55 = val;
                                                }
                                                inline int64_t& get_f55(){
                                                    return f55;
                                                }
                                            
                                                inline void set_f56(int64_t val){
                                                    f56 = val;
                                                }
                                                inline int64_t& get_f56(){
                                                    return f56;
                                                }
                                            
                                                inline void set_f57(int64_t val){
                                                    f57 = val;
                                                }
                                                inline int64_t& get_f57(){
                                                    return f57;
                                                }
                                            
                                                inline void set_f58(int64_t val){
                                                    f58 = val;
                                                }
                                                inline int64_t& get_f58(){
                                                    return f58;
                                                }
                                            
                                                inline void set_f59(int64_t val){
                                                    f59 = val;
                                                }
                                                inline int64_t& get_f59(){
                                                    return f59;
                                                }
                                            
                                                inline void set_f60(int64_t val){
                                                    f60 = val;
                                                }
                                                inline int64_t& get_f60(){
                                                    return f60;
                                                }
                                            
                                                inline void set_f61(int64_t val){
                                                    f61 = val;
                                                }
                                                inline int64_t& get_f61(){
                                                    return f61;
                                                }
                                            
                                                inline void set_f62(int64_t val){
                                                    f62 = val;
                                                }
                                                inline int64_t& get_f62(){
                                                    return f62;
                                                }
                                            
                                                inline void set_f63(int64_t val){
                                                    f63 = val;
                                                }
                                                inline int64_t& get_f63(){
                                                    return f63;
                                                }
                                            
                                                inline void set_f64(int64_t val){
                                                    f64 = val;
                                                }
                                                inline int64_t& get_f64(){
                                                    return f64;
                                                }
                                            
                                                inline M28* mutable_f65(){
                                                    f65 = new M28();
                                                    return f65;
                                                }
                                                inline M28*& get_f65(){
                                                    return f65;
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
                                                    fout << "M27->f33: " << f33 << std::endl;
                                                    fout << "M27->f34: " << f34 << std::endl;
                                                    fout << "M27->f35: " << f35 << std::endl;
                                                    fout << "M27->f36: " << f36 << std::endl;
                                                    fout << "M27->f37: " << f37 << std::endl;
                                                    fout << "M27->f38: " << f38 << std::endl;
                                                    fout << "M27->f39: " << f39 << std::endl;
                                                    fout << "M27->f40: " << f40 << std::endl;
                                                    fout << "M27->f41: " << f41 << std::endl;
                                                    fout << "M27->f42: " << f42 << std::endl;
                                                    fout << "M27->f43: " << f43 << std::endl;
                                                    fout << "M27->f44: " << f44 << std::endl;
                                                    fout << "M27->f45: " << f45 << std::endl;
                                                    fout << "M27->f46: " << f46 << std::endl;
                                                    fout << "M27->f47: " << f47 << std::endl;
                                                    fout << "M27->f48: " << f48 << std::endl;
                                                    fout << "M27->f49: " << f49 << std::endl;
                                                    fout << "M27->f50: " << f50 << std::endl;
                                                    fout << "M27->f51: " << f51 << std::endl;
                                                    fout << "M27->f52: " << f52 << std::endl;
                                                    fout << "M27->f53: " << f53 << std::endl;
                                                    fout << "M27->f54: " << f54 << std::endl;
                                                    fout << "M27->f55: " << f55 << std::endl;
                                                    fout << "M27->f56: " << f56 << std::endl;
                                                    fout << "M27->f57: " << f57 << std::endl;
                                                    fout << "M27->f58: " << f58 << std::endl;
                                                    fout << "M27->f59: " << f59 << std::endl;
                                                    fout << "M27->f60: " << f60 << std::endl;
                                                    fout << "M27->f61: " << f61 << std::endl;
                                                    fout << "M27->f62: " << f62 << std::endl;
                                                    fout << "M27->f63: " << f63 << std::endl;
                                                    fout << "M27->f64: " << f64 << std::endl;
                                                    if(f65 != nullptr)
                                                        f65->print_message(fout);
                                                }
                                            
                                                ~M27(){
                                                    if(f65 != nullptr)
                                                        delete f65;
                                                }
                                            
                                                M27(){
                                                   f65 = nullptr;
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
                                                alignas(8) int64_t f33;
                                                alignas(8) int64_t f34;
                                                alignas(8) int64_t f35;
                                                alignas(8) int64_t f36;
                                                alignas(8) int64_t f37;
                                                alignas(8) int64_t f38;
                                                alignas(8) int64_t f39;
                                                alignas(8) int64_t f40;
                                                alignas(8) int64_t f41;
                                                alignas(8) int64_t f42;
                                                alignas(8) int64_t f43;
                                                alignas(8) int64_t f44;
                                                alignas(8) int64_t f45;
                                                alignas(8) int64_t f46;
                                                alignas(8) int64_t f47;
                                                alignas(8) int64_t f48;
                                                alignas(8) int64_t f49;
                                                alignas(8) int64_t f50;
                                                alignas(8) int64_t f51;
                                                alignas(8) int64_t f52;
                                                alignas(8) int64_t f53;
                                                alignas(8) int64_t f54;
                                                alignas(8) int64_t f55;
                                                alignas(8) int64_t f56;
                                                alignas(8) int64_t f57;
                                                alignas(8) int64_t f58;
                                                alignas(8) int64_t f59;
                                                alignas(8) int64_t f60;
                                                alignas(8) int64_t f61;
                                                alignas(8) int64_t f62;
                                                alignas(8) int64_t f63;
                                                alignas(8) int64_t f64;
                                                alignas(8) M28* f65;
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
                                        
                                            inline void set_f33(int64_t val){
                                                f33 = val;
                                            }
                                            inline int64_t& get_f33(){
                                                return f33;
                                            }
                                        
                                            inline void set_f34(int64_t val){
                                                f34 = val;
                                            }
                                            inline int64_t& get_f34(){
                                                return f34;
                                            }
                                        
                                            inline void set_f35(int64_t val){
                                                f35 = val;
                                            }
                                            inline int64_t& get_f35(){
                                                return f35;
                                            }
                                        
                                            inline void set_f36(int64_t val){
                                                f36 = val;
                                            }
                                            inline int64_t& get_f36(){
                                                return f36;
                                            }
                                        
                                            inline void set_f37(int64_t val){
                                                f37 = val;
                                            }
                                            inline int64_t& get_f37(){
                                                return f37;
                                            }
                                        
                                            inline void set_f38(int64_t val){
                                                f38 = val;
                                            }
                                            inline int64_t& get_f38(){
                                                return f38;
                                            }
                                        
                                            inline void set_f39(int64_t val){
                                                f39 = val;
                                            }
                                            inline int64_t& get_f39(){
                                                return f39;
                                            }
                                        
                                            inline void set_f40(int64_t val){
                                                f40 = val;
                                            }
                                            inline int64_t& get_f40(){
                                                return f40;
                                            }
                                        
                                            inline void set_f41(int64_t val){
                                                f41 = val;
                                            }
                                            inline int64_t& get_f41(){
                                                return f41;
                                            }
                                        
                                            inline void set_f42(int64_t val){
                                                f42 = val;
                                            }
                                            inline int64_t& get_f42(){
                                                return f42;
                                            }
                                        
                                            inline void set_f43(int64_t val){
                                                f43 = val;
                                            }
                                            inline int64_t& get_f43(){
                                                return f43;
                                            }
                                        
                                            inline void set_f44(int64_t val){
                                                f44 = val;
                                            }
                                            inline int64_t& get_f44(){
                                                return f44;
                                            }
                                        
                                            inline void set_f45(int64_t val){
                                                f45 = val;
                                            }
                                            inline int64_t& get_f45(){
                                                return f45;
                                            }
                                        
                                            inline void set_f46(int64_t val){
                                                f46 = val;
                                            }
                                            inline int64_t& get_f46(){
                                                return f46;
                                            }
                                        
                                            inline void set_f47(int64_t val){
                                                f47 = val;
                                            }
                                            inline int64_t& get_f47(){
                                                return f47;
                                            }
                                        
                                            inline void set_f48(int64_t val){
                                                f48 = val;
                                            }
                                            inline int64_t& get_f48(){
                                                return f48;
                                            }
                                        
                                            inline void set_f49(int64_t val){
                                                f49 = val;
                                            }
                                            inline int64_t& get_f49(){
                                                return f49;
                                            }
                                        
                                            inline void set_f50(int64_t val){
                                                f50 = val;
                                            }
                                            inline int64_t& get_f50(){
                                                return f50;
                                            }
                                        
                                            inline void set_f51(int64_t val){
                                                f51 = val;
                                            }
                                            inline int64_t& get_f51(){
                                                return f51;
                                            }
                                        
                                            inline void set_f52(int64_t val){
                                                f52 = val;
                                            }
                                            inline int64_t& get_f52(){
                                                return f52;
                                            }
                                        
                                            inline void set_f53(int64_t val){
                                                f53 = val;
                                            }
                                            inline int64_t& get_f53(){
                                                return f53;
                                            }
                                        
                                            inline void set_f54(int64_t val){
                                                f54 = val;
                                            }
                                            inline int64_t& get_f54(){
                                                return f54;
                                            }
                                        
                                            inline void set_f55(int64_t val){
                                                f55 = val;
                                            }
                                            inline int64_t& get_f55(){
                                                return f55;
                                            }
                                        
                                            inline void set_f56(int64_t val){
                                                f56 = val;
                                            }
                                            inline int64_t& get_f56(){
                                                return f56;
                                            }
                                        
                                            inline void set_f57(int64_t val){
                                                f57 = val;
                                            }
                                            inline int64_t& get_f57(){
                                                return f57;
                                            }
                                        
                                            inline void set_f58(int64_t val){
                                                f58 = val;
                                            }
                                            inline int64_t& get_f58(){
                                                return f58;
                                            }
                                        
                                            inline void set_f59(int64_t val){
                                                f59 = val;
                                            }
                                            inline int64_t& get_f59(){
                                                return f59;
                                            }
                                        
                                            inline void set_f60(int64_t val){
                                                f60 = val;
                                            }
                                            inline int64_t& get_f60(){
                                                return f60;
                                            }
                                        
                                            inline void set_f61(int64_t val){
                                                f61 = val;
                                            }
                                            inline int64_t& get_f61(){
                                                return f61;
                                            }
                                        
                                            inline void set_f62(int64_t val){
                                                f62 = val;
                                            }
                                            inline int64_t& get_f62(){
                                                return f62;
                                            }
                                        
                                            inline void set_f63(int64_t val){
                                                f63 = val;
                                            }
                                            inline int64_t& get_f63(){
                                                return f63;
                                            }
                                        
                                            inline void set_f64(int64_t val){
                                                f64 = val;
                                            }
                                            inline int64_t& get_f64(){
                                                return f64;
                                            }
                                        
                                            inline M27* mutable_f65(){
                                                f65 = new M27();
                                                return f65;
                                            }
                                            inline M27*& get_f65(){
                                                return f65;
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
                                                fout << "M26->f33: " << f33 << std::endl;
                                                fout << "M26->f34: " << f34 << std::endl;
                                                fout << "M26->f35: " << f35 << std::endl;
                                                fout << "M26->f36: " << f36 << std::endl;
                                                fout << "M26->f37: " << f37 << std::endl;
                                                fout << "M26->f38: " << f38 << std::endl;
                                                fout << "M26->f39: " << f39 << std::endl;
                                                fout << "M26->f40: " << f40 << std::endl;
                                                fout << "M26->f41: " << f41 << std::endl;
                                                fout << "M26->f42: " << f42 << std::endl;
                                                fout << "M26->f43: " << f43 << std::endl;
                                                fout << "M26->f44: " << f44 << std::endl;
                                                fout << "M26->f45: " << f45 << std::endl;
                                                fout << "M26->f46: " << f46 << std::endl;
                                                fout << "M26->f47: " << f47 << std::endl;
                                                fout << "M26->f48: " << f48 << std::endl;
                                                fout << "M26->f49: " << f49 << std::endl;
                                                fout << "M26->f50: " << f50 << std::endl;
                                                fout << "M26->f51: " << f51 << std::endl;
                                                fout << "M26->f52: " << f52 << std::endl;
                                                fout << "M26->f53: " << f53 << std::endl;
                                                fout << "M26->f54: " << f54 << std::endl;
                                                fout << "M26->f55: " << f55 << std::endl;
                                                fout << "M26->f56: " << f56 << std::endl;
                                                fout << "M26->f57: " << f57 << std::endl;
                                                fout << "M26->f58: " << f58 << std::endl;
                                                fout << "M26->f59: " << f59 << std::endl;
                                                fout << "M26->f60: " << f60 << std::endl;
                                                fout << "M26->f61: " << f61 << std::endl;
                                                fout << "M26->f62: " << f62 << std::endl;
                                                fout << "M26->f63: " << f63 << std::endl;
                                                fout << "M26->f64: " << f64 << std::endl;
                                                if(f65 != nullptr)
                                                    f65->print_message(fout);
                                            }
                                        
                                            ~M26(){
                                                if(f65 != nullptr)
                                                    delete f65;
                                            }
                                        
                                            M26(){
                                               f65 = nullptr;
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
                                            alignas(8) int64_t f33;
                                            alignas(8) int64_t f34;
                                            alignas(8) int64_t f35;
                                            alignas(8) int64_t f36;
                                            alignas(8) int64_t f37;
                                            alignas(8) int64_t f38;
                                            alignas(8) int64_t f39;
                                            alignas(8) int64_t f40;
                                            alignas(8) int64_t f41;
                                            alignas(8) int64_t f42;
                                            alignas(8) int64_t f43;
                                            alignas(8) int64_t f44;
                                            alignas(8) int64_t f45;
                                            alignas(8) int64_t f46;
                                            alignas(8) int64_t f47;
                                            alignas(8) int64_t f48;
                                            alignas(8) int64_t f49;
                                            alignas(8) int64_t f50;
                                            alignas(8) int64_t f51;
                                            alignas(8) int64_t f52;
                                            alignas(8) int64_t f53;
                                            alignas(8) int64_t f54;
                                            alignas(8) int64_t f55;
                                            alignas(8) int64_t f56;
                                            alignas(8) int64_t f57;
                                            alignas(8) int64_t f58;
                                            alignas(8) int64_t f59;
                                            alignas(8) int64_t f60;
                                            alignas(8) int64_t f61;
                                            alignas(8) int64_t f62;
                                            alignas(8) int64_t f63;
                                            alignas(8) int64_t f64;
                                            alignas(8) M27* f65;
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
                                    
                                        inline void set_f33(int64_t val){
                                            f33 = val;
                                        }
                                        inline int64_t& get_f33(){
                                            return f33;
                                        }
                                    
                                        inline void set_f34(int64_t val){
                                            f34 = val;
                                        }
                                        inline int64_t& get_f34(){
                                            return f34;
                                        }
                                    
                                        inline void set_f35(int64_t val){
                                            f35 = val;
                                        }
                                        inline int64_t& get_f35(){
                                            return f35;
                                        }
                                    
                                        inline void set_f36(int64_t val){
                                            f36 = val;
                                        }
                                        inline int64_t& get_f36(){
                                            return f36;
                                        }
                                    
                                        inline void set_f37(int64_t val){
                                            f37 = val;
                                        }
                                        inline int64_t& get_f37(){
                                            return f37;
                                        }
                                    
                                        inline void set_f38(int64_t val){
                                            f38 = val;
                                        }
                                        inline int64_t& get_f38(){
                                            return f38;
                                        }
                                    
                                        inline void set_f39(int64_t val){
                                            f39 = val;
                                        }
                                        inline int64_t& get_f39(){
                                            return f39;
                                        }
                                    
                                        inline void set_f40(int64_t val){
                                            f40 = val;
                                        }
                                        inline int64_t& get_f40(){
                                            return f40;
                                        }
                                    
                                        inline void set_f41(int64_t val){
                                            f41 = val;
                                        }
                                        inline int64_t& get_f41(){
                                            return f41;
                                        }
                                    
                                        inline void set_f42(int64_t val){
                                            f42 = val;
                                        }
                                        inline int64_t& get_f42(){
                                            return f42;
                                        }
                                    
                                        inline void set_f43(int64_t val){
                                            f43 = val;
                                        }
                                        inline int64_t& get_f43(){
                                            return f43;
                                        }
                                    
                                        inline void set_f44(int64_t val){
                                            f44 = val;
                                        }
                                        inline int64_t& get_f44(){
                                            return f44;
                                        }
                                    
                                        inline void set_f45(int64_t val){
                                            f45 = val;
                                        }
                                        inline int64_t& get_f45(){
                                            return f45;
                                        }
                                    
                                        inline void set_f46(int64_t val){
                                            f46 = val;
                                        }
                                        inline int64_t& get_f46(){
                                            return f46;
                                        }
                                    
                                        inline void set_f47(int64_t val){
                                            f47 = val;
                                        }
                                        inline int64_t& get_f47(){
                                            return f47;
                                        }
                                    
                                        inline void set_f48(int64_t val){
                                            f48 = val;
                                        }
                                        inline int64_t& get_f48(){
                                            return f48;
                                        }
                                    
                                        inline void set_f49(int64_t val){
                                            f49 = val;
                                        }
                                        inline int64_t& get_f49(){
                                            return f49;
                                        }
                                    
                                        inline void set_f50(int64_t val){
                                            f50 = val;
                                        }
                                        inline int64_t& get_f50(){
                                            return f50;
                                        }
                                    
                                        inline void set_f51(int64_t val){
                                            f51 = val;
                                        }
                                        inline int64_t& get_f51(){
                                            return f51;
                                        }
                                    
                                        inline void set_f52(int64_t val){
                                            f52 = val;
                                        }
                                        inline int64_t& get_f52(){
                                            return f52;
                                        }
                                    
                                        inline void set_f53(int64_t val){
                                            f53 = val;
                                        }
                                        inline int64_t& get_f53(){
                                            return f53;
                                        }
                                    
                                        inline void set_f54(int64_t val){
                                            f54 = val;
                                        }
                                        inline int64_t& get_f54(){
                                            return f54;
                                        }
                                    
                                        inline void set_f55(int64_t val){
                                            f55 = val;
                                        }
                                        inline int64_t& get_f55(){
                                            return f55;
                                        }
                                    
                                        inline void set_f56(int64_t val){
                                            f56 = val;
                                        }
                                        inline int64_t& get_f56(){
                                            return f56;
                                        }
                                    
                                        inline void set_f57(int64_t val){
                                            f57 = val;
                                        }
                                        inline int64_t& get_f57(){
                                            return f57;
                                        }
                                    
                                        inline void set_f58(int64_t val){
                                            f58 = val;
                                        }
                                        inline int64_t& get_f58(){
                                            return f58;
                                        }
                                    
                                        inline void set_f59(int64_t val){
                                            f59 = val;
                                        }
                                        inline int64_t& get_f59(){
                                            return f59;
                                        }
                                    
                                        inline void set_f60(int64_t val){
                                            f60 = val;
                                        }
                                        inline int64_t& get_f60(){
                                            return f60;
                                        }
                                    
                                        inline void set_f61(int64_t val){
                                            f61 = val;
                                        }
                                        inline int64_t& get_f61(){
                                            return f61;
                                        }
                                    
                                        inline void set_f62(int64_t val){
                                            f62 = val;
                                        }
                                        inline int64_t& get_f62(){
                                            return f62;
                                        }
                                    
                                        inline void set_f63(int64_t val){
                                            f63 = val;
                                        }
                                        inline int64_t& get_f63(){
                                            return f63;
                                        }
                                    
                                        inline void set_f64(int64_t val){
                                            f64 = val;
                                        }
                                        inline int64_t& get_f64(){
                                            return f64;
                                        }
                                    
                                        inline M26* mutable_f65(){
                                            f65 = new M26();
                                            return f65;
                                        }
                                        inline M26*& get_f65(){
                                            return f65;
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
                                            fout << "M25->f33: " << f33 << std::endl;
                                            fout << "M25->f34: " << f34 << std::endl;
                                            fout << "M25->f35: " << f35 << std::endl;
                                            fout << "M25->f36: " << f36 << std::endl;
                                            fout << "M25->f37: " << f37 << std::endl;
                                            fout << "M25->f38: " << f38 << std::endl;
                                            fout << "M25->f39: " << f39 << std::endl;
                                            fout << "M25->f40: " << f40 << std::endl;
                                            fout << "M25->f41: " << f41 << std::endl;
                                            fout << "M25->f42: " << f42 << std::endl;
                                            fout << "M25->f43: " << f43 << std::endl;
                                            fout << "M25->f44: " << f44 << std::endl;
                                            fout << "M25->f45: " << f45 << std::endl;
                                            fout << "M25->f46: " << f46 << std::endl;
                                            fout << "M25->f47: " << f47 << std::endl;
                                            fout << "M25->f48: " << f48 << std::endl;
                                            fout << "M25->f49: " << f49 << std::endl;
                                            fout << "M25->f50: " << f50 << std::endl;
                                            fout << "M25->f51: " << f51 << std::endl;
                                            fout << "M25->f52: " << f52 << std::endl;
                                            fout << "M25->f53: " << f53 << std::endl;
                                            fout << "M25->f54: " << f54 << std::endl;
                                            fout << "M25->f55: " << f55 << std::endl;
                                            fout << "M25->f56: " << f56 << std::endl;
                                            fout << "M25->f57: " << f57 << std::endl;
                                            fout << "M25->f58: " << f58 << std::endl;
                                            fout << "M25->f59: " << f59 << std::endl;
                                            fout << "M25->f60: " << f60 << std::endl;
                                            fout << "M25->f61: " << f61 << std::endl;
                                            fout << "M25->f62: " << f62 << std::endl;
                                            fout << "M25->f63: " << f63 << std::endl;
                                            fout << "M25->f64: " << f64 << std::endl;
                                            if(f65 != nullptr)
                                                f65->print_message(fout);
                                        }
                                    
                                        ~M25(){
                                            if(f65 != nullptr)
                                                delete f65;
                                        }
                                    
                                        M25(){
                                           f65 = nullptr;
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
                                        alignas(8) int64_t f33;
                                        alignas(8) int64_t f34;
                                        alignas(8) int64_t f35;
                                        alignas(8) int64_t f36;
                                        alignas(8) int64_t f37;
                                        alignas(8) int64_t f38;
                                        alignas(8) int64_t f39;
                                        alignas(8) int64_t f40;
                                        alignas(8) int64_t f41;
                                        alignas(8) int64_t f42;
                                        alignas(8) int64_t f43;
                                        alignas(8) int64_t f44;
                                        alignas(8) int64_t f45;
                                        alignas(8) int64_t f46;
                                        alignas(8) int64_t f47;
                                        alignas(8) int64_t f48;
                                        alignas(8) int64_t f49;
                                        alignas(8) int64_t f50;
                                        alignas(8) int64_t f51;
                                        alignas(8) int64_t f52;
                                        alignas(8) int64_t f53;
                                        alignas(8) int64_t f54;
                                        alignas(8) int64_t f55;
                                        alignas(8) int64_t f56;
                                        alignas(8) int64_t f57;
                                        alignas(8) int64_t f58;
                                        alignas(8) int64_t f59;
                                        alignas(8) int64_t f60;
                                        alignas(8) int64_t f61;
                                        alignas(8) int64_t f62;
                                        alignas(8) int64_t f63;
                                        alignas(8) int64_t f64;
                                        alignas(8) M26* f65;
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
                                
                                    inline void set_f33(int64_t val){
                                        f33 = val;
                                    }
                                    inline int64_t& get_f33(){
                                        return f33;
                                    }
                                
                                    inline void set_f34(int64_t val){
                                        f34 = val;
                                    }
                                    inline int64_t& get_f34(){
                                        return f34;
                                    }
                                
                                    inline void set_f35(int64_t val){
                                        f35 = val;
                                    }
                                    inline int64_t& get_f35(){
                                        return f35;
                                    }
                                
                                    inline void set_f36(int64_t val){
                                        f36 = val;
                                    }
                                    inline int64_t& get_f36(){
                                        return f36;
                                    }
                                
                                    inline void set_f37(int64_t val){
                                        f37 = val;
                                    }
                                    inline int64_t& get_f37(){
                                        return f37;
                                    }
                                
                                    inline void set_f38(int64_t val){
                                        f38 = val;
                                    }
                                    inline int64_t& get_f38(){
                                        return f38;
                                    }
                                
                                    inline void set_f39(int64_t val){
                                        f39 = val;
                                    }
                                    inline int64_t& get_f39(){
                                        return f39;
                                    }
                                
                                    inline void set_f40(int64_t val){
                                        f40 = val;
                                    }
                                    inline int64_t& get_f40(){
                                        return f40;
                                    }
                                
                                    inline void set_f41(int64_t val){
                                        f41 = val;
                                    }
                                    inline int64_t& get_f41(){
                                        return f41;
                                    }
                                
                                    inline void set_f42(int64_t val){
                                        f42 = val;
                                    }
                                    inline int64_t& get_f42(){
                                        return f42;
                                    }
                                
                                    inline void set_f43(int64_t val){
                                        f43 = val;
                                    }
                                    inline int64_t& get_f43(){
                                        return f43;
                                    }
                                
                                    inline void set_f44(int64_t val){
                                        f44 = val;
                                    }
                                    inline int64_t& get_f44(){
                                        return f44;
                                    }
                                
                                    inline void set_f45(int64_t val){
                                        f45 = val;
                                    }
                                    inline int64_t& get_f45(){
                                        return f45;
                                    }
                                
                                    inline void set_f46(int64_t val){
                                        f46 = val;
                                    }
                                    inline int64_t& get_f46(){
                                        return f46;
                                    }
                                
                                    inline void set_f47(int64_t val){
                                        f47 = val;
                                    }
                                    inline int64_t& get_f47(){
                                        return f47;
                                    }
                                
                                    inline void set_f48(int64_t val){
                                        f48 = val;
                                    }
                                    inline int64_t& get_f48(){
                                        return f48;
                                    }
                                
                                    inline void set_f49(int64_t val){
                                        f49 = val;
                                    }
                                    inline int64_t& get_f49(){
                                        return f49;
                                    }
                                
                                    inline void set_f50(int64_t val){
                                        f50 = val;
                                    }
                                    inline int64_t& get_f50(){
                                        return f50;
                                    }
                                
                                    inline void set_f51(int64_t val){
                                        f51 = val;
                                    }
                                    inline int64_t& get_f51(){
                                        return f51;
                                    }
                                
                                    inline void set_f52(int64_t val){
                                        f52 = val;
                                    }
                                    inline int64_t& get_f52(){
                                        return f52;
                                    }
                                
                                    inline void set_f53(int64_t val){
                                        f53 = val;
                                    }
                                    inline int64_t& get_f53(){
                                        return f53;
                                    }
                                
                                    inline void set_f54(int64_t val){
                                        f54 = val;
                                    }
                                    inline int64_t& get_f54(){
                                        return f54;
                                    }
                                
                                    inline void set_f55(int64_t val){
                                        f55 = val;
                                    }
                                    inline int64_t& get_f55(){
                                        return f55;
                                    }
                                
                                    inline void set_f56(int64_t val){
                                        f56 = val;
                                    }
                                    inline int64_t& get_f56(){
                                        return f56;
                                    }
                                
                                    inline void set_f57(int64_t val){
                                        f57 = val;
                                    }
                                    inline int64_t& get_f57(){
                                        return f57;
                                    }
                                
                                    inline void set_f58(int64_t val){
                                        f58 = val;
                                    }
                                    inline int64_t& get_f58(){
                                        return f58;
                                    }
                                
                                    inline void set_f59(int64_t val){
                                        f59 = val;
                                    }
                                    inline int64_t& get_f59(){
                                        return f59;
                                    }
                                
                                    inline void set_f60(int64_t val){
                                        f60 = val;
                                    }
                                    inline int64_t& get_f60(){
                                        return f60;
                                    }
                                
                                    inline void set_f61(int64_t val){
                                        f61 = val;
                                    }
                                    inline int64_t& get_f61(){
                                        return f61;
                                    }
                                
                                    inline void set_f62(int64_t val){
                                        f62 = val;
                                    }
                                    inline int64_t& get_f62(){
                                        return f62;
                                    }
                                
                                    inline void set_f63(int64_t val){
                                        f63 = val;
                                    }
                                    inline int64_t& get_f63(){
                                        return f63;
                                    }
                                
                                    inline void set_f64(int64_t val){
                                        f64 = val;
                                    }
                                    inline int64_t& get_f64(){
                                        return f64;
                                    }
                                
                                    inline M25* mutable_f65(){
                                        f65 = new M25();
                                        return f65;
                                    }
                                    inline M25*& get_f65(){
                                        return f65;
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
                                        fout << "M24->f33: " << f33 << std::endl;
                                        fout << "M24->f34: " << f34 << std::endl;
                                        fout << "M24->f35: " << f35 << std::endl;
                                        fout << "M24->f36: " << f36 << std::endl;
                                        fout << "M24->f37: " << f37 << std::endl;
                                        fout << "M24->f38: " << f38 << std::endl;
                                        fout << "M24->f39: " << f39 << std::endl;
                                        fout << "M24->f40: " << f40 << std::endl;
                                        fout << "M24->f41: " << f41 << std::endl;
                                        fout << "M24->f42: " << f42 << std::endl;
                                        fout << "M24->f43: " << f43 << std::endl;
                                        fout << "M24->f44: " << f44 << std::endl;
                                        fout << "M24->f45: " << f45 << std::endl;
                                        fout << "M24->f46: " << f46 << std::endl;
                                        fout << "M24->f47: " << f47 << std::endl;
                                        fout << "M24->f48: " << f48 << std::endl;
                                        fout << "M24->f49: " << f49 << std::endl;
                                        fout << "M24->f50: " << f50 << std::endl;
                                        fout << "M24->f51: " << f51 << std::endl;
                                        fout << "M24->f52: " << f52 << std::endl;
                                        fout << "M24->f53: " << f53 << std::endl;
                                        fout << "M24->f54: " << f54 << std::endl;
                                        fout << "M24->f55: " << f55 << std::endl;
                                        fout << "M24->f56: " << f56 << std::endl;
                                        fout << "M24->f57: " << f57 << std::endl;
                                        fout << "M24->f58: " << f58 << std::endl;
                                        fout << "M24->f59: " << f59 << std::endl;
                                        fout << "M24->f60: " << f60 << std::endl;
                                        fout << "M24->f61: " << f61 << std::endl;
                                        fout << "M24->f62: " << f62 << std::endl;
                                        fout << "M24->f63: " << f63 << std::endl;
                                        fout << "M24->f64: " << f64 << std::endl;
                                        if(f65 != nullptr)
                                            f65->print_message(fout);
                                    }
                                
                                    ~M24(){
                                        if(f65 != nullptr)
                                            delete f65;
                                    }
                                
                                    M24(){
                                       f65 = nullptr;
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
                                    alignas(8) int64_t f33;
                                    alignas(8) int64_t f34;
                                    alignas(8) int64_t f35;
                                    alignas(8) int64_t f36;
                                    alignas(8) int64_t f37;
                                    alignas(8) int64_t f38;
                                    alignas(8) int64_t f39;
                                    alignas(8) int64_t f40;
                                    alignas(8) int64_t f41;
                                    alignas(8) int64_t f42;
                                    alignas(8) int64_t f43;
                                    alignas(8) int64_t f44;
                                    alignas(8) int64_t f45;
                                    alignas(8) int64_t f46;
                                    alignas(8) int64_t f47;
                                    alignas(8) int64_t f48;
                                    alignas(8) int64_t f49;
                                    alignas(8) int64_t f50;
                                    alignas(8) int64_t f51;
                                    alignas(8) int64_t f52;
                                    alignas(8) int64_t f53;
                                    alignas(8) int64_t f54;
                                    alignas(8) int64_t f55;
                                    alignas(8) int64_t f56;
                                    alignas(8) int64_t f57;
                                    alignas(8) int64_t f58;
                                    alignas(8) int64_t f59;
                                    alignas(8) int64_t f60;
                                    alignas(8) int64_t f61;
                                    alignas(8) int64_t f62;
                                    alignas(8) int64_t f63;
                                    alignas(8) int64_t f64;
                                    alignas(8) M25* f65;
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
                            
                                inline void set_f33(int64_t val){
                                    f33 = val;
                                }
                                inline int64_t& get_f33(){
                                    return f33;
                                }
                            
                                inline void set_f34(int64_t val){
                                    f34 = val;
                                }
                                inline int64_t& get_f34(){
                                    return f34;
                                }
                            
                                inline void set_f35(int64_t val){
                                    f35 = val;
                                }
                                inline int64_t& get_f35(){
                                    return f35;
                                }
                            
                                inline void set_f36(int64_t val){
                                    f36 = val;
                                }
                                inline int64_t& get_f36(){
                                    return f36;
                                }
                            
                                inline void set_f37(int64_t val){
                                    f37 = val;
                                }
                                inline int64_t& get_f37(){
                                    return f37;
                                }
                            
                                inline void set_f38(int64_t val){
                                    f38 = val;
                                }
                                inline int64_t& get_f38(){
                                    return f38;
                                }
                            
                                inline void set_f39(int64_t val){
                                    f39 = val;
                                }
                                inline int64_t& get_f39(){
                                    return f39;
                                }
                            
                                inline void set_f40(int64_t val){
                                    f40 = val;
                                }
                                inline int64_t& get_f40(){
                                    return f40;
                                }
                            
                                inline void set_f41(int64_t val){
                                    f41 = val;
                                }
                                inline int64_t& get_f41(){
                                    return f41;
                                }
                            
                                inline void set_f42(int64_t val){
                                    f42 = val;
                                }
                                inline int64_t& get_f42(){
                                    return f42;
                                }
                            
                                inline void set_f43(int64_t val){
                                    f43 = val;
                                }
                                inline int64_t& get_f43(){
                                    return f43;
                                }
                            
                                inline void set_f44(int64_t val){
                                    f44 = val;
                                }
                                inline int64_t& get_f44(){
                                    return f44;
                                }
                            
                                inline void set_f45(int64_t val){
                                    f45 = val;
                                }
                                inline int64_t& get_f45(){
                                    return f45;
                                }
                            
                                inline void set_f46(int64_t val){
                                    f46 = val;
                                }
                                inline int64_t& get_f46(){
                                    return f46;
                                }
                            
                                inline void set_f47(int64_t val){
                                    f47 = val;
                                }
                                inline int64_t& get_f47(){
                                    return f47;
                                }
                            
                                inline void set_f48(int64_t val){
                                    f48 = val;
                                }
                                inline int64_t& get_f48(){
                                    return f48;
                                }
                            
                                inline void set_f49(int64_t val){
                                    f49 = val;
                                }
                                inline int64_t& get_f49(){
                                    return f49;
                                }
                            
                                inline void set_f50(int64_t val){
                                    f50 = val;
                                }
                                inline int64_t& get_f50(){
                                    return f50;
                                }
                            
                                inline void set_f51(int64_t val){
                                    f51 = val;
                                }
                                inline int64_t& get_f51(){
                                    return f51;
                                }
                            
                                inline void set_f52(int64_t val){
                                    f52 = val;
                                }
                                inline int64_t& get_f52(){
                                    return f52;
                                }
                            
                                inline void set_f53(int64_t val){
                                    f53 = val;
                                }
                                inline int64_t& get_f53(){
                                    return f53;
                                }
                            
                                inline void set_f54(int64_t val){
                                    f54 = val;
                                }
                                inline int64_t& get_f54(){
                                    return f54;
                                }
                            
                                inline void set_f55(int64_t val){
                                    f55 = val;
                                }
                                inline int64_t& get_f55(){
                                    return f55;
                                }
                            
                                inline void set_f56(int64_t val){
                                    f56 = val;
                                }
                                inline int64_t& get_f56(){
                                    return f56;
                                }
                            
                                inline void set_f57(int64_t val){
                                    f57 = val;
                                }
                                inline int64_t& get_f57(){
                                    return f57;
                                }
                            
                                inline void set_f58(int64_t val){
                                    f58 = val;
                                }
                                inline int64_t& get_f58(){
                                    return f58;
                                }
                            
                                inline void set_f59(int64_t val){
                                    f59 = val;
                                }
                                inline int64_t& get_f59(){
                                    return f59;
                                }
                            
                                inline void set_f60(int64_t val){
                                    f60 = val;
                                }
                                inline int64_t& get_f60(){
                                    return f60;
                                }
                            
                                inline void set_f61(int64_t val){
                                    f61 = val;
                                }
                                inline int64_t& get_f61(){
                                    return f61;
                                }
                            
                                inline void set_f62(int64_t val){
                                    f62 = val;
                                }
                                inline int64_t& get_f62(){
                                    return f62;
                                }
                            
                                inline void set_f63(int64_t val){
                                    f63 = val;
                                }
                                inline int64_t& get_f63(){
                                    return f63;
                                }
                            
                                inline void set_f64(int64_t val){
                                    f64 = val;
                                }
                                inline int64_t& get_f64(){
                                    return f64;
                                }
                            
                                inline M24* mutable_f65(){
                                    f65 = new M24();
                                    return f65;
                                }
                                inline M24*& get_f65(){
                                    return f65;
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
                                    fout << "M23->f33: " << f33 << std::endl;
                                    fout << "M23->f34: " << f34 << std::endl;
                                    fout << "M23->f35: " << f35 << std::endl;
                                    fout << "M23->f36: " << f36 << std::endl;
                                    fout << "M23->f37: " << f37 << std::endl;
                                    fout << "M23->f38: " << f38 << std::endl;
                                    fout << "M23->f39: " << f39 << std::endl;
                                    fout << "M23->f40: " << f40 << std::endl;
                                    fout << "M23->f41: " << f41 << std::endl;
                                    fout << "M23->f42: " << f42 << std::endl;
                                    fout << "M23->f43: " << f43 << std::endl;
                                    fout << "M23->f44: " << f44 << std::endl;
                                    fout << "M23->f45: " << f45 << std::endl;
                                    fout << "M23->f46: " << f46 << std::endl;
                                    fout << "M23->f47: " << f47 << std::endl;
                                    fout << "M23->f48: " << f48 << std::endl;
                                    fout << "M23->f49: " << f49 << std::endl;
                                    fout << "M23->f50: " << f50 << std::endl;
                                    fout << "M23->f51: " << f51 << std::endl;
                                    fout << "M23->f52: " << f52 << std::endl;
                                    fout << "M23->f53: " << f53 << std::endl;
                                    fout << "M23->f54: " << f54 << std::endl;
                                    fout << "M23->f55: " << f55 << std::endl;
                                    fout << "M23->f56: " << f56 << std::endl;
                                    fout << "M23->f57: " << f57 << std::endl;
                                    fout << "M23->f58: " << f58 << std::endl;
                                    fout << "M23->f59: " << f59 << std::endl;
                                    fout << "M23->f60: " << f60 << std::endl;
                                    fout << "M23->f61: " << f61 << std::endl;
                                    fout << "M23->f62: " << f62 << std::endl;
                                    fout << "M23->f63: " << f63 << std::endl;
                                    fout << "M23->f64: " << f64 << std::endl;
                                    if(f65 != nullptr)
                                        f65->print_message(fout);
                                }
                            
                                ~M23(){
                                    if(f65 != nullptr)
                                        delete f65;
                                }
                            
                                M23(){
                                   f65 = nullptr;
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
                                alignas(8) int64_t f33;
                                alignas(8) int64_t f34;
                                alignas(8) int64_t f35;
                                alignas(8) int64_t f36;
                                alignas(8) int64_t f37;
                                alignas(8) int64_t f38;
                                alignas(8) int64_t f39;
                                alignas(8) int64_t f40;
                                alignas(8) int64_t f41;
                                alignas(8) int64_t f42;
                                alignas(8) int64_t f43;
                                alignas(8) int64_t f44;
                                alignas(8) int64_t f45;
                                alignas(8) int64_t f46;
                                alignas(8) int64_t f47;
                                alignas(8) int64_t f48;
                                alignas(8) int64_t f49;
                                alignas(8) int64_t f50;
                                alignas(8) int64_t f51;
                                alignas(8) int64_t f52;
                                alignas(8) int64_t f53;
                                alignas(8) int64_t f54;
                                alignas(8) int64_t f55;
                                alignas(8) int64_t f56;
                                alignas(8) int64_t f57;
                                alignas(8) int64_t f58;
                                alignas(8) int64_t f59;
                                alignas(8) int64_t f60;
                                alignas(8) int64_t f61;
                                alignas(8) int64_t f62;
                                alignas(8) int64_t f63;
                                alignas(8) int64_t f64;
                                alignas(8) M24* f65;
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
                        
                            inline void set_f33(int64_t val){
                                f33 = val;
                            }
                            inline int64_t& get_f33(){
                                return f33;
                            }
                        
                            inline void set_f34(int64_t val){
                                f34 = val;
                            }
                            inline int64_t& get_f34(){
                                return f34;
                            }
                        
                            inline void set_f35(int64_t val){
                                f35 = val;
                            }
                            inline int64_t& get_f35(){
                                return f35;
                            }
                        
                            inline void set_f36(int64_t val){
                                f36 = val;
                            }
                            inline int64_t& get_f36(){
                                return f36;
                            }
                        
                            inline void set_f37(int64_t val){
                                f37 = val;
                            }
                            inline int64_t& get_f37(){
                                return f37;
                            }
                        
                            inline void set_f38(int64_t val){
                                f38 = val;
                            }
                            inline int64_t& get_f38(){
                                return f38;
                            }
                        
                            inline void set_f39(int64_t val){
                                f39 = val;
                            }
                            inline int64_t& get_f39(){
                                return f39;
                            }
                        
                            inline void set_f40(int64_t val){
                                f40 = val;
                            }
                            inline int64_t& get_f40(){
                                return f40;
                            }
                        
                            inline void set_f41(int64_t val){
                                f41 = val;
                            }
                            inline int64_t& get_f41(){
                                return f41;
                            }
                        
                            inline void set_f42(int64_t val){
                                f42 = val;
                            }
                            inline int64_t& get_f42(){
                                return f42;
                            }
                        
                            inline void set_f43(int64_t val){
                                f43 = val;
                            }
                            inline int64_t& get_f43(){
                                return f43;
                            }
                        
                            inline void set_f44(int64_t val){
                                f44 = val;
                            }
                            inline int64_t& get_f44(){
                                return f44;
                            }
                        
                            inline void set_f45(int64_t val){
                                f45 = val;
                            }
                            inline int64_t& get_f45(){
                                return f45;
                            }
                        
                            inline void set_f46(int64_t val){
                                f46 = val;
                            }
                            inline int64_t& get_f46(){
                                return f46;
                            }
                        
                            inline void set_f47(int64_t val){
                                f47 = val;
                            }
                            inline int64_t& get_f47(){
                                return f47;
                            }
                        
                            inline void set_f48(int64_t val){
                                f48 = val;
                            }
                            inline int64_t& get_f48(){
                                return f48;
                            }
                        
                            inline void set_f49(int64_t val){
                                f49 = val;
                            }
                            inline int64_t& get_f49(){
                                return f49;
                            }
                        
                            inline void set_f50(int64_t val){
                                f50 = val;
                            }
                            inline int64_t& get_f50(){
                                return f50;
                            }
                        
                            inline void set_f51(int64_t val){
                                f51 = val;
                            }
                            inline int64_t& get_f51(){
                                return f51;
                            }
                        
                            inline void set_f52(int64_t val){
                                f52 = val;
                            }
                            inline int64_t& get_f52(){
                                return f52;
                            }
                        
                            inline void set_f53(int64_t val){
                                f53 = val;
                            }
                            inline int64_t& get_f53(){
                                return f53;
                            }
                        
                            inline void set_f54(int64_t val){
                                f54 = val;
                            }
                            inline int64_t& get_f54(){
                                return f54;
                            }
                        
                            inline void set_f55(int64_t val){
                                f55 = val;
                            }
                            inline int64_t& get_f55(){
                                return f55;
                            }
                        
                            inline void set_f56(int64_t val){
                                f56 = val;
                            }
                            inline int64_t& get_f56(){
                                return f56;
                            }
                        
                            inline void set_f57(int64_t val){
                                f57 = val;
                            }
                            inline int64_t& get_f57(){
                                return f57;
                            }
                        
                            inline void set_f58(int64_t val){
                                f58 = val;
                            }
                            inline int64_t& get_f58(){
                                return f58;
                            }
                        
                            inline void set_f59(int64_t val){
                                f59 = val;
                            }
                            inline int64_t& get_f59(){
                                return f59;
                            }
                        
                            inline void set_f60(int64_t val){
                                f60 = val;
                            }
                            inline int64_t& get_f60(){
                                return f60;
                            }
                        
                            inline void set_f61(int64_t val){
                                f61 = val;
                            }
                            inline int64_t& get_f61(){
                                return f61;
                            }
                        
                            inline void set_f62(int64_t val){
                                f62 = val;
                            }
                            inline int64_t& get_f62(){
                                return f62;
                            }
                        
                            inline void set_f63(int64_t val){
                                f63 = val;
                            }
                            inline int64_t& get_f63(){
                                return f63;
                            }
                        
                            inline void set_f64(int64_t val){
                                f64 = val;
                            }
                            inline int64_t& get_f64(){
                                return f64;
                            }
                        
                            inline M23* mutable_f65(){
                                f65 = new M23();
                                return f65;
                            }
                            inline M23*& get_f65(){
                                return f65;
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
                                fout << "M22->f33: " << f33 << std::endl;
                                fout << "M22->f34: " << f34 << std::endl;
                                fout << "M22->f35: " << f35 << std::endl;
                                fout << "M22->f36: " << f36 << std::endl;
                                fout << "M22->f37: " << f37 << std::endl;
                                fout << "M22->f38: " << f38 << std::endl;
                                fout << "M22->f39: " << f39 << std::endl;
                                fout << "M22->f40: " << f40 << std::endl;
                                fout << "M22->f41: " << f41 << std::endl;
                                fout << "M22->f42: " << f42 << std::endl;
                                fout << "M22->f43: " << f43 << std::endl;
                                fout << "M22->f44: " << f44 << std::endl;
                                fout << "M22->f45: " << f45 << std::endl;
                                fout << "M22->f46: " << f46 << std::endl;
                                fout << "M22->f47: " << f47 << std::endl;
                                fout << "M22->f48: " << f48 << std::endl;
                                fout << "M22->f49: " << f49 << std::endl;
                                fout << "M22->f50: " << f50 << std::endl;
                                fout << "M22->f51: " << f51 << std::endl;
                                fout << "M22->f52: " << f52 << std::endl;
                                fout << "M22->f53: " << f53 << std::endl;
                                fout << "M22->f54: " << f54 << std::endl;
                                fout << "M22->f55: " << f55 << std::endl;
                                fout << "M22->f56: " << f56 << std::endl;
                                fout << "M22->f57: " << f57 << std::endl;
                                fout << "M22->f58: " << f58 << std::endl;
                                fout << "M22->f59: " << f59 << std::endl;
                                fout << "M22->f60: " << f60 << std::endl;
                                fout << "M22->f61: " << f61 << std::endl;
                                fout << "M22->f62: " << f62 << std::endl;
                                fout << "M22->f63: " << f63 << std::endl;
                                fout << "M22->f64: " << f64 << std::endl;
                                if(f65 != nullptr)
                                    f65->print_message(fout);
                            }
                        
                            ~M22(){
                                if(f65 != nullptr)
                                    delete f65;
                            }
                        
                            M22(){
                               f65 = nullptr;
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
                            alignas(8) int64_t f33;
                            alignas(8) int64_t f34;
                            alignas(8) int64_t f35;
                            alignas(8) int64_t f36;
                            alignas(8) int64_t f37;
                            alignas(8) int64_t f38;
                            alignas(8) int64_t f39;
                            alignas(8) int64_t f40;
                            alignas(8) int64_t f41;
                            alignas(8) int64_t f42;
                            alignas(8) int64_t f43;
                            alignas(8) int64_t f44;
                            alignas(8) int64_t f45;
                            alignas(8) int64_t f46;
                            alignas(8) int64_t f47;
                            alignas(8) int64_t f48;
                            alignas(8) int64_t f49;
                            alignas(8) int64_t f50;
                            alignas(8) int64_t f51;
                            alignas(8) int64_t f52;
                            alignas(8) int64_t f53;
                            alignas(8) int64_t f54;
                            alignas(8) int64_t f55;
                            alignas(8) int64_t f56;
                            alignas(8) int64_t f57;
                            alignas(8) int64_t f58;
                            alignas(8) int64_t f59;
                            alignas(8) int64_t f60;
                            alignas(8) int64_t f61;
                            alignas(8) int64_t f62;
                            alignas(8) int64_t f63;
                            alignas(8) int64_t f64;
                            alignas(8) M23* f65;
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
                    
                        inline void set_f33(int64_t val){
                            f33 = val;
                        }
                        inline int64_t& get_f33(){
                            return f33;
                        }
                    
                        inline void set_f34(int64_t val){
                            f34 = val;
                        }
                        inline int64_t& get_f34(){
                            return f34;
                        }
                    
                        inline void set_f35(int64_t val){
                            f35 = val;
                        }
                        inline int64_t& get_f35(){
                            return f35;
                        }
                    
                        inline void set_f36(int64_t val){
                            f36 = val;
                        }
                        inline int64_t& get_f36(){
                            return f36;
                        }
                    
                        inline void set_f37(int64_t val){
                            f37 = val;
                        }
                        inline int64_t& get_f37(){
                            return f37;
                        }
                    
                        inline void set_f38(int64_t val){
                            f38 = val;
                        }
                        inline int64_t& get_f38(){
                            return f38;
                        }
                    
                        inline void set_f39(int64_t val){
                            f39 = val;
                        }
                        inline int64_t& get_f39(){
                            return f39;
                        }
                    
                        inline void set_f40(int64_t val){
                            f40 = val;
                        }
                        inline int64_t& get_f40(){
                            return f40;
                        }
                    
                        inline void set_f41(int64_t val){
                            f41 = val;
                        }
                        inline int64_t& get_f41(){
                            return f41;
                        }
                    
                        inline void set_f42(int64_t val){
                            f42 = val;
                        }
                        inline int64_t& get_f42(){
                            return f42;
                        }
                    
                        inline void set_f43(int64_t val){
                            f43 = val;
                        }
                        inline int64_t& get_f43(){
                            return f43;
                        }
                    
                        inline void set_f44(int64_t val){
                            f44 = val;
                        }
                        inline int64_t& get_f44(){
                            return f44;
                        }
                    
                        inline void set_f45(int64_t val){
                            f45 = val;
                        }
                        inline int64_t& get_f45(){
                            return f45;
                        }
                    
                        inline void set_f46(int64_t val){
                            f46 = val;
                        }
                        inline int64_t& get_f46(){
                            return f46;
                        }
                    
                        inline void set_f47(int64_t val){
                            f47 = val;
                        }
                        inline int64_t& get_f47(){
                            return f47;
                        }
                    
                        inline void set_f48(int64_t val){
                            f48 = val;
                        }
                        inline int64_t& get_f48(){
                            return f48;
                        }
                    
                        inline void set_f49(int64_t val){
                            f49 = val;
                        }
                        inline int64_t& get_f49(){
                            return f49;
                        }
                    
                        inline void set_f50(int64_t val){
                            f50 = val;
                        }
                        inline int64_t& get_f50(){
                            return f50;
                        }
                    
                        inline void set_f51(int64_t val){
                            f51 = val;
                        }
                        inline int64_t& get_f51(){
                            return f51;
                        }
                    
                        inline void set_f52(int64_t val){
                            f52 = val;
                        }
                        inline int64_t& get_f52(){
                            return f52;
                        }
                    
                        inline void set_f53(int64_t val){
                            f53 = val;
                        }
                        inline int64_t& get_f53(){
                            return f53;
                        }
                    
                        inline void set_f54(int64_t val){
                            f54 = val;
                        }
                        inline int64_t& get_f54(){
                            return f54;
                        }
                    
                        inline void set_f55(int64_t val){
                            f55 = val;
                        }
                        inline int64_t& get_f55(){
                            return f55;
                        }
                    
                        inline void set_f56(int64_t val){
                            f56 = val;
                        }
                        inline int64_t& get_f56(){
                            return f56;
                        }
                    
                        inline void set_f57(int64_t val){
                            f57 = val;
                        }
                        inline int64_t& get_f57(){
                            return f57;
                        }
                    
                        inline void set_f58(int64_t val){
                            f58 = val;
                        }
                        inline int64_t& get_f58(){
                            return f58;
                        }
                    
                        inline void set_f59(int64_t val){
                            f59 = val;
                        }
                        inline int64_t& get_f59(){
                            return f59;
                        }
                    
                        inline void set_f60(int64_t val){
                            f60 = val;
                        }
                        inline int64_t& get_f60(){
                            return f60;
                        }
                    
                        inline void set_f61(int64_t val){
                            f61 = val;
                        }
                        inline int64_t& get_f61(){
                            return f61;
                        }
                    
                        inline void set_f62(int64_t val){
                            f62 = val;
                        }
                        inline int64_t& get_f62(){
                            return f62;
                        }
                    
                        inline void set_f63(int64_t val){
                            f63 = val;
                        }
                        inline int64_t& get_f63(){
                            return f63;
                        }
                    
                        inline void set_f64(int64_t val){
                            f64 = val;
                        }
                        inline int64_t& get_f64(){
                            return f64;
                        }
                    
                        inline M22* mutable_f65(){
                            f65 = new M22();
                            return f65;
                        }
                        inline M22*& get_f65(){
                            return f65;
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
                            fout << "M21->f33: " << f33 << std::endl;
                            fout << "M21->f34: " << f34 << std::endl;
                            fout << "M21->f35: " << f35 << std::endl;
                            fout << "M21->f36: " << f36 << std::endl;
                            fout << "M21->f37: " << f37 << std::endl;
                            fout << "M21->f38: " << f38 << std::endl;
                            fout << "M21->f39: " << f39 << std::endl;
                            fout << "M21->f40: " << f40 << std::endl;
                            fout << "M21->f41: " << f41 << std::endl;
                            fout << "M21->f42: " << f42 << std::endl;
                            fout << "M21->f43: " << f43 << std::endl;
                            fout << "M21->f44: " << f44 << std::endl;
                            fout << "M21->f45: " << f45 << std::endl;
                            fout << "M21->f46: " << f46 << std::endl;
                            fout << "M21->f47: " << f47 << std::endl;
                            fout << "M21->f48: " << f48 << std::endl;
                            fout << "M21->f49: " << f49 << std::endl;
                            fout << "M21->f50: " << f50 << std::endl;
                            fout << "M21->f51: " << f51 << std::endl;
                            fout << "M21->f52: " << f52 << std::endl;
                            fout << "M21->f53: " << f53 << std::endl;
                            fout << "M21->f54: " << f54 << std::endl;
                            fout << "M21->f55: " << f55 << std::endl;
                            fout << "M21->f56: " << f56 << std::endl;
                            fout << "M21->f57: " << f57 << std::endl;
                            fout << "M21->f58: " << f58 << std::endl;
                            fout << "M21->f59: " << f59 << std::endl;
                            fout << "M21->f60: " << f60 << std::endl;
                            fout << "M21->f61: " << f61 << std::endl;
                            fout << "M21->f62: " << f62 << std::endl;
                            fout << "M21->f63: " << f63 << std::endl;
                            fout << "M21->f64: " << f64 << std::endl;
                            if(f65 != nullptr)
                                f65->print_message(fout);
                        }
                    
                        ~M21(){
                            if(f65 != nullptr)
                                delete f65;
                        }
                    
                        M21(){
                           f65 = nullptr;
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
                        alignas(8) int64_t f33;
                        alignas(8) int64_t f34;
                        alignas(8) int64_t f35;
                        alignas(8) int64_t f36;
                        alignas(8) int64_t f37;
                        alignas(8) int64_t f38;
                        alignas(8) int64_t f39;
                        alignas(8) int64_t f40;
                        alignas(8) int64_t f41;
                        alignas(8) int64_t f42;
                        alignas(8) int64_t f43;
                        alignas(8) int64_t f44;
                        alignas(8) int64_t f45;
                        alignas(8) int64_t f46;
                        alignas(8) int64_t f47;
                        alignas(8) int64_t f48;
                        alignas(8) int64_t f49;
                        alignas(8) int64_t f50;
                        alignas(8) int64_t f51;
                        alignas(8) int64_t f52;
                        alignas(8) int64_t f53;
                        alignas(8) int64_t f54;
                        alignas(8) int64_t f55;
                        alignas(8) int64_t f56;
                        alignas(8) int64_t f57;
                        alignas(8) int64_t f58;
                        alignas(8) int64_t f59;
                        alignas(8) int64_t f60;
                        alignas(8) int64_t f61;
                        alignas(8) int64_t f62;
                        alignas(8) int64_t f63;
                        alignas(8) int64_t f64;
                        alignas(8) M22* f65;
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
                
                    inline void set_f33(int64_t val){
                        f33 = val;
                    }
                    inline int64_t& get_f33(){
                        return f33;
                    }
                
                    inline void set_f34(int64_t val){
                        f34 = val;
                    }
                    inline int64_t& get_f34(){
                        return f34;
                    }
                
                    inline void set_f35(int64_t val){
                        f35 = val;
                    }
                    inline int64_t& get_f35(){
                        return f35;
                    }
                
                    inline void set_f36(int64_t val){
                        f36 = val;
                    }
                    inline int64_t& get_f36(){
                        return f36;
                    }
                
                    inline void set_f37(int64_t val){
                        f37 = val;
                    }
                    inline int64_t& get_f37(){
                        return f37;
                    }
                
                    inline void set_f38(int64_t val){
                        f38 = val;
                    }
                    inline int64_t& get_f38(){
                        return f38;
                    }
                
                    inline void set_f39(int64_t val){
                        f39 = val;
                    }
                    inline int64_t& get_f39(){
                        return f39;
                    }
                
                    inline void set_f40(int64_t val){
                        f40 = val;
                    }
                    inline int64_t& get_f40(){
                        return f40;
                    }
                
                    inline void set_f41(int64_t val){
                        f41 = val;
                    }
                    inline int64_t& get_f41(){
                        return f41;
                    }
                
                    inline void set_f42(int64_t val){
                        f42 = val;
                    }
                    inline int64_t& get_f42(){
                        return f42;
                    }
                
                    inline void set_f43(int64_t val){
                        f43 = val;
                    }
                    inline int64_t& get_f43(){
                        return f43;
                    }
                
                    inline void set_f44(int64_t val){
                        f44 = val;
                    }
                    inline int64_t& get_f44(){
                        return f44;
                    }
                
                    inline void set_f45(int64_t val){
                        f45 = val;
                    }
                    inline int64_t& get_f45(){
                        return f45;
                    }
                
                    inline void set_f46(int64_t val){
                        f46 = val;
                    }
                    inline int64_t& get_f46(){
                        return f46;
                    }
                
                    inline void set_f47(int64_t val){
                        f47 = val;
                    }
                    inline int64_t& get_f47(){
                        return f47;
                    }
                
                    inline void set_f48(int64_t val){
                        f48 = val;
                    }
                    inline int64_t& get_f48(){
                        return f48;
                    }
                
                    inline void set_f49(int64_t val){
                        f49 = val;
                    }
                    inline int64_t& get_f49(){
                        return f49;
                    }
                
                    inline void set_f50(int64_t val){
                        f50 = val;
                    }
                    inline int64_t& get_f50(){
                        return f50;
                    }
                
                    inline void set_f51(int64_t val){
                        f51 = val;
                    }
                    inline int64_t& get_f51(){
                        return f51;
                    }
                
                    inline void set_f52(int64_t val){
                        f52 = val;
                    }
                    inline int64_t& get_f52(){
                        return f52;
                    }
                
                    inline void set_f53(int64_t val){
                        f53 = val;
                    }
                    inline int64_t& get_f53(){
                        return f53;
                    }
                
                    inline void set_f54(int64_t val){
                        f54 = val;
                    }
                    inline int64_t& get_f54(){
                        return f54;
                    }
                
                    inline void set_f55(int64_t val){
                        f55 = val;
                    }
                    inline int64_t& get_f55(){
                        return f55;
                    }
                
                    inline void set_f56(int64_t val){
                        f56 = val;
                    }
                    inline int64_t& get_f56(){
                        return f56;
                    }
                
                    inline void set_f57(int64_t val){
                        f57 = val;
                    }
                    inline int64_t& get_f57(){
                        return f57;
                    }
                
                    inline void set_f58(int64_t val){
                        f58 = val;
                    }
                    inline int64_t& get_f58(){
                        return f58;
                    }
                
                    inline void set_f59(int64_t val){
                        f59 = val;
                    }
                    inline int64_t& get_f59(){
                        return f59;
                    }
                
                    inline void set_f60(int64_t val){
                        f60 = val;
                    }
                    inline int64_t& get_f60(){
                        return f60;
                    }
                
                    inline void set_f61(int64_t val){
                        f61 = val;
                    }
                    inline int64_t& get_f61(){
                        return f61;
                    }
                
                    inline void set_f62(int64_t val){
                        f62 = val;
                    }
                    inline int64_t& get_f62(){
                        return f62;
                    }
                
                    inline void set_f63(int64_t val){
                        f63 = val;
                    }
                    inline int64_t& get_f63(){
                        return f63;
                    }
                
                    inline void set_f64(int64_t val){
                        f64 = val;
                    }
                    inline int64_t& get_f64(){
                        return f64;
                    }
                
                    inline M21* mutable_f65(){
                        f65 = new M21();
                        return f65;
                    }
                    inline M21*& get_f65(){
                        return f65;
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
                        fout << "M20->f33: " << f33 << std::endl;
                        fout << "M20->f34: " << f34 << std::endl;
                        fout << "M20->f35: " << f35 << std::endl;
                        fout << "M20->f36: " << f36 << std::endl;
                        fout << "M20->f37: " << f37 << std::endl;
                        fout << "M20->f38: " << f38 << std::endl;
                        fout << "M20->f39: " << f39 << std::endl;
                        fout << "M20->f40: " << f40 << std::endl;
                        fout << "M20->f41: " << f41 << std::endl;
                        fout << "M20->f42: " << f42 << std::endl;
                        fout << "M20->f43: " << f43 << std::endl;
                        fout << "M20->f44: " << f44 << std::endl;
                        fout << "M20->f45: " << f45 << std::endl;
                        fout << "M20->f46: " << f46 << std::endl;
                        fout << "M20->f47: " << f47 << std::endl;
                        fout << "M20->f48: " << f48 << std::endl;
                        fout << "M20->f49: " << f49 << std::endl;
                        fout << "M20->f50: " << f50 << std::endl;
                        fout << "M20->f51: " << f51 << std::endl;
                        fout << "M20->f52: " << f52 << std::endl;
                        fout << "M20->f53: " << f53 << std::endl;
                        fout << "M20->f54: " << f54 << std::endl;
                        fout << "M20->f55: " << f55 << std::endl;
                        fout << "M20->f56: " << f56 << std::endl;
                        fout << "M20->f57: " << f57 << std::endl;
                        fout << "M20->f58: " << f58 << std::endl;
                        fout << "M20->f59: " << f59 << std::endl;
                        fout << "M20->f60: " << f60 << std::endl;
                        fout << "M20->f61: " << f61 << std::endl;
                        fout << "M20->f62: " << f62 << std::endl;
                        fout << "M20->f63: " << f63 << std::endl;
                        fout << "M20->f64: " << f64 << std::endl;
                        if(f65 != nullptr)
                            f65->print_message(fout);
                    }
                
                    ~M20(){
                        if(f65 != nullptr)
                            delete f65;
                    }
                
                    M20(){
                       f65 = nullptr;
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
                    alignas(8) int64_t f33;
                    alignas(8) int64_t f34;
                    alignas(8) int64_t f35;
                    alignas(8) int64_t f36;
                    alignas(8) int64_t f37;
                    alignas(8) int64_t f38;
                    alignas(8) int64_t f39;
                    alignas(8) int64_t f40;
                    alignas(8) int64_t f41;
                    alignas(8) int64_t f42;
                    alignas(8) int64_t f43;
                    alignas(8) int64_t f44;
                    alignas(8) int64_t f45;
                    alignas(8) int64_t f46;
                    alignas(8) int64_t f47;
                    alignas(8) int64_t f48;
                    alignas(8) int64_t f49;
                    alignas(8) int64_t f50;
                    alignas(8) int64_t f51;
                    alignas(8) int64_t f52;
                    alignas(8) int64_t f53;
                    alignas(8) int64_t f54;
                    alignas(8) int64_t f55;
                    alignas(8) int64_t f56;
                    alignas(8) int64_t f57;
                    alignas(8) int64_t f58;
                    alignas(8) int64_t f59;
                    alignas(8) int64_t f60;
                    alignas(8) int64_t f61;
                    alignas(8) int64_t f62;
                    alignas(8) int64_t f63;
                    alignas(8) int64_t f64;
                    alignas(8) M21* f65;
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
            
                inline void set_f33(int64_t val){
                    f33 = val;
                }
                inline int64_t& get_f33(){
                    return f33;
                }
            
                inline void set_f34(int64_t val){
                    f34 = val;
                }
                inline int64_t& get_f34(){
                    return f34;
                }
            
                inline void set_f35(int64_t val){
                    f35 = val;
                }
                inline int64_t& get_f35(){
                    return f35;
                }
            
                inline void set_f36(int64_t val){
                    f36 = val;
                }
                inline int64_t& get_f36(){
                    return f36;
                }
            
                inline void set_f37(int64_t val){
                    f37 = val;
                }
                inline int64_t& get_f37(){
                    return f37;
                }
            
                inline void set_f38(int64_t val){
                    f38 = val;
                }
                inline int64_t& get_f38(){
                    return f38;
                }
            
                inline void set_f39(int64_t val){
                    f39 = val;
                }
                inline int64_t& get_f39(){
                    return f39;
                }
            
                inline void set_f40(int64_t val){
                    f40 = val;
                }
                inline int64_t& get_f40(){
                    return f40;
                }
            
                inline void set_f41(int64_t val){
                    f41 = val;
                }
                inline int64_t& get_f41(){
                    return f41;
                }
            
                inline void set_f42(int64_t val){
                    f42 = val;
                }
                inline int64_t& get_f42(){
                    return f42;
                }
            
                inline void set_f43(int64_t val){
                    f43 = val;
                }
                inline int64_t& get_f43(){
                    return f43;
                }
            
                inline void set_f44(int64_t val){
                    f44 = val;
                }
                inline int64_t& get_f44(){
                    return f44;
                }
            
                inline void set_f45(int64_t val){
                    f45 = val;
                }
                inline int64_t& get_f45(){
                    return f45;
                }
            
                inline void set_f46(int64_t val){
                    f46 = val;
                }
                inline int64_t& get_f46(){
                    return f46;
                }
            
                inline void set_f47(int64_t val){
                    f47 = val;
                }
                inline int64_t& get_f47(){
                    return f47;
                }
            
                inline void set_f48(int64_t val){
                    f48 = val;
                }
                inline int64_t& get_f48(){
                    return f48;
                }
            
                inline void set_f49(int64_t val){
                    f49 = val;
                }
                inline int64_t& get_f49(){
                    return f49;
                }
            
                inline void set_f50(int64_t val){
                    f50 = val;
                }
                inline int64_t& get_f50(){
                    return f50;
                }
            
                inline void set_f51(int64_t val){
                    f51 = val;
                }
                inline int64_t& get_f51(){
                    return f51;
                }
            
                inline void set_f52(int64_t val){
                    f52 = val;
                }
                inline int64_t& get_f52(){
                    return f52;
                }
            
                inline void set_f53(int64_t val){
                    f53 = val;
                }
                inline int64_t& get_f53(){
                    return f53;
                }
            
                inline void set_f54(int64_t val){
                    f54 = val;
                }
                inline int64_t& get_f54(){
                    return f54;
                }
            
                inline void set_f55(int64_t val){
                    f55 = val;
                }
                inline int64_t& get_f55(){
                    return f55;
                }
            
                inline void set_f56(int64_t val){
                    f56 = val;
                }
                inline int64_t& get_f56(){
                    return f56;
                }
            
                inline void set_f57(int64_t val){
                    f57 = val;
                }
                inline int64_t& get_f57(){
                    return f57;
                }
            
                inline void set_f58(int64_t val){
                    f58 = val;
                }
                inline int64_t& get_f58(){
                    return f58;
                }
            
                inline void set_f59(int64_t val){
                    f59 = val;
                }
                inline int64_t& get_f59(){
                    return f59;
                }
            
                inline void set_f60(int64_t val){
                    f60 = val;
                }
                inline int64_t& get_f60(){
                    return f60;
                }
            
                inline void set_f61(int64_t val){
                    f61 = val;
                }
                inline int64_t& get_f61(){
                    return f61;
                }
            
                inline void set_f62(int64_t val){
                    f62 = val;
                }
                inline int64_t& get_f62(){
                    return f62;
                }
            
                inline void set_f63(int64_t val){
                    f63 = val;
                }
                inline int64_t& get_f63(){
                    return f63;
                }
            
                inline void set_f64(int64_t val){
                    f64 = val;
                }
                inline int64_t& get_f64(){
                    return f64;
                }
            
                inline M20* mutable_f65(){
                    f65 = new M20();
                    return f65;
                }
                inline M20*& get_f65(){
                    return f65;
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
                    fout << "M19->f33: " << f33 << std::endl;
                    fout << "M19->f34: " << f34 << std::endl;
                    fout << "M19->f35: " << f35 << std::endl;
                    fout << "M19->f36: " << f36 << std::endl;
                    fout << "M19->f37: " << f37 << std::endl;
                    fout << "M19->f38: " << f38 << std::endl;
                    fout << "M19->f39: " << f39 << std::endl;
                    fout << "M19->f40: " << f40 << std::endl;
                    fout << "M19->f41: " << f41 << std::endl;
                    fout << "M19->f42: " << f42 << std::endl;
                    fout << "M19->f43: " << f43 << std::endl;
                    fout << "M19->f44: " << f44 << std::endl;
                    fout << "M19->f45: " << f45 << std::endl;
                    fout << "M19->f46: " << f46 << std::endl;
                    fout << "M19->f47: " << f47 << std::endl;
                    fout << "M19->f48: " << f48 << std::endl;
                    fout << "M19->f49: " << f49 << std::endl;
                    fout << "M19->f50: " << f50 << std::endl;
                    fout << "M19->f51: " << f51 << std::endl;
                    fout << "M19->f52: " << f52 << std::endl;
                    fout << "M19->f53: " << f53 << std::endl;
                    fout << "M19->f54: " << f54 << std::endl;
                    fout << "M19->f55: " << f55 << std::endl;
                    fout << "M19->f56: " << f56 << std::endl;
                    fout << "M19->f57: " << f57 << std::endl;
                    fout << "M19->f58: " << f58 << std::endl;
                    fout << "M19->f59: " << f59 << std::endl;
                    fout << "M19->f60: " << f60 << std::endl;
                    fout << "M19->f61: " << f61 << std::endl;
                    fout << "M19->f62: " << f62 << std::endl;
                    fout << "M19->f63: " << f63 << std::endl;
                    fout << "M19->f64: " << f64 << std::endl;
                    if(f65 != nullptr)
                        f65->print_message(fout);
                }
            
                ~M19(){
                    if(f65 != nullptr)
                        delete f65;
                }
            
                M19(){
                   f65 = nullptr;
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
                alignas(8) int64_t f33;
                alignas(8) int64_t f34;
                alignas(8) int64_t f35;
                alignas(8) int64_t f36;
                alignas(8) int64_t f37;
                alignas(8) int64_t f38;
                alignas(8) int64_t f39;
                alignas(8) int64_t f40;
                alignas(8) int64_t f41;
                alignas(8) int64_t f42;
                alignas(8) int64_t f43;
                alignas(8) int64_t f44;
                alignas(8) int64_t f45;
                alignas(8) int64_t f46;
                alignas(8) int64_t f47;
                alignas(8) int64_t f48;
                alignas(8) int64_t f49;
                alignas(8) int64_t f50;
                alignas(8) int64_t f51;
                alignas(8) int64_t f52;
                alignas(8) int64_t f53;
                alignas(8) int64_t f54;
                alignas(8) int64_t f55;
                alignas(8) int64_t f56;
                alignas(8) int64_t f57;
                alignas(8) int64_t f58;
                alignas(8) int64_t f59;
                alignas(8) int64_t f60;
                alignas(8) int64_t f61;
                alignas(8) int64_t f62;
                alignas(8) int64_t f63;
                alignas(8) int64_t f64;
                alignas(8) M20* f65;
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
        
            inline void set_f33(int64_t val){
                f33 = val;
            }
            inline int64_t& get_f33(){
                return f33;
            }
        
            inline void set_f34(int64_t val){
                f34 = val;
            }
            inline int64_t& get_f34(){
                return f34;
            }
        
            inline void set_f35(int64_t val){
                f35 = val;
            }
            inline int64_t& get_f35(){
                return f35;
            }
        
            inline void set_f36(int64_t val){
                f36 = val;
            }
            inline int64_t& get_f36(){
                return f36;
            }
        
            inline void set_f37(int64_t val){
                f37 = val;
            }
            inline int64_t& get_f37(){
                return f37;
            }
        
            inline void set_f38(int64_t val){
                f38 = val;
            }
            inline int64_t& get_f38(){
                return f38;
            }
        
            inline void set_f39(int64_t val){
                f39 = val;
            }
            inline int64_t& get_f39(){
                return f39;
            }
        
            inline void set_f40(int64_t val){
                f40 = val;
            }
            inline int64_t& get_f40(){
                return f40;
            }
        
            inline void set_f41(int64_t val){
                f41 = val;
            }
            inline int64_t& get_f41(){
                return f41;
            }
        
            inline void set_f42(int64_t val){
                f42 = val;
            }
            inline int64_t& get_f42(){
                return f42;
            }
        
            inline void set_f43(int64_t val){
                f43 = val;
            }
            inline int64_t& get_f43(){
                return f43;
            }
        
            inline void set_f44(int64_t val){
                f44 = val;
            }
            inline int64_t& get_f44(){
                return f44;
            }
        
            inline void set_f45(int64_t val){
                f45 = val;
            }
            inline int64_t& get_f45(){
                return f45;
            }
        
            inline void set_f46(int64_t val){
                f46 = val;
            }
            inline int64_t& get_f46(){
                return f46;
            }
        
            inline void set_f47(int64_t val){
                f47 = val;
            }
            inline int64_t& get_f47(){
                return f47;
            }
        
            inline void set_f48(int64_t val){
                f48 = val;
            }
            inline int64_t& get_f48(){
                return f48;
            }
        
            inline void set_f49(int64_t val){
                f49 = val;
            }
            inline int64_t& get_f49(){
                return f49;
            }
        
            inline void set_f50(int64_t val){
                f50 = val;
            }
            inline int64_t& get_f50(){
                return f50;
            }
        
            inline void set_f51(int64_t val){
                f51 = val;
            }
            inline int64_t& get_f51(){
                return f51;
            }
        
            inline void set_f52(int64_t val){
                f52 = val;
            }
            inline int64_t& get_f52(){
                return f52;
            }
        
            inline void set_f53(int64_t val){
                f53 = val;
            }
            inline int64_t& get_f53(){
                return f53;
            }
        
            inline void set_f54(int64_t val){
                f54 = val;
            }
            inline int64_t& get_f54(){
                return f54;
            }
        
            inline void set_f55(int64_t val){
                f55 = val;
            }
            inline int64_t& get_f55(){
                return f55;
            }
        
            inline void set_f56(int64_t val){
                f56 = val;
            }
            inline int64_t& get_f56(){
                return f56;
            }
        
            inline void set_f57(int64_t val){
                f57 = val;
            }
            inline int64_t& get_f57(){
                return f57;
            }
        
            inline void set_f58(int64_t val){
                f58 = val;
            }
            inline int64_t& get_f58(){
                return f58;
            }
        
            inline void set_f59(int64_t val){
                f59 = val;
            }
            inline int64_t& get_f59(){
                return f59;
            }
        
            inline void set_f60(int64_t val){
                f60 = val;
            }
            inline int64_t& get_f60(){
                return f60;
            }
        
            inline void set_f61(int64_t val){
                f61 = val;
            }
            inline int64_t& get_f61(){
                return f61;
            }
        
            inline void set_f62(int64_t val){
                f62 = val;
            }
            inline int64_t& get_f62(){
                return f62;
            }
        
            inline void set_f63(int64_t val){
                f63 = val;
            }
            inline int64_t& get_f63(){
                return f63;
            }
        
            inline void set_f64(int64_t val){
                f64 = val;
            }
            inline int64_t& get_f64(){
                return f64;
            }
        
            inline M19* mutable_f65(){
                f65 = new M19();
                return f65;
            }
            inline M19*& get_f65(){
                return f65;
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
                fout << "M18->f33: " << f33 << std::endl;
                fout << "M18->f34: " << f34 << std::endl;
                fout << "M18->f35: " << f35 << std::endl;
                fout << "M18->f36: " << f36 << std::endl;
                fout << "M18->f37: " << f37 << std::endl;
                fout << "M18->f38: " << f38 << std::endl;
                fout << "M18->f39: " << f39 << std::endl;
                fout << "M18->f40: " << f40 << std::endl;
                fout << "M18->f41: " << f41 << std::endl;
                fout << "M18->f42: " << f42 << std::endl;
                fout << "M18->f43: " << f43 << std::endl;
                fout << "M18->f44: " << f44 << std::endl;
                fout << "M18->f45: " << f45 << std::endl;
                fout << "M18->f46: " << f46 << std::endl;
                fout << "M18->f47: " << f47 << std::endl;
                fout << "M18->f48: " << f48 << std::endl;
                fout << "M18->f49: " << f49 << std::endl;
                fout << "M18->f50: " << f50 << std::endl;
                fout << "M18->f51: " << f51 << std::endl;
                fout << "M18->f52: " << f52 << std::endl;
                fout << "M18->f53: " << f53 << std::endl;
                fout << "M18->f54: " << f54 << std::endl;
                fout << "M18->f55: " << f55 << std::endl;
                fout << "M18->f56: " << f56 << std::endl;
                fout << "M18->f57: " << f57 << std::endl;
                fout << "M18->f58: " << f58 << std::endl;
                fout << "M18->f59: " << f59 << std::endl;
                fout << "M18->f60: " << f60 << std::endl;
                fout << "M18->f61: " << f61 << std::endl;
                fout << "M18->f62: " << f62 << std::endl;
                fout << "M18->f63: " << f63 << std::endl;
                fout << "M18->f64: " << f64 << std::endl;
                if(f65 != nullptr)
                    f65->print_message(fout);
            }
        
            ~M18(){
                if(f65 != nullptr)
                    delete f65;
            }
        
            M18(){
               f65 = nullptr;
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
            alignas(8) int64_t f33;
            alignas(8) int64_t f34;
            alignas(8) int64_t f35;
            alignas(8) int64_t f36;
            alignas(8) int64_t f37;
            alignas(8) int64_t f38;
            alignas(8) int64_t f39;
            alignas(8) int64_t f40;
            alignas(8) int64_t f41;
            alignas(8) int64_t f42;
            alignas(8) int64_t f43;
            alignas(8) int64_t f44;
            alignas(8) int64_t f45;
            alignas(8) int64_t f46;
            alignas(8) int64_t f47;
            alignas(8) int64_t f48;
            alignas(8) int64_t f49;
            alignas(8) int64_t f50;
            alignas(8) int64_t f51;
            alignas(8) int64_t f52;
            alignas(8) int64_t f53;
            alignas(8) int64_t f54;
            alignas(8) int64_t f55;
            alignas(8) int64_t f56;
            alignas(8) int64_t f57;
            alignas(8) int64_t f58;
            alignas(8) int64_t f59;
            alignas(8) int64_t f60;
            alignas(8) int64_t f61;
            alignas(8) int64_t f62;
            alignas(8) int64_t f63;
            alignas(8) int64_t f64;
            alignas(8) M19* f65;
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
    
        inline void set_f33(int64_t val){
            f33 = val;
        }
        inline int64_t& get_f33(){
            return f33;
        }
    
        inline void set_f34(int64_t val){
            f34 = val;
        }
        inline int64_t& get_f34(){
            return f34;
        }
    
        inline void set_f35(int64_t val){
            f35 = val;
        }
        inline int64_t& get_f35(){
            return f35;
        }
    
        inline void set_f36(int64_t val){
            f36 = val;
        }
        inline int64_t& get_f36(){
            return f36;
        }
    
        inline void set_f37(int64_t val){
            f37 = val;
        }
        inline int64_t& get_f37(){
            return f37;
        }
    
        inline void set_f38(int64_t val){
            f38 = val;
        }
        inline int64_t& get_f38(){
            return f38;
        }
    
        inline void set_f39(int64_t val){
            f39 = val;
        }
        inline int64_t& get_f39(){
            return f39;
        }
    
        inline void set_f40(int64_t val){
            f40 = val;
        }
        inline int64_t& get_f40(){
            return f40;
        }
    
        inline void set_f41(int64_t val){
            f41 = val;
        }
        inline int64_t& get_f41(){
            return f41;
        }
    
        inline void set_f42(int64_t val){
            f42 = val;
        }
        inline int64_t& get_f42(){
            return f42;
        }
    
        inline void set_f43(int64_t val){
            f43 = val;
        }
        inline int64_t& get_f43(){
            return f43;
        }
    
        inline void set_f44(int64_t val){
            f44 = val;
        }
        inline int64_t& get_f44(){
            return f44;
        }
    
        inline void set_f45(int64_t val){
            f45 = val;
        }
        inline int64_t& get_f45(){
            return f45;
        }
    
        inline void set_f46(int64_t val){
            f46 = val;
        }
        inline int64_t& get_f46(){
            return f46;
        }
    
        inline void set_f47(int64_t val){
            f47 = val;
        }
        inline int64_t& get_f47(){
            return f47;
        }
    
        inline void set_f48(int64_t val){
            f48 = val;
        }
        inline int64_t& get_f48(){
            return f48;
        }
    
        inline void set_f49(int64_t val){
            f49 = val;
        }
        inline int64_t& get_f49(){
            return f49;
        }
    
        inline void set_f50(int64_t val){
            f50 = val;
        }
        inline int64_t& get_f50(){
            return f50;
        }
    
        inline void set_f51(int64_t val){
            f51 = val;
        }
        inline int64_t& get_f51(){
            return f51;
        }
    
        inline void set_f52(int64_t val){
            f52 = val;
        }
        inline int64_t& get_f52(){
            return f52;
        }
    
        inline void set_f53(int64_t val){
            f53 = val;
        }
        inline int64_t& get_f53(){
            return f53;
        }
    
        inline void set_f54(int64_t val){
            f54 = val;
        }
        inline int64_t& get_f54(){
            return f54;
        }
    
        inline void set_f55(int64_t val){
            f55 = val;
        }
        inline int64_t& get_f55(){
            return f55;
        }
    
        inline void set_f56(int64_t val){
            f56 = val;
        }
        inline int64_t& get_f56(){
            return f56;
        }
    
        inline void set_f57(int64_t val){
            f57 = val;
        }
        inline int64_t& get_f57(){
            return f57;
        }
    
        inline void set_f58(int64_t val){
            f58 = val;
        }
        inline int64_t& get_f58(){
            return f58;
        }
    
        inline void set_f59(int64_t val){
            f59 = val;
        }
        inline int64_t& get_f59(){
            return f59;
        }
    
        inline void set_f60(int64_t val){
            f60 = val;
        }
        inline int64_t& get_f60(){
            return f60;
        }
    
        inline void set_f61(int64_t val){
            f61 = val;
        }
        inline int64_t& get_f61(){
            return f61;
        }
    
        inline void set_f62(int64_t val){
            f62 = val;
        }
        inline int64_t& get_f62(){
            return f62;
        }
    
        inline void set_f63(int64_t val){
            f63 = val;
        }
        inline int64_t& get_f63(){
            return f63;
        }
    
        inline void set_f64(int64_t val){
            f64 = val;
        }
        inline int64_t& get_f64(){
            return f64;
        }
    
        inline M18* mutable_f65(){
            f65 = new M18();
            return f65;
        }
        inline M18*& get_f65(){
            return f65;
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
            fout << "M17->f33: " << f33 << std::endl;
            fout << "M17->f34: " << f34 << std::endl;
            fout << "M17->f35: " << f35 << std::endl;
            fout << "M17->f36: " << f36 << std::endl;
            fout << "M17->f37: " << f37 << std::endl;
            fout << "M17->f38: " << f38 << std::endl;
            fout << "M17->f39: " << f39 << std::endl;
            fout << "M17->f40: " << f40 << std::endl;
            fout << "M17->f41: " << f41 << std::endl;
            fout << "M17->f42: " << f42 << std::endl;
            fout << "M17->f43: " << f43 << std::endl;
            fout << "M17->f44: " << f44 << std::endl;
            fout << "M17->f45: " << f45 << std::endl;
            fout << "M17->f46: " << f46 << std::endl;
            fout << "M17->f47: " << f47 << std::endl;
            fout << "M17->f48: " << f48 << std::endl;
            fout << "M17->f49: " << f49 << std::endl;
            fout << "M17->f50: " << f50 << std::endl;
            fout << "M17->f51: " << f51 << std::endl;
            fout << "M17->f52: " << f52 << std::endl;
            fout << "M17->f53: " << f53 << std::endl;
            fout << "M17->f54: " << f54 << std::endl;
            fout << "M17->f55: " << f55 << std::endl;
            fout << "M17->f56: " << f56 << std::endl;
            fout << "M17->f57: " << f57 << std::endl;
            fout << "M17->f58: " << f58 << std::endl;
            fout << "M17->f59: " << f59 << std::endl;
            fout << "M17->f60: " << f60 << std::endl;
            fout << "M17->f61: " << f61 << std::endl;
            fout << "M17->f62: " << f62 << std::endl;
            fout << "M17->f63: " << f63 << std::endl;
            fout << "M17->f64: " << f64 << std::endl;
            if(f65 != nullptr)
                f65->print_message(fout);
        }
    
        ~M17(){
            if(f65 != nullptr)
                delete f65;
        }
    
        M17(){
           f65 = nullptr;
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
        alignas(8) int64_t f33;
        alignas(8) int64_t f34;
        alignas(8) int64_t f35;
        alignas(8) int64_t f36;
        alignas(8) int64_t f37;
        alignas(8) int64_t f38;
        alignas(8) int64_t f39;
        alignas(8) int64_t f40;
        alignas(8) int64_t f41;
        alignas(8) int64_t f42;
        alignas(8) int64_t f43;
        alignas(8) int64_t f44;
        alignas(8) int64_t f45;
        alignas(8) int64_t f46;
        alignas(8) int64_t f47;
        alignas(8) int64_t f48;
        alignas(8) int64_t f49;
        alignas(8) int64_t f50;
        alignas(8) int64_t f51;
        alignas(8) int64_t f52;
        alignas(8) int64_t f53;
        alignas(8) int64_t f54;
        alignas(8) int64_t f55;
        alignas(8) int64_t f56;
        alignas(8) int64_t f57;
        alignas(8) int64_t f58;
        alignas(8) int64_t f59;
        alignas(8) int64_t f60;
        alignas(8) int64_t f61;
        alignas(8) int64_t f62;
        alignas(8) int64_t f63;
        alignas(8) int64_t f64;
        alignas(8) M18* f65;
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

    inline void set_f33(int64_t val){
        f33 = val;
    }
    inline int64_t& get_f33(){
        return f33;
    }

    inline void set_f34(int64_t val){
        f34 = val;
    }
    inline int64_t& get_f34(){
        return f34;
    }

    inline void set_f35(int64_t val){
        f35 = val;
    }
    inline int64_t& get_f35(){
        return f35;
    }

    inline void set_f36(int64_t val){
        f36 = val;
    }
    inline int64_t& get_f36(){
        return f36;
    }

    inline void set_f37(int64_t val){
        f37 = val;
    }
    inline int64_t& get_f37(){
        return f37;
    }

    inline void set_f38(int64_t val){
        f38 = val;
    }
    inline int64_t& get_f38(){
        return f38;
    }

    inline void set_f39(int64_t val){
        f39 = val;
    }
    inline int64_t& get_f39(){
        return f39;
    }

    inline void set_f40(int64_t val){
        f40 = val;
    }
    inline int64_t& get_f40(){
        return f40;
    }

    inline void set_f41(int64_t val){
        f41 = val;
    }
    inline int64_t& get_f41(){
        return f41;
    }

    inline void set_f42(int64_t val){
        f42 = val;
    }
    inline int64_t& get_f42(){
        return f42;
    }

    inline void set_f43(int64_t val){
        f43 = val;
    }
    inline int64_t& get_f43(){
        return f43;
    }

    inline void set_f44(int64_t val){
        f44 = val;
    }
    inline int64_t& get_f44(){
        return f44;
    }

    inline void set_f45(int64_t val){
        f45 = val;
    }
    inline int64_t& get_f45(){
        return f45;
    }

    inline void set_f46(int64_t val){
        f46 = val;
    }
    inline int64_t& get_f46(){
        return f46;
    }

    inline void set_f47(int64_t val){
        f47 = val;
    }
    inline int64_t& get_f47(){
        return f47;
    }

    inline void set_f48(int64_t val){
        f48 = val;
    }
    inline int64_t& get_f48(){
        return f48;
    }

    inline void set_f49(int64_t val){
        f49 = val;
    }
    inline int64_t& get_f49(){
        return f49;
    }

    inline void set_f50(int64_t val){
        f50 = val;
    }
    inline int64_t& get_f50(){
        return f50;
    }

    inline void set_f51(int64_t val){
        f51 = val;
    }
    inline int64_t& get_f51(){
        return f51;
    }

    inline void set_f52(int64_t val){
        f52 = val;
    }
    inline int64_t& get_f52(){
        return f52;
    }

    inline void set_f53(int64_t val){
        f53 = val;
    }
    inline int64_t& get_f53(){
        return f53;
    }

    inline void set_f54(int64_t val){
        f54 = val;
    }
    inline int64_t& get_f54(){
        return f54;
    }

    inline void set_f55(int64_t val){
        f55 = val;
    }
    inline int64_t& get_f55(){
        return f55;
    }

    inline void set_f56(int64_t val){
        f56 = val;
    }
    inline int64_t& get_f56(){
        return f56;
    }

    inline void set_f57(int64_t val){
        f57 = val;
    }
    inline int64_t& get_f57(){
        return f57;
    }

    inline void set_f58(int64_t val){
        f58 = val;
    }
    inline int64_t& get_f58(){
        return f58;
    }

    inline void set_f59(int64_t val){
        f59 = val;
    }
    inline int64_t& get_f59(){
        return f59;
    }

    inline void set_f60(int64_t val){
        f60 = val;
    }
    inline int64_t& get_f60(){
        return f60;
    }

    inline void set_f61(int64_t val){
        f61 = val;
    }
    inline int64_t& get_f61(){
        return f61;
    }

    inline void set_f62(int64_t val){
        f62 = val;
    }
    inline int64_t& get_f62(){
        return f62;
    }

    inline void set_f63(int64_t val){
        f63 = val;
    }
    inline int64_t& get_f63(){
        return f63;
    }

    inline void set_f64(int64_t val){
        f64 = val;
    }
    inline int64_t& get_f64(){
        return f64;
    }

    inline M17* mutable_f65(){
        f65 = new M17();
        return f65;
    }
    inline M17*& get_f65(){
        return f65;
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
        fout << "M16->f33: " << f33 << std::endl;
        fout << "M16->f34: " << f34 << std::endl;
        fout << "M16->f35: " << f35 << std::endl;
        fout << "M16->f36: " << f36 << std::endl;
        fout << "M16->f37: " << f37 << std::endl;
        fout << "M16->f38: " << f38 << std::endl;
        fout << "M16->f39: " << f39 << std::endl;
        fout << "M16->f40: " << f40 << std::endl;
        fout << "M16->f41: " << f41 << std::endl;
        fout << "M16->f42: " << f42 << std::endl;
        fout << "M16->f43: " << f43 << std::endl;
        fout << "M16->f44: " << f44 << std::endl;
        fout << "M16->f45: " << f45 << std::endl;
        fout << "M16->f46: " << f46 << std::endl;
        fout << "M16->f47: " << f47 << std::endl;
        fout << "M16->f48: " << f48 << std::endl;
        fout << "M16->f49: " << f49 << std::endl;
        fout << "M16->f50: " << f50 << std::endl;
        fout << "M16->f51: " << f51 << std::endl;
        fout << "M16->f52: " << f52 << std::endl;
        fout << "M16->f53: " << f53 << std::endl;
        fout << "M16->f54: " << f54 << std::endl;
        fout << "M16->f55: " << f55 << std::endl;
        fout << "M16->f56: " << f56 << std::endl;
        fout << "M16->f57: " << f57 << std::endl;
        fout << "M16->f58: " << f58 << std::endl;
        fout << "M16->f59: " << f59 << std::endl;
        fout << "M16->f60: " << f60 << std::endl;
        fout << "M16->f61: " << f61 << std::endl;
        fout << "M16->f62: " << f62 << std::endl;
        fout << "M16->f63: " << f63 << std::endl;
        fout << "M16->f64: " << f64 << std::endl;
        if(f65 != nullptr)
            f65->print_message(fout);
    }

    ~M16(){
        if(f65 != nullptr)
            delete f65;
    }

    M16(){
       f65 = nullptr;
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
    alignas(8) int64_t f33;
    alignas(8) int64_t f34;
    alignas(8) int64_t f35;
    alignas(8) int64_t f36;
    alignas(8) int64_t f37;
    alignas(8) int64_t f38;
    alignas(8) int64_t f39;
    alignas(8) int64_t f40;
    alignas(8) int64_t f41;
    alignas(8) int64_t f42;
    alignas(8) int64_t f43;
    alignas(8) int64_t f44;
    alignas(8) int64_t f45;
    alignas(8) int64_t f46;
    alignas(8) int64_t f47;
    alignas(8) int64_t f48;
    alignas(8) int64_t f49;
    alignas(8) int64_t f50;
    alignas(8) int64_t f51;
    alignas(8) int64_t f52;
    alignas(8) int64_t f53;
    alignas(8) int64_t f54;
    alignas(8) int64_t f55;
    alignas(8) int64_t f56;
    alignas(8) int64_t f57;
    alignas(8) int64_t f58;
    alignas(8) int64_t f59;
    alignas(8) int64_t f60;
    alignas(8) int64_t f61;
    alignas(8) int64_t f62;
    alignas(8) int64_t f63;
    alignas(8) int64_t f64;
    alignas(8) M17* f65;
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


