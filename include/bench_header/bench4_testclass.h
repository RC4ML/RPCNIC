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
        enum E1 {
            E1_CONST_1 = 73,
            E1_CONST_2 = 9,
            E1_CONST_3 = 110,
            E1_CONST_4 = 51,
            E1_CONST_5 = 21,
        };
        
        class alignas(8) M3 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 67,
                E1_CONST_2 = 74,
                E1_CONST_3 = 78,
                E1_CONST_4 = 16,
                E1_CONST_5 = 26,
            };
            
            class alignas(8) M4 : public M_base
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
            
                inline void set_f5(string val){
                    f5 = val;
                }
                inline string& get_f5(){
                    return f5;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M4->f1: " << f1 << std::endl;
                    fout << "M4->f2: " << f2 << std::endl;
                    fout << "M4->f3: " << f3 << std::endl;
                    fout << "M4->f4: " << f4 << std::endl;
                    fout << "M4->f5: " << f5 << std::endl;
                }
            
                ~M4(){
                }
            
                M4(){
                }
            
            private:
                alignas(8) string f1;
                alignas(8) string f2;
                alignas(8) uint64_t f3;
                alignas(8) int64_t f4;
                alignas(8) string f5;
            };


            inline M4* mutable_f1(){
                f1 = new M4();
                return f1;
            }
            inline M4*& get_f1(){
                return f1;
            }
        
            inline void set_f2(int64_t val){
                f2 = val;
            }
            inline int64_t& get_f2(){
                return f2;
            }
        
            inline void set_f3(bool val){
                f3 = val;
            }
            inline bool& get_f3(){
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
        
            inline void set_f6(bool val){
                f6 = val;
            }
            inline bool& get_f6(){
                return f6;
            }
        
            inline void set_f7(bool val){
                f7 = val;
            }
            inline bool& get_f7(){
                return f7;
            }
        
            inline void set_f8(bool val){
                f8 = val;
            }
            inline bool& get_f8(){
                return f8;
            }
        
            inline void set_f9(bool val){
                f9 = val;
            }
            inline bool& get_f9(){
                return f9;
            }
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                fout << "M3->f2: " << f2 << std::endl;
                fout << "M3->f3: " << f3 << std::endl;
                fout << "M3->f4: " << f4 << std::endl;
                fout << "M3->f5: " << f5 << std::endl;
                fout << "M3->f6: " << f6 << std::endl;
                fout << "M3->f7: " << f7 << std::endl;
                fout << "M3->f8: " << f8 << std::endl;
                fout << "M3->f9: " << f9 << std::endl;
            }
        
            ~M3(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M3(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M4* f1;
            alignas(8) int64_t f2;
            alignas(8) bool f3;
            alignas(8) int32_t f4;
            alignas(8) E1 f5;
            alignas(8) bool f6;
            alignas(8) bool f7;
            alignas(8) bool f8;
            alignas(8) bool f9;
        };


        inline void set_f1(E1 val){
            f1 = val;
        }
        inline E1& get_f1(){
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
    
        inline M3* mutable_f7(){
            f7 = new M3();
            return f7;
        }
        inline M3*& get_f7(){
            return f7;
        }
    
        inline void set_f8(string val){
            f8 = val;
        }
        inline string& get_f8(){
            return f8;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M2->f1: " << f1 << std::endl;
            fout << "M2->f2: " << f2 << std::endl;
            fout << "M2->f3: " << f3 << std::endl;
            fout << "M2->f4: " << f4 << std::endl;
            fout << "M2->f5: " << f5 << std::endl;
            fout << "M2->f6: " << f6 << std::endl;
            if(f7 != nullptr)
                f7->print_message(fout);
            fout << "M2->f8: " << f8 << std::endl;
        }
    
        ~M2(){
            if(f7 != nullptr)
                delete f7;
        }
    
        M2(){
           f7 = nullptr;
        }
    
    private:
        alignas(8) E1 f1;
        alignas(8) int32_t f2;
        alignas(8) int32_t f3;
        alignas(8) double f4;
        alignas(8) string f5;
        alignas(8) int64_t f6;
        alignas(8) M3* f7;
        alignas(8) string f8;
    };


    class alignas(8) M5 : public M_base
    {
    public:
        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
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
        alignas(8) string f1;
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

    inline M2* mutable_f5(){
        f5 = new M2();
        return f5;
    }
    inline M2*& get_f5(){
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

    inline void set_f8(string val){
        f8 = val;
    }
    inline string& get_f8(){
        return f8;
    }

    inline void set_f9(int32_t val){
        f9 = val;
    }
    inline int32_t& get_f9(){
        return f9;
    }

    inline M5* mutable_f10(){
        f10 = new M5();
        return f10;
    }
    inline M5*& get_f10(){
        return f10;
    }

    inline void set_f11(string val){
        f11 = val;
    }
    inline string& get_f11(){
        return f11;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M1->f1: " << f1 << std::endl;
        fout << "M1->f2: " << f2 << std::endl;
        fout << "M1->f3: " << f3 << std::endl;
        fout << "M1->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        fout << "M1->f6: " << f6 << std::endl;
        fout << "M1->f7: " << f7 << std::endl;
        fout << "M1->f8: " << f8 << std::endl;
        fout << "M1->f9: " << f9 << std::endl;
        if(f10 != nullptr)
            f10->print_message(fout);
        fout << "M1->f11: " << f11 << std::endl;
    }

    ~M1(){
        if(f5 != nullptr)
            delete f5;
        if(f10 != nullptr)
            delete f10;
    }

    M1(){
       f5 = nullptr;
       f10 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) string f2;
    alignas(8) int32_t f3;
    alignas(8) int32_t f4;
    alignas(8) M2* f5;
    alignas(8) int32_t f6;
    alignas(8) int32_t f7;
    alignas(8) string f8;
    alignas(8) int32_t f9;
    alignas(8) M5* f10;
    alignas(8) string f11;
};


class alignas(8) M6 : public M_base
{
public:
    class alignas(8) M7 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 33,
            E1_CONST_2 = 67,
            E1_CONST_3 = 39,
            E1_CONST_4 = 115,
            E1_CONST_5 = 60,
        };
        
        class alignas(8) M8 : public M_base
        {
        public:
            class alignas(8) M9 : public M_base
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
            
                inline void print_message(std::ofstream &fout){
                    fout << "M9->f1: " << f1 << std::endl;
                    fout << "M9->f2: " << f2 << std::endl;
                }
            
                ~M9(){
                }
            
                M9(){
                }
            
            private:
                alignas(8) string f1;
                alignas(8) string f2;
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M8->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
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
        };


        class alignas(8) M10 : public M_base
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
            alignas(8) int64_t f1;
            alignas(8) string f2;
            alignas(8) int64_t f3;
        };


        inline M8* mutable_f1(){
            f1 = new M8();
            return f1;
        }
        inline M8*& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(double val){
            f3 = val;
        }
        inline double& get_f3(){
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
    
        inline void set_f6(E1 val){
            f6 = val;
        }
        inline E1& get_f6(){
            return f6;
        }
    
        inline void set_f7(bool val){
            f7 = val;
        }
        inline bool& get_f7(){
            return f7;
        }
    
        inline M10* mutable_f8(){
            f8 = new M10();
            return f8;
        }
        inline M10*& get_f8(){
            return f8;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M7->f2: " << f2 << std::endl;
            fout << "M7->f3: " << f3 << std::endl;
            fout << "M7->f4: " << f4 << std::endl;
            fout << "M7->f5: " << f5 << std::endl;
            fout << "M7->f6: " << f6 << std::endl;
            fout << "M7->f7: " << f7 << std::endl;
            if(f8 != nullptr)
                f8->print_message(fout);
        }
    
        ~M7(){
            if(f1 != nullptr)
                delete f1;
            if(f8 != nullptr)
                delete f8;
        }
    
        M7(){
           f1 = nullptr;
           f8 = nullptr;
        }
    
    private:
        alignas(8) M8* f1;
        alignas(8) int32_t f2;
        alignas(8) double f3;
        alignas(8) int64_t f4;
        alignas(8) uint64_t f5;
        alignas(8) E1 f6;
        alignas(8) bool f7;
        alignas(8) M10* f8;
    };


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

    inline void set_f7(uint64_t val){
        f7 = val;
    }
    inline uint64_t& get_f7(){
        return f7;
    }

    inline void set_f8(string val){
        f8 = val;
    }
    inline string& get_f8(){
        return f8;
    }

    inline M7* mutable_f9(){
        f9 = new M7();
        return f9;
    }
    inline M7*& get_f9(){
        return f9;
    }

    inline void set_f10(int64_t val){
        f10 = val;
    }
    inline int64_t& get_f10(){
        return f10;
    }

    inline void set_f11(int32_t val){
        f11 = val;
    }
    inline int32_t& get_f11(){
        return f11;
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
        if(f9 != nullptr)
            f9->print_message(fout);
        fout << "M6->f10: " << f10 << std::endl;
        fout << "M6->f11: " << f11 << std::endl;
    }

    ~M6(){
        if(f9 != nullptr)
            delete f9;
    }

    M6(){
       f9 = nullptr;
    }

private:
    alignas(8) bool f1;
    alignas(8) int32_t f2;
    alignas(8) bool f3;
    alignas(8) int64_t f4;
    alignas(8) string f5;
    alignas(8) uint64_t f6;
    alignas(8) uint64_t f7;
    alignas(8) string f8;
    alignas(8) M7* f9;
    alignas(8) int64_t f10;
    alignas(8) int32_t f11;
};


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
                enum E1 {
                    E1_CONST_1 = 5,
                    E1_CONST_2 = 75,
                    E1_CONST_3 = 110,
                    E1_CONST_4 = 88,
                    E1_CONST_5 = 60,
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
            
                inline void set_f5(E1 val){
                    f5 = val;
                }
                inline E1& get_f5(){
                    return f5;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M14->f1: " << f1 << std::endl;
                    fout << "M14->f2: " << f2 << std::endl;
                    fout << "M14->f3: " << f3 << std::endl;
                    fout << "M14->f4: " << f4 << std::endl;
                    fout << "M14->f5: " << f5 << std::endl;
                }
            
                ~M14(){
                }
            
                M14(){
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) bool f2;
                alignas(8) int64_t f3;
                alignas(8) int32_t f4;
                alignas(8) E1 f5;
            };


            inline void set_f1(bool val){
                f1 = val;
            }
            inline bool& get_f1(){
                return f1;
            }
        
            inline M14* mutable_f2(){
                f2 = new M14();
                return f2;
            }
            inline M14*& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M13->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
            }
        
            ~M13(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M13(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) bool f1;
            alignas(8) M14* f2;
        };


        class alignas(8) M15 : public M_base
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M15->f1: " << f1 << std::endl;
                fout << "M15->f2: " << f2 << std::endl;
                fout << "M15->f3: " << f3 << std::endl;
            }
        
            ~M15(){
            }
        
            M15(){
            }
        
        private:
            alignas(8) string f1;
            alignas(8) string f2;
            alignas(8) int64_t f3;
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
    
        inline void set_f3(int32_t val){
            f3 = val;
        }
        inline int32_t& get_f3(){
            return f3;
        }
    
        inline M13* mutable_f4(){
            f4 = new M13();
            return f4;
        }
        inline M13*& get_f4(){
            return f4;
        }
    
        inline M15* mutable_f5(){
            f5 = new M15();
            return f5;
        }
        inline M15*& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M12->f1: " << f1 << std::endl;
            fout << "M12->f2: " << f2 << std::endl;
            fout << "M12->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
            if(f5 != nullptr)
                f5->print_message(fout);
        }
    
        ~M12(){
            if(f4 != nullptr)
                delete f4;
            if(f5 != nullptr)
                delete f5;
        }
    
        M12(){
           f4 = nullptr;
           f5 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) string f2;
        alignas(8) int32_t f3;
        alignas(8) M13* f4;
        alignas(8) M15* f5;
    };


    class alignas(8) M16 : public M_base
    {
    public:
        inline void set_f1(bool val){
            f1 = val;
        }
        inline bool& get_f1(){
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
        alignas(8) bool f1;
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

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
        return f3;
    }

    inline M16* mutable_f4(){
        f4 = new M16();
        return f4;
    }
    inline M16*& get_f4(){
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

    inline void set_f8(int64_t val){
        f8 = val;
    }
    inline int64_t& get_f8(){
        return f8;
    }

    inline void set_f9(bool val){
        f9 = val;
    }
    inline bool& get_f9(){
        return f9;
    }

    inline void set_f10(bool val){
        f10 = val;
    }
    inline bool& get_f10(){
        return f10;
    }

    inline void set_f11(int32_t val){
        f11 = val;
    }
    inline int32_t& get_f11(){
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

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        fout << "M11->f2: " << f2 << std::endl;
        fout << "M11->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M11->f5: " << f5 << std::endl;
        fout << "M11->f6: " << f6 << std::endl;
        fout << "M11->f7: " << f7 << std::endl;
        fout << "M11->f8: " << f8 << std::endl;
        fout << "M11->f9: " << f9 << std::endl;
        fout << "M11->f10: " << f10 << std::endl;
        fout << "M11->f11: " << f11 << std::endl;
        fout << "M11->f12: " << f12 << std::endl;
        fout << "M11->f13: " << f13 << std::endl;
    }

    ~M11(){
        if(f1 != nullptr)
            delete f1;
        if(f4 != nullptr)
            delete f4;
    }

    M11(){
       f1 = nullptr;
       f4 = nullptr;
    }

private:
    alignas(8) M12* f1;
    alignas(8) string f2;
    alignas(8) string f3;
    alignas(8) M16* f4;
    alignas(8) int32_t f5;
    alignas(8) int32_t f6;
    alignas(8) string f7;
    alignas(8) int64_t f8;
    alignas(8) bool f9;
    alignas(8) bool f10;
    alignas(8) int32_t f11;
    alignas(8) int64_t f12;
    alignas(8) int64_t f13;
};


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
                inline void set_f1(uint64_t val){
                    f1 = val;
                }
                inline uint64_t& get_f1(){
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
                alignas(8) uint64_t f1;
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M19->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M19->f3: " << f3 << std::endl;
                fout << "M19->f4: " << f4 << std::endl;
            }
        
            ~M19(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M19(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) M20* f2;
            alignas(8) string f3;
            alignas(8) int32_t f4;
        };


        inline void set_f1(double val){
            f1 = val;
        }
        inline double& get_f1(){
            return f1;
        }
    
        inline M19* mutable_f2(){
            f2 = new M19();
            return f2;
        }
        inline M19*& get_f2(){
            return f2;
        }
    
        inline void set_f3(string val){
            f3 = val;
        }
        inline string& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M18->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M18->f3: " << f3 << std::endl;
        }
    
        ~M18(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M18(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) double f1;
        alignas(8) M19* f2;
        alignas(8) string f3;
    };


    inline M18* mutable_f1(){
        f1 = new M18();
        return f1;
    }
    inline M18*& get_f1(){
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

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        fout << "M17->f2: " << f2 << std::endl;
        fout << "M17->f3: " << f3 << std::endl;
        fout << "M17->f4: " << f4 << std::endl;
        fout << "M17->f5: " << f5 << std::endl;
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
    alignas(8) string f2;
    alignas(8) int64_t f3;
    alignas(8) string f4;
    alignas(8) int64_t f5;
};


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
            
                inline void print_message(std::ofstream &fout){
                    fout << "M24->f1: " << f1 << std::endl;
                    fout << "M24->f2: " << f2 << std::endl;
                    fout << "M24->f3: " << f3 << std::endl;
                    fout << "M24->f4: " << f4 << std::endl;
                }
            
                ~M24(){
                }
            
                M24(){
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) int32_t f2;
                alignas(8) int64_t f3;
                alignas(8) int32_t f4;
            };


            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline M24* mutable_f2(){
                f2 = new M24();
                return f2;
            }
            inline M24*& get_f2(){
                return f2;
            }
        
            inline void set_f3(int32_t val){
                f3 = val;
            }
            inline int32_t& get_f3(){
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M23->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M23->f3: " << f3 << std::endl;
                fout << "M23->f4: " << f4 << std::endl;
                fout << "M23->f5: " << f5 << std::endl;
                fout << "M23->f6: " << f6 << std::endl;
            }
        
            ~M23(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M23(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) M24* f2;
            alignas(8) int32_t f3;
            alignas(8) bool f4;
            alignas(8) string f5;
            alignas(8) int32_t f6;
        };


        inline void set_f1(bool val){
            f1 = val;
        }
        inline bool& get_f1(){
            return f1;
        }
    
        inline M23* mutable_f2(){
            f2 = new M23();
            return f2;
        }
        inline M23*& get_f2(){
            return f2;
        }
    
        inline void set_f3(uint64_t val){
            f3 = val;
        }
        inline uint64_t& get_f3(){
            return f3;
        }
    
        inline void set_f4(double val){
            f4 = val;
        }
        inline double& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M22->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M22->f3: " << f3 << std::endl;
            fout << "M22->f4: " << f4 << std::endl;
        }
    
        ~M22(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M22(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) bool f1;
        alignas(8) M23* f2;
        alignas(8) uint64_t f3;
        alignas(8) double f4;
    };


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

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
        return f3;
    }

    inline M22* mutable_f4(){
        f4 = new M22();
        return f4;
    }
    inline M22*& get_f4(){
        return f4;
    }

    inline void set_f5(bool val){
        f5 = val;
    }
    inline bool& get_f5(){
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

    inline void print_message(std::ofstream &fout){
        fout << "M21->f1: " << f1 << std::endl;
        fout << "M21->f2: " << f2 << std::endl;
        fout << "M21->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M21->f5: " << f5 << std::endl;
        fout << "M21->f6: " << f6 << std::endl;
        fout << "M21->f7: " << f7 << std::endl;
    }

    ~M21(){
        if(f4 != nullptr)
            delete f4;
    }

    M21(){
       f4 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) uint64_t f2;
    alignas(8) string f3;
    alignas(8) M22* f4;
    alignas(8) bool f5;
    alignas(8) string f6;
    alignas(8) uint64_t f7;
};


