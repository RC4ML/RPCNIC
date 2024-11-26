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
        E1_CONST_1 = 0,
        E1_CONST_2 = 65,
        E1_CONST_3 = 67,
        E1_CONST_4 = 16,
        E1_CONST_5 = 114,
    };
    
    class alignas(8) M2 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 35,
            E1_CONST_2 = 110,
            E1_CONST_3 = 80,
            E1_CONST_4 = 23,
            E1_CONST_5 = 123,
        };
        
        class alignas(8) M3 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
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
            alignas(8) int32_t f1;
        };


        class alignas(8) M4 : public M_base
        {
        public:
            class alignas(8) M5 : public M_base
            {
            public:
                inline void set_f1(int32_t val){
                    f1 = val;
                }
                inline int32_t& get_f1(){
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
                alignas(8) int32_t f1;
            };


            inline M5* mutable_f1(){
                f1 = new M5();
                return f1;
            }
            inline M5*& get_f1(){
                return f1;
            }
        
            inline void set_f2(int64_t val){
                f2 = val;
            }
            inline int64_t& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                fout << "M4->f2: " << f2 << std::endl;
            }
        
            ~M4(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M4(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M5* f1;
            alignas(8) int64_t f2;
        };


        inline M3* mutable_f1(){
            f1 = new M3();
            return f1;
        }
        inline M3*& get_f1(){
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
    
        inline void set_f4(E1 val){
            f4 = val;
        }
        inline E1& get_f4(){
            return f4;
        }
    
        inline void set_f5(float val){
            f5 = val;
        }
        inline float& get_f5(){
            return f5;
        }
    
        inline void set_f6(float val){
            f6 = val;
        }
        inline float& get_f6(){
            return f6;
        }
    
        inline void set_f7(int32_t val){
            f7 = val;
        }
        inline int32_t& get_f7(){
            return f7;
        }
    
        inline M4* mutable_f8(){
            f8 = new M4();
            return f8;
        }
        inline M4*& get_f8(){
            return f8;
        }
    
        inline void set_f9(int32_t val){
            f9 = val;
        }
        inline int32_t& get_f9(){
            return f9;
        }
    
        inline void set_f10(string val){
            f10 = val;
        }
        inline string& get_f10(){
            return f10;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M2->f2: " << f2 << std::endl;
            fout << "M2->f3: " << f3 << std::endl;
            fout << "M2->f4: " << f4 << std::endl;
            fout << "M2->f5: " << f5 << std::endl;
            fout << "M2->f6: " << f6 << std::endl;
            fout << "M2->f7: " << f7 << std::endl;
            if(f8 != nullptr)
                f8->print_message(fout);
            fout << "M2->f9: " << f9 << std::endl;
            fout << "M2->f10: " << f10 << std::endl;
        }
    
        ~M2(){
            if(f1 != nullptr)
                delete f1;
            if(f8 != nullptr)
                delete f8;
        }
    
        M2(){
           f1 = nullptr;
           f8 = nullptr;
        }
    
    private:
        alignas(8) M3* f1;
        alignas(8) int32_t f2;
        alignas(8) float f3;
        alignas(8) E1 f4;
        alignas(8) float f5;
        alignas(8) float f6;
        alignas(8) int32_t f7;
        alignas(8) M4* f8;
        alignas(8) int32_t f9;
        alignas(8) string f10;
    };


    class alignas(8) M6 : public M_base
    {
    public:
        class alignas(8) M7 : public M_base
        {
        public:
            inline void set_f1(float val){
                f1 = val;
            }
            inline float& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M7->f1: " << f1 << std::endl;
            }
        
            ~M7(){
            }
        
            M7(){
            }
        
        private:
            alignas(8) float f1;
        };


        class alignas(8) M8 : public M_base
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M8->f1: " << f1 << std::endl;
                fout << "M8->f2: " << f2 << std::endl;
            }
        
            ~M8(){
            }
        
            M8(){
            }
        
        private:
            alignas(8) bool f1;
            alignas(8) int32_t f2;
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
                        fout << "M11->f1: " << f1 << std::endl;
                        fout << "M11->f2: " << f2 << std::endl;
                    }
                
                    ~M11(){
                    }
                
                    M11(){
                    }
                
                private:
                    alignas(8) string f1;
                    alignas(8) string f2;
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


            inline void set_f1(bool val){
                f1 = val;
            }
            inline bool& get_f1(){
                return f1;
            }
        
            inline M10* mutable_f2(){
                f2 = new M10();
                return f2;
            }
            inline M10*& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M9->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
            }
        
            ~M9(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M9(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) bool f1;
            alignas(8) M10* f2;
        };


        inline M7* mutable_f1(){
            f1 = new M7();
            return f1;
        }
        inline M7*& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint64_t val){
            f2 = val;
        }
        inline uint64_t& get_f2(){
            return f2;
        }
    
        inline M8* mutable_f3(){
            f3 = new M8();
            return f3;
        }
        inline M8*& get_f3(){
            return f3;
        }
    
        inline M9* mutable_f4(){
            f4 = new M9();
            return f4;
        }
        inline M9*& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M6->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
            if(f4 != nullptr)
                f4->print_message(fout);
        }
    
        ~M6(){
            if(f1 != nullptr)
                delete f1;
            if(f3 != nullptr)
                delete f3;
            if(f4 != nullptr)
                delete f4;
        }
    
        M6(){
           f1 = nullptr;
           f3 = nullptr;
           f4 = nullptr;
        }
    
    private:
        alignas(8) M7* f1;
        alignas(8) uint64_t f2;
        alignas(8) M8* f3;
        alignas(8) M9* f4;
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

    inline M2* mutable_f3(){
        f3 = new M2();
        return f3;
    }
    inline M2*& get_f3(){
        return f3;
    }

    inline void set_f4(float val){
        f4 = val;
    }
    inline float& get_f4(){
        return f4;
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

    inline void set_f10(int32_t val){
        f10 = val;
    }
    inline int32_t& get_f10(){
        return f10;
    }

    inline M6* mutable_f11(){
        f11 = new M6();
        return f11;
    }
    inline M6*& get_f11(){
        return f11;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M1->f1: " << f1 << std::endl;
        fout << "M1->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
        fout << "M1->f4: " << f4 << std::endl;
        fout << "M1->f5: " << f5 << std::endl;
        fout << "M1->f6: " << f6 << std::endl;
        fout << "M1->f7: " << f7 << std::endl;
        fout << "M1->f8: " << f8 << std::endl;
        fout << "M1->f9: " << f9 << std::endl;
        fout << "M1->f10: " << f10 << std::endl;
        if(f11 != nullptr)
            f11->print_message(fout);
    }

    ~M1(){
        if(f3 != nullptr)
            delete f3;
        if(f11 != nullptr)
            delete f11;
    }

    M1(){
       f3 = nullptr;
       f11 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) uint64_t f2;
    alignas(8) M2* f3;
    alignas(8) float f4;
    alignas(8) string f5;
    alignas(8) bool f6;
    alignas(8) string f7;
    alignas(8) string f8;
    alignas(8) E1 f9;
    alignas(8) int32_t f10;
    alignas(8) M6* f11;
};


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
                inline void set_f1(int32_t val){
                    f1 = val;
                }
                inline int32_t& get_f1(){
                    return f1;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M15->f1: " << f1 << std::endl;
                }
            
                ~M15(){
                }
            
                M15(){
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
        
            inline M15* mutable_f2(){
                f2 = new M15();
                return f2;
            }
            inline M15*& get_f2(){
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
        
            inline void set_f5(string val){
                f5 = val;
            }
            inline string& get_f5(){
                return f5;
            }
        
            inline void set_f6(float val){
                f6 = val;
            }
            inline float& get_f6(){
                return f6;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M14->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M14->f3: " << f3 << std::endl;
                fout << "M14->f4: " << f4 << std::endl;
                fout << "M14->f5: " << f5 << std::endl;
                fout << "M14->f6: " << f6 << std::endl;
            }
        
            ~M14(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M14(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) M15* f2;
            alignas(8) bool f3;
            alignas(8) int32_t f4;
            alignas(8) string f5;
            alignas(8) float f6;
        };


        inline M14* mutable_f1(){
            f1 = new M14();
            return f1;
        }
        inline M14*& get_f1(){
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
            fout << "M13->f2: " << f2 << std::endl;
        }
    
        ~M13(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M13(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M14* f1;
        alignas(8) int32_t f2;
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
            fout << "M16->f1: " << f1 << std::endl;
            fout << "M16->f2: " << f2 << std::endl;
            fout << "M16->f3: " << f3 << std::endl;
        }
    
        ~M16(){
        }
    
        M16(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) int32_t f2;
        alignas(8) int32_t f3;
    };


    class alignas(8) M17 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 96,
            E1_CONST_2 = 33,
            E1_CONST_3 = 98,
            E1_CONST_4 = 16,
            E1_CONST_5 = 61,
        };
        
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
                        enum E1 {
                            E1_CONST_1 = 2,
                            E1_CONST_2 = 36,
                            E1_CONST_3 = 45,
                            E1_CONST_4 = 113,
                            E1_CONST_5 = 125,
                        };
                        
                        inline void set_f1(string val){
                            f1 = val;
                        }
                        inline string& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(E1 val){
                            f2 = val;
                        }
                        inline E1& get_f2(){
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
                        alignas(8) string f1;
                        alignas(8) E1 f2;
                    };


                    inline M21* mutable_f1(){
                        f1 = new M21();
                        return f1;
                    }
                    inline M21*& get_f1(){
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
                        fout << "M20->f2: " << f2 << std::endl;
                    }
                
                    ~M20(){
                        if(f1 != nullptr)
                            delete f1;
                    }
                
                    M20(){
                       f1 = nullptr;
                    }
                
                private:
                    alignas(8) M21* f1;
                    alignas(8) int32_t f2;
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
            
                inline void print_message(std::ofstream &fout){
                    fout << "M19->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
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
            };


            inline void set_f1(uint64_t val){
                f1 = val;
            }
            inline uint64_t& get_f1(){
                return f1;
            }
        
            inline M19* mutable_f2(){
                f2 = new M19();
                return f2;
            }
            inline M19*& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M18->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
            }
        
            ~M18(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M18(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) uint64_t f1;
            alignas(8) M19* f2;
        };


        class alignas(8) M22 : public M_base
        {
        public:
            inline void set_f1(float val){
                f1 = val;
            }
            inline float& get_f1(){
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
                fout << "M22->f1: " << f1 << std::endl;
                fout << "M22->f2: " << f2 << std::endl;
                fout << "M22->f3: " << f3 << std::endl;
            }
        
            ~M22(){
            }
        
            M22(){
            }
        
        private:
            alignas(8) float f1;
            alignas(8) string f2;
            alignas(8) int32_t f3;
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
    
        inline void set_f3(int32_t val){
            f3 = val;
        }
        inline int32_t& get_f3(){
            return f3;
        }
    
        inline M18* mutable_f4(){
            f4 = new M18();
            return f4;
        }
        inline M18*& get_f4(){
            return f4;
        }
    
        inline M22* mutable_f5(){
            f5 = new M22();
            return f5;
        }
        inline M22*& get_f5(){
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
            fout << "M17->f1: " << f1 << std::endl;
            fout << "M17->f2: " << f2 << std::endl;
            fout << "M17->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
            if(f5 != nullptr)
                f5->print_message(fout);
            fout << "M17->f6: " << f6 << std::endl;
            fout << "M17->f7: " << f7 << std::endl;
        }
    
        ~M17(){
            if(f4 != nullptr)
                delete f4;
            if(f5 != nullptr)
                delete f5;
        }
    
        M17(){
           f4 = nullptr;
           f5 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) E1 f2;
        alignas(8) int32_t f3;
        alignas(8) M18* f4;
        alignas(8) M22* f5;
        alignas(8) int32_t f6;
        alignas(8) int32_t f7;
    };


    inline M13* mutable_f1(){
        f1 = new M13();
        return f1;
    }
    inline M13*& get_f1(){
        return f1;
    }

    inline void set_f2(string val){
        f2 = val;
    }
    inline string& get_f2(){
        return f2;
    }

    inline M16* mutable_f3(){
        f3 = new M16();
        return f3;
    }
    inline M16*& get_f3(){
        return f3;
    }

    inline void set_f4(int64_t val){
        f4 = val;
    }
    inline int64_t& get_f4(){
        return f4;
    }

    inline M17* mutable_f5(){
        f5 = new M17();
        return f5;
    }
    inline M17*& get_f5(){
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

    inline void set_f13(int32_t val){
        f13 = val;
    }
    inline int32_t& get_f13(){
        return f13;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        fout << "M12->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
        fout << "M12->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        fout << "M12->f6: " << f6 << std::endl;
        fout << "M12->f7: " << f7 << std::endl;
        fout << "M12->f8: " << f8 << std::endl;
        fout << "M12->f9: " << f9 << std::endl;
        fout << "M12->f10: " << f10 << std::endl;
        fout << "M12->f11: " << f11 << std::endl;
        fout << "M12->f12: " << f12 << std::endl;
        fout << "M12->f13: " << f13 << std::endl;
    }

    ~M12(){
        if(f1 != nullptr)
            delete f1;
        if(f3 != nullptr)
            delete f3;
        if(f5 != nullptr)
            delete f5;
    }

    M12(){
       f1 = nullptr;
       f3 = nullptr;
       f5 = nullptr;
    }

private:
    alignas(8) M13* f1;
    alignas(8) string f2;
    alignas(8) M16* f3;
    alignas(8) int64_t f4;
    alignas(8) M17* f5;
    alignas(8) bool f6;
    alignas(8) string f7;
    alignas(8) int32_t f8;
    alignas(8) int32_t f9;
    alignas(8) int64_t f10;
    alignas(8) int64_t f11;
    alignas(8) string f12;
    alignas(8) int32_t f13;
};


