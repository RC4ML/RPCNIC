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
        E1_CONST_1 = 84,
        E1_CONST_2 = 20,
        E1_CONST_3 = 85,
        E1_CONST_4 = 118,
        E1_CONST_5 = 119,
    };
    
    enum E2 {
        E2_CONST_1 = 69,
        E2_CONST_2 = 76,
        E2_CONST_3 = 80,
        E2_CONST_4 = 115,
        E2_CONST_5 = 27,
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
    
        inline void add_f2(uint32_t val){
            f2.push_back(val);
        }
        inline uint32_t& get_f2(int idx){
            return f2[idx];
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M2->f1: " << f1 << std::endl;
            for(auto &f2_val : f2){
                fout << "M2->f2: " << f2_val << std::endl;
            }
        }
    
        ~M2(){
        }
    
        M2(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) std::vector<uint32_t> f2;
    };


    class alignas(8) M3 : public M_base
    {
    public:
        class alignas(8) M4 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 98,
                E1_CONST_2 = 77,
                E1_CONST_3 = 53,
                E1_CONST_4 = 119,
                E1_CONST_5 = 124,
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


                inline M6* mutable_f1(){
                    f1 = new M6();
                    return f1;
                }
                inline M6*& get_f1(){
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
                    if(f1 != nullptr)
                        f1->print_message(fout);
                    fout << "M5->f2: " << f2 << std::endl;
                    fout << "M5->f3: " << f3 << std::endl;
                }
            
                ~M5(){
                    if(f1 != nullptr)
                        delete f1;
                }
            
                M5(){
                   f1 = nullptr;
                }
            
            private:
                alignas(8) M6* f1;
                alignas(8) int32_t f2;
                alignas(8) int32_t f3;
            };


            class alignas(8) M7 : public M_base
            {
            public:
                inline void set_f1(bool val){
                    f1 = val;
                }
                inline bool& get_f1(){
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
                alignas(8) bool f1;
            };


            inline M5* mutable_f1(){
                f1 = new M5();
                return f1;
            }
            inline M5*& get_f1(){
                return f1;
            }
        
            inline M7* mutable_f2(){
                f2 = new M7();
                return f2;
            }
            inline M7*& get_f2(){
                return f2;
            }
        
            inline void set_f3(E1 val){
                f3 = val;
            }
            inline E1& get_f3(){
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
            alignas(8) M7* f2;
            alignas(8) E1 f3;
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
                    fout << "M9->f1: " << f1 << std::endl;
                    fout << "M9->f2: " << f2 << std::endl;
                    fout << "M9->f3: " << f3 << std::endl;
                }
            
                ~M9(){
                }
            
                M9(){
                }
            
            private:
                alignas(8) string f1;
                alignas(8) bool f2;
                alignas(8) int32_t f3;
            };


            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
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
            alignas(8) int32_t f1;
            alignas(8) M9* f2;
        };


        inline void set_f1(uint32_t val){
            f1 = val;
        }
        inline uint32_t& get_f1(){
            return f1;
        }
    
        inline M4* mutable_f2(){
            f2 = new M4();
            return f2;
        }
        inline M4*& get_f2(){
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
            fout << "M3->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M3(){
            if(f2 != nullptr)
                delete f2;
            if(f3 != nullptr)
                delete f3;
        }
    
        M3(){
           f2 = nullptr;
           f3 = nullptr;
        }
    
    private:
        alignas(8) uint32_t f1;
        alignas(8) M4* f2;
        alignas(8) M8* f3;
    };


    class alignas(8) M10 : public M_base
    {
    public:
        class alignas(8) M11 : public M_base
        {
        public:
            inline void set_f1(int64_t val){
                f1 = val;
            }
            inline int64_t& get_f1(){
                return f1;
            }
        
            inline void set_f2(uint32_t val){
                f2 = val;
            }
            inline uint32_t& get_f2(){
                return f2;
            }
        
            inline void set_f3(uint32_t val){
                f3 = val;
            }
            inline uint32_t& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M11->f1: " << f1 << std::endl;
                fout << "M11->f2: " << f2 << std::endl;
                fout << "M11->f3: " << f3 << std::endl;
            }
        
            ~M11(){
            }
        
            M11(){
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) uint32_t f2;
            alignas(8) uint32_t f3;
        };


        class alignas(8) M12 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 8,
                E1_CONST_2 = 104,
                E1_CONST_3 = 108,
                E1_CONST_4 = 110,
                E1_CONST_5 = 123,
            };
            
            class alignas(8) M13 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 98,
                    E1_CONST_2 = 68,
                    E1_CONST_3 = 106,
                    E1_CONST_4 = 13,
                    E1_CONST_5 = 28,
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
            
                inline void set_f3(E1 val){
                    f3 = val;
                }
                inline E1& get_f3(){
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
                alignas(8) int64_t f1;
                alignas(8) string f2;
                alignas(8) E1 f3;
            };


            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline M13* mutable_f2(){
                f2 = new M13();
                return f2;
            }
            inline M13*& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M12->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
            }
        
            ~M12(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M12(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) E1 f1;
            alignas(8) M13* f2;
        };


        class alignas(8) M14 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 73,
                E1_CONST_2 = 9,
                E1_CONST_3 = 110,
                E1_CONST_4 = 51,
                E1_CONST_5 = 21,
            };
            
            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
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
            alignas(8) E1 f1;
        };


        inline M11* mutable_f1(){
            f1 = new M11();
            return f1;
        }
        inline M11*& get_f1(){
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
    
        inline M12* mutable_f4(){
            f4 = new M12();
            return f4;
        }
        inline M12*& get_f4(){
            return f4;
        }
    
        inline void set_f5(uint32_t val){
            f5 = val;
        }
        inline uint32_t& get_f5(){
            return f5;
        }
    
        inline void set_f6(uint32_t val){
            f6 = val;
        }
        inline uint32_t& get_f6(){
            return f6;
        }
    
        inline void set_f7(int32_t val){
            f7 = val;
        }
        inline int32_t& get_f7(){
            return f7;
        }
    
        inline M14* mutable_f8(){
            f8 = new M14();
            return f8;
        }
        inline M14*& get_f8(){
            return f8;
        }
    
        inline void set_f9(int64_t val){
            f9 = val;
        }
        inline int64_t& get_f9(){
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
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M10->f2: " << f2 << std::endl;
            fout << "M10->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
            fout << "M10->f5: " << f5 << std::endl;
            fout << "M10->f6: " << f6 << std::endl;
            fout << "M10->f7: " << f7 << std::endl;
            if(f8 != nullptr)
                f8->print_message(fout);
            fout << "M10->f9: " << f9 << std::endl;
            fout << "M10->f10: " << f10 << std::endl;
            fout << "M10->f11: " << f11 << std::endl;
        }
    
        ~M10(){
            if(f1 != nullptr)
                delete f1;
            if(f4 != nullptr)
                delete f4;
            if(f8 != nullptr)
                delete f8;
        }
    
        M10(){
           f1 = nullptr;
           f4 = nullptr;
           f8 = nullptr;
        }
    
    private:
        alignas(8) M11* f1;
        alignas(8) int32_t f2;
        alignas(8) int32_t f3;
        alignas(8) M12* f4;
        alignas(8) uint32_t f5;
        alignas(8) uint32_t f6;
        alignas(8) int32_t f7;
        alignas(8) M14* f8;
        alignas(8) int64_t f9;
        alignas(8) int32_t f10;
        alignas(8) int64_t f11;
    };


    class alignas(8) M15 : public M_base
    {
    public:
        class alignas(8) M16 : public M_base
        {
        public:
            class alignas(8) M17 : public M_base
            {
            public:
                class alignas(8) M18 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 38,
                        E1_CONST_2 = 72,
                        E1_CONST_3 = 9,
                        E1_CONST_4 = 76,
                        E1_CONST_5 = 47,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 96,
                        E2_CONST_2 = 67,
                        E2_CONST_3 = 42,
                        E2_CONST_4 = 44,
                        E2_CONST_5 = 120,
                    };
                    
                    class alignas(8) M19 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 36,
                            E1_CONST_2 = 4,
                            E1_CONST_3 = 78,
                            E1_CONST_4 = 79,
                            E1_CONST_5 = 83,
                        };
                        
                        enum E2 {
                            E2_CONST_1 = 67,
                            E2_CONST_2 = 103,
                            E2_CONST_3 = 109,
                            E2_CONST_4 = 83,
                            E2_CONST_5 = 88,
                        };
                        
                        enum E3 {
                            E3_CONST_1 = 100,
                            E3_CONST_2 = 39,
                            E3_CONST_3 = 108,
                            E3_CONST_4 = 109,
                            E3_CONST_5 = 86,
                        };
                        
                        class alignas(8) M20 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 43,
                                E1_CONST_2 = 46,
                                E1_CONST_3 = 21,
                                E1_CONST_4 = 55,
                                E1_CONST_5 = 29,
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
                        
                            inline void set_f4(string val){
                                f4 = val;
                            }
                            inline string& get_f4(){
                                return f4;
                            }
                        
                            inline void set_f5(uint32_t val){
                                f5 = val;
                            }
                            inline uint32_t& get_f5(){
                                return f5;
                            }
                        
                            inline void set_f6(int64_t val){
                                f6 = val;
                            }
                            inline int64_t& get_f6(){
                                return f6;
                            }
                        
                            inline void set_f7(E1 val){
                                f7 = val;
                            }
                            inline E1& get_f7(){
                                return f7;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M20->f1: " << f1 << std::endl;
                                fout << "M20->f2: " << f2 << std::endl;
                                fout << "M20->f3: " << f3 << std::endl;
                                fout << "M20->f4: " << f4 << std::endl;
                                fout << "M20->f5: " << f5 << std::endl;
                                fout << "M20->f6: " << f6 << std::endl;
                                fout << "M20->f7: " << f7 << std::endl;
                            }
                        
                            ~M20(){
                            }
                        
                            M20(){
                            }
                        
                        private:
                            alignas(8) int32_t f1;
                            alignas(8) int32_t f2;
                            alignas(8) int32_t f3;
                            alignas(8) string f4;
                            alignas(8) uint32_t f5;
                            alignas(8) int64_t f6;
                            alignas(8) E1 f7;
                        };


                        class alignas(8) M21 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 32,
                                E1_CONST_2 = 51,
                                E1_CONST_3 = 21,
                                E1_CONST_4 = 57,
                                E1_CONST_5 = 95,
                            };
                            
                            inline void set_f1(E1 val){
                                f1 = val;
                            }
                            inline E1& get_f1(){
                                return f1;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M21->f1: " << f1 << std::endl;
                            }
                        
                            ~M21(){
                            }
                        
                            M21(){
                            }
                        
                        private:
                            alignas(8) E1 f1;
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
                    
                        inline void set_f3(int32_t val){
                            f3 = val;
                        }
                        inline int32_t& get_f3(){
                            return f3;
                        }
                    
                        inline M20* mutable_f4(){
                            f4 = new M20();
                            return f4;
                        }
                        inline M20*& get_f4(){
                            return f4;
                        }
                    
                        inline M21* mutable_f5(){
                            f5 = new M21();
                            return f5;
                        }
                        inline M21*& get_f5(){
                            return f5;
                        }
                    
                        inline void set_f6(E2 val){
                            f6 = val;
                        }
                        inline E2& get_f6(){
                            return f6;
                        }
                    
                        inline void set_f7(uint32_t val){
                            f7 = val;
                        }
                        inline uint32_t& get_f7(){
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
                    
                        inline void set_f10(E3 val){
                            f10 = val;
                        }
                        inline E3& get_f10(){
                            return f10;
                        }
                    
                        inline void set_f11(string val){
                            f11 = val;
                        }
                        inline string& get_f11(){
                            return f11;
                        }
                    
                        inline void set_f12(int64_t val){
                            f12 = val;
                        }
                        inline int64_t& get_f12(){
                            return f12;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M19->f1: " << f1 << std::endl;
                            fout << "M19->f2: " << f2 << std::endl;
                            fout << "M19->f3: " << f3 << std::endl;
                            if(f4 != nullptr)
                                f4->print_message(fout);
                            if(f5 != nullptr)
                                f5->print_message(fout);
                            fout << "M19->f6: " << f6 << std::endl;
                            fout << "M19->f7: " << f7 << std::endl;
                            fout << "M19->f8: " << f8 << std::endl;
                            fout << "M19->f9: " << f9 << std::endl;
                            fout << "M19->f10: " << f10 << std::endl;
                            fout << "M19->f11: " << f11 << std::endl;
                            fout << "M19->f12: " << f12 << std::endl;
                        }
                    
                        ~M19(){
                            if(f4 != nullptr)
                                delete f4;
                            if(f5 != nullptr)
                                delete f5;
                        }
                    
                        M19(){
                           f4 = nullptr;
                           f5 = nullptr;
                        }
                    
                    private:
                        alignas(8) E1 f1;
                        alignas(8) float f2;
                        alignas(8) int32_t f3;
                        alignas(8) M20* f4;
                        alignas(8) M21* f5;
                        alignas(8) E2 f6;
                        alignas(8) uint32_t f7;
                        alignas(8) int32_t f8;
                        alignas(8) int32_t f9;
                        alignas(8) E3 f10;
                        alignas(8) string f11;
                        alignas(8) int64_t f12;
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
                
                    inline void set_f6(E1 val){
                        f6 = val;
                    }
                    inline E1& get_f6(){
                        return f6;
                    }
                
                    inline void set_f7(E2 val){
                        f7 = val;
                    }
                    inline E2& get_f7(){
                        return f7;
                    }
                
                    inline M19* mutable_f8(){
                        f8 = new M19();
                        return f8;
                    }
                    inline M19*& get_f8(){
                        return f8;
                    }
                
                    inline void set_f9(uint32_t val){
                        f9 = val;
                    }
                    inline uint32_t& get_f9(){
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
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M18->f1: " << f1 << std::endl;
                        fout << "M18->f2: " << f2 << std::endl;
                        fout << "M18->f3: " << f3 << std::endl;
                        fout << "M18->f4: " << f4 << std::endl;
                        fout << "M18->f5: " << f5 << std::endl;
                        fout << "M18->f6: " << f6 << std::endl;
                        fout << "M18->f7: " << f7 << std::endl;
                        if(f8 != nullptr)
                            f8->print_message(fout);
                        fout << "M18->f9: " << f9 << std::endl;
                        fout << "M18->f10: " << f10 << std::endl;
                        fout << "M18->f11: " << f11 << std::endl;
                    }
                
                    ~M18(){
                        if(f8 != nullptr)
                            delete f8;
                    }
                
                    M18(){
                       f8 = nullptr;
                    }
                
                private:
                    alignas(8) bool f1;
                    alignas(8) int32_t f2;
                    alignas(8) int32_t f3;
                    alignas(8) int64_t f4;
                    alignas(8) int64_t f5;
                    alignas(8) E1 f6;
                    alignas(8) E2 f7;
                    alignas(8) M19* f8;
                    alignas(8) uint32_t f9;
                    alignas(8) int32_t f10;
                    alignas(8) int32_t f11;
                };


                class alignas(8) M22 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 1,
                        E1_CONST_2 = 35,
                        E1_CONST_3 = 101,
                        E1_CONST_4 = 43,
                        E1_CONST_5 = 108,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 43,
                        E2_CONST_2 = 81,
                        E2_CONST_3 = 55,
                        E2_CONST_4 = 26,
                        E2_CONST_5 = 30,
                    };
                    
                    enum E3 {
                        E3_CONST_1 = 14,
                        E3_CONST_2 = 56,
                        E3_CONST_3 = 91,
                        E3_CONST_4 = 125,
                        E3_CONST_5 = 94,
                    };
                    
                    class alignas(8) M23 : public M_base
                    {
                    public:
                        class alignas(8) M24 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 99,
                                E1_CONST_2 = 40,
                                E1_CONST_3 = 104,
                                E1_CONST_4 = 19,
                                E1_CONST_5 = 93,
                            };
                            
                            enum E2 {
                                E2_CONST_1 = 74,
                                E2_CONST_2 = 45,
                                E2_CONST_3 = 14,
                                E2_CONST_4 = 15,
                                E2_CONST_5 = 55,
                            };
                            
                            class alignas(8) M25 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 67,
                                    E1_CONST_2 = 79,
                                    E1_CONST_3 = 18,
                                    E1_CONST_4 = 116,
                                    E1_CONST_5 = 2362,
                                };
                                
                                class alignas(8) M26 : public M_base
                                {
                                public:
                                    enum E1 {
                                        E1_CONST_1 = 101,
                                        E1_CONST_2 = 71,
                                        E1_CONST_3 = 40,
                                        E1_CONST_4 = 113,
                                        E1_CONST_5 = 21,
                                    };
                                    
                                    class alignas(8) M27 : public M_base
                                    {
                                    public:
                                        enum E1 {
                                            E1_CONST_1 = 0,
                                            E1_CONST_2 = 64,
                                            E1_CONST_3 = 66,
                                            E1_CONST_4 = 102,
                                            E1_CONST_5 = 118,
                                        };
                                        
                                        enum E2 {
                                            E2_CONST_1 = 97,
                                            E2_CONST_2 = 34,
                                            E2_CONST_3 = 84,
                                            E2_CONST_4 = 88,
                                            E2_CONST_5 = 123,
                                        };
                                        
                                        enum E3 {
                                            E3_CONST_1 = 96,
                                            E3_CONST_2 = 75,
                                            E3_CONST_3 = 112,
                                            E3_CONST_4 = 91,
                                            E3_CONST_5 = 126,
                                        };
                                        
                                        class alignas(8) M28 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 3,
                                                E1_CONST_2 = 70,
                                                E1_CONST_3 = 39,
                                                E1_CONST_4 = 11,
                                                E1_CONST_5 = 93,
                                            };
                                            
                                            enum E2 {
                                                E2_CONST_1 = 69,
                                                E2_CONST_2 = 43,
                                                E2_CONST_3 = 47,
                                                E2_CONST_4 = 81,
                                                E2_CONST_5 = 60,
                                            };
                                            
                                            enum E3 {
                                                E3_CONST_1 = 102,
                                                E3_CONST_2 = 114,
                                                E3_CONST_3 = 21,
                                                E3_CONST_4 = 122,
                                                E3_CONST_5 = 63,
                                            };
                                            
                                            class alignas(8) M29 : public M_base
                                            {
                                            public:
                                                enum E1 {
                                                    E1_CONST_1 = 41,
                                                    E1_CONST_2 = 13,
                                                    E1_CONST_3 = 15,
                                                    E1_CONST_4 = 115,
                                                    E1_CONST_5 = 25,
                                                };
                                                
                                                class alignas(8) M30 : public M_base
                                                {
                                                public:
                                                    enum E1 {
                                                        E1_CONST_1 = 74,
                                                        E1_CONST_2 = 107,
                                                        E1_CONST_3 = 108,
                                                        E1_CONST_4 = 118,
                                                        E1_CONST_5 = 22,
                                                    };
                                                    
                                                    class alignas(8) M31 : public M_base
                                                    {
                                                    public:
                                                        inline void set_f1(int32_t val){
                                                            f1 = val;
                                                        }
                                                        inline int32_t& get_f1(){
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
                                                        alignas(8) int32_t f1;
                                                    };


                                                    class alignas(8) M32 : public M_base
                                                    {
                                                    public:
                                                        enum E1 {
                                                            E1_CONST_1 = 3,
                                                            E1_CONST_2 = 103,
                                                            E1_CONST_3 = 49,
                                                            E1_CONST_4 = 113,
                                                            E1_CONST_5 = 83,
                                                        };
                                                        
                                                        enum E2 {
                                                            E2_CONST_1 = 4,
                                                            E2_CONST_2 = 38,
                                                            E2_CONST_3 = 6,
                                                            E2_CONST_4 = 9,
                                                            E2_CONST_5 = 23,
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
                                                    
                                                        inline void set_f3(int64_t val){
                                                            f3 = val;
                                                        }
                                                        inline int64_t& get_f3(){
                                                            return f3;
                                                        }
                                                    
                                                        inline void set_f4(E1 val){
                                                            f4 = val;
                                                        }
                                                        inline E1& get_f4(){
                                                            return f4;
                                                        }
                                                    
                                                        inline void set_f5(int32_t val){
                                                            f5 = val;
                                                        }
                                                        inline int32_t& get_f5(){
                                                            return f5;
                                                        }
                                                    
                                                        inline void set_f6(E2 val){
                                                            f6 = val;
                                                        }
                                                        inline E2& get_f6(){
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
                                                    
                                                        inline void set_f9(int64_t val){
                                                            f9 = val;
                                                        }
                                                        inline int64_t& get_f9(){
                                                            return f9;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M32->f1: " << f1 << std::endl;
                                                            fout << "M32->f2: " << f2 << std::endl;
                                                            fout << "M32->f3: " << f3 << std::endl;
                                                            fout << "M32->f4: " << f4 << std::endl;
                                                            fout << "M32->f5: " << f5 << std::endl;
                                                            fout << "M32->f6: " << f6 << std::endl;
                                                            fout << "M32->f7: " << f7 << std::endl;
                                                            fout << "M32->f8: " << f8 << std::endl;
                                                            fout << "M32->f9: " << f9 << std::endl;
                                                        }
                                                    
                                                        ~M32(){
                                                        }
                                                    
                                                        M32(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) int32_t f1;
                                                        alignas(8) bool f2;
                                                        alignas(8) int64_t f3;
                                                        alignas(8) E1 f4;
                                                        alignas(8) int32_t f5;
                                                        alignas(8) E2 f6;
                                                        alignas(8) int32_t f7;
                                                        alignas(8) int32_t f8;
                                                        alignas(8) int64_t f9;
                                                    };


                                                    inline void set_f1(E1 val){
                                                        f1 = val;
                                                    }
                                                    inline E1& get_f1(){
                                                        return f1;
                                                    }
                                                
                                                    inline M31* mutable_f2(){
                                                        f2 = new M31();
                                                        return f2;
                                                    }
                                                    inline M31*& get_f2(){
                                                        return f2;
                                                    }
                                                
                                                    inline M32* mutable_f3(){
                                                        f3 = new M32();
                                                        return f3;
                                                    }
                                                    inline M32*& get_f3(){
                                                        return f3;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M30->f1: " << f1 << std::endl;
                                                        if(f2 != nullptr)
                                                            f2->print_message(fout);
                                                        if(f3 != nullptr)
                                                            f3->print_message(fout);
                                                    }
                                                
                                                    ~M30(){
                                                        if(f2 != nullptr)
                                                            delete f2;
                                                        if(f3 != nullptr)
                                                            delete f3;
                                                    }
                                                
                                                    M30(){
                                                       f2 = nullptr;
                                                       f3 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) E1 f1;
                                                    alignas(8) M31* f2;
                                                    alignas(8) M32* f3;
                                                };


                                                class alignas(8) M33 : public M_base
                                                {
                                                public:
                                                    inline void set_f1(float val){
                                                        f1 = val;
                                                    }
                                                    inline float& get_f1(){
                                                        return f1;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M33->f1: " << f1 << std::endl;
                                                    }
                                                
                                                    ~M33(){
                                                    }
                                                
                                                    M33(){
                                                    }
                                                
                                                private:
                                                    alignas(8) float f1;
                                                };


                                                inline M30* mutable_f1(){
                                                    f1 = new M30();
                                                    return f1;
                                                }
                                                inline M30*& get_f1(){
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
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    if(f1 != nullptr)
                                                        f1->print_message(fout);
                                                    if(f2 != nullptr)
                                                        f2->print_message(fout);
                                                    fout << "M29->f3: " << f3 << std::endl;
                                                    fout << "M29->f4: " << f4 << std::endl;
                                                }
                                            
                                                ~M29(){
                                                    if(f1 != nullptr)
                                                        delete f1;
                                                    if(f2 != nullptr)
                                                        delete f2;
                                                }
                                            
                                                M29(){
                                                   f1 = nullptr;
                                                   f2 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) M30* f1;
                                                alignas(8) M33* f2;
                                                alignas(8) E1 f3;
                                                alignas(8) int64_t f4;
                                            };


                                            inline void set_f1(float val){
                                                f1 = val;
                                            }
                                            inline float& get_f1(){
                                                return f1;
                                            }
                                        
                                            inline M29* mutable_f2(){
                                                f2 = new M29();
                                                return f2;
                                            }
                                            inline M29*& get_f2(){
                                                return f2;
                                            }
                                        
                                            inline void set_f3(E1 val){
                                                f3 = val;
                                            }
                                            inline E1& get_f3(){
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
                                        
                                            inline void set_f6(E2 val){
                                                f6 = val;
                                            }
                                            inline E2& get_f6(){
                                                return f6;
                                            }
                                        
                                            inline void set_f7(float val){
                                                f7 = val;
                                            }
                                            inline float& get_f7(){
                                                return f7;
                                            }
                                        
                                            inline void set_f8(E3 val){
                                                f8 = val;
                                            }
                                            inline E3& get_f8(){
                                                return f8;
                                            }
                                        
                                            inline void add_f9(float val){
                                                f9.push_back(val);
                                            }
                                            inline float& get_f9(int idx){
                                                return f9[idx];
                                            }
                                        
                                            inline void set_f10(string val){
                                                f10 = val;
                                            }
                                            inline string& get_f10(){
                                                return f10;
                                            }
                                        
                                            inline void set_f11(float val){
                                                f11 = val;
                                            }
                                            inline float& get_f11(){
                                                return f11;
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
                                                for(auto &f9_val : f9){
                                                    fout << "M28->f9: " << f9_val << std::endl;
                                                }
                                                fout << "M28->f10: " << f10 << std::endl;
                                                fout << "M28->f11: " << f11 << std::endl;
                                            }
                                        
                                            ~M28(){
                                                if(f2 != nullptr)
                                                    delete f2;
                                            }
                                        
                                            M28(){
                                               f2 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) float f1;
                                            alignas(8) M29* f2;
                                            alignas(8) E1 f3;
                                            alignas(8) float f4;
                                            alignas(8) string f5;
                                            alignas(8) E2 f6;
                                            alignas(8) float f7;
                                            alignas(8) E3 f8;
                                            alignas(8) std::vector<float> f9;
                                            alignas(8) string f10;
                                            alignas(8) float f11;
                                        };


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
                                    
                                        inline void set_f3(bool val){
                                            f3 = val;
                                        }
                                        inline bool& get_f3(){
                                            return f3;
                                        }
                                    
                                        inline M28* mutable_f4(){
                                            f4 = new M28();
                                            return f4;
                                        }
                                        inline M28*& get_f4(){
                                            return f4;
                                        }
                                    
                                        inline void set_f5(uint32_t val){
                                            f5 = val;
                                        }
                                        inline uint32_t& get_f5(){
                                            return f5;
                                        }
                                    
                                        inline void set_f6(uint32_t val){
                                            f6 = val;
                                        }
                                        inline uint32_t& get_f6(){
                                            return f6;
                                        }
                                    
                                        inline void set_f7(int32_t val){
                                            f7 = val;
                                        }
                                        inline int32_t& get_f7(){
                                            return f7;
                                        }
                                    
                                        inline void set_f8(bool val){
                                            f8 = val;
                                        }
                                        inline bool& get_f8(){
                                            return f8;
                                        }
                                    
                                        inline void set_f9(E1 val){
                                            f9 = val;
                                        }
                                        inline E1& get_f9(){
                                            return f9;
                                        }
                                    
                                        inline void set_f10(E2 val){
                                            f10 = val;
                                        }
                                        inline E2& get_f10(){
                                            return f10;
                                        }
                                    
                                        inline void set_f11(E3 val){
                                            f11 = val;
                                        }
                                        inline E3& get_f11(){
                                            return f11;
                                        }
                                    
                                        inline void print_message(std::ofstream &fout){
                                            fout << "M27->f1: " << f1 << std::endl;
                                            fout << "M27->f2: " << f2 << std::endl;
                                            fout << "M27->f3: " << f3 << std::endl;
                                            if(f4 != nullptr)
                                                f4->print_message(fout);
                                            fout << "M27->f5: " << f5 << std::endl;
                                            fout << "M27->f6: " << f6 << std::endl;
                                            fout << "M27->f7: " << f7 << std::endl;
                                            fout << "M27->f8: " << f8 << std::endl;
                                            fout << "M27->f9: " << f9 << std::endl;
                                            fout << "M27->f10: " << f10 << std::endl;
                                            fout << "M27->f11: " << f11 << std::endl;
                                        }
                                    
                                        ~M27(){
                                            if(f4 != nullptr)
                                                delete f4;
                                        }
                                    
                                        M27(){
                                           f4 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) bool f1;
                                        alignas(8) bool f2;
                                        alignas(8) bool f3;
                                        alignas(8) M28* f4;
                                        alignas(8) uint32_t f5;
                                        alignas(8) uint32_t f6;
                                        alignas(8) int32_t f7;
                                        alignas(8) bool f8;
                                        alignas(8) E1 f9;
                                        alignas(8) E2 f10;
                                        alignas(8) E3 f11;
                                    };


                                    inline void set_f1(E1 val){
                                        f1 = val;
                                    }
                                    inline E1& get_f1(){
                                        return f1;
                                    }
                                
                                    inline M27* mutable_f2(){
                                        f2 = new M27();
                                        return f2;
                                    }
                                    inline M27*& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void set_f3(float val){
                                        f3 = val;
                                    }
                                    inline float& get_f3(){
                                        return f3;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M26->f1: " << f1 << std::endl;
                                        if(f2 != nullptr)
                                            f2->print_message(fout);
                                        fout << "M26->f3: " << f3 << std::endl;
                                    }
                                
                                    ~M26(){
                                        if(f2 != nullptr)
                                            delete f2;
                                    }
                                
                                    M26(){
                                       f2 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) E1 f1;
                                    alignas(8) M27* f2;
                                    alignas(8) float f3;
                                };


                                inline M26* mutable_f1(){
                                    f1 = new M26();
                                    return f1;
                                }
                                inline M26*& get_f1(){
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
                            
                                inline void set_f4(bool val){
                                    f4 = val;
                                }
                                inline bool& get_f4(){
                                    return f4;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    if(f1 != nullptr)
                                        f1->print_message(fout);
                                    fout << "M25->f2: " << f2 << std::endl;
                                    fout << "M25->f3: " << f3 << std::endl;
                                    fout << "M25->f4: " << f4 << std::endl;
                                }
                            
                                ~M25(){
                                    if(f1 != nullptr)
                                        delete f1;
                                }
                            
                                M25(){
                                   f1 = nullptr;
                                }
                            
                            private:
                                alignas(8) M26* f1;
                                alignas(8) E1 f2;
                                alignas(8) int32_t f3;
                                alignas(8) bool f4;
                            };


                            inline void set_f1(E1 val){
                                f1 = val;
                            }
                            inline E1& get_f1(){
                                return f1;
                            }
                        
                            inline void set_f2(E2 val){
                                f2 = val;
                            }
                            inline E2& get_f2(){
                                return f2;
                            }
                        
                            inline M25* mutable_f3(){
                                f3 = new M25();
                                return f3;
                            }
                            inline M25*& get_f3(){
                                return f3;
                            }
                        
                            inline void add_f4(string val){
                                f4.push_back(val);
                            }
                            inline string& get_f4(int idx){
                                return f4[idx];
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M24->f1: " << f1 << std::endl;
                                fout << "M24->f2: " << f2 << std::endl;
                                if(f3 != nullptr)
                                    f3->print_message(fout);
                                for(auto &f4_val : f4){
                                    fout << "M24->f4: " << f4_val << std::endl;
                                }
                            }
                        
                            ~M24(){
                                if(f3 != nullptr)
                                    delete f3;
                            }
                        
                            M24(){
                               f3 = nullptr;
                            }
                        
                        private:
                            alignas(8) E1 f1;
                            alignas(8) E2 f2;
                            alignas(8) M25* f3;
                            alignas(8) std::vector<string> f4;
                        };


                        inline void set_f1(uint32_t val){
                            f1 = val;
                        }
                        inline uint32_t& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(int64_t val){
                            f2 = val;
                        }
                        inline int64_t& get_f2(){
                            return f2;
                        }
                    
                        inline M24* mutable_f3(){
                            f3 = new M24();
                            return f3;
                        }
                        inline M24*& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M23->f1: " << f1 << std::endl;
                            fout << "M23->f2: " << f2 << std::endl;
                            if(f3 != nullptr)
                                f3->print_message(fout);
                        }
                    
                        ~M23(){
                            if(f3 != nullptr)
                                delete f3;
                        }
                    
                        M23(){
                           f3 = nullptr;
                        }
                    
                    private:
                        alignas(8) uint32_t f1;
                        alignas(8) int64_t f2;
                        alignas(8) M24* f3;
                    };


                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline M23* mutable_f2(){
                        f2 = new M23();
                        return f2;
                    }
                    inline M23*& get_f2(){
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
                
                    inline void set_f5(E2 val){
                        f5 = val;
                    }
                    inline E2& get_f5(){
                        return f5;
                    }
                
                    inline void set_f6(uint32_t val){
                        f6 = val;
                    }
                    inline uint32_t& get_f6(){
                        return f6;
                    }
                
                    inline void set_f7(E3 val){
                        f7 = val;
                    }
                    inline E3& get_f7(){
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
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M22->f1: " << f1 << std::endl;
                        if(f2 != nullptr)
                            f2->print_message(fout);
                        fout << "M22->f3: " << f3 << std::endl;
                        fout << "M22->f4: " << f4 << std::endl;
                        fout << "M22->f5: " << f5 << std::endl;
                        fout << "M22->f6: " << f6 << std::endl;
                        fout << "M22->f7: " << f7 << std::endl;
                        fout << "M22->f8: " << f8 << std::endl;
                        fout << "M22->f9: " << f9 << std::endl;
                    }
                
                    ~M22(){
                        if(f2 != nullptr)
                            delete f2;
                    }
                
                    M22(){
                       f2 = nullptr;
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) M23* f2;
                    alignas(8) bool f3;
                    alignas(8) int32_t f4;
                    alignas(8) E2 f5;
                    alignas(8) uint32_t f6;
                    alignas(8) E3 f7;
                    alignas(8) int32_t f8;
                    alignas(8) int64_t f9;
                };


                inline void set_f1(int32_t val){
                    f1 = val;
                }
                inline int32_t& get_f1(){
                    return f1;
                }
            
                inline M18* mutable_f2(){
                    f2 = new M18();
                    return f2;
                }
                inline M18*& get_f2(){
                    return f2;
                }
            
                inline M22* mutable_f3(){
                    f3 = new M22();
                    return f3;
                }
                inline M22*& get_f3(){
                    return f3;
                }
            
                inline void set_f4(float val){
                    f4 = val;
                }
                inline float& get_f4(){
                    return f4;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M17->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    if(f3 != nullptr)
                        f3->print_message(fout);
                    fout << "M17->f4: " << f4 << std::endl;
                }
            
                ~M17(){
                    if(f2 != nullptr)
                        delete f2;
                    if(f3 != nullptr)
                        delete f3;
                }
            
                M17(){
                   f2 = nullptr;
                   f3 = nullptr;
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) M18* f2;
                alignas(8) M22* f3;
                alignas(8) float f4;
            };


            inline M17* mutable_f1(){
                f1 = new M17();
                return f1;
            }
            inline M17*& get_f1(){
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
                fout << "M16->f2: " << f2 << std::endl;
            }
        
            ~M16(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M16(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M17* f1;
            alignas(8) int32_t f2;
        };


        class alignas(8) M34 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 97,
                E1_CONST_2 = 99,
                E1_CONST_3 = 4,
                E1_CONST_4 = 17,
                E1_CONST_5 = 116,
            };
            
            enum E2 {
                E2_CONST_1 = 70,
                E2_CONST_2 = 73,
                E2_CONST_3 = 109,
                E2_CONST_4 = 87,
                E2_CONST_5 = 26,
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
        
            inline void set_f5(E2 val){
                f5 = val;
            }
            inline E2& get_f5(){
                return f5;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M34->f1: " << f1 << std::endl;
                fout << "M34->f2: " << f2 << std::endl;
                fout << "M34->f3: " << f3 << std::endl;
                fout << "M34->f4: " << f4 << std::endl;
                fout << "M34->f5: " << f5 << std::endl;
            }
        
            ~M34(){
            }
        
            M34(){
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int32_t f2;
            alignas(8) int32_t f3;
            alignas(8) E1 f4;
            alignas(8) E2 f5;
        };


        inline M16* mutable_f1(){
            f1 = new M16();
            return f1;
        }
        inline M16*& get_f1(){
            return f1;
        }
    
        inline M34* mutable_f2(){
            f2 = new M34();
            return f2;
        }
        inline M34*& get_f2(){
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
    
        inline void set_f5(bool val){
            f5 = val;
        }
        inline bool& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M15->f3: " << f3 << std::endl;
            fout << "M15->f4: " << f4 << std::endl;
            fout << "M15->f5: " << f5 << std::endl;
        }
    
        ~M15(){
            if(f1 != nullptr)
                delete f1;
            if(f2 != nullptr)
                delete f2;
        }
    
        M15(){
           f1 = nullptr;
           f2 = nullptr;
        }
    
    private:
        alignas(8) M16* f1;
        alignas(8) M34* f2;
        alignas(8) int64_t f3;
        alignas(8) int32_t f4;
        alignas(8) bool f5;
    };


    inline void set_f1(E1 val){
        f1 = val;
    }
    inline E1& get_f1(){
        return f1;
    }

    inline M2* mutable_f2(){
        f2 = new M2();
        return f2;
    }
    inline M2*& get_f2(){
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

    inline M3* mutable_f5(){
        f5 = new M3();
        return f5;
    }
    inline M3*& get_f5(){
        return f5;
    }

    inline M10* mutable_f6(){
        f6 = new M10();
        return f6;
    }
    inline M10*& get_f6(){
        return f6;
    }

    inline void set_f7(float val){
        f7 = val;
    }
    inline float& get_f7(){
        return f7;
    }

    inline M15* mutable_f8(){
        f8 = new M15();
        return f8;
    }
    inline M15*& get_f8(){
        return f8;
    }

    inline void set_f9(bool val){
        f9 = val;
    }
    inline bool& get_f9(){
        return f9;
    }

    inline void set_f10(float val){
        f10 = val;
    }
    inline float& get_f10(){
        return f10;
    }

    inline void set_f11(float val){
        f11 = val;
    }
    inline float& get_f11(){
        return f11;
    }

    inline void set_f12(int32_t val){
        f12 = val;
    }
    inline int32_t& get_f12(){
        return f12;
    }

    inline void set_f13(E2 val){
        f13 = val;
    }
    inline E2& get_f13(){
        return f13;
    }

    inline void set_f14(int32_t val){
        f14 = val;
    }
    inline int32_t& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M1->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M1->f3: " << f3 << std::endl;
        fout << "M1->f4: " << f4 << std::endl;
        if(f5 != nullptr)
            f5->print_message(fout);
        if(f6 != nullptr)
            f6->print_message(fout);
        fout << "M1->f7: " << f7 << std::endl;
        if(f8 != nullptr)
            f8->print_message(fout);
        fout << "M1->f9: " << f9 << std::endl;
        fout << "M1->f10: " << f10 << std::endl;
        fout << "M1->f11: " << f11 << std::endl;
        fout << "M1->f12: " << f12 << std::endl;
        fout << "M1->f13: " << f13 << std::endl;
        fout << "M1->f14: " << f14 << std::endl;
    }

    ~M1(){
        if(f2 != nullptr)
            delete f2;
        if(f5 != nullptr)
            delete f5;
        if(f6 != nullptr)
            delete f6;
        if(f8 != nullptr)
            delete f8;
    }

    M1(){
       f2 = nullptr;
       f5 = nullptr;
       f6 = nullptr;
       f8 = nullptr;
    }

private:
    alignas(8) E1 f1;
    alignas(8) M2* f2;
    alignas(8) bool f3;
    alignas(8) int64_t f4;
    alignas(8) M3* f5;
    alignas(8) M10* f6;
    alignas(8) float f7;
    alignas(8) M15* f8;
    alignas(8) bool f9;
    alignas(8) float f10;
    alignas(8) float f11;
    alignas(8) int32_t f12;
    alignas(8) E2 f13;
    alignas(8) int32_t f14;
};


class alignas(8) M35 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 4,
        E1_CONST_2 = 42,
        E1_CONST_3 = 14,
        E1_CONST_4 = 50,
        E1_CONST_5 = 91,
    };
    
    enum E2 {
        E2_CONST_1 = 37,
        E2_CONST_2 = 10,
        E2_CONST_3 = 76,
        E2_CONST_4 = 60,
        E2_CONST_5 = 124,
    };
    
    class alignas(8) M36 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 49,
            E1_CONST_2 = 51,
            E1_CONST_3 = 56,
            E1_CONST_4 = 25,
            E1_CONST_5 = 123,
        };
        
        class alignas(8) M37 : public M_base
        {
        public:
            class alignas(8) M38 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 38,
                    E1_CONST_2 = 104,
                    E1_CONST_3 = 43,
                    E1_CONST_4 = 11,
                    E1_CONST_5 = 113,
                };
                
                enum E2 {
                    E2_CONST_1 = 69,
                    E2_CONST_2 = 42,
                    E2_CONST_3 = 76,
                    E2_CONST_4 = 44,
                    E2_CONST_5 = 118,
                };
                
                enum E3 {
                    E3_CONST_1 = 106,
                    E3_CONST_2 = 49,
                    E3_CONST_3 = 85,
                    E3_CONST_4 = 117,
                    E3_CONST_5 = 122,
                };
                
                class alignas(8) M39 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 9,
                        E1_CONST_2 = 41,
                        E1_CONST_3 = 43,
                        E1_CONST_4 = 18,
                        E1_CONST_5 = 31,
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
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M39->f1: " << f1 << std::endl;
                        fout << "M39->f2: " << f2 << std::endl;
                    }
                
                    ~M39(){
                    }
                
                    M39(){
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) int32_t f2;
                };


                class alignas(8) M40 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 64,
                        E1_CONST_2 = 4,
                        E1_CONST_3 = 41,
                        E1_CONST_4 = 22,
                        E1_CONST_5 = 88,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 43,
                        E2_CONST_2 = 23,
                        E2_CONST_3 = 89,
                        E2_CONST_4 = 122,
                        E2_CONST_5 = 124,
                    };
                    
                    enum E3 {
                        E3_CONST_1 = 11,
                        E3_CONST_2 = 77,
                        E3_CONST_3 = 23,
                        E3_CONST_4 = 56,
                        E3_CONST_5 = 121,
                    };
                    
                    class alignas(8) M41 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 75,
                            E1_CONST_2 = 107,
                            E1_CONST_3 = 121,
                            E1_CONST_4 = 60,
                            E1_CONST_5 = 25,
                        };
                        
                        enum E2 {
                            E2_CONST_1 = 42,
                            E2_CONST_2 = 82,
                            E2_CONST_3 = 84,
                            E2_CONST_4 = 87,
                            E2_CONST_5 = 59,
                        };
                        
                        enum E3 {
                            E3_CONST_1 = 67,
                            E3_CONST_2 = 106,
                            E3_CONST_3 = 56,
                            E3_CONST_4 = 25,
                            E3_CONST_5 = 90,
                        };
                        
                        enum E4 {
                            E4_CONST_1 = 8,
                            E4_CONST_2 = 9,
                            E4_CONST_3 = 52,
                            E4_CONST_4 = 57,
                            E4_CONST_5 = 25,
                        };
                        
                        class alignas(8) M42 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 99,
                                E1_CONST_2 = 44,
                                E1_CONST_3 = 45,
                                E1_CONST_4 = 92,
                                E1_CONST_5 = 93,
                            };
                            
                            inline void set_f1(E1 val){
                                f1 = val;
                            }
                            inline E1& get_f1(){
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
                            alignas(8) E1 f1;
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
                    
                        inline void set_f3(E2 val){
                            f3 = val;
                        }
                        inline E2& get_f3(){
                            return f3;
                        }
                    
                        inline M42* mutable_f4(){
                            f4 = new M42();
                            return f4;
                        }
                        inline M42*& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(int64_t val){
                            f5 = val;
                        }
                        inline int64_t& get_f5(){
                            return f5;
                        }
                    
                        inline void set_f6(float val){
                            f6 = val;
                        }
                        inline float& get_f6(){
                            return f6;
                        }
                    
                        inline void set_f7(E3 val){
                            f7 = val;
                        }
                        inline E3& get_f7(){
                            return f7;
                        }
                    
                        inline void set_f8(uint32_t val){
                            f8 = val;
                        }
                        inline uint32_t& get_f8(){
                            return f8;
                        }
                    
                        inline void set_f9(E4 val){
                            f9 = val;
                        }
                        inline E4& get_f9(){
                            return f9;
                        }
                    
                        inline void set_f10(string val){
                            f10 = val;
                        }
                        inline string& get_f10(){
                            return f10;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M41->f1: " << f1 << std::endl;
                            fout << "M41->f2: " << f2 << std::endl;
                            fout << "M41->f3: " << f3 << std::endl;
                            if(f4 != nullptr)
                                f4->print_message(fout);
                            fout << "M41->f5: " << f5 << std::endl;
                            fout << "M41->f6: " << f6 << std::endl;
                            fout << "M41->f7: " << f7 << std::endl;
                            fout << "M41->f8: " << f8 << std::endl;
                            fout << "M41->f9: " << f9 << std::endl;
                            fout << "M41->f10: " << f10 << std::endl;
                        }
                    
                        ~M41(){
                            if(f4 != nullptr)
                                delete f4;
                        }
                    
                        M41(){
                           f4 = nullptr;
                        }
                    
                    private:
                        alignas(8) E1 f1;
                        alignas(8) int32_t f2;
                        alignas(8) E2 f3;
                        alignas(8) M42* f4;
                        alignas(8) int64_t f5;
                        alignas(8) float f6;
                        alignas(8) E3 f7;
                        alignas(8) uint32_t f8;
                        alignas(8) E4 f9;
                        alignas(8) string f10;
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
                
                    inline void set_f3(string val){
                        f3 = val;
                    }
                    inline string& get_f3(){
                        return f3;
                    }
                
                    inline M41* mutable_f4(){
                        f4 = new M41();
                        return f4;
                    }
                    inline M41*& get_f4(){
                        return f4;
                    }
                
                    inline void set_f5(E1 val){
                        f5 = val;
                    }
                    inline E1& get_f5(){
                        return f5;
                    }
                
                    inline void set_f6(E2 val){
                        f6 = val;
                    }
                    inline E2& get_f6(){
                        return f6;
                    }
                
                    inline void set_f7(E3 val){
                        f7 = val;
                    }
                    inline E3& get_f7(){
                        return f7;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M40->f1: " << f1 << std::endl;
                        fout << "M40->f2: " << f2 << std::endl;
                        fout << "M40->f3: " << f3 << std::endl;
                        if(f4 != nullptr)
                            f4->print_message(fout);
                        fout << "M40->f5: " << f5 << std::endl;
                        fout << "M40->f6: " << f6 << std::endl;
                        fout << "M40->f7: " << f7 << std::endl;
                    }
                
                    ~M40(){
                        if(f4 != nullptr)
                            delete f4;
                    }
                
                    M40(){
                       f4 = nullptr;
                    }
                
                private:
                    alignas(8) int32_t f1;
                    alignas(8) string f2;
                    alignas(8) string f3;
                    alignas(8) M41* f4;
                    alignas(8) E1 f5;
                    alignas(8) E2 f6;
                    alignas(8) E3 f7;
                };


                inline void set_f1(E1 val){
                    f1 = val;
                }
                inline E1& get_f1(){
                    return f1;
                }
            
                inline void set_f2(uint64_t val){
                    f2 = val;
                }
                inline uint64_t& get_f2(){
                    return f2;
                }
            
                inline void set_f3(uint32_t val){
                    f3 = val;
                }
                inline uint32_t& get_f3(){
                    return f3;
                }
            
                inline M39* mutable_f4(){
                    f4 = new M39();
                    return f4;
                }
                inline M39*& get_f4(){
                    return f4;
                }
            
                inline M40* mutable_f5(){
                    f5 = new M40();
                    return f5;
                }
                inline M40*& get_f5(){
                    return f5;
                }
            
                inline void set_f6(uint32_t val){
                    f6 = val;
                }
                inline uint32_t& get_f6(){
                    return f6;
                }
            
                inline void set_f7(uint32_t val){
                    f7 = val;
                }
                inline uint32_t& get_f7(){
                    return f7;
                }
            
                inline void set_f8(E2 val){
                    f8 = val;
                }
                inline E2& get_f8(){
                    return f8;
                }
            
                inline void set_f9(E3 val){
                    f9 = val;
                }
                inline E3& get_f9(){
                    return f9;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M38->f1: " << f1 << std::endl;
                    fout << "M38->f2: " << f2 << std::endl;
                    fout << "M38->f3: " << f3 << std::endl;
                    if(f4 != nullptr)
                        f4->print_message(fout);
                    if(f5 != nullptr)
                        f5->print_message(fout);
                    fout << "M38->f6: " << f6 << std::endl;
                    fout << "M38->f7: " << f7 << std::endl;
                    fout << "M38->f8: " << f8 << std::endl;
                    fout << "M38->f9: " << f9 << std::endl;
                }
            
                ~M38(){
                    if(f4 != nullptr)
                        delete f4;
                    if(f5 != nullptr)
                        delete f5;
                }
            
                M38(){
                   f4 = nullptr;
                   f5 = nullptr;
                }
            
            private:
                alignas(8) E1 f1;
                alignas(8) uint64_t f2;
                alignas(8) uint32_t f3;
                alignas(8) M39* f4;
                alignas(8) M40* f5;
                alignas(8) uint32_t f6;
                alignas(8) uint32_t f7;
                alignas(8) E2 f8;
                alignas(8) E3 f9;
            };


            inline M38* mutable_f1(){
                f1 = new M38();
                return f1;
            }
            inline M38*& get_f1(){
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
                fout << "M37->f2: " << f2 << std::endl;
                fout << "M37->f3: " << f3 << std::endl;
            }
        
            ~M37(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M37(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M38* f1;
            alignas(8) int32_t f2;
            alignas(8) bool f3;
        };


        class alignas(8) M43 : public M_base
        {
        public:
            class alignas(8) M44 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 5,
                    E1_CONST_2 = 49,
                    E1_CONST_3 = 90,
                    E1_CONST_4 = 92,
                    E1_CONST_5 = 125,
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
            
                inline void set_f3(bool val){
                    f3 = val;
                }
                inline bool& get_f3(){
                    return f3;
                }
            
                inline void set_f4(float val){
                    f4 = val;
                }
                inline float& get_f4(){
                    return f4;
                }
            
                inline void set_f5(E1 val){
                    f5 = val;
                }
                inline E1& get_f5(){
                    return f5;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M44->f1: " << f1 << std::endl;
                    fout << "M44->f2: " << f2 << std::endl;
                    fout << "M44->f3: " << f3 << std::endl;
                    fout << "M44->f4: " << f4 << std::endl;
                    fout << "M44->f5: " << f5 << std::endl;
                }
            
                ~M44(){
                }
            
                M44(){
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) int32_t f2;
                alignas(8) bool f3;
                alignas(8) float f4;
                alignas(8) E1 f5;
            };


            inline M44* mutable_f1(){
                f1 = new M44();
                return f1;
            }
            inline M44*& get_f1(){
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
                fout << "M43->f2: " << f2 << std::endl;
            }
        
            ~M43(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M43(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M44* f1;
            alignas(8) int64_t f2;
        };


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
                E1_CONST_1 = 3,
                E1_CONST_2 = 39,
                E1_CONST_3 = 73,
                E1_CONST_4 = 113,
                E1_CONST_5 = 52,
            };
            
            class alignas(8) M47 : public M_base
            {
            public:
                class alignas(8) M48 : public M_base
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
                        fout << "M48->f1: " << f1 << std::endl;
                        fout << "M48->f2: " << f2 << std::endl;
                    }
                
                    ~M48(){
                    }
                
                    M48(){
                    }
                
                private:
                    alignas(8) int32_t f1;
                    alignas(8) float f2;
                };


                class alignas(8) M49 : public M_base
                {
                public:
                    class alignas(8) M50 : public M_base
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
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M50->f1: " << f1 << std::endl;
                            fout << "M50->f2: " << f2 << std::endl;
                            fout << "M50->f3: " << f3 << std::endl;
                            fout << "M50->f4: " << f4 << std::endl;
                        }
                    
                        ~M50(){
                        }
                    
                        M50(){
                        }
                    
                    private:
                        alignas(8) int32_t f1;
                        alignas(8) uint64_t f2;
                        alignas(8) int64_t f3;
                        alignas(8) int64_t f4;
                    };


                    class alignas(8) M51 : public M_base
                    {
                    public:
                        class alignas(8) M52 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 0,
                                E1_CONST_2 = 66,
                                E1_CONST_3 = 67,
                                E1_CONST_4 = 72,
                                E1_CONST_5 = 85,
                            };
                            
                            enum E2 {
                                E2_CONST_1 = 68,
                                E2_CONST_2 = 9,
                                E2_CONST_3 = 16,
                                E2_CONST_4 = 17,
                                E2_CONST_5 = 89,
                            };
                            
                            enum E3 {
                                E3_CONST_1 = 97,
                                E3_CONST_2 = 17,
                                E3_CONST_3 = 114,
                                E3_CONST_4 = 51,
                                E3_CONST_5 = 118,
                            };
                            
                            inline void set_f1(E1 val){
                                f1 = val;
                            }
                            inline E1& get_f1(){
                                return f1;
                            }
                        
                            inline void set_f2(E2 val){
                                f2 = val;
                            }
                            inline E2& get_f2(){
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
                        
                            inline void set_f5(E3 val){
                                f5 = val;
                            }
                            inline E3& get_f5(){
                                return f5;
                            }
                        
                            inline void set_f6(int32_t val){
                                f6 = val;
                            }
                            inline int32_t& get_f6(){
                                return f6;
                            }
                        
                            inline void add_f7(string val){
                                f7.push_back(val);
                            }
                            inline string& get_f7(int idx){
                                return f7[idx];
                            }
                        
                            inline void set_f8(bool val){
                                f8 = val;
                            }
                            inline bool& get_f8(){
                                return f8;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M52->f1: " << f1 << std::endl;
                                fout << "M52->f2: " << f2 << std::endl;
                                fout << "M52->f3: " << f3 << std::endl;
                                fout << "M52->f4: " << f4 << std::endl;
                                fout << "M52->f5: " << f5 << std::endl;
                                fout << "M52->f6: " << f6 << std::endl;
                                for(auto &f7_val : f7){
                                    fout << "M52->f7: " << f7_val << std::endl;
                                }
                                fout << "M52->f8: " << f8 << std::endl;
                            }
                        
                            ~M52(){
                            }
                        
                            M52(){
                            }
                        
                        private:
                            alignas(8) E1 f1;
                            alignas(8) E2 f2;
                            alignas(8) string f3;
                            alignas(8) float f4;
                            alignas(8) E3 f5;
                            alignas(8) int32_t f6;
                            alignas(8) std::vector<string> f7;
                            alignas(8) bool f8;
                        };


                        class alignas(8) M53 : public M_base
                        {
                        public:
                            class alignas(8) M54 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 104,
                                    E1_CONST_2 = 41,
                                    E1_CONST_3 = 53,
                                    E1_CONST_4 = 85,
                                    E1_CONST_5 = 93,
                                };
                                
                                enum E2 {
                                    E2_CONST_1 = 32,
                                    E2_CONST_2 = 99,
                                    E2_CONST_3 = 116,
                                    E2_CONST_4 = 90,
                                    E2_CONST_5 = 28,
                                };
                                
                                enum E3 {
                                    E3_CONST_1 = 0,
                                    E3_CONST_2 = 97,
                                    E3_CONST_3 = 40,
                                    E3_CONST_4 = 116,
                                    E3_CONST_5 = 84,
                                };
                                
                                class alignas(8) M55 : public M_base
                                {
                                public:
                                    enum E1 {
                                        E1_CONST_1 = 75,
                                        E1_CONST_2 = 78,
                                        E1_CONST_3 = 115,
                                        E1_CONST_4 = 19,
                                        E1_CONST_5 = 55,
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
                                
                                    inline void set_f3(uint32_t val){
                                        f3 = val;
                                    }
                                    inline uint32_t& get_f3(){
                                        return f3;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M55->f1: " << f1 << std::endl;
                                        fout << "M55->f2: " << f2 << std::endl;
                                        fout << "M55->f3: " << f3 << std::endl;
                                    }
                                
                                    ~M55(){
                                    }
                                
                                    M55(){
                                    }
                                
                                private:
                                    alignas(8) E1 f1;
                                    alignas(8) int32_t f2;
                                    alignas(8) uint32_t f3;
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
                                            class alignas(8) M59 : public M_base
                                            {
                                            public:
                                                class alignas(8) M60 : public M_base
                                                {
                                                public:
                                                    enum E1 {
                                                        E1_CONST_1 = 101,
                                                        E1_CONST_2 = 71,
                                                        E1_CONST_3 = 15,
                                                        E1_CONST_4 = 55,
                                                        E1_CONST_5 = 56,
                                                    };
                                                    
                                                    class alignas(8) M61 : public M_base
                                                    {
                                                    public:
                                                        enum E1 {
                                                            E1_CONST_1 = 33,
                                                            E1_CONST_2 = 40,
                                                            E1_CONST_3 = 86,
                                                            E1_CONST_4 = 23,
                                                            E1_CONST_5 = 92,
                                                        };
                                                        
                                                        enum E2 {
                                                            E2_CONST_1 = 106,
                                                            E2_CONST_2 = 77,
                                                            E2_CONST_3 = 85,
                                                            E2_CONST_4 = 118,
                                                            E2_CONST_5 = 92,
                                                        };
                                                        
                                                        inline void set_f1(uint32_t val){
                                                            f1 = val;
                                                        }
                                                        inline uint32_t& get_f1(){
                                                            return f1;
                                                        }
                                                    
                                                        inline void set_f2(uint32_t val){
                                                            f2 = val;
                                                        }
                                                        inline uint32_t& get_f2(){
                                                            return f2;
                                                        }
                                                    
                                                        inline void set_f3(int64_t val){
                                                            f3 = val;
                                                        }
                                                        inline int64_t& get_f3(){
                                                            return f3;
                                                        }
                                                    
                                                        inline void set_f4(E1 val){
                                                            f4 = val;
                                                        }
                                                        inline E1& get_f4(){
                                                            return f4;
                                                        }
                                                    
                                                        inline void add_f5(string val){
                                                            f5.push_back(val);
                                                        }
                                                        inline string& get_f5(int idx){
                                                            return f5[idx];
                                                        }
                                                    
                                                        inline void add_f6(string val){
                                                            f6.push_back(val);
                                                        }
                                                        inline string& get_f6(int idx){
                                                            return f6[idx];
                                                        }
                                                    
                                                        inline void set_f7(E2 val){
                                                            f7 = val;
                                                        }
                                                        inline E2& get_f7(){
                                                            return f7;
                                                        }
                                                    
                                                        inline void set_f8(bool val){
                                                            f8 = val;
                                                        }
                                                        inline bool& get_f8(){
                                                            return f8;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M61->f1: " << f1 << std::endl;
                                                            fout << "M61->f2: " << f2 << std::endl;
                                                            fout << "M61->f3: " << f3 << std::endl;
                                                            fout << "M61->f4: " << f4 << std::endl;
                                                            for(auto &f5_val : f5){
                                                                fout << "M61->f5: " << f5_val << std::endl;
                                                            }
                                                            for(auto &f6_val : f6){
                                                                fout << "M61->f6: " << f6_val << std::endl;
                                                            }
                                                            fout << "M61->f7: " << f7 << std::endl;
                                                            fout << "M61->f8: " << f8 << std::endl;
                                                        }
                                                    
                                                        ~M61(){
                                                        }
                                                    
                                                        M61(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) uint32_t f1;
                                                        alignas(8) uint32_t f2;
                                                        alignas(8) int64_t f3;
                                                        alignas(8) E1 f4;
                                                        alignas(8) std::vector<string> f5;
                                                        alignas(8) std::vector<string> f6;
                                                        alignas(8) E2 f7;
                                                        alignas(8) bool f8;
                                                    };


                                                    inline void set_f1(bool val){
                                                        f1 = val;
                                                    }
                                                    inline bool& get_f1(){
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
                                                
                                                    inline void set_f4(uint32_t val){
                                                        f4 = val;
                                                    }
                                                    inline uint32_t& get_f4(){
                                                        return f4;
                                                    }
                                                
                                                    inline void set_f5(uint32_t val){
                                                        f5 = val;
                                                    }
                                                    inline uint32_t& get_f5(){
                                                        return f5;
                                                    }
                                                
                                                    inline void set_f6(int32_t val){
                                                        f6 = val;
                                                    }
                                                    inline int32_t& get_f6(){
                                                        return f6;
                                                    }
                                                
                                                    inline void set_f7(float val){
                                                        f7 = val;
                                                    }
                                                    inline float& get_f7(){
                                                        return f7;
                                                    }
                                                
                                                    inline void set_f8(bool val){
                                                        f8 = val;
                                                    }
                                                    inline bool& get_f8(){
                                                        return f8;
                                                    }
                                                
                                                    inline void set_f9(float val){
                                                        f9 = val;
                                                    }
                                                    inline float& get_f9(){
                                                        return f9;
                                                    }
                                                
                                                    inline void set_f10(string val){
                                                        f10 = val;
                                                    }
                                                    inline string& get_f10(){
                                                        return f10;
                                                    }
                                                
                                                    inline M61* mutable_f11(){
                                                        f11 = new M61();
                                                        return f11;
                                                    }
                                                    inline M61*& get_f11(){
                                                        return f11;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M60->f1: " << f1 << std::endl;
                                                        fout << "M60->f2: " << f2 << std::endl;
                                                        fout << "M60->f3: " << f3 << std::endl;
                                                        fout << "M60->f4: " << f4 << std::endl;
                                                        fout << "M60->f5: " << f5 << std::endl;
                                                        fout << "M60->f6: " << f6 << std::endl;
                                                        fout << "M60->f7: " << f7 << std::endl;
                                                        fout << "M60->f8: " << f8 << std::endl;
                                                        fout << "M60->f9: " << f9 << std::endl;
                                                        fout << "M60->f10: " << f10 << std::endl;
                                                        if(f11 != nullptr)
                                                            f11->print_message(fout);
                                                    }
                                                
                                                    ~M60(){
                                                        if(f11 != nullptr)
                                                            delete f11;
                                                    }
                                                
                                                    M60(){
                                                       f11 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) bool f1;
                                                    alignas(8) float f2;
                                                    alignas(8) E1 f3;
                                                    alignas(8) uint32_t f4;
                                                    alignas(8) uint32_t f5;
                                                    alignas(8) int32_t f6;
                                                    alignas(8) float f7;
                                                    alignas(8) bool f8;
                                                    alignas(8) float f9;
                                                    alignas(8) string f10;
                                                    alignas(8) M61* f11;
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
                                            
                                                inline M60* mutable_f3(){
                                                    f3 = new M60();
                                                    return f3;
                                                }
                                                inline M60*& get_f3(){
                                                    return f3;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    fout << "M59->f1: " << f1 << std::endl;
                                                    fout << "M59->f2: " << f2 << std::endl;
                                                    if(f3 != nullptr)
                                                        f3->print_message(fout);
                                                }
                                            
                                                ~M59(){
                                                    if(f3 != nullptr)
                                                        delete f3;
                                                }
                                            
                                                M59(){
                                                   f3 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) string f1;
                                                alignas(8) int32_t f2;
                                                alignas(8) M60* f3;
                                            };


                                            inline void set_f1(int32_t val){
                                                f1 = val;
                                            }
                                            inline int32_t& get_f1(){
                                                return f1;
                                            }
                                        
                                            inline M59* mutable_f2(){
                                                f2 = new M59();
                                                return f2;
                                            }
                                            inline M59*& get_f2(){
                                                return f2;
                                            }
                                        
                                            inline void set_f3(uint32_t val){
                                                f3 = val;
                                            }
                                            inline uint32_t& get_f3(){
                                                return f3;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M58->f1: " << f1 << std::endl;
                                                if(f2 != nullptr)
                                                    f2->print_message(fout);
                                                fout << "M58->f3: " << f3 << std::endl;
                                            }
                                        
                                            ~M58(){
                                                if(f2 != nullptr)
                                                    delete f2;
                                            }
                                        
                                            M58(){
                                               f2 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) int32_t f1;
                                            alignas(8) M59* f2;
                                            alignas(8) uint32_t f3;
                                        };


                                        inline void set_f1(float val){
                                            f1 = val;
                                        }
                                        inline float& get_f1(){
                                            return f1;
                                        }
                                    
                                        inline M58* mutable_f2(){
                                            f2 = new M58();
                                            return f2;
                                        }
                                        inline M58*& get_f2(){
                                            return f2;
                                        }
                                    
                                        inline void print_message(std::ofstream &fout){
                                            fout << "M57->f1: " << f1 << std::endl;
                                            if(f2 != nullptr)
                                                f2->print_message(fout);
                                        }
                                    
                                        ~M57(){
                                            if(f2 != nullptr)
                                                delete f2;
                                        }
                                    
                                        M57(){
                                           f2 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) float f1;
                                        alignas(8) M58* f2;
                                    };


                                    inline void set_f1(uint32_t val){
                                        f1 = val;
                                    }
                                    inline uint32_t& get_f1(){
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
                                    alignas(8) uint32_t f1;
                                    alignas(8) M57* f2;
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
                            
                                inline void set_f6(E2 val){
                                    f6 = val;
                                }
                                inline E2& get_f6(){
                                    return f6;
                                }
                            
                                inline void add_f7(float val){
                                    f7.push_back(val);
                                }
                                inline float& get_f7(int idx){
                                    return f7[idx];
                                }
                            
                                inline M55* mutable_f8(){
                                    f8 = new M55();
                                    return f8;
                                }
                                inline M55*& get_f8(){
                                    return f8;
                                }
                            
                                inline void set_f9(E3 val){
                                    f9 = val;
                                }
                                inline E3& get_f9(){
                                    return f9;
                                }
                            
                                inline M56* mutable_f10(){
                                    f10 = new M56();
                                    return f10;
                                }
                                inline M56*& get_f10(){
                                    return f10;
                                }
                            
                                inline void set_f11(int64_t val){
                                    f11 = val;
                                }
                                inline int64_t& get_f11(){
                                    return f11;
                                }
                            
                                inline void set_f12(bool val){
                                    f12 = val;
                                }
                                inline bool& get_f12(){
                                    return f12;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M54->f1: " << f1 << std::endl;
                                    fout << "M54->f2: " << f2 << std::endl;
                                    fout << "M54->f3: " << f3 << std::endl;
                                    fout << "M54->f4: " << f4 << std::endl;
                                    fout << "M54->f5: " << f5 << std::endl;
                                    fout << "M54->f6: " << f6 << std::endl;
                                    for(auto &f7_val : f7){
                                        fout << "M54->f7: " << f7_val << std::endl;
                                    }
                                    if(f8 != nullptr)
                                        f8->print_message(fout);
                                    fout << "M54->f9: " << f9 << std::endl;
                                    if(f10 != nullptr)
                                        f10->print_message(fout);
                                    fout << "M54->f11: " << f11 << std::endl;
                                    fout << "M54->f12: " << f12 << std::endl;
                                }
                            
                                ~M54(){
                                    if(f8 != nullptr)
                                        delete f8;
                                    if(f10 != nullptr)
                                        delete f10;
                                }
                            
                                M54(){
                                   f8 = nullptr;
                                   f10 = nullptr;
                                }
                            
                            private:
                                alignas(8) E1 f1;
                                alignas(8) int32_t f2;
                                alignas(8) int32_t f3;
                                alignas(8) int32_t f4;
                                alignas(8) uint32_t f5;
                                alignas(8) E2 f6;
                                alignas(8) std::vector<float> f7;
                                alignas(8) M55* f8;
                                alignas(8) E3 f9;
                                alignas(8) M56* f10;
                                alignas(8) int64_t f11;
                                alignas(8) bool f12;
                            };


                            inline void set_f1(int32_t val){
                                f1 = val;
                            }
                            inline int32_t& get_f1(){
                                return f1;
                            }
                        
                            inline M54* mutable_f2(){
                                f2 = new M54();
                                return f2;
                            }
                            inline M54*& get_f2(){
                                return f2;
                            }
                        
                            inline void set_f3(int64_t val){
                                f3 = val;
                            }
                            inline int64_t& get_f3(){
                                return f3;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M53->f1: " << f1 << std::endl;
                                if(f2 != nullptr)
                                    f2->print_message(fout);
                                fout << "M53->f3: " << f3 << std::endl;
                            }
                        
                            ~M53(){
                                if(f2 != nullptr)
                                    delete f2;
                            }
                        
                            M53(){
                               f2 = nullptr;
                            }
                        
                        private:
                            alignas(8) int32_t f1;
                            alignas(8) M54* f2;
                            alignas(8) int64_t f3;
                        };


                        inline M52* mutable_f1(){
                            f1 = new M52();
                            return f1;
                        }
                        inline M52*& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(uint32_t val){
                            f2 = val;
                        }
                        inline uint32_t& get_f2(){
                            return f2;
                        }
                    
                        inline M53* mutable_f3(){
                            f3 = new M53();
                            return f3;
                        }
                        inline M53*& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            if(f1 != nullptr)
                                f1->print_message(fout);
                            fout << "M51->f2: " << f2 << std::endl;
                            if(f3 != nullptr)
                                f3->print_message(fout);
                        }
                    
                        ~M51(){
                            if(f1 != nullptr)
                                delete f1;
                            if(f3 != nullptr)
                                delete f3;
                        }
                    
                        M51(){
                           f1 = nullptr;
                           f3 = nullptr;
                        }
                    
                    private:
                        alignas(8) M52* f1;
                        alignas(8) uint32_t f2;
                        alignas(8) M53* f3;
                    };


                    inline M50* mutable_f1(){
                        f1 = new M50();
                        return f1;
                    }
                    inline M50*& get_f1(){
                        return f1;
                    }
                
                    inline void set_f2(float val){
                        f2 = val;
                    }
                    inline float& get_f2(){
                        return f2;
                    }
                
                    inline M51* mutable_f3(){
                        f3 = new M51();
                        return f3;
                    }
                    inline M51*& get_f3(){
                        return f3;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        if(f1 != nullptr)
                            f1->print_message(fout);
                        fout << "M49->f2: " << f2 << std::endl;
                        if(f3 != nullptr)
                            f3->print_message(fout);
                    }
                
                    ~M49(){
                        if(f1 != nullptr)
                            delete f1;
                        if(f3 != nullptr)
                            delete f3;
                    }
                
                    M49(){
                       f1 = nullptr;
                       f3 = nullptr;
                    }
                
                private:
                    alignas(8) M50* f1;
                    alignas(8) float f2;
                    alignas(8) M51* f3;
                };


                class alignas(8) M62 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 1,
                        E1_CONST_2 = 72,
                        E1_CONST_3 = 118,
                        E1_CONST_4 = 119,
                        E1_CONST_5 = 95,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M62->f1: " << f1 << std::endl;
                    }
                
                    ~M62(){
                    }
                
                    M62(){
                    }
                
                private:
                    alignas(8) E1 f1;
                };


                inline M48* mutable_f1(){
                    f1 = new M48();
                    return f1;
                }
                inline M48*& get_f1(){
                    return f1;
                }
            
                inline M49* mutable_f2(){
                    f2 = new M49();
                    return f2;
                }
                inline M49*& get_f2(){
                    return f2;
                }
            
                inline M62* mutable_f3(){
                    f3 = new M62();
                    return f3;
                }
                inline M62*& get_f3(){
                    return f3;
                }
            
                inline void set_f4(uint32_t val){
                    f4 = val;
                }
                inline uint32_t& get_f4(){
                    return f4;
                }
            
                inline void print_message(std::ofstream &fout){
                    if(f1 != nullptr)
                        f1->print_message(fout);
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    if(f3 != nullptr)
                        f3->print_message(fout);
                    fout << "M47->f4: " << f4 << std::endl;
                }
            
                ~M47(){
                    if(f1 != nullptr)
                        delete f1;
                    if(f2 != nullptr)
                        delete f2;
                    if(f3 != nullptr)
                        delete f3;
                }
            
                M47(){
                   f1 = nullptr;
                   f2 = nullptr;
                   f3 = nullptr;
                }
            
            private:
                alignas(8) M48* f1;
                alignas(8) M49* f2;
                alignas(8) M62* f3;
                alignas(8) uint32_t f4;
            };


            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline M47* mutable_f2(){
                f2 = new M47();
                return f2;
            }
            inline M47*& get_f2(){
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M46->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M46->f3: " << f3 << std::endl;
                fout << "M46->f4: " << f4 << std::endl;
            }
        
            ~M46(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M46(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) E1 f1;
            alignas(8) M47* f2;
            alignas(8) bool f3;
            alignas(8) string f4;
        };


        inline void set_f1(E1 val){
            f1 = val;
        }
        inline E1& get_f1(){
            return f1;
        }
    
        inline M37* mutable_f2(){
            f2 = new M37();
            return f2;
        }
        inline M37*& get_f2(){
            return f2;
        }
    
        inline M43* mutable_f3(){
            f3 = new M43();
            return f3;
        }
        inline M43*& get_f3(){
            return f3;
        }
    
        inline M45* mutable_f4(){
            f4 = new M45();
            return f4;
        }
        inline M45*& get_f4(){
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
    
        inline M46* mutable_f7(){
            f7 = new M46();
            return f7;
        }
        inline M46*& get_f7(){
            return f7;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M36->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            if(f3 != nullptr)
                f3->print_message(fout);
            if(f4 != nullptr)
                f4->print_message(fout);
            fout << "M36->f5: " << f5 << std::endl;
            fout << "M36->f6: " << f6 << std::endl;
            if(f7 != nullptr)
                f7->print_message(fout);
        }
    
        ~M36(){
            if(f2 != nullptr)
                delete f2;
            if(f3 != nullptr)
                delete f3;
            if(f4 != nullptr)
                delete f4;
            if(f7 != nullptr)
                delete f7;
        }
    
        M36(){
           f2 = nullptr;
           f3 = nullptr;
           f4 = nullptr;
           f7 = nullptr;
        }
    
    private:
        alignas(8) E1 f1;
        alignas(8) M37* f2;
        alignas(8) M43* f3;
        alignas(8) M45* f4;
        alignas(8) int64_t f5;
        alignas(8) bool f6;
        alignas(8) M46* f7;
    };


    class alignas(8) M63 : public M_base
    {
    public:
        class alignas(8) M64 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M64->f1: " << f1 << std::endl;
            }
        
            ~M64(){
            }
        
            M64(){
            }
        
        private:
            alignas(8) int32_t f1;
        };


        inline M64* mutable_f1(){
            f1 = new M64();
            return f1;
        }
        inline M64*& get_f1(){
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
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M63->f2: " << f2 << std::endl;
            fout << "M63->f3: " << f3 << std::endl;
        }
    
        ~M63(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M63(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M64* f1;
        alignas(8) string f2;
        alignas(8) int64_t f3;
    };


    class alignas(8) M65 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 4,
            E1_CONST_2 = 46,
            E1_CONST_3 = 15,
            E1_CONST_4 = 122,
            E1_CONST_5 = 94,
        };
        
        enum E2 {
            E2_CONST_1 = 12,
            E2_CONST_2 = 51,
            E2_CONST_3 = 119,
            E2_CONST_4 = 85,
            E2_CONST_5 = 55,
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
    
        inline void set_f3(E1 val){
            f3 = val;
        }
        inline E1& get_f3(){
            return f3;
        }
    
        inline void set_f4(int32_t val){
            f4 = val;
        }
        inline int32_t& get_f4(){
            return f4;
        }
    
        inline void set_f5(E2 val){
            f5 = val;
        }
        inline E2& get_f5(){
            return f5;
        }
    
        inline void set_f6(float val){
            f6 = val;
        }
        inline float& get_f6(){
            return f6;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M65->f1: " << f1 << std::endl;
            fout << "M65->f2: " << f2 << std::endl;
            fout << "M65->f3: " << f3 << std::endl;
            fout << "M65->f4: " << f4 << std::endl;
            fout << "M65->f5: " << f5 << std::endl;
            fout << "M65->f6: " << f6 << std::endl;
        }
    
        ~M65(){
        }
    
        M65(){
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) float f2;
        alignas(8) E1 f3;
        alignas(8) int32_t f4;
        alignas(8) E2 f5;
        alignas(8) float f6;
    };


    class alignas(8) M66 : public M_base
    {
    public:
        class alignas(8) M67 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 7,
                E1_CONST_2 = 81,
                E1_CONST_3 = 50,
                E1_CONST_4 = 85,
                E1_CONST_5 = 3103,
            };
            
            enum E2 {
                E2_CONST_1 = 44,
                E2_CONST_2 = 78,
                E2_CONST_3 = 15,
                E2_CONST_4 = 84,
                E2_CONST_5 = 60,
            };
            
            inline void add_f1(string val){
                f1.push_back(val);
            }
            inline string& get_f1(int idx){
                return f1[idx];
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
        
            inline void set_f4(bool val){
                f4 = val;
            }
            inline bool& get_f4(){
                return f4;
            }
        
            inline void set_f5(uint32_t val){
                f5 = val;
            }
            inline uint32_t& get_f5(){
                return f5;
            }
        
            inline void set_f6(E2 val){
                f6 = val;
            }
            inline E2& get_f6(){
                return f6;
            }
        
            inline void print_message(std::ofstream &fout){
                for(auto &f1_val : f1){
                    fout << "M67->f1: " << f1_val << std::endl;
                }
                fout << "M67->f2: " << f2 << std::endl;
                fout << "M67->f3: " << f3 << std::endl;
                fout << "M67->f4: " << f4 << std::endl;
                fout << "M67->f5: " << f5 << std::endl;
                fout << "M67->f6: " << f6 << std::endl;
            }
        
            ~M67(){
            }
        
            M67(){
            }
        
        private:
            alignas(8) std::vector<string> f1;
            alignas(8) E1 f2;
            alignas(8) int64_t f3;
            alignas(8) bool f4;
            alignas(8) uint32_t f5;
            alignas(8) E2 f6;
        };


        inline M67* mutable_f1(){
            f1 = new M67();
            return f1;
        }
        inline M67*& get_f1(){
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
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M66->f2: " << f2 << std::endl;
            fout << "M66->f3: " << f3 << std::endl;
        }
    
        ~M66(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M66(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M67* f1;
        alignas(8) bool f2;
        alignas(8) int32_t f3;
    };


    inline void set_f1(uint32_t val){
        f1 = val;
    }
    inline uint32_t& get_f1(){
        return f1;
    }

    inline M36* mutable_f2(){
        f2 = new M36();
        return f2;
    }
    inline M36*& get_f2(){
        return f2;
    }

    inline M63* mutable_f3(){
        f3 = new M63();
        return f3;
    }
    inline M63*& get_f3(){
        return f3;
    }

    inline M65* mutable_f4(){
        f4 = new M65();
        return f4;
    }
    inline M65*& get_f4(){
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

    inline void set_f7(uint64_t val){
        f7 = val;
    }
    inline uint64_t& get_f7(){
        return f7;
    }

    inline void set_f8(E1 val){
        f8 = val;
    }
    inline E1& get_f8(){
        return f8;
    }

    inline void set_f9(E2 val){
        f9 = val;
    }
    inline E2& get_f9(){
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

    inline M66* mutable_f13(){
        f13 = new M66();
        return f13;
    }
    inline M66*& get_f13(){
        return f13;
    }

    inline void set_f14(uint32_t val){
        f14 = val;
    }
    inline uint32_t& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M35->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        if(f3 != nullptr)
            f3->print_message(fout);
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M35->f5: " << f5 << std::endl;
        fout << "M35->f6: " << f6 << std::endl;
        fout << "M35->f7: " << f7 << std::endl;
        fout << "M35->f8: " << f8 << std::endl;
        fout << "M35->f9: " << f9 << std::endl;
        fout << "M35->f10: " << f10 << std::endl;
        fout << "M35->f11: " << f11 << std::endl;
        fout << "M35->f12: " << f12 << std::endl;
        if(f13 != nullptr)
            f13->print_message(fout);
        fout << "M35->f14: " << f14 << std::endl;
    }

    ~M35(){
        if(f2 != nullptr)
            delete f2;
        if(f3 != nullptr)
            delete f3;
        if(f4 != nullptr)
            delete f4;
        if(f13 != nullptr)
            delete f13;
    }

    M35(){
       f2 = nullptr;
       f3 = nullptr;
       f4 = nullptr;
       f13 = nullptr;
    }

private:
    alignas(8) uint32_t f1;
    alignas(8) M36* f2;
    alignas(8) M63* f3;
    alignas(8) M65* f4;
    alignas(8) int32_t f5;
    alignas(8) float f6;
    alignas(8) uint64_t f7;
    alignas(8) E1 f8;
    alignas(8) E2 f9;
    alignas(8) int32_t f10;
    alignas(8) int32_t f11;
    alignas(8) int32_t f12;
    alignas(8) M66* f13;
    alignas(8) uint32_t f14;
};


class alignas(8) M68 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 35,
        E1_CONST_2 = 43,
        E1_CONST_3 = 81,
        E1_CONST_4 = 113,
        E1_CONST_5 = 83,
    };
    
    enum E2 {
        E2_CONST_1 = 90,
        E2_CONST_2 = 16,
        E2_CONST_3 = 116,
        E2_CONST_4 = 24,
        E2_CONST_5 = 122,
    };
    
    enum E3 {
        E3_CONST_1 = 2,
        E3_CONST_2 = 101,
        E3_CONST_3 = 74,
        E3_CONST_4 = 77,
        E3_CONST_5 = 110,
    };
    
    class alignas(8) M69 : public M_base
    {
    public:
        inline void set_f1(float val){
            f1 = val;
        }
        inline float& get_f1(){
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
    
        inline void set_f4(float val){
            f4 = val;
        }
        inline float& get_f4(){
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
            fout << "M69->f1: " << f1 << std::endl;
            fout << "M69->f2: " << f2 << std::endl;
            fout << "M69->f3: " << f3 << std::endl;
            fout << "M69->f4: " << f4 << std::endl;
            for(auto &f5_val : f5){
                fout << "M69->f5: " << f5_val << std::endl;
            }
            fout << "M69->f6: " << f6 << std::endl;
        }
    
        ~M69(){
        }
    
        M69(){
        }
    
    private:
        alignas(8) float f1;
        alignas(8) uint32_t f2;
        alignas(8) int32_t f3;
        alignas(8) float f4;
        alignas(8) std::vector<string> f5;
        alignas(8) int64_t f6;
    };


    class alignas(8) M70 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 98,
            E1_CONST_2 = 99,
            E1_CONST_3 = 102,
            E1_CONST_4 = 109,
            E1_CONST_5 = 79,
        };
        
        class alignas(8) M71 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 103,
                E1_CONST_2 = 10,
                E1_CONST_3 = 44,
                E1_CONST_4 = 90,
                E1_CONST_5 = 28,
            };
            
            enum E2 {
                E2_CONST_1 = 33,
                E2_CONST_2 = 11,
                E2_CONST_3 = 109,
                E2_CONST_4 = 82,
                E2_CONST_5 = 20,
            };
            
            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline void set_f2(E2 val){
                f2 = val;
            }
            inline E2& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M71->f1: " << f1 << std::endl;
                fout << "M71->f2: " << f2 << std::endl;
            }
        
            ~M71(){
            }
        
            M71(){
            }
        
        private:
            alignas(8) E1 f1;
            alignas(8) E2 f2;
        };


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
    
        inline void set_f3(E1 val){
            f3 = val;
        }
        inline E1& get_f3(){
            return f3;
        }
    
        inline M71* mutable_f4(){
            f4 = new M71();
            return f4;
        }
        inline M71*& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M70->f1: " << f1 << std::endl;
            fout << "M70->f2: " << f2 << std::endl;
            fout << "M70->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
        }
    
        ~M70(){
            if(f4 != nullptr)
                delete f4;
        }
    
        M70(){
           f4 = nullptr;
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) uint64_t f2;
        alignas(8) E1 f3;
        alignas(8) M71* f4;
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
                class alignas(8) M75 : public M_base
                {
                public:
                    inline void set_f1(int64_t val){
                        f1 = val;
                    }
                    inline int64_t& get_f1(){
                        return f1;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M75->f1: " << f1 << std::endl;
                    }
                
                    ~M75(){
                    }
                
                    M75(){
                    }
                
                private:
                    alignas(8) int64_t f1;
                };


                inline M75* mutable_f1(){
                    f1 = new M75();
                    return f1;
                }
                inline M75*& get_f1(){
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
            
                inline void add_f4(int64_t val){
                    f4.push_back(val);
                }
                inline int64_t& get_f4(int idx){
                    return f4[idx];
                }
            
                inline void print_message(std::ofstream &fout){
                    if(f1 != nullptr)
                        f1->print_message(fout);
                    fout << "M74->f2: " << f2 << std::endl;
                    fout << "M74->f3: " << f3 << std::endl;
                    for(auto &f4_val : f4){
                        fout << "M74->f4: " << f4_val << std::endl;
                    }
                }
            
                ~M74(){
                    if(f1 != nullptr)
                        delete f1;
                }
            
                M74(){
                   f1 = nullptr;
                }
            
            private:
                alignas(8) M75* f1;
                alignas(8) int32_t f2;
                alignas(8) int32_t f3;
                alignas(8) std::vector<int64_t> f4;
            };


            inline void set_f1(int64_t val){
                f1 = val;
            }
            inline int64_t& get_f1(){
                return f1;
            }
        
            inline M74* mutable_f2(){
                f2 = new M74();
                return f2;
            }
            inline M74*& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M73->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
            }
        
            ~M73(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M73(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) M74* f2;
        };


        class alignas(8) M76 : public M_base
        {
        public:
            class alignas(8) M77 : public M_base
            {
            public:
                inline void set_f1(float val){
                    f1 = val;
                }
                inline float& get_f1(){
                    return f1;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M77->f1: " << f1 << std::endl;
                }
            
                ~M77(){
                }
            
                M77(){
                }
            
            private:
                alignas(8) float f1;
            };


            class alignas(8) M78 : public M_base
            {
            public:
                class alignas(8) M79 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 33,
                        E1_CONST_2 = 6,
                        E1_CONST_3 = 52,
                        E1_CONST_4 = 118,
                        E1_CONST_5 = 25,
                    };
                    
                    class alignas(8) M80 : public M_base
                    {
                    public:
                        class alignas(8) M81 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 65,
                                E1_CONST_2 = 103,
                                E1_CONST_3 = 48,
                                E1_CONST_4 = 19,
                                E1_CONST_5 = 116,
                            };
                            
                            class alignas(8) M82 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 3,
                                    E1_CONST_2 = 4,
                                    E1_CONST_3 = 102,
                                    E1_CONST_4 = 119,
                                    E1_CONST_5 = 124,
                                };
                                
                                enum E2 {
                                    E2_CONST_1 = 5,
                                    E2_CONST_2 = 8,
                                    E2_CONST_3 = 107,
                                    E2_CONST_4 = 25,
                                    E2_CONST_5 = 26,
                                };
                                
                                inline void set_f1(E1 val){
                                    f1 = val;
                                }
                                inline E1& get_f1(){
                                    return f1;
                                }
                            
                                inline void set_f2(E2 val){
                                    f2 = val;
                                }
                                inline E2& get_f2(){
                                    return f2;
                                }
                            
                                inline void set_f3(string val){
                                    f3 = val;
                                }
                                inline string& get_f3(){
                                    return f3;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M82->f1: " << f1 << std::endl;
                                    fout << "M82->f2: " << f2 << std::endl;
                                    fout << "M82->f3: " << f3 << std::endl;
                                }
                            
                                ~M82(){
                                }
                            
                                M82(){
                                }
                            
                            private:
                                alignas(8) E1 f1;
                                alignas(8) E2 f2;
                                alignas(8) string f3;
                            };


                            class alignas(8) M83 : public M_base
                            {
                            public:
                                class alignas(8) M84 : public M_base
                                {
                                public:
                                    enum E1 {
                                        E1_CONST_1 = 101,
                                        E1_CONST_2 = 70,
                                        E1_CONST_3 = 10,
                                        E1_CONST_4 = 49,
                                        E1_CONST_5 = 63,
                                    };
                                    
                                    enum E2 {
                                        E2_CONST_1 = 67,
                                        E2_CONST_2 = 70,
                                        E2_CONST_3 = 10,
                                        E2_CONST_4 = 106,
                                        E2_CONST_5 = 55,
                                    };
                                    
                                    class alignas(8) M85 : public M_base
                                    {
                                    public:
                                        class alignas(8) M86 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 37,
                                                E1_CONST_2 = 74,
                                                E1_CONST_3 = 75,
                                                E1_CONST_4 = 13,
                                                E1_CONST_5 = 55,
                                            };
                                            
                                            enum E2 {
                                                E2_CONST_1 = 2,
                                                E2_CONST_2 = 67,
                                                E2_CONST_3 = 14,
                                                E2_CONST_4 = 80,
                                                E2_CONST_5 = 92,
                                            };
                                            
                                            class alignas(8) M87 : public M_base
                                            {
                                            public:
                                                enum E1 {
                                                    E1_CONST_1 = 67,
                                                    E1_CONST_2 = 75,
                                                    E1_CONST_3 = 50,
                                                    E1_CONST_4 = 27,
                                                    E1_CONST_5 = 61,
                                                };
                                                
                                                class alignas(8) M88 : public M_base
                                                {
                                                public:
                                                    class alignas(8) M89 : public M_base
                                                    {
                                                    public:
                                                        enum E1 {
                                                            E1_CONST_1 = 72,
                                                            E1_CONST_2 = 115,
                                                            E1_CONST_3 = 53,
                                                            E1_CONST_4 = 93,
                                                            E1_CONST_5 = 126,
                                                        };
                                                        
                                                        inline void set_f1(E1 val){
                                                            f1 = val;
                                                        }
                                                        inline E1& get_f1(){
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
                                                        alignas(8) E1 f1;
                                                        alignas(8) int64_t f2;
                                                        alignas(8) bool f3;
                                                    };


                                                    inline M89* mutable_f1(){
                                                        f1 = new M89();
                                                        return f1;
                                                    }
                                                    inline M89*& get_f1(){
                                                        return f1;
                                                    }
                                                
                                                    inline void set_f2(float val){
                                                        f2 = val;
                                                    }
                                                    inline float& get_f2(){
                                                        return f2;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        if(f1 != nullptr)
                                                            f1->print_message(fout);
                                                        fout << "M88->f2: " << f2 << std::endl;
                                                    }
                                                
                                                    ~M88(){
                                                        if(f1 != nullptr)
                                                            delete f1;
                                                    }
                                                
                                                    M88(){
                                                       f1 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) M89* f1;
                                                    alignas(8) float f2;
                                                };


                                                class alignas(8) M90 : public M_base
                                                {
                                                public:
                                                    inline void set_f1(uint32_t val){
                                                        f1 = val;
                                                    }
                                                    inline uint32_t& get_f1(){
                                                        return f1;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M90->f1: " << f1 << std::endl;
                                                    }
                                                
                                                    ~M90(){
                                                    }
                                                
                                                    M90(){
                                                    }
                                                
                                                private:
                                                    alignas(8) uint32_t f1;
                                                };


                                                inline void set_f1(float val){
                                                    f1 = val;
                                                }
                                                inline float& get_f1(){
                                                    return f1;
                                                }
                                            
                                                inline void set_f2(int64_t val){
                                                    f2 = val;
                                                }
                                                inline int64_t& get_f2(){
                                                    return f2;
                                                }
                                            
                                                inline M88* mutable_f3(){
                                                    f3 = new M88();
                                                    return f3;
                                                }
                                                inline M88*& get_f3(){
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
                                            
                                                inline M90* mutable_f6(){
                                                    f6 = new M90();
                                                    return f6;
                                                }
                                                inline M90*& get_f6(){
                                                    return f6;
                                                }
                                            
                                                inline void set_f7(E1 val){
                                                    f7 = val;
                                                }
                                                inline E1& get_f7(){
                                                    return f7;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    fout << "M87->f1: " << f1 << std::endl;
                                                    fout << "M87->f2: " << f2 << std::endl;
                                                    if(f3 != nullptr)
                                                        f3->print_message(fout);
                                                    fout << "M87->f4: " << f4 << std::endl;
                                                    fout << "M87->f5: " << f5 << std::endl;
                                                    if(f6 != nullptr)
                                                        f6->print_message(fout);
                                                    fout << "M87->f7: " << f7 << std::endl;
                                                }
                                            
                                                ~M87(){
                                                    if(f3 != nullptr)
                                                        delete f3;
                                                    if(f6 != nullptr)
                                                        delete f6;
                                                }
                                            
                                                M87(){
                                                   f3 = nullptr;
                                                   f6 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) float f1;
                                                alignas(8) int64_t f2;
                                                alignas(8) M88* f3;
                                                alignas(8) float f4;
                                                alignas(8) string f5;
                                                alignas(8) M90* f6;
                                                alignas(8) E1 f7;
                                            };


                                            inline void set_f1(E1 val){
                                                f1 = val;
                                            }
                                            inline E1& get_f1(){
                                                return f1;
                                            }
                                        
                                            inline M87* mutable_f2(){
                                                f2 = new M87();
                                                return f2;
                                            }
                                            inline M87*& get_f2(){
                                                return f2;
                                            }
                                        
                                            inline void set_f3(E2 val){
                                                f3 = val;
                                            }
                                            inline E2& get_f3(){
                                                return f3;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M86->f1: " << f1 << std::endl;
                                                if(f2 != nullptr)
                                                    f2->print_message(fout);
                                                fout << "M86->f3: " << f3 << std::endl;
                                            }
                                        
                                            ~M86(){
                                                if(f2 != nullptr)
                                                    delete f2;
                                            }
                                        
                                            M86(){
                                               f2 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) E1 f1;
                                            alignas(8) M87* f2;
                                            alignas(8) E2 f3;
                                        };


                                        inline M86* mutable_f1(){
                                            f1 = new M86();
                                            return f1;
                                        }
                                        inline M86*& get_f1(){
                                            return f1;
                                        }
                                    
                                        inline void set_f2(bool val){
                                            f2 = val;
                                        }
                                        inline bool& get_f2(){
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
                                        alignas(8) bool f2;
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
                                
                                    inline void set_f3(E1 val){
                                        f3 = val;
                                    }
                                    inline E1& get_f3(){
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
                                
                                    inline void set_f6(E2 val){
                                        f6 = val;
                                    }
                                    inline E2& get_f6(){
                                        return f6;
                                    }
                                
                                    inline M85* mutable_f7(){
                                        f7 = new M85();
                                        return f7;
                                    }
                                    inline M85*& get_f7(){
                                        return f7;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M84->f1: " << f1 << std::endl;
                                        fout << "M84->f2: " << f2 << std::endl;
                                        fout << "M84->f3: " << f3 << std::endl;
                                        fout << "M84->f4: " << f4 << std::endl;
                                        fout << "M84->f5: " << f5 << std::endl;
                                        fout << "M84->f6: " << f6 << std::endl;
                                        if(f7 != nullptr)
                                            f7->print_message(fout);
                                    }
                                
                                    ~M84(){
                                        if(f7 != nullptr)
                                            delete f7;
                                    }
                                
                                    M84(){
                                       f7 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) bool f1;
                                    alignas(8) int32_t f2;
                                    alignas(8) E1 f3;
                                    alignas(8) int32_t f4;
                                    alignas(8) float f5;
                                    alignas(8) E2 f6;
                                    alignas(8) M85* f7;
                                };


                                inline M84* mutable_f1(){
                                    f1 = new M84();
                                    return f1;
                                }
                                inline M84*& get_f1(){
                                    return f1;
                                }
                            
                                inline void set_f2(int64_t val){
                                    f2 = val;
                                }
                                inline int64_t& get_f2(){
                                    return f2;
                                }
                            
                                inline void set_f3(float val){
                                    f3 = val;
                                }
                                inline float& get_f3(){
                                    return f3;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    if(f1 != nullptr)
                                        f1->print_message(fout);
                                    fout << "M83->f2: " << f2 << std::endl;
                                    fout << "M83->f3: " << f3 << std::endl;
                                }
                            
                                ~M83(){
                                    if(f1 != nullptr)
                                        delete f1;
                                }
                            
                                M83(){
                                   f1 = nullptr;
                                }
                            
                            private:
                                alignas(8) M84* f1;
                                alignas(8) int64_t f2;
                                alignas(8) float f3;
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
                        
                            inline void set_f3(E1 val){
                                f3 = val;
                            }
                            inline E1& get_f3(){
                                return f3;
                            }
                        
                            inline M82* mutable_f4(){
                                f4 = new M82();
                                return f4;
                            }
                            inline M82*& get_f4(){
                                return f4;
                            }
                        
                            inline M83* mutable_f5(){
                                f5 = new M83();
                                return f5;
                            }
                            inline M83*& get_f5(){
                                return f5;
                            }
                        
                            inline void set_f6(uint32_t val){
                                f6 = val;
                            }
                            inline uint32_t& get_f6(){
                                return f6;
                            }
                        
                            inline void add_f7(string val){
                                f7.push_back(val);
                            }
                            inline string& get_f7(int idx){
                                return f7[idx];
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M81->f1: " << f1 << std::endl;
                                fout << "M81->f2: " << f2 << std::endl;
                                fout << "M81->f3: " << f3 << std::endl;
                                if(f4 != nullptr)
                                    f4->print_message(fout);
                                if(f5 != nullptr)
                                    f5->print_message(fout);
                                fout << "M81->f6: " << f6 << std::endl;
                                for(auto &f7_val : f7){
                                    fout << "M81->f7: " << f7_val << std::endl;
                                }
                            }
                        
                            ~M81(){
                                if(f4 != nullptr)
                                    delete f4;
                                if(f5 != nullptr)
                                    delete f5;
                            }
                        
                            M81(){
                               f4 = nullptr;
                               f5 = nullptr;
                            }
                        
                        private:
                            alignas(8) string f1;
                            alignas(8) bool f2;
                            alignas(8) E1 f3;
                            alignas(8) M82* f4;
                            alignas(8) M83* f5;
                            alignas(8) uint32_t f6;
                            alignas(8) std::vector<string> f7;
                        };


                        inline void set_f1(int64_t val){
                            f1 = val;
                        }
                        inline int64_t& get_f1(){
                            return f1;
                        }
                    
                        inline M81* mutable_f2(){
                            f2 = new M81();
                            return f2;
                        }
                        inline M81*& get_f2(){
                            return f2;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M80->f1: " << f1 << std::endl;
                            if(f2 != nullptr)
                                f2->print_message(fout);
                        }
                    
                        ~M80(){
                            if(f2 != nullptr)
                                delete f2;
                        }
                    
                        M80(){
                           f2 = nullptr;
                        }
                    
                    private:
                        alignas(8) int64_t f1;
                        alignas(8) M81* f2;
                    };


                    inline M80* mutable_f1(){
                        f1 = new M80();
                        return f1;
                    }
                    inline M80*& get_f1(){
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
                
                    inline void print_message(std::ofstream &fout){
                        if(f1 != nullptr)
                            f1->print_message(fout);
                        fout << "M79->f2: " << f2 << std::endl;
                        fout << "M79->f3: " << f3 << std::endl;
                    }
                
                    ~M79(){
                        if(f1 != nullptr)
                            delete f1;
                    }
                
                    M79(){
                       f1 = nullptr;
                    }
                
                private:
                    alignas(8) M80* f1;
                    alignas(8) E1 f2;
                    alignas(8) int32_t f3;
                };


                class alignas(8) M91 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 1,
                        E1_CONST_2 = 5,
                        E1_CONST_3 = 69,
                        E1_CONST_4 = 75,
                        E1_CONST_5 = 115,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 4,
                        E2_CONST_2 = 103,
                        E2_CONST_3 = 74,
                        E2_CONST_4 = 27,
                        E2_CONST_5 = 92,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline void set_f2(E2 val){
                        f2 = val;
                    }
                    inline E2& get_f2(){
                        return f2;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M91->f1: " << f1 << std::endl;
                        fout << "M91->f2: " << f2 << std::endl;
                    }
                
                    ~M91(){
                    }
                
                    M91(){
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) E2 f2;
                };


                class alignas(8) M92 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 1,
                        E1_CONST_2 = 66,
                        E1_CONST_3 = 102,
                        E1_CONST_4 = 40,
                        E1_CONST_5 = 89,
                    };
                    
                    class alignas(8) M93 : public M_base
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
                            fout << "M93->f1: " << f1 << std::endl;
                            fout << "M93->f2: " << f2 << std::endl;
                        }
                    
                        ~M93(){
                        }
                    
                        M93(){
                        }
                    
                    private:
                        alignas(8) int32_t f1;
                        alignas(8) int32_t f2;
                    };


                    inline M93* mutable_f1(){
                        f1 = new M93();
                        return f1;
                    }
                    inline M93*& get_f1(){
                        return f1;
                    }
                
                    inline void set_f2(uint32_t val){
                        f2 = val;
                    }
                    inline uint32_t& get_f2(){
                        return f2;
                    }
                
                    inline void set_f3(E1 val){
                        f3 = val;
                    }
                    inline E1& get_f3(){
                        return f3;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        if(f1 != nullptr)
                            f1->print_message(fout);
                        fout << "M92->f2: " << f2 << std::endl;
                        fout << "M92->f3: " << f3 << std::endl;
                    }
                
                    ~M92(){
                        if(f1 != nullptr)
                            delete f1;
                    }
                
                    M92(){
                       f1 = nullptr;
                    }
                
                private:
                    alignas(8) M93* f1;
                    alignas(8) uint32_t f2;
                    alignas(8) E1 f3;
                };


                class alignas(8) M94 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 46,
                        E1_CONST_2 = 111,
                        E1_CONST_3 = 114,
                        E1_CONST_4 = 2198,
                        E1_CONST_5 = 126,
                    };
                    
                    class alignas(8) M95 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 0,
                            E1_CONST_2 = 33,
                            E1_CONST_3 = 54,
                            E1_CONST_4 = 25,
                            E1_CONST_5 = 122,
                        };
                        
                        enum E2 {
                            E2_CONST_1 = 66,
                            E2_CONST_2 = 84,
                            E2_CONST_3 = 121,
                            E2_CONST_4 = 28,
                            E2_CONST_5 = 95,
                        };
                        
                        enum E3 {
                            E3_CONST_1 = 97,
                            E3_CONST_2 = 1,
                            E3_CONST_3 = 46,
                            E3_CONST_4 = 117,
                            E3_CONST_5 = 90,
                        };
                        
                        enum E4 {
                            E4_CONST_1 = 4,
                            E4_CONST_2 = 105,
                            E4_CONST_3 = 10,
                            E4_CONST_4 = 17,
                            E4_CONST_5 = 121,
                        };
                        
                        class alignas(8) M96 : public M_base
                        {
                        public:
                            inline void set_f1(int32_t val){
                                f1 = val;
                            }
                            inline int32_t& get_f1(){
                                return f1;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M96->f1: " << f1 << std::endl;
                            }
                        
                            ~M96(){
                            }
                        
                            M96(){
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
                    
                        inline M96* mutable_f2(){
                            f2 = new M96();
                            return f2;
                        }
                        inline M96*& get_f2(){
                            return f2;
                        }
                    
                        inline void set_f3(E2 val){
                            f3 = val;
                        }
                        inline E2& get_f3(){
                            return f3;
                        }
                    
                        inline void add_f4(string val){
                            f4.push_back(val);
                        }
                        inline string& get_f4(int idx){
                            return f4[idx];
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
                    
                        inline void set_f7(E3 val){
                            f7 = val;
                        }
                        inline E3& get_f7(){
                            return f7;
                        }
                    
                        inline void set_f8(E4 val){
                            f8 = val;
                        }
                        inline E4& get_f8(){
                            return f8;
                        }
                    
                        inline void set_f9(float val){
                            f9 = val;
                        }
                        inline float& get_f9(){
                            return f9;
                        }
                    
                        inline void set_f10(uint32_t val){
                            f10 = val;
                        }
                        inline uint32_t& get_f10(){
                            return f10;
                        }
                    
                        inline void set_f11(int32_t val){
                            f11 = val;
                        }
                        inline int32_t& get_f11(){
                            return f11;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M95->f1: " << f1 << std::endl;
                            if(f2 != nullptr)
                                f2->print_message(fout);
                            fout << "M95->f3: " << f3 << std::endl;
                            for(auto &f4_val : f4){
                                fout << "M95->f4: " << f4_val << std::endl;
                            }
                            fout << "M95->f5: " << f5 << std::endl;
                            fout << "M95->f6: " << f6 << std::endl;
                            fout << "M95->f7: " << f7 << std::endl;
                            fout << "M95->f8: " << f8 << std::endl;
                            fout << "M95->f9: " << f9 << std::endl;
                            fout << "M95->f10: " << f10 << std::endl;
                            fout << "M95->f11: " << f11 << std::endl;
                        }
                    
                        ~M95(){
                            if(f2 != nullptr)
                                delete f2;
                        }
                    
                        M95(){
                           f2 = nullptr;
                        }
                    
                    private:
                        alignas(8) E1 f1;
                        alignas(8) M96* f2;
                        alignas(8) E2 f3;
                        alignas(8) std::vector<string> f4;
                        alignas(8) bool f5;
                        alignas(8) int32_t f6;
                        alignas(8) E3 f7;
                        alignas(8) E4 f8;
                        alignas(8) float f9;
                        alignas(8) uint32_t f10;
                        alignas(8) int32_t f11;
                    };


                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
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
                    alignas(8) E1 f1;
                    alignas(8) M95* f2;
                };


                class alignas(8) M97 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 106,
                        E1_CONST_2 = 80,
                        E1_CONST_3 = 114,
                        E1_CONST_4 = 62,
                        E1_CONST_5 = 126,
                    };
                    
                    class alignas(8) M98 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 36,
                            E1_CONST_2 = 102,
                            E1_CONST_3 = 73,
                            E1_CONST_4 = 45,
                            E1_CONST_5 = 14,
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
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M98->f1: " << f1 << std::endl;
                            fout << "M98->f2: " << f2 << std::endl;
                        }
                    
                        ~M98(){
                        }
                    
                        M98(){
                        }
                    
                    private:
                        alignas(8) int64_t f1;
                        alignas(8) E1 f2;
                    };


                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline M98* mutable_f2(){
                        f2 = new M98();
                        return f2;
                    }
                    inline M98*& get_f2(){
                        return f2;
                    }
                
                    inline void set_f3(int32_t val){
                        f3 = val;
                    }
                    inline int32_t& get_f3(){
                        return f3;
                    }
                
                    inline void set_f4(uint64_t val){
                        f4 = val;
                    }
                    inline uint64_t& get_f4(){
                        return f4;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M97->f1: " << f1 << std::endl;
                        if(f2 != nullptr)
                            f2->print_message(fout);
                        fout << "M97->f3: " << f3 << std::endl;
                        fout << "M97->f4: " << f4 << std::endl;
                    }
                
                    ~M97(){
                        if(f2 != nullptr)
                            delete f2;
                    }
                
                    M97(){
                       f2 = nullptr;
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) M98* f2;
                    alignas(8) int32_t f3;
                    alignas(8) uint64_t f4;
                };


                inline M79* mutable_f1(){
                    f1 = new M79();
                    return f1;
                }
                inline M79*& get_f1(){
                    return f1;
                }
            
                inline M91* mutable_f2(){
                    f2 = new M91();
                    return f2;
                }
                inline M91*& get_f2(){
                    return f2;
                }
            
                inline M92* mutable_f3(){
                    f3 = new M92();
                    return f3;
                }
                inline M92*& get_f3(){
                    return f3;
                }
            
                inline void set_f4(float val){
                    f4 = val;
                }
                inline float& get_f4(){
                    return f4;
                }
            
                inline void set_f5(uint32_t val){
                    f5 = val;
                }
                inline uint32_t& get_f5(){
                    return f5;
                }
            
                inline M94* mutable_f6(){
                    f6 = new M94();
                    return f6;
                }
                inline M94*& get_f6(){
                    return f6;
                }
            
                inline M97* mutable_f7(){
                    f7 = new M97();
                    return f7;
                }
                inline M97*& get_f7(){
                    return f7;
                }
            
                inline void print_message(std::ofstream &fout){
                    if(f1 != nullptr)
                        f1->print_message(fout);
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    if(f3 != nullptr)
                        f3->print_message(fout);
                    fout << "M78->f4: " << f4 << std::endl;
                    fout << "M78->f5: " << f5 << std::endl;
                    if(f6 != nullptr)
                        f6->print_message(fout);
                    if(f7 != nullptr)
                        f7->print_message(fout);
                }
            
                ~M78(){
                    if(f1 != nullptr)
                        delete f1;
                    if(f2 != nullptr)
                        delete f2;
                    if(f3 != nullptr)
                        delete f3;
                    if(f6 != nullptr)
                        delete f6;
                    if(f7 != nullptr)
                        delete f7;
                }
            
                M78(){
                   f1 = nullptr;
                   f2 = nullptr;
                   f3 = nullptr;
                   f6 = nullptr;
                   f7 = nullptr;
                }
            
            private:
                alignas(8) M79* f1;
                alignas(8) M91* f2;
                alignas(8) M92* f3;
                alignas(8) float f4;
                alignas(8) uint32_t f5;
                alignas(8) M94* f6;
                alignas(8) M97* f7;
            };


            class alignas(8) M99 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 53,
                    E1_CONST_2 = 86,
                    E1_CONST_3 = 89,
                    E1_CONST_4 = 124,
                    E1_CONST_5 = 29,
                };
                
                enum E2 {
                    E2_CONST_1 = 64,
                    E2_CONST_2 = 1,
                    E2_CONST_3 = 102,
                    E2_CONST_4 = 74,
                    E2_CONST_5 = 17,
                };
                
                inline void set_f1(int32_t val){
                    f1 = val;
                }
                inline int32_t& get_f1(){
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
            
                inline void set_f4(E2 val){
                    f4 = val;
                }
                inline E2& get_f4(){
                    return f4;
                }
            
                inline void set_f5(bool val){
                    f5 = val;
                }
                inline bool& get_f5(){
                    return f5;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M99->f1: " << f1 << std::endl;
                    fout << "M99->f2: " << f2 << std::endl;
                    fout << "M99->f3: " << f3 << std::endl;
                    fout << "M99->f4: " << f4 << std::endl;
                    fout << "M99->f5: " << f5 << std::endl;
                }
            
                ~M99(){
                }
            
                M99(){
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) E1 f2;
                alignas(8) int32_t f3;
                alignas(8) E2 f4;
                alignas(8) bool f5;
            };


            inline M77* mutable_f1(){
                f1 = new M77();
                return f1;
            }
            inline M77*& get_f1(){
                return f1;
            }
        
            inline void set_f2(float val){
                f2 = val;
            }
            inline float& get_f2(){
                return f2;
            }
        
            inline M78* mutable_f3(){
                f3 = new M78();
                return f3;
            }
            inline M78*& get_f3(){
                return f3;
            }
        
            inline M99* mutable_f4(){
                f4 = new M99();
                return f4;
            }
            inline M99*& get_f4(){
                return f4;
            }
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                fout << "M76->f2: " << f2 << std::endl;
                if(f3 != nullptr)
                    f3->print_message(fout);
                if(f4 != nullptr)
                    f4->print_message(fout);
            }
        
            ~M76(){
                if(f1 != nullptr)
                    delete f1;
                if(f3 != nullptr)
                    delete f3;
                if(f4 != nullptr)
                    delete f4;
            }
        
            M76(){
               f1 = nullptr;
               f3 = nullptr;
               f4 = nullptr;
            }
        
        private:
            alignas(8) M77* f1;
            alignas(8) float f2;
            alignas(8) M78* f3;
            alignas(8) M99* f4;
        };


        inline void set_f1(int32_t val){
            f1 = val;
        }
        inline int32_t& get_f1(){
            return f1;
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
    
        inline void print_message(std::ofstream &fout){
            fout << "M72->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M72(){
            if(f2 != nullptr)
                delete f2;
            if(f3 != nullptr)
                delete f3;
        }
    
        M72(){
           f2 = nullptr;
           f3 = nullptr;
        }
    
    private:
        alignas(8) int32_t f1;
        alignas(8) M73* f2;
        alignas(8) M76* f3;
    };


    class alignas(8) M100 : public M_base
    {
    public:
        class alignas(8) M101 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 96,
                E1_CONST_2 = 2,
                E1_CONST_3 = 46,
                E1_CONST_4 = 20,
                E1_CONST_5 = 57,
            };
            
            class alignas(8) M102 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 4,
                    E1_CONST_2 = 104,
                    E1_CONST_3 = 107,
                    E1_CONST_4 = 14,
                    E1_CONST_5 = 85,
                };
                
                inline void add_f1(int64_t val){
                    f1.push_back(val);
                }
                inline int64_t& get_f1(int idx){
                    return f1[idx];
                }
            
                inline void set_f2(E1 val){
                    f2 = val;
                }
                inline E1& get_f2(){
                    return f2;
                }
            
                inline void print_message(std::ofstream &fout){
                    for(auto &f1_val : f1){
                        fout << "M102->f1: " << f1_val << std::endl;
                    }
                    fout << "M102->f2: " << f2 << std::endl;
                }
            
                ~M102(){
                }
            
                M102(){
                }
            
            private:
                alignas(8) std::vector<int64_t> f1;
                alignas(8) E1 f2;
            };


            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline M102* mutable_f2(){
                f2 = new M102();
                return f2;
            }
            inline M102*& get_f2(){
                return f2;
            }
        
            inline void set_f3(uint32_t val){
                f3 = val;
            }
            inline uint32_t& get_f3(){
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
        
            inline void set_f6(float val){
                f6 = val;
            }
            inline float& get_f6(){
                return f6;
            }
        
            inline void set_f7(uint32_t val){
                f7 = val;
            }
            inline uint32_t& get_f7(){
                return f7;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M101->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M101->f3: " << f3 << std::endl;
                fout << "M101->f4: " << f4 << std::endl;
                fout << "M101->f5: " << f5 << std::endl;
                fout << "M101->f6: " << f6 << std::endl;
                fout << "M101->f7: " << f7 << std::endl;
            }
        
            ~M101(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M101(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) E1 f1;
            alignas(8) M102* f2;
            alignas(8) uint32_t f3;
            alignas(8) int32_t f4;
            alignas(8) float f5;
            alignas(8) float f6;
            alignas(8) uint32_t f7;
        };


        inline void set_f1(bool val){
            f1 = val;
        }
        inline bool& get_f1(){
            return f1;
        }
    
        inline M101* mutable_f2(){
            f2 = new M101();
            return f2;
        }
        inline M101*& get_f2(){
            return f2;
        }
    
        inline void set_f3(uint32_t val){
            f3 = val;
        }
        inline uint32_t& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M100->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M100->f3: " << f3 << std::endl;
        }
    
        ~M100(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M100(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) bool f1;
        alignas(8) M101* f2;
        alignas(8) uint32_t f3;
    };


    class alignas(8) M103 : public M_base
    {
    public:
        inline void set_f1(uint64_t val){
            f1 = val;
        }
        inline uint64_t& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M103->f1: " << f1 << std::endl;
        }
    
        ~M103(){
        }
    
        M103(){
        }
    
    private:
        alignas(8) uint64_t f1;
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

    inline M69* mutable_f6(){
        f6 = new M69();
        return f6;
    }
    inline M69*& get_f6(){
        return f6;
    }

    inline void set_f7(bool val){
        f7 = val;
    }
    inline bool& get_f7(){
        return f7;
    }

    inline void set_f8(E2 val){
        f8 = val;
    }
    inline E2& get_f8(){
        return f8;
    }

    inline M70* mutable_f9(){
        f9 = new M70();
        return f9;
    }
    inline M70*& get_f9(){
        return f9;
    }

    inline void set_f10(string val){
        f10 = val;
    }
    inline string& get_f10(){
        return f10;
    }

    inline M72* mutable_f11(){
        f11 = new M72();
        return f11;
    }
    inline M72*& get_f11(){
        return f11;
    }

    inline M100* mutable_f12(){
        f12 = new M100();
        return f12;
    }
    inline M100*& get_f12(){
        return f12;
    }

    inline M103* mutable_f13(){
        f13 = new M103();
        return f13;
    }
    inline M103*& get_f13(){
        return f13;
    }

    inline void add_f14(float val){
        f14.push_back(val);
    }
    inline float& get_f14(int idx){
        return f14[idx];
    }

    inline void set_f15(E3 val){
        f15 = val;
    }
    inline E3& get_f15(){
        return f15;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M68->f1: " << f1 << std::endl;
        fout << "M68->f2: " << f2 << std::endl;
        fout << "M68->f3: " << f3 << std::endl;
        fout << "M68->f4: " << f4 << std::endl;
        fout << "M68->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        fout << "M68->f7: " << f7 << std::endl;
        fout << "M68->f8: " << f8 << std::endl;
        if(f9 != nullptr)
            f9->print_message(fout);
        fout << "M68->f10: " << f10 << std::endl;
        if(f11 != nullptr)
            f11->print_message(fout);
        if(f12 != nullptr)
            f12->print_message(fout);
        if(f13 != nullptr)
            f13->print_message(fout);
        for(auto &f14_val : f14){
            fout << "M68->f14: " << f14_val << std::endl;
        }
        fout << "M68->f15: " << f15 << std::endl;
    }

    ~M68(){
        if(f6 != nullptr)
            delete f6;
        if(f9 != nullptr)
            delete f9;
        if(f11 != nullptr)
            delete f11;
        if(f12 != nullptr)
            delete f12;
        if(f13 != nullptr)
            delete f13;
    }

    M68(){
       f6 = nullptr;
       f9 = nullptr;
       f11 = nullptr;
       f12 = nullptr;
       f13 = nullptr;
    }

private:
    alignas(8) float f1;
    alignas(8) E1 f2;
    alignas(8) int64_t f3;
    alignas(8) int32_t f4;
    alignas(8) int32_t f5;
    alignas(8) M69* f6;
    alignas(8) bool f7;
    alignas(8) E2 f8;
    alignas(8) M70* f9;
    alignas(8) string f10;
    alignas(8) M72* f11;
    alignas(8) M100* f12;
    alignas(8) M103* f13;
    alignas(8) std::vector<float> f14;
    alignas(8) E3 f15;
};


class alignas(8) M104 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 3,
        E1_CONST_2 = 107,
        E1_CONST_3 = 47,
        E1_CONST_4 = 118,
        E1_CONST_5 = 90,
    };
    
    enum E2 {
        E2_CONST_1 = 96,
        E2_CONST_2 = 41,
        E2_CONST_3 = 107,
        E2_CONST_4 = 57,
        E2_CONST_5 = 124,
    };
    
    class alignas(8) M105 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 35,
            E1_CONST_2 = 102,
            E1_CONST_3 = 104,
            E1_CONST_4 = 53,
            E1_CONST_5 = 89,
        };
        
        enum E2 {
            E2_CONST_1 = 1,
            E2_CONST_2 = 67,
            E2_CONST_3 = 74,
            E2_CONST_4 = 109,
            E2_CONST_5 = 47,
        };
        
        enum E3 {
            E3_CONST_1 = 35,
            E3_CONST_2 = 37,
            E3_CONST_3 = 113,
            E3_CONST_4 = 60,
            E3_CONST_5 = 94,
        };
        
        class alignas(8) M106 : public M_base
        {
        public:
            class alignas(8) M107 : public M_base
            {
            public:
                class alignas(8) M108 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 12,
                        E1_CONST_2 = 114,
                        E1_CONST_3 = 56,
                        E1_CONST_4 = 89,
                        E1_CONST_5 = 126,
                    };
                    
                    class alignas(8) M109 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 106,
                            E1_CONST_2 = 44,
                            E1_CONST_3 = 78,
                            E1_CONST_4 = 58,
                            E1_CONST_5 = 124,
                        };
                        
                        class alignas(8) M110 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 42,
                                E1_CONST_2 = 106,
                                E1_CONST_3 = 79,
                                E1_CONST_4 = 51,
                                E1_CONST_5 = 121,
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
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M110->f1: " << f1 << std::endl;
                                fout << "M110->f2: " << f2 << std::endl;
                                fout << "M110->f3: " << f3 << std::endl;
                                fout << "M110->f4: " << f4 << std::endl;
                            }
                        
                            ~M110(){
                            }
                        
                            M110(){
                            }
                        
                        private:
                            alignas(8) E1 f1;
                            alignas(8) float f2;
                            alignas(8) int32_t f3;
                            alignas(8) bool f4;
                        };


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
                    
                        inline void set_f3(float val){
                            f3 = val;
                        }
                        inline float& get_f3(){
                            return f3;
                        }
                    
                        inline M110* mutable_f4(){
                            f4 = new M110();
                            return f4;
                        }
                        inline M110*& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(E1 val){
                            f5 = val;
                        }
                        inline E1& get_f5(){
                            return f5;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M109->f1: " << f1 << std::endl;
                            fout << "M109->f2: " << f2 << std::endl;
                            fout << "M109->f3: " << f3 << std::endl;
                            if(f4 != nullptr)
                                f4->print_message(fout);
                            fout << "M109->f5: " << f5 << std::endl;
                        }
                    
                        ~M109(){
                            if(f4 != nullptr)
                                delete f4;
                        }
                    
                        M109(){
                           f4 = nullptr;
                        }
                    
                    private:
                        alignas(8) float f1;
                        alignas(8) int32_t f2;
                        alignas(8) float f3;
                        alignas(8) M110* f4;
                        alignas(8) E1 f5;
                    };


                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline M109* mutable_f2(){
                        f2 = new M109();
                        return f2;
                    }
                    inline M109*& get_f2(){
                        return f2;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M108->f1: " << f1 << std::endl;
                        if(f2 != nullptr)
                            f2->print_message(fout);
                    }
                
                    ~M108(){
                        if(f2 != nullptr)
                            delete f2;
                    }
                
                    M108(){
                       f2 = nullptr;
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) M109* f2;
                };


                class alignas(8) M111 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 99,
                        E1_CONST_2 = 40,
                        E1_CONST_3 = 47,
                        E1_CONST_4 = 82,
                        E1_CONST_5 = 60,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 3,
                        E2_CONST_2 = 100,
                        E2_CONST_3 = 103,
                        E2_CONST_4 = 4367,
                        E2_CONST_5 = 81,
                    };
                    
                    enum E3 {
                        E3_CONST_1 = 7,
                        E3_CONST_2 = 10,
                        E3_CONST_3 = 92,
                        E3_CONST_4 = 24,
                        E3_CONST_5 = 28,
                    };
                    
                    class alignas(8) M112 : public M_base
                    {
                    public:
                        class alignas(8) M113 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 39,
                                E1_CONST_2 = 42,
                                E1_CONST_3 = 112,
                                E1_CONST_4 = 116,
                                E1_CONST_5 = 126,
                            };
                            
                            class alignas(8) M114 : public M_base
                            {
                            public:
                                class alignas(8) M115 : public M_base
                                {
                                public:
                                    class alignas(8) M116 : public M_base
                                    {
                                    public:
                                        enum E1 {
                                            E1_CONST_1 = 98,
                                            E1_CONST_2 = 102,
                                            E1_CONST_3 = 105,
                                            E1_CONST_4 = 118,
                                            E1_CONST_5 = 56,
                                        };
                                        
                                        class alignas(8) M117 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 67,
                                                E1_CONST_2 = 72,
                                                E1_CONST_3 = 51,
                                                E1_CONST_4 = 117,
                                                E1_CONST_5 = 93,
                                            };
                                            
                                            class alignas(8) M118 : public M_base
                                            {
                                            public:
                                                class alignas(8) M119 : public M_base
                                                {
                                                public:
                                                    enum E1 {
                                                        E1_CONST_1 = 70,
                                                        E1_CONST_2 = 42,
                                                        E1_CONST_3 = 76,
                                                        E1_CONST_4 = 117,
                                                        E1_CONST_5 = 119,
                                                    };
                                                    
                                                    class alignas(8) M120 : public M_base
                                                    {
                                                    public:
                                                        inline void add_f1(string val){
                                                            f1.push_back(val);
                                                        }
                                                        inline string& get_f1(int idx){
                                                            return f1[idx];
                                                        }
                                                    
                                                        inline void add_f2(string val){
                                                            f2.push_back(val);
                                                        }
                                                        inline string& get_f2(int idx){
                                                            return f2[idx];
                                                        }
                                                    
                                                        inline void set_f3(float val){
                                                            f3 = val;
                                                        }
                                                        inline float& get_f3(){
                                                            return f3;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            for(auto &f1_val : f1){
                                                                fout << "M120->f1: " << f1_val << std::endl;
                                                            }
                                                            for(auto &f2_val : f2){
                                                                fout << "M120->f2: " << f2_val << std::endl;
                                                            }
                                                            fout << "M120->f3: " << f3 << std::endl;
                                                        }
                                                    
                                                        ~M120(){
                                                        }
                                                    
                                                        M120(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) std::vector<string> f1;
                                                        alignas(8) std::vector<string> f2;
                                                        alignas(8) float f3;
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
                                                
                                                    inline void set_f4(float val){
                                                        f4 = val;
                                                    }
                                                    inline float& get_f4(){
                                                        return f4;
                                                    }
                                                
                                                    inline void set_f5(uint32_t val){
                                                        f5 = val;
                                                    }
                                                    inline uint32_t& get_f5(){
                                                        return f5;
                                                    }
                                                
                                                    inline M120* mutable_f6(){
                                                        f6 = new M120();
                                                        return f6;
                                                    }
                                                    inline M120*& get_f6(){
                                                        return f6;
                                                    }
                                                
                                                    inline void set_f7(uint32_t val){
                                                        f7 = val;
                                                    }
                                                    inline uint32_t& get_f7(){
                                                        return f7;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M119->f1: " << f1 << std::endl;
                                                        fout << "M119->f2: " << f2 << std::endl;
                                                        fout << "M119->f3: " << f3 << std::endl;
                                                        fout << "M119->f4: " << f4 << std::endl;
                                                        fout << "M119->f5: " << f5 << std::endl;
                                                        if(f6 != nullptr)
                                                            f6->print_message(fout);
                                                        fout << "M119->f7: " << f7 << std::endl;
                                                    }
                                                
                                                    ~M119(){
                                                        if(f6 != nullptr)
                                                            delete f6;
                                                    }
                                                
                                                    M119(){
                                                       f6 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) int64_t f1;
                                                    alignas(8) E1 f2;
                                                    alignas(8) int64_t f3;
                                                    alignas(8) float f4;
                                                    alignas(8) uint32_t f5;
                                                    alignas(8) M120* f6;
                                                    alignas(8) uint32_t f7;
                                                };


                                                inline void set_f1(string val){
                                                    f1 = val;
                                                }
                                                inline string& get_f1(){
                                                    return f1;
                                                }
                                            
                                                inline M119* mutable_f2(){
                                                    f2 = new M119();
                                                    return f2;
                                                }
                                                inline M119*& get_f2(){
                                                    return f2;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    fout << "M118->f1: " << f1 << std::endl;
                                                    if(f2 != nullptr)
                                                        f2->print_message(fout);
                                                }
                                            
                                                ~M118(){
                                                    if(f2 != nullptr)
                                                        delete f2;
                                                }
                                            
                                                M118(){
                                                   f2 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) string f1;
                                                alignas(8) M119* f2;
                                            };


                                            inline void set_f1(E1 val){
                                                f1 = val;
                                            }
                                            inline E1& get_f1(){
                                                return f1;
                                            }
                                        
                                            inline M118* mutable_f2(){
                                                f2 = new M118();
                                                return f2;
                                            }
                                            inline M118*& get_f2(){
                                                return f2;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M117->f1: " << f1 << std::endl;
                                                if(f2 != nullptr)
                                                    f2->print_message(fout);
                                            }
                                        
                                            ~M117(){
                                                if(f2 != nullptr)
                                                    delete f2;
                                            }
                                        
                                            M117(){
                                               f2 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) E1 f1;
                                            alignas(8) M118* f2;
                                        };


                                        inline M117* mutable_f1(){
                                            f1 = new M117();
                                            return f1;
                                        }
                                        inline M117*& get_f1(){
                                            return f1;
                                        }
                                    
                                        inline void set_f2(E1 val){
                                            f2 = val;
                                        }
                                        inline E1& get_f2(){
                                            return f2;
                                        }
                                    
                                        inline void print_message(std::ofstream &fout){
                                            if(f1 != nullptr)
                                                f1->print_message(fout);
                                            fout << "M116->f2: " << f2 << std::endl;
                                        }
                                    
                                        ~M116(){
                                            if(f1 != nullptr)
                                                delete f1;
                                        }
                                    
                                        M116(){
                                           f1 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) M117* f1;
                                        alignas(8) E1 f2;
                                    };


                                    inline M116* mutable_f1(){
                                        f1 = new M116();
                                        return f1;
                                    }
                                    inline M116*& get_f1(){
                                        return f1;
                                    }
                                
                                    inline void set_f2(uint32_t val){
                                        f2 = val;
                                    }
                                    inline uint32_t& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        if(f1 != nullptr)
                                            f1->print_message(fout);
                                        fout << "M115->f2: " << f2 << std::endl;
                                    }
                                
                                    ~M115(){
                                        if(f1 != nullptr)
                                            delete f1;
                                    }
                                
                                    M115(){
                                       f1 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) M116* f1;
                                    alignas(8) uint32_t f2;
                                };


                                inline void set_f1(int32_t val){
                                    f1 = val;
                                }
                                inline int32_t& get_f1(){
                                    return f1;
                                }
                            
                                inline M115* mutable_f2(){
                                    f2 = new M115();
                                    return f2;
                                }
                                inline M115*& get_f2(){
                                    return f2;
                                }
                            
                                inline void set_f3(int32_t val){
                                    f3 = val;
                                }
                                inline int32_t& get_f3(){
                                    return f3;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M114->f1: " << f1 << std::endl;
                                    if(f2 != nullptr)
                                        f2->print_message(fout);
                                    fout << "M114->f3: " << f3 << std::endl;
                                }
                            
                                ~M114(){
                                    if(f2 != nullptr)
                                        delete f2;
                                }
                            
                                M114(){
                                   f2 = nullptr;
                                }
                            
                            private:
                                alignas(8) int32_t f1;
                                alignas(8) M115* f2;
                                alignas(8) int32_t f3;
                            };


                            inline M114* mutable_f1(){
                                f1 = new M114();
                                return f1;
                            }
                            inline M114*& get_f1(){
                                return f1;
                            }
                        
                            inline void set_f2(E1 val){
                                f2 = val;
                            }
                            inline E1& get_f2(){
                                return f2;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                if(f1 != nullptr)
                                    f1->print_message(fout);
                                fout << "M113->f2: " << f2 << std::endl;
                            }
                        
                            ~M113(){
                                if(f1 != nullptr)
                                    delete f1;
                            }
                        
                            M113(){
                               f1 = nullptr;
                            }
                        
                        private:
                            alignas(8) M114* f1;
                            alignas(8) E1 f2;
                        };


                        class alignas(8) M121 : public M_base
                        {
                        public:
                            inline void set_f1(float val){
                                f1 = val;
                            }
                            inline float& get_f1(){
                                return f1;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M121->f1: " << f1 << std::endl;
                            }
                        
                            ~M121(){
                            }
                        
                            M121(){
                            }
                        
                        private:
                            alignas(8) float f1;
                        };


                        inline M113* mutable_f1(){
                            f1 = new M113();
                            return f1;
                        }
                        inline M113*& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(float val){
                            f2 = val;
                        }
                        inline float& get_f2(){
                            return f2;
                        }
                    
                        inline M121* mutable_f3(){
                            f3 = new M121();
                            return f3;
                        }
                        inline M121*& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            if(f1 != nullptr)
                                f1->print_message(fout);
                            fout << "M112->f2: " << f2 << std::endl;
                            if(f3 != nullptr)
                                f3->print_message(fout);
                        }
                    
                        ~M112(){
                            if(f1 != nullptr)
                                delete f1;
                            if(f3 != nullptr)
                                delete f3;
                        }
                    
                        M112(){
                           f1 = nullptr;
                           f3 = nullptr;
                        }
                    
                    private:
                        alignas(8) M113* f1;
                        alignas(8) float f2;
                        alignas(8) M121* f3;
                    };


                    inline void set_f1(int32_t val){
                        f1 = val;
                    }
                    inline int32_t& get_f1(){
                        return f1;
                    }
                
                    inline M112* mutable_f2(){
                        f2 = new M112();
                        return f2;
                    }
                    inline M112*& get_f2(){
                        return f2;
                    }
                
                    inline void set_f3(E1 val){
                        f3 = val;
                    }
                    inline E1& get_f3(){
                        return f3;
                    }
                
                    inline void set_f4(int32_t val){
                        f4 = val;
                    }
                    inline int32_t& get_f4(){
                        return f4;
                    }
                
                    inline void set_f5(E2 val){
                        f5 = val;
                    }
                    inline E2& get_f5(){
                        return f5;
                    }
                
                    inline void set_f6(string val){
                        f6 = val;
                    }
                    inline string& get_f6(){
                        return f6;
                    }
                
                    inline void set_f7(E3 val){
                        f7 = val;
                    }
                    inline E3& get_f7(){
                        return f7;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M111->f1: " << f1 << std::endl;
                        if(f2 != nullptr)
                            f2->print_message(fout);
                        fout << "M111->f3: " << f3 << std::endl;
                        fout << "M111->f4: " << f4 << std::endl;
                        fout << "M111->f5: " << f5 << std::endl;
                        fout << "M111->f6: " << f6 << std::endl;
                        fout << "M111->f7: " << f7 << std::endl;
                    }
                
                    ~M111(){
                        if(f2 != nullptr)
                            delete f2;
                    }
                
                    M111(){
                       f2 = nullptr;
                    }
                
                private:
                    alignas(8) int32_t f1;
                    alignas(8) M112* f2;
                    alignas(8) E1 f3;
                    alignas(8) int32_t f4;
                    alignas(8) E2 f5;
                    alignas(8) string f6;
                    alignas(8) E3 f7;
                };


                inline M108* mutable_f1(){
                    f1 = new M108();
                    return f1;
                }
                inline M108*& get_f1(){
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
            
                inline M111* mutable_f4(){
                    f4 = new M111();
                    return f4;
                }
                inline M111*& get_f4(){
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
            
                inline void print_message(std::ofstream &fout){
                    if(f1 != nullptr)
                        f1->print_message(fout);
                    fout << "M107->f2: " << f2 << std::endl;
                    fout << "M107->f3: " << f3 << std::endl;
                    if(f4 != nullptr)
                        f4->print_message(fout);
                    fout << "M107->f5: " << f5 << std::endl;
                    fout << "M107->f6: " << f6 << std::endl;
                }
            
                ~M107(){
                    if(f1 != nullptr)
                        delete f1;
                    if(f4 != nullptr)
                        delete f4;
                }
            
                M107(){
                   f1 = nullptr;
                   f4 = nullptr;
                }
            
            private:
                alignas(8) M108* f1;
                alignas(8) uint32_t f2;
                alignas(8) int32_t f3;
                alignas(8) M111* f4;
                alignas(8) int32_t f5;
                alignas(8) float f6;
            };


            class alignas(8) M122 : public M_base
            {
            public:
                inline void set_f1(int32_t val){
                    f1 = val;
                }
                inline int32_t& get_f1(){
                    return f1;
                }
            
                inline void set_f2(uint32_t val){
                    f2 = val;
                }
                inline uint32_t& get_f2(){
                    return f2;
                }
            
                inline void set_f3(string val){
                    f3 = val;
                }
                inline string& get_f3(){
                    return f3;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M122->f1: " << f1 << std::endl;
                    fout << "M122->f2: " << f2 << std::endl;
                    fout << "M122->f3: " << f3 << std::endl;
                }
            
                ~M122(){
                }
            
                M122(){
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) uint32_t f2;
                alignas(8) string f3;
            };


            inline void set_f1(uint32_t val){
                f1 = val;
            }
            inline uint32_t& get_f1(){
                return f1;
            }
        
            inline M107* mutable_f2(){
                f2 = new M107();
                return f2;
            }
            inline M107*& get_f2(){
                return f2;
            }
        
            inline M122* mutable_f3(){
                f3 = new M122();
                return f3;
            }
            inline M122*& get_f3(){
                return f3;
            }
        
            inline void set_f4(float val){
                f4 = val;
            }
            inline float& get_f4(){
                return f4;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M106->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                if(f3 != nullptr)
                    f3->print_message(fout);
                fout << "M106->f4: " << f4 << std::endl;
            }
        
            ~M106(){
                if(f2 != nullptr)
                    delete f2;
                if(f3 != nullptr)
                    delete f3;
            }
        
            M106(){
               f2 = nullptr;
               f3 = nullptr;
            }
        
        private:
            alignas(8) uint32_t f1;
            alignas(8) M107* f2;
            alignas(8) M122* f3;
            alignas(8) float f4;
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
    
        inline void add_f3(string val){
            f3.push_back(val);
        }
        inline string& get_f3(int idx){
            return f3[idx];
        }
    
        inline void set_f4(E2 val){
            f4 = val;
        }
        inline E2& get_f4(){
            return f4;
        }
    
        inline M106* mutable_f5(){
            f5 = new M106();
            return f5;
        }
        inline M106*& get_f5(){
            return f5;
        }
    
        inline void set_f6(int64_t val){
            f6 = val;
        }
        inline int64_t& get_f6(){
            return f6;
        }
    
        inline void set_f7(E3 val){
            f7 = val;
        }
        inline E3& get_f7(){
            return f7;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M105->f1: " << f1 << std::endl;
            fout << "M105->f2: " << f2 << std::endl;
            for(auto &f3_val : f3){
                fout << "M105->f3: " << f3_val << std::endl;
            }
            fout << "M105->f4: " << f4 << std::endl;
            if(f5 != nullptr)
                f5->print_message(fout);
            fout << "M105->f6: " << f6 << std::endl;
            fout << "M105->f7: " << f7 << std::endl;
        }
    
        ~M105(){
            if(f5 != nullptr)
                delete f5;
        }
    
        M105(){
           f5 = nullptr;
        }
    
    private:
        alignas(8) E1 f1;
        alignas(8) int32_t f2;
        alignas(8) std::vector<string> f3;
        alignas(8) E2 f4;
        alignas(8) M106* f5;
        alignas(8) int64_t f6;
        alignas(8) E3 f7;
    };


    class alignas(8) M123 : public M_base
    {
    public:
        class alignas(8) M124 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 0,
                E1_CONST_2 = 2,
                E1_CONST_3 = 71,
                E1_CONST_4 = 104,
                E1_CONST_5 = 18,
            };
            
            class alignas(8) M125 : public M_base
            {
            public:
                class alignas(8) M126 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 69,
                        E1_CONST_2 = 41,
                        E1_CONST_3 = 11,
                        E1_CONST_4 = 111,
                        E1_CONST_5 = 24,
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
                
                    inline void set_f3(E1 val){
                        f3 = val;
                    }
                    inline E1& get_f3(){
                        return f3;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M126->f1: " << f1 << std::endl;
                        fout << "M126->f2: " << f2 << std::endl;
                        fout << "M126->f3: " << f3 << std::endl;
                    }
                
                    ~M126(){
                    }
                
                    M126(){
                    }
                
                private:
                    alignas(8) uint32_t f1;
                    alignas(8) int32_t f2;
                    alignas(8) E1 f3;
                };


                inline M126* mutable_f1(){
                    f1 = new M126();
                    return f1;
                }
                inline M126*& get_f1(){
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
                    fout << "M125->f2: " << f2 << std::endl;
                }
            
                ~M125(){
                    if(f1 != nullptr)
                        delete f1;
                }
            
                M125(){
                   f1 = nullptr;
                }
            
            private:
                alignas(8) M126* f1;
                alignas(8) int32_t f2;
            };


            class alignas(8) M127 : public M_base
            {
            public:
                class alignas(8) M128 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 3,
                        E1_CONST_2 = 48,
                        E1_CONST_3 = 58,
                        E1_CONST_4 = 29,
                        E1_CONST_5 = 94,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M128->f1: " << f1 << std::endl;
                    }
                
                    ~M128(){
                    }
                
                    M128(){
                    }
                
                private:
                    alignas(8) E1 f1;
                };


                inline void set_f1(int32_t val){
                    f1 = val;
                }
                inline int32_t& get_f1(){
                    return f1;
                }
            
                inline M128* mutable_f2(){
                    f2 = new M128();
                    return f2;
                }
                inline M128*& get_f2(){
                    return f2;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M127->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
                }
            
                ~M127(){
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M127(){
                   f2 = nullptr;
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) M128* f2;
            };


            inline void set_f1(float val){
                f1 = val;
            }
            inline float& get_f1(){
                return f1;
            }
        
            inline M125* mutable_f2(){
                f2 = new M125();
                return f2;
            }
            inline M125*& get_f2(){
                return f2;
            }
        
            inline M127* mutable_f3(){
                f3 = new M127();
                return f3;
            }
            inline M127*& get_f3(){
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
        
            inline void set_f6(E1 val){
                f6 = val;
            }
            inline E1& get_f6(){
                return f6;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M124->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                if(f3 != nullptr)
                    f3->print_message(fout);
                fout << "M124->f4: " << f4 << std::endl;
                fout << "M124->f5: " << f5 << std::endl;
                fout << "M124->f6: " << f6 << std::endl;
            }
        
            ~M124(){
                if(f2 != nullptr)
                    delete f2;
                if(f3 != nullptr)
                    delete f3;
            }
        
            M124(){
               f2 = nullptr;
               f3 = nullptr;
            }
        
        private:
            alignas(8) float f1;
            alignas(8) M125* f2;
            alignas(8) M127* f3;
            alignas(8) bool f4;
            alignas(8) bool f5;
            alignas(8) E1 f6;
        };


        inline void set_f1(uint32_t val){
            f1 = val;
        }
        inline uint32_t& get_f1(){
            return f1;
        }
    
        inline M124* mutable_f2(){
            f2 = new M124();
            return f2;
        }
        inline M124*& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M123->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
        }
    
        ~M123(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M123(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) uint32_t f1;
        alignas(8) M124* f2;
    };


    inline void set_f1(int32_t val){
        f1 = val;
    }
    inline int32_t& get_f1(){
        return f1;
    }

    inline M105* mutable_f2(){
        f2 = new M105();
        return f2;
    }
    inline M105*& get_f2(){
        return f2;
    }

    inline void set_f3(uint32_t val){
        f3 = val;
    }
    inline uint32_t& get_f3(){
        return f3;
    }

    inline M123* mutable_f4(){
        f4 = new M123();
        return f4;
    }
    inline M123*& get_f4(){
        return f4;
    }

    inline void set_f5(int64_t val){
        f5 = val;
    }
    inline int64_t& get_f5(){
        return f5;
    }

    inline void add_f6(int32_t val){
        f6.push_back(val);
    }
    inline int32_t& get_f6(int idx){
        return f6[idx];
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

    inline void set_f9(E2 val){
        f9 = val;
    }
    inline E2& get_f9(){
        return f9;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M104->f1: " << f1 << std::endl;
        if(f2 != nullptr)
            f2->print_message(fout);
        fout << "M104->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        fout << "M104->f5: " << f5 << std::endl;
        for(auto &f6_val : f6){
            fout << "M104->f6: " << f6_val << std::endl;
        }
        fout << "M104->f7: " << f7 << std::endl;
        fout << "M104->f8: " << f8 << std::endl;
        fout << "M104->f9: " << f9 << std::endl;
    }

    ~M104(){
        if(f2 != nullptr)
            delete f2;
        if(f4 != nullptr)
            delete f4;
    }

    M104(){
       f2 = nullptr;
       f4 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) M105* f2;
    alignas(8) uint32_t f3;
    alignas(8) M123* f4;
    alignas(8) int64_t f5;
    alignas(8) std::vector<int32_t> f6;
    alignas(8) string f7;
    alignas(8) E1 f8;
    alignas(8) E2 f9;
};


class alignas(8) M129 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 34,
        E1_CONST_2 = 4,
        E1_CONST_3 = 48,
        E1_CONST_4 = 113,
        E1_CONST_5 = 25,
    };
    
    class alignas(8) M130 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 2,
            E1_CONST_2 = 67,
            E1_CONST_3 = 71,
            E1_CONST_4 = 104,
            E1_CONST_5 = 88,
        };
        
        enum E2 {
            E2_CONST_1 = 101,
            E2_CONST_2 = 14,
            E2_CONST_3 = 117,
            E2_CONST_4 = 86,
            E2_CONST_5 = 126,
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
    
        inline void set_f3(E2 val){
            f3 = val;
        }
        inline E2& get_f3(){
            return f3;
        }
    
        inline void set_f4(bool val){
            f4 = val;
        }
        inline bool& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M130->f1: " << f1 << std::endl;
            fout << "M130->f2: " << f2 << std::endl;
            fout << "M130->f3: " << f3 << std::endl;
            fout << "M130->f4: " << f4 << std::endl;
        }
    
        ~M130(){
        }
    
        M130(){
        }
    
    private:
        alignas(8) E1 f1;
        alignas(8) int32_t f2;
        alignas(8) E2 f3;
        alignas(8) bool f4;
    };


    class alignas(8) M131 : public M_base
    {
    public:
        class alignas(8) M132 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 77,
                E1_CONST_2 = 109,
                E1_CONST_3 = 110,
                E1_CONST_4 = 92,
                E1_CONST_5 = 29,
            };
            
            class alignas(8) M133 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 101,
                    E1_CONST_2 = 104,
                    E1_CONST_3 = 106,
                    E1_CONST_4 = 77,
                    E1_CONST_5 = 91,
                };
                
                class alignas(8) M134 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 33,
                        E1_CONST_2 = 41,
                        E1_CONST_3 = 47,
                        E1_CONST_4 = 124,
                        E1_CONST_5 = 93,
                    };
                    
                    class alignas(8) M135 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 10,
                            E1_CONST_2 = 107,
                            E1_CONST_3 = 47,
                            E1_CONST_4 = 83,
                            E1_CONST_5 = 59,
                        };
                        
                        enum E2 {
                            E2_CONST_1 = 32,
                            E2_CONST_2 = 122,
                            E2_CONST_3 = 73,
                            E2_CONST_4 = 89,
                            E2_CONST_5 = 26,
                        };
                        
                        enum E3 {
                            E3_CONST_1 = 40,
                            E3_CONST_2 = 79,
                            E3_CONST_3 = 81,
                            E3_CONST_4 = 25,
                            E3_CONST_5 = 29,
                        };
                        
                        enum E4 {
                            E4_CONST_1 = 75,
                            E4_CONST_2 = 112,
                            E4_CONST_3 = 87,
                            E4_CONST_4 = 119,
                            E4_CONST_5 = 90,
                        };
                        
                        inline void set_f1(bool val){
                            f1 = val;
                        }
                        inline bool& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(E1 val){
                            f2 = val;
                        }
                        inline E1& get_f2(){
                            return f2;
                        }
                    
                        inline void set_f3(E2 val){
                            f3 = val;
                        }
                        inline E2& get_f3(){
                            return f3;
                        }
                    
                        inline void set_f4(string val){
                            f4 = val;
                        }
                        inline string& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(E3 val){
                            f5 = val;
                        }
                        inline E3& get_f5(){
                            return f5;
                        }
                    
                        inline void set_f6(int32_t val){
                            f6 = val;
                        }
                        inline int32_t& get_f6(){
                            return f6;
                        }
                    
                        inline void set_f7(uint32_t val){
                            f7 = val;
                        }
                        inline uint32_t& get_f7(){
                            return f7;
                        }
                    
                        inline void set_f8(E4 val){
                            f8 = val;
                        }
                        inline E4& get_f8(){
                            return f8;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M135->f1: " << f1 << std::endl;
                            fout << "M135->f2: " << f2 << std::endl;
                            fout << "M135->f3: " << f3 << std::endl;
                            fout << "M135->f4: " << f4 << std::endl;
                            fout << "M135->f5: " << f5 << std::endl;
                            fout << "M135->f6: " << f6 << std::endl;
                            fout << "M135->f7: " << f7 << std::endl;
                            fout << "M135->f8: " << f8 << std::endl;
                        }
                    
                        ~M135(){
                        }
                    
                        M135(){
                        }
                    
                    private:
                        alignas(8) bool f1;
                        alignas(8) E1 f2;
                        alignas(8) E2 f3;
                        alignas(8) string f4;
                        alignas(8) E3 f5;
                        alignas(8) int32_t f6;
                        alignas(8) uint32_t f7;
                        alignas(8) E4 f8;
                    };


                    inline void set_f1(int32_t val){
                        f1 = val;
                    }
                    inline int32_t& get_f1(){
                        return f1;
                    }
                
                    inline M135* mutable_f2(){
                        f2 = new M135();
                        return f2;
                    }
                    inline M135*& get_f2(){
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
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M134->f1: " << f1 << std::endl;
                        if(f2 != nullptr)
                            f2->print_message(fout);
                        fout << "M134->f3: " << f3 << std::endl;
                        fout << "M134->f4: " << f4 << std::endl;
                    }
                
                    ~M134(){
                        if(f2 != nullptr)
                            delete f2;
                    }
                
                    M134(){
                       f2 = nullptr;
                    }
                
                private:
                    alignas(8) int32_t f1;
                    alignas(8) M135* f2;
                    alignas(8) float f3;
                    alignas(8) E1 f4;
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
            
                inline void set_f3(bool val){
                    f3 = val;
                }
                inline bool& get_f3(){
                    return f3;
                }
            
                inline void set_f4(float val){
                    f4 = val;
                }
                inline float& get_f4(){
                    return f4;
                }
            
                inline M134* mutable_f5(){
                    f5 = new M134();
                    return f5;
                }
                inline M134*& get_f5(){
                    return f5;
                }
            
                inline void set_f6(string val){
                    f6 = val;
                }
                inline string& get_f6(){
                    return f6;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M133->f1: " << f1 << std::endl;
                    fout << "M133->f2: " << f2 << std::endl;
                    fout << "M133->f3: " << f3 << std::endl;
                    fout << "M133->f4: " << f4 << std::endl;
                    if(f5 != nullptr)
                        f5->print_message(fout);
                    fout << "M133->f6: " << f6 << std::endl;
                }
            
                ~M133(){
                    if(f5 != nullptr)
                        delete f5;
                }
            
                M133(){
                   f5 = nullptr;
                }
            
            private:
                alignas(8) E1 f1;
                alignas(8) float f2;
                alignas(8) bool f3;
                alignas(8) float f4;
                alignas(8) M134* f5;
                alignas(8) string f6;
            };


            class alignas(8) M136 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 65,
                    E1_CONST_2 = 2,
                    E1_CONST_3 = 121,
                    E1_CONST_4 = 126,
                    E1_CONST_5 = 95,
                };
                
                class alignas(8) M137 : public M_base
                {
                public:
                    class alignas(8) M138 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 99,
                            E1_CONST_2 = 77,
                            E1_CONST_3 = 17,
                            E1_CONST_4 = 115,
                            E1_CONST_5 = 22,
                        };
                        
                        inline void set_f1(E1 val){
                            f1 = val;
                        }
                        inline E1& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(uint32_t val){
                            f2 = val;
                        }
                        inline uint32_t& get_f2(){
                            return f2;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M138->f1: " << f1 << std::endl;
                            fout << "M138->f2: " << f2 << std::endl;
                        }
                    
                        ~M138(){
                        }
                    
                        M138(){
                        }
                    
                    private:
                        alignas(8) E1 f1;
                        alignas(8) uint32_t f2;
                    };


                    class alignas(8) M139 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 99,
                            E1_CONST_2 = 38,
                            E1_CONST_3 = 16,
                            E1_CONST_4 = 86,
                            E1_CONST_5 = 120,
                        };
                        
                        enum E2 {
                            E2_CONST_1 = 98,
                            E2_CONST_2 = 4,
                            E2_CONST_3 = 45,
                            E2_CONST_4 = 21,
                            E2_CONST_5 = 23,
                        };
                        
                        enum E3 {
                            E3_CONST_1 = 70,
                            E3_CONST_2 = 10,
                            E3_CONST_3 = 11,
                            E3_CONST_4 = 123,
                            E3_CONST_5 = 93,
                        };
                        
                        class alignas(8) M140 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 100,
                                E1_CONST_2 = 107,
                                E1_CONST_3 = 49,
                                E1_CONST_4 = 92,
                                E1_CONST_5 = 94,
                            };
                            
                            enum E2 {
                                E2_CONST_1 = 109,
                                E2_CONST_2 = 110,
                                E2_CONST_3 = 118,
                                E2_CONST_4 = 22,
                                E2_CONST_5 = 89,
                            };
                            
                            class alignas(8) M141 : public M_base
                            {
                            public:
                                class alignas(8) M142 : public M_base
                                {
                                public:
                                    class alignas(8) M143 : public M_base
                                    {
                                    public:
                                        enum E1 {
                                            E1_CONST_1 = 100,
                                            E1_CONST_2 = 5,
                                            E1_CONST_3 = 80,
                                            E1_CONST_4 = 81,
                                            E1_CONST_5 = 20,
                                        };
                                        
                                        enum E2 {
                                            E2_CONST_1 = 64,
                                            E2_CONST_2 = 86,
                                            E2_CONST_3 = 124,
                                            E2_CONST_4 = 30,
                                            E2_CONST_5 = 95,
                                        };
                                        
                                        enum E3 {
                                            E3_CONST_1 = 97,
                                            E3_CONST_2 = 6,
                                            E3_CONST_3 = 109,
                                            E3_CONST_4 = 17,
                                            E3_CONST_5 = 114,
                                        };
                                        
                                        class alignas(8) M144 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 97,
                                                E1_CONST_2 = 2,
                                                E1_CONST_3 = 45,
                                                E1_CONST_4 = 113,
                                                E1_CONST_5 = 49,
                                            };
                                            
                                            enum E2 {
                                                E2_CONST_1 = 103,
                                                E2_CONST_2 = 105,
                                                E2_CONST_3 = 79,
                                                E2_CONST_4 = 15,
                                                E2_CONST_5 = 86,
                                            };
                                            
                                            enum E3 {
                                                E3_CONST_1 = 65,
                                                E3_CONST_2 = 109,
                                                E3_CONST_3 = 114,
                                                E3_CONST_4 = 60,
                                                E3_CONST_5 = 61,
                                            };
                                            
                                            enum E4 {
                                                E4_CONST_1 = 64,
                                                E4_CONST_2 = 79,
                                                E4_CONST_3 = 114,
                                                E4_CONST_4 = 24,
                                                E4_CONST_5 = 56,
                                            };
                                            
                                            enum E5 {
                                                E5_CONST_1 = 104,
                                                E5_CONST_2 = 46,
                                                E5_CONST_3 = 51,
                                                E5_CONST_4 = 126,
                                                E5_CONST_5 = 63,
                                            };
                                            
                                            enum E6 {
                                                E6_CONST_1 = 102,
                                                E6_CONST_2 = 109,
                                                E6_CONST_3 = 50,
                                                E6_CONST_4 = 115,
                                                E6_CONST_5 = 54,
                                            };
                                            
                                            class alignas(8) M145 : public M_base
                                            {
                                            public:
                                                enum E1 {
                                                    E1_CONST_1 = 68,
                                                    E1_CONST_2 = 41,
                                                    E1_CONST_3 = 17,
                                                    E1_CONST_4 = 119,
                                                    E1_CONST_5 = 30,
                                                };
                                                
                                                class alignas(8) M146 : public M_base
                                                {
                                                public:
                                                    enum E1 {
                                                        E1_CONST_1 = 2,
                                                        E1_CONST_2 = 6,
                                                        E1_CONST_3 = 87,
                                                        E1_CONST_4 = 56,
                                                        E1_CONST_5 = 89,
                                                    };
                                                    
                                                    inline void set_f1(E1 val){
                                                        f1 = val;
                                                    }
                                                    inline E1& get_f1(){
                                                        return f1;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M146->f1: " << f1 << std::endl;
                                                    }
                                                
                                                    ~M146(){
                                                    }
                                                
                                                    M146(){
                                                    }
                                                
                                                private:
                                                    alignas(8) E1 f1;
                                                };


                                                inline M146* mutable_f1(){
                                                    f1 = new M146();
                                                    return f1;
                                                }
                                                inline M146*& get_f1(){
                                                    return f1;
                                                }
                                            
                                                inline void set_f2(E1 val){
                                                    f2 = val;
                                                }
                                                inline E1& get_f2(){
                                                    return f2;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    if(f1 != nullptr)
                                                        f1->print_message(fout);
                                                    fout << "M145->f2: " << f2 << std::endl;
                                                }
                                            
                                                ~M145(){
                                                    if(f1 != nullptr)
                                                        delete f1;
                                                }
                                            
                                                M145(){
                                                   f1 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) M146* f1;
                                                alignas(8) E1 f2;
                                            };


                                            inline void set_f1(E1 val){
                                                f1 = val;
                                            }
                                            inline E1& get_f1(){
                                                return f1;
                                            }
                                        
                                            inline void set_f2(E2 val){
                                                f2 = val;
                                            }
                                            inline E2& get_f2(){
                                                return f2;
                                            }
                                        
                                            inline void set_f3(E3 val){
                                                f3 = val;
                                            }
                                            inline E3& get_f3(){
                                                return f3;
                                            }
                                        
                                            inline void set_f4(E4 val){
                                                f4 = val;
                                            }
                                            inline E4& get_f4(){
                                                return f4;
                                            }
                                        
                                            inline void set_f5(bool val){
                                                f5 = val;
                                            }
                                            inline bool& get_f5(){
                                                return f5;
                                            }
                                        
                                            inline void set_f6(E5 val){
                                                f6 = val;
                                            }
                                            inline E5& get_f6(){
                                                return f6;
                                            }
                                        
                                            inline M145* mutable_f7(){
                                                f7 = new M145();
                                                return f7;
                                            }
                                            inline M145*& get_f7(){
                                                return f7;
                                            }
                                        
                                            inline void set_f8(float val){
                                                f8 = val;
                                            }
                                            inline float& get_f8(){
                                                return f8;
                                            }
                                        
                                            inline void set_f9(bool val){
                                                f9 = val;
                                            }
                                            inline bool& get_f9(){
                                                return f9;
                                            }
                                        
                                            inline void set_f10(int32_t val){
                                                f10 = val;
                                            }
                                            inline int32_t& get_f10(){
                                                return f10;
                                            }
                                        
                                            inline void set_f11(E6 val){
                                                f11 = val;
                                            }
                                            inline E6& get_f11(){
                                                return f11;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M144->f1: " << f1 << std::endl;
                                                fout << "M144->f2: " << f2 << std::endl;
                                                fout << "M144->f3: " << f3 << std::endl;
                                                fout << "M144->f4: " << f4 << std::endl;
                                                fout << "M144->f5: " << f5 << std::endl;
                                                fout << "M144->f6: " << f6 << std::endl;
                                                if(f7 != nullptr)
                                                    f7->print_message(fout);
                                                fout << "M144->f8: " << f8 << std::endl;
                                                fout << "M144->f9: " << f9 << std::endl;
                                                fout << "M144->f10: " << f10 << std::endl;
                                                fout << "M144->f11: " << f11 << std::endl;
                                            }
                                        
                                            ~M144(){
                                                if(f7 != nullptr)
                                                    delete f7;
                                            }
                                        
                                            M144(){
                                               f7 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) E1 f1;
                                            alignas(8) E2 f2;
                                            alignas(8) E3 f3;
                                            alignas(8) E4 f4;
                                            alignas(8) bool f5;
                                            alignas(8) E5 f6;
                                            alignas(8) M145* f7;
                                            alignas(8) float f8;
                                            alignas(8) bool f9;
                                            alignas(8) int32_t f10;
                                            alignas(8) E6 f11;
                                        };


                                        class alignas(8) M147 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 32,
                                                E1_CONST_2 = 70,
                                                E1_CONST_3 = 12,
                                                E1_CONST_4 = 48,
                                                E1_CONST_5 = 123,
                                            };
                                            
                                            class alignas(8) M148 : public M_base
                                            {
                                            public:
                                                enum E1 {
                                                    E1_CONST_1 = 34,
                                                    E1_CONST_2 = 110,
                                                    E1_CONST_3 = 14,
                                                    E1_CONST_4 = 113,
                                                    E1_CONST_5 = 114,
                                                };
                                                
                                                class alignas(8) M149 : public M_base
                                                {
                                                public:
                                                    class alignas(8) M150 : public M_base
                                                    {
                                                    public:
                                                        enum E1 {
                                                            E1_CONST_1 = 28,
                                                            E1_CONST_2 = 46,
                                                            E1_CONST_3 = 116,
                                                            E1_CONST_4 = 59,
                                                            E1_CONST_5 = 60,
                                                        };
                                                        
                                                        enum E2 {
                                                            E2_CONST_1 = 2,
                                                            E2_CONST_2 = 4,
                                                            E2_CONST_3 = 9,
                                                            E2_CONST_4 = 108,
                                                            E2_CONST_5 = 109,
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
                                                    
                                                        inline void set_f3(E2 val){
                                                            f3 = val;
                                                        }
                                                        inline E2& get_f3(){
                                                            return f3;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M150->f1: " << f1 << std::endl;
                                                            fout << "M150->f2: " << f2 << std::endl;
                                                            fout << "M150->f3: " << f3 << std::endl;
                                                        }
                                                    
                                                        ~M150(){
                                                        }
                                                    
                                                        M150(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) float f1;
                                                        alignas(8) E1 f2;
                                                        alignas(8) E2 f3;
                                                    };


                                                    inline M150* mutable_f1(){
                                                        f1 = new M150();
                                                        return f1;
                                                    }
                                                    inline M150*& get_f1(){
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
                                                        fout << "M149->f2: " << f2 << std::endl;
                                                    }
                                                
                                                    ~M149(){
                                                        if(f1 != nullptr)
                                                            delete f1;
                                                    }
                                                
                                                    M149(){
                                                       f1 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) M150* f1;
                                                    alignas(8) int64_t f2;
                                                };


                                                inline M149* mutable_f1(){
                                                    f1 = new M149();
                                                    return f1;
                                                }
                                                inline M149*& get_f1(){
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
                                                    if(f1 != nullptr)
                                                        f1->print_message(fout);
                                                    fout << "M148->f2: " << f2 << std::endl;
                                                    fout << "M148->f3: " << f3 << std::endl;
                                                }
                                            
                                                ~M148(){
                                                    if(f1 != nullptr)
                                                        delete f1;
                                                }
                                            
                                                M148(){
                                                   f1 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) M149* f1;
                                                alignas(8) bool f2;
                                                alignas(8) E1 f3;
                                            };


                                            inline void set_f1(E1 val){
                                                f1 = val;
                                            }
                                            inline E1& get_f1(){
                                                return f1;
                                            }
                                        
                                            inline M148* mutable_f2(){
                                                f2 = new M148();
                                                return f2;
                                            }
                                            inline M148*& get_f2(){
                                                return f2;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M147->f1: " << f1 << std::endl;
                                                if(f2 != nullptr)
                                                    f2->print_message(fout);
                                            }
                                        
                                            ~M147(){
                                                if(f2 != nullptr)
                                                    delete f2;
                                            }
                                        
                                            M147(){
                                               f2 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) E1 f1;
                                            alignas(8) M148* f2;
                                        };


                                        inline void set_f1(int32_t val){
                                            f1 = val;
                                        }
                                        inline int32_t& get_f1(){
                                            return f1;
                                        }
                                    
                                        inline M144* mutable_f2(){
                                            f2 = new M144();
                                            return f2;
                                        }
                                        inline M144*& get_f2(){
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
                                    
                                        inline void add_f5(E2 val){
                                            f5.push_back(val);
                                        }
                                        inline E2& get_f5(int idx){
                                            return f5[idx];
                                        }
                                    
                                        inline void set_f6(E3 val){
                                            f6 = val;
                                        }
                                        inline E3& get_f6(){
                                            return f6;
                                        }
                                    
                                        inline void set_f7(float val){
                                            f7 = val;
                                        }
                                        inline float& get_f7(){
                                            return f7;
                                        }
                                    
                                        inline void set_f8(float val){
                                            f8 = val;
                                        }
                                        inline float& get_f8(){
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
                                    
                                        inline void set_f11(uint32_t val){
                                            f11 = val;
                                        }
                                        inline uint32_t& get_f11(){
                                            return f11;
                                        }
                                    
                                        inline M147* mutable_f12(){
                                            f12 = new M147();
                                            return f12;
                                        }
                                        inline M147*& get_f12(){
                                            return f12;
                                        }
                                    
                                        inline void print_message(std::ofstream &fout){
                                            fout << "M143->f1: " << f1 << std::endl;
                                            if(f2 != nullptr)
                                                f2->print_message(fout);
                                            fout << "M143->f3: " << f3 << std::endl;
                                            fout << "M143->f4: " << f4 << std::endl;
                                            for(auto &f5_val : f5){
                                                fout << "M143->f5: " << f5_val << std::endl;
                                            }
                                            fout << "M143->f6: " << f6 << std::endl;
                                            fout << "M143->f7: " << f7 << std::endl;
                                            fout << "M143->f8: " << f8 << std::endl;
                                            fout << "M143->f9: " << f9 << std::endl;
                                            fout << "M143->f10: " << f10 << std::endl;
                                            fout << "M143->f11: " << f11 << std::endl;
                                            if(f12 != nullptr)
                                                f12->print_message(fout);
                                        }
                                    
                                        ~M143(){
                                            if(f2 != nullptr)
                                                delete f2;
                                            if(f12 != nullptr)
                                                delete f12;
                                        }
                                    
                                        M143(){
                                           f2 = nullptr;
                                           f12 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) int32_t f1;
                                        alignas(8) M144* f2;
                                        alignas(8) int32_t f3;
                                        alignas(8) E1 f4;
                                        alignas(8) std::vector<E2> f5;
                                        alignas(8) E3 f6;
                                        alignas(8) float f7;
                                        alignas(8) float f8;
                                        alignas(8) string f9;
                                        alignas(8) bool f10;
                                        alignas(8) uint32_t f11;
                                        alignas(8) M147* f12;
                                    };


                                    inline void set_f1(int32_t val){
                                        f1 = val;
                                    }
                                    inline int32_t& get_f1(){
                                        return f1;
                                    }
                                
                                    inline M143* mutable_f2(){
                                        f2 = new M143();
                                        return f2;
                                    }
                                    inline M143*& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void set_f3(int64_t val){
                                        f3 = val;
                                    }
                                    inline int64_t& get_f3(){
                                        return f3;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M142->f1: " << f1 << std::endl;
                                        if(f2 != nullptr)
                                            f2->print_message(fout);
                                        fout << "M142->f3: " << f3 << std::endl;
                                    }
                                
                                    ~M142(){
                                        if(f2 != nullptr)
                                            delete f2;
                                    }
                                
                                    M142(){
                                       f2 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) int32_t f1;
                                    alignas(8) M143* f2;
                                    alignas(8) int64_t f3;
                                };


                                inline void set_f1(uint32_t val){
                                    f1 = val;
                                }
                                inline uint32_t& get_f1(){
                                    return f1;
                                }
                            
                                inline M142* mutable_f2(){
                                    f2 = new M142();
                                    return f2;
                                }
                                inline M142*& get_f2(){
                                    return f2;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M141->f1: " << f1 << std::endl;
                                    if(f2 != nullptr)
                                        f2->print_message(fout);
                                }
                            
                                ~M141(){
                                    if(f2 != nullptr)
                                        delete f2;
                                }
                            
                                M141(){
                                   f2 = nullptr;
                                }
                            
                            private:
                                alignas(8) uint32_t f1;
                                alignas(8) M142* f2;
                            };


                            class alignas(8) M151 : public M_base
                            {
                            public:
                                inline void set_f1(bool val){
                                    f1 = val;
                                }
                                inline bool& get_f1(){
                                    return f1;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M151->f1: " << f1 << std::endl;
                                }
                            
                                ~M151(){
                                }
                            
                                M151(){
                                }
                            
                            private:
                                alignas(8) bool f1;
                            };


                            class alignas(8) M152 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 72,
                                    E1_CONST_2 = 9,
                                    E1_CONST_3 = 78,
                                    E1_CONST_4 = 48,
                                    E1_CONST_5 = 119,
                                };
                                
                                inline void set_f1(E1 val){
                                    f1 = val;
                                }
                                inline E1& get_f1(){
                                    return f1;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M152->f1: " << f1 << std::endl;
                                }
                            
                                ~M152(){
                                }
                            
                                M152(){
                                }
                            
                            private:
                                alignas(8) E1 f1;
                            };


                            inline void set_f1(E1 val){
                                f1 = val;
                            }
                            inline E1& get_f1(){
                                return f1;
                            }
                        
                            inline M141* mutable_f2(){
                                f2 = new M141();
                                return f2;
                            }
                            inline M141*& get_f2(){
                                return f2;
                            }
                        
                            inline void add_f3(float val){
                                f3.push_back(val);
                            }
                            inline float& get_f3(int idx){
                                return f3[idx];
                            }
                        
                            inline M151* mutable_f4(){
                                f4 = new M151();
                                return f4;
                            }
                            inline M151*& get_f4(){
                                return f4;
                            }
                        
                            inline void set_f5(string val){
                                f5 = val;
                            }
                            inline string& get_f5(){
                                return f5;
                            }
                        
                            inline void set_f6(E2 val){
                                f6 = val;
                            }
                            inline E2& get_f6(){
                                return f6;
                            }
                        
                            inline M152* mutable_f7(){
                                f7 = new M152();
                                return f7;
                            }
                            inline M152*& get_f7(){
                                return f7;
                            }
                        
                            inline void set_f8(int64_t val){
                                f8 = val;
                            }
                            inline int64_t& get_f8(){
                                return f8;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M140->f1: " << f1 << std::endl;
                                if(f2 != nullptr)
                                    f2->print_message(fout);
                                for(auto &f3_val : f3){
                                    fout << "M140->f3: " << f3_val << std::endl;
                                }
                                if(f4 != nullptr)
                                    f4->print_message(fout);
                                fout << "M140->f5: " << f5 << std::endl;
                                fout << "M140->f6: " << f6 << std::endl;
                                if(f7 != nullptr)
                                    f7->print_message(fout);
                                fout << "M140->f8: " << f8 << std::endl;
                            }
                        
                            ~M140(){
                                if(f2 != nullptr)
                                    delete f2;
                                if(f4 != nullptr)
                                    delete f4;
                                if(f7 != nullptr)
                                    delete f7;
                            }
                        
                            M140(){
                               f2 = nullptr;
                               f4 = nullptr;
                               f7 = nullptr;
                            }
                        
                        private:
                            alignas(8) E1 f1;
                            alignas(8) M141* f2;
                            alignas(8) std::vector<float> f3;
                            alignas(8) M151* f4;
                            alignas(8) string f5;
                            alignas(8) E2 f6;
                            alignas(8) M152* f7;
                            alignas(8) int64_t f8;
                        };


                        class alignas(8) M153 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 34,
                                E1_CONST_2 = 35,
                                E1_CONST_3 = 77,
                                E1_CONST_4 = 111,
                                E1_CONST_5 = 91,
                            };
                            
                            inline void set_f1(E1 val){
                                f1 = val;
                            }
                            inline E1& get_f1(){
                                return f1;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M153->f1: " << f1 << std::endl;
                            }
                        
                            ~M153(){
                            }
                        
                            M153(){
                            }
                        
                        private:
                            alignas(8) E1 f1;
                        };


                        inline void set_f1(E1 val){
                            f1 = val;
                        }
                        inline E1& get_f1(){
                            return f1;
                        }
                    
                        inline M140* mutable_f2(){
                            f2 = new M140();
                            return f2;
                        }
                        inline M140*& get_f2(){
                            return f2;
                        }
                    
                        inline M153* mutable_f3(){
                            f3 = new M153();
                            return f3;
                        }
                        inline M153*& get_f3(){
                            return f3;
                        }
                    
                        inline void set_f4(int32_t val){
                            f4 = val;
                        }
                        inline int32_t& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(E2 val){
                            f5 = val;
                        }
                        inline E2& get_f5(){
                            return f5;
                        }
                    
                        inline void set_f6(E3 val){
                            f6 = val;
                        }
                        inline E3& get_f6(){
                            return f6;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M139->f1: " << f1 << std::endl;
                            if(f2 != nullptr)
                                f2->print_message(fout);
                            if(f3 != nullptr)
                                f3->print_message(fout);
                            fout << "M139->f4: " << f4 << std::endl;
                            fout << "M139->f5: " << f5 << std::endl;
                            fout << "M139->f6: " << f6 << std::endl;
                        }
                    
                        ~M139(){
                            if(f2 != nullptr)
                                delete f2;
                            if(f3 != nullptr)
                                delete f3;
                        }
                    
                        M139(){
                           f2 = nullptr;
                           f3 = nullptr;
                        }
                    
                    private:
                        alignas(8) E1 f1;
                        alignas(8) M140* f2;
                        alignas(8) M153* f3;
                        alignas(8) int32_t f4;
                        alignas(8) E2 f5;
                        alignas(8) E3 f6;
                    };


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
                
                    inline M138* mutable_f3(){
                        f3 = new M138();
                        return f3;
                    }
                    inline M138*& get_f3(){
                        return f3;
                    }
                
                    inline M139* mutable_f4(){
                        f4 = new M139();
                        return f4;
                    }
                    inline M139*& get_f4(){
                        return f4;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M137->f1: " << f1 << std::endl;
                        fout << "M137->f2: " << f2 << std::endl;
                        if(f3 != nullptr)
                            f3->print_message(fout);
                        if(f4 != nullptr)
                            f4->print_message(fout);
                    }
                
                    ~M137(){
                        if(f3 != nullptr)
                            delete f3;
                        if(f4 != nullptr)
                            delete f4;
                    }
                
                    M137(){
                       f3 = nullptr;
                       f4 = nullptr;
                    }
                
                private:
                    alignas(8) bool f1;
                    alignas(8) int64_t f2;
                    alignas(8) M138* f3;
                    alignas(8) M139* f4;
                };


                class alignas(8) M154 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 13,
                        E1_CONST_2 = 80,
                        E1_CONST_3 = 114,
                        E1_CONST_4 = 119,
                        E1_CONST_5 = 60,
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
                
                    inline void set_f3(bool val){
                        f3 = val;
                    }
                    inline bool& get_f3(){
                        return f3;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M154->f1: " << f1 << std::endl;
                        fout << "M154->f2: " << f2 << std::endl;
                        fout << "M154->f3: " << f3 << std::endl;
                    }
                
                    ~M154(){
                    }
                
                    M154(){
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) float f2;
                    alignas(8) bool f3;
                };


                class alignas(8) M155 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 98,
                        E1_CONST_2 = 7,
                        E1_CONST_3 = 10,
                        E1_CONST_4 = 113,
                        E1_CONST_5 = 56,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M155->f1: " << f1 << std::endl;
                    }
                
                    ~M155(){
                    }
                
                    M155(){
                    }
                
                private:
                    alignas(8) E1 f1;
                };


                class alignas(8) M156 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 38,
                        E1_CONST_2 = 77,
                        E1_CONST_3 = 49,
                        E1_CONST_4 = 22,
                        E1_CONST_5 = 23,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 97,
                        E2_CONST_2 = 9,
                        E2_CONST_3 = 14,
                        E2_CONST_4 = 51,
                        E2_CONST_5 = 85,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline void set_f2(E2 val){
                        f2 = val;
                    }
                    inline E2& get_f2(){
                        return f2;
                    }
                
                    inline void set_f3(int64_t val){
                        f3 = val;
                    }
                    inline int64_t& get_f3(){
                        return f3;
                    }
                
                    inline void set_f4(uint32_t val){
                        f4 = val;
                    }
                    inline uint32_t& get_f4(){
                        return f4;
                    }
                
                    inline void set_f5(float val){
                        f5 = val;
                    }
                    inline float& get_f5(){
                        return f5;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M156->f1: " << f1 << std::endl;
                        fout << "M156->f2: " << f2 << std::endl;
                        fout << "M156->f3: " << f3 << std::endl;
                        fout << "M156->f4: " << f4 << std::endl;
                        fout << "M156->f5: " << f5 << std::endl;
                    }
                
                    ~M156(){
                    }
                
                    M156(){
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) E2 f2;
                    alignas(8) int64_t f3;
                    alignas(8) uint32_t f4;
                    alignas(8) float f5;
                };


                inline M137* mutable_f1(){
                    f1 = new M137();
                    return f1;
                }
                inline M137*& get_f1(){
                    return f1;
                }
            
                inline void set_f2(uint32_t val){
                    f2 = val;
                }
                inline uint32_t& get_f2(){
                    return f2;
                }
            
                inline void set_f3(uint32_t val){
                    f3 = val;
                }
                inline uint32_t& get_f3(){
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
            
                inline M154* mutable_f6(){
                    f6 = new M154();
                    return f6;
                }
                inline M154*& get_f6(){
                    return f6;
                }
            
                inline M155* mutable_f7(){
                    f7 = new M155();
                    return f7;
                }
                inline M155*& get_f7(){
                    return f7;
                }
            
                inline void set_f8(float val){
                    f8 = val;
                }
                inline float& get_f8(){
                    return f8;
                }
            
                inline void set_f9(float val){
                    f9 = val;
                }
                inline float& get_f9(){
                    return f9;
                }
            
                inline M156* mutable_f10(){
                    f10 = new M156();
                    return f10;
                }
                inline M156*& get_f10(){
                    return f10;
                }
            
                inline void set_f11(E1 val){
                    f11 = val;
                }
                inline E1& get_f11(){
                    return f11;
                }
            
                inline void print_message(std::ofstream &fout){
                    if(f1 != nullptr)
                        f1->print_message(fout);
                    fout << "M136->f2: " << f2 << std::endl;
                    fout << "M136->f3: " << f3 << std::endl;
                    fout << "M136->f4: " << f4 << std::endl;
                    fout << "M136->f5: " << f5 << std::endl;
                    if(f6 != nullptr)
                        f6->print_message(fout);
                    if(f7 != nullptr)
                        f7->print_message(fout);
                    fout << "M136->f8: " << f8 << std::endl;
                    fout << "M136->f9: " << f9 << std::endl;
                    if(f10 != nullptr)
                        f10->print_message(fout);
                    fout << "M136->f11: " << f11 << std::endl;
                }
            
                ~M136(){
                    if(f1 != nullptr)
                        delete f1;
                    if(f6 != nullptr)
                        delete f6;
                    if(f7 != nullptr)
                        delete f7;
                    if(f10 != nullptr)
                        delete f10;
                }
            
                M136(){
                   f1 = nullptr;
                   f6 = nullptr;
                   f7 = nullptr;
                   f10 = nullptr;
                }
            
            private:
                alignas(8) M137* f1;
                alignas(8) uint32_t f2;
                alignas(8) uint32_t f3;
                alignas(8) int32_t f4;
                alignas(8) uint32_t f5;
                alignas(8) M154* f6;
                alignas(8) M155* f7;
                alignas(8) float f8;
                alignas(8) float f9;
                alignas(8) M156* f10;
                alignas(8) E1 f11;
            };


            inline M133* mutable_f1(){
                f1 = new M133();
                return f1;
            }
            inline M133*& get_f1(){
                return f1;
            }
        
            inline M136* mutable_f2(){
                f2 = new M136();
                return f2;
            }
            inline M136*& get_f2(){
                return f2;
            }
        
            inline void set_f3(E1 val){
                f3 = val;
            }
            inline E1& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M132->f3: " << f3 << std::endl;
            }
        
            ~M132(){
                if(f1 != nullptr)
                    delete f1;
                if(f2 != nullptr)
                    delete f2;
            }
        
            M132(){
               f1 = nullptr;
               f2 = nullptr;
            }
        
        private:
            alignas(8) M133* f1;
            alignas(8) M136* f2;
            alignas(8) E1 f3;
        };


        inline void set_f1(uint64_t val){
            f1 = val;
        }
        inline uint64_t& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint32_t val){
            f2 = val;
        }
        inline uint32_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(float val){
            f3 = val;
        }
        inline float& get_f3(){
            return f3;
        }
    
        inline M132* mutable_f4(){
            f4 = new M132();
            return f4;
        }
        inline M132*& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M131->f1: " << f1 << std::endl;
            fout << "M131->f2: " << f2 << std::endl;
            fout << "M131->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
        }
    
        ~M131(){
            if(f4 != nullptr)
                delete f4;
        }
    
        M131(){
           f4 = nullptr;
        }
    
    private:
        alignas(8) uint64_t f1;
        alignas(8) uint32_t f2;
        alignas(8) float f3;
        alignas(8) M132* f4;
    };


    class alignas(8) M157 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 38,
            E1_CONST_2 = 13,
            E1_CONST_3 = 113,
            E1_CONST_4 = 56,
            E1_CONST_5 = 126,
        };
        
        class alignas(8) M158 : public M_base
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
                fout << "M158->f1: " << f1 << std::endl;
                fout << "M158->f2: " << f2 << std::endl;
            }
        
            ~M158(){
            }
        
            M158(){
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) float f2;
        };


        class alignas(8) M159 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 10,
                E1_CONST_2 = 78,
                E1_CONST_3 = 80,
                E1_CONST_4 = 86,
                E1_CONST_5 = 58,
            };
            
            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M159->f1: " << f1 << std::endl;
            }
        
            ~M159(){
            }
        
            M159(){
            }
        
        private:
            alignas(8) E1 f1;
        };


        inline void set_f1(E1 val){
            f1 = val;
        }
        inline E1& get_f1(){
            return f1;
        }
    
        inline M158* mutable_f2(){
            f2 = new M158();
            return f2;
        }
        inline M158*& get_f2(){
            return f2;
        }
    
        inline void set_f3(uint32_t val){
            f3 = val;
        }
        inline uint32_t& get_f3(){
            return f3;
        }
    
        inline M159* mutable_f4(){
            f4 = new M159();
            return f4;
        }
        inline M159*& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M157->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M157->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
        }
    
        ~M157(){
            if(f2 != nullptr)
                delete f2;
            if(f4 != nullptr)
                delete f4;
        }
    
        M157(){
           f2 = nullptr;
           f4 = nullptr;
        }
    
    private:
        alignas(8) E1 f1;
        alignas(8) M158* f2;
        alignas(8) uint32_t f3;
        alignas(8) M159* f4;
    };


    class alignas(8) M160 : public M_base
    {
    public:
        class alignas(8) M161 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 71,
                E1_CONST_2 = 8,
                E1_CONST_3 = 9,
                E1_CONST_4 = 14,
                E1_CONST_5 = 30,
            };
            
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
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
        
            inline void set_f5(int32_t val){
                f5 = val;
            }
            inline int32_t& get_f5(){
                return f5;
            }
        
            inline void set_f6(bool val){
                f6 = val;
            }
            inline bool& get_f6(){
                return f6;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M161->f1: " << f1 << std::endl;
                fout << "M161->f2: " << f2 << std::endl;
                fout << "M161->f3: " << f3 << std::endl;
                fout << "M161->f4: " << f4 << std::endl;
                fout << "M161->f5: " << f5 << std::endl;
                fout << "M161->f6: " << f6 << std::endl;
            }
        
            ~M161(){
            }
        
            M161(){
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) E1 f2;
            alignas(8) int64_t f3;
            alignas(8) int32_t f4;
            alignas(8) int32_t f5;
            alignas(8) bool f6;
        };


        class alignas(8) M162 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M162->f1: " << f1 << std::endl;
            }
        
            ~M162(){
            }
        
            M162(){
            }
        
        private:
            alignas(8) int32_t f1;
        };


        inline M161* mutable_f1(){
            f1 = new M161();
            return f1;
        }
        inline M161*& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline M162* mutable_f3(){
            f3 = new M162();
            return f3;
        }
        inline M162*& get_f3(){
            return f3;
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
            fout << "M160->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
            fout << "M160->f4: " << f4 << std::endl;
        }
    
        ~M160(){
            if(f1 != nullptr)
                delete f1;
            if(f3 != nullptr)
                delete f3;
        }
    
        M160(){
           f1 = nullptr;
           f3 = nullptr;
        }
    
    private:
        alignas(8) M161* f1;
        alignas(8) int32_t f2;
        alignas(8) M162* f3;
        alignas(8) float f4;
    };


    inline M130* mutable_f1(){
        f1 = new M130();
        return f1;
    }
    inline M130*& get_f1(){
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

    inline void set_f6(E1 val){
        f6 = val;
    }
    inline E1& get_f6(){
        return f6;
    }

    inline M131* mutable_f7(){
        f7 = new M131();
        return f7;
    }
    inline M131*& get_f7(){
        return f7;
    }

    inline M157* mutable_f8(){
        f8 = new M157();
        return f8;
    }
    inline M157*& get_f8(){
        return f8;
    }

    inline void set_f9(uint32_t val){
        f9 = val;
    }
    inline uint32_t& get_f9(){
        return f9;
    }

    inline void set_f10(float val){
        f10 = val;
    }
    inline float& get_f10(){
        return f10;
    }

    inline void set_f11(float val){
        f11 = val;
    }
    inline float& get_f11(){
        return f11;
    }

    inline M160* mutable_f12(){
        f12 = new M160();
        return f12;
    }
    inline M160*& get_f12(){
        return f12;
    }

    inline void set_f13(uint32_t val){
        f13 = val;
    }
    inline uint32_t& get_f13(){
        return f13;
    }

    inline void set_f14(int32_t val){
        f14 = val;
    }
    inline int32_t& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        fout << "M129->f2: " << f2 << std::endl;
        fout << "M129->f3: " << f3 << std::endl;
        fout << "M129->f4: " << f4 << std::endl;
        fout << "M129->f5: " << f5 << std::endl;
        fout << "M129->f6: " << f6 << std::endl;
        if(f7 != nullptr)
            f7->print_message(fout);
        if(f8 != nullptr)
            f8->print_message(fout);
        fout << "M129->f9: " << f9 << std::endl;
        fout << "M129->f10: " << f10 << std::endl;
        fout << "M129->f11: " << f11 << std::endl;
        if(f12 != nullptr)
            f12->print_message(fout);
        fout << "M129->f13: " << f13 << std::endl;
        fout << "M129->f14: " << f14 << std::endl;
    }

    ~M129(){
        if(f1 != nullptr)
            delete f1;
        if(f7 != nullptr)
            delete f7;
        if(f8 != nullptr)
            delete f8;
        if(f12 != nullptr)
            delete f12;
    }

    M129(){
       f1 = nullptr;
       f7 = nullptr;
       f8 = nullptr;
       f12 = nullptr;
    }

private:
    alignas(8) M130* f1;
    alignas(8) float f2;
    alignas(8) float f3;
    alignas(8) string f4;
    alignas(8) int32_t f5;
    alignas(8) E1 f6;
    alignas(8) M131* f7;
    alignas(8) M157* f8;
    alignas(8) uint32_t f9;
    alignas(8) float f10;
    alignas(8) float f11;
    alignas(8) M160* f12;
    alignas(8) uint32_t f13;
    alignas(8) int32_t f14;
};


class alignas(8) M163 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 34,
        E1_CONST_2 = 45,
        E1_CONST_3 = 110,
        E1_CONST_4 = 116,
        E1_CONST_5 = 53,
    };
    
    enum E2 {
        E2_CONST_1 = 2,
        E2_CONST_2 = 104,
        E2_CONST_3 = 9,
        E2_CONST_4 = 119,
        E2_CONST_5 = 90,
    };
    
    class alignas(8) M164 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 0,
            E1_CONST_2 = 69,
            E1_CONST_3 = 102,
            E1_CONST_4 = 40,
            E1_CONST_5 = 80,
        };
        
        enum E2 {
            E2_CONST_1 = 4,
            E2_CONST_2 = 38,
            E2_CONST_3 = 8,
            E2_CONST_4 = 54,
            E2_CONST_5 = 31,
        };
        
        class alignas(8) M165 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 69,
                E1_CONST_2 = 75,
                E1_CONST_3 = 94,
                E1_CONST_4 = 29,
                E1_CONST_5 = 62,
            };
            
            class alignas(8) M166 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 96,
                    E1_CONST_2 = 77,
                    E1_CONST_3 = 53,
                    E1_CONST_4 = 118,
                    E1_CONST_5 = 22,
                };
                
                class alignas(8) M167 : public M_base
                {
                public:
                    class alignas(8) M168 : public M_base
                    {
                    public:
                        class alignas(8) M169 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 96,
                                E1_CONST_2 = 71,
                                E1_CONST_3 = 10,
                                E1_CONST_4 = 17,
                                E1_CONST_5 = 115,
                            };
                            
                            class alignas(8) M170 : public M_base
                            {
                            public:
                                inline void set_f1(uint32_t val){
                                    f1 = val;
                                }
                                inline uint32_t& get_f1(){
                                    return f1;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M170->f1: " << f1 << std::endl;
                                }
                            
                                ~M170(){
                                }
                            
                                M170(){
                                }
                            
                            private:
                                alignas(8) uint32_t f1;
                            };


                            class alignas(8) M171 : public M_base
                            {
                            public:
                                inline void set_f1(int32_t val){
                                    f1 = val;
                                }
                                inline int32_t& get_f1(){
                                    return f1;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M171->f1: " << f1 << std::endl;
                                }
                            
                                ~M171(){
                                }
                            
                                M171(){
                                }
                            
                            private:
                                alignas(8) int32_t f1;
                            };


                            class alignas(8) M172 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 33,
                                    E1_CONST_2 = 66,
                                    E1_CONST_3 = 80,
                                    E1_CONST_4 = 113,
                                    E1_CONST_5 = 89,
                                };
                                
                                enum E2 {
                                    E2_CONST_1 = 97,
                                    E2_CONST_2 = 69,
                                    E2_CONST_3 = 9,
                                    E2_CONST_4 = 10,
                                    E2_CONST_5 = 49,
                                };
                                
                                class alignas(8) M173 : public M_base
                                {
                                public:
                                    enum E1 {
                                        E1_CONST_1 = 103,
                                        E1_CONST_2 = 43,
                                        E1_CONST_3 = 118,
                                        E1_CONST_4 = 87,
                                        E1_CONST_5 = 120,
                                    };
                                    
                                    inline void set_f1(E1 val){
                                        f1 = val;
                                    }
                                    inline E1& get_f1(){
                                        return f1;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M173->f1: " << f1 << std::endl;
                                    }
                                
                                    ~M173(){
                                    }
                                
                                    M173(){
                                    }
                                
                                private:
                                    alignas(8) E1 f1;
                                };


                                class alignas(8) M174 : public M_base
                                {
                                public:
                                    enum E1 {
                                        E1_CONST_1 = 72,
                                        E1_CONST_2 = 105,
                                        E1_CONST_3 = 108,
                                        E1_CONST_4 = 6838,
                                        E1_CONST_5 = 124,
                                    };
                                    
                                    class alignas(8) M175 : public M_base
                                    {
                                    public:
                                        class alignas(8) M176 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 68,
                                                E1_CONST_2 = 71,
                                                E1_CONST_3 = 8,
                                                E1_CONST_4 = 44,
                                                E1_CONST_5 = 29,
                                            };
                                            
                                            enum E2 {
                                                E2_CONST_1 = 98,
                                                E2_CONST_2 = 113,
                                                E2_CONST_3 = 85,
                                                E2_CONST_4 = 54,
                                                E2_CONST_5 = 120,
                                            };
                                            
                                            enum E3 {
                                                E3_CONST_1 = 70,
                                                E3_CONST_2 = 72,
                                                E3_CONST_3 = 105,
                                                E3_CONST_4 = 20,
                                                E3_CONST_5 = 123,
                                            };
                                            
                                            enum E4 {
                                                E4_CONST_1 = 11,
                                                E4_CONST_2 = 17,
                                                E4_CONST_3 = 118,
                                                E4_CONST_4 = 55,
                                                E4_CONST_5 = 122,
                                            };
                                            
                                            class alignas(8) M177 : public M_base
                                            {
                                            public:
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
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    fout << "M177->f1: " << f1 << std::endl;
                                                    fout << "M177->f2: " << f2 << std::endl;
                                                }
                                            
                                                ~M177(){
                                                }
                                            
                                                M177(){
                                                }
                                            
                                            private:
                                                alignas(8) float f1;
                                                alignas(8) float f2;
                                            };


                                            class alignas(8) M178 : public M_base
                                            {
                                            public:
                                                class alignas(8) M179 : public M_base
                                                {
                                                public:
                                                    enum E1 {
                                                        E1_CONST_1 = 34,
                                                        E1_CONST_2 = 72,
                                                        E1_CONST_3 = 77,
                                                        E1_CONST_4 = 48,
                                                        E1_CONST_5 = 117,
                                                    };
                                                    
                                                    class alignas(8) M180 : public M_base
                                                    {
                                                    public:
                                                        inline void set_f1(uint32_t val){
                                                            f1 = val;
                                                        }
                                                        inline uint32_t& get_f1(){
                                                            return f1;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M180->f1: " << f1 << std::endl;
                                                        }
                                                    
                                                        ~M180(){
                                                        }
                                                    
                                                        M180(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) uint32_t f1;
                                                    };


                                                    class alignas(8) M181 : public M_base
                                                    {
                                                    public:
                                                        inline void add_f1(string val){
                                                            f1.push_back(val);
                                                        }
                                                        inline string& get_f1(int idx){
                                                            return f1[idx];
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            for(auto &f1_val : f1){
                                                                fout << "M181->f1: " << f1_val << std::endl;
                                                            }
                                                        }
                                                    
                                                        ~M181(){
                                                        }
                                                    
                                                        M181(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) std::vector<string> f1;
                                                    };


                                                    inline void set_f1(int32_t val){
                                                        f1 = val;
                                                    }
                                                    inline int32_t& get_f1(){
                                                        return f1;
                                                    }
                                                
                                                    inline M180* mutable_f2(){
                                                        f2 = new M180();
                                                        return f2;
                                                    }
                                                    inline M180*& get_f2(){
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
                                                
                                                    inline void set_f6(string val){
                                                        f6 = val;
                                                    }
                                                    inline string& get_f6(){
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
                                                
                                                    inline void set_f9(float val){
                                                        f9 = val;
                                                    }
                                                    inline float& get_f9(){
                                                        return f9;
                                                    }
                                                
                                                    inline void set_f10(E1 val){
                                                        f10 = val;
                                                    }
                                                    inline E1& get_f10(){
                                                        return f10;
                                                    }
                                                
                                                    inline void set_f11(int32_t val){
                                                        f11 = val;
                                                    }
                                                    inline int32_t& get_f11(){
                                                        return f11;
                                                    }
                                                
                                                    inline M181* mutable_f12(){
                                                        f12 = new M181();
                                                        return f12;
                                                    }
                                                    inline M181*& get_f12(){
                                                        return f12;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M179->f1: " << f1 << std::endl;
                                                        if(f2 != nullptr)
                                                            f2->print_message(fout);
                                                        fout << "M179->f3: " << f3 << std::endl;
                                                        fout << "M179->f4: " << f4 << std::endl;
                                                        fout << "M179->f5: " << f5 << std::endl;
                                                        fout << "M179->f6: " << f6 << std::endl;
                                                        fout << "M179->f7: " << f7 << std::endl;
                                                        fout << "M179->f8: " << f8 << std::endl;
                                                        fout << "M179->f9: " << f9 << std::endl;
                                                        fout << "M179->f10: " << f10 << std::endl;
                                                        fout << "M179->f11: " << f11 << std::endl;
                                                        if(f12 != nullptr)
                                                            f12->print_message(fout);
                                                    }
                                                
                                                    ~M179(){
                                                        if(f2 != nullptr)
                                                            delete f2;
                                                        if(f12 != nullptr)
                                                            delete f12;
                                                    }
                                                
                                                    M179(){
                                                       f2 = nullptr;
                                                       f12 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) int32_t f1;
                                                    alignas(8) M180* f2;
                                                    alignas(8) string f3;
                                                    alignas(8) int32_t f4;
                                                    alignas(8) int32_t f5;
                                                    alignas(8) string f6;
                                                    alignas(8) float f7;
                                                    alignas(8) int32_t f8;
                                                    alignas(8) float f9;
                                                    alignas(8) E1 f10;
                                                    alignas(8) int32_t f11;
                                                    alignas(8) M181* f12;
                                                };


                                                inline M179* mutable_f1(){
                                                    f1 = new M179();
                                                    return f1;
                                                }
                                                inline M179*& get_f1(){
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
                                                    fout << "M178->f2: " << f2 << std::endl;
                                                }
                                            
                                                ~M178(){
                                                    if(f1 != nullptr)
                                                        delete f1;
                                                }
                                            
                                                M178(){
                                                   f1 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) M179* f1;
                                                alignas(8) string f2;
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
                                        
                                            inline void set_f3(string val){
                                                f3 = val;
                                            }
                                            inline string& get_f3(){
                                                return f3;
                                            }
                                        
                                            inline M177* mutable_f4(){
                                                f4 = new M177();
                                                return f4;
                                            }
                                            inline M177*& get_f4(){
                                                return f4;
                                            }
                                        
                                            inline M178* mutable_f5(){
                                                f5 = new M178();
                                                return f5;
                                            }
                                            inline M178*& get_f5(){
                                                return f5;
                                            }
                                        
                                            inline void set_f6(E2 val){
                                                f6 = val;
                                            }
                                            inline E2& get_f6(){
                                                return f6;
                                            }
                                        
                                            inline void set_f7(E3 val){
                                                f7 = val;
                                            }
                                            inline E3& get_f7(){
                                                return f7;
                                            }
                                        
                                            inline void set_f8(E4 val){
                                                f8 = val;
                                            }
                                            inline E4& get_f8(){
                                                return f8;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M176->f1: " << f1 << std::endl;
                                                fout << "M176->f2: " << f2 << std::endl;
                                                fout << "M176->f3: " << f3 << std::endl;
                                                if(f4 != nullptr)
                                                    f4->print_message(fout);
                                                if(f5 != nullptr)
                                                    f5->print_message(fout);
                                                fout << "M176->f6: " << f6 << std::endl;
                                                fout << "M176->f7: " << f7 << std::endl;
                                                fout << "M176->f8: " << f8 << std::endl;
                                            }
                                        
                                            ~M176(){
                                                if(f4 != nullptr)
                                                    delete f4;
                                                if(f5 != nullptr)
                                                    delete f5;
                                            }
                                        
                                            M176(){
                                               f4 = nullptr;
                                               f5 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) E1 f1;
                                            alignas(8) float f2;
                                            alignas(8) string f3;
                                            alignas(8) M177* f4;
                                            alignas(8) M178* f5;
                                            alignas(8) E2 f6;
                                            alignas(8) E3 f7;
                                            alignas(8) E4 f8;
                                        };


                                        inline M176* mutable_f1(){
                                            f1 = new M176();
                                            return f1;
                                        }
                                        inline M176*& get_f1(){
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
                                            fout << "M175->f2: " << f2 << std::endl;
                                        }
                                    
                                        ~M175(){
                                            if(f1 != nullptr)
                                                delete f1;
                                        }
                                    
                                        M175(){
                                           f1 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) M176* f1;
                                        alignas(8) int32_t f2;
                                    };


                                    inline void set_f1(E1 val){
                                        f1 = val;
                                    }
                                    inline E1& get_f1(){
                                        return f1;
                                    }
                                
                                    inline M175* mutable_f2(){
                                        f2 = new M175();
                                        return f2;
                                    }
                                    inline M175*& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M174->f1: " << f1 << std::endl;
                                        if(f2 != nullptr)
                                            f2->print_message(fout);
                                    }
                                
                                    ~M174(){
                                        if(f2 != nullptr)
                                            delete f2;
                                    }
                                
                                    M174(){
                                       f2 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) E1 f1;
                                    alignas(8) M175* f2;
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
                            
                                inline void set_f3(int32_t val){
                                    f3 = val;
                                }
                                inline int32_t& get_f3(){
                                    return f3;
                                }
                            
                                inline M173* mutable_f4(){
                                    f4 = new M173();
                                    return f4;
                                }
                                inline M173*& get_f4(){
                                    return f4;
                                }
                            
                                inline M174* mutable_f5(){
                                    f5 = new M174();
                                    return f5;
                                }
                                inline M174*& get_f5(){
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
                            
                                inline void set_f8(E2 val){
                                    f8 = val;
                                }
                                inline E2& get_f8(){
                                    return f8;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M172->f1: " << f1 << std::endl;
                                    fout << "M172->f2: " << f2 << std::endl;
                                    fout << "M172->f3: " << f3 << std::endl;
                                    if(f4 != nullptr)
                                        f4->print_message(fout);
                                    if(f5 != nullptr)
                                        f5->print_message(fout);
                                    fout << "M172->f6: " << f6 << std::endl;
                                    fout << "M172->f7: " << f7 << std::endl;
                                    fout << "M172->f8: " << f8 << std::endl;
                                }
                            
                                ~M172(){
                                    if(f4 != nullptr)
                                        delete f4;
                                    if(f5 != nullptr)
                                        delete f5;
                                }
                            
                                M172(){
                                   f4 = nullptr;
                                   f5 = nullptr;
                                }
                            
                            private:
                                alignas(8) E1 f1;
                                alignas(8) string f2;
                                alignas(8) int32_t f3;
                                alignas(8) M173* f4;
                                alignas(8) M174* f5;
                                alignas(8) int32_t f6;
                                alignas(8) int32_t f7;
                                alignas(8) E2 f8;
                            };


                            inline void set_f1(int64_t val){
                                f1 = val;
                            }
                            inline int64_t& get_f1(){
                                return f1;
                            }
                        
                            inline void set_f2(float val){
                                f2 = val;
                            }
                            inline float& get_f2(){
                                return f2;
                            }
                        
                            inline M170* mutable_f3(){
                                f3 = new M170();
                                return f3;
                            }
                            inline M170*& get_f3(){
                                return f3;
                            }
                        
                            inline void set_f4(int64_t val){
                                f4 = val;
                            }
                            inline int64_t& get_f4(){
                                return f4;
                            }
                        
                            inline M171* mutable_f5(){
                                f5 = new M171();
                                return f5;
                            }
                            inline M171*& get_f5(){
                                return f5;
                            }
                        
                            inline void set_f6(float val){
                                f6 = val;
                            }
                            inline float& get_f6(){
                                return f6;
                            }
                        
                            inline void set_f7(uint32_t val){
                                f7 = val;
                            }
                            inline uint32_t& get_f7(){
                                return f7;
                            }
                        
                            inline void set_f8(E1 val){
                                f8 = val;
                            }
                            inline E1& get_f8(){
                                return f8;
                            }
                        
                            inline M172* mutable_f9(){
                                f9 = new M172();
                                return f9;
                            }
                            inline M172*& get_f9(){
                                return f9;
                            }
                        
                            inline void set_f10(uint32_t val){
                                f10 = val;
                            }
                            inline uint32_t& get_f10(){
                                return f10;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M169->f1: " << f1 << std::endl;
                                fout << "M169->f2: " << f2 << std::endl;
                                if(f3 != nullptr)
                                    f3->print_message(fout);
                                fout << "M169->f4: " << f4 << std::endl;
                                if(f5 != nullptr)
                                    f5->print_message(fout);
                                fout << "M169->f6: " << f6 << std::endl;
                                fout << "M169->f7: " << f7 << std::endl;
                                fout << "M169->f8: " << f8 << std::endl;
                                if(f9 != nullptr)
                                    f9->print_message(fout);
                                fout << "M169->f10: " << f10 << std::endl;
                            }
                        
                            ~M169(){
                                if(f3 != nullptr)
                                    delete f3;
                                if(f5 != nullptr)
                                    delete f5;
                                if(f9 != nullptr)
                                    delete f9;
                            }
                        
                            M169(){
                               f3 = nullptr;
                               f5 = nullptr;
                               f9 = nullptr;
                            }
                        
                        private:
                            alignas(8) int64_t f1;
                            alignas(8) float f2;
                            alignas(8) M170* f3;
                            alignas(8) int64_t f4;
                            alignas(8) M171* f5;
                            alignas(8) float f6;
                            alignas(8) uint32_t f7;
                            alignas(8) E1 f8;
                            alignas(8) M172* f9;
                            alignas(8) uint32_t f10;
                        };


                        inline void set_f1(uint32_t val){
                            f1 = val;
                        }
                        inline uint32_t& get_f1(){
                            return f1;
                        }
                    
                        inline M169* mutable_f2(){
                            f2 = new M169();
                            return f2;
                        }
                        inline M169*& get_f2(){
                            return f2;
                        }
                    
                        inline void set_f3(bool val){
                            f3 = val;
                        }
                        inline bool& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M168->f1: " << f1 << std::endl;
                            if(f2 != nullptr)
                                f2->print_message(fout);
                            fout << "M168->f3: " << f3 << std::endl;
                        }
                    
                        ~M168(){
                            if(f2 != nullptr)
                                delete f2;
                        }
                    
                        M168(){
                           f2 = nullptr;
                        }
                    
                    private:
                        alignas(8) uint32_t f1;
                        alignas(8) M169* f2;
                        alignas(8) bool f3;
                    };


                    class alignas(8) M182 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 98,
                            E1_CONST_2 = 19,
                            E1_CONST_3 = 116,
                            E1_CONST_4 = 85,
                            E1_CONST_5 = 55,
                        };
                        
                        enum E2 {
                            E2_CONST_1 = 0,
                            E2_CONST_2 = 113,
                            E2_CONST_3 = 83,
                            E2_CONST_4 = 27,
                            E2_CONST_5 = 62,
                        };
                        
                        enum E3 {
                            E3_CONST_1 = 99,
                            E3_CONST_2 = 70,
                            E3_CONST_3 = 80,
                            E3_CONST_4 = 54,
                            E3_CONST_5 = 61,
                        };
                        
                        enum E4 {
                            E4_CONST_1 = 102,
                            E4_CONST_2 = 72,
                            E4_CONST_3 = 44,
                            E4_CONST_4 = 45,
                            E4_CONST_5 = 83,
                        };
                        
                        inline void set_f1(uint32_t val){
                            f1 = val;
                        }
                        inline uint32_t& get_f1(){
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
                    
                        inline void set_f4(int64_t val){
                            f4 = val;
                        }
                        inline int64_t& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(E2 val){
                            f5 = val;
                        }
                        inline E2& get_f5(){
                            return f5;
                        }
                    
                        inline void set_f6(E3 val){
                            f6 = val;
                        }
                        inline E3& get_f6(){
                            return f6;
                        }
                    
                        inline void set_f7(int32_t val){
                            f7 = val;
                        }
                        inline int32_t& get_f7(){
                            return f7;
                        }
                    
                        inline void set_f8(float val){
                            f8 = val;
                        }
                        inline float& get_f8(){
                            return f8;
                        }
                    
                        inline void set_f9(E4 val){
                            f9 = val;
                        }
                        inline E4& get_f9(){
                            return f9;
                        }
                    
                        inline void set_f10(uint32_t val){
                            f10 = val;
                        }
                        inline uint32_t& get_f10(){
                            return f10;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M182->f1: " << f1 << std::endl;
                            fout << "M182->f2: " << f2 << std::endl;
                            fout << "M182->f3: " << f3 << std::endl;
                            fout << "M182->f4: " << f4 << std::endl;
                            fout << "M182->f5: " << f5 << std::endl;
                            fout << "M182->f6: " << f6 << std::endl;
                            fout << "M182->f7: " << f7 << std::endl;
                            fout << "M182->f8: " << f8 << std::endl;
                            fout << "M182->f9: " << f9 << std::endl;
                            fout << "M182->f10: " << f10 << std::endl;
                        }
                    
                        ~M182(){
                        }
                    
                        M182(){
                        }
                    
                    private:
                        alignas(8) uint32_t f1;
                        alignas(8) float f2;
                        alignas(8) E1 f3;
                        alignas(8) int64_t f4;
                        alignas(8) E2 f5;
                        alignas(8) E3 f6;
                        alignas(8) int32_t f7;
                        alignas(8) float f8;
                        alignas(8) E4 f9;
                        alignas(8) uint32_t f10;
                    };


                    inline void set_f1(float val){
                        f1 = val;
                    }
                    inline float& get_f1(){
                        return f1;
                    }
                
                    inline M168* mutable_f2(){
                        f2 = new M168();
                        return f2;
                    }
                    inline M168*& get_f2(){
                        return f2;
                    }
                
                    inline M182* mutable_f3(){
                        f3 = new M182();
                        return f3;
                    }
                    inline M182*& get_f3(){
                        return f3;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M167->f1: " << f1 << std::endl;
                        if(f2 != nullptr)
                            f2->print_message(fout);
                        if(f3 != nullptr)
                            f3->print_message(fout);
                    }
                
                    ~M167(){
                        if(f2 != nullptr)
                            delete f2;
                        if(f3 != nullptr)
                            delete f3;
                    }
                
                    M167(){
                       f2 = nullptr;
                       f3 = nullptr;
                    }
                
                private:
                    alignas(8) float f1;
                    alignas(8) M168* f2;
                    alignas(8) M182* f3;
                };


                inline void set_f1(E1 val){
                    f1 = val;
                }
                inline E1& get_f1(){
                    return f1;
                }
            
                inline M167* mutable_f2(){
                    f2 = new M167();
                    return f2;
                }
                inline M167*& get_f2(){
                    return f2;
                }
            
                inline void add_f3(float val){
                    f3.push_back(val);
                }
                inline float& get_f3(int idx){
                    return f3[idx];
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M166->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    for(auto &f3_val : f3){
                        fout << "M166->f3: " << f3_val << std::endl;
                    }
                }
            
                ~M166(){
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M166(){
                   f2 = nullptr;
                }
            
            private:
                alignas(8) E1 f1;
                alignas(8) M167* f2;
                alignas(8) std::vector<float> f3;
            };


            inline M166* mutable_f1(){
                f1 = new M166();
                return f1;
            }
            inline M166*& get_f1(){
                return f1;
            }
        
            inline void set_f2(E1 val){
                f2 = val;
            }
            inline E1& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                fout << "M165->f2: " << f2 << std::endl;
            }
        
            ~M165(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M165(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M166* f1;
            alignas(8) E1 f2;
        };


        class alignas(8) M183 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 96,
                E1_CONST_2 = 73,
                E1_CONST_3 = 74,
                E1_CONST_4 = 12,
                E1_CONST_5 = 57,
            };
            
            class alignas(8) M184 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 0,
                    E1_CONST_2 = 115,
                    E1_CONST_3 = 85,
                    E1_CONST_4 = 54,
                    E1_CONST_5 = 63,
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
            
                inline void set_f3(int32_t val){
                    f3 = val;
                }
                inline int32_t& get_f3(){
                    return f3;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M184->f1: " << f1 << std::endl;
                    fout << "M184->f2: " << f2 << std::endl;
                    fout << "M184->f3: " << f3 << std::endl;
                }
            
                ~M184(){
                }
            
                M184(){
                }
            
            private:
                alignas(8) E1 f1;
                alignas(8) string f2;
                alignas(8) int32_t f3;
            };


            class alignas(8) M185 : public M_base
            {
            public:
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
            
                inline void print_message(std::ofstream &fout){
                    fout << "M185->f1: " << f1 << std::endl;
                    fout << "M185->f2: " << f2 << std::endl;
                }
            
                ~M185(){
                }
            
                M185(){
                }
            
            private:
                alignas(8) float f1;
                alignas(8) float f2;
            };


            class alignas(8) M186 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 33,
                    E1_CONST_2 = 106,
                    E1_CONST_3 = 80,
                    E1_CONST_4 = 55,
                    E1_CONST_5 = 59,
                };
                
                inline void set_f1(E1 val){
                    f1 = val;
                }
                inline E1& get_f1(){
                    return f1;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M186->f1: " << f1 << std::endl;
                }
            
                ~M186(){
                }
            
                M186(){
                }
            
            private:
                alignas(8) E1 f1;
            };


            inline M184* mutable_f1(){
                f1 = new M184();
                return f1;
            }
            inline M184*& get_f1(){
                return f1;
            }
        
            inline M185* mutable_f2(){
                f2 = new M185();
                return f2;
            }
            inline M185*& get_f2(){
                return f2;
            }
        
            inline void set_f3(E1 val){
                f3 = val;
            }
            inline E1& get_f3(){
                return f3;
            }
        
            inline void set_f4(int32_t val){
                f4 = val;
            }
            inline int32_t& get_f4(){
                return f4;
            }
        
            inline M186* mutable_f5(){
                f5 = new M186();
                return f5;
            }
            inline M186*& get_f5(){
                return f5;
            }
        
            inline void add_f6(float val){
                f6.push_back(val);
            }
            inline float& get_f6(int idx){
                return f6[idx];
            }
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M183->f3: " << f3 << std::endl;
                fout << "M183->f4: " << f4 << std::endl;
                if(f5 != nullptr)
                    f5->print_message(fout);
                for(auto &f6_val : f6){
                    fout << "M183->f6: " << f6_val << std::endl;
                }
            }
        
            ~M183(){
                if(f1 != nullptr)
                    delete f1;
                if(f2 != nullptr)
                    delete f2;
                if(f5 != nullptr)
                    delete f5;
            }
        
            M183(){
               f1 = nullptr;
               f2 = nullptr;
               f5 = nullptr;
            }
        
        private:
            alignas(8) M184* f1;
            alignas(8) M185* f2;
            alignas(8) E1 f3;
            alignas(8) int32_t f4;
            alignas(8) M186* f5;
            alignas(8) std::vector<float> f6;
        };


        inline M165* mutable_f1(){
            f1 = new M165();
            return f1;
        }
        inline M165*& get_f1(){
            return f1;
        }
    
        inline void set_f2(E1 val){
            f2 = val;
        }
        inline E1& get_f2(){
            return f2;
        }
    
        inline void set_f3(E2 val){
            f3 = val;
        }
        inline E2& get_f3(){
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
    
        inline M183* mutable_f6(){
            f6 = new M183();
            return f6;
        }
        inline M183*& get_f6(){
            return f6;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M164->f2: " << f2 << std::endl;
            fout << "M164->f3: " << f3 << std::endl;
            fout << "M164->f4: " << f4 << std::endl;
            fout << "M164->f5: " << f5 << std::endl;
            if(f6 != nullptr)
                f6->print_message(fout);
        }
    
        ~M164(){
            if(f1 != nullptr)
                delete f1;
            if(f6 != nullptr)
                delete f6;
        }
    
        M164(){
           f1 = nullptr;
           f6 = nullptr;
        }
    
    private:
        alignas(8) M165* f1;
        alignas(8) E1 f2;
        alignas(8) E2 f3;
        alignas(8) uint32_t f4;
        alignas(8) int32_t f5;
        alignas(8) M183* f6;
    };


    class alignas(8) M187 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 66,
            E1_CONST_2 = 40,
            E1_CONST_3 = 10,
            E1_CONST_4 = 44,
            E1_CONST_5 = 93,
        };
        
        enum E2 {
            E2_CONST_1 = 66,
            E2_CONST_2 = 79,
            E2_CONST_3 = 9524,
            E2_CONST_4 = 20,
            E2_CONST_5 = 122,
        };
        
        class alignas(8) M188 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 65,
                E1_CONST_2 = 108,
                E1_CONST_3 = 116,
                E1_CONST_4 = 25,
                E1_CONST_5 = 31,
            };
            
            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M188->f1: " << f1 << std::endl;
            }
        
            ~M188(){
            }
        
            M188(){
            }
        
        private:
            alignas(8) E1 f1;
        };


        class alignas(8) M189 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 5,
                E1_CONST_2 = 60,
                E1_CONST_3 = 86,
                E1_CONST_4 = 89,
                E1_CONST_5 = 92,
            };
            
            class alignas(8) M190 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 96,
                    E1_CONST_2 = 65,
                    E1_CONST_3 = 112,
                    E1_CONST_4 = 50,
                    E1_CONST_5 = 89,
                };
                
                enum E2 {
                    E2_CONST_1 = 73,
                    E2_CONST_2 = 15,
                    E2_CONST_3 = 18,
                    E2_CONST_4 = 91,
                    E2_CONST_5 = 30,
                };
                
                class alignas(8) M191 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 65,
                        E1_CONST_2 = 66,
                        E1_CONST_3 = 68,
                        E1_CONST_4 = 76,
                        E1_CONST_5 = 78,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 83,
                        E2_CONST_2 = 20,
                        E2_CONST_3 = 27,
                        E2_CONST_4 = 125,
                        E2_CONST_5 = 94,
                    };
                    
                    enum E3 {
                        E3_CONST_1 = 104,
                        E3_CONST_2 = 47,
                        E3_CONST_3 = 115,
                        E3_CONST_4 = 51,
                        E3_CONST_5 = 54,
                    };
                    
                    enum E4 {
                        E4_CONST_1 = 64,
                        E4_CONST_2 = 35,
                        E4_CONST_3 = 13,
                        E4_CONST_4 = 112,
                        E4_CONST_5 = 49,
                    };
                    
                    enum E5 {
                        E5_CONST_1 = 101,
                        E5_CONST_2 = 111,
                        E5_CONST_3 = 81,
                        E5_CONST_4 = 20,
                        E5_CONST_5 = 89,
                    };
                    
                    class alignas(8) M192 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 8,
                            E1_CONST_2 = 105,
                            E1_CONST_3 = 74,
                            E1_CONST_4 = 44,
                            E1_CONST_5 = 88,
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
                            fout << "M192->f1: " << f1 << std::endl;
                            fout << "M192->f2: " << f2 << std::endl;
                            fout << "M192->f3: " << f3 << std::endl;
                        }
                    
                        ~M192(){
                        }
                    
                        M192(){
                        }
                    
                    private:
                        alignas(8) int32_t f1;
                        alignas(8) bool f2;
                        alignas(8) E1 f3;
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
                
                    inline void set_f3(int64_t val){
                        f3 = val;
                    }
                    inline int64_t& get_f3(){
                        return f3;
                    }
                
                    inline void set_f4(E1 val){
                        f4 = val;
                    }
                    inline E1& get_f4(){
                        return f4;
                    }
                
                    inline M192* mutable_f5(){
                        f5 = new M192();
                        return f5;
                    }
                    inline M192*& get_f5(){
                        return f5;
                    }
                
                    inline void set_f6(E2 val){
                        f6 = val;
                    }
                    inline E2& get_f6(){
                        return f6;
                    }
                
                    inline void set_f7(int32_t val){
                        f7 = val;
                    }
                    inline int32_t& get_f7(){
                        return f7;
                    }
                
                    inline void set_f8(E3 val){
                        f8 = val;
                    }
                    inline E3& get_f8(){
                        return f8;
                    }
                
                    inline void set_f9(E4 val){
                        f9 = val;
                    }
                    inline E4& get_f9(){
                        return f9;
                    }
                
                    inline void set_f10(float val){
                        f10 = val;
                    }
                    inline float& get_f10(){
                        return f10;
                    }
                
                    inline void set_f11(E5 val){
                        f11 = val;
                    }
                    inline E5& get_f11(){
                        return f11;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M191->f1: " << f1 << std::endl;
                        fout << "M191->f2: " << f2 << std::endl;
                        fout << "M191->f3: " << f3 << std::endl;
                        fout << "M191->f4: " << f4 << std::endl;
                        if(f5 != nullptr)
                            f5->print_message(fout);
                        fout << "M191->f6: " << f6 << std::endl;
                        fout << "M191->f7: " << f7 << std::endl;
                        fout << "M191->f8: " << f8 << std::endl;
                        fout << "M191->f9: " << f9 << std::endl;
                        fout << "M191->f10: " << f10 << std::endl;
                        fout << "M191->f11: " << f11 << std::endl;
                    }
                
                    ~M191(){
                        if(f5 != nullptr)
                            delete f5;
                    }
                
                    M191(){
                       f5 = nullptr;
                    }
                
                private:
                    alignas(8) float f1;
                    alignas(8) float f2;
                    alignas(8) int64_t f3;
                    alignas(8) E1 f4;
                    alignas(8) M192* f5;
                    alignas(8) E2 f6;
                    alignas(8) int32_t f7;
                    alignas(8) E3 f8;
                    alignas(8) E4 f9;
                    alignas(8) float f10;
                    alignas(8) E5 f11;
                };


                inline void set_f1(E1 val){
                    f1 = val;
                }
                inline E1& get_f1(){
                    return f1;
                }
            
                inline M191* mutable_f2(){
                    f2 = new M191();
                    return f2;
                }
                inline M191*& get_f2(){
                    return f2;
                }
            
                inline void set_f3(E2 val){
                    f3 = val;
                }
                inline E2& get_f3(){
                    return f3;
                }
            
                inline void set_f4(float val){
                    f4 = val;
                }
                inline float& get_f4(){
                    return f4;
                }
            
                inline void set_f5(uint32_t val){
                    f5 = val;
                }
                inline uint32_t& get_f5(){
                    return f5;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M190->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    fout << "M190->f3: " << f3 << std::endl;
                    fout << "M190->f4: " << f4 << std::endl;
                    fout << "M190->f5: " << f5 << std::endl;
                }
            
                ~M190(){
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M190(){
                   f2 = nullptr;
                }
            
            private:
                alignas(8) E1 f1;
                alignas(8) M191* f2;
                alignas(8) E2 f3;
                alignas(8) float f4;
                alignas(8) uint32_t f5;
            };


            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline M190* mutable_f2(){
                f2 = new M190();
                return f2;
            }
            inline M190*& get_f2(){
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
        
            inline void print_message(std::ofstream &fout){
                fout << "M189->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M189->f3: " << f3 << std::endl;
                fout << "M189->f4: " << f4 << std::endl;
                fout << "M189->f5: " << f5 << std::endl;
                fout << "M189->f6: " << f6 << std::endl;
            }
        
            ~M189(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M189(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) E1 f1;
            alignas(8) M190* f2;
            alignas(8) int32_t f3;
            alignas(8) int32_t f4;
            alignas(8) int64_t f5;
            alignas(8) int32_t f6;
        };


        inline void set_f1(E1 val){
            f1 = val;
        }
        inline E1& get_f1(){
            return f1;
        }
    
        inline M188* mutable_f2(){
            f2 = new M188();
            return f2;
        }
        inline M188*& get_f2(){
            return f2;
        }
    
        inline void set_f3(float val){
            f3 = val;
        }
        inline float& get_f3(){
            return f3;
        }
    
        inline M189* mutable_f4(){
            f4 = new M189();
            return f4;
        }
        inline M189*& get_f4(){
            return f4;
        }
    
        inline void set_f5(int64_t val){
            f5 = val;
        }
        inline int64_t& get_f5(){
            return f5;
        }
    
        inline void set_f6(uint32_t val){
            f6 = val;
        }
        inline uint32_t& get_f6(){
            return f6;
        }
    
        inline void set_f7(int32_t val){
            f7 = val;
        }
        inline int32_t& get_f7(){
            return f7;
        }
    
        inline void set_f8(uint32_t val){
            f8 = val;
        }
        inline uint32_t& get_f8(){
            return f8;
        }
    
        inline void set_f9(E2 val){
            f9 = val;
        }
        inline E2& get_f9(){
            return f9;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M187->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M187->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
            fout << "M187->f5: " << f5 << std::endl;
            fout << "M187->f6: " << f6 << std::endl;
            fout << "M187->f7: " << f7 << std::endl;
            fout << "M187->f8: " << f8 << std::endl;
            fout << "M187->f9: " << f9 << std::endl;
        }
    
        ~M187(){
            if(f2 != nullptr)
                delete f2;
            if(f4 != nullptr)
                delete f4;
        }
    
        M187(){
           f2 = nullptr;
           f4 = nullptr;
        }
    
    private:
        alignas(8) E1 f1;
        alignas(8) M188* f2;
        alignas(8) float f3;
        alignas(8) M189* f4;
        alignas(8) int64_t f5;
        alignas(8) uint32_t f6;
        alignas(8) int32_t f7;
        alignas(8) uint32_t f8;
        alignas(8) E2 f9;
    };


    inline void set_f1(E1 val){
        f1 = val;
    }
    inline E1& get_f1(){
        return f1;
    }

    inline void set_f2(int64_t val){
        f2 = val;
    }
    inline int64_t& get_f2(){
        return f2;
    }

    inline void set_f3(float val){
        f3 = val;
    }
    inline float& get_f3(){
        return f3;
    }

    inline M164* mutable_f4(){
        f4 = new M164();
        return f4;
    }
    inline M164*& get_f4(){
        return f4;
    }

    inline M187* mutable_f5(){
        f5 = new M187();
        return f5;
    }
    inline M187*& get_f5(){
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

    inline void add_f8(int32_t val){
        f8.push_back(val);
    }
    inline int32_t& get_f8(int idx){
        return f8[idx];
    }

    inline void set_f9(uint32_t val){
        f9 = val;
    }
    inline uint32_t& get_f9(){
        return f9;
    }

    inline void set_f10(E2 val){
        f10 = val;
    }
    inline E2& get_f10(){
        return f10;
    }

    inline void set_f11(int32_t val){
        f11 = val;
    }
    inline int32_t& get_f11(){
        return f11;
    }

    inline void set_f12(float val){
        f12 = val;
    }
    inline float& get_f12(){
        return f12;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M163->f1: " << f1 << std::endl;
        fout << "M163->f2: " << f2 << std::endl;
        fout << "M163->f3: " << f3 << std::endl;
        if(f4 != nullptr)
            f4->print_message(fout);
        if(f5 != nullptr)
            f5->print_message(fout);
        fout << "M163->f6: " << f6 << std::endl;
        fout << "M163->f7: " << f7 << std::endl;
        for(auto &f8_val : f8){
            fout << "M163->f8: " << f8_val << std::endl;
        }
        fout << "M163->f9: " << f9 << std::endl;
        fout << "M163->f10: " << f10 << std::endl;
        fout << "M163->f11: " << f11 << std::endl;
        fout << "M163->f12: " << f12 << std::endl;
    }

    ~M163(){
        if(f4 != nullptr)
            delete f4;
        if(f5 != nullptr)
            delete f5;
    }

    M163(){
       f4 = nullptr;
       f5 = nullptr;
    }

private:
    alignas(8) E1 f1;
    alignas(8) int64_t f2;
    alignas(8) float f3;
    alignas(8) M164* f4;
    alignas(8) M187* f5;
    alignas(8) float f6;
    alignas(8) bool f7;
    alignas(8) std::vector<int32_t> f8;
    alignas(8) uint32_t f9;
    alignas(8) E2 f10;
    alignas(8) int32_t f11;
    alignas(8) float f12;
};


class alignas(8) M193 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 67,
        E1_CONST_2 = 16,
        E1_CONST_3 = 84,
        E1_CONST_4 = 86,
        E1_CONST_5 = 58,
    };
    
    class alignas(8) M194 : public M_base
    {
    public:
        class alignas(8) M195 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M195->f1: " << f1 << std::endl;
            }
        
            ~M195(){
            }
        
            M195(){
            }
        
        private:
            alignas(8) int32_t f1;
        };


        inline M195* mutable_f1(){
            f1 = new M195();
            return f1;
        }
        inline M195*& get_f1(){
            return f1;
        }
    
        inline void set_f2(bool val){
            f2 = val;
        }
        inline bool& get_f2(){
            return f2;
        }
    
        inline void set_f3(uint32_t val){
            f3 = val;
        }
        inline uint32_t& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M194->f2: " << f2 << std::endl;
            fout << "M194->f3: " << f3 << std::endl;
        }
    
        ~M194(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M194(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M195* f1;
        alignas(8) bool f2;
        alignas(8) uint32_t f3;
    };


    class alignas(8) M196 : public M_base
    {
    public:
        class alignas(8) M197 : public M_base
        {
        public:
            class alignas(8) M198 : public M_base
            {
            public:
                class alignas(8) M199 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 96,
                        E1_CONST_2 = 97,
                        E1_CONST_3 = 66,
                        E1_CONST_4 = 39,
                        E1_CONST_5 = 125,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
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
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M199->f1: " << f1 << std::endl;
                        fout << "M199->f2: " << f2 << std::endl;
                        fout << "M199->f3: " << f3 << std::endl;
                    }
                
                    ~M199(){
                    }
                
                    M199(){
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) uint32_t f2;
                    alignas(8) int32_t f3;
                };


                inline void set_f1(string val){
                    f1 = val;
                }
                inline string& get_f1(){
                    return f1;
                }
            
                inline M199* mutable_f2(){
                    f2 = new M199();
                    return f2;
                }
                inline M199*& get_f2(){
                    return f2;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M198->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
                }
            
                ~M198(){
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M198(){
                   f2 = nullptr;
                }
            
            private:
                alignas(8) string f1;
                alignas(8) M199* f2;
            };


            class alignas(8) M200 : public M_base
            {
            public:
                class alignas(8) M201 : public M_base
                {
                public:
                    inline void set_f1(uint32_t val){
                        f1 = val;
                    }
                    inline uint32_t& get_f1(){
                        return f1;
                    }
                
                    inline void add_f2(string val){
                        f2.push_back(val);
                    }
                    inline string& get_f2(int idx){
                        return f2[idx];
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M201->f1: " << f1 << std::endl;
                        for(auto &f2_val : f2){
                            fout << "M201->f2: " << f2_val << std::endl;
                        }
                    }
                
                    ~M201(){
                    }
                
                    M201(){
                    }
                
                private:
                    alignas(8) uint32_t f1;
                    alignas(8) std::vector<string> f2;
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
            
                inline M201* mutable_f3(){
                    f3 = new M201();
                    return f3;
                }
                inline M201*& get_f3(){
                    return f3;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M200->f1: " << f1 << std::endl;
                    fout << "M200->f2: " << f2 << std::endl;
                    if(f3 != nullptr)
                        f3->print_message(fout);
                }
            
                ~M200(){
                    if(f3 != nullptr)
                        delete f3;
                }
            
                M200(){
                   f3 = nullptr;
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) int64_t f2;
                alignas(8) M201* f3;
            };


            class alignas(8) M202 : public M_base
            {
            public:
                inline void set_f1(int32_t val){
                    f1 = val;
                }
                inline int32_t& get_f1(){
                    return f1;
                }
            
                inline void set_f2(uint32_t val){
                    f2 = val;
                }
                inline uint32_t& get_f2(){
                    return f2;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M202->f1: " << f1 << std::endl;
                    fout << "M202->f2: " << f2 << std::endl;
                }
            
                ~M202(){
                }
            
                M202(){
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) uint32_t f2;
            };


            class alignas(8) M203 : public M_base
            {
            public:
                class alignas(8) M204 : public M_base
                {
                public:
                    class alignas(8) M205 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 116,
                            E1_CONST_2 = 85,
                            E1_CONST_3 = 55,
                            E1_CONST_4 = 120,
                            E1_CONST_5 = 58,
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
                    
                        inline void set_f4(int64_t val){
                            f4 = val;
                        }
                        inline int64_t& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(E1 val){
                            f5 = val;
                        }
                        inline E1& get_f5(){
                            return f5;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M205->f1: " << f1 << std::endl;
                            fout << "M205->f2: " << f2 << std::endl;
                            fout << "M205->f3: " << f3 << std::endl;
                            fout << "M205->f4: " << f4 << std::endl;
                            fout << "M205->f5: " << f5 << std::endl;
                        }
                    
                        ~M205(){
                        }
                    
                        M205(){
                        }
                    
                    private:
                        alignas(8) int32_t f1;
                        alignas(8) int64_t f2;
                        alignas(8) int64_t f3;
                        alignas(8) int64_t f4;
                        alignas(8) E1 f5;
                    };


                    class alignas(8) M206 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 34,
                            E1_CONST_2 = 38,
                            E1_CONST_3 = 103,
                            E1_CONST_4 = 105,
                            E1_CONST_5 = 20,
                        };
                        
                        class alignas(8) M207 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 66,
                                E1_CONST_2 = 4,
                                E1_CONST_3 = 17,
                                E1_CONST_4 = 125,
                                E1_CONST_5 = 62,
                            };
                            
                            enum E2 {
                                E2_CONST_1 = 103,
                                E2_CONST_2 = 104,
                                E2_CONST_3 = 114,
                                E2_CONST_4 = 118,
                                E2_CONST_5 = 55,
                            };
                            
                            class alignas(8) M208 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 7,
                                    E1_CONST_2 = 14,
                                    E1_CONST_3 = 85,
                                    E1_CONST_4 = 57,
                                    E1_CONST_5 = 63,
                                };
                                
                                enum E2 {
                                    E2_CONST_1 = 8,
                                    E2_CONST_2 = 111,
                                    E2_CONST_3 = 86,
                                    E2_CONST_4 = 123,
                                    E2_CONST_5 = 63,
                                };
                                
                                class alignas(8) M209 : public M_base
                                {
                                public:
                                    enum E1 {
                                        E1_CONST_1 = 39,
                                        E1_CONST_2 = 109,
                                        E1_CONST_3 = 114,
                                        E1_CONST_4 = 51,
                                        E1_CONST_5 = 91,
                                    };
                                    
                                    class alignas(8) M210 : public M_base
                                    {
                                    public:
                                        enum E1 {
                                            E1_CONST_1 = 3,
                                            E1_CONST_2 = 35,
                                            E1_CONST_3 = 39,
                                            E1_CONST_4 = 114,
                                            E1_CONST_5 = 29,
                                        };
                                        
                                        class alignas(8) M211 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 2,
                                                E1_CONST_2 = 101,
                                                E1_CONST_3 = 13,
                                                E1_CONST_4 = 118,
                                                E1_CONST_5 = 24,
                                            };
                                            
                                            enum E2 {
                                                E2_CONST_1 = 67,
                                                E2_CONST_2 = 40,
                                                E2_CONST_3 = 9,
                                                E2_CONST_4 = 111,
                                                E2_CONST_5 = 126,
                                            };
                                            
                                            enum E3 {
                                                E3_CONST_1 = 100,
                                                E3_CONST_2 = 109,
                                                E3_CONST_3 = 27,
                                                E3_CONST_4 = 60,
                                                E3_CONST_5 = 62,
                                            };
                                            
                                            enum E4 {
                                                E4_CONST_1 = 32,
                                                E4_CONST_2 = 37,
                                                E4_CONST_3 = 46,
                                                E4_CONST_4 = 18,
                                                E4_CONST_5 = 27,
                                            };
                                            
                                            class alignas(8) M212 : public M_base
                                            {
                                            public:
                                                class alignas(8) M213 : public M_base
                                                {
                                                public:
                                                    class alignas(8) M214 : public M_base
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
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M214->f1: " << f1 << std::endl;
                                                            fout << "M214->f2: " << f2 << std::endl;
                                                        }
                                                    
                                                        ~M214(){
                                                        }
                                                    
                                                        M214(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) int64_t f1;
                                                        alignas(8) string f2;
                                                    };


                                                    inline M214* mutable_f1(){
                                                        f1 = new M214();
                                                        return f1;
                                                    }
                                                    inline M214*& get_f1(){
                                                        return f1;
                                                    }
                                                
                                                    inline void set_f2(bool val){
                                                        f2 = val;
                                                    }
                                                    inline bool& get_f2(){
                                                        return f2;
                                                    }
                                                
                                                    inline void set_f3(uint32_t val){
                                                        f3 = val;
                                                    }
                                                    inline uint32_t& get_f3(){
                                                        return f3;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        if(f1 != nullptr)
                                                            f1->print_message(fout);
                                                        fout << "M213->f2: " << f2 << std::endl;
                                                        fout << "M213->f3: " << f3 << std::endl;
                                                    }
                                                
                                                    ~M213(){
                                                        if(f1 != nullptr)
                                                            delete f1;
                                                    }
                                                
                                                    M213(){
                                                       f1 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) M214* f1;
                                                    alignas(8) bool f2;
                                                    alignas(8) uint32_t f3;
                                                };


                                                inline void set_f1(uint32_t val){
                                                    f1 = val;
                                                }
                                                inline uint32_t& get_f1(){
                                                    return f1;
                                                }
                                            
                                                inline void set_f2(string val){
                                                    f2 = val;
                                                }
                                                inline string& get_f2(){
                                                    return f2;
                                                }
                                            
                                                inline M213* mutable_f3(){
                                                    f3 = new M213();
                                                    return f3;
                                                }
                                                inline M213*& get_f3(){
                                                    return f3;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    fout << "M212->f1: " << f1 << std::endl;
                                                    fout << "M212->f2: " << f2 << std::endl;
                                                    if(f3 != nullptr)
                                                        f3->print_message(fout);
                                                }
                                            
                                                ~M212(){
                                                    if(f3 != nullptr)
                                                        delete f3;
                                                }
                                            
                                                M212(){
                                                   f3 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) uint32_t f1;
                                                alignas(8) string f2;
                                                alignas(8) M213* f3;
                                            };


                                            inline void set_f1(E1 val){
                                                f1 = val;
                                            }
                                            inline E1& get_f1(){
                                                return f1;
                                            }
                                        
                                            inline void set_f2(E2 val){
                                                f2 = val;
                                            }
                                            inline E2& get_f2(){
                                                return f2;
                                            }
                                        
                                            inline M212* mutable_f3(){
                                                f3 = new M212();
                                                return f3;
                                            }
                                            inline M212*& get_f3(){
                                                return f3;
                                            }
                                        
                                            inline void set_f4(E3 val){
                                                f4 = val;
                                            }
                                            inline E3& get_f4(){
                                                return f4;
                                            }
                                        
                                            inline void set_f5(E4 val){
                                                f5 = val;
                                            }
                                            inline E4& get_f5(){
                                                return f5;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M211->f1: " << f1 << std::endl;
                                                fout << "M211->f2: " << f2 << std::endl;
                                                if(f3 != nullptr)
                                                    f3->print_message(fout);
                                                fout << "M211->f4: " << f4 << std::endl;
                                                fout << "M211->f5: " << f5 << std::endl;
                                            }
                                        
                                            ~M211(){
                                                if(f3 != nullptr)
                                                    delete f3;
                                            }
                                        
                                            M211(){
                                               f3 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) E1 f1;
                                            alignas(8) E2 f2;
                                            alignas(8) M212* f3;
                                            alignas(8) E3 f4;
                                            alignas(8) E4 f5;
                                        };


                                        inline M211* mutable_f1(){
                                            f1 = new M211();
                                            return f1;
                                        }
                                        inline M211*& get_f1(){
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
                                            if(f1 != nullptr)
                                                f1->print_message(fout);
                                            fout << "M210->f2: " << f2 << std::endl;
                                            fout << "M210->f3: " << f3 << std::endl;
                                        }
                                    
                                        ~M210(){
                                            if(f1 != nullptr)
                                                delete f1;
                                        }
                                    
                                        M210(){
                                           f1 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) M211* f1;
                                        alignas(8) bool f2;
                                        alignas(8) E1 f3;
                                    };


                                    inline void set_f1(E1 val){
                                        f1 = val;
                                    }
                                    inline E1& get_f1(){
                                        return f1;
                                    }
                                
                                    inline M210* mutable_f2(){
                                        f2 = new M210();
                                        return f2;
                                    }
                                    inline M210*& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void set_f3(uint32_t val){
                                        f3 = val;
                                    }
                                    inline uint32_t& get_f3(){
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
                                        fout << "M209->f1: " << f1 << std::endl;
                                        if(f2 != nullptr)
                                            f2->print_message(fout);
                                        fout << "M209->f3: " << f3 << std::endl;
                                        fout << "M209->f4: " << f4 << std::endl;
                                        fout << "M209->f5: " << f5 << std::endl;
                                    }
                                
                                    ~M209(){
                                        if(f2 != nullptr)
                                            delete f2;
                                    }
                                
                                    M209(){
                                       f2 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) E1 f1;
                                    alignas(8) M210* f2;
                                    alignas(8) uint32_t f3;
                                    alignas(8) int32_t f4;
                                    alignas(8) bool f5;
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
                            
                                inline M209* mutable_f4(){
                                    f4 = new M209();
                                    return f4;
                                }
                                inline M209*& get_f4(){
                                    return f4;
                                }
                            
                                inline void set_f5(E2 val){
                                    f5 = val;
                                }
                                inline E2& get_f5(){
                                    return f5;
                                }
                            
                                inline void set_f6(int32_t val){
                                    f6 = val;
                                }
                                inline int32_t& get_f6(){
                                    return f6;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M208->f1: " << f1 << std::endl;
                                    fout << "M208->f2: " << f2 << std::endl;
                                    fout << "M208->f3: " << f3 << std::endl;
                                    if(f4 != nullptr)
                                        f4->print_message(fout);
                                    fout << "M208->f5: " << f5 << std::endl;
                                    fout << "M208->f6: " << f6 << std::endl;
                                }
                            
                                ~M208(){
                                    if(f4 != nullptr)
                                        delete f4;
                                }
                            
                                M208(){
                                   f4 = nullptr;
                                }
                            
                            private:
                                alignas(8) E1 f1;
                                alignas(8) int32_t f2;
                                alignas(8) int32_t f3;
                                alignas(8) M209* f4;
                                alignas(8) E2 f5;
                                alignas(8) int32_t f6;
                            };


                            inline M208* mutable_f1(){
                                f1 = new M208();
                                return f1;
                            }
                            inline M208*& get_f1(){
                                return f1;
                            }
                        
                            inline void set_f2(E1 val){
                                f2 = val;
                            }
                            inline E1& get_f2(){
                                return f2;
                            }
                        
                            inline void set_f3(E2 val){
                                f3 = val;
                            }
                            inline E2& get_f3(){
                                return f3;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                if(f1 != nullptr)
                                    f1->print_message(fout);
                                fout << "M207->f2: " << f2 << std::endl;
                                fout << "M207->f3: " << f3 << std::endl;
                            }
                        
                            ~M207(){
                                if(f1 != nullptr)
                                    delete f1;
                            }
                        
                            M207(){
                               f1 = nullptr;
                            }
                        
                        private:
                            alignas(8) M208* f1;
                            alignas(8) E1 f2;
                            alignas(8) E2 f3;
                        };


                        class alignas(8) M215 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 64,
                                E1_CONST_2 = 35,
                                E1_CONST_3 = 68,
                                E1_CONST_4 = 58,
                                E1_CONST_5 = 29,
                            };
                            
                            inline void set_f1(float val){
                                f1 = val;
                            }
                            inline float& get_f1(){
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
                        
                            inline void set_f4(float val){
                                f4 = val;
                            }
                            inline float& get_f4(){
                                return f4;
                            }
                        
                            inline void set_f5(E1 val){
                                f5 = val;
                            }
                            inline E1& get_f5(){
                                return f5;
                            }
                        
                            inline void set_f6(uint32_t val){
                                f6 = val;
                            }
                            inline uint32_t& get_f6(){
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
                        
                            inline void set_f9(int64_t val){
                                f9 = val;
                            }
                            inline int64_t& get_f9(){
                                return f9;
                            }
                        
                            inline void set_f10(int32_t val){
                                f10 = val;
                            }
                            inline int32_t& get_f10(){
                                return f10;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M215->f1: " << f1 << std::endl;
                                fout << "M215->f2: " << f2 << std::endl;
                                fout << "M215->f3: " << f3 << std::endl;
                                fout << "M215->f4: " << f4 << std::endl;
                                fout << "M215->f5: " << f5 << std::endl;
                                fout << "M215->f6: " << f6 << std::endl;
                                fout << "M215->f7: " << f7 << std::endl;
                                fout << "M215->f8: " << f8 << std::endl;
                                fout << "M215->f9: " << f9 << std::endl;
                                fout << "M215->f10: " << f10 << std::endl;
                            }
                        
                            ~M215(){
                            }
                        
                            M215(){
                            }
                        
                        private:
                            alignas(8) float f1;
                            alignas(8) bool f2;
                            alignas(8) string f3;
                            alignas(8) float f4;
                            alignas(8) E1 f5;
                            alignas(8) uint32_t f6;
                            alignas(8) string f7;
                            alignas(8) int32_t f8;
                            alignas(8) int64_t f9;
                            alignas(8) int32_t f10;
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
                    
                        inline M207* mutable_f3(){
                            f3 = new M207();
                            return f3;
                        }
                        inline M207*& get_f3(){
                            return f3;
                        }
                    
                        inline M215* mutable_f4(){
                            f4 = new M215();
                            return f4;
                        }
                        inline M215*& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(E1 val){
                            f5 = val;
                        }
                        inline E1& get_f5(){
                            return f5;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M206->f1: " << f1 << std::endl;
                            fout << "M206->f2: " << f2 << std::endl;
                            if(f3 != nullptr)
                                f3->print_message(fout);
                            if(f4 != nullptr)
                                f4->print_message(fout);
                            fout << "M206->f5: " << f5 << std::endl;
                        }
                    
                        ~M206(){
                            if(f3 != nullptr)
                                delete f3;
                            if(f4 != nullptr)
                                delete f4;
                        }
                    
                        M206(){
                           f3 = nullptr;
                           f4 = nullptr;
                        }
                    
                    private:
                        alignas(8) uint32_t f1;
                        alignas(8) int32_t f2;
                        alignas(8) M207* f3;
                        alignas(8) M215* f4;
                        alignas(8) E1 f5;
                    };


                    inline M205* mutable_f1(){
                        f1 = new M205();
                        return f1;
                    }
                    inline M205*& get_f1(){
                        return f1;
                    }
                
                    inline void set_f2(uint32_t val){
                        f2 = val;
                    }
                    inline uint32_t& get_f2(){
                        return f2;
                    }
                
                    inline void add_f3(string val){
                        f3.push_back(val);
                    }
                    inline string& get_f3(int idx){
                        return f3[idx];
                    }
                
                    inline void set_f4(uint32_t val){
                        f4 = val;
                    }
                    inline uint32_t& get_f4(){
                        return f4;
                    }
                
                    inline void set_f5(float val){
                        f5 = val;
                    }
                    inline float& get_f5(){
                        return f5;
                    }
                
                    inline M206* mutable_f6(){
                        f6 = new M206();
                        return f6;
                    }
                    inline M206*& get_f6(){
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
                
                    inline void print_message(std::ofstream &fout){
                        if(f1 != nullptr)
                            f1->print_message(fout);
                        fout << "M204->f2: " << f2 << std::endl;
                        for(auto &f3_val : f3){
                            fout << "M204->f3: " << f3_val << std::endl;
                        }
                        fout << "M204->f4: " << f4 << std::endl;
                        fout << "M204->f5: " << f5 << std::endl;
                        if(f6 != nullptr)
                            f6->print_message(fout);
                        fout << "M204->f7: " << f7 << std::endl;
                        fout << "M204->f8: " << f8 << std::endl;
                    }
                
                    ~M204(){
                        if(f1 != nullptr)
                            delete f1;
                        if(f6 != nullptr)
                            delete f6;
                    }
                
                    M204(){
                       f1 = nullptr;
                       f6 = nullptr;
                    }
                
                private:
                    alignas(8) M205* f1;
                    alignas(8) uint32_t f2;
                    alignas(8) std::vector<string> f3;
                    alignas(8) uint32_t f4;
                    alignas(8) float f5;
                    alignas(8) M206* f6;
                    alignas(8) float f7;
                    alignas(8) int32_t f8;
                };


                inline M204* mutable_f1(){
                    f1 = new M204();
                    return f1;
                }
                inline M204*& get_f1(){
                    return f1;
                }
            
                inline void set_f2(bool val){
                    f2 = val;
                }
                inline bool& get_f2(){
                    return f2;
                }
            
                inline void print_message(std::ofstream &fout){
                    if(f1 != nullptr)
                        f1->print_message(fout);
                    fout << "M203->f2: " << f2 << std::endl;
                }
            
                ~M203(){
                    if(f1 != nullptr)
                        delete f1;
                }
            
                M203(){
                   f1 = nullptr;
                }
            
            private:
                alignas(8) M204* f1;
                alignas(8) bool f2;
            };


            inline void set_f1(uint32_t val){
                f1 = val;
            }
            inline uint32_t& get_f1(){
                return f1;
            }
        
            inline void set_f2(string val){
                f2 = val;
            }
            inline string& get_f2(){
                return f2;
            }
        
            inline M198* mutable_f3(){
                f3 = new M198();
                return f3;
            }
            inline M198*& get_f3(){
                return f3;
            }
        
            inline M200* mutable_f4(){
                f4 = new M200();
                return f4;
            }
            inline M200*& get_f4(){
                return f4;
            }
        
            inline M202* mutable_f5(){
                f5 = new M202();
                return f5;
            }
            inline M202*& get_f5(){
                return f5;
            }
        
            inline M203* mutable_f6(){
                f6 = new M203();
                return f6;
            }
            inline M203*& get_f6(){
                return f6;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M197->f1: " << f1 << std::endl;
                fout << "M197->f2: " << f2 << std::endl;
                if(f3 != nullptr)
                    f3->print_message(fout);
                if(f4 != nullptr)
                    f4->print_message(fout);
                if(f5 != nullptr)
                    f5->print_message(fout);
                if(f6 != nullptr)
                    f6->print_message(fout);
            }
        
            ~M197(){
                if(f3 != nullptr)
                    delete f3;
                if(f4 != nullptr)
                    delete f4;
                if(f5 != nullptr)
                    delete f5;
                if(f6 != nullptr)
                    delete f6;
            }
        
            M197(){
               f3 = nullptr;
               f4 = nullptr;
               f5 = nullptr;
               f6 = nullptr;
            }
        
        private:
            alignas(8) uint32_t f1;
            alignas(8) string f2;
            alignas(8) M198* f3;
            alignas(8) M200* f4;
            alignas(8) M202* f5;
            alignas(8) M203* f6;
        };


        inline void set_f1(float val){
            f1 = val;
        }
        inline float& get_f1(){
            return f1;
        }
    
        inline M197* mutable_f2(){
            f2 = new M197();
            return f2;
        }
        inline M197*& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M196->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
        }
    
        ~M196(){
            if(f2 != nullptr)
                delete f2;
        }
    
        M196(){
           f2 = nullptr;
        }
    
    private:
        alignas(8) float f1;
        alignas(8) M197* f2;
    };


    class alignas(8) M216 : public M_base
    {
    public:
        class alignas(8) M217 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 5,
                E1_CONST_2 = 80,
                E1_CONST_3 = 82,
                E1_CONST_4 = 114,
                E1_CONST_5 = 119,
            };
            
            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M217->f1: " << f1 << std::endl;
            }
        
            ~M217(){
            }
        
            M217(){
            }
        
        private:
            alignas(8) E1 f1;
        };


        class alignas(8) M218 : public M_base
        {
        public:
            inline void set_f1(uint32_t val){
                f1 = val;
            }
            inline uint32_t& get_f1(){
                return f1;
            }
        
            inline void set_f2(float val){
                f2 = val;
            }
            inline float& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M218->f1: " << f1 << std::endl;
                fout << "M218->f2: " << f2 << std::endl;
            }
        
            ~M218(){
            }
        
            M218(){
            }
        
        private:
            alignas(8) uint32_t f1;
            alignas(8) float f2;
        };


        class alignas(8) M219 : public M_base
        {
        public:
            inline void set_f1(float val){
                f1 = val;
            }
            inline float& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M219->f1: " << f1 << std::endl;
            }
        
            ~M219(){
            }
        
            M219(){
            }
        
        private:
            alignas(8) float f1;
        };


        class alignas(8) M220 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 105,
                E1_CONST_2 = 10,
                E1_CONST_3 = 76,
                E1_CONST_4 = 61,
                E1_CONST_5 = 62,
            };
            
            class alignas(8) M221 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 69,
                    E1_CONST_2 = 80,
                    E1_CONST_3 = 81,
                    E1_CONST_4 = 19,
                    E1_CONST_5 = 122,
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
            
                inline void set_f3(uint32_t val){
                    f3 = val;
                }
                inline uint32_t& get_f3(){
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
                    fout << "M221->f1: " << f1 << std::endl;
                    fout << "M221->f2: " << f2 << std::endl;
                    fout << "M221->f3: " << f3 << std::endl;
                    fout << "M221->f4: " << f4 << std::endl;
                    fout << "M221->f5: " << f5 << std::endl;
                }
            
                ~M221(){
                }
            
                M221(){
                }
            
            private:
                alignas(8) string f1;
                alignas(8) E1 f2;
                alignas(8) uint32_t f3;
                alignas(8) uint32_t f4;
                alignas(8) int32_t f5;
            };


            inline M221* mutable_f1(){
                f1 = new M221();
                return f1;
            }
            inline M221*& get_f1(){
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
                if(f1 != nullptr)
                    f1->print_message(fout);
                fout << "M220->f2: " << f2 << std::endl;
                fout << "M220->f3: " << f3 << std::endl;
            }
        
            ~M220(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M220(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M221* f1;
            alignas(8) bool f2;
            alignas(8) E1 f3;
        };


        inline M217* mutable_f1(){
            f1 = new M217();
            return f1;
        }
        inline M217*& get_f1(){
            return f1;
        }
    
        inline M218* mutable_f2(){
            f2 = new M218();
            return f2;
        }
        inline M218*& get_f2(){
            return f2;
        }
    
        inline M219* mutable_f3(){
            f3 = new M219();
            return f3;
        }
        inline M219*& get_f3(){
            return f3;
        }
    
        inline void set_f4(float val){
            f4 = val;
        }
        inline float& get_f4(){
            return f4;
        }
    
        inline M220* mutable_f5(){
            f5 = new M220();
            return f5;
        }
        inline M220*& get_f5(){
            return f5;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            if(f2 != nullptr)
                f2->print_message(fout);
            if(f3 != nullptr)
                f3->print_message(fout);
            fout << "M216->f4: " << f4 << std::endl;
            if(f5 != nullptr)
                f5->print_message(fout);
        }
    
        ~M216(){
            if(f1 != nullptr)
                delete f1;
            if(f2 != nullptr)
                delete f2;
            if(f3 != nullptr)
                delete f3;
            if(f5 != nullptr)
                delete f5;
        }
    
        M216(){
           f1 = nullptr;
           f2 = nullptr;
           f3 = nullptr;
           f5 = nullptr;
        }
    
    private:
        alignas(8) M217* f1;
        alignas(8) M218* f2;
        alignas(8) M219* f3;
        alignas(8) float f4;
        alignas(8) M220* f5;
    };


    class alignas(8) M222 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 65,
            E1_CONST_2 = 67,
            E1_CONST_3 = 26,
            E1_CONST_4 = 28,
            E1_CONST_5 = 29,
        };
        
        enum E2 {
            E2_CONST_1 = 36,
            E2_CONST_2 = 15,
            E2_CONST_3 = 115,
            E2_CONST_4 = 119,
            E2_CONST_5 = 31,
        };
        
        enum E3 {
            E3_CONST_1 = 7,
            E3_CONST_2 = 43,
            E3_CONST_3 = 109,
            E3_CONST_4 = 115,
            E3_CONST_5 = 29,
        };
        
        inline void set_f1(uint32_t val){
            f1 = val;
        }
        inline uint32_t& get_f1(){
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
    
        inline void set_f4(E2 val){
            f4 = val;
        }
        inline E2& get_f4(){
            return f4;
        }
    
        inline void set_f5(uint32_t val){
            f5 = val;
        }
        inline uint32_t& get_f5(){
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
    
        inline void set_f8(E3 val){
            f8 = val;
        }
        inline E3& get_f8(){
            return f8;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M222->f1: " << f1 << std::endl;
            fout << "M222->f2: " << f2 << std::endl;
            fout << "M222->f3: " << f3 << std::endl;
            fout << "M222->f4: " << f4 << std::endl;
            fout << "M222->f5: " << f5 << std::endl;
            fout << "M222->f6: " << f6 << std::endl;
            fout << "M222->f7: " << f7 << std::endl;
            fout << "M222->f8: " << f8 << std::endl;
        }
    
        ~M222(){
        }
    
        M222(){
        }
    
    private:
        alignas(8) uint32_t f1;
        alignas(8) E1 f2;
        alignas(8) int64_t f3;
        alignas(8) E2 f4;
        alignas(8) uint32_t f5;
        alignas(8) string f6;
        alignas(8) int64_t f7;
        alignas(8) E3 f8;
    };


    inline void set_f1(int64_t val){
        f1 = val;
    }
    inline int64_t& get_f1(){
        return f1;
    }

    inline void set_f2(uint32_t val){
        f2 = val;
    }
    inline uint32_t& get_f2(){
        return f2;
    }

    inline void set_f3(string val){
        f3 = val;
    }
    inline string& get_f3(){
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

    inline M194* mutable_f8(){
        f8 = new M194();
        return f8;
    }
    inline M194*& get_f8(){
        return f8;
    }

    inline void set_f9(uint32_t val){
        f9 = val;
    }
    inline uint32_t& get_f9(){
        return f9;
    }

    inline void set_f10(float val){
        f10 = val;
    }
    inline float& get_f10(){
        return f10;
    }

    inline M196* mutable_f11(){
        f11 = new M196();
        return f11;
    }
    inline M196*& get_f11(){
        return f11;
    }

    inline M216* mutable_f12(){
        f12 = new M216();
        return f12;
    }
    inline M216*& get_f12(){
        return f12;
    }

    inline void set_f13(E1 val){
        f13 = val;
    }
    inline E1& get_f13(){
        return f13;
    }

    inline M222* mutable_f14(){
        f14 = new M222();
        return f14;
    }
    inline M222*& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M193->f1: " << f1 << std::endl;
        fout << "M193->f2: " << f2 << std::endl;
        fout << "M193->f3: " << f3 << std::endl;
        fout << "M193->f4: " << f4 << std::endl;
        fout << "M193->f5: " << f5 << std::endl;
        fout << "M193->f6: " << f6 << std::endl;
        fout << "M193->f7: " << f7 << std::endl;
        if(f8 != nullptr)
            f8->print_message(fout);
        fout << "M193->f9: " << f9 << std::endl;
        fout << "M193->f10: " << f10 << std::endl;
        if(f11 != nullptr)
            f11->print_message(fout);
        if(f12 != nullptr)
            f12->print_message(fout);
        fout << "M193->f13: " << f13 << std::endl;
        if(f14 != nullptr)
            f14->print_message(fout);
    }

    ~M193(){
        if(f8 != nullptr)
            delete f8;
        if(f11 != nullptr)
            delete f11;
        if(f12 != nullptr)
            delete f12;
        if(f14 != nullptr)
            delete f14;
    }

    M193(){
       f8 = nullptr;
       f11 = nullptr;
       f12 = nullptr;
       f14 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) uint32_t f2;
    alignas(8) string f3;
    alignas(8) uint32_t f4;
    alignas(8) int32_t f5;
    alignas(8) int32_t f6;
    alignas(8) bool f7;
    alignas(8) M194* f8;
    alignas(8) uint32_t f9;
    alignas(8) float f10;
    alignas(8) M196* f11;
    alignas(8) M216* f12;
    alignas(8) E1 f13;
    alignas(8) M222* f14;
};


class alignas(8) M223 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 59,
        E1_CONST_2 = 79,
        E1_CONST_3 = 116,
        E1_CONST_4 = 123,
        E1_CONST_5 = 124,
    };
    
    enum E2 {
        E2_CONST_1 = 79,
        E2_CONST_2 = 125,
        E2_CONST_3 = 89,
        E2_CONST_4 = 122,
        E2_CONST_5 = 93,
    };
    
    enum E3 {
        E3_CONST_1 = 0,
        E3_CONST_2 = 18,
        E3_CONST_3 = 56,
        E3_CONST_4 = 57,
        E3_CONST_5 = 125,
    };
    
    enum E4 {
        E4_CONST_1 = 38,
        E4_CONST_2 = 6,
        E4_CONST_3 = 108,
        E4_CONST_4 = 82,
        E4_CONST_5 = 119,
    };
    
    class alignas(8) M224 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 48,
            E1_CONST_2 = 81,
            E1_CONST_3 = 82,
            E1_CONST_4 = 119,
            E1_CONST_5 = 55,
        };
        
        class alignas(8) M225 : public M_base
        {
        public:
            class alignas(8) M226 : public M_base
            {
            public:
                class alignas(8) M227 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 42,
                        E1_CONST_2 = 82,
                        E1_CONST_3 = 121,
                        E1_CONST_4 = 58,
                        E1_CONST_5 = 95,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 68,
                        E2_CONST_2 = 8,
                        E2_CONST_3 = 17,
                        E2_CONST_4 = 21,
                        E2_CONST_5 = 62,
                    };
                    
                    class alignas(8) M228 : public M_base
                    {
                    public:
                        inline void set_f1(float val){
                            f1 = val;
                        }
                        inline float& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(bool val){
                            f2 = val;
                        }
                        inline bool& get_f2(){
                            return f2;
                        }
                    
                        inline void set_f3(float val){
                            f3 = val;
                        }
                        inline float& get_f3(){
                            return f3;
                        }
                    
                        inline void set_f4(bool val){
                            f4 = val;
                        }
                        inline bool& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(float val){
                            f5 = val;
                        }
                        inline float& get_f5(){
                            return f5;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M228->f1: " << f1 << std::endl;
                            fout << "M228->f2: " << f2 << std::endl;
                            fout << "M228->f3: " << f3 << std::endl;
                            fout << "M228->f4: " << f4 << std::endl;
                            fout << "M228->f5: " << f5 << std::endl;
                        }
                    
                        ~M228(){
                        }
                    
                        M228(){
                        }
                    
                    private:
                        alignas(8) float f1;
                        alignas(8) bool f2;
                        alignas(8) float f3;
                        alignas(8) bool f4;
                        alignas(8) float f5;
                    };


                    class alignas(8) M229 : public M_base
                    {
                    public:
                        inline void set_f1(bool val){
                            f1 = val;
                        }
                        inline bool& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(double val){
                            f2 = val;
                        }
                        inline double& get_f2(){
                            return f2;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M229->f1: " << f1 << std::endl;
                            fout << "M229->f2: " << f2 << std::endl;
                        }
                    
                        ~M229(){
                        }
                    
                        M229(){
                        }
                    
                    private:
                        alignas(8) bool f1;
                        alignas(8) double f2;
                    };


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
                
                    inline M228* mutable_f5(){
                        f5 = new M228();
                        return f5;
                    }
                    inline M228*& get_f5(){
                        return f5;
                    }
                
                    inline void set_f6(E1 val){
                        f6 = val;
                    }
                    inline E1& get_f6(){
                        return f6;
                    }
                
                    inline void set_f7(E2 val){
                        f7 = val;
                    }
                    inline E2& get_f7(){
                        return f7;
                    }
                
                    inline M229* mutable_f8(){
                        f8 = new M229();
                        return f8;
                    }
                    inline M229*& get_f8(){
                        return f8;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M227->f1: " << f1 << std::endl;
                        fout << "M227->f2: " << f2 << std::endl;
                        fout << "M227->f3: " << f3 << std::endl;
                        fout << "M227->f4: " << f4 << std::endl;
                        if(f5 != nullptr)
                            f5->print_message(fout);
                        fout << "M227->f6: " << f6 << std::endl;
                        fout << "M227->f7: " << f7 << std::endl;
                        if(f8 != nullptr)
                            f8->print_message(fout);
                    }
                
                    ~M227(){
                        if(f5 != nullptr)
                            delete f5;
                        if(f8 != nullptr)
                            delete f8;
                    }
                
                    M227(){
                       f5 = nullptr;
                       f8 = nullptr;
                    }
                
                private:
                    alignas(8) float f1;
                    alignas(8) int32_t f2;
                    alignas(8) float f3;
                    alignas(8) int32_t f4;
                    alignas(8) M228* f5;
                    alignas(8) E1 f6;
                    alignas(8) E2 f7;
                    alignas(8) M229* f8;
                };


                inline void add_f1(string val){
                    f1.push_back(val);
                }
                inline string& get_f1(int idx){
                    return f1[idx];
                }
            
                inline M227* mutable_f2(){
                    f2 = new M227();
                    return f2;
                }
                inline M227*& get_f2(){
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
            
                inline void set_f5(uint64_t val){
                    f5 = val;
                }
                inline uint64_t& get_f5(){
                    return f5;
                }
            
                inline void print_message(std::ofstream &fout){
                    for(auto &f1_val : f1){
                        fout << "M226->f1: " << f1_val << std::endl;
                    }
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    fout << "M226->f3: " << f3 << std::endl;
                    fout << "M226->f4: " << f4 << std::endl;
                    fout << "M226->f5: " << f5 << std::endl;
                }
            
                ~M226(){
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M226(){
                   f2 = nullptr;
                }
            
            private:
                alignas(8) std::vector<string> f1;
                alignas(8) M227* f2;
                alignas(8) float f3;
                alignas(8) int32_t f4;
                alignas(8) uint64_t f5;
            };


            inline M226* mutable_f1(){
                f1 = new M226();
                return f1;
            }
            inline M226*& get_f1(){
                return f1;
            }
        
            inline void set_f2(float val){
                f2 = val;
            }
            inline float& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                if(f1 != nullptr)
                    f1->print_message(fout);
                fout << "M225->f2: " << f2 << std::endl;
            }
        
            ~M225(){
                if(f1 != nullptr)
                    delete f1;
            }
        
            M225(){
               f1 = nullptr;
            }
        
        private:
            alignas(8) M226* f1;
            alignas(8) float f2;
        };


        inline M225* mutable_f1(){
            f1 = new M225();
            return f1;
        }
        inline M225*& get_f1(){
            return f1;
        }
    
        inline void set_f2(int32_t val){
            f2 = val;
        }
        inline int32_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(E1 val){
            f3 = val;
        }
        inline E1& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M224->f2: " << f2 << std::endl;
            fout << "M224->f3: " << f3 << std::endl;
        }
    
        ~M224(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M224(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M225* f1;
        alignas(8) int32_t f2;
        alignas(8) E1 f3;
    };


    class alignas(8) M230 : public M_base
    {
    public:
        inline void set_f1(bool val){
            f1 = val;
        }
        inline bool& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M230->f1: " << f1 << std::endl;
        }
    
        ~M230(){
        }
    
        M230(){
        }
    
    private:
        alignas(8) bool f1;
    };


    class alignas(8) M231 : public M_base
    {
    public:
        inline void set_f1(double val){
            f1 = val;
        }
        inline double& get_f1(){
            return f1;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M231->f1: " << f1 << std::endl;
        }
    
        ~M231(){
        }
    
        M231(){
        }
    
    private:
        alignas(8) double f1;
    };


    class alignas(8) M232 : public M_base
    {
    public:
        class alignas(8) M233 : public M_base
        {
        public:
            inline void set_f1(float val){
                f1 = val;
            }
            inline float& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M233->f1: " << f1 << std::endl;
            }
        
            ~M233(){
            }
        
            M233(){
            }
        
        private:
            alignas(8) float f1;
        };


        class alignas(8) M234 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 107,
                E1_CONST_2 = 50,
                E1_CONST_3 = 52,
                E1_CONST_4 = 84,
                E1_CONST_5 = 126,
            };
            
            enum E2 {
                E2_CONST_1 = 72,
                E2_CONST_2 = 49,
                E2_CONST_3 = 87,
                E2_CONST_4 = 120,
                E2_CONST_5 = 58,
            };
            
            enum E3 {
                E3_CONST_1 = 1,
                E3_CONST_2 = 41,
                E3_CONST_3 = 79,
                E3_CONST_4 = 24,
                E3_CONST_5 = 93,
            };
            
            class alignas(8) M235 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 36,
                    E1_CONST_2 = 105,
                    E1_CONST_3 = 17,
                    E1_CONST_4 = 84,
                    E1_CONST_5 = 27,
                };
                
                class alignas(8) M236 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 13,
                        E1_CONST_2 = 78,
                        E1_CONST_3 = 113,
                        E1_CONST_4 = 57,
                        E1_CONST_5 = 30,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 36,
                        E2_CONST_2 = 69,
                        E2_CONST_3 = 103,
                        E2_CONST_4 = 115,
                        E2_CONST_5 = 92,
                    };
                    
                    enum E3 {
                        E3_CONST_1 = 6,
                        E3_CONST_2 = 18,
                        E3_CONST_3 = 89,
                        E3_CONST_4 = 60,
                        E3_CONST_5 = 57,
                    };
                    
                    enum E4 {
                        E4_CONST_1 = 37,
                        E4_CONST_2 = 43,
                        E4_CONST_3 = 77,
                        E4_CONST_4 = 15,
                        E4_CONST_5 = 48,
                    };
                    
                    class alignas(8) M237 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 99,
                            E1_CONST_2 = 48,
                            E1_CONST_3 = 115,
                            E1_CONST_4 = 60,
                            E1_CONST_5 = 125,
                        };
                        
                        class alignas(8) M238 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 33,
                                E1_CONST_2 = 43,
                                E1_CONST_3 = 110,
                                E1_CONST_4 = 48,
                                E1_CONST_5 = 17,
                            };
                            
                            class alignas(8) M239 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 58,
                                    E1_CONST_2 = 69,
                                    E1_CONST_3 = 16,
                                    E1_CONST_4 = 25,
                                    E1_CONST_5 = 26,
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
                                    fout << "M239->f1: " << f1 << std::endl;
                                    fout << "M239->f2: " << f2 << std::endl;
                                }
                            
                                ~M239(){
                                }
                            
                                M239(){
                                }
                            
                            private:
                                alignas(8) string f1;
                                alignas(8) E1 f2;
                            };


                            class alignas(8) M240 : public M_base
                            {
                            public:
                                class alignas(8) M241 : public M_base
                                {
                                public:
                                    class alignas(8) M242 : public M_base
                                    {
                                    public:
                                        class alignas(8) M243 : public M_base
                                        {
                                        public:
                                            class alignas(8) M244 : public M_base
                                            {
                                            public:
                                                enum E1 {
                                                    E1_CONST_1 = 38,
                                                    E1_CONST_2 = 40,
                                                    E1_CONST_3 = 19,
                                                    E1_CONST_4 = 116,
                                                    E1_CONST_5 = 25,
                                                };
                                                
                                                enum E2 {
                                                    E2_CONST_1 = 70,
                                                    E2_CONST_2 = 9,
                                                    E2_CONST_3 = 74,
                                                    E2_CONST_4 = 52,
                                                    E2_CONST_5 = 61,
                                                };
                                                
                                                class alignas(8) M245 : public M_base
                                                {
                                                public:
                                                    class alignas(8) M246 : public M_base
                                                    {
                                                    public:
                                                        enum E1 {
                                                            E1_CONST_1 = 42,
                                                            E1_CONST_2 = 76,
                                                            E1_CONST_3 = 78,
                                                            E1_CONST_4 = 16,
                                                            E1_CONST_5 = 92,
                                                        };
                                                        
                                                        enum E2 {
                                                            E2_CONST_1 = 3,
                                                            E2_CONST_2 = 41,
                                                            E2_CONST_3 = 10,
                                                            E2_CONST_4 = 109,
                                                            E2_CONST_5 = 84,
                                                        };
                                                        
                                                        inline void set_f1(E1 val){
                                                            f1 = val;
                                                        }
                                                        inline E1& get_f1(){
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
                                                    
                                                        inline void set_f5(int32_t val){
                                                            f5 = val;
                                                        }
                                                        inline int32_t& get_f5(){
                                                            return f5;
                                                        }
                                                    
                                                        inline void set_f6(E2 val){
                                                            f6 = val;
                                                        }
                                                        inline E2& get_f6(){
                                                            return f6;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M246->f1: " << f1 << std::endl;
                                                            fout << "M246->f2: " << f2 << std::endl;
                                                            fout << "M246->f3: " << f3 << std::endl;
                                                            fout << "M246->f4: " << f4 << std::endl;
                                                            fout << "M246->f5: " << f5 << std::endl;
                                                            fout << "M246->f6: " << f6 << std::endl;
                                                        }
                                                    
                                                        ~M246(){
                                                        }
                                                    
                                                        M246(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) E1 f1;
                                                        alignas(8) int64_t f2;
                                                        alignas(8) int32_t f3;
                                                        alignas(8) int32_t f4;
                                                        alignas(8) int32_t f5;
                                                        alignas(8) E2 f6;
                                                    };


                                                    inline M246* mutable_f1(){
                                                        f1 = new M246();
                                                        return f1;
                                                    }
                                                    inline M246*& get_f1(){
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
                                                
                                                    inline void set_f4(string val){
                                                        f4 = val;
                                                    }
                                                    inline string& get_f4(){
                                                        return f4;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        if(f1 != nullptr)
                                                            f1->print_message(fout);
                                                        fout << "M245->f2: " << f2 << std::endl;
                                                        fout << "M245->f3: " << f3 << std::endl;
                                                        fout << "M245->f4: " << f4 << std::endl;
                                                    }
                                                
                                                    ~M245(){
                                                        if(f1 != nullptr)
                                                            delete f1;
                                                    }
                                                
                                                    M245(){
                                                       f1 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) M246* f1;
                                                    alignas(8) int32_t f2;
                                                    alignas(8) float f3;
                                                    alignas(8) string f4;
                                                };


                                                inline void set_f1(int32_t val){
                                                    f1 = val;
                                                }
                                                inline int32_t& get_f1(){
                                                    return f1;
                                                }
                                            
                                                inline void set_f2(E1 val){
                                                    f2 = val;
                                                }
                                                inline E1& get_f2(){
                                                    return f2;
                                                }
                                            
                                                inline void set_f3(E2 val){
                                                    f3 = val;
                                                }
                                                inline E2& get_f3(){
                                                    return f3;
                                                }
                                            
                                                inline M245* mutable_f4(){
                                                    f4 = new M245();
                                                    return f4;
                                                }
                                                inline M245*& get_f4(){
                                                    return f4;
                                                }
                                            
                                                inline void set_f5(string val){
                                                    f5 = val;
                                                }
                                                inline string& get_f5(){
                                                    return f5;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    fout << "M244->f1: " << f1 << std::endl;
                                                    fout << "M244->f2: " << f2 << std::endl;
                                                    fout << "M244->f3: " << f3 << std::endl;
                                                    if(f4 != nullptr)
                                                        f4->print_message(fout);
                                                    fout << "M244->f5: " << f5 << std::endl;
                                                }
                                            
                                                ~M244(){
                                                    if(f4 != nullptr)
                                                        delete f4;
                                                }
                                            
                                                M244(){
                                                   f4 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) int32_t f1;
                                                alignas(8) E1 f2;
                                                alignas(8) E2 f3;
                                                alignas(8) M245* f4;
                                                alignas(8) string f5;
                                            };


                                            inline void set_f1(uint32_t val){
                                                f1 = val;
                                            }
                                            inline uint32_t& get_f1(){
                                                return f1;
                                            }
                                        
                                            inline void set_f2(float val){
                                                f2 = val;
                                            }
                                            inline float& get_f2(){
                                                return f2;
                                            }
                                        
                                            inline void set_f3(uint32_t val){
                                                f3 = val;
                                            }
                                            inline uint32_t& get_f3(){
                                                return f3;
                                            }
                                        
                                            inline M244* mutable_f4(){
                                                f4 = new M244();
                                                return f4;
                                            }
                                            inline M244*& get_f4(){
                                                return f4;
                                            }
                                        
                                            inline void set_f5(int32_t val){
                                                f5 = val;
                                            }
                                            inline int32_t& get_f5(){
                                                return f5;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M243->f1: " << f1 << std::endl;
                                                fout << "M243->f2: " << f2 << std::endl;
                                                fout << "M243->f3: " << f3 << std::endl;
                                                if(f4 != nullptr)
                                                    f4->print_message(fout);
                                                fout << "M243->f5: " << f5 << std::endl;
                                            }
                                        
                                            ~M243(){
                                                if(f4 != nullptr)
                                                    delete f4;
                                            }
                                        
                                            M243(){
                                               f4 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) uint32_t f1;
                                            alignas(8) float f2;
                                            alignas(8) uint32_t f3;
                                            alignas(8) M244* f4;
                                            alignas(8) int32_t f5;
                                        };


                                        inline M243* mutable_f1(){
                                            f1 = new M243();
                                            return f1;
                                        }
                                        inline M243*& get_f1(){
                                            return f1;
                                        }
                                    
                                        inline void set_f2(uint32_t val){
                                            f2 = val;
                                        }
                                        inline uint32_t& get_f2(){
                                            return f2;
                                        }
                                    
                                        inline void print_message(std::ofstream &fout){
                                            if(f1 != nullptr)
                                                f1->print_message(fout);
                                            fout << "M242->f2: " << f2 << std::endl;
                                        }
                                    
                                        ~M242(){
                                            if(f1 != nullptr)
                                                delete f1;
                                        }
                                    
                                        M242(){
                                           f1 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) M243* f1;
                                        alignas(8) uint32_t f2;
                                    };


                                    inline void set_f1(float val){
                                        f1 = val;
                                    }
                                    inline float& get_f1(){
                                        return f1;
                                    }
                                
                                    inline M242* mutable_f2(){
                                        f2 = new M242();
                                        return f2;
                                    }
                                    inline M242*& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M241->f1: " << f1 << std::endl;
                                        if(f2 != nullptr)
                                            f2->print_message(fout);
                                    }
                                
                                    ~M241(){
                                        if(f2 != nullptr)
                                            delete f2;
                                    }
                                
                                    M241(){
                                       f2 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) float f1;
                                    alignas(8) M242* f2;
                                };


                                class alignas(8) M247 : public M_base
                                {
                                public:
                                    inline void set_f1(int64_t val){
                                        f1 = val;
                                    }
                                    inline int64_t& get_f1(){
                                        return f1;
                                    }
                                
                                    inline void set_f2(uint32_t val){
                                        f2 = val;
                                    }
                                    inline uint32_t& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void add_f3(int32_t val){
                                        f3.push_back(val);
                                    }
                                    inline int32_t& get_f3(int idx){
                                        return f3[idx];
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M247->f1: " << f1 << std::endl;
                                        fout << "M247->f2: " << f2 << std::endl;
                                        for(auto &f3_val : f3){
                                            fout << "M247->f3: " << f3_val << std::endl;
                                        }
                                    }
                                
                                    ~M247(){
                                    }
                                
                                    M247(){
                                    }
                                
                                private:
                                    alignas(8) int64_t f1;
                                    alignas(8) uint32_t f2;
                                    alignas(8) std::vector<int32_t> f3;
                                };


                                inline void set_f1(int64_t val){
                                    f1 = val;
                                }
                                inline int64_t& get_f1(){
                                    return f1;
                                }
                            
                                inline M241* mutable_f2(){
                                    f2 = new M241();
                                    return f2;
                                }
                                inline M241*& get_f2(){
                                    return f2;
                                }
                            
                                inline M247* mutable_f3(){
                                    f3 = new M247();
                                    return f3;
                                }
                                inline M247*& get_f3(){
                                    return f3;
                                }
                            
                                inline void set_f4(uint32_t val){
                                    f4 = val;
                                }
                                inline uint32_t& get_f4(){
                                    return f4;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M240->f1: " << f1 << std::endl;
                                    if(f2 != nullptr)
                                        f2->print_message(fout);
                                    if(f3 != nullptr)
                                        f3->print_message(fout);
                                    fout << "M240->f4: " << f4 << std::endl;
                                }
                            
                                ~M240(){
                                    if(f2 != nullptr)
                                        delete f2;
                                    if(f3 != nullptr)
                                        delete f3;
                                }
                            
                                M240(){
                                   f2 = nullptr;
                                   f3 = nullptr;
                                }
                            
                            private:
                                alignas(8) int64_t f1;
                                alignas(8) M241* f2;
                                alignas(8) M247* f3;
                                alignas(8) uint32_t f4;
                            };


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
                        
                            inline void set_f3(int32_t val){
                                f3 = val;
                            }
                            inline int32_t& get_f3(){
                                return f3;
                            }
                        
                            inline M239* mutable_f4(){
                                f4 = new M239();
                                return f4;
                            }
                            inline M239*& get_f4(){
                                return f4;
                            }
                        
                            inline M240* mutable_f5(){
                                f5 = new M240();
                                return f5;
                            }
                            inline M240*& get_f5(){
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
                        
                            inline void set_f8(uint32_t val){
                                f8 = val;
                            }
                            inline uint32_t& get_f8(){
                                return f8;
                            }
                        
                            inline void set_f9(uint32_t val){
                                f9 = val;
                            }
                            inline uint32_t& get_f9(){
                                return f9;
                            }
                        
                            inline void set_f10(E1 val){
                                f10 = val;
                            }
                            inline E1& get_f10(){
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
                                fout << "M238->f1: " << f1 << std::endl;
                                fout << "M238->f2: " << f2 << std::endl;
                                fout << "M238->f3: " << f3 << std::endl;
                                if(f4 != nullptr)
                                    f4->print_message(fout);
                                if(f5 != nullptr)
                                    f5->print_message(fout);
                                fout << "M238->f6: " << f6 << std::endl;
                                fout << "M238->f7: " << f7 << std::endl;
                                fout << "M238->f8: " << f8 << std::endl;
                                fout << "M238->f9: " << f9 << std::endl;
                                fout << "M238->f10: " << f10 << std::endl;
                                fout << "M238->f11: " << f11 << std::endl;
                                fout << "M238->f12: " << f12 << std::endl;
                            }
                        
                            ~M238(){
                                if(f4 != nullptr)
                                    delete f4;
                                if(f5 != nullptr)
                                    delete f5;
                            }
                        
                            M238(){
                               f4 = nullptr;
                               f5 = nullptr;
                            }
                        
                        private:
                            alignas(8) float f1;
                            alignas(8) int32_t f2;
                            alignas(8) int32_t f3;
                            alignas(8) M239* f4;
                            alignas(8) M240* f5;
                            alignas(8) int32_t f6;
                            alignas(8) string f7;
                            alignas(8) uint32_t f8;
                            alignas(8) uint32_t f9;
                            alignas(8) E1 f10;
                            alignas(8) int32_t f11;
                            alignas(8) string f12;
                        };


                        inline M238* mutable_f1(){
                            f1 = new M238();
                            return f1;
                        }
                        inline M238*& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(E1 val){
                            f2 = val;
                        }
                        inline E1& get_f2(){
                            return f2;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            if(f1 != nullptr)
                                f1->print_message(fout);
                            fout << "M237->f2: " << f2 << std::endl;
                        }
                    
                        ~M237(){
                            if(f1 != nullptr)
                                delete f1;
                        }
                    
                        M237(){
                           f1 = nullptr;
                        }
                    
                    private:
                        alignas(8) M238* f1;
                        alignas(8) E1 f2;
                    };


                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline void set_f2(E2 val){
                        f2 = val;
                    }
                    inline E2& get_f2(){
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
                
                    inline M237* mutable_f5(){
                        f5 = new M237();
                        return f5;
                    }
                    inline M237*& get_f5(){
                        return f5;
                    }
                
                    inline void set_f6(int32_t val){
                        f6 = val;
                    }
                    inline int32_t& get_f6(){
                        return f6;
                    }
                
                    inline void set_f7(E3 val){
                        f7 = val;
                    }
                    inline E3& get_f7(){
                        return f7;
                    }
                
                    inline void set_f8(E4 val){
                        f8 = val;
                    }
                    inline E4& get_f8(){
                        return f8;
                    }
                
                    inline void set_f9(bool val){
                        f9 = val;
                    }
                    inline bool& get_f9(){
                        return f9;
                    }
                
                    inline void set_f10(float val){
                        f10 = val;
                    }
                    inline float& get_f10(){
                        return f10;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M236->f1: " << f1 << std::endl;
                        fout << "M236->f2: " << f2 << std::endl;
                        fout << "M236->f3: " << f3 << std::endl;
                        fout << "M236->f4: " << f4 << std::endl;
                        if(f5 != nullptr)
                            f5->print_message(fout);
                        fout << "M236->f6: " << f6 << std::endl;
                        fout << "M236->f7: " << f7 << std::endl;
                        fout << "M236->f8: " << f8 << std::endl;
                        fout << "M236->f9: " << f9 << std::endl;
                        fout << "M236->f10: " << f10 << std::endl;
                    }
                
                    ~M236(){
                        if(f5 != nullptr)
                            delete f5;
                    }
                
                    M236(){
                       f5 = nullptr;
                    }
                
                private:
                    alignas(8) E1 f1;
                    alignas(8) E2 f2;
                    alignas(8) float f3;
                    alignas(8) int32_t f4;
                    alignas(8) M237* f5;
                    alignas(8) int32_t f6;
                    alignas(8) E3 f7;
                    alignas(8) E4 f8;
                    alignas(8) bool f9;
                    alignas(8) float f10;
                };


                inline void add_f1(float val){
                    f1.push_back(val);
                }
                inline float& get_f1(int idx){
                    return f1[idx];
                }
            
                inline M236* mutable_f2(){
                    f2 = new M236();
                    return f2;
                }
                inline M236*& get_f2(){
                    return f2;
                }
            
                inline void set_f3(E1 val){
                    f3 = val;
                }
                inline E1& get_f3(){
                    return f3;
                }
            
                inline void print_message(std::ofstream &fout){
                    for(auto &f1_val : f1){
                        fout << "M235->f1: " << f1_val << std::endl;
                    }
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    fout << "M235->f3: " << f3 << std::endl;
                }
            
                ~M235(){
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M235(){
                   f2 = nullptr;
                }
            
            private:
                alignas(8) std::vector<float> f1;
                alignas(8) M236* f2;
                alignas(8) E1 f3;
            };


            class alignas(8) M248 : public M_base
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
                    fout << "M248->f1: " << f1 << std::endl;
                    fout << "M248->f2: " << f2 << std::endl;
                }
            
                ~M248(){
                }
            
                M248(){
                }
            
            private:
                alignas(8) int32_t f1;
                alignas(8) float f2;
            };


            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline void set_f2(E2 val){
                f2 = val;
            }
            inline E2& get_f2(){
                return f2;
            }
        
            inline void add_f3(string val){
                f3.push_back(val);
            }
            inline string& get_f3(int idx){
                return f3[idx];
            }
        
            inline M235* mutable_f4(){
                f4 = new M235();
                return f4;
            }
            inline M235*& get_f4(){
                return f4;
            }
        
            inline void set_f5(bool val){
                f5 = val;
            }
            inline bool& get_f5(){
                return f5;
            }
        
            inline M248* mutable_f6(){
                f6 = new M248();
                return f6;
            }
            inline M248*& get_f6(){
                return f6;
            }
        
            inline void set_f7(E3 val){
                f7 = val;
            }
            inline E3& get_f7(){
                return f7;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M234->f1: " << f1 << std::endl;
                fout << "M234->f2: " << f2 << std::endl;
                for(auto &f3_val : f3){
                    fout << "M234->f3: " << f3_val << std::endl;
                }
                if(f4 != nullptr)
                    f4->print_message(fout);
                fout << "M234->f5: " << f5 << std::endl;
                if(f6 != nullptr)
                    f6->print_message(fout);
                fout << "M234->f7: " << f7 << std::endl;
            }
        
            ~M234(){
                if(f4 != nullptr)
                    delete f4;
                if(f6 != nullptr)
                    delete f6;
            }
        
            M234(){
               f4 = nullptr;
               f6 = nullptr;
            }
        
        private:
            alignas(8) E1 f1;
            alignas(8) E2 f2;
            alignas(8) std::vector<string> f3;
            alignas(8) M235* f4;
            alignas(8) bool f5;
            alignas(8) M248* f6;
            alignas(8) E3 f7;
        };


        class alignas(8) M249 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 66,
                E1_CONST_2 = 70,
                E1_CONST_3 = 118,
                E1_CONST_4 = 88,
                E1_CONST_5 = 91,
            };
            
            class alignas(8) M250 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 37,
                    E1_CONST_2 = 41,
                    E1_CONST_3 = 10,
                    E1_CONST_4 = 23,
                    E1_CONST_5 = 94,
                };
                
                inline void set_f1(E1 val){
                    f1 = val;
                }
                inline E1& get_f1(){
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
            
                inline void set_f4(int32_t val){
                    f4 = val;
                }
                inline int32_t& get_f4(){
                    return f4;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M250->f1: " << f1 << std::endl;
                    fout << "M250->f2: " << f2 << std::endl;
                    fout << "M250->f3: " << f3 << std::endl;
                    fout << "M250->f4: " << f4 << std::endl;
                }
            
                ~M250(){
                }
            
                M250(){
                }
            
            private:
                alignas(8) E1 f1;
                alignas(8) uint32_t f2;
                alignas(8) int32_t f3;
                alignas(8) int32_t f4;
            };


            inline void set_f1(float val){
                f1 = val;
            }
            inline float& get_f1(){
                return f1;
            }
        
            inline M250* mutable_f2(){
                f2 = new M250();
                return f2;
            }
            inline M250*& get_f2(){
                return f2;
            }
        
            inline void set_f3(E1 val){
                f3 = val;
            }
            inline E1& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M249->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M249->f3: " << f3 << std::endl;
            }
        
            ~M249(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M249(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) float f1;
            alignas(8) M250* f2;
            alignas(8) E1 f3;
        };


        inline M233* mutable_f1(){
            f1 = new M233();
            return f1;
        }
        inline M233*& get_f1(){
            return f1;
        }
    
        inline M234* mutable_f2(){
            f2 = new M234();
            return f2;
        }
        inline M234*& get_f2(){
            return f2;
        }
    
        inline void set_f3(bool val){
            f3 = val;
        }
        inline bool& get_f3(){
            return f3;
        }
    
        inline M249* mutable_f4(){
            f4 = new M249();
            return f4;
        }
        inline M249*& get_f4(){
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
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M232->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
            fout << "M232->f5: " << f5 << std::endl;
        }
    
        ~M232(){
            if(f1 != nullptr)
                delete f1;
            if(f2 != nullptr)
                delete f2;
            if(f4 != nullptr)
                delete f4;
        }
    
        M232(){
           f1 = nullptr;
           f2 = nullptr;
           f4 = nullptr;
        }
    
    private:
        alignas(8) M233* f1;
        alignas(8) M234* f2;
        alignas(8) bool f3;
        alignas(8) M249* f4;
        alignas(8) int64_t f5;
    };


    class alignas(8) M251 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 76,
            E1_CONST_2 = 46,
            E1_CONST_3 = 57,
            E1_CONST_4 = 126,
            E1_CONST_5 = 62,
        };
        
        enum E2 {
            E2_CONST_1 = 41,
            E2_CONST_2 = 76,
            E2_CONST_3 = 84,
            E2_CONST_4 = 87,
            E2_CONST_5 = 28,
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
    
        inline void set_f3(E2 val){
            f3 = val;
        }
        inline E2& get_f3(){
            return f3;
        }
    
        inline void set_f4(float val){
            f4 = val;
        }
        inline float& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M251->f1: " << f1 << std::endl;
            fout << "M251->f2: " << f2 << std::endl;
            fout << "M251->f3: " << f3 << std::endl;
            fout << "M251->f4: " << f4 << std::endl;
        }
    
        ~M251(){
        }
    
        M251(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) E1 f2;
        alignas(8) E2 f3;
        alignas(8) float f4;
    };


    inline void set_f1(E1 val){
        f1 = val;
    }
    inline E1& get_f1(){
        return f1;
    }

    inline void set_f2(E2 val){
        f2 = val;
    }
    inline E2& get_f2(){
        return f2;
    }

    inline M224* mutable_f3(){
        f3 = new M224();
        return f3;
    }
    inline M224*& get_f3(){
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

    inline void set_f6(E3 val){
        f6 = val;
    }
    inline E3& get_f6(){
        return f6;
    }

    inline void set_f7(uint32_t val){
        f7 = val;
    }
    inline uint32_t& get_f7(){
        return f7;
    }

    inline void set_f8(E4 val){
        f8 = val;
    }
    inline E4& get_f8(){
        return f8;
    }

    inline void set_f9(uint32_t val){
        f9 = val;
    }
    inline uint32_t& get_f9(){
        return f9;
    }

    inline M230* mutable_f10(){
        f10 = new M230();
        return f10;
    }
    inline M230*& get_f10(){
        return f10;
    }

    inline M231* mutable_f11(){
        f11 = new M231();
        return f11;
    }
    inline M231*& get_f11(){
        return f11;
    }

    inline M232* mutable_f12(){
        f12 = new M232();
        return f12;
    }
    inline M232*& get_f12(){
        return f12;
    }

    inline M251* mutable_f13(){
        f13 = new M251();
        return f13;
    }
    inline M251*& get_f13(){
        return f13;
    }

    inline void set_f14(bool val){
        f14 = val;
    }
    inline bool& get_f14(){
        return f14;
    }

    inline void set_f15(string val){
        f15 = val;
    }
    inline string& get_f15(){
        return f15;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M223->f1: " << f1 << std::endl;
        fout << "M223->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
        fout << "M223->f4: " << f4 << std::endl;
        fout << "M223->f5: " << f5 << std::endl;
        fout << "M223->f6: " << f6 << std::endl;
        fout << "M223->f7: " << f7 << std::endl;
        fout << "M223->f8: " << f8 << std::endl;
        fout << "M223->f9: " << f9 << std::endl;
        if(f10 != nullptr)
            f10->print_message(fout);
        if(f11 != nullptr)
            f11->print_message(fout);
        if(f12 != nullptr)
            f12->print_message(fout);
        if(f13 != nullptr)
            f13->print_message(fout);
        fout << "M223->f14: " << f14 << std::endl;
        fout << "M223->f15: " << f15 << std::endl;
    }

    ~M223(){
        if(f3 != nullptr)
            delete f3;
        if(f10 != nullptr)
            delete f10;
        if(f11 != nullptr)
            delete f11;
        if(f12 != nullptr)
            delete f12;
        if(f13 != nullptr)
            delete f13;
    }

    M223(){
       f3 = nullptr;
       f10 = nullptr;
       f11 = nullptr;
       f12 = nullptr;
       f13 = nullptr;
    }

private:
    alignas(8) E1 f1;
    alignas(8) E2 f2;
    alignas(8) M224* f3;
    alignas(8) string f4;
    alignas(8) string f5;
    alignas(8) E3 f6;
    alignas(8) uint32_t f7;
    alignas(8) E4 f8;
    alignas(8) uint32_t f9;
    alignas(8) M230* f10;
    alignas(8) M231* f11;
    alignas(8) M232* f12;
    alignas(8) M251* f13;
    alignas(8) bool f14;
    alignas(8) string f15;
};


class alignas(8) M252 : public M_base
{
public:
    enum E1 {
        E1_CONST_1 = 32,
        E1_CONST_2 = 7,
        E1_CONST_3 = 9,
        E1_CONST_4 = 50,
        E1_CONST_5 = 122,
    };
    
    enum E2 {
        E2_CONST_1 = 37,
        E2_CONST_2 = 75,
        E2_CONST_3 = 12,
        E2_CONST_4 = 54,
        E2_CONST_5 = 124,
    };
    
    class alignas(8) M253 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 71,
            E1_CONST_2 = 16312,
            E1_CONST_3 = 56,
            E1_CONST_4 = 62,
            E1_CONST_5 = 63,
        };
        
        class alignas(8) M254 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 34,
                E1_CONST_2 = 10,
                E1_CONST_3 = 109,
                E1_CONST_4 = 18,
                E1_CONST_5 = 30,
            };
            
            class alignas(8) M255 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 0,
                    E1_CONST_2 = 36,
                    E1_CONST_3 = 8,
                    E1_CONST_4 = 81,
                    E1_CONST_5 = 53,
                };
                
                enum E2 {
                    E2_CONST_1 = 78,
                    E2_CONST_2 = 46,
                    E2_CONST_3 = 80,
                    E2_CONST_4 = 51,
                    E2_CONST_5 = 86,
                };
                
                enum E3 {
                    E3_CONST_1 = 96,
                    E3_CONST_2 = 104,
                    E3_CONST_3 = 78,
                    E3_CONST_4 = 110,
                    E3_CONST_5 = 88,
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
            
                inline void set_f3(E2 val){
                    f3 = val;
                }
                inline E2& get_f3(){
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
            
                inline void set_f8(bool val){
                    f8 = val;
                }
                inline bool& get_f8(){
                    return f8;
                }
            
                inline void set_f9(uint32_t val){
                    f9 = val;
                }
                inline uint32_t& get_f9(){
                    return f9;
                }
            
                inline void set_f10(E3 val){
                    f10 = val;
                }
                inline E3& get_f10(){
                    return f10;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M255->f1: " << f1 << std::endl;
                    fout << "M255->f2: " << f2 << std::endl;
                    fout << "M255->f3: " << f3 << std::endl;
                    fout << "M255->f4: " << f4 << std::endl;
                    fout << "M255->f5: " << f5 << std::endl;
                    fout << "M255->f6: " << f6 << std::endl;
                    fout << "M255->f7: " << f7 << std::endl;
                    fout << "M255->f8: " << f8 << std::endl;
                    fout << "M255->f9: " << f9 << std::endl;
                    fout << "M255->f10: " << f10 << std::endl;
                }
            
                ~M255(){
                }
            
                M255(){
                }
            
            private:
                alignas(8) float f1;
                alignas(8) E1 f2;
                alignas(8) E2 f3;
                alignas(8) float f4;
                alignas(8) float f5;
                alignas(8) uint32_t f6;
                alignas(8) int64_t f7;
                alignas(8) bool f8;
                alignas(8) uint32_t f9;
                alignas(8) E3 f10;
            };


            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline M255* mutable_f2(){
                f2 = new M255();
                return f2;
            }
            inline M255*& get_f2(){
                return f2;
            }
        
            inline void set_f3(int64_t val){
                f3 = val;
            }
            inline int64_t& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M254->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M254->f3: " << f3 << std::endl;
            }
        
            ~M254(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M254(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) E1 f1;
            alignas(8) M255* f2;
            alignas(8) int64_t f3;
        };


        inline M254* mutable_f1(){
            f1 = new M254();
            return f1;
        }
        inline M254*& get_f1(){
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
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M253->f2: " << f2 << std::endl;
            fout << "M253->f3: " << f3 << std::endl;
        }
    
        ~M253(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M253(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M254* f1;
        alignas(8) E1 f2;
        alignas(8) bool f3;
    };


    class alignas(8) M256 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 0,
            E1_CONST_2 = 70,
            E1_CONST_3 = 7,
            E1_CONST_4 = 83,
            E1_CONST_5 = 95,
        };
        
        enum E2 {
            E2_CONST_1 = 65,
            E2_CONST_2 = 100,
            E2_CONST_3 = 19,
            E2_CONST_4 = 117,
            E2_CONST_5 = 95,
        };
        
        class alignas(8) M257 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void add_f2(int32_t val){
                f2.push_back(val);
            }
            inline int32_t& get_f2(int idx){
                return f2[idx];
            }
        
            inline void set_f3(uint32_t val){
                f3 = val;
            }
            inline uint32_t& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M257->f1: " << f1 << std::endl;
                for(auto &f2_val : f2){
                    fout << "M257->f2: " << f2_val << std::endl;
                }
                fout << "M257->f3: " << f3 << std::endl;
            }
        
            ~M257(){
            }
        
            M257(){
            }
        
        private:
            alignas(8) int32_t f1;
            alignas(8) std::vector<int32_t> f2;
            alignas(8) uint32_t f3;
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
    
        inline void set_f5(string val){
            f5 = val;
        }
        inline string& get_f5(){
            return f5;
        }
    
        inline void add_f6(E2 val){
            f6.push_back(val);
        }
        inline E2& get_f6(int idx){
            return f6[idx];
        }
    
        inline M257* mutable_f7(){
            f7 = new M257();
            return f7;
        }
        inline M257*& get_f7(){
            return f7;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M256->f1: " << f1 << std::endl;
            fout << "M256->f2: " << f2 << std::endl;
            fout << "M256->f3: " << f3 << std::endl;
            fout << "M256->f4: " << f4 << std::endl;
            fout << "M256->f5: " << f5 << std::endl;
            for(auto &f6_val : f6){
                fout << "M256->f6: " << f6_val << std::endl;
            }
            if(f7 != nullptr)
                f7->print_message(fout);
        }
    
        ~M256(){
            if(f7 != nullptr)
                delete f7;
        }
    
        M256(){
           f7 = nullptr;
        }
    
    private:
        alignas(8) E1 f1;
        alignas(8) bool f2;
        alignas(8) float f3;
        alignas(8) int32_t f4;
        alignas(8) string f5;
        alignas(8) std::vector<E2> f6;
        alignas(8) M257* f7;
    };


    class alignas(8) M258 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 35,
            E1_CONST_2 = 5,
            E1_CONST_3 = 9,
            E1_CONST_4 = 114,
            E1_CONST_5 = 124,
        };
        
        class alignas(8) M259 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 38,
                E1_CONST_2 = 105,
                E1_CONST_3 = 45,
                E1_CONST_4 = 48,
                E1_CONST_5 = 119,
            };
            
            class alignas(8) M260 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 109,
                    E1_CONST_2 = 15,
                    E1_CONST_3 = 81,
                    E1_CONST_4 = 118,
                    E1_CONST_5 = 91,
                };
                
                class alignas(8) M261 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 39,
                        E1_CONST_2 = 104,
                        E1_CONST_3 = 12,
                        E1_CONST_4 = 115,
                        E1_CONST_5 = 94,
                    };
                    
                    class alignas(8) M262 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 64,
                            E1_CONST_2 = 35,
                            E1_CONST_3 = 74,
                            E1_CONST_4 = 50,
                            E1_CONST_5 = 89,
                        };
                        
                        enum E2 {
                            E2_CONST_1 = 64,
                            E2_CONST_2 = 10,
                            E2_CONST_3 = 75,
                            E2_CONST_4 = 84,
                            E2_CONST_5 = 86,
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
                    
                        inline void set_f3(E2 val){
                            f3 = val;
                        }
                        inline E2& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M262->f1: " << f1 << std::endl;
                            fout << "M262->f2: " << f2 << std::endl;
                            fout << "M262->f3: " << f3 << std::endl;
                        }
                    
                        ~M262(){
                        }
                    
                        M262(){
                        }
                    
                    private:
                        alignas(8) E1 f1;
                        alignas(8) float f2;
                        alignas(8) E2 f3;
                    };


                    inline M262* mutable_f1(){
                        f1 = new M262();
                        return f1;
                    }
                    inline M262*& get_f1(){
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
                
                    inline void set_f4(uint32_t val){
                        f4 = val;
                    }
                    inline uint32_t& get_f4(){
                        return f4;
                    }
                
                    inline void set_f5(E1 val){
                        f5 = val;
                    }
                    inline E1& get_f5(){
                        return f5;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        if(f1 != nullptr)
                            f1->print_message(fout);
                        fout << "M261->f2: " << f2 << std::endl;
                        fout << "M261->f3: " << f3 << std::endl;
                        fout << "M261->f4: " << f4 << std::endl;
                        fout << "M261->f5: " << f5 << std::endl;
                    }
                
                    ~M261(){
                        if(f1 != nullptr)
                            delete f1;
                    }
                
                    M261(){
                       f1 = nullptr;
                    }
                
                private:
                    alignas(8) M262* f1;
                    alignas(8) int32_t f2;
                    alignas(8) int32_t f3;
                    alignas(8) uint32_t f4;
                    alignas(8) E1 f5;
                };


                class alignas(8) M263 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 98,
                        E1_CONST_2 = 44,
                        E1_CONST_3 = 79,
                        E1_CONST_4 = 49,
                        E1_CONST_5 = 24,
                    };
                    
                    enum E2 {
                        E2_CONST_1 = 96,
                        E2_CONST_2 = 67,
                        E2_CONST_3 = 50,
                        E2_CONST_4 = 23,
                        E2_CONST_5 = 120,
                    };
                    
                    enum E3 {
                        E3_CONST_1 = 64,
                        E3_CONST_2 = 35,
                        E3_CONST_3 = 116,
                        E3_CONST_4 = 122,
                        E3_CONST_5 = 59,
                    };
                    
                    class alignas(8) M264 : public M_base
                    {
                    public:
                        class alignas(8) M265 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 3,
                                E1_CONST_2 = 4165,
                                E1_CONST_3 = 28,
                                E1_CONST_4 = 112,
                                E1_CONST_5 = 92,
                            };
                            
                            enum E2 {
                                E2_CONST_1 = 0,
                                E2_CONST_2 = 64,
                                E2_CONST_3 = 5,
                                E2_CONST_4 = 89,
                                E2_CONST_5 = 30,
                            };
                            
                            class alignas(8) M266 : public M_base
                            {
                            public:
                                inline void set_f1(int32_t val){
                                    f1 = val;
                                }
                                inline int32_t& get_f1(){
                                    return f1;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M266->f1: " << f1 << std::endl;
                                }
                            
                                ~M266(){
                                }
                            
                                M266(){
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
                        
                            inline void set_f2(bool val){
                                f2 = val;
                            }
                            inline bool& get_f2(){
                                return f2;
                            }
                        
                            inline void set_f3(E2 val){
                                f3 = val;
                            }
                            inline E2& get_f3(){
                                return f3;
                            }
                        
                            inline M266* mutable_f4(){
                                f4 = new M266();
                                return f4;
                            }
                            inline M266*& get_f4(){
                                return f4;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M265->f1: " << f1 << std::endl;
                                fout << "M265->f2: " << f2 << std::endl;
                                fout << "M265->f3: " << f3 << std::endl;
                                if(f4 != nullptr)
                                    f4->print_message(fout);
                            }
                        
                            ~M265(){
                                if(f4 != nullptr)
                                    delete f4;
                            }
                        
                            M265(){
                               f4 = nullptr;
                            }
                        
                        private:
                            alignas(8) E1 f1;
                            alignas(8) bool f2;
                            alignas(8) E2 f3;
                            alignas(8) M266* f4;
                        };


                        inline M265* mutable_f1(){
                            f1 = new M265();
                            return f1;
                        }
                        inline M265*& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(uint32_t val){
                            f2 = val;
                        }
                        inline uint32_t& get_f2(){
                            return f2;
                        }
                    
                        inline void set_f3(float val){
                            f3 = val;
                        }
                        inline float& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            if(f1 != nullptr)
                                f1->print_message(fout);
                            fout << "M264->f2: " << f2 << std::endl;
                            fout << "M264->f3: " << f3 << std::endl;
                        }
                    
                        ~M264(){
                            if(f1 != nullptr)
                                delete f1;
                        }
                    
                        M264(){
                           f1 = nullptr;
                        }
                    
                    private:
                        alignas(8) M265* f1;
                        alignas(8) uint32_t f2;
                        alignas(8) float f3;
                    };


                    class alignas(8) M267 : public M_base
                    {
                    public:
                        class alignas(8) M268 : public M_base
                        {
                        public:
                            class alignas(8) M269 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 97,
                                    E1_CONST_2 = 35,
                                    E1_CONST_3 = 54,
                                    E1_CONST_4 = 90,
                                    E1_CONST_5 = 29,
                                };
                                
                                class alignas(8) M270 : public M_base
                                {
                                public:
                                    enum E1 {
                                        E1_CONST_1 = 101,
                                        E1_CONST_2 = 73,
                                        E1_CONST_3 = 10,
                                        E1_CONST_4 = 79,
                                        E1_CONST_5 = 47,
                                    };
                                    
                                    inline void set_f1(uint32_t val){
                                        f1 = val;
                                    }
                                    inline uint32_t& get_f1(){
                                        return f1;
                                    }
                                
                                    inline void set_f2(E1 val){
                                        f2 = val;
                                    }
                                    inline E1& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M270->f1: " << f1 << std::endl;
                                        fout << "M270->f2: " << f2 << std::endl;
                                    }
                                
                                    ~M270(){
                                    }
                                
                                    M270(){
                                    }
                                
                                private:
                                    alignas(8) uint32_t f1;
                                    alignas(8) E1 f2;
                                };


                                class alignas(8) M271 : public M_base
                                {
                                public:
                                    class alignas(8) M272 : public M_base
                                    {
                                    public:
                                        enum E1 {
                                            E1_CONST_1 = 97,
                                            E1_CONST_2 = 67,
                                            E1_CONST_3 = 39,
                                            E1_CONST_4 = 89,
                                            E1_CONST_5 = 90,
                                        };
                                        
                                        class alignas(8) M273 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 32,
                                                E1_CONST_2 = 64,
                                                E1_CONST_3 = 69,
                                                E1_CONST_4 = 48,
                                                E1_CONST_5 = 51,
                                            };
                                            
                                            enum E2 {
                                                E2_CONST_1 = 7,
                                                E2_CONST_2 = 42,
                                                E2_CONST_3 = 25,
                                                E2_CONST_4 = 126,
                                                E2_CONST_5 = 94,
                                            };
                                            
                                            class alignas(8) M274 : public M_base
                                            {
                                            public:
                                                class alignas(8) M275 : public M_base
                                                {
                                                public:
                                                    enum E1 {
                                                        E1_CONST_1 = 66,
                                                        E1_CONST_2 = 37,
                                                        E1_CONST_3 = 70,
                                                        E1_CONST_4 = 43,
                                                        E1_CONST_5 = 86,
                                                    };
                                                    
                                                    enum E2 {
                                                        E2_CONST_1 = 7,
                                                        E2_CONST_2 = 108,
                                                        E2_CONST_3 = 13,
                                                        E2_CONST_4 = 110,
                                                        E2_CONST_5 = 51,
                                                    };
                                                    
                                                    enum E3 {
                                                        E3_CONST_1 = 0,
                                                        E3_CONST_2 = 2,
                                                        E3_CONST_3 = 70,
                                                        E3_CONST_4 = 72,
                                                        E3_CONST_5 = 92,
                                                    };
                                                    
                                                    enum E4 {
                                                        E4_CONST_1 = 5,
                                                        E4_CONST_2 = 43,
                                                        E4_CONST_3 = 108,
                                                        E4_CONST_4 = 16,
                                                        E4_CONST_5 = 29,
                                                    };
                                                    
                                                    class alignas(8) M276 : public M_base
                                                    {
                                                    public:
                                                        enum E1 {
                                                            E1_CONST_1 = 100,
                                                            E1_CONST_2 = 115,
                                                            E1_CONST_3 = 55,
                                                            E1_CONST_4 = 120,
                                                            E1_CONST_5 = 63,
                                                        };
                                                        
                                                        enum E2 {
                                                            E2_CONST_1 = 66,
                                                            E2_CONST_2 = 99,
                                                            E2_CONST_3 = 100,
                                                            E2_CONST_4 = 41,
                                                            E2_CONST_5 = 23,
                                                        };
                                                        
                                                        enum E3 {
                                                            E3_CONST_1 = 0,
                                                            E3_CONST_2 = 11,
                                                            E3_CONST_3 = 12,
                                                            E3_CONST_4 = 117,
                                                            E3_CONST_5 = 95,
                                                        };
                                                        
                                                        enum E4 {
                                                            E4_CONST_1 = 0,
                                                            E4_CONST_2 = 12,
                                                            E4_CONST_3 = 119,
                                                            E4_CONST_4 = 55,
                                                            E4_CONST_5 = 27,
                                                        };
                                                        
                                                        inline void set_f1(uint32_t val){
                                                            f1 = val;
                                                        }
                                                        inline uint32_t& get_f1(){
                                                            return f1;
                                                        }
                                                    
                                                        inline void set_f2(E1 val){
                                                            f2 = val;
                                                        }
                                                        inline E1& get_f2(){
                                                            return f2;
                                                        }
                                                    
                                                        inline void set_f3(E2 val){
                                                            f3 = val;
                                                        }
                                                        inline E2& get_f3(){
                                                            return f3;
                                                        }
                                                    
                                                        inline void set_f4(float val){
                                                            f4 = val;
                                                        }
                                                        inline float& get_f4(){
                                                            return f4;
                                                        }
                                                    
                                                        inline void set_f5(E3 val){
                                                            f5 = val;
                                                        }
                                                        inline E3& get_f5(){
                                                            return f5;
                                                        }
                                                    
                                                        inline void set_f6(bool val){
                                                            f6 = val;
                                                        }
                                                        inline bool& get_f6(){
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
                                                    
                                                        inline void set_f9(E4 val){
                                                            f9 = val;
                                                        }
                                                        inline E4& get_f9(){
                                                            return f9;
                                                        }
                                                    
                                                        inline void set_f10(int64_t val){
                                                            f10 = val;
                                                        }
                                                        inline int64_t& get_f10(){
                                                            return f10;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M276->f1: " << f1 << std::endl;
                                                            fout << "M276->f2: " << f2 << std::endl;
                                                            fout << "M276->f3: " << f3 << std::endl;
                                                            fout << "M276->f4: " << f4 << std::endl;
                                                            fout << "M276->f5: " << f5 << std::endl;
                                                            fout << "M276->f6: " << f6 << std::endl;
                                                            fout << "M276->f7: " << f7 << std::endl;
                                                            fout << "M276->f8: " << f8 << std::endl;
                                                            fout << "M276->f9: " << f9 << std::endl;
                                                            fout << "M276->f10: " << f10 << std::endl;
                                                        }
                                                    
                                                        ~M276(){
                                                        }
                                                    
                                                        M276(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) uint32_t f1;
                                                        alignas(8) E1 f2;
                                                        alignas(8) E2 f3;
                                                        alignas(8) float f4;
                                                        alignas(8) E3 f5;
                                                        alignas(8) bool f6;
                                                        alignas(8) int32_t f7;
                                                        alignas(8) string f8;
                                                        alignas(8) E4 f9;
                                                        alignas(8) int64_t f10;
                                                    };


                                                    inline void add_f1(E1 val){
                                                        f1.push_back(val);
                                                    }
                                                    inline E1& get_f1(int idx){
                                                        return f1[idx];
                                                    }
                                                
                                                    inline void set_f2(E2 val){
                                                        f2 = val;
                                                    }
                                                    inline E2& get_f2(){
                                                        return f2;
                                                    }
                                                
                                                    inline M276* mutable_f3(){
                                                        f3 = new M276();
                                                        return f3;
                                                    }
                                                    inline M276*& get_f3(){
                                                        return f3;
                                                    }
                                                
                                                    inline void set_f4(bool val){
                                                        f4 = val;
                                                    }
                                                    inline bool& get_f4(){
                                                        return f4;
                                                    }
                                                
                                                    inline void set_f5(float val){
                                                        f5 = val;
                                                    }
                                                    inline float& get_f5(){
                                                        return f5;
                                                    }
                                                
                                                    inline void set_f6(E3 val){
                                                        f6 = val;
                                                    }
                                                    inline E3& get_f6(){
                                                        return f6;
                                                    }
                                                
                                                    inline void set_f7(E4 val){
                                                        f7 = val;
                                                    }
                                                    inline E4& get_f7(){
                                                        return f7;
                                                    }
                                                
                                                    inline void set_f8(bool val){
                                                        f8 = val;
                                                    }
                                                    inline bool& get_f8(){
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
                                                
                                                    inline void set_f11(int32_t val){
                                                        f11 = val;
                                                    }
                                                    inline int32_t& get_f11(){
                                                        return f11;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        for(auto &f1_val : f1){
                                                            fout << "M275->f1: " << f1_val << std::endl;
                                                        }
                                                        fout << "M275->f2: " << f2 << std::endl;
                                                        if(f3 != nullptr)
                                                            f3->print_message(fout);
                                                        fout << "M275->f4: " << f4 << std::endl;
                                                        fout << "M275->f5: " << f5 << std::endl;
                                                        fout << "M275->f6: " << f6 << std::endl;
                                                        fout << "M275->f7: " << f7 << std::endl;
                                                        fout << "M275->f8: " << f8 << std::endl;
                                                        fout << "M275->f9: " << f9 << std::endl;
                                                        fout << "M275->f10: " << f10 << std::endl;
                                                        fout << "M275->f11: " << f11 << std::endl;
                                                    }
                                                
                                                    ~M275(){
                                                        if(f3 != nullptr)
                                                            delete f3;
                                                    }
                                                
                                                    M275(){
                                                       f3 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) std::vector<E1> f1;
                                                    alignas(8) E2 f2;
                                                    alignas(8) M276* f3;
                                                    alignas(8) bool f4;
                                                    alignas(8) float f5;
                                                    alignas(8) E3 f6;
                                                    alignas(8) E4 f7;
                                                    alignas(8) bool f8;
                                                    alignas(8) float f9;
                                                    alignas(8) int32_t f10;
                                                    alignas(8) int32_t f11;
                                                };


                                                inline void add_f1(string val){
                                                    f1.push_back(val);
                                                }
                                                inline string& get_f1(int idx){
                                                    return f1[idx];
                                                }
                                            
                                                inline M275* mutable_f2(){
                                                    f2 = new M275();
                                                    return f2;
                                                }
                                                inline M275*& get_f2(){
                                                    return f2;
                                                }
                                            
                                                inline void set_f3(int32_t val){
                                                    f3 = val;
                                                }
                                                inline int32_t& get_f3(){
                                                    return f3;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    for(auto &f1_val : f1){
                                                        fout << "M274->f1: " << f1_val << std::endl;
                                                    }
                                                    if(f2 != nullptr)
                                                        f2->print_message(fout);
                                                    fout << "M274->f3: " << f3 << std::endl;
                                                }
                                            
                                                ~M274(){
                                                    if(f2 != nullptr)
                                                        delete f2;
                                                }
                                            
                                                M274(){
                                                   f2 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) std::vector<string> f1;
                                                alignas(8) M275* f2;
                                                alignas(8) int32_t f3;
                                            };


                                            inline void set_f1(float val){
                                                f1 = val;
                                            }
                                            inline float& get_f1(){
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
                                        
                                            inline void set_f4(E2 val){
                                                f4 = val;
                                            }
                                            inline E2& get_f4(){
                                                return f4;
                                            }
                                        
                                            inline void set_f5(int32_t val){
                                                f5 = val;
                                            }
                                            inline int32_t& get_f5(){
                                                return f5;
                                            }
                                        
                                            inline M274* mutable_f6(){
                                                f6 = new M274();
                                                return f6;
                                            }
                                            inline M274*& get_f6(){
                                                return f6;
                                            }
                                        
                                            inline void set_f7(float val){
                                                f7 = val;
                                            }
                                            inline float& get_f7(){
                                                return f7;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M273->f1: " << f1 << std::endl;
                                                fout << "M273->f2: " << f2 << std::endl;
                                                fout << "M273->f3: " << f3 << std::endl;
                                                fout << "M273->f4: " << f4 << std::endl;
                                                fout << "M273->f5: " << f5 << std::endl;
                                                if(f6 != nullptr)
                                                    f6->print_message(fout);
                                                fout << "M273->f7: " << f7 << std::endl;
                                            }
                                        
                                            ~M273(){
                                                if(f6 != nullptr)
                                                    delete f6;
                                            }
                                        
                                            M273(){
                                               f6 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) float f1;
                                            alignas(8) bool f2;
                                            alignas(8) E1 f3;
                                            alignas(8) E2 f4;
                                            alignas(8) int32_t f5;
                                            alignas(8) M274* f6;
                                            alignas(8) float f7;
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
                                    
                                        inline M273* mutable_f3(){
                                            f3 = new M273();
                                            return f3;
                                        }
                                        inline M273*& get_f3(){
                                            return f3;
                                        }
                                    
                                        inline void set_f4(float val){
                                            f4 = val;
                                        }
                                        inline float& get_f4(){
                                            return f4;
                                        }
                                    
                                        inline void print_message(std::ofstream &fout){
                                            fout << "M272->f1: " << f1 << std::endl;
                                            fout << "M272->f2: " << f2 << std::endl;
                                            if(f3 != nullptr)
                                                f3->print_message(fout);
                                            fout << "M272->f4: " << f4 << std::endl;
                                        }
                                    
                                        ~M272(){
                                            if(f3 != nullptr)
                                                delete f3;
                                        }
                                    
                                        M272(){
                                           f3 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) float f1;
                                        alignas(8) E1 f2;
                                        alignas(8) M273* f3;
                                        alignas(8) float f4;
                                    };


                                    inline void set_f1(int32_t val){
                                        f1 = val;
                                    }
                                    inline int32_t& get_f1(){
                                        return f1;
                                    }
                                
                                    inline M272* mutable_f2(){
                                        f2 = new M272();
                                        return f2;
                                    }
                                    inline M272*& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M271->f1: " << f1 << std::endl;
                                        if(f2 != nullptr)
                                            f2->print_message(fout);
                                    }
                                
                                    ~M271(){
                                        if(f2 != nullptr)
                                            delete f2;
                                    }
                                
                                    M271(){
                                       f2 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) int32_t f1;
                                    alignas(8) M272* f2;
                                };


                                inline void set_f1(uint32_t val){
                                    f1 = val;
                                }
                                inline uint32_t& get_f1(){
                                    return f1;
                                }
                            
                                inline M270* mutable_f2(){
                                    f2 = new M270();
                                    return f2;
                                }
                                inline M270*& get_f2(){
                                    return f2;
                                }
                            
                                inline void set_f3(E1 val){
                                    f3 = val;
                                }
                                inline E1& get_f3(){
                                    return f3;
                                }
                            
                                inline void set_f4(int32_t val){
                                    f4 = val;
                                }
                                inline int32_t& get_f4(){
                                    return f4;
                                }
                            
                                inline M271* mutable_f5(){
                                    f5 = new M271();
                                    return f5;
                                }
                                inline M271*& get_f5(){
                                    return f5;
                                }
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M269->f1: " << f1 << std::endl;
                                    if(f2 != nullptr)
                                        f2->print_message(fout);
                                    fout << "M269->f3: " << f3 << std::endl;
                                    fout << "M269->f4: " << f4 << std::endl;
                                    if(f5 != nullptr)
                                        f5->print_message(fout);
                                }
                            
                                ~M269(){
                                    if(f2 != nullptr)
                                        delete f2;
                                    if(f5 != nullptr)
                                        delete f5;
                                }
                            
                                M269(){
                                   f2 = nullptr;
                                   f5 = nullptr;
                                }
                            
                            private:
                                alignas(8) uint32_t f1;
                                alignas(8) M270* f2;
                                alignas(8) E1 f3;
                                alignas(8) int32_t f4;
                                alignas(8) M271* f5;
                            };


                            inline void set_f1(int64_t val){
                                f1 = val;
                            }
                            inline int64_t& get_f1(){
                                return f1;
                            }
                        
                            inline M269* mutable_f2(){
                                f2 = new M269();
                                return f2;
                            }
                            inline M269*& get_f2(){
                                return f2;
                            }
                        
                            inline void set_f3(int32_t val){
                                f3 = val;
                            }
                            inline int32_t& get_f3(){
                                return f3;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M268->f1: " << f1 << std::endl;
                                if(f2 != nullptr)
                                    f2->print_message(fout);
                                fout << "M268->f3: " << f3 << std::endl;
                            }
                        
                            ~M268(){
                                if(f2 != nullptr)
                                    delete f2;
                            }
                        
                            M268(){
                               f2 = nullptr;
                            }
                        
                        private:
                            alignas(8) int64_t f1;
                            alignas(8) M269* f2;
                            alignas(8) int32_t f3;
                        };


                        class alignas(8) M277 : public M_base
                        {
                        public:
                            inline void set_f1(uint32_t val){
                                f1 = val;
                            }
                            inline uint32_t& get_f1(){
                                return f1;
                            }
                        
                            inline void set_f2(bool val){
                                f2 = val;
                            }
                            inline bool& get_f2(){
                                return f2;
                            }
                        
                            inline void set_f3(uint32_t val){
                                f3 = val;
                            }
                            inline uint32_t& get_f3(){
                                return f3;
                            }
                        
                            inline void set_f4(bool val){
                                f4 = val;
                            }
                            inline bool& get_f4(){
                                return f4;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M277->f1: " << f1 << std::endl;
                                fout << "M277->f2: " << f2 << std::endl;
                                fout << "M277->f3: " << f3 << std::endl;
                                fout << "M277->f4: " << f4 << std::endl;
                            }
                        
                            ~M277(){
                            }
                        
                            M277(){
                            }
                        
                        private:
                            alignas(8) uint32_t f1;
                            alignas(8) bool f2;
                            alignas(8) uint32_t f3;
                            alignas(8) bool f4;
                        };


                        inline M268* mutable_f1(){
                            f1 = new M268();
                            return f1;
                        }
                        inline M268*& get_f1(){
                            return f1;
                        }
                    
                        inline M277* mutable_f2(){
                            f2 = new M277();
                            return f2;
                        }
                        inline M277*& get_f2(){
                            return f2;
                        }
                    
                        inline void set_f3(float val){
                            f3 = val;
                        }
                        inline float& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            if(f1 != nullptr)
                                f1->print_message(fout);
                            if(f2 != nullptr)
                                f2->print_message(fout);
                            fout << "M267->f3: " << f3 << std::endl;
                        }
                    
                        ~M267(){
                            if(f1 != nullptr)
                                delete f1;
                            if(f2 != nullptr)
                                delete f2;
                        }
                    
                        M267(){
                           f1 = nullptr;
                           f2 = nullptr;
                        }
                    
                    private:
                        alignas(8) M268* f1;
                        alignas(8) M277* f2;
                        alignas(8) float f3;
                    };


                    class alignas(8) M278 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 68,
                            E1_CONST_2 = 9,
                            E1_CONST_3 = 110,
                            E1_CONST_4 = 14,
                            E1_CONST_5 = 60,
                        };
                        
                        inline void set_f1(E1 val){
                            f1 = val;
                        }
                        inline E1& get_f1(){
                            return f1;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M278->f1: " << f1 << std::endl;
                        }
                    
                        ~M278(){
                        }
                    
                        M278(){
                        }
                    
                    private:
                        alignas(8) E1 f1;
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
                
                    inline void set_f3(uint32_t val){
                        f3 = val;
                    }
                    inline uint32_t& get_f3(){
                        return f3;
                    }
                
                    inline void set_f4(bool val){
                        f4 = val;
                    }
                    inline bool& get_f4(){
                        return f4;
                    }
                
                    inline void set_f5(uint32_t val){
                        f5 = val;
                    }
                    inline uint32_t& get_f5(){
                        return f5;
                    }
                
                    inline M264* mutable_f6(){
                        f6 = new M264();
                        return f6;
                    }
                    inline M264*& get_f6(){
                        return f6;
                    }
                
                    inline void set_f7(uint32_t val){
                        f7 = val;
                    }
                    inline uint32_t& get_f7(){
                        return f7;
                    }
                
                    inline M267* mutable_f8(){
                        f8 = new M267();
                        return f8;
                    }
                    inline M267*& get_f8(){
                        return f8;
                    }
                
                    inline void set_f9(int32_t val){
                        f9 = val;
                    }
                    inline int32_t& get_f9(){
                        return f9;
                    }
                
                    inline M278* mutable_f10(){
                        f10 = new M278();
                        return f10;
                    }
                    inline M278*& get_f10(){
                        return f10;
                    }
                
                    inline void set_f11(E2 val){
                        f11 = val;
                    }
                    inline E2& get_f11(){
                        return f11;
                    }
                
                    inline void set_f12(uint32_t val){
                        f12 = val;
                    }
                    inline uint32_t& get_f12(){
                        return f12;
                    }
                
                    inline void set_f13(E3 val){
                        f13 = val;
                    }
                    inline E3& get_f13(){
                        return f13;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M263->f1: " << f1 << std::endl;
                        fout << "M263->f2: " << f2 << std::endl;
                        fout << "M263->f3: " << f3 << std::endl;
                        fout << "M263->f4: " << f4 << std::endl;
                        fout << "M263->f5: " << f5 << std::endl;
                        if(f6 != nullptr)
                            f6->print_message(fout);
                        fout << "M263->f7: " << f7 << std::endl;
                        if(f8 != nullptr)
                            f8->print_message(fout);
                        fout << "M263->f9: " << f9 << std::endl;
                        if(f10 != nullptr)
                            f10->print_message(fout);
                        fout << "M263->f11: " << f11 << std::endl;
                        fout << "M263->f12: " << f12 << std::endl;
                        fout << "M263->f13: " << f13 << std::endl;
                    }
                
                    ~M263(){
                        if(f6 != nullptr)
                            delete f6;
                        if(f8 != nullptr)
                            delete f8;
                        if(f10 != nullptr)
                            delete f10;
                    }
                
                    M263(){
                       f6 = nullptr;
                       f8 = nullptr;
                       f10 = nullptr;
                    }
                
                private:
                    alignas(8) float f1;
                    alignas(8) E1 f2;
                    alignas(8) uint32_t f3;
                    alignas(8) bool f4;
                    alignas(8) uint32_t f5;
                    alignas(8) M264* f6;
                    alignas(8) uint32_t f7;
                    alignas(8) M267* f8;
                    alignas(8) int32_t f9;
                    alignas(8) M278* f10;
                    alignas(8) E2 f11;
                    alignas(8) uint32_t f12;
                    alignas(8) E3 f13;
                };


                inline void set_f1(int64_t val){
                    f1 = val;
                }
                inline int64_t& get_f1(){
                    return f1;
                }
            
                inline M261* mutable_f2(){
                    f2 = new M261();
                    return f2;
                }
                inline M261*& get_f2(){
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
            
                inline void set_f7(float val){
                    f7 = val;
                }
                inline float& get_f7(){
                    return f7;
                }
            
                inline void set_f8(float val){
                    f8 = val;
                }
                inline float& get_f8(){
                    return f8;
                }
            
                inline M263* mutable_f9(){
                    f9 = new M263();
                    return f9;
                }
                inline M263*& get_f9(){
                    return f9;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M260->f1: " << f1 << std::endl;
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    fout << "M260->f3: " << f3 << std::endl;
                    fout << "M260->f4: " << f4 << std::endl;
                    fout << "M260->f5: " << f5 << std::endl;
                    fout << "M260->f6: " << f6 << std::endl;
                    fout << "M260->f7: " << f7 << std::endl;
                    fout << "M260->f8: " << f8 << std::endl;
                    if(f9 != nullptr)
                        f9->print_message(fout);
                }
            
                ~M260(){
                    if(f2 != nullptr)
                        delete f2;
                    if(f9 != nullptr)
                        delete f9;
                }
            
                M260(){
                   f2 = nullptr;
                   f9 = nullptr;
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) M261* f2;
                alignas(8) int32_t f3;
                alignas(8) E1 f4;
                alignas(8) int32_t f5;
                alignas(8) int32_t f6;
                alignas(8) float f7;
                alignas(8) float f8;
                alignas(8) M263* f9;
            };


            inline void set_f1(int64_t val){
                f1 = val;
            }
            inline int64_t& get_f1(){
                return f1;
            }
        
            inline M260* mutable_f2(){
                f2 = new M260();
                return f2;
            }
            inline M260*& get_f2(){
                return f2;
            }
        
            inline void set_f3(E1 val){
                f3 = val;
            }
            inline E1& get_f3(){
                return f3;
            }
        
            inline void set_f4(bool val){
                f4 = val;
            }
            inline bool& get_f4(){
                return f4;
            }
        
            inline void set_f5(float val){
                f5 = val;
            }
            inline float& get_f5(){
                return f5;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M259->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                fout << "M259->f3: " << f3 << std::endl;
                fout << "M259->f4: " << f4 << std::endl;
                fout << "M259->f5: " << f5 << std::endl;
            }
        
            ~M259(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M259(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) M260* f2;
            alignas(8) E1 f3;
            alignas(8) bool f4;
            alignas(8) float f5;
        };


        class alignas(8) M279 : public M_base
        {
        public:
            inline void set_f1(int32_t val){
                f1 = val;
            }
            inline int32_t& get_f1(){
                return f1;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M279->f1: " << f1 << std::endl;
            }
        
            ~M279(){
            }
        
            M279(){
            }
        
        private:
            alignas(8) int32_t f1;
        };


        inline void set_f1(uint32_t val){
            f1 = val;
        }
        inline uint32_t& get_f1(){
            return f1;
        }
    
        inline M259* mutable_f2(){
            f2 = new M259();
            return f2;
        }
        inline M259*& get_f2(){
            return f2;
        }
    
        inline void set_f3(E1 val){
            f3 = val;
        }
        inline E1& get_f3(){
            return f3;
        }
    
        inline M279* mutable_f4(){
            f4 = new M279();
            return f4;
        }
        inline M279*& get_f4(){
            return f4;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M258->f1: " << f1 << std::endl;
            if(f2 != nullptr)
                f2->print_message(fout);
            fout << "M258->f3: " << f3 << std::endl;
            if(f4 != nullptr)
                f4->print_message(fout);
        }
    
        ~M258(){
            if(f2 != nullptr)
                delete f2;
            if(f4 != nullptr)
                delete f4;
        }
    
        M258(){
           f2 = nullptr;
           f4 = nullptr;
        }
    
    private:
        alignas(8) uint32_t f1;
        alignas(8) M259* f2;
        alignas(8) E1 f3;
        alignas(8) M279* f4;
    };


    class alignas(8) M280 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 35,
            E1_CONST_2 = 5,
            E1_CONST_3 = 73,
            E1_CONST_4 = 75,
            E1_CONST_5 = 15,
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
    
        inline void set_f3(float val){
            f3 = val;
        }
        inline float& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M280->f1: " << f1 << std::endl;
            fout << "M280->f2: " << f2 << std::endl;
            fout << "M280->f3: " << f3 << std::endl;
        }
    
        ~M280(){
        }
    
        M280(){
        }
    
    private:
        alignas(8) string f1;
        alignas(8) E1 f2;
        alignas(8) float f3;
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

    inline M253* mutable_f7(){
        f7 = new M253();
        return f7;
    }
    inline M253*& get_f7(){
        return f7;
    }

    inline M256* mutable_f8(){
        f8 = new M256();
        return f8;
    }
    inline M256*& get_f8(){
        return f8;
    }

    inline void set_f9(float val){
        f9 = val;
    }
    inline float& get_f9(){
        return f9;
    }

    inline M258* mutable_f10(){
        f10 = new M258();
        return f10;
    }
    inline M258*& get_f10(){
        return f10;
    }

    inline void set_f11(int32_t val){
        f11 = val;
    }
    inline int32_t& get_f11(){
        return f11;
    }

    inline void set_f12(bool val){
        f12 = val;
    }
    inline bool& get_f12(){
        return f12;
    }

    inline M280* mutable_f13(){
        f13 = new M280();
        return f13;
    }
    inline M280*& get_f13(){
        return f13;
    }

    inline void set_f14(E2 val){
        f14 = val;
    }
    inline E2& get_f14(){
        return f14;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M252->f1: " << f1 << std::endl;
        fout << "M252->f2: " << f2 << std::endl;
        fout << "M252->f3: " << f3 << std::endl;
        fout << "M252->f4: " << f4 << std::endl;
        fout << "M252->f5: " << f5 << std::endl;
        fout << "M252->f6: " << f6 << std::endl;
        if(f7 != nullptr)
            f7->print_message(fout);
        if(f8 != nullptr)
            f8->print_message(fout);
        fout << "M252->f9: " << f9 << std::endl;
        if(f10 != nullptr)
            f10->print_message(fout);
        fout << "M252->f11: " << f11 << std::endl;
        fout << "M252->f12: " << f12 << std::endl;
        if(f13 != nullptr)
            f13->print_message(fout);
        fout << "M252->f14: " << f14 << std::endl;
    }

    ~M252(){
        if(f7 != nullptr)
            delete f7;
        if(f8 != nullptr)
            delete f8;
        if(f10 != nullptr)
            delete f10;
        if(f13 != nullptr)
            delete f13;
    }

    M252(){
       f7 = nullptr;
       f8 = nullptr;
       f10 = nullptr;
       f13 = nullptr;
    }

private:
    alignas(8) int32_t f1;
    alignas(8) bool f2;
    alignas(8) E1 f3;
    alignas(8) string f4;
    alignas(8) int32_t f5;
    alignas(8) int32_t f6;
    alignas(8) M253* f7;
    alignas(8) M256* f8;
    alignas(8) float f9;
    alignas(8) M258* f10;
    alignas(8) int32_t f11;
    alignas(8) bool f12;
    alignas(8) M280* f13;
    alignas(8) E2 f14;
};


class alignas(8) M281 : public M_base
{
public:
    class alignas(8) M282 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 101,
            E1_CONST_2 = 44,
            E1_CONST_3 = 78,
            E1_CONST_4 = 56,
            E1_CONST_5 = 29,
        };
        
        enum E2 {
            E2_CONST_1 = 99,
            E2_CONST_2 = 40,
            E2_CONST_3 = 44,
            E2_CONST_4 = 20,
            E2_CONST_5 = 93,
        };
        
        class alignas(8) M283 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 110,
                E1_CONST_2 = 47,
                E1_CONST_3 = 113,
                E1_CONST_4 = 116,
                E1_CONST_5 = 29,
            };
            
            class alignas(8) M284 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 34,
                    E1_CONST_2 = 13,
                    E1_CONST_3 = 55,
                    E1_CONST_4 = 123,
                    E1_CONST_5 = 28,
                };
                
                enum E2 {
                    E2_CONST_1 = 65,
                    E2_CONST_2 = 40,
                    E2_CONST_3 = 9,
                    E2_CONST_4 = 46,
                    E2_CONST_5 = 123,
                };
                
                enum E3 {
                    E3_CONST_1 = 71,
                    E3_CONST_2 = 73,
                    E3_CONST_3 = 77,
                    E3_CONST_4 = 115,
                    E3_CONST_5 = 28,
                };
                
                enum E4 {
                    E4_CONST_1 = 73,
                    E4_CONST_2 = 79,
                    E4_CONST_3 = 112,
                    E4_CONST_4 = 57,
                    E4_CONST_5 = 93,
                };
                
                inline void set_f1(uint32_t val){
                    f1 = val;
                }
                inline uint32_t& get_f1(){
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
            
                inline void set_f4(int64_t val){
                    f4 = val;
                }
                inline int64_t& get_f4(){
                    return f4;
                }
            
                inline void set_f5(E2 val){
                    f5 = val;
                }
                inline E2& get_f5(){
                    return f5;
                }
            
                inline void set_f6(E3 val){
                    f6 = val;
                }
                inline E3& get_f6(){
                    return f6;
                }
            
                inline void set_f7(E4 val){
                    f7 = val;
                }
                inline E4& get_f7(){
                    return f7;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M284->f1: " << f1 << std::endl;
                    fout << "M284->f2: " << f2 << std::endl;
                    fout << "M284->f3: " << f3 << std::endl;
                    fout << "M284->f4: " << f4 << std::endl;
                    fout << "M284->f5: " << f5 << std::endl;
                    fout << "M284->f6: " << f6 << std::endl;
                    fout << "M284->f7: " << f7 << std::endl;
                }
            
                ~M284(){
                }
            
                M284(){
                }
            
            private:
                alignas(8) uint32_t f1;
                alignas(8) E1 f2;
                alignas(8) int32_t f3;
                alignas(8) int64_t f4;
                alignas(8) E2 f5;
                alignas(8) E3 f6;
                alignas(8) E4 f7;
            };


            inline void set_f1(E1 val){
                f1 = val;
            }
            inline E1& get_f1(){
                return f1;
            }
        
            inline M284* mutable_f2(){
                f2 = new M284();
                return f2;
            }
            inline M284*& get_f2(){
                return f2;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M283->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
            }
        
            ~M283(){
                if(f2 != nullptr)
                    delete f2;
            }
        
            M283(){
               f2 = nullptr;
            }
        
        private:
            alignas(8) E1 f1;
            alignas(8) M284* f2;
        };


        class alignas(8) M285 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 7,
                E1_CONST_2 = 51,
                E1_CONST_3 = 57,
                E1_CONST_4 = 122,
                E1_CONST_5 = 59,
            };
            
            class alignas(8) M286 : public M_base
            {
            public:
                class alignas(8) M287 : public M_base
                {
                public:
                    class alignas(8) M288 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 12,
                            E1_CONST_2 = 76,
                            E1_CONST_3 = 46,
                            E1_CONST_4 = 117,
                            E1_CONST_5 = 124,
                        };
                        
                        enum E2 {
                            E2_CONST_1 = 11,
                            E2_CONST_2 = 55,
                            E2_CONST_3 = 24,
                            E2_CONST_4 = 122,
                            E2_CONST_5 = 31,
                        };
                        
                        enum E3 {
                            E3_CONST_1 = 5,
                            E3_CONST_2 = 39,
                            E3_CONST_3 = 42,
                            E3_CONST_4 = 109,
                            E3_CONST_5 = 124,
                        };
                        
                        enum E4 {
                            E4_CONST_1 = 69,
                            E4_CONST_2 = 83,
                            E4_CONST_3 = 86,
                            E4_CONST_4 = 24,
                            E4_CONST_5 = 89,
                        };
                        
                        enum E5 {
                            E5_CONST_1 = 67,
                            E5_CONST_2 = 75,
                            E5_CONST_3 = 81,
                            E5_CONST_4 = 122,
                            E5_CONST_5 = 31,
                        };
                        
                        inline void set_f1(bool val){
                            f1 = val;
                        }
                        inline bool& get_f1(){
                            return f1;
                        }
                    
                        inline void set_f2(E1 val){
                            f2 = val;
                        }
                        inline E1& get_f2(){
                            return f2;
                        }
                    
                        inline void set_f3(float val){
                            f3 = val;
                        }
                        inline float& get_f3(){
                            return f3;
                        }
                    
                        inline void set_f4(E2 val){
                            f4 = val;
                        }
                        inline E2& get_f4(){
                            return f4;
                        }
                    
                        inline void set_f5(int64_t val){
                            f5 = val;
                        }
                        inline int64_t& get_f5(){
                            return f5;
                        }
                    
                        inline void set_f6(E3 val){
                            f6 = val;
                        }
                        inline E3& get_f6(){
                            return f6;
                        }
                    
                        inline void set_f7(E4 val){
                            f7 = val;
                        }
                        inline E4& get_f7(){
                            return f7;
                        }
                    
                        inline void set_f8(E5 val){
                            f8 = val;
                        }
                        inline E5& get_f8(){
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
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M288->f1: " << f1 << std::endl;
                            fout << "M288->f2: " << f2 << std::endl;
                            fout << "M288->f3: " << f3 << std::endl;
                            fout << "M288->f4: " << f4 << std::endl;
                            fout << "M288->f5: " << f5 << std::endl;
                            fout << "M288->f6: " << f6 << std::endl;
                            fout << "M288->f7: " << f7 << std::endl;
                            fout << "M288->f8: " << f8 << std::endl;
                            fout << "M288->f9: " << f9 << std::endl;
                            fout << "M288->f10: " << f10 << std::endl;
                        }
                    
                        ~M288(){
                        }
                    
                        M288(){
                        }
                    
                    private:
                        alignas(8) bool f1;
                        alignas(8) E1 f2;
                        alignas(8) float f3;
                        alignas(8) E2 f4;
                        alignas(8) int64_t f5;
                        alignas(8) E3 f6;
                        alignas(8) E4 f7;
                        alignas(8) E5 f8;
                        alignas(8) float f9;
                        alignas(8) bool f10;
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
                
                    inline M288* mutable_f3(){
                        f3 = new M288();
                        return f3;
                    }
                    inline M288*& get_f3(){
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
                        fout << "M287->f1: " << f1 << std::endl;
                        fout << "M287->f2: " << f2 << std::endl;
                        if(f3 != nullptr)
                            f3->print_message(fout);
                        fout << "M287->f4: " << f4 << std::endl;
                        fout << "M287->f5: " << f5 << std::endl;
                    }
                
                    ~M287(){
                        if(f3 != nullptr)
                            delete f3;
                    }
                
                    M287(){
                       f3 = nullptr;
                    }
                
                private:
                    alignas(8) int32_t f1;
                    alignas(8) float f2;
                    alignas(8) M288* f3;
                    alignas(8) uint32_t f4;
                    alignas(8) int32_t f5;
                };


                class alignas(8) M289 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 11,
                        E1_CONST_2 = 76,
                        E1_CONST_3 = 47,
                        E1_CONST_4 = 51,
                        E1_CONST_5 = 63,
                    };
                    
                    inline void set_f1(E1 val){
                        f1 = val;
                    }
                    inline E1& get_f1(){
                        return f1;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M289->f1: " << f1 << std::endl;
                    }
                
                    ~M289(){
                    }
                
                    M289(){
                    }
                
                private:
                    alignas(8) E1 f1;
                };


                inline M287* mutable_f1(){
                    f1 = new M287();
                    return f1;
                }
                inline M287*& get_f1(){
                    return f1;
                }
            
                inline M289* mutable_f2(){
                    f2 = new M289();
                    return f2;
                }
                inline M289*& get_f2(){
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
                    if(f2 != nullptr)
                        f2->print_message(fout);
                    fout << "M286->f3: " << f3 << std::endl;
                }
            
                ~M286(){
                    if(f1 != nullptr)
                        delete f1;
                    if(f2 != nullptr)
                        delete f2;
                }
            
                M286(){
                   f1 = nullptr;
                   f2 = nullptr;
                }
            
            private:
                alignas(8) M287* f1;
                alignas(8) M289* f2;
                alignas(8) bool f3;
            };


            inline void set_f1(uint64_t val){
                f1 = val;
            }
            inline uint64_t& get_f1(){
                return f1;
            }
        
            inline void set_f2(E1 val){
                f2 = val;
            }
            inline E1& get_f2(){
                return f2;
            }
        
            inline void add_f3(string val){
                f3.push_back(val);
            }
            inline string& get_f3(int idx){
                return f3[idx];
            }
        
            inline M286* mutable_f4(){
                f4 = new M286();
                return f4;
            }
            inline M286*& get_f4(){
                return f4;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M285->f1: " << f1 << std::endl;
                fout << "M285->f2: " << f2 << std::endl;
                for(auto &f3_val : f3){
                    fout << "M285->f3: " << f3_val << std::endl;
                }
                if(f4 != nullptr)
                    f4->print_message(fout);
            }
        
            ~M285(){
                if(f4 != nullptr)
                    delete f4;
            }
        
            M285(){
               f4 = nullptr;
            }
        
        private:
            alignas(8) uint64_t f1;
            alignas(8) E1 f2;
            alignas(8) std::vector<string> f3;
            alignas(8) M286* f4;
        };


        inline M283* mutable_f1(){
            f1 = new M283();
            return f1;
        }
        inline M283*& get_f1(){
            return f1;
        }
    
        inline void set_f2(uint32_t val){
            f2 = val;
        }
        inline uint32_t& get_f2(){
            return f2;
        }
    
        inline void set_f3(string val){
            f3 = val;
        }
        inline string& get_f3(){
            return f3;
        }
    
        inline void set_f4(E1 val){
            f4 = val;
        }
        inline E1& get_f4(){
            return f4;
        }
    
        inline void set_f5(E2 val){
            f5 = val;
        }
        inline E2& get_f5(){
            return f5;
        }
    
        inline M285* mutable_f6(){
            f6 = new M285();
            return f6;
        }
        inline M285*& get_f6(){
            return f6;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M282->f2: " << f2 << std::endl;
            fout << "M282->f3: " << f3 << std::endl;
            fout << "M282->f4: " << f4 << std::endl;
            fout << "M282->f5: " << f5 << std::endl;
            if(f6 != nullptr)
                f6->print_message(fout);
        }
    
        ~M282(){
            if(f1 != nullptr)
                delete f1;
            if(f6 != nullptr)
                delete f6;
        }
    
        M282(){
           f1 = nullptr;
           f6 = nullptr;
        }
    
    private:
        alignas(8) M283* f1;
        alignas(8) uint32_t f2;
        alignas(8) string f3;
        alignas(8) E1 f4;
        alignas(8) E2 f5;
        alignas(8) M285* f6;
    };


    class alignas(8) M290 : public M_base
    {
    public:
        enum E1 {
            E1_CONST_1 = 2,
            E1_CONST_2 = 100,
            E1_CONST_3 = 15,
            E1_CONST_4 = 83,
            E1_CONST_5 = 89,
        };
        
        class alignas(8) M291 : public M_base
        {
        public:
            enum E1 {
                E1_CONST_1 = 73,
                E1_CONST_2 = 46,
                E1_CONST_3 = 81,
                E1_CONST_4 = 29,
                E1_CONST_5 = 95,
            };
            
            enum E2 {
                E2_CONST_1 = 38,
                E2_CONST_2 = 39,
                E2_CONST_3 = 19,
                E2_CONST_4 = 88,
                E2_CONST_5 = 90,
            };
            
            enum E3 {
                E3_CONST_1 = 33,
                E3_CONST_2 = 16,
                E3_CONST_3 = 82,
                E3_CONST_4 = 115,
                E3_CONST_5 = 87,
            };
            
            inline void set_f1(uint32_t val){
                f1 = val;
            }
            inline uint32_t& get_f1(){
                return f1;
            }
        
            inline void set_f2(E1 val){
                f2 = val;
            }
            inline E1& get_f2(){
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
        
            inline void add_f6(string val){
                f6.push_back(val);
            }
            inline string& get_f6(int idx){
                return f6[idx];
            }
        
            inline void set_f7(E2 val){
                f7 = val;
            }
            inline E2& get_f7(){
                return f7;
            }
        
            inline void set_f8(E3 val){
                f8 = val;
            }
            inline E3& get_f8(){
                return f8;
            }
        
            inline void set_f9(float val){
                f9 = val;
            }
            inline float& get_f9(){
                return f9;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M291->f1: " << f1 << std::endl;
                fout << "M291->f2: " << f2 << std::endl;
                fout << "M291->f3: " << f3 << std::endl;
                fout << "M291->f4: " << f4 << std::endl;
                fout << "M291->f5: " << f5 << std::endl;
                for(auto &f6_val : f6){
                    fout << "M291->f6: " << f6_val << std::endl;
                }
                fout << "M291->f7: " << f7 << std::endl;
                fout << "M291->f8: " << f8 << std::endl;
                fout << "M291->f9: " << f9 << std::endl;
            }
        
            ~M291(){
            }
        
            M291(){
            }
        
        private:
            alignas(8) uint32_t f1;
            alignas(8) E1 f2;
            alignas(8) uint64_t f3;
            alignas(8) int32_t f4;
            alignas(8) float f5;
            alignas(8) std::vector<string> f6;
            alignas(8) E2 f7;
            alignas(8) E3 f8;
            alignas(8) float f9;
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
    
        inline void set_f7(float val){
            f7 = val;
        }
        inline float& get_f7(){
            return f7;
        }
    
        inline void set_f8(E1 val){
            f8 = val;
        }
        inline E1& get_f8(){
            return f8;
        }
    
        inline M291* mutable_f9(){
            f9 = new M291();
            return f9;
        }
        inline M291*& get_f9(){
            return f9;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M290->f1: " << f1 << std::endl;
            fout << "M290->f2: " << f2 << std::endl;
            fout << "M290->f3: " << f3 << std::endl;
            fout << "M290->f4: " << f4 << std::endl;
            fout << "M290->f5: " << f5 << std::endl;
            fout << "M290->f6: " << f6 << std::endl;
            fout << "M290->f7: " << f7 << std::endl;
            fout << "M290->f8: " << f8 << std::endl;
            if(f9 != nullptr)
                f9->print_message(fout);
        }
    
        ~M290(){
            if(f9 != nullptr)
                delete f9;
        }
    
        M290(){
           f9 = nullptr;
        }
    
    private:
        alignas(8) bool f1;
        alignas(8) int32_t f2;
        alignas(8) int64_t f3;
        alignas(8) bool f4;
        alignas(8) int64_t f5;
        alignas(8) bool f6;
        alignas(8) float f7;
        alignas(8) E1 f8;
        alignas(8) M291* f9;
    };


    class alignas(8) M292 : public M_base
    {
    public:
        class alignas(8) M293 : public M_base
        {
        public:
            class alignas(8) M294 : public M_base
            {
            public:
                inline void set_f1(int64_t val){
                    f1 = val;
                }
                inline int64_t& get_f1(){
                    return f1;
                }
            
                inline void set_f2(uint32_t val){
                    f2 = val;
                }
                inline uint32_t& get_f2(){
                    return f2;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M294->f1: " << f1 << std::endl;
                    fout << "M294->f2: " << f2 << std::endl;
                }
            
                ~M294(){
                }
            
                M294(){
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) uint32_t f2;
            };


            class alignas(8) M295 : public M_base
            {
            public:
                enum E1 {
                    E1_CONST_1 = 67,
                    E1_CONST_2 = 8,
                    E1_CONST_3 = 77,
                    E1_CONST_4 = 46,
                    E1_CONST_5 = 123,
                };
                
                enum E2 {
                    E2_CONST_1 = 106,
                    E2_CONST_2 = 49,
                    E2_CONST_3 = 23,
                    E2_CONST_4 = 28,
                    E2_CONST_5 = 94,
                };
                
                class alignas(8) M296 : public M_base
                {
                public:
                    enum E1 {
                        E1_CONST_1 = 75,
                        E1_CONST_2 = 107,
                        E1_CONST_3 = 113,
                        E1_CONST_4 = 118,
                        E1_CONST_5 = 92,
                    };
                    
                    inline void set_f1(uint32_t val){
                        f1 = val;
                    }
                    inline uint32_t& get_f1(){
                        return f1;
                    }
                
                    inline void set_f2(E1 val){
                        f2 = val;
                    }
                    inline E1& get_f2(){
                        return f2;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M296->f1: " << f1 << std::endl;
                        fout << "M296->f2: " << f2 << std::endl;
                    }
                
                    ~M296(){
                    }
                
                    M296(){
                    }
                
                private:
                    alignas(8) uint32_t f1;
                    alignas(8) E1 f2;
                };


                class alignas(8) M297 : public M_base
                {
                public:
                    class alignas(8) M298 : public M_base
                    {
                    public:
                        enum E1 {
                            E1_CONST_1 = 102,
                            E1_CONST_2 = 105,
                            E1_CONST_3 = 74,
                            E1_CONST_4 = 14,
                            E1_CONST_5 = 122,
                        };
                        
                        class alignas(8) M299 : public M_base
                        {
                        public:
                            inline void set_f1(uint32_t val){
                                f1 = val;
                            }
                            inline uint32_t& get_f1(){
                                return f1;
                            }
                        
                            inline void add_f2(string val){
                                f2.push_back(val);
                            }
                            inline string& get_f2(int idx){
                                return f2[idx];
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M299->f1: " << f1 << std::endl;
                                for(auto &f2_val : f2){
                                    fout << "M299->f2: " << f2_val << std::endl;
                                }
                            }
                        
                            ~M299(){
                            }
                        
                            M299(){
                            }
                        
                        private:
                            alignas(8) uint32_t f1;
                            alignas(8) std::vector<string> f2;
                        };


                        inline M299* mutable_f1(){
                            f1 = new M299();
                            return f1;
                        }
                        inline M299*& get_f1(){
                            return f1;
                        }
                    
                        inline void add_f2(int64_t val){
                            f2.push_back(val);
                        }
                        inline int64_t& get_f2(int idx){
                            return f2[idx];
                        }
                    
                        inline void set_f3(E1 val){
                            f3 = val;
                        }
                        inline E1& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            if(f1 != nullptr)
                                f1->print_message(fout);
                            for(auto &f2_val : f2){
                                fout << "M298->f2: " << f2_val << std::endl;
                            }
                            fout << "M298->f3: " << f3 << std::endl;
                        }
                    
                        ~M298(){
                            if(f1 != nullptr)
                                delete f1;
                        }
                    
                        M298(){
                           f1 = nullptr;
                        }
                    
                    private:
                        alignas(8) M299* f1;
                        alignas(8) std::vector<int64_t> f2;
                        alignas(8) E1 f3;
                    };


                    class alignas(8) M300 : public M_base
                    {
                    public:
                        inline void add_f1(float val){
                            f1.push_back(val);
                        }
                        inline float& get_f1(int idx){
                            return f1[idx];
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            for(auto &f1_val : f1){
                                fout << "M300->f1: " << f1_val << std::endl;
                            }
                        }
                    
                        ~M300(){
                        }
                    
                        M300(){
                        }
                    
                    private:
                        alignas(8) std::vector<float> f1;
                    };


                    class alignas(8) M301 : public M_base
                    {
                    public:
                        class alignas(8) M302 : public M_base
                        {
                        public:
                            enum E1 {
                                E1_CONST_1 = 36,
                                E1_CONST_2 = 37,
                                E1_CONST_3 = 81,
                                E1_CONST_4 = 22,
                                E1_CONST_5 = 29,
                            };
                            
                            enum E2 {
                                E2_CONST_1 = 98,
                                E2_CONST_2 = 36,
                                E2_CONST_3 = 107,
                                E2_CONST_4 = 120,
                                E2_CONST_5 = 63,
                            };
                            
                            class alignas(8) M303 : public M_base
                            {
                            public:
                                enum E1 {
                                    E1_CONST_1 = 65,
                                    E1_CONST_2 = 40,
                                    E1_CONST_3 = 16,
                                    E1_CONST_4 = 113,
                                    E1_CONST_5 = 86,
                                };
                                
                                enum E2 {
                                    E2_CONST_1 = 97,
                                    E2_CONST_2 = 102,
                                    E2_CONST_3 = 91,
                                    E2_CONST_4 = 107,
                                    E2_CONST_5 = 27,
                                };
                                
                                class alignas(8) M304 : public M_base
                                {
                                public:
                                    enum E1 {
                                        E1_CONST_1 = 4,
                                        E1_CONST_2 = 71,
                                        E1_CONST_3 = 51,
                                        E1_CONST_4 = 91,
                                        E1_CONST_5 = 92,
                                    };
                                    
                                    enum E2 {
                                        E2_CONST_1 = 43,
                                        E2_CONST_2 = 79,
                                        E2_CONST_3 = 115,
                                        E2_CONST_4 = 86,
                                        E2_CONST_5 = 123,
                                    };
                                    
                                    enum E3 {
                                        E3_CONST_1 = 68,
                                        E3_CONST_2 = 36,
                                        E3_CONST_3 = 112,
                                        E3_CONST_4 = 84,
                                        E3_CONST_5 = 92,
                                    };
                                    
                                    class alignas(8) M305 : public M_base
                                    {
                                    public:
                                        class alignas(8) M306 : public M_base
                                        {
                                        public:
                                            enum E1 {
                                                E1_CONST_1 = 35,
                                                E1_CONST_2 = 37,
                                                E1_CONST_3 = 114,
                                                E1_CONST_4 = 83,
                                                E1_CONST_5 = 59,
                                            };
                                            
                                            class alignas(8) M307 : public M_base
                                            {
                                            public:
                                                enum E1 {
                                                    E1_CONST_1 = 10,
                                                    E1_CONST_2 = 77,
                                                    E1_CONST_3 = 53,
                                                    E1_CONST_4 = 24,
                                                    E1_CONST_5 = 90,
                                                };
                                                
                                                enum E2 {
                                                    E2_CONST_1 = 96,
                                                    E2_CONST_2 = 35,
                                                    E2_CONST_3 = 11,
                                                    E2_CONST_4 = 45,
                                                    E2_CONST_5 = 23,
                                                };
                                                
                                                class alignas(8) M308 : public M_base
                                                {
                                                public:
                                                    enum E1 {
                                                        E1_CONST_1 = 2,
                                                        E1_CONST_2 = 76,
                                                        E1_CONST_3 = 111,
                                                        E1_CONST_4 = 88,
                                                        E1_CONST_5 = 26,
                                                    };
                                                    
                                                    class alignas(8) M309 : public M_base
                                                    {
                                                    public:
                                                        inline void set_f1(int32_t val){
                                                            f1 = val;
                                                        }
                                                        inline int32_t& get_f1(){
                                                            return f1;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M309->f1: " << f1 << std::endl;
                                                        }
                                                    
                                                        ~M309(){
                                                        }
                                                    
                                                        M309(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) int32_t f1;
                                                    };


                                                    class alignas(8) M310 : public M_base
                                                    {
                                                    public:
                                                        enum E1 {
                                                            E1_CONST_1 = 5,
                                                            E1_CONST_2 = 42,
                                                            E1_CONST_3 = 76,
                                                            E1_CONST_4 = 20,
                                                            E1_CONST_5 = 53,
                                                        };
                                                        
                                                        enum E2 {
                                                            E2_CONST_1 = 0,
                                                            E2_CONST_2 = 79,
                                                            E2_CONST_3 = 16,
                                                            E2_CONST_4 = 91,
                                                            E2_CONST_5 = 125,
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
                                                    
                                                        inline void set_f3(float val){
                                                            f3 = val;
                                                        }
                                                        inline float& get_f3(){
                                                            return f3;
                                                        }
                                                    
                                                        inline void set_f4(float val){
                                                            f4 = val;
                                                        }
                                                        inline float& get_f4(){
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
                                                    
                                                        inline void set_f7(E2 val){
                                                            f7 = val;
                                                        }
                                                        inline E2& get_f7(){
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
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M310->f1: " << f1 << std::endl;
                                                            fout << "M310->f2: " << f2 << std::endl;
                                                            fout << "M310->f3: " << f3 << std::endl;
                                                            fout << "M310->f4: " << f4 << std::endl;
                                                            fout << "M310->f5: " << f5 << std::endl;
                                                            fout << "M310->f6: " << f6 << std::endl;
                                                            fout << "M310->f7: " << f7 << std::endl;
                                                            fout << "M310->f8: " << f8 << std::endl;
                                                            fout << "M310->f9: " << f9 << std::endl;
                                                        }
                                                    
                                                        ~M310(){
                                                        }
                                                    
                                                        M310(){
                                                        }
                                                    
                                                    private:
                                                        alignas(8) E1 f1;
                                                        alignas(8) float f2;
                                                        alignas(8) float f3;
                                                        alignas(8) float f4;
                                                        alignas(8) int64_t f5;
                                                        alignas(8) int32_t f6;
                                                        alignas(8) E2 f7;
                                                        alignas(8) float f8;
                                                        alignas(8) int32_t f9;
                                                    };


                                                    inline M309* mutable_f1(){
                                                        f1 = new M309();
                                                        return f1;
                                                    }
                                                    inline M309*& get_f1(){
                                                        return f1;
                                                    }
                                                
                                                    inline M310* mutable_f2(){
                                                        f2 = new M310();
                                                        return f2;
                                                    }
                                                    inline M310*& get_f2(){
                                                        return f2;
                                                    }
                                                
                                                    inline void set_f3(int64_t val){
                                                        f3 = val;
                                                    }
                                                    inline int64_t& get_f3(){
                                                        return f3;
                                                    }
                                                
                                                    inline void set_f4(E1 val){
                                                        f4 = val;
                                                    }
                                                    inline E1& get_f4(){
                                                        return f4;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        if(f1 != nullptr)
                                                            f1->print_message(fout);
                                                        if(f2 != nullptr)
                                                            f2->print_message(fout);
                                                        fout << "M308->f3: " << f3 << std::endl;
                                                        fout << "M308->f4: " << f4 << std::endl;
                                                    }
                                                
                                                    ~M308(){
                                                        if(f1 != nullptr)
                                                            delete f1;
                                                        if(f2 != nullptr)
                                                            delete f2;
                                                    }
                                                
                                                    M308(){
                                                       f1 = nullptr;
                                                       f2 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) M309* f1;
                                                    alignas(8) M310* f2;
                                                    alignas(8) int64_t f3;
                                                    alignas(8) E1 f4;
                                                };


                                                inline M308* mutable_f1(){
                                                    f1 = new M308();
                                                    return f1;
                                                }
                                                inline M308*& get_f1(){
                                                    return f1;
                                                }
                                            
                                                inline void set_f2(E1 val){
                                                    f2 = val;
                                                }
                                                inline E1& get_f2(){
                                                    return f2;
                                                }
                                            
                                                inline void set_f3(E2 val){
                                                    f3 = val;
                                                }
                                                inline E2& get_f3(){
                                                    return f3;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    if(f1 != nullptr)
                                                        f1->print_message(fout);
                                                    fout << "M307->f2: " << f2 << std::endl;
                                                    fout << "M307->f3: " << f3 << std::endl;
                                                }
                                            
                                                ~M307(){
                                                    if(f1 != nullptr)
                                                        delete f1;
                                                }
                                            
                                                M307(){
                                                   f1 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) M308* f1;
                                                alignas(8) E1 f2;
                                                alignas(8) E2 f3;
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
                                        
                                            inline M307* mutable_f3(){
                                                f3 = new M307();
                                                return f3;
                                            }
                                            inline M307*& get_f3(){
                                                return f3;
                                            }
                                        
                                            inline void print_message(std::ofstream &fout){
                                                fout << "M306->f1: " << f1 << std::endl;
                                                fout << "M306->f2: " << f2 << std::endl;
                                                if(f3 != nullptr)
                                                    f3->print_message(fout);
                                            }
                                        
                                            ~M306(){
                                                if(f3 != nullptr)
                                                    delete f3;
                                            }
                                        
                                            M306(){
                                               f3 = nullptr;
                                            }
                                        
                                        private:
                                            alignas(8) E1 f1;
                                            alignas(8) float f2;
                                            alignas(8) M307* f3;
                                        };


                                        inline M306* mutable_f1(){
                                            f1 = new M306();
                                            return f1;
                                        }
                                        inline M306*& get_f1(){
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
                                            fout << "M305->f2: " << f2 << std::endl;
                                        }
                                    
                                        ~M305(){
                                            if(f1 != nullptr)
                                                delete f1;
                                        }
                                    
                                        M305(){
                                           f1 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) M306* f1;
                                        alignas(8) int32_t f2;
                                    };


                                    inline M305* mutable_f1(){
                                        f1 = new M305();
                                        return f1;
                                    }
                                    inline M305*& get_f1(){
                                        return f1;
                                    }
                                
                                    inline void set_f2(int32_t val){
                                        f2 = val;
                                    }
                                    inline int32_t& get_f2(){
                                        return f2;
                                    }
                                
                                    inline void set_f3(E1 val){
                                        f3 = val;
                                    }
                                    inline E1& get_f3(){
                                        return f3;
                                    }
                                
                                    inline void set_f4(E2 val){
                                        f4 = val;
                                    }
                                    inline E2& get_f4(){
                                        return f4;
                                    }
                                
                                    inline void set_f5(int32_t val){
                                        f5 = val;
                                    }
                                    inline int32_t& get_f5(){
                                        return f5;
                                    }
                                
                                    inline void set_f6(E3 val){
                                        f6 = val;
                                    }
                                    inline E3& get_f6(){
                                        return f6;
                                    }
                                
                                    inline void set_f7(int32_t val){
                                        f7 = val;
                                    }
                                    inline int32_t& get_f7(){
                                        return f7;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        if(f1 != nullptr)
                                            f1->print_message(fout);
                                        fout << "M304->f2: " << f2 << std::endl;
                                        fout << "M304->f3: " << f3 << std::endl;
                                        fout << "M304->f4: " << f4 << std::endl;
                                        fout << "M304->f5: " << f5 << std::endl;
                                        fout << "M304->f6: " << f6 << std::endl;
                                        fout << "M304->f7: " << f7 << std::endl;
                                    }
                                
                                    ~M304(){
                                        if(f1 != nullptr)
                                            delete f1;
                                    }
                                
                                    M304(){
                                       f1 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) M305* f1;
                                    alignas(8) int32_t f2;
                                    alignas(8) E1 f3;
                                    alignas(8) E2 f4;
                                    alignas(8) int32_t f5;
                                    alignas(8) E3 f6;
                                    alignas(8) int32_t f7;
                                };


                                inline M304* mutable_f1(){
                                    f1 = new M304();
                                    return f1;
                                }
                                inline M304*& get_f1(){
                                    return f1;
                                }
                            
                                inline void set_f2(E1 val){
                                    f2 = val;
                                }
                                inline E1& get_f2(){
                                    return f2;
                                }
                            
                                inline void set_f3(E2 val){
                                    f3 = val;
                                }
                                inline E2& get_f3(){
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
                            
                                inline void print_message(std::ofstream &fout){
                                    if(f1 != nullptr)
                                        f1->print_message(fout);
                                    fout << "M303->f2: " << f2 << std::endl;
                                    fout << "M303->f3: " << f3 << std::endl;
                                    fout << "M303->f4: " << f4 << std::endl;
                                    fout << "M303->f5: " << f5 << std::endl;
                                }
                            
                                ~M303(){
                                    if(f1 != nullptr)
                                        delete f1;
                                }
                            
                                M303(){
                                   f1 = nullptr;
                                }
                            
                            private:
                                alignas(8) M304* f1;
                                alignas(8) E1 f2;
                                alignas(8) E2 f3;
                                alignas(8) float f4;
                                alignas(8) int32_t f5;
                            };


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
                        
                            inline void add_f3(uint32_t val){
                                f3.push_back(val);
                            }
                            inline uint32_t& get_f3(int idx){
                                return f3[idx];
                            }
                        
                            inline void set_f4(E1 val){
                                f4 = val;
                            }
                            inline E1& get_f4(){
                                return f4;
                            }
                        
                            inline void set_f5(string val){
                                f5 = val;
                            }
                            inline string& get_f5(){
                                return f5;
                            }
                        
                            inline M303* mutable_f6(){
                                f6 = new M303();
                                return f6;
                            }
                            inline M303*& get_f6(){
                                return f6;
                            }
                        
                            inline void set_f7(E2 val){
                                f7 = val;
                            }
                            inline E2& get_f7(){
                                return f7;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M302->f1: " << f1 << std::endl;
                                fout << "M302->f2: " << f2 << std::endl;
                                for(auto &f3_val : f3){
                                    fout << "M302->f3: " << f3_val << std::endl;
                                }
                                fout << "M302->f4: " << f4 << std::endl;
                                fout << "M302->f5: " << f5 << std::endl;
                                if(f6 != nullptr)
                                    f6->print_message(fout);
                                fout << "M302->f7: " << f7 << std::endl;
                            }
                        
                            ~M302(){
                                if(f6 != nullptr)
                                    delete f6;
                            }
                        
                            M302(){
                               f6 = nullptr;
                            }
                        
                        private:
                            alignas(8) float f1;
                            alignas(8) string f2;
                            alignas(8) std::vector<uint32_t> f3;
                            alignas(8) E1 f4;
                            alignas(8) string f5;
                            alignas(8) M303* f6;
                            alignas(8) E2 f7;
                        };


                        inline void add_f1(float val){
                            f1.push_back(val);
                        }
                        inline float& get_f1(int idx){
                            return f1[idx];
                        }
                    
                        inline void set_f2(bool val){
                            f2 = val;
                        }
                        inline bool& get_f2(){
                            return f2;
                        }
                    
                        inline M302* mutable_f3(){
                            f3 = new M302();
                            return f3;
                        }
                        inline M302*& get_f3(){
                            return f3;
                        }
                    
                        inline void set_f4(int32_t val){
                            f4 = val;
                        }
                        inline int32_t& get_f4(){
                            return f4;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            for(auto &f1_val : f1){
                                fout << "M301->f1: " << f1_val << std::endl;
                            }
                            fout << "M301->f2: " << f2 << std::endl;
                            if(f3 != nullptr)
                                f3->print_message(fout);
                            fout << "M301->f4: " << f4 << std::endl;
                        }
                    
                        ~M301(){
                            if(f3 != nullptr)
                                delete f3;
                        }
                    
                        M301(){
                           f3 = nullptr;
                        }
                    
                    private:
                        alignas(8) std::vector<float> f1;
                        alignas(8) bool f2;
                        alignas(8) M302* f3;
                        alignas(8) int32_t f4;
                    };


                    inline void set_f1(float val){
                        f1 = val;
                    }
                    inline float& get_f1(){
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
                
                    inline M298* mutable_f4(){
                        f4 = new M298();
                        return f4;
                    }
                    inline M298*& get_f4(){
                        return f4;
                    }
                
                    inline void set_f5(bool val){
                        f5 = val;
                    }
                    inline bool& get_f5(){
                        return f5;
                    }
                
                    inline M300* mutable_f6(){
                        f6 = new M300();
                        return f6;
                    }
                    inline M300*& get_f6(){
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
                
                    inline M301* mutable_f9(){
                        f9 = new M301();
                        return f9;
                    }
                    inline M301*& get_f9(){
                        return f9;
                    }
                
                    inline void set_f10(int64_t val){
                        f10 = val;
                    }
                    inline int64_t& get_f10(){
                        return f10;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M297->f1: " << f1 << std::endl;
                        fout << "M297->f2: " << f2 << std::endl;
                        fout << "M297->f3: " << f3 << std::endl;
                        if(f4 != nullptr)
                            f4->print_message(fout);
                        fout << "M297->f5: " << f5 << std::endl;
                        if(f6 != nullptr)
                            f6->print_message(fout);
                        fout << "M297->f7: " << f7 << std::endl;
                        fout << "M297->f8: " << f8 << std::endl;
                        if(f9 != nullptr)
                            f9->print_message(fout);
                        fout << "M297->f10: " << f10 << std::endl;
                    }
                
                    ~M297(){
                        if(f4 != nullptr)
                            delete f4;
                        if(f6 != nullptr)
                            delete f6;
                        if(f9 != nullptr)
                            delete f9;
                    }
                
                    M297(){
                       f4 = nullptr;
                       f6 = nullptr;
                       f9 = nullptr;
                    }
                
                private:
                    alignas(8) float f1;
                    alignas(8) int64_t f2;
                    alignas(8) int64_t f3;
                    alignas(8) M298* f4;
                    alignas(8) bool f5;
                    alignas(8) M300* f6;
                    alignas(8) int32_t f7;
                    alignas(8) int64_t f8;
                    alignas(8) M301* f9;
                    alignas(8) int64_t f10;
                };


                inline void set_f1(E1 val){
                    f1 = val;
                }
                inline E1& get_f1(){
                    return f1;
                }
            
                inline void add_f2(float val){
                    f2.push_back(val);
                }
                inline float& get_f2(int idx){
                    return f2[idx];
                }
            
                inline M296* mutable_f3(){
                    f3 = new M296();
                    return f3;
                }
                inline M296*& get_f3(){
                    return f3;
                }
            
                inline M297* mutable_f4(){
                    f4 = new M297();
                    return f4;
                }
                inline M297*& get_f4(){
                    return f4;
                }
            
                inline void set_f5(E2 val){
                    f5 = val;
                }
                inline E2& get_f5(){
                    return f5;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M295->f1: " << f1 << std::endl;
                    for(auto &f2_val : f2){
                        fout << "M295->f2: " << f2_val << std::endl;
                    }
                    if(f3 != nullptr)
                        f3->print_message(fout);
                    if(f4 != nullptr)
                        f4->print_message(fout);
                    fout << "M295->f5: " << f5 << std::endl;
                }
            
                ~M295(){
                    if(f3 != nullptr)
                        delete f3;
                    if(f4 != nullptr)
                        delete f4;
                }
            
                M295(){
                   f3 = nullptr;
                   f4 = nullptr;
                }
            
            private:
                alignas(8) E1 f1;
                alignas(8) std::vector<float> f2;
                alignas(8) M296* f3;
                alignas(8) M297* f4;
                alignas(8) E2 f5;
            };


            inline void set_f1(int64_t val){
                f1 = val;
            }
            inline int64_t& get_f1(){
                return f1;
            }
        
            inline M294* mutable_f2(){
                f2 = new M294();
                return f2;
            }
            inline M294*& get_f2(){
                return f2;
            }
        
            inline M295* mutable_f3(){
                f3 = new M295();
                return f3;
            }
            inline M295*& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M293->f1: " << f1 << std::endl;
                if(f2 != nullptr)
                    f2->print_message(fout);
                if(f3 != nullptr)
                    f3->print_message(fout);
            }
        
            ~M293(){
                if(f2 != nullptr)
                    delete f2;
                if(f3 != nullptr)
                    delete f3;
            }
        
            M293(){
               f2 = nullptr;
               f3 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) M294* f2;
            alignas(8) M295* f3;
        };


        inline M293* mutable_f1(){
            f1 = new M293();
            return f1;
        }
        inline M293*& get_f1(){
            return f1;
        }
    
        inline void set_f2(float val){
            f2 = val;
        }
        inline float& get_f2(){
            return f2;
        }
    
        inline void print_message(std::ofstream &fout){
            if(f1 != nullptr)
                f1->print_message(fout);
            fout << "M292->f2: " << f2 << std::endl;
        }
    
        ~M292(){
            if(f1 != nullptr)
                delete f1;
        }
    
        M292(){
           f1 = nullptr;
        }
    
    private:
        alignas(8) M293* f1;
        alignas(8) float f2;
    };


    inline M282* mutable_f1(){
        f1 = new M282();
        return f1;
    }
    inline M282*& get_f1(){
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

    inline void set_f5(int32_t val){
        f5 = val;
    }
    inline int32_t& get_f5(){
        return f5;
    }

    inline M290* mutable_f6(){
        f6 = new M290();
        return f6;
    }
    inline M290*& get_f6(){
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

    inline void set_f9(bool val){
        f9 = val;
    }
    inline bool& get_f9(){
        return f9;
    }

    inline M292* mutable_f10(){
        f10 = new M292();
        return f10;
    }
    inline M292*& get_f10(){
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

    inline void set_f13(float val){
        f13 = val;
    }
    inline float& get_f13(){
        return f13;
    }

    inline void print_message(std::ofstream &fout){
        if(f1 != nullptr)
            f1->print_message(fout);
        fout << "M281->f2: " << f2 << std::endl;
        fout << "M281->f3: " << f3 << std::endl;
        fout << "M281->f4: " << f4 << std::endl;
        fout << "M281->f5: " << f5 << std::endl;
        if(f6 != nullptr)
            f6->print_message(fout);
        fout << "M281->f7: " << f7 << std::endl;
        fout << "M281->f8: " << f8 << std::endl;
        fout << "M281->f9: " << f9 << std::endl;
        if(f10 != nullptr)
            f10->print_message(fout);
        fout << "M281->f11: " << f11 << std::endl;
        fout << "M281->f12: " << f12 << std::endl;
        fout << "M281->f13: " << f13 << std::endl;
    }

    ~M281(){
        if(f1 != nullptr)
            delete f1;
        if(f6 != nullptr)
            delete f6;
        if(f10 != nullptr)
            delete f10;
    }

    M281(){
       f1 = nullptr;
       f6 = nullptr;
       f10 = nullptr;
    }

private:
    alignas(8) M282* f1;
    alignas(8) int32_t f2;
    alignas(8) int32_t f3;
    alignas(8) int32_t f4;
    alignas(8) int32_t f5;
    alignas(8) M290* f6;
    alignas(8) string f7;
    alignas(8) int32_t f8;
    alignas(8) bool f9;
    alignas(8) M292* f10;
    alignas(8) float f11;
    alignas(8) float f12;
    alignas(8) float f13;
};

M_base* createMessage(int temp_class_id) {
    switch (temp_class_id) {
        case 104:
            return new M104();
        case 123:
            return new M104::M123();
        case 124:
            return new M104::M123::M124();
        case 127:
            return new M104::M123::M124::M127();
        case 128:
            return new M104::M123::M124::M127::M128();
        case 125:
            return new M104::M123::M124::M125();
        case 126:
            return new M104::M123::M124::M125::M126();
        case 105:
            return new M104::M105();
        case 106:
            return new M104::M105::M106();
        case 107:
            return new M104::M105::M106::M107();
        case 111:
            return new M104::M105::M106::M107::M111();
        case 112:
            return new M104::M105::M106::M107::M111::M112();
        case 113:
            return new M104::M105::M106::M107::M111::M112::M113();
        case 114:
            return new M104::M105::M106::M107::M111::M112::M113::M114();
        case 115:
            return new M104::M105::M106::M107::M111::M112::M113::M114::M115();
        case 116:
            return new M104::M105::M106::M107::M111::M112::M113::M114::M115::M116();
        case 117:
            return new M104::M105::M106::M107::M111::M112::M113::M114::M115::M116::M117();
        case 118:
            return new M104::M105::M106::M107::M111::M112::M113::M114::M115::M116::M117::M118();
        case 119:
            return new M104::M105::M106::M107::M111::M112::M113::M114::M115::M116::M117::M118::M119();
        case 120:
            return new M104::M105::M106::M107::M111::M112::M113::M114::M115::M116::M117::M118::M119::M120();
        case 121:
            return new M104::M105::M106::M107::M111::M112::M121();
        case 108:
            return new M104::M105::M106::M107::M108();
        case 109:
            return new M104::M105::M106::M107::M108::M109();
        case 110:
            return new M104::M105::M106::M107::M108::M109::M110();
        case 122:
            return new M104::M105::M106::M122();
        case 129:
            return new M129();
        case 131:
            return new M129::M131();
        case 132:
            return new M129::M131::M132();
        case 133:
            return new M129::M131::M132::M133();
        case 134:
            return new M129::M131::M132::M133::M134();
        case 135:
            return new M129::M131::M132::M133::M134::M135();
        case 136:
            return new M129::M131::M132::M136();
        case 154:
            return new M129::M131::M132::M136::M154();
        case 137:
            return new M129::M131::M132::M136::M137();
        case 139:
            return new M129::M131::M132::M136::M137::M139();
        case 140:
            return new M129::M131::M132::M136::M137::M139::M140();
        case 151:
            return new M129::M131::M132::M136::M137::M139::M140::M151();
        case 152:
            return new M129::M131::M132::M136::M137::M139::M140::M152();
        case 141:
            return new M129::M131::M132::M136::M137::M139::M140::M141();
        case 142:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142();
        case 143:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142::M143();
        case 144:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M144();
        case 145:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M144::M145();
        case 146:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M144::M145::M146();
        case 147:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M147();
        case 148:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M147::M148();
        case 149:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M147::M148::M149();
        case 150:
            return new M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M147::M148::M149::M150();
        case 153:
            return new M129::M131::M132::M136::M137::M139::M153();
        case 138:
            return new M129::M131::M132::M136::M137::M138();
        case 155:
            return new M129::M131::M132::M136::M155();
        case 156:
            return new M129::M131::M132::M136::M156();
        case 157:
            return new M129::M157();
        case 158:
            return new M129::M157::M158();
        case 159:
            return new M129::M157::M159();
        case 160:
            return new M129::M160();
        case 161:
            return new M129::M160::M161();
        case 162:
            return new M129::M160::M162();
        case 130:
            return new M129::M130();
        case 163:
            return new M163();
        case 187:
            return new M163::M187();
        case 188:
            return new M163::M187::M188();
        case 189:
            return new M163::M187::M189();
        case 190:
            return new M163::M187::M189::M190();
        case 191:
            return new M163::M187::M189::M190::M191();
        case 192:
            return new M163::M187::M189::M190::M191::M192();
        case 164:
            return new M163::M164();
        case 165:
            return new M163::M164::M165();
        case 166:
            return new M163::M164::M165::M166();
        case 167:
            return new M163::M164::M165::M166::M167();
        case 168:
            return new M163::M164::M165::M166::M167::M168();
        case 169:
            return new M163::M164::M165::M166::M167::M168::M169();
        case 171:
            return new M163::M164::M165::M166::M167::M168::M169::M171();
        case 170:
            return new M163::M164::M165::M166::M167::M168::M169::M170();
        case 172:
            return new M163::M164::M165::M166::M167::M168::M169::M172();
        case 174:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M174();
        case 175:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M174::M175();
        case 176:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176();
        case 178:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M178();
        case 179:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M178::M179();
        case 181:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M178::M179::M181();
        case 180:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M178::M179::M180();
        case 177:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M177();
        case 173:
            return new M163::M164::M165::M166::M167::M168::M169::M172::M173();
        case 182:
            return new M163::M164::M165::M166::M167::M182();
        case 183:
            return new M163::M164::M183();
        case 185:
            return new M163::M164::M183::M185();
        case 184:
            return new M163::M164::M183::M184();
        case 186:
            return new M163::M164::M183::M186();
        case 193:
            return new M193();
        case 196:
            return new M193::M196();
        case 197:
            return new M193::M196::M197();
        case 200:
            return new M193::M196::M197::M200();
        case 201:
            return new M193::M196::M197::M200::M201();
        case 198:
            return new M193::M196::M197::M198();
        case 199:
            return new M193::M196::M197::M198::M199();
        case 203:
            return new M193::M196::M197::M203();
        case 204:
            return new M193::M196::M197::M203::M204();
        case 206:
            return new M193::M196::M197::M203::M204::M206();
        case 215:
            return new M193::M196::M197::M203::M204::M206::M215();
        case 207:
            return new M193::M196::M197::M203::M204::M206::M207();
        case 208:
            return new M193::M196::M197::M203::M204::M206::M207::M208();
        case 209:
            return new M193::M196::M197::M203::M204::M206::M207::M208::M209();
        case 210:
            return new M193::M196::M197::M203::M204::M206::M207::M208::M209::M210();
        case 211:
            return new M193::M196::M197::M203::M204::M206::M207::M208::M209::M210::M211();
        case 212:
            return new M193::M196::M197::M203::M204::M206::M207::M208::M209::M210::M211::M212();
        case 213:
            return new M193::M196::M197::M203::M204::M206::M207::M208::M209::M210::M211::M212::M213();
        case 214:
            return new M193::M196::M197::M203::M204::M206::M207::M208::M209::M210::M211::M212::M213::M214();
        case 205:
            return new M193::M196::M197::M203::M204::M205();
        case 202:
            return new M193::M196::M197::M202();
        case 216:
            return new M193::M216();
        case 219:
            return new M193::M216::M219();
        case 220:
            return new M193::M216::M220();
        case 221:
            return new M193::M216::M220::M221();
        case 218:
            return new M193::M216::M218();
        case 217:
            return new M193::M216::M217();
        case 194:
            return new M193::M194();
        case 195:
            return new M193::M194::M195();
        case 222:
            return new M193::M222();
        case 1:
            return new M1();
        case 3:
            return new M1::M3();
        case 8:
            return new M1::M3::M8();
        case 9:
            return new M1::M3::M8::M9();
        case 4:
            return new M1::M3::M4();
        case 5:
            return new M1::M3::M4::M5();
        case 6:
            return new M1::M3::M4::M5::M6();
        case 7:
            return new M1::M3::M4::M7();
        case 15:
            return new M1::M15();
        case 34:
            return new M1::M15::M34();
        case 16:
            return new M1::M15::M16();
        case 17:
            return new M1::M15::M16::M17();
        case 18:
            return new M1::M15::M16::M17::M18();
        case 19:
            return new M1::M15::M16::M17::M18::M19();
        case 21:
            return new M1::M15::M16::M17::M18::M19::M21();
        case 20:
            return new M1::M15::M16::M17::M18::M19::M20();
        case 22:
            return new M1::M15::M16::M17::M22();
        case 23:
            return new M1::M15::M16::M17::M22::M23();
        case 24:
            return new M1::M15::M16::M17::M22::M23::M24();
        case 25:
            return new M1::M15::M16::M17::M22::M23::M24::M25();
        case 26:
            return new M1::M15::M16::M17::M22::M23::M24::M25::M26();
        case 27:
            return new M1::M15::M16::M17::M22::M23::M24::M25::M26::M27();
        case 28:
            return new M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28();
        case 29:
            return new M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29();
        case 30:
            return new M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29::M30();
        case 31:
            return new M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29::M30::M31();
        case 32:
            return new M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29::M30::M32();
        case 33:
            return new M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29::M33();
        case 2:
            return new M1::M2();
        case 10:
            return new M1::M10();
        case 11:
            return new M1::M10::M11();
        case 12:
            return new M1::M10::M12();
        case 13:
            return new M1::M10::M12::M13();
        case 14:
            return new M1::M10::M14();
        case 223:
            return new M223();
        case 230:
            return new M223::M230();
        case 251:
            return new M223::M251();
        case 231:
            return new M223::M231();
        case 232:
            return new M223::M232();
        case 234:
            return new M223::M232::M234();
        case 235:
            return new M223::M232::M234::M235();
        case 236:
            return new M223::M232::M234::M235::M236();
        case 237:
            return new M223::M232::M234::M235::M236::M237();
        case 238:
            return new M223::M232::M234::M235::M236::M237::M238();
        case 239:
            return new M223::M232::M234::M235::M236::M237::M238::M239();
        case 240:
            return new M223::M232::M234::M235::M236::M237::M238::M240();
        case 247:
            return new M223::M232::M234::M235::M236::M237::M238::M240::M247();
        case 241:
            return new M223::M232::M234::M235::M236::M237::M238::M240::M241();
        case 242:
            return new M223::M232::M234::M235::M236::M237::M238::M240::M241::M242();
        case 243:
            return new M223::M232::M234::M235::M236::M237::M238::M240::M241::M242::M243();
        case 244:
            return new M223::M232::M234::M235::M236::M237::M238::M240::M241::M242::M243::M244();
        case 245:
            return new M223::M232::M234::M235::M236::M237::M238::M240::M241::M242::M243::M244::M245();
        case 246:
            return new M223::M232::M234::M235::M236::M237::M238::M240::M241::M242::M243::M244::M245::M246();
        case 248:
            return new M223::M232::M234::M248();
        case 233:
            return new M223::M232::M233();
        case 249:
            return new M223::M232::M249();
        case 250:
            return new M223::M232::M249::M250();
        case 224:
            return new M223::M224();
        case 225:
            return new M223::M224::M225();
        case 226:
            return new M223::M224::M225::M226();
        case 227:
            return new M223::M224::M225::M226::M227();
        case 229:
            return new M223::M224::M225::M226::M227::M229();
        case 228:
            return new M223::M224::M225::M226::M227::M228();
        case 252:
            return new M252();
        case 280:
            return new M252::M280();
        case 258:
            return new M252::M258();
        case 279:
            return new M252::M258::M279();
        case 259:
            return new M252::M258::M259();
        case 260:
            return new M252::M258::M259::M260();
        case 261:
            return new M252::M258::M259::M260::M261();
        case 262:
            return new M252::M258::M259::M260::M261::M262();
        case 263:
            return new M252::M258::M259::M260::M263();
        case 278:
            return new M252::M258::M259::M260::M263::M278();
        case 267:
            return new M252::M258::M259::M260::M263::M267();
        case 268:
            return new M252::M258::M259::M260::M263::M267::M268();
        case 269:
            return new M252::M258::M259::M260::M263::M267::M268::M269();
        case 271:
            return new M252::M258::M259::M260::M263::M267::M268::M269::M271();
        case 272:
            return new M252::M258::M259::M260::M263::M267::M268::M269::M271::M272();
        case 273:
            return new M252::M258::M259::M260::M263::M267::M268::M269::M271::M272::M273();
        case 274:
            return new M252::M258::M259::M260::M263::M267::M268::M269::M271::M272::M273::M274();
        case 275:
            return new M252::M258::M259::M260::M263::M267::M268::M269::M271::M272::M273::M274::M275();
        case 276:
            return new M252::M258::M259::M260::M263::M267::M268::M269::M271::M272::M273::M274::M275::M276();
        case 270:
            return new M252::M258::M259::M260::M263::M267::M268::M269::M270();
        case 277:
            return new M252::M258::M259::M260::M263::M267::M277();
        case 264:
            return new M252::M258::M259::M260::M263::M264();
        case 265:
            return new M252::M258::M259::M260::M263::M264::M265();
        case 266:
            return new M252::M258::M259::M260::M263::M264::M265::M266();
        case 253:
            return new M252::M253();
        case 254:
            return new M252::M253::M254();
        case 255:
            return new M252::M253::M254::M255();
        case 256:
            return new M252::M256();
        case 257:
            return new M252::M256::M257();
        case 281:
            return new M281();
        case 282:
            return new M281::M282();
        case 285:
            return new M281::M282::M285();
        case 286:
            return new M281::M282::M285::M286();
        case 289:
            return new M281::M282::M285::M286::M289();
        case 287:
            return new M281::M282::M285::M286::M287();
        case 288:
            return new M281::M282::M285::M286::M287::M288();
        case 283:
            return new M281::M282::M283();
        case 284:
            return new M281::M282::M283::M284();
        case 292:
            return new M281::M292();
        case 293:
            return new M281::M292::M293();
        case 294:
            return new M281::M292::M293::M294();
        case 295:
            return new M281::M292::M293::M295();
        case 296:
            return new M281::M292::M293::M295::M296();
        case 297:
            return new M281::M292::M293::M295::M297();
        case 298:
            return new M281::M292::M293::M295::M297::M298();
        case 299:
            return new M281::M292::M293::M295::M297::M298::M299();
        case 300:
            return new M281::M292::M293::M295::M297::M300();
        case 301:
            return new M281::M292::M293::M295::M297::M301();
        case 302:
            return new M281::M292::M293::M295::M297::M301::M302();
        case 303:
            return new M281::M292::M293::M295::M297::M301::M302::M303();
        case 304:
            return new M281::M292::M293::M295::M297::M301::M302::M303::M304();
        case 305:
            return new M281::M292::M293::M295::M297::M301::M302::M303::M304::M305();
        case 306:
            return new M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306();
        case 307:
            return new M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306::M307();
        case 308:
            return new M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306::M307::M308();
        case 310:
            return new M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306::M307::M308::M310();
        case 309:
            return new M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306::M307::M308::M309();
        case 290:
            return new M281::M290();
        case 291:
            return new M281::M290::M291();
        case 35:
            return new M35();
        case 63:
            return new M35::M63();
        case 64:
            return new M35::M63::M64();
        case 36:
            return new M35::M36();
        case 43:
            return new M35::M36::M43();
        case 44:
            return new M35::M36::M43::M44();
        case 46:
            return new M35::M36::M46();
        case 47:
            return new M35::M36::M46::M47();
        case 48:
            return new M35::M36::M46::M47::M48();
        case 49:
            return new M35::M36::M46::M47::M49();
        case 50:
            return new M35::M36::M46::M47::M49::M50();
        case 51:
            return new M35::M36::M46::M47::M49::M51();
        case 53:
            return new M35::M36::M46::M47::M49::M51::M53();
        case 54:
            return new M35::M36::M46::M47::M49::M51::M53::M54();
        case 55:
            return new M35::M36::M46::M47::M49::M51::M53::M54::M55();
        case 56:
            return new M35::M36::M46::M47::M49::M51::M53::M54::M56();
        case 57:
            return new M35::M36::M46::M47::M49::M51::M53::M54::M56::M57();
        case 58:
            return new M35::M36::M46::M47::M49::M51::M53::M54::M56::M57::M58();
        case 59:
            return new M35::M36::M46::M47::M49::M51::M53::M54::M56::M57::M58::M59();
        case 60:
            return new M35::M36::M46::M47::M49::M51::M53::M54::M56::M57::M58::M59::M60();
        case 61:
            return new M35::M36::M46::M47::M49::M51::M53::M54::M56::M57::M58::M59::M60::M61();
        case 52:
            return new M35::M36::M46::M47::M49::M51::M52();
        case 62:
            return new M35::M36::M46::M47::M62();
        case 37:
            return new M35::M36::M37();
        case 38:
            return new M35::M36::M37::M38();
        case 40:
            return new M35::M36::M37::M38::M40();
        case 41:
            return new M35::M36::M37::M38::M40::M41();
        case 42:
            return new M35::M36::M37::M38::M40::M41::M42();
        case 39:
            return new M35::M36::M37::M38::M39();
        case 45:
            return new M35::M36::M45();
        case 65:
            return new M35::M65();
        case 66:
            return new M35::M66();
        case 67:
            return new M35::M66::M67();
        case 68:
            return new M68();
        case 70:
            return new M68::M70();
        case 71:
            return new M68::M70::M71();
        case 103:
            return new M68::M103();
        case 100:
            return new M68::M100();
        case 101:
            return new M68::M100::M101();
        case 102:
            return new M68::M100::M101::M102();
        case 69:
            return new M68::M69();
        case 72:
            return new M68::M72();
        case 73:
            return new M68::M72::M73();
        case 74:
            return new M68::M72::M73::M74();
        case 75:
            return new M68::M72::M73::M74::M75();
        case 76:
            return new M68::M72::M76();
        case 77:
            return new M68::M72::M76::M77();
        case 78:
            return new M68::M72::M76::M78();
        case 92:
            return new M68::M72::M76::M78::M92();
        case 93:
            return new M68::M72::M76::M78::M92::M93();
        case 94:
            return new M68::M72::M76::M78::M94();
        case 95:
            return new M68::M72::M76::M78::M94::M95();
        case 96:
            return new M68::M72::M76::M78::M94::M95::M96();
        case 97:
            return new M68::M72::M76::M78::M97();
        case 98:
            return new M68::M72::M76::M78::M97::M98();
        case 91:
            return new M68::M72::M76::M78::M91();
        case 79:
            return new M68::M72::M76::M78::M79();
        case 80:
            return new M68::M72::M76::M78::M79::M80();
        case 81:
            return new M68::M72::M76::M78::M79::M80::M81();
        case 82:
            return new M68::M72::M76::M78::M79::M80::M81::M82();
        case 83:
            return new M68::M72::M76::M78::M79::M80::M81::M83();
        case 84:
            return new M68::M72::M76::M78::M79::M80::M81::M83::M84();
        case 85:
            return new M68::M72::M76::M78::M79::M80::M81::M83::M84::M85();
        case 86:
            return new M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86();
        case 87:
            return new M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86::M87();
        case 90:
            return new M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86::M87::M90();
        case 88:
            return new M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86::M87::M88();
        case 89:
            return new M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86::M87::M88::M89();
        case 99:
            return new M68::M72::M76::M99();
        default:
            throw std::invalid_argument("Invalid class id");
    }
}

size_t getMessageSize(int temp_class_id) {
    switch (temp_class_id) {
        case 104:
            return sizeof(M104);
        case 123:
            return sizeof(M104::M123);
        case 124:
            return sizeof(M104::M123::M124);
        case 127:
            return sizeof(M104::M123::M124::M127);
        case 128:
            return sizeof(M104::M123::M124::M127::M128);
        case 125:
            return sizeof(M104::M123::M124::M125);
        case 126:
            return sizeof(M104::M123::M124::M125::M126);
        case 105:
            return sizeof(M104::M105);
        case 106:
            return sizeof(M104::M105::M106);
        case 107:
            return sizeof(M104::M105::M106::M107);
        case 111:
            return sizeof(M104::M105::M106::M107::M111);
        case 112:
            return sizeof(M104::M105::M106::M107::M111::M112);
        case 113:
            return sizeof(M104::M105::M106::M107::M111::M112::M113);
        case 114:
            return sizeof(M104::M105::M106::M107::M111::M112::M113::M114);
        case 115:
            return sizeof(M104::M105::M106::M107::M111::M112::M113::M114::M115);
        case 116:
            return sizeof(M104::M105::M106::M107::M111::M112::M113::M114::M115::M116);
        case 117:
            return sizeof(M104::M105::M106::M107::M111::M112::M113::M114::M115::M116::M117);
        case 118:
            return sizeof(M104::M105::M106::M107::M111::M112::M113::M114::M115::M116::M117::M118);
        case 119:
            return sizeof(M104::M105::M106::M107::M111::M112::M113::M114::M115::M116::M117::M118::M119);
        case 120:
            return sizeof(M104::M105::M106::M107::M111::M112::M113::M114::M115::M116::M117::M118::M119::M120);
        case 121:
            return sizeof(M104::M105::M106::M107::M111::M112::M121);
        case 108:
            return sizeof(M104::M105::M106::M107::M108);
        case 109:
            return sizeof(M104::M105::M106::M107::M108::M109);
        case 110:
            return sizeof(M104::M105::M106::M107::M108::M109::M110);
        case 122:
            return sizeof(M104::M105::M106::M122);
        case 129:
            return sizeof(M129);
        case 131:
            return sizeof(M129::M131);
        case 132:
            return sizeof(M129::M131::M132);
        case 133:
            return sizeof(M129::M131::M132::M133);
        case 134:
            return sizeof(M129::M131::M132::M133::M134);
        case 135:
            return sizeof(M129::M131::M132::M133::M134::M135);
        case 136:
            return sizeof(M129::M131::M132::M136);
        case 154:
            return sizeof(M129::M131::M132::M136::M154);
        case 137:
            return sizeof(M129::M131::M132::M136::M137);
        case 139:
            return sizeof(M129::M131::M132::M136::M137::M139);
        case 140:
            return sizeof(M129::M131::M132::M136::M137::M139::M140);
        case 151:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M151);
        case 152:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M152);
        case 141:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141);
        case 142:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142);
        case 143:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142::M143);
        case 144:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M144);
        case 145:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M144::M145);
        case 146:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M144::M145::M146);
        case 147:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M147);
        case 148:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M147::M148);
        case 149:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M147::M148::M149);
        case 150:
            return sizeof(M129::M131::M132::M136::M137::M139::M140::M141::M142::M143::M147::M148::M149::M150);
        case 153:
            return sizeof(M129::M131::M132::M136::M137::M139::M153);
        case 138:
            return sizeof(M129::M131::M132::M136::M137::M138);
        case 155:
            return sizeof(M129::M131::M132::M136::M155);
        case 156:
            return sizeof(M129::M131::M132::M136::M156);
        case 157:
            return sizeof(M129::M157);
        case 158:
            return sizeof(M129::M157::M158);
        case 159:
            return sizeof(M129::M157::M159);
        case 160:
            return sizeof(M129::M160);
        case 161:
            return sizeof(M129::M160::M161);
        case 162:
            return sizeof(M129::M160::M162);
        case 130:
            return sizeof(M129::M130);
        case 163:
            return sizeof(M163);
        case 187:
            return sizeof(M163::M187);
        case 188:
            return sizeof(M163::M187::M188);
        case 189:
            return sizeof(M163::M187::M189);
        case 190:
            return sizeof(M163::M187::M189::M190);
        case 191:
            return sizeof(M163::M187::M189::M190::M191);
        case 192:
            return sizeof(M163::M187::M189::M190::M191::M192);
        case 164:
            return sizeof(M163::M164);
        case 165:
            return sizeof(M163::M164::M165);
        case 166:
            return sizeof(M163::M164::M165::M166);
        case 167:
            return sizeof(M163::M164::M165::M166::M167);
        case 168:
            return sizeof(M163::M164::M165::M166::M167::M168);
        case 169:
            return sizeof(M163::M164::M165::M166::M167::M168::M169);
        case 171:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M171);
        case 170:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M170);
        case 172:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172);
        case 174:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M174);
        case 175:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M174::M175);
        case 176:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176);
        case 178:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M178);
        case 179:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M178::M179);
        case 181:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M178::M179::M181);
        case 180:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M178::M179::M180);
        case 177:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M174::M175::M176::M177);
        case 173:
            return sizeof(M163::M164::M165::M166::M167::M168::M169::M172::M173);
        case 182:
            return sizeof(M163::M164::M165::M166::M167::M182);
        case 183:
            return sizeof(M163::M164::M183);
        case 185:
            return sizeof(M163::M164::M183::M185);
        case 184:
            return sizeof(M163::M164::M183::M184);
        case 186:
            return sizeof(M163::M164::M183::M186);
        case 193:
            return sizeof(M193);
        case 196:
            return sizeof(M193::M196);
        case 197:
            return sizeof(M193::M196::M197);
        case 200:
            return sizeof(M193::M196::M197::M200);
        case 201:
            return sizeof(M193::M196::M197::M200::M201);
        case 198:
            return sizeof(M193::M196::M197::M198);
        case 199:
            return sizeof(M193::M196::M197::M198::M199);
        case 203:
            return sizeof(M193::M196::M197::M203);
        case 204:
            return sizeof(M193::M196::M197::M203::M204);
        case 206:
            return sizeof(M193::M196::M197::M203::M204::M206);
        case 215:
            return sizeof(M193::M196::M197::M203::M204::M206::M215);
        case 207:
            return sizeof(M193::M196::M197::M203::M204::M206::M207);
        case 208:
            return sizeof(M193::M196::M197::M203::M204::M206::M207::M208);
        case 209:
            return sizeof(M193::M196::M197::M203::M204::M206::M207::M208::M209);
        case 210:
            return sizeof(M193::M196::M197::M203::M204::M206::M207::M208::M209::M210);
        case 211:
            return sizeof(M193::M196::M197::M203::M204::M206::M207::M208::M209::M210::M211);
        case 212:
            return sizeof(M193::M196::M197::M203::M204::M206::M207::M208::M209::M210::M211::M212);
        case 213:
            return sizeof(M193::M196::M197::M203::M204::M206::M207::M208::M209::M210::M211::M212::M213);
        case 214:
            return sizeof(M193::M196::M197::M203::M204::M206::M207::M208::M209::M210::M211::M212::M213::M214);
        case 205:
            return sizeof(M193::M196::M197::M203::M204::M205);
        case 202:
            return sizeof(M193::M196::M197::M202);
        case 216:
            return sizeof(M193::M216);
        case 219:
            return sizeof(M193::M216::M219);
        case 220:
            return sizeof(M193::M216::M220);
        case 221:
            return sizeof(M193::M216::M220::M221);
        case 218:
            return sizeof(M193::M216::M218);
        case 217:
            return sizeof(M193::M216::M217);
        case 194:
            return sizeof(M193::M194);
        case 195:
            return sizeof(M193::M194::M195);
        case 222:
            return sizeof(M193::M222);
        case 1:
            return sizeof(M1);
        case 3:
            return sizeof(M1::M3);
        case 8:
            return sizeof(M1::M3::M8);
        case 9:
            return sizeof(M1::M3::M8::M9);
        case 4:
            return sizeof(M1::M3::M4);
        case 5:
            return sizeof(M1::M3::M4::M5);
        case 6:
            return sizeof(M1::M3::M4::M5::M6);
        case 7:
            return sizeof(M1::M3::M4::M7);
        case 15:
            return sizeof(M1::M15);
        case 34:
            return sizeof(M1::M15::M34);
        case 16:
            return sizeof(M1::M15::M16);
        case 17:
            return sizeof(M1::M15::M16::M17);
        case 18:
            return sizeof(M1::M15::M16::M17::M18);
        case 19:
            return sizeof(M1::M15::M16::M17::M18::M19);
        case 21:
            return sizeof(M1::M15::M16::M17::M18::M19::M21);
        case 20:
            return sizeof(M1::M15::M16::M17::M18::M19::M20);
        case 22:
            return sizeof(M1::M15::M16::M17::M22);
        case 23:
            return sizeof(M1::M15::M16::M17::M22::M23);
        case 24:
            return sizeof(M1::M15::M16::M17::M22::M23::M24);
        case 25:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25);
        case 26:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25::M26);
        case 27:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25::M26::M27);
        case 28:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28);
        case 29:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29);
        case 30:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29::M30);
        case 31:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29::M30::M31);
        case 32:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29::M30::M32);
        case 33:
            return sizeof(M1::M15::M16::M17::M22::M23::M24::M25::M26::M27::M28::M29::M33);
        case 2:
            return sizeof(M1::M2);
        case 10:
            return sizeof(M1::M10);
        case 11:
            return sizeof(M1::M10::M11);
        case 12:
            return sizeof(M1::M10::M12);
        case 13:
            return sizeof(M1::M10::M12::M13);
        case 14:
            return sizeof(M1::M10::M14);
        case 223:
            return sizeof(M223);
        case 230:
            return sizeof(M223::M230);
        case 251:
            return sizeof(M223::M251);
        case 231:
            return sizeof(M223::M231);
        case 232:
            return sizeof(M223::M232);
        case 234:
            return sizeof(M223::M232::M234);
        case 235:
            return sizeof(M223::M232::M234::M235);
        case 236:
            return sizeof(M223::M232::M234::M235::M236);
        case 237:
            return sizeof(M223::M232::M234::M235::M236::M237);
        case 238:
            return sizeof(M223::M232::M234::M235::M236::M237::M238);
        case 239:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M239);
        case 240:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M240);
        case 247:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M240::M247);
        case 241:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M240::M241);
        case 242:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M240::M241::M242);
        case 243:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M240::M241::M242::M243);
        case 244:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M240::M241::M242::M243::M244);
        case 245:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M240::M241::M242::M243::M244::M245);
        case 246:
            return sizeof(M223::M232::M234::M235::M236::M237::M238::M240::M241::M242::M243::M244::M245::M246);
        case 248:
            return sizeof(M223::M232::M234::M248);
        case 233:
            return sizeof(M223::M232::M233);
        case 249:
            return sizeof(M223::M232::M249);
        case 250:
            return sizeof(M223::M232::M249::M250);
        case 224:
            return sizeof(M223::M224);
        case 225:
            return sizeof(M223::M224::M225);
        case 226:
            return sizeof(M223::M224::M225::M226);
        case 227:
            return sizeof(M223::M224::M225::M226::M227);
        case 229:
            return sizeof(M223::M224::M225::M226::M227::M229);
        case 228:
            return sizeof(M223::M224::M225::M226::M227::M228);
        case 252:
            return sizeof(M252);
        case 280:
            return sizeof(M252::M280);
        case 258:
            return sizeof(M252::M258);
        case 279:
            return sizeof(M252::M258::M279);
        case 259:
            return sizeof(M252::M258::M259);
        case 260:
            return sizeof(M252::M258::M259::M260);
        case 261:
            return sizeof(M252::M258::M259::M260::M261);
        case 262:
            return sizeof(M252::M258::M259::M260::M261::M262);
        case 263:
            return sizeof(M252::M258::M259::M260::M263);
        case 278:
            return sizeof(M252::M258::M259::M260::M263::M278);
        case 267:
            return sizeof(M252::M258::M259::M260::M263::M267);
        case 268:
            return sizeof(M252::M258::M259::M260::M263::M267::M268);
        case 269:
            return sizeof(M252::M258::M259::M260::M263::M267::M268::M269);
        case 271:
            return sizeof(M252::M258::M259::M260::M263::M267::M268::M269::M271);
        case 272:
            return sizeof(M252::M258::M259::M260::M263::M267::M268::M269::M271::M272);
        case 273:
            return sizeof(M252::M258::M259::M260::M263::M267::M268::M269::M271::M272::M273);
        case 274:
            return sizeof(M252::M258::M259::M260::M263::M267::M268::M269::M271::M272::M273::M274);
        case 275:
            return sizeof(M252::M258::M259::M260::M263::M267::M268::M269::M271::M272::M273::M274::M275);
        case 276:
            return sizeof(M252::M258::M259::M260::M263::M267::M268::M269::M271::M272::M273::M274::M275::M276);
        case 270:
            return sizeof(M252::M258::M259::M260::M263::M267::M268::M269::M270);
        case 277:
            return sizeof(M252::M258::M259::M260::M263::M267::M277);
        case 264:
            return sizeof(M252::M258::M259::M260::M263::M264);
        case 265:
            return sizeof(M252::M258::M259::M260::M263::M264::M265);
        case 266:
            return sizeof(M252::M258::M259::M260::M263::M264::M265::M266);
        case 253:
            return sizeof(M252::M253);
        case 254:
            return sizeof(M252::M253::M254);
        case 255:
            return sizeof(M252::M253::M254::M255);
        case 256:
            return sizeof(M252::M256);
        case 257:
            return sizeof(M252::M256::M257);
        case 281:
            return sizeof(M281);
        case 282:
            return sizeof(M281::M282);
        case 285:
            return sizeof(M281::M282::M285);
        case 286:
            return sizeof(M281::M282::M285::M286);
        case 289:
            return sizeof(M281::M282::M285::M286::M289);
        case 287:
            return sizeof(M281::M282::M285::M286::M287);
        case 288:
            return sizeof(M281::M282::M285::M286::M287::M288);
        case 283:
            return sizeof(M281::M282::M283);
        case 284:
            return sizeof(M281::M282::M283::M284);
        case 292:
            return sizeof(M281::M292);
        case 293:
            return sizeof(M281::M292::M293);
        case 294:
            return sizeof(M281::M292::M293::M294);
        case 295:
            return sizeof(M281::M292::M293::M295);
        case 296:
            return sizeof(M281::M292::M293::M295::M296);
        case 297:
            return sizeof(M281::M292::M293::M295::M297);
        case 298:
            return sizeof(M281::M292::M293::M295::M297::M298);
        case 299:
            return sizeof(M281::M292::M293::M295::M297::M298::M299);
        case 300:
            return sizeof(M281::M292::M293::M295::M297::M300);
        case 301:
            return sizeof(M281::M292::M293::M295::M297::M301);
        case 302:
            return sizeof(M281::M292::M293::M295::M297::M301::M302);
        case 303:
            return sizeof(M281::M292::M293::M295::M297::M301::M302::M303);
        case 304:
            return sizeof(M281::M292::M293::M295::M297::M301::M302::M303::M304);
        case 305:
            return sizeof(M281::M292::M293::M295::M297::M301::M302::M303::M304::M305);
        case 306:
            return sizeof(M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306);
        case 307:
            return sizeof(M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306::M307);
        case 308:
            return sizeof(M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306::M307::M308);
        case 310:
            return sizeof(M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306::M307::M308::M310);
        case 309:
            return sizeof(M281::M292::M293::M295::M297::M301::M302::M303::M304::M305::M306::M307::M308::M309);
        case 290:
            return sizeof(M281::M290);
        case 291:
            return sizeof(M281::M290::M291);
        case 35:
            return sizeof(M35);
        case 63:
            return sizeof(M35::M63);
        case 64:
            return sizeof(M35::M63::M64);
        case 36:
            return sizeof(M35::M36);
        case 43:
            return sizeof(M35::M36::M43);
        case 44:
            return sizeof(M35::M36::M43::M44);
        case 46:
            return sizeof(M35::M36::M46);
        case 47:
            return sizeof(M35::M36::M46::M47);
        case 48:
            return sizeof(M35::M36::M46::M47::M48);
        case 49:
            return sizeof(M35::M36::M46::M47::M49);
        case 50:
            return sizeof(M35::M36::M46::M47::M49::M50);
        case 51:
            return sizeof(M35::M36::M46::M47::M49::M51);
        case 53:
            return sizeof(M35::M36::M46::M47::M49::M51::M53);
        case 54:
            return sizeof(M35::M36::M46::M47::M49::M51::M53::M54);
        case 55:
            return sizeof(M35::M36::M46::M47::M49::M51::M53::M54::M55);
        case 56:
            return sizeof(M35::M36::M46::M47::M49::M51::M53::M54::M56);
        case 57:
            return sizeof(M35::M36::M46::M47::M49::M51::M53::M54::M56::M57);
        case 58:
            return sizeof(M35::M36::M46::M47::M49::M51::M53::M54::M56::M57::M58);
        case 59:
            return sizeof(M35::M36::M46::M47::M49::M51::M53::M54::M56::M57::M58::M59);
        case 60:
            return sizeof(M35::M36::M46::M47::M49::M51::M53::M54::M56::M57::M58::M59::M60);
        case 61:
            return sizeof(M35::M36::M46::M47::M49::M51::M53::M54::M56::M57::M58::M59::M60::M61);
        case 52:
            return sizeof(M35::M36::M46::M47::M49::M51::M52);
        case 62:
            return sizeof(M35::M36::M46::M47::M62);
        case 37:
            return sizeof(M35::M36::M37);
        case 38:
            return sizeof(M35::M36::M37::M38);
        case 40:
            return sizeof(M35::M36::M37::M38::M40);
        case 41:
            return sizeof(M35::M36::M37::M38::M40::M41);
        case 42:
            return sizeof(M35::M36::M37::M38::M40::M41::M42);
        case 39:
            return sizeof(M35::M36::M37::M38::M39);
        case 45:
            return sizeof(M35::M36::M45);
        case 65:
            return sizeof(M35::M65);
        case 66:
            return sizeof(M35::M66);
        case 67:
            return sizeof(M35::M66::M67);
        case 68:
            return sizeof(M68);
        case 70:
            return sizeof(M68::M70);
        case 71:
            return sizeof(M68::M70::M71);
        case 103:
            return sizeof(M68::M103);
        case 100:
            return sizeof(M68::M100);
        case 101:
            return sizeof(M68::M100::M101);
        case 102:
            return sizeof(M68::M100::M101::M102);
        case 69:
            return sizeof(M68::M69);
        case 72:
            return sizeof(M68::M72);
        case 73:
            return sizeof(M68::M72::M73);
        case 74:
            return sizeof(M68::M72::M73::M74);
        case 75:
            return sizeof(M68::M72::M73::M74::M75);
        case 76:
            return sizeof(M68::M72::M76);
        case 77:
            return sizeof(M68::M72::M76::M77);
        case 78:
            return sizeof(M68::M72::M76::M78);
        case 92:
            return sizeof(M68::M72::M76::M78::M92);
        case 93:
            return sizeof(M68::M72::M76::M78::M92::M93);
        case 94:
            return sizeof(M68::M72::M76::M78::M94);
        case 95:
            return sizeof(M68::M72::M76::M78::M94::M95);
        case 96:
            return sizeof(M68::M72::M76::M78::M94::M95::M96);
        case 97:
            return sizeof(M68::M72::M76::M78::M97);
        case 98:
            return sizeof(M68::M72::M76::M78::M97::M98);
        case 91:
            return sizeof(M68::M72::M76::M78::M91);
        case 79:
            return sizeof(M68::M72::M76::M78::M79);
        case 80:
            return sizeof(M68::M72::M76::M78::M79::M80);
        case 81:
            return sizeof(M68::M72::M76::M78::M79::M80::M81);
        case 82:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M82);
        case 83:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M83);
        case 84:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M83::M84);
        case 85:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M83::M84::M85);
        case 86:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86);
        case 87:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86::M87);
        case 90:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86::M87::M90);
        case 88:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86::M87::M88);
        case 89:
            return sizeof(M68::M72::M76::M78::M79::M80::M81::M83::M84::M85::M86::M87::M88::M89);
        case 99:
            return sizeof(M68::M72::M76::M99);
        default:
            return 0;
    }
}