class alignas(8) M25 : public M_base
{
public:
    class alignas(8) M26 : public M_base
    {
    public:
        class alignas(8) M27 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 100,
                E1_CONST_2 = 4,
                E1_CONST_3 = 36,
                E1_CONST_4 = 79,
                E1_CONST_5 = 83,
            };
            
            class alignas(8) M28 : public M_base
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
            
                inline void print_message(std::ofstream &fout){
                    fout << "M28->f1: " << f1 << std::endl;
                    fout << "M28->f2: " << f2 << std::endl;
                    fout << "M28->f3: " << f3 << std::endl;
                }
            
                ~M28(){
                }
            
                M28(){
                }
            
            private:
                alignas(8) string f1;
                alignas(8) string f2;
                alignas(8) bool f3;
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
        
            inline void set_f3(int32_t val){
                f3 = val;
            }
            inline int32_t& get_f3(){
                return f3;
            }
        
            inline void set_f4(E1 val){
                f4 = val;
            }
            inline E1& get_f4(){
                return f4;
            }
        
            inline M28* mutable_f5(){
                f5 = new M28();
                return f5;
            }
            inline M28*& get_f5(){
                return f5;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M27->f1: " << f1 << std::endl;
                fout << "M27->f2: " << f2 << std::endl;
                fout << "M27->f3: " << f3 << std::endl;
                fout << "M27->f4: " << f4 << std::endl;
                if(f5 != nullptr)
                    f5->print_message(fout);
            }
        