class alignas(8) M23 : public M_base
{
public:
    class alignas(8) M24 : public M_base
    {
    public:
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


        class alignas(8) M26 : public M_base
        {
        public:
            inline void set_f1(string val){
                f1 = val;
            }
            inline string& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M26->f1: " << f1 << std::endl;
            }
        
            ~M26(){
            }
        
            M26(){
            }
        
        private:
            alignas(8) string f1;
        };


        class alignas(8) M27 : public M_base
        {
        public:
            inline void add_f1(uint8_t val){
                f1.push_back(val);
            }
            inline uint8_t get_f1(int idx){
                return f1[idx];
            }
        
            inline void print_message(std::ofstream &fout){
                for(auto f1_val : f1){
                    fout << "M27->f1: " << (f1_val ? 1 : 0) << std::endl;
                }
            }
        
            ~M27(){
            }
        
            M27(){
            }
        
        private:
            alignas(8) std::vector<uint8_t> f1;
        };


        inline void set_f1(double val){
            f1 = val;
        }
        inline double& get_f1(){
            return f1;
        }
    
        inline M25* mutable_f2(){
            f2 = new M25();
            return f2;
        }
        inline M25*& get_f2(){
            return f2;
        }
    
        inline M26* mutable_f3(){
            f3 = new M26();
            return f3;
        }
        inline M26*& get_f3(){
            return f3;
        }
    
        inline M27* mutable_f4(){
            f4 = new M27();
            return f4;
        }
        inline M27*& get_f4(){
            return f4;
        }
    
        inline void set_f5(int32_t val){
            f5 = val;
        }
        inline int32_t& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M24->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            if(f3 != nullptr)
                f3->print_message(fout);
            if(f4 != nullptr)
                f4->print_message(fout);
            fout << "M24->f5: " << f5 << std::endl;
        }
    
        ~M24(){
            if(f2 != nullptr)
                delete f2;
            if(f3 != nullptr)
                delete f3;
            if(f4 != nullptr)
                delete f4;
        }
    
        M24(){
           f2 = nullptr;
           f3 = nullptr;
           f4 = nullptr;
        }
    
    private:
        alignas(8) double f1;
        alignas(8) M25* f2;
        alignas(8) M26* f3;
        alignas(8) M27* f4;
        alignas(8) int32_t f5;
    };


    class alignas(8) M28 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
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
        alignas(8) int32_t f1;
    };


    class alignas(8) M29 : public M_base
    {
    public:
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
                        E1_CONST_1 = 38,
                        E1_CONST_2 = 7,
                        E1_CONST_3 = 72,
                        E1_CONST_4 = 76,
                        E1_CONST_5 = 47,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
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
                
                    inline void set_f4(string val){
                        f4 = val;
                    }
                    inline string& get_f4(){
                        return f4;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M32->f1: " << f1 << std::endl;
                        fout << "M32->f2: " << f2 << std::endl;
                        fout << "M32->f3: " << f3 << std::endl;
                        fout << "M32->f4: " << f4 << std::endl;
                    }
                
                    ~M32(){
                    }
                
                    M32(){
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) bool f2;
                    alignas(8) int32_t f3;
                    alignas(8) string f4;
                };


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
            
                inline void set_f6(string val){
                    f6 = val;
                }
                inline string& get_f6(){
                    return f6;
                }
            
                inline M32* mutable_f7(){
                    f7 = new M32();
                    return f7;
                }
                inline M32*& get_f7(){
                    return f7;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M31->f1: " << f1 << std::endl;
                    fout << "M31->f2: " << f2 << std::endl;
                    fout << "M31->f3: " << f3 << std::endl;
                    fout << "M31->f4: " << f4 << std::endl;
                    fout << "M31->f5: " << f5 << std::endl;
                    fout << "M31->f6: " << f6 << std::endl;
                    if(f7 != nullptr)
                        f7->print_message(fout);
                }
            
                ~M31(){
                    if(f7 != nullptr)
                        delete f7;
                }
            
                M31(){
                   f7 = nullptr;
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) float f2;
                alignas(8) int32_t f3;
                alignas(8) int32_t f4;
                alignas(8) bool f5;
                alignas(8) string f6;
                alignas(8) M32* f7;
            };


            inline M31* mutable_f1(){
                f1 = new M31();
                return f1;
            }
            inline M31*& get_f1(){
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
                fout << "M30->f2: " << f2 << std::endl;
            }
        
            ~M30(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M30(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M31* f1;
            alignas(8) uint64_t f2;
        };


        class alignas(8) M33 : public M_base
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
        
            inline void set_f3(string val){
                f3 = val;
            }
            inline string& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M33->f1: " << f1 << std::endl;
                fout << "M33->f2: " << f2 << std::endl;
                fout << "M33->f3: " << f3 << std::endl;
            }
        
            ~M33(){
            }
        
            M33(){
            }
        
        private:
            alignas(8) string f1;
            alignas(8) int32_t f2;
            alignas(8) string f3;
        };


        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline M30* mutable_f2(){
            f2 = new M30();
            return f2;
        }
        inline M30*& get_f2(){
            return f2;
        }
    
        inline void set_f3(int32_t val){
            f3 = val;
        }
        inline int32_t& get_f3(){
            return f3;
        }
    
        inline M33* mutable_f4(){
            f4 = new M33();
            return f4;
        }
        inline M33*& get_f4(){
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
    
        inline void print_message(std::ofstream &fout){
            fout << "M29->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M29->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
            fout << "M29->f5: " << f5 << std::endl;
            fout << "M29->f6: " << f6 << std::endl;
        }
    
        ~M29(){
            if(f2 != nullptr)
                delete f2;
            if(f4 != nullptr)
                delete f4;
        }
    
        M29(){
           f2 = nullptr;
           f4 = nullptr;
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) M30* f2;
        alignas(8) int32_t f3;
        alignas(8) M33* f4;
        alignas(8) float f5;
        alignas(8) string f6;
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

    inline void set_f4(float val){
        f4 = val;
    }
    inline float& get_f4(){
        return f4;
    }

    inline void set_f5(int32_t val){
        f5 = val;
    }
    inline int32_t& get_f5(){
        return f5;
    }

    inline M28* mutable_f6(){
        f6 = new M28();
        return f6;
    }
    inline M28*& get_f6(){
        return f6;
    }

    inline M29* mutable_f7(){
        f7 = new M29();
        return f7;
    }
    inline M29*& get_f7(){
        return f7;
    }

    inline void set_f8(int64_t val){
        f8 = val;
    }
    inline int64_t& get_f8(){
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
        fout << "M23->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M23->f3: " << f3 << std::endl;
        fout << "M23->f4: " << f4 << std::endl;
        fout << "M23->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        if(f7 != nullptr)
            f7->print_message(fout);
        fout << "M23->f8: " << f8 << std::endl;
        fout << "M23->f9: " << f9 << std::endl;
        fout << "M23->f10: " << f10 << std::endl;
    }

    ~M23(){
        if(f2 != nullptr)
            delete f2;
        if(f6 != nullptr)
            delete f6;
        if(f7 != nullptr)
            delete f7;
    }

    M23(){
       f2 = nullptr;
       f6 = nullptr;
       f7 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) M24* f2;
    alignas(8) int32_t f3;
    alignas(8) float f4;
    alignas(8) int32_t f5;
    alignas(8) M28* f6;
    alignas(8) M29* f7;
    alignas(8) int64_t f8;
    alignas(8) float f9;
    alignas(8) int32_t f10;
};


class alignas(8) M34 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 2,
        E1_CONST_2 = 50,
        E1_CONST_3 = 21,
        E1_CONST_4 = 55,
        E1_CONST_5 = 56,
    };
    
    enum E2 {
        E2_CONST_1 = 68,
        E2_CONST_2 = 43,
        E2_CONST_3 = 7214,
        E2_CONST_4 = 55,
        E2_CONST_5 = 56,
    };
    
    class alignas(8) M35 : public M_base
    {
    public:
        inline void set_f1(uint64_t val){
            f1 = val;
        }
        inline uint64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M35->f1: " << f1 << std::endl;
        }
    
        ~M35(){
        }
    
        M35(){
        }
    
    private:
        alignas(8) uint64_t f1;
    };


    class alignas(8) M36 : public M_base
    {
    public:
        inline void set_f1(uint64_t val){
            f1 = val;
        }
        inline uint64_t& get_f1(){
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
    
        inline void set_f4(uint32_t val){
            f4 = val;
        }
        inline uint32_t& get_f4(){
            return f4;
        }
    
        inline void set_f5(int32_t val){
            f5 = val;
        }
        inline int32_t& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M36->f1: " << f1 << std::endl;
            fout << "M36->f2: " << f2 << std::endl;
            fout << "M36->f3: " << f3 << std::endl;
            fout << "M36->f4: " << f4 << std::endl;
            fout << "M36->f5: " << f5 << std::endl;
        }
    
        ~M36(){
        }
    
        M36(){
        }
    
    private:
        alignas(8) uint64_t f1;
        alignas(8) string f2;
        alignas(8) int32_t f3;
        alignas(8) uint32_t f4;
        alignas(8) int32_t f5;
    };


    class alignas(8) M37 : public M_base
    {
    public:
        class alignas(8) M38 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 99,
                E1_CONST_2 = 40,
                E1_CONST_3 = 104,
                E1_CONST_4 = 19,
                E1_CONST_5 = 115,
            };
            
            class alignas(8) M39 : public M_base
            {
            public:
                class alignas(8) M40 : public M_base
                {
                public:
                    class alignas(8) M41 : public M_base
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
                    
                        inline void set_f5(string val){
                            f5 = val;
                        }
                        inline string& get_f5(){
                            return f5;
                        }
                    
                        inline void set_f6(float val){
                            f6 = val;
                        }
                        inline float& get_f6(){
                            return f6;
                        }
                    
                        inline void set_f7(int32_t val){
                            f7 = val;
                        }
                        inline int32_t& get_f7(){
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
                    
                        inline void set_f10(uint64_t val){
                            f10 = val;
                        }
                        inline uint64_t& get_f10(){
                            return f10;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M41->f1: " << f1 << std::endl;
                            fout << "M41->f2: " << f2 << std::endl;
                            fout << "M41->f3: " << f3 << std::endl;
                            fout << "M41->f4: " << f4 << std::endl;
                            fout << "M41->f5: " << f5 << std::endl;
                            fout << "M41->f6: " << f6 << std::endl;
                            fout << "M41->f7: " << f7 << std::endl;
                            for(auto &f8_val : f8){
                                fout << "M41->f8: " << f8_val << std::endl;
                            }
                            fout << "M41->f9: " << f9 << std::endl;
                            fout << "M41->f10: " << f10 << std::endl;
                        }
                    
                        ~M41(){
                        }
                    
                        M41(){
                        }
                    
                    private:
                        alignas(8) float f1;
                        alignas(8) int32_t f2;
                        alignas(8) string f3;
                        alignas(8) string f4;
                        alignas(8) string f5;
                        alignas(8) float f6;
                        alignas(8) int32_t f7;
                        alignas(8) std::vector<string> f8;
                        alignas(8) string f9;
                        alignas(8) uint64_t f10;
                    };


                    inline void set_f1(int32_t val){
                        f1 = val;
                    }
                    inline int32_t& get_f1(){
                        return f1;
                    }
                
                    inline M41* mutable_f2(){
                        f2 = new M41();
                        return f2;
                    }
                    inline M41*& get_f2(){
                        return f2;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M40->f1: " << f1 << std::endl;
                        if(f2 != nullptr)
                            f2->print_message(fout);
                    }
                
                    ~M40(){
                        if(f2 != nullptr)
                            delete f2;
                    }
                
                    M40(){
                       f2 = nullptr;
                    }
                
                private:
                    alignas(8) int32_t f1;
                    alignas(8) M41* f2;
                };


                inline void set_f1(string val){
                    f1 = val;
                }
                inline string& get_f1(){
                    return f1;
                }
            
                inline M40* mutable_f2(){
                    f2 = new M40();
                    return f2;
                }
                inline M40*& get_f2(){
                    return f2;
                }
            
                inline void set_f3(int32_t val){
                    f3 = val;
                }
                inline int32_t& get_f3(){
                    return f3;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M39->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    fout << "M39->f3: " << f3 << std::endl;
                }
            
                ~M39(){
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M39(){
                   f2 = nullptr;
                }
            
            private:
                alignas(8) string f1;
                alignas(8) M40* f2;
                alignas(8) int32_t f3;
            };


            inline M39* mutable_f1(){
                f1 = new M39();
                return f1;
            }
            inline M39*& get_f1(){
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
        
            inline void set_f5(int32_t val){
                f5 = val;
            }
            inline int32_t& get_f5(){
                return f5;
            }
        
            inline void set_f6(E1 val){
                f6 = val;
            }
            inline E1& get_f6(){
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
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                fout << "M38->f2: " << f2 << std::endl;
                fout << "M38->f3: " << f3 << std::endl;
                fout << "M38->f4: " << f4 << std::endl;
                fout << "M38->f5: " << f5 << std::endl;
                fout << "M38->f6: " << f6 << std::endl;
                fout << "M38->f7: " << f7 << std::endl;
                fout << "M38->f8: " << f8 << std::endl;
            }
        
            ~M38(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M38(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M39* f1;
            alignas(8) int32_t f2;
            alignas(8) int64_t f3;
            alignas(8) int32_t f4;
            alignas(8) int32_t f5;
            alignas(8) E1 f6;
            alignas(8) int32_t f7;
            alignas(8) int64_t f8;
        };


        inline void set_f1(float val){
            f1 = val;
        }
        inline float& get_f1(){
            return f1;
        }
    
        inline void set_f2(float val){
            f2 = val;
        }
        inline float& get_f2(){
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
        alignas(8) float f1;
        alignas(8) float f2;
        alignas(8) M38* f3;
    };


    class alignas(8) M42 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M42->f1: " << f1 << std::endl;
        }
    
        ~M42(){
        }
    
        M42(){
        }
    
    private:
        alignas(8) int32_t f1;
    };


    inline void set_f1(E1 val){
        f1 = val;
    }
    inline E1& get_f1(){
        return f1;
    }

    inline M35* mutable_f2(){
        f2 = new M35();
        return f2;
    }
    inline M35*& get_f2(){
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

    inline void set_f9(E2 val){
        f9 = val;
    }
    inline E2& get_f9(){
        return f9;
    }

    inline M36* mutable_f10(){
        f10 = new M36();
        return f10;
    }
    inline M36*& get_f10(){
        return f10;
    }

    inline M37* mutable_f11(){
        f11 = new M37();
        return f11;
    }
    inline M37*& get_f11(){
        return f11;
    }

    inline void set_f12(int32_t val){
        f12 = val;
    }
    inline int32_t& get_f12(){
        return f12;
    }

    inline void set_f13(uint64_t val){
        f13 = val;
    }
    inline uint64_t& get_f13(){
        return f13;
    }

    inline M42* mutable_f14(){
        f14 = new M42();
        return f14;
    }
    inline M42*& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M34->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M34->f3: " << f3 << std::endl;
        fout << "M34->f4: " << f4 << std::endl;
        fout << "M34->f5: " << f5 << std::endl;
        fout << "M34->f6: " << f6 << std::endl;
        fout << "M34->f7: " << f7 << std::endl;
        fout << "M34->f8: " << f8 << std::endl;
        fout << "M34->f9: " << f9 << std::endl;
        if(f10 != nullptr)
            f10->print_message(fout);
        if(f11 != nullptr)
            f11->print_message(fout);
        fout << "M34->f12: " << f12 << std::endl;
        fout << "M34->f13: " << f13 << std::endl;
        if(f14 != nullptr)
            f14->print_message(fout);
    }

    ~M34(){
        if(f2 != nullptr)
            delete f2;
        if(f10 != nullptr)
            delete f10;
        if(f11 != nullptr)
            delete f11;
        if(f14 != nullptr)
            delete f14;
    }

    M34(){
       f2 = nullptr;
       f10 = nullptr;
       f11 = nullptr;
       f14 = nullptr;
    }

private:
    alignas(8) E1 f1;
    alignas(8) M35* f2;
    alignas(8) int32_t f3;
    alignas(8) string f4;
    alignas(8) int32_t f5;
    alignas(8) int32_t f6;
    alignas(8) int32_t f7;
    alignas(8) int64_t f8;
    alignas(8) E2 f9;
    alignas(8) M36* f10;
    alignas(8) M37* f11;
    alignas(8) int32_t f12;
    alignas(8) uint64_t f13;
    alignas(8) M42* f14;
};