            ~M27(){
                if(f5 != nullptr)
                    delete f5;
            }
        
            M27(){
               f5 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) string f2;
            alignas(8) int32_t f3;
            alignas(8) E1 f4;
            alignas(8) M28* f5;
        };


        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline M27* mutable_f2(){
            f2 = new M27();
            return f2;
        }
        inline M27*& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M26->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
        }
    
        ~M26(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M26(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) M27* f2;
    };


    class alignas(8) M29 : public M_base
    {
    public:
        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M29->f1: " << f1 << std::endl;
        }
    
        ~M29(){
        }
    
        M29(){
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

    inline M26* mutable_f2(){
        f2 = new M26();
        return f2;
    }
    inline M26*& get_f2(){
        return f2;
    }

    inline void set_f3(int64_t val){
        f3 = val;
    }
    inline int64_t& get_f3(){
        return f3;
    }

    inline void set_f4(uint64_t val){
        f4 = val;
    }
    inline uint64_t& get_f4(){
        return f4;
    }

    inline M29* mutable_f5(){
        f5 = new M29();
        return f5;
    }
    inline M29*& get_f5(){
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

    inline void set_f8(uint64_t val){
        f8 = val;
    }
    inline uint64_t& get_f8(){
        return f8;
    }

    inline void set_f9(double val){
        f9 = val;
    }
    inline double& get_f9(){
        return f9;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M25->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M25->f3: " << f3 << std::endl;
        fout << "M25->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        fout << "M25->f6: " << f6 << std::endl;
        fout << "M25->f7: " << f7 << std::endl;
        fout << "M25->f8: " << f8 << std::endl;
        fout << "M25->f9: " << f9 << std::endl;
    }

    ~M25(){
        if(f2 != nullptr)
            delete f2;
        if(f5 != nullptr)
            delete f5;
    }

    M25(){
       f2 = nullptr;
       f5 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) M26* f2;
    alignas(8) int64_t f3;
    alignas(8) uint64_t f4;
    alignas(8) M29* f5;
    alignas(8) int32_t f6;
    alignas(8) int32_t f7;
    alignas(8) uint64_t f8;
    alignas(8) double f9;
};


class alignas(8) M30 : public M_base
{
public:
    class alignas(8) M31 : public M_base
    {
    public:
        class alignas(8) M32 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 74,
                E1_CONST_2 = 50,
                E1_CONST_3 = 21,
                E1_CONST_4 = 55,
                E1_CONST_5 = 56,
            };
            
            class alignas(8) M33 : public M_base
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
            
                inline void print_message(std::ofstream &fout){
                    fout << "M33->f1: " << f1 << std::endl;
                    fout << "M33->f2: " << f2 << std::endl;
                    fout << "M33->f3: " << f3 << std::endl;
                    fout << "M33->f4: " << f4 << std::endl;
                }
            
                ~M33(){
                }
            
                M33(){
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) string f2;
                alignas(8) string f3;
                alignas(8) string f4;
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


            inline void set_f1(uint64_t val){
                f1 = val;
            }
            inline uint64_t& get_f1(){
                return f1;
            }
        
            inline M33* mutable_f2(){
                f2 = new M33();
                return f2;
            }
            inline M33*& get_f2(){
                return f2;
            }
        
            inline void set_f3(E1 val){
                f3 = val;
            }
            inline E1& get_f3(){
                return f3;
            }
        
            inline void set_f4(int64_t val){
                f4 = val;
            }
            inline int64_t& get_f4(){
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
        
            inline M34* mutable_f7(){
                f7 = new M34();
                return f7;
            }
            inline M34*& get_f7(){
                return f7;
            }
        
            inline void set_f8(int32_t val){
                f8 = val;
            }
            inline int32_t& get_f8(){
                return f8;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M32->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M32->f3: " << f3 << std::endl;
                fout << "M32->f4: " << f4 << std::endl;
                fout << "M32->f5: " << f5 << std::endl;
                fout << "M32->f6: " << f6 << std::endl;
                if(f7 != nullptr)
                    f7->print_message(fout);
                fout << "M32->f8: " << f8 << std::endl;
            }
        
            ~M32(){
                if(f2 != nullptr)
                    delete f2;
                if(f7 != nullptr)
                    delete f7;
            }
        
            M32(){
               f2 = nullptr;
               f7 = nullptr;
            }
        
        private:
            alignas(8) uint64_t f1;
            alignas(8) M33* f2;
            alignas(8) E1 f3;
            alignas(8) int64_t f4;
            alignas(8) bool f5;
            alignas(8) int64_t f6;
            alignas(8) M34* f7;
            alignas(8) int32_t f8;
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
    
        inline void set_f3(double val){
            f3 = val;
        }
        inline double& get_f3(){
            return f3;
        }
    
        inline void set_f4(string val){
            f4 = val;
        }
        inline string& get_f4(){
            return f4;
        }
    
        inline M32* mutable_f5(){
            f5 = new M32();
            return f5;
        }
        inline M32*& get_f5(){
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
    
        inline void print_message(std::ofstream &fout){
            fout << "M31->f1: " << f1 << std::endl;
            fout << "M31->f2: " << f2 << std::endl;
            fout << "M31->f3: " << f3 << std::endl;
            fout << "M31->f4: " << f4 << std::endl;
            if(f5 != nullptr)
                f5->print_message(fout);
            fout << "M31->f6: " << f6 << std::endl;
            fout << "M31->f7: " << f7 << std::endl;
            fout << "M31->f8: " << f8 << std::endl;
            fout << "M31->f9: " << f9 << std::endl;
        }
    
        ~M31(){
            if(f5 != nullptr)
                delete f5;
        }
    
        M31(){
           f5 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) int32_t f2;
        alignas(8) double f3;
        alignas(8) string f4;
        alignas(8) M32* f5;
        alignas(8) bool f6;
        alignas(8) int64_t f7;
        alignas(8) int32_t f8;
        alignas(8) int32_t f9;
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

    inline M31* mutable_f11(){
        f11 = new M31();
        return f11;
    }
    inline M31*& get_f11(){
        return f11;
    }

    inline void set_f12(int64_t val){
        f12 = val;
    }
    inline int64_t& get_f12(){
        return f12;
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
        if(f11 != nullptr)
            f11->print_message(fout);
        fout << "M30->f12: " << f12 << std::endl;
    }

    ~M30(){
        if(f11 != nullptr)
            delete f11;
    }

    M30(){
       f11 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) string f2;
    alignas(8) bool f3;
    alignas(8) string f4;
    alignas(8) int64_t f5;
    alignas(8) string f6;
    alignas(8) string f7;
    alignas(8) int32_t f8;
    alignas(8) string f9;
    alignas(8) string f10;
    alignas(8) M31* f11;
    alignas(8) int64_t f12;
};


class alignas(8) M35 : public M_base
{
public:
    class alignas(8) M36 : public M_base
    {
    public:
        class alignas(8) M37 : public M_base
        {
        public:
            class alignas(8) M38 : public M_base
            {
            public:
                inline void set_f1(string val){
                    f1 = val;
                }
                inline string& get_f1(){
                    return f1;
                }
            
                inline void set_f2(uint64_t val){
                    f2 = val;
                }
                inline uint64_t& get_f2(){
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
                alignas(8) string f1;
                alignas(8) uint64_t f2;
            };


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
        
            inline M38* mutable_f3(){
                f3 = new M38();
                return f3;
            }
            inline M38*& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M37->f1: " << f1 << std::endl;
                fout << "M37->f2: " << f2 << std::endl;
                if(f3 != nullptr)
                    f3->print_message(fout);
            }
        
            ~M37(){
                if(f3 != nullptr)
                    delete f3;
            }
        
            M37(){
               f3 = nullptr;
            }
        
        private:
            alignas(8) bool f1;
            alignas(8) int32_t f2;
            alignas(8) M38* f3;
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
    
        inline M37* mutable_f3(){
            f3 = new M37();
            return f3;
        }
        inline M37*& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M36->f1: " << f1 << std::endl;
            fout << "M36->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M36(){
            if(f3 != nullptr)
                delete f3;
        }
    
        M36(){
           f3 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) int32_t f2;
        alignas(8) M37* f3;
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

    inline void set_f3(int32_t val){
        f3 = val;
    }
    inline int32_t& get_f3(){
        return f3;
    }

    inline M36* mutable_f4(){
        f4 = new M36();
        return f4;
    }
    inline M36*& get_f4(){
        return f4;
    }

    inline void set_f5(double val){
        f5 = val;
    }
    inline double& get_f5(){
        return f5;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M35->f1: " << f1 << std::endl;
        fout << "M35->f2: " << f2 << std::endl;
        fout << "M35->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M35->f5: " << f5 << std::endl;
    }

    ~M35(){
        if(f4 != nullptr)
            delete f4;
    }

    M35(){
       f4 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) int32_t f2;
    alignas(8) int32_t f3;
    alignas(8) M36* f4;
    alignas(8) double f5;
};


class alignas(8) M39 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 65,
        E1_CONST_2 = 21,
        E1_CONST_3 = 24,
        E1_CONST_4 = 122,
        E1_CONST_5 = 63,
    };
    
    class alignas(8) M40 : public M_base
    {
    public:
        class alignas(8) M41 : public M_base
        {
        public:
            class alignas(8) M42 : public M_base
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
            
                inline void set_f3(int32_t val){
                    f3 = val;
                }
                inline int32_t& get_f3(){
                    return f3;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M42->f1: " << f1 << std::endl;
                    fout << "M42->f2: " << f2 << std::endl;
                    fout << "M42->f3: " << f3 << std::endl;
                }
            
                ~M42(){
                }
            
                M42(){
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) bool f2;
                alignas(8) int32_t f3;
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
        
            inline void set_f3(int32_t val){
                f3 = val;
            }
            inline int32_t& get_f3(){
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
        
            inline void set_f6(string val){
                f6 = val;
            }
            inline string& get_f6(){
                return f6;
            }
        
            inline M42* mutable_f7(){
                f7 = new M42();
                return f7;
            }
            inline M42*& get_f7(){
                return f7;
            }
        
            inline void set_f8(bool val){
                f8 = val;
            }
            inline bool& get_f8(){
                return f8;
            }
        
            inline void set_f9(int32_t val){
                f9 = val;
            }
            inline int32_t& get_f9(){
                return f9;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M41->f1: " << f1 << std::endl;
                fout << "M41->f2: " << f2 << std::endl;
                fout << "M41->f3: " << f3 << std::endl;
                fout << "M41->f4: " << f4 << std::endl;
                fout << "M41->f5: " << f5 << std::endl;
                fout << "M41->f6: " << f6 << std::endl;
                if(f7 != nullptr)
                    f7->print_message(fout);
                fout << "M41->f8: " << f8 << std::endl;
                fout << "M41->f9: " << f9 << std::endl;
            }
        
            ~M41(){
                if(f7 != nullptr)
                    delete f7;
            }
        
            M41(){
               f7 = nullptr;
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) int64_t f2;
            alignas(8) int32_t f3;
            alignas(8) bool f4;
            alignas(8) string f5;
            alignas(8) string f6;
            alignas(8) M42* f7;
            alignas(8) bool f8;
            alignas(8) int32_t f9;
        };


        inline M41* mutable_f1(){
            f1 = new M41();
            return f1;
        }
        inline M41*& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(bool val){
            f3 = val;
        }
        inline bool& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M40->f2: " << f2 << std::endl;
            fout << "M40->f3: " << f3 << std::endl;
        }
    
        ~M40(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M40(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M41* f1;
        alignas(8) int32_t f2;
        alignas(8) bool f3;
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

    inline void set_f3(bool val){
        f3 = val;
    }
    inline bool& get_f3(){
        return f3;
    }

    inline void set_f4(E1 val){
        f4 = val;
    }
    inline E1& get_f4(){
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

    inline M40* mutable_f9(){
        f9 = new M40();
        return f9;
    }
    inline M40*& get_f9(){
        return f9;
    }

    inline void set_f10(double val){
        f10 = val;
    }
    inline double& get_f10(){
        return f10;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M39->f1: " << f1 << std::endl;
        fout << "M39->f2: " << f2 << std::endl;
        fout << "M39->f3: " << f3 << std::endl;
        fout << "M39->f4: " << f4 << std::endl;
        fout << "M39->f5: " << f5 << std::endl;
        fout << "M39->f6: " << f6 << std::endl;
        fout << "M39->f7: " << f7 << std::endl;
        fout << "M39->f8: " << f8 << std::endl;
        if(f9 != nullptr)
            f9->print_message(fout);
        fout << "M39->f10: " << f10 << std::endl;
    }

    ~M39(){
        if(f9 != nullptr)
            delete f9;
    }

    M39(){
       f9 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) string f2;
    alignas(8) bool f3;
    alignas(8) E1 f4;
    alignas(8) int64_t f5;
    alignas(8) string f6;
    alignas(8) string f7;
    alignas(8) string f8;
    alignas(8) M40* f9;
    alignas(8) double f10;
};


class alignas(8) M43 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 103,
        E1_CONST_2 = 14,
        E1_CONST_3 = 113,
        E1_CONST_4 = 116,
        E1_CONST_5 = 26,
    };
    
    class alignas(8) M44 : public M_base
    {
    public:
        class alignas(8) M45 : public M_base
        {
        public:
            class alignas(8) M46 : public M_base
            {
            public:
                inline void set_f1(bool val){
                    f1 = val;
                }
                inline bool& get_f1(){
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
                alignas(8) bool f1;
                alignas(8) string f2;
                alignas(8) int32_t f3;
            };


            inline void set_f1(bool val){
                f1 = val;
            }
            inline bool& get_f1(){
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
            alignas(8) bool f1;
            alignas(8) M46* f2;
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
    
        inline M45* mutable_f4(){
            f4 = new M45();
            return f4;
        }
        inline M45*& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M44->f1: " << f1 << std::endl;
            fout << "M44->f2: " << f2 << std::endl;
            fout << "M44->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
        }
    
        ~M44(){
            if(f4 != nullptr)
                delete f4;
        }
    
        M44(){
           f4 = nullptr;
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) int32_t f2;
        alignas(8) string f3;
        alignas(8) M45* f4;
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

    inline void set_f3(E1 val){
        f3 = val;
    }
    inline E1& get_f3(){
        return f3;
    }

    inline M44* mutable_f4(){
        f4 = new M44();
        return f4;
    }
    inline M44*& get_f4(){
        return f4;
    }

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M43->f1: " << f1 << std::endl;
        fout << "M43->f2: " << f2 << std::endl;
        fout << "M43->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M43->f5: " << f5 << std::endl;
    }

    ~M43(){
        if(f4 != nullptr)
            delete f4;
    }

    M43(){
       f4 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) double f2;
    alignas(8) E1 f3;
    alignas(8) M44* f4;
    alignas(8) int64_t f5;
};

M_base* createMessage(int temp_class_id) {
    switch (temp_class_id) {
        case 11:
            return new M11();
        case 16:
            return new M11::M16();
        case 12:
            return new M11::M12();
        case 15:
            return new M11::M12::M15();
        case 13:
            return new M11::M12::M13();
        case 14:
            return new M11::M12::M13::M14();
        case 17:
            return new M17();
        case 18:
            return new M17::M18();
        case 19:
            return new M17::M18::M19();
        case 20:
            return new M17::M18::M19::M20();
        case 1:
            return new M1();
        case 5:
            return new M1::M5();
        case 2:
            return new M1::M2();
        case 3:
            return new M1::M2::M3();
        case 4:
            return new M1::M2::M3::M4();
        case 21:
            return new M21();
        case 22:
            return new M21::M22();
        case 23:
            return new M21::M22::M23();
        case 24:
            return new M21::M22::M23::M24();
        case 25:
            return new M25();
        case 26:
            return new M25::M26();
        case 27:
            return new M25::M26::M27();
        case 28:
            return new M25::M26::M27::M28();
        case 29:
            return new M25::M29();
        case 30:
            return new M30();
        case 31:
            return new M30::M31();
        case 32:
            return new M30::M31::M32();
        case 33:
            return new M30::M31::M32::M33();
        case 34:
            return new M30::M31::M32::M34();
        case 35:
            return new M35();
        case 36:
            return new M35::M36();
        case 37:
            return new M35::M36::M37();
        case 38:
            return new M35::M36::M37::M38();
        case 39:
            return new M39();
        case 40:
            return new M39::M40();
        case 41:
            return new M39::M40::M41();
        case 42:
            return new M39::M40::M41::M42();
        case 43:
            return new M43();
        case 44:
            return new M43::M44();
        case 45:
            return new M43::M44::M45();
        case 46:
            return new M43::M44::M45::M46();
        case 6:
            return new M6();
        case 7:
            return new M6::M7();
        case 8:
            return new M6::M7::M8();
        case 9:
            return new M6::M7::M8::M9();
        case 10:
            return new M6::M7::M10();
        default:
            throw std::invalid_argument("Invalid class id");
    }
}

size_t getMessageSize(int temp_class_id) {
    switch (temp_class_id) {
        case 11:
            return sizeof(M11);
        case 16:
            return sizeof(M11::M16);
        case 12:
            return sizeof(M11::M12);
        case 15:
            return sizeof(M11::M12::M15);
        case 13:
            return sizeof(M11::M12::M13);
        case 14:
            return sizeof(M11::M12::M13::M14);
        case 17:
            return sizeof(M17);
        case 18:
            return sizeof(M17::M18);
        case 19:
            return sizeof(M17::M18::M19);
        case 20:
            return sizeof(M17::M18::M19::M20);
        case 1:
            return sizeof(M1);
        case 5:
            return sizeof(M1::M5);
        case 2:
            return sizeof(M1::M2);
        case 3:
            return sizeof(M1::M2::M3);
        case 4:
            return sizeof(M1::M2::M3::M4);
        case 21:
            return sizeof(M21);
        case 22:
            return sizeof(M21::M22);
        case 23:
            return sizeof(M21::M22::M23);
        case 24:
            return sizeof(M21::M22::M23::M24);
        case 25:
            return sizeof(M25);
        case 26:
            return sizeof(M25::M26);
        case 27:
            return sizeof(M25::M26::M27);
        case 28:
            return sizeof(M25::M26::M27::M28);
        case 29:
            return sizeof(M25::M29);
        case 30:
            return sizeof(M30);
        case 31:
            return sizeof(M30::M31);
        case 32:
            return sizeof(M30::M31::M32);
        case 33:
            return sizeof(M30::M31::M32::M33);
        case 34:
            return sizeof(M30::M31::M32::M34);
        case 35:
            return sizeof(M35);
        case 36:
            return sizeof(M35::M36);
        case 37:
            return sizeof(M35::M36::M37);
        case 38:
            return sizeof(M35::M36::M37::M38);
        case 39:
            return sizeof(M39);
        case 40:
            return sizeof(M39::M40);
        case 41:
            return sizeof(M39::M40::M41);
        case 42:
            return sizeof(M39::M40::M41::M42);
        case 43:
            return sizeof(M43);
        case 44:
            return sizeof(M43::M44);
        case 45:
            return sizeof(M43::M44::M45);
        case 46:
            return sizeof(M43::M44::M45::M46);
        case 6:
            return sizeof(M6);
        case 7:
            return sizeof(M6::M7);
        case 8:
            return sizeof(M6::M7::M8);
        case 9:
            return sizeof(M6::M7::M8::M9);
        case 10:
            return sizeof(M6::M7::M10);
        default:
            return 0;
    }
}