class alignas(8) M43 : public M_base
{
public:
    class alignas(8) M44 : public M_base
    {
    public:
        class alignas(8) M45 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M45->f1: " << f1 << std::endl;
            }
        
            ~M45(){
            }
        
            M45(){
            }
        
        private:
            alignas(8) int32_t f1;
        };


        class alignas(8) M46 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 64,
                E1_CONST_2 = 66,
                E1_CONST_3 = 102,
                E1_CONST_4 = 24,
                E1_CONST_5 = 28,
            };
            
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void add_f2(E1 val){
                f2.push_back(val);
            }
            inline E1& get_f2(int idx){
                return f2[idx];
            }
        
            inline void set_f3(int64_t val){
                f3 = val;
            }
            inline int64_t& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M46->f1: " << f1 << std::endl;
                for(auto &f2_val : f2){
                    fout << "M46->f2: " << f2_val << std::endl;
                }
                fout << "M46->f3: " << f3 << std::endl;
            }
        
            ~M46(){
            }
        
            M46(){
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) std::vector<E1> f2;
            alignas(8) int64_t f3;
        };


        class alignas(8) M47 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
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
            alignas(8) int32_t f1;
        };


        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline M45* mutable_f2(){
            f2 = new M45();
            return f2;
        }
        inline M45*& get_f2(){
            return f2;
        }
    
        inline M46* mutable_f3(){
            f3 = new M46();
            return f3;
        }
        inline M46*& get_f3(){
            return f3;
        }
    
        inline M47* mutable_f4(){
            f4 = new M47();
            return f4;
        }
        inline M47*& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M44->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            if(f3 != nullptr)
                f3->print_message(fout);
            if(f4 != nullptr)
                f4->print_message(fout);
        }
    
        ~M44(){
            if(f2 != nullptr)
                delete f2;
            if(f3 != nullptr)
                delete f3;
            if(f4 != nullptr)
                delete f4;
        }
    
        M44(){
           f2 = nullptr;
           f3 = nullptr;
           f4 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) M45* f2;
        alignas(8) M46* f3;
        alignas(8) M47* f4;
    };


    class alignas(8) M48 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 5,
            E1_CONST_2 = 75,
            E1_CONST_3 = 107,
            E1_CONST_4 = 77,
            E1_CONST_5 = 78,
        };
        
        class alignas(8) M49 : public M_base
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
                fout << "M49->f1: " << f1 << std::endl;
                fout << "M49->f2: " << f2 << std::endl;
            }
        
            ~M49(){
            }
        
            M49(){
            }
        
        private:
            alignas(8) string f1;
            alignas(8) uint64_t f2;
        };


        class alignas(8) M50 : public M_base
        {
        public:
            class alignas(8) M51 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 102,
                    E1_CONST_2 = 40,
                    E1_CONST_3 = 82,
                    E1_CONST_4 = 52,
                    E1_CONST_5 = 24,
                };
                
                class alignas(8) M52 : public M_base
                {
                public:
                    class alignas(8) M53 : public M_base
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
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M53->f1: " << f1 << std::endl;
                            fout << "M53->f2: " << f2 << std::endl;
                        }
                    
                        ~M53(){
                        }
                    
                        M53(){
                        }
                    
                    private:
                        alignas(8) float f1;
                        alignas(8) uint64_t f2;
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
                
                    inline void set_f4(float val){
                        f4 = val;
                    }
                    inline float& get_f4(){
                        return f4;
                    }
                
                    inline M53* mutable_f5(){
                        f5 = new M53();
                        return f5;
                    }
                    inline M53*& get_f5(){
                        return f5;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M52->f1: " << f1 << std::endl;
                        fout << "M52->f2: " << f2 << std::endl;
                        fout << "M52->f3: " << f3 << std::endl;
                        fout << "M52->f4: " << f4 << std::endl;
                        if(f5 != nullptr)
                            f5->print_message(fout);
                    }
                
                    ~M52(){
                        if(f5 != nullptr)
                            delete f5;
                    }
                
                    M52(){
                       f5 = nullptr;
                    }
                
                private:
                    alignas(8) string f1;
                    alignas(8) int32_t f2;
                    alignas(8) int32_t f3;
                    alignas(8) float f4;
                    alignas(8) M53* f5;
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
            
                inline void set_f3(double val){
                    f3 = val;
                }
                inline double& get_f3(){
                    return f3;
                }
            
                inline void set_f4(E1 val){
                    f4 = val;
                }
                inline E1& get_f4(){
                    return f4;
                }
            
                inline void set_f5(float val){
                    f5 = val;
                }
                inline float& get_f5(){
                    return f5;
                }
            
                inline M52* mutable_f6(){
                    f6 = new M52();
                    return f6;
                }
                inline M52*& get_f6(){
                    return f6;
                }
            
                inline void set_f7(uint64_t val){
                    f7 = val;
                }
                inline uint64_t& get_f7(){
                    return f7;
                }
            
                inline void set_f8(float val){
                    f8 = val;
                }
                inline float& get_f8(){
                    return f8;
                }
            
                inline void set_f9(int32_t val){
                    f9 = val;
                }
                inline int32_t& get_f9(){
                    return f9;
                }
            
                inline void set_f10(string val){
                    f10 = val;
                }
                inline string& get_f10(){
                    return f10;
                }
            
                inline void add_f11(string val){
                    f11.push_back(val);
                }
                inline string& get_f11(int idx){
                    return f11[idx];
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M51->f1: " << f1 << std::endl;
                    fout << "M51->f2: " << f2 << std::endl;
                    fout << "M51->f3: " << f3 << std::endl;
                    fout << "M51->f4: " << f4 << std::endl;
                    fout << "M51->f5: " << f5 << std::endl;
                    if(f6 != nullptr)
                        f6->print_message(fout);
                    fout << "M51->f7: " << f7 << std::endl;
                    fout << "M51->f8: " << f8 << std::endl;
                    fout << "M51->f9: " << f9 << std::endl;
                    fout << "M51->f10: " << f10 << std::endl;
                    for(auto &f11_val : f11){
                        fout << "M51->f11: " << f11_val << std::endl;
                    }
                }
            
                ~M51(){
                    if(f6 != nullptr)
                        delete f6;
                }
            
                M51(){
                   f6 = nullptr;
                }
            
            private:
                alignas(8) string f1;
                alignas(8) string f2;
                alignas(8) double f3;
                alignas(8) E1 f4;
                alignas(8) float f5;
                alignas(8) M52* f6;
                alignas(8) uint64_t f7;
                alignas(8) float f8;
                alignas(8) int32_t f9;
                alignas(8) string f10;
                alignas(8) std::vector<string> f11;
            };


            inline M51* mutable_f1(){
                f1 = new M51();
                return f1;
            }
            inline M51*& get_f1(){
                return f1;
            }
        
            inline void set_f2(int64_t val){
                f2 = val;
            }
            inline int64_t& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                fout << "M50->f2: " << f2 << std::endl;
            }
        
            ~M50(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M50(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M51* f1;
            alignas(8) int64_t f2;
        };


        inline M49* mutable_f1(){
            f1 = new M49();
            return f1;
        }
        inline M49*& get_f1(){
            return f1;
        }
    
        inline void set_f2(E1 val){
            f2 = val;
        }
        inline E1& get_f2(){
            return f2;
        }
    
        inline void set_f3(int32_t val){
            f3 = val;
        }
        inline int32_t& get_f3(){
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
    
        inline void set_f9(double val){
            f9 = val;
        }
        inline double& get_f9(){
            return f9;
        }
    
        inline M50* mutable_f10(){
            f10 = new M50();
            return f10;
        }
        inline M50*& get_f10(){
            return f10;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M48->f2: " << f2 << std::endl;
            fout << "M48->f3: " << f3 << std::endl;
            fout << "M48->f4: " << f4 << std::endl;
            fout << "M48->f5: " << f5 << std::endl;
            fout << "M48->f6: " << f6 << std::endl;
            fout << "M48->f7: " << f7 << std::endl;
            fout << "M48->f8: " << f8 << std::endl;
            fout << "M48->f9: " << f9 << std::endl;
            if(f10 != nullptr)
                f10->print_message(fout);
        }
    
        ~M48(){
            if(f1 != nullptr)
                delete f1;
            if(f10 != nullptr)
                delete f10;
        }
    
        M48(){
           f1 = nullptr;
           f10 = nullptr;
        }
    
    private:
        alignas(8) M49* f1;
        alignas(8) E1 f2;
        alignas(8) int32_t f3;
        alignas(8) float f4;
        alignas(8) float f5;
        alignas(8) string f6;
        alignas(8) int64_t f7;
        alignas(8) string f8;
        alignas(8) double f9;
        alignas(8) M50* f10;
    };


    inline void set_f1(string val){
        f1 = val;
    }
    inline string& get_f1(){
        return f1;
    }

    inline void set_f2(float val){
        f2 = val;
    }
    inline float& get_f2(){
        return f2;
    }

    inline M44* mutable_f3(){
        f3 = new M44();
        return f3;
    }
    inline M44*& get_f3(){
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

    inline void set_f10(int32_t val){
        f10 = val;
    }
    inline int32_t& get_f10(){
        return f10;
    }

    inline void set_f11(uint64_t val){
        f11 = val;
    }
    inline uint64_t& get_f11(){
        return f11;
    }

    inline M48* mutable_f12(){
        f12 = new M48();
        return f12;
    }
    inline M48*& get_f12(){
        return f12;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M43->f1: " << f1 << std::endl;
        fout << "M43->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
        fout << "M43->f4: " << f4 << std::endl;
        fout << "M43->f5: " << f5 << std::endl;
        fout << "M43->f6: " << f6 << std::endl;
        fout << "M43->f7: " << f7 << std::endl;
        fout << "M43->f8: " << f8 << std::endl;
        fout << "M43->f9: " << f9 << std::endl;
        fout << "M43->f10: " << f10 << std::endl;
        fout << "M43->f11: " << f11 << std::endl;
        if(f12 != nullptr)
            f12->print_message(fout);
    }

    ~M43(){
        if(f3 != nullptr)
            delete f3;
        if(f12 != nullptr)
            delete f12;
    }

    M43(){
       f3 = nullptr;
       f12 = nullptr;
    }

private:
    alignas(8) string f1;
    alignas(8) float f2;
    alignas(8) M44* f3;
    alignas(8) int32_t f4;
    alignas(8) int64_t f5;
    alignas(8) int32_t f6;
    alignas(8) int64_t f7;
    alignas(8) int32_t f8;
    alignas(8) int32_t f9;
    alignas(8) int32_t f10;
    alignas(8) uint64_t f11;
    alignas(8) M48* f12;
};


class alignas(8) M54 : public M_base
{
public:
    class alignas(8) M55 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 1,
            E1_CONST_2 = 41,
            E1_CONST_3 = 118,
            E1_CONST_4 = 61,
            E1_CONST_5 = 95,
        };
        
        class alignas(8) M56 : public M_base
        {
        public:
            class alignas(8) M57 : public M_base
            {
            public:
                class alignas(8) M58 : public M_base
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
                
                    inline void set_f3(int32_t val){
                        f3 = val;
                    }
                    inline int32_t& get_f3(){
                        return f3;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M58->f1: " << f1 << std::endl;
                        fout << "M58->f2: " << f2 << std::endl;
                        fout << "M58->f3: " << f3 << std::endl;
                    }
                
                    ~M58(){
                    }
                
                    M58(){
                    }
                
                private:
                    alignas(8) int32_t f1;
                    alignas(8) int32_t f2;
                    alignas(8) int32_t f3;
                };


                inline M58* mutable_f1(){
                    f1 = new M58();
                    return f1;
                }
                inline M58*& get_f1(){
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
                    fout << "M57->f2: " << f2 << std::endl;
                }
            
                ~M57(){
                    if(f1 != nullptr)
                        delete f1;
                }
            
                M57(){
                   f1 = nullptr;
                }
            
            private:
                alignas(8) M58* f1;
                alignas(8) string f2;
            };


            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline M57* mutable_f2(){
                f2 = new M57();
                return f2;
            }
            inline M57*& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M56->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
            }
        
            ~M56(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M56(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) M57* f2;
        };


        inline void set_f1(float val){
            f1 = val;
        }
        inline float& get_f1(){
            return f1;
        }
    
        inline void set_f2(E1 val){
            f2 = val;
        }
        inline E1& get_f2(){
            return f2;
        }
    
        inline M56* mutable_f3(){
            f3 = new M56();
            return f3;
        }
        inline M56*& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M55->f1: " << f1 << std::endl;
            fout << "M55->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M55(){
            if(f3 != nullptr)
                delete f3;
        }
    
        M55(){
           f3 = nullptr;
        }
    
    private:
        alignas(8) float f1;
        alignas(8) E1 f2;
        alignas(8) M56* f3;
    };


    class alignas(8) M59 : public M_base
    {
    public:
        class alignas(8) M60 : public M_base
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
                fout << "M60->f1: " << f1 << std::endl;
                fout << "M60->f2: " << f2 << std::endl;
                fout << "M60->f3: " << f3 << std::endl;
                fout << "M60->f4: " << f4 << std::endl;
            }
        
            ~M60(){
            }
        
            M60(){
            }
        
        private:
            alignas(8) string f1;
            alignas(8) int32_t f2;
            alignas(8) string f3;
            alignas(8) int32_t f4;
        };


        inline M60* mutable_f1(){
            f1 = new M60();
            return f1;
        }
        inline M60*& get_f1(){
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
            fout << "M59->f2: " << f2 << std::endl;
        }
    
        ~M59(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M59(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M60* f1;
        alignas(8) uint64_t f2;
    };


    class alignas(8) M61 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 67,
            E1_CONST_2 = 38,
            E1_CONST_3 = 40,
            E1_CONST_4 = 43,
            E1_CONST_5 = 78,
        };
        
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void add_f2(E1 val){
            f2.push_back(val);
        }
        inline E1& get_f2(int idx){
            return f2[idx];
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M61->f1: " << f1 << std::endl;
            for(auto &f2_val : f2){
                fout << "M61->f2: " << f2_val << std::endl;
            }
        }
    
        ~M61(){
        }
    
        M61(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) std::vector<E1> f2;
    };


    class alignas(8) M62 : public M_base
    {
    public:
        class alignas(8) M63 : public M_base
        {
        public:
            inline void set_f1(uint32_t val){
                f1 = val;
            }
            inline uint32_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M63->f1: " << f1 << std::endl;
            }
        
            ~M63(){
            }
        
            M63(){
            }
        
        private:
            alignas(8) uint32_t f1;
        };


        inline void set_f1(uint64_t val){
            f1 = val;
        }
        inline uint64_t& get_f1(){
            return f1;
        }
    
        inline M63* mutable_f2(){
            f2 = new M63();
            return f2;
        }
        inline M63*& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M62->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
        }
    
        ~M62(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M62(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) uint64_t f1;
        alignas(8) M63* f2;
    };


    inline void add_f1(string val){
        f1.push_back(val);
    }
    inline string& get_f1(int idx){
        return f1[idx];
    }

    inline M55* mutable_f2(){
        f2 = new M55();
        return f2;
    }
    inline M55*& get_f2(){
        return f2;
    }

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
        return f3;
    }

    inline M59* mutable_f4(){
        f4 = new M59();
        return f4;
    }
    inline M59*& get_f4(){
        return f4;
    }

    inline void set_f5(string val){
        f5 = val;
    }
    inline string& get_f5(){
        return f5;
    }

    inline void add_f6(string val){
        f6.push_back(val);
    }
    inline string& get_f6(int idx){
        return f6[idx];
    }

    inline M61* mutable_f7(){
        f7 = new M61();
        return f7;
    }
    inline M61*& get_f7(){
        return f7;
    }

    inline void set_f8(int32_t val){
        f8 = val;
    }
    inline int32_t& get_f8(){
        return f8;
    }

    inline M62* mutable_f9(){
        f9 = new M62();
        return f9;
    }
    inline M62*& get_f9(){
        return f9;
    }

    inline void print_message(std::ofstream &fout){
        for(auto &f1_val : f1){
            fout << "M54->f1: " << f1_val << std::endl;
        }
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M54->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M54->f5: " << f5 << std::endl;
        for(auto &f6_val : f6){
            fout << "M54->f6: " << f6_val << std::endl;
        }
        if(f7 != nullptr)
            f7->print_message(fout);
        fout << "M54->f8: " << f8 << std::endl;
        if(f9 != nullptr)
            f9->print_message(fout);
    }

    ~M54(){
        if(f2 != nullptr)
            delete f2;
        if(f4 != nullptr)
            delete f4;
        if(f7 != nullptr)
            delete f7;
        if(f9 != nullptr)
            delete f9;
    }

    M54(){
       f2 = nullptr;
       f4 = nullptr;
       f7 = nullptr;
       f9 = nullptr;
    }

private:
    alignas(8) std::vector<string> f1;
    alignas(8) M55* f2;
    alignas(8) string f3;
    alignas(8) M59* f4;
    alignas(8) string f5;
    alignas(8) std::vector<string> f6;
    alignas(8) M61* f7;
    alignas(8) int32_t f8;
    alignas(8) M62* f9;
};


class alignas(8) M64 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 49,
        E1_CONST_2 = 18,
        E1_CONST_3 = 85,
        E1_CONST_4 = 122,
        E1_CONST_5 = 94,
    };
    
    class alignas(8) M65 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M65->f1: " << f1 << std::endl;
        }
    
        ~M65(){
        }
    
        M65(){
        }
    
    private:
        alignas(8) int32_t f1;
    };


    class alignas(8) M66 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M66->f1: " << f1 << std::endl;
        }
    
        ~M66(){
        }
    
        M66(){
        }
    
    private:
        alignas(8) int32_t f1;
    };


    class alignas(8) M67 : public M_base
    {
    public:
        inline void set_f1(float val){
            f1 = val;
        }
        inline float& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M67->f1: " << f1 << std::endl;
        }
    
        ~M67(){
        }
    
        M67(){
        }
    
    private:
        alignas(8) float f1;
    };


    class alignas(8) M68 : public M_base
    {
    public:
        class alignas(8) M69 : public M_base
        {
        public:
            class alignas(8) M70 : public M_base
            {
            public:
                class alignas(8) M71 : public M_base
                {
                public:
                    inline void set_f1(string val){
                        f1 = val;
                    }
                    inline string& get_f1(){
                        return f1;
                    }
                
                    inline void add_f2(int32_t val){
                        f2.push_back(val);
                    }
                    inline int32_t& get_f2(int idx){
                        return f2[idx];
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M71->f1: " << f1 << std::endl;
                        for(auto &f2_val : f2){
                            fout << "M71->f2: " << f2_val << std::endl;
                        }
                    }
                
                    ~M71(){
                    }
                
                    M71(){
                    }
                
                private:
                    alignas(8) string f1;
                    alignas(8) std::vector<int32_t> f2;
                };


                inline void set_f1(int32_t val){
                    f1 = val;
                }
                inline int32_t& get_f1(){
                    return f1;
                }
            
                inline M71* mutable_f2(){
                    f2 = new M71();
                    return f2;
                }
                inline M71*& get_f2(){
                    return f2;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M70->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
                }
            
                ~M70(){
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M70(){
                   f2 = nullptr;
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) M71* f2;
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
        
            inline M70* mutable_f4(){
                f4 = new M70();
                return f4;
            }
            inline M70*& get_f4(){
                return f4;
            }
        
            inline void set_f5(int32_t val){
                f5 = val;
            }
            inline int32_t& get_f5(){
                return f5;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M69->f1: " << f1 << std::endl;
                fout << "M69->f2: " << f2 << std::endl;
                fout << "M69->f3: " << f3 << std::endl;
                if(f4 != nullptr)
                    f4->print_message(fout);
                fout << "M69->f5: " << f5 << std::endl;
            }
        
            ~M69(){
                if(f4 != nullptr)
                    delete f4;
            }
        
            M69(){
               f4 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) string f2;
            alignas(8) int32_t f3;
            alignas(8) M70* f4;
            alignas(8) int32_t f5;
        };


        inline M69* mutable_f1(){
            f1 = new M69();
            return f1;
        }
        inline M69*& get_f1(){
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
            fout << "M68->f2: " << f2 << std::endl;
        }
    
        ~M68(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M68(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M69* f1;
        alignas(8) string f2;
    };


    inline void set_f1(int32_t val){
        f1 = val;
    }
    inline int32_t& get_f1(){
        return f1;
    }

    inline M65* mutable_f2(){
        f2 = new M65();
        return f2;
    }
    inline M65*& get_f2(){
        return f2;
    }

    inline M66* mutable_f3(){
        f3 = new M66();
        return f3;
    }
    inline M66*& get_f3(){
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

    inline M67* mutable_f6(){
        f6 = new M67();
        return f6;
    }
    inline M67*& get_f6(){
        return f6;
    }

    inline M68* mutable_f7(){
        f7 = new M68();
        return f7;
    }
    inline M68*& get_f7(){
        return f7;
    }

    inline void set_f8(uint64_t val){
        f8 = val;
    }
    inline uint64_t& get_f8(){
        return f8;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M64->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        if(f3 != nullptr)
            f3->print_message(fout);
        fout << "M64->f4: " << f4 << std::endl;
        fout << "M64->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        if(f7 != nullptr)
            f7->print_message(fout);
        fout << "M64->f8: " << f8 << std::endl;
    }

    ~M64(){
        if(f2 != nullptr)
            delete f2;
        if(f3 != nullptr)
            delete f3;
        if(f6 != nullptr)
            delete f6;
        if(f7 != nullptr)
            delete f7;
    }

    M64(){
       f2 = nullptr;
       f3 = nullptr;
       f6 = nullptr;
       f7 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) M65* f2;
    alignas(8) M66* f3;
    alignas(8) string f4;
    alignas(8) E1 f5;
    alignas(8) M67* f6;
    alignas(8) M68* f7;
    alignas(8) uint64_t f8;
};


class alignas(8) M72 : public M_base
{
public:
    class alignas(8) M73 : public M_base
    {
    public:
        class alignas(8) M74 : public M_base
        {
        public:
            inline void set_f1(float val){
                f1 = val;
            }
            inline float& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M74->f1: " << f1 << std::endl;
            }
        
            ~M74(){
            }
        
            M74(){
            }
        
        private:
            alignas(8) float f1;
        };


        class alignas(8) M75 : public M_base
        {
        public:
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M75->f1: " << f1 << std::endl;
                fout << "M75->f2: " << f2 << std::endl;
            }
        
            ~M75(){
            }
        
            M75(){
            }
        
        private:
            alignas(8) string f1;
            alignas(8) double f2;
        };


        inline M74* mutable_f1(){
            f1 = new M74();
            return f1;
        }
        inline M74*& get_f1(){
            return f1;
        }
    
        inline M75* mutable_f2(){
            f2 = new M75();
            return f2;
        }
        inline M75*& get_f2(){
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
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M73->f3: " << f3 << std::endl;
        }
    
        ~M73(){
            if(f1 != nullptr)
                delete f1;
            if(f2 != nullptr)
                delete f2;
        }
    
        M73(){
           f1 = nullptr;
           f2 = nullptr;
        }
    
    private:
        alignas(8) M74* f1;
        alignas(8) M75* f2;
        alignas(8) string f3;
    };


    class alignas(8) M76 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 4,
            E1_CONST_2 = 104,
            E1_CONST_3 = 14,
            E1_CONST_4 = 53,
            E1_CONST_5 = 91,
        };
        
        inline void set_f1(bool val){
            f1 = val;
        }
        inline bool& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint32_t val){
            f2 = val;
        }
        inline uint32_t& get_f2(){
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
    
        inline void print_message(std::ofstream &fout){
            fout << "M76->f1: " << f1 << std::endl;
            fout << "M76->f2: " << f2 << std::endl;
            fout << "M76->f3: " << f3 << std::endl;
            fout << "M76->f4: " << f4 << std::endl;
        }
    
        ~M76(){
        }
    
        M76(){
        }
    
    private:
        alignas(8) bool f1;
        alignas(8) uint32_t f2;
        alignas(8) int32_t f3;
        alignas(8) E1 f4;
    };


    class alignas(8) M77 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 4,
            E1_CONST_2 = 37,
            E1_CONST_3 = 40,
            E1_CONST_4 = 53,
            E1_CONST_5 = 122,
        };
        
        inline void set_f1(E1 val){
            f1 = val;
        }
        inline E1& get_f1(){
            return f1;
        }
    
        inline void set_f2(float val){
            f2 = val;
        }
        inline float& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M77->f1: " << f1 << std::endl;
            fout << "M77->f2: " << f2 << std::endl;
        }
    
        ~M77(){
        }
    
        M77(){
        }
    
    private:
        alignas(8) E1 f1;
        alignas(8) float f2;
    };


    class alignas(8) M78 : public M_base
    {
    public:
        class alignas(8) M79 : public M_base
        {
        public:
            class alignas(8) M80 : public M_base
            {
            public:
                class alignas(8) M81 : public M_base
                {
                public:
                    inline void set_f1(int32_t val){
                        f1 = val;
                    }
                    inline int32_t& get_f1(){
                        return f1;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M81->f1: " << f1 << std::endl;
                    }
                
                    ~M81(){
                    }
                
                    M81(){
                    }
                
                private:
                    alignas(8) int32_t f1;
                };


                inline M81* mutable_f1(){
                    f1 = new M81();
                    return f1;
                }
                inline M81*& get_f1(){
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
                    fout << "M80->f2: " << f2 << std::endl;
                }
            
                ~M80(){
                    if(f1 != nullptr)
                        delete f1;
                }
            
                M80(){
                   f1 = nullptr;
                }
            
            private:
                alignas(8) M81* f1;
                alignas(8) string f2;
            };


            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline M80* mutable_f2(){
                f2 = new M80();
                return f2;
            }
            inline M80*& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M79->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
            }
        
            ~M79(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M79(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) M80* f2;
        };


        inline M79* mutable_f1(){
            f1 = new M79();
            return f1;
        }
        inline M79*& get_f1(){
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
            fout << "M78->f2: " << f2 << std::endl;
        }
    
        ~M78(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M78(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M79* f1;
        alignas(8) int32_t f2;
    };


    inline void add_f1(int64_t val){
        f1.push_back(val);
    }
    inline int64_t& get_f1(int idx){
        return f1[idx];
    }

    inline M73* mutable_f2(){
        f2 = new M73();
        return f2;
    }
    inline M73*& get_f2(){
        return f2;
    }

    inline M76* mutable_f3(){
        f3 = new M76();
        return f3;
    }
    inline M76*& get_f3(){
        return f3;
    }

    inline M77* mutable_f4(){
        f4 = new M77();
        return f4;
    }
    inline M77*& get_f4(){
        return f4;
    }

    inline void set_f5(float val){
        f5 = val;
    }
    inline float& get_f5(){
        return f5;
    }

    inline void set_f6(int64_t val){
        f6 = val;
    }
    inline int64_t& get_f6(){
        return f6;
    }

    inline void set_f7(float val){
        f7 = val;
    }
    inline float& get_f7(){
        return f7;
    }

    inline void set_f8(int32_t val){
        f8 = val;
    }
    inline int32_t& get_f8(){
        return f8;
    }

    inline M78* mutable_f9(){
        f9 = new M78();
        return f9;
    }
    inline M78*& get_f9(){
        return f9;
    }

    inline void set_f10(int32_t val){
        f10 = val;
    }
    inline int32_t& get_f10(){
        return f10;
    }

    inline void print_message(std::ofstream &fout){
        for(auto &f1_val : f1){
            fout << "M72->f1: " << f1_val << std::endl;
        }
        if(f2 != nullptr)
            f2->print_message(fout);
        if(f3 != nullptr)
            f3->print_message(fout);
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M72->f5: " << f5 << std::endl;
        fout << "M72->f6: " << f6 << std::endl;
        fout << "M72->f7: " << f7 << std::endl;
        fout << "M72->f8: " << f8 << std::endl;
        if(f9 != nullptr)
            f9->print_message(fout);
        fout << "M72->f10: " << f10 << std::endl;
    }

    ~M72(){
        if(f2 != nullptr)
            delete f2;
        if(f3 != nullptr)
            delete f3;
        if(f4 != nullptr)
            delete f4;
        if(f9 != nullptr)
            delete f9;
    }

    M72(){
       f2 = nullptr;
       f3 = nullptr;
       f4 = nullptr;
       f9 = nullptr;
    }

private:
    alignas(8) std::vector<int64_t> f1;
    alignas(8) M73* f2;
    alignas(8) M76* f3;
    alignas(8) M77* f4;
    alignas(8) float f5;
    alignas(8) int64_t f6;
    alignas(8) float f7;
    alignas(8) int32_t f8;
    alignas(8) M78* f9;
    alignas(8) int32_t f10;
};


class alignas(8) M82 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 0,
        E1_CONST_2 = 67,
        E1_CONST_3 = 43,
        E1_CONST_4 = 78,
        E1_CONST_5 = 92,
    };
    
    class alignas(8) M83 : public M_base
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
            fout << "M83->f1: " << f1 << std::endl;
            fout << "M83->f2: " << f2 << std::endl;
        }
    
        ~M83(){
        }
    
        M83(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int32_t f2;
    };


    class alignas(8) M84 : public M_base
    {
    public:
        class alignas(8) M85 : public M_base
        {
        public:
            class alignas(8) M86 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 68,
                    E1_CONST_2 = 103,
                    E1_CONST_3 = 73,
                    E1_CONST_4 = 44,
                    E1_CONST_5 = 91,
                };
                
                class alignas(8) M87 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 38,
                        E1_CONST_2 = 18,
                        E1_CONST_3 = 20,
                        E1_CONST_4 = 25,
                        E1_CONST_5 = 122,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline void set_f2(string val){
                        f2 = val;
                    }
                    inline string& get_f2(){
                        return f2;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M87->f1: " << f1 << std::endl;
                        fout << "M87->f2: " << f2 << std::endl;
                    }
                
                    ~M87(){
                    }
                
                    M87(){
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) string f2;
                };


                inline M87* mutable_f1(){
                    f1 = new M87();
                    return f1;
                }
                inline M87*& get_f1(){
                    return f1;
                }
            
                inline void set_f2(E1 val){
                    f2 = val;
                }
                inline E1& get_f2(){
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
            
                inline void set_f5(int32_t val){
                    f5 = val;
                }
                inline int32_t& get_f5(){
                    return f5;
                }
            
                inline void print_message(std::ofstream &fout){
                    if(f1 != nullptr)
                        f1->print_message(fout);
                    fout << "M86->f2: " << f2 << std::endl;
                    fout << "M86->f3: " << f3 << std::endl;
                    fout << "M86->f4: " << f4 << std::endl;
                    fout << "M86->f5: " << f5 << std::endl;
                }
            
                ~M86(){
                    if(f1 != nullptr)
                        delete f1;
                }
            
                M86(){
                   f1 = nullptr;
                }
            
            private:
                alignas(8) M87* f1;
                alignas(8) E1 f2;
                alignas(8) bool f3;
                alignas(8) int64_t f4;
                alignas(8) int32_t f5;
            };


            inline M86* mutable_f1(){
                f1 = new M86();
                return f1;
            }
            inline M86*& get_f1(){
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
                fout << "M85->f2: " << f2 << std::endl;
            }
        
            ~M85(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M85(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M86* f1;
            alignas(8) int32_t f2;
        };


        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline M85* mutable_f2(){
            f2 = new M85();
            return f2;
        }
        inline M85*& get_f2(){
            return f2;
        }
    
        inline void set_f3(string val){
            f3 = val;
        }
        inline string& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M84->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M84->f3: " << f3 << std::endl;
        }
    
        ~M84(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M84(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) M85* f2;
        alignas(8) string f3;
    };


    class alignas(8) M88 : public M_base
    {
    public:
        class alignas(8) M89 : public M_base
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
        
            inline void set_f3(int32_t val){
                f3 = val;
            }
            inline int32_t& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M89->f1: " << f1 << std::endl;
                fout << "M89->f2: " << f2 << std::endl;
                fout << "M89->f3: " << f3 << std::endl;
            }
        
            ~M89(){
            }
        
            M89(){
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) float f2;
            alignas(8) int32_t f3;
        };


        inline void set_f1(string val){
            f1 = val;
        }
        inline string& get_f1(){
            return f1;
        }
    
        inline M89* mutable_f2(){
            f2 = new M89();
            return f2;
        }
        inline M89*& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M88->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
        }
    
        ~M88(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M88(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) string f1;
        alignas(8) M89* f2;
    };


    class alignas(8) M90 : public M_base
    {
    public:
        class alignas(8) M91 : public M_base
        {
        public:
            inline void set_f1(string val){
                f1 = val;
            }
            inline string& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M91->f1: " << f1 << std::endl;
            }
        
            ~M91(){
            }
        
            M91(){
            }
        
        private:
            alignas(8) string f1;
        };


        inline M91* mutable_f1(){
            f1 = new M91();
            return f1;
        }
        inline M91*& get_f1(){
            return f1;
        }
    
        inline void set_f2(float val){
            f2 = val;
        }
        inline float& get_f2(){
            return f2;
        }
    
        inline void add_f3(uint8_t val){
            f3.push_back(val);
        }
        inline uint8_t get_f3(int idx){
            return f3[idx];
        }
    
        inline void set_f4(float val){
            f4 = val;
        }
        inline float& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M90->f2: " << f2 << std::endl;
            for(auto f3_val : f3){
                fout << "M90->f3: " << (f3_val ? 1 : 0) << std::endl;
            }
            fout << "M90->f4: " << f4 << std::endl;
        }
    
        ~M90(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M90(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M91* f1;
        alignas(8) float f2;
        alignas(8) std::vector<uint8_t> f3;
        alignas(8) float f4;
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

    inline void set_f3(int64_t val){
        f3 = val;
    }
    inline int64_t& get_f3(){
        return f3;
    }

    inline M83* mutable_f4(){
        f4 = new M83();
        return f4;
    }
    inline M83*& get_f4(){
        return f4;
    }

    inline void set_f5(E1 val){
        f5 = val;
    }
    inline E1& get_f5(){
        return f5;
    }

    inline M84* mutable_f6(){
        f6 = new M84();
        return f6;
    }
    inline M84*& get_f6(){
        return f6;
    }

    inline M88* mutable_f7(){
        f7 = new M88();
        return f7;
    }
    inline M88*& get_f7(){
        return f7;
    }

    inline M90* mutable_f8(){
        f8 = new M90();
        return f8;
    }
    inline M90*& get_f8(){
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

    inline void set_f11(int32_t val){
        f11 = val;
    }
    inline int32_t& get_f11(){
        return f11;
    }

    inline void set_f12(int32_t val){
        f12 = val;
    }
    inline int32_t& get_f12(){
        return f12;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M82->f1: " << f1 << std::endl;
        fout << "M82->f2: " << f2 << std::endl;
        fout << "M82->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M82->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        if(f7 != nullptr)
            f7->print_message(fout);
        if(f8 != nullptr)
            f8->print_message(fout);
        fout << "M82->f9: " << f9 << std::endl;
        fout << "M82->f10: " << f10 << std::endl;
        fout << "M82->f11: " << f11 << std::endl;
        fout << "M82->f12: " << f12 << std::endl;
    }

    ~M82(){
        if(f4 != nullptr)
            delete f4;
        if(f6 != nullptr)
            delete f6;
        if(f7 != nullptr)
            delete f7;
        if(f8 != nullptr)
            delete f8;
    }

    M82(){
       f4 = nullptr;
       f6 = nullptr;
       f7 = nullptr;
       f8 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) double f2;
    alignas(8) int64_t f3;
    alignas(8) M83* f4;
    alignas(8) E1 f5;
    alignas(8) M84* f6;
    alignas(8) M88* f7;
    alignas(8) M90* f8;
    alignas(8) int32_t f9;
    alignas(8) int32_t f10;
    alignas(8) int32_t f11;
    alignas(8) int32_t f12;
};


class alignas(8) M92 : public M_base
{
public:
    class alignas(8) M93 : public M_base
    {
    public:
        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M93->f1: " << f1 << std::endl;
        }
    
        ~M93(){
        }
    
        M93(){
        }
    
    private:
        alignas(8) int32_t f1;
    };


    class alignas(8) M94 : public M_base
    {
    public:
        class alignas(8) M95 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M95->f1: " << f1 << std::endl;
            }
        
            ~M95(){
            }
        
            M95(){
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
    
        inline M95* mutable_f2(){
            f2 = new M95();
            return f2;
        }
        inline M95*& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M94->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
        }
    
        ~M94(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M94(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) M95* f2;
    };


    inline M93* mutable_f1(){
        f1 = new M93();
        return f1;
    }
    inline M93*& get_f1(){
        return f1;
    }

    inline M94* mutable_f2(){
        f2 = new M94();
        return f2;
    }
    inline M94*& get_f2(){
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

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M92->f3: " << f3 << std::endl;
        fout << "M92->f4: " << f4 << std::endl;
    }

    ~M92(){
        if(f1 != nullptr)
            delete f1;
        if(f2 != nullptr)
            delete f2;
    }

    M92(){
       f1 = nullptr;
       f2 = nullptr;
    }

private:
    alignas(8) M93* f1;
    alignas(8) M94* f2;
    alignas(8) int32_t f3;
    alignas(8) int32_t f4;
};

M_base* createMessage(int temp_class_id) {
    switch (temp_class_id) {
        case 12:
            return new M12();
        case 13:
            return new M12::M13();
        case 14:
            return new M12::M13::M14();
        case 15:
            return new M12::M13::M14::M15();
        case 17:
            return new M12::M17();
        case 18:
            return new M12::M17::M18();
        case 19:
            return new M12::M17::M18::M19();
        case 20:
            return new M12::M17::M18::M19::M20();
        case 21:
            return new M12::M17::M18::M19::M20::M21();
        case 22:
            return new M12::M17::M22();
        case 16:
            return new M12::M16();
        case 1:
            return new M1();
        case 2:
            return new M1::M2();
        case 4:
            return new M1::M2::M4();
        case 5:
            return new M1::M2::M4::M5();
        case 3:
            return new M1::M2::M3();
        case 6:
            return new M1::M6();
        case 9:
            return new M1::M6::M9();
        case 10:
            return new M1::M6::M9::M10();
        case 11:
            return new M1::M6::M9::M10::M11();
        case 8:
            return new M1::M6::M8();
        case 7:
            return new M1::M6::M7();
        case 23:
            return new M23();
        case 29:
            return new M23::M29();
        case 33:
            return new M23::M29::M33();
        case 30:
            return new M23::M29::M30();
        case 31:
            return new M23::M29::M30::M31();
        case 32:
            return new M23::M29::M30::M31::M32();
        case 24:
            return new M23::M24();
        case 26:
            return new M23::M24::M26();
        case 27:
            return new M23::M24::M27();
        case 25:
            return new M23::M24::M25();
        case 28:
            return new M23::M28();
        case 34:
            return new M34();
        case 42:
            return new M34::M42();
        case 35:
            return new M34::M35();
        case 36:
            return new M34::M36();
        case 37:
            return new M34::M37();
        case 38:
            return new M34::M37::M38();
        case 39:
            return new M34::M37::M38::M39();
        case 40:
            return new M34::M37::M38::M39::M40();
        case 41:
            return new M34::M37::M38::M39::M40::M41();
        case 43:
            return new M43();
        case 48:
            return new M43::M48();
        case 50:
            return new M43::M48::M50();
        case 51:
            return new M43::M48::M50::M51();
        case 52:
            return new M43::M48::M50::M51::M52();
        case 53:
            return new M43::M48::M50::M51::M52::M53();
        case 49:
            return new M43::M48::M49();
        case 44:
            return new M43::M44();
        case 45:
            return new M43::M44::M45();
        case 46:
            return new M43::M44::M46();
        case 47:
            return new M43::M44::M47();
        case 54:
            return new M54();
        case 55:
            return new M54::M55();
        case 56:
            return new M54::M55::M56();
        case 57:
            return new M54::M55::M56::M57();
        case 58:
            return new M54::M55::M56::M57::M58();
        case 59:
            return new M54::M59();
        case 60:
            return new M54::M59::M60();
        case 62:
            return new M54::M62();
        case 63:
            return new M54::M62::M63();
        case 61:
            return new M54::M61();
        case 64:
            return new M64();
        case 66:
            return new M64::M66();
        case 67:
            return new M64::M67();
        case 65:
            return new M64::M65();
        case 68:
            return new M64::M68();
        case 69:
            return new M64::M68::M69();
        case 70:
            return new M64::M68::M69::M70();
        case 71:
            return new M64::M68::M69::M70::M71();
        case 72:
            return new M72();
        case 77:
            return new M72::M77();
        case 78:
            return new M72::M78();
        case 79:
            return new M72::M78::M79();
        case 80:
            return new M72::M78::M79::M80();
        case 81:
            return new M72::M78::M79::M80::M81();
        case 73:
            return new M72::M73();
        case 75:
            return new M72::M73::M75();
        case 74:
            return new M72::M73::M74();
        case 76:
            return new M72::M76();
        case 82:
            return new M82();
        case 84:
            return new M82::M84();
        case 85:
            return new M82::M84::M85();
        case 86:
            return new M82::M84::M85::M86();
        case 87:
            return new M82::M84::M85::M86::M87();
        case 88:
            return new M82::M88();
        case 89:
            return new M82::M88::M89();
        case 90:
            return new M82::M90();
        case 91:
            return new M82::M90::M91();
        case 83:
            return new M82::M83();
        case 92:
            return new M92();
        case 94:
            return new M92::M94();
        case 95:
            return new M92::M94::M95();
        case 93:
            return new M92::M93();
        default:
            throw std::invalid_argument("Invalid class id");
    }
}

size_t getMessageSize(int temp_class_id) {
    switch (temp_class_id) {
        case 12:
            return sizeof(M12);
        case 13:
            return sizeof(M12::M13);
        case 14:
            return sizeof(M12::M13::M14);
        case 15:
            return sizeof(M12::M13::M14::M15);
        case 17:
            return sizeof(M12::M17);
        case 18:
            return sizeof(M12::M17::M18);
        case 19:
            return sizeof(M12::M17::M18::M19);
        case 20:
            return sizeof(M12::M17::M18::M19::M20);
        case 21:
            return sizeof(M12::M17::M18::M19::M20::M21);
        case 22:
            return sizeof(M12::M17::M22);
        case 16:
            return sizeof(M12::M16);
        case 1:
            return sizeof(M1);
        case 2:
            return sizeof(M1::M2);
        case 4:
            return sizeof(M1::M2::M4);
        case 5:
            return sizeof(M1::M2::M4::M5);
        case 3:
            return sizeof(M1::M2::M3);
        case 6:
            return sizeof(M1::M6);
        case 9:
            return sizeof(M1::M6::M9);
        case 10:
            return sizeof(M1::M6::M9::M10);
        case 11:
            return sizeof(M1::M6::M9::M10::M11);
        case 8:
            return sizeof(M1::M6::M8);
        case 7:
            return sizeof(M1::M6::M7);
        case 23:
            return sizeof(M23);
        case 29:
            return sizeof(M23::M29);
        case 33:
            return sizeof(M23::M29::M33);
        case 30:
            return sizeof(M23::M29::M30);
        case 31:
            return sizeof(M23::M29::M30::M31);
        case 32:
            return sizeof(M23::M29::M30::M31::M32);
        case 24:
            return sizeof(M23::M24);
        case 26:
            return sizeof(M23::M24::M26);
        case 27:
            return sizeof(M23::M24::M27);
        case 25:
            return sizeof(M23::M24::M25);
        case 28:
            return sizeof(M23::M28);
        case 34:
            return sizeof(M34);
        case 42:
            return sizeof(M34::M42);
        case 35:
            return sizeof(M34::M35);
        case 36:
            return sizeof(M34::M36);
        case 37:
            return sizeof(M34::M37);
        case 38:
            return sizeof(M34::M37::M38);
        case 39:
            return sizeof(M34::M37::M38::M39);
        case 40:
            return sizeof(M34::M37::M38::M39::M40);
        case 41:
            return sizeof(M34::M37::M38::M39::M40::M41);
        case 43:
            return sizeof(M43);
        case 48:
            return sizeof(M43::M48);
        case 50:
            return sizeof(M43::M48::M50);
        case 51:
            return sizeof(M43::M48::M50::M51);
        case 52:
            return sizeof(M43::M48::M50::M51::M52);
        case 53:
            return sizeof(M43::M48::M50::M51::M52::M53);
        case 49:
            return sizeof(M43::M48::M49);
        case 44:
            return sizeof(M43::M44);
        case 45:
            return sizeof(M43::M44::M45);
        case 46:
            return sizeof(M43::M44::M46);
        case 47:
            return sizeof(M43::M44::M47);
        case 54:
            return sizeof(M54);
        case 55:
            return sizeof(M54::M55);
        case 56:
            return sizeof(M54::M55::M56);
        case 57:
            return sizeof(M54::M55::M56::M57);
        case 58:
            return sizeof(M54::M55::M56::M57::M58);
        case 59:
            return sizeof(M54::M59);
        case 60:
            return sizeof(M54::M59::M60);
        case 62:
            return sizeof(M54::M62);
        case 63:
            return sizeof(M54::M62::M63);
        case 61:
            return sizeof(M54::M61);
        case 64:
            return sizeof(M64);
        case 66:
            return sizeof(M64::M66);
        case 67:
            return sizeof(M64::M67);
        case 65:
            return sizeof(M64::M65);
        case 68:
            return sizeof(M64::M68);
        case 69:
            return sizeof(M64::M68::M69);
        case 70:
            return sizeof(M64::M68::M69::M70);
        case 71:
            return sizeof(M64::M68::M69::M70::M71);
        case 72:
            return sizeof(M72);
        case 77:
            return sizeof(M72::M77);
        case 78:
            return sizeof(M72::M78);
        case 79:
            return sizeof(M72::M78::M79);
        case 80:
            return sizeof(M72::M78::M79::M80);
        case 81:
            return sizeof(M72::M78::M79::M80::M81);
        case 73:
            return sizeof(M72::M73);
        case 75:
            return sizeof(M72::M73::M75);
        case 74:
            return sizeof(M72::M73::M74);
        case 76:
            return sizeof(M72::M76);
        case 82:
            return sizeof(M82);
        case 84:
            return sizeof(M82::M84);
        case 85:
            return sizeof(M82::M84::M85);
        case 86:
            return sizeof(M82::M84::M85::M86);
        case 87:
            return sizeof(M82::M84::M85::M86::M87);
        case 88:
            return sizeof(M82::M88);
        case 89:
            return sizeof(M82::M88::M89);
        case 90:
            return sizeof(M82::M90);
        case 91:
            return sizeof(M82::M90::M91);
        case 83:
            return sizeof(M82::M83);
        case 92:
            return sizeof(M92);
        case 94:
            return sizeof(M92::M94);
        case 95:
            return sizeof(M92::M94::M95);
        case 93:
            return sizeof(M92::M93);
        default:
            return 0;
    }
}
