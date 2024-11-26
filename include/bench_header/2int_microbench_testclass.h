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

    inline void print_message(std::ofstream &fout){
        fout << "M1->f1: " << f1 << std::endl;
        fout << "M1->f2: " << f2 << std::endl;
    }

    ~M1(){
    }

    M1(){
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
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
    
        inline void print_message(std::ofstream &fout){
            fout << "M3->f1: " << f1 << std::endl;
            fout << "M3->f2: " << f2 << std::endl;
        }
    
        ~M3(){
        }
    
        M3(){
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
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

    inline M3* mutable_f3(){
        f3 = new M3();
        return f3;
    }
    inline M3*& get_f3(){
        return f3;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M2->f1: " << f1 << std::endl;
        fout << "M2->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
    }

    ~M2(){
        if(f3 != nullptr)
            delete f3;
    }

    M2(){
       f3 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) M3* f3;
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
            
                inline void print_message(std::ofstream &fout){
                    fout << "M7->f1: " << f1 << std::endl;
                    fout << "M7->f2: " << f2 << std::endl;
                }
            
                ~M7(){
                }
            
                M7(){
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) int64_t f2;
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
        
            inline M7* mutable_f3(){
                f3 = new M7();
                return f3;
            }
            inline M7*& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M6->f1: " << f1 << std::endl;
                fout << "M6->f2: " << f2 << std::endl;
                if(f3 != nullptr)
                    f3->print_message(fout);
            }
        
            ~M6(){
                if(f3 != nullptr)
                    delete f3;
            }
        
            M6(){
               f3 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int64_t f2;
            alignas(8) M7* f3;
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
    
        inline M6* mutable_f3(){
            f3 = new M6();
            return f3;
        }
        inline M6*& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M5->f1: " << f1 << std::endl;
            fout << "M5->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M5(){
            if(f3 != nullptr)
                delete f3;
        }
    
        M5(){
           f3 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
        alignas(8) M6* f3;
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

    inline M5* mutable_f3(){
        f3 = new M5();
        return f3;
    }
    inline M5*& get_f3(){
        return f3;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M4->f1: " << f1 << std::endl;
        fout << "M4->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
    }

    ~M4(){
        if(f3 != nullptr)
            delete f3;
    }

    M4(){
       f3 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) M5* f3;
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
                            
                                inline void print_message(std::ofstream &fout){
                                    fout << "M15->f1: " << f1 << std::endl;
                                    fout << "M15->f2: " << f2 << std::endl;
                                }
                            
                                ~M15(){
                                }
                            
                                M15(){
                                }
                            
                            private:
                                alignas(8) int64_t f1;
                                alignas(8) int64_t f2;
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
                        
                            inline M15* mutable_f3(){
                                f3 = new M15();
                                return f3;
                            }
                            inline M15*& get_f3(){
                                return f3;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M14->f1: " << f1 << std::endl;
                                fout << "M14->f2: " << f2 << std::endl;
                                if(f3 != nullptr)
                                    f3->print_message(fout);
                            }
                        
                            ~M14(){
                                if(f3 != nullptr)
                                    delete f3;
                            }
                        
                            M14(){
                               f3 = nullptr;
                            }
                        
                        private:
                            alignas(8) int64_t f1;
                            alignas(8) int64_t f2;
                            alignas(8) M15* f3;
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
                    
                        inline M14* mutable_f3(){
                            f3 = new M14();
                            return f3;
                        }
                        inline M14*& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M13->f1: " << f1 << std::endl;
                            fout << "M13->f2: " << f2 << std::endl;
                            if(f3 != nullptr)
                                f3->print_message(fout);
                        }
                    
                        ~M13(){
                            if(f3 != nullptr)
                                delete f3;
                        }
                    
                        M13(){
                           f3 = nullptr;
                        }
                    
                    private:
                        alignas(8) int64_t f1;
                        alignas(8) int64_t f2;
                        alignas(8) M14* f3;
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
                
                    inline M13* mutable_f3(){
                        f3 = new M13();
                        return f3;
                    }
                    inline M13*& get_f3(){
                        return f3;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M12->f1: " << f1 << std::endl;
                        fout << "M12->f2: " << f2 << std::endl;
                        if(f3 != nullptr)
                            f3->print_message(fout);
                    }
                
                    ~M12(){
                        if(f3 != nullptr)
                            delete f3;
                    }
                
                    M12(){
                       f3 = nullptr;
                    }
                
                private:
                    alignas(8) int64_t f1;
                    alignas(8) int64_t f2;
                    alignas(8) M13* f3;
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
            
                inline M12* mutable_f3(){
                    f3 = new M12();
                    return f3;
                }
                inline M12*& get_f3(){
                    return f3;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M11->f1: " << f1 << std::endl;
                    fout << "M11->f2: " << f2 << std::endl;
                    if(f3 != nullptr)
                        f3->print_message(fout);
                }
            
                ~M11(){
                    if(f3 != nullptr)
                        delete f3;
                }
            
                M11(){
                   f3 = nullptr;
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) int64_t f2;
                alignas(8) M12* f3;
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
        
            inline M11* mutable_f3(){
                f3 = new M11();
                return f3;
            }
            inline M11*& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M10->f1: " << f1 << std::endl;
                fout << "M10->f2: " << f2 << std::endl;
                if(f3 != nullptr)
                    f3->print_message(fout);
            }
        
            ~M10(){
                if(f3 != nullptr)
                    delete f3;
            }
        
            M10(){
               f3 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int64_t f2;
            alignas(8) M11* f3;
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
    
        inline M10* mutable_f3(){
            f3 = new M10();
            return f3;
        }
        inline M10*& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M9->f1: " << f1 << std::endl;
            fout << "M9->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M9(){
            if(f3 != nullptr)
                delete f3;
        }
    
        M9(){
           f3 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
        alignas(8) M10* f3;
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

    inline M9* mutable_f3(){
        f3 = new M9();
        return f3;
    }
    inline M9*& get_f3(){
        return f3;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M8->f1: " << f1 << std::endl;
        fout << "M8->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
    }

    ~M8(){
        if(f3 != nullptr)
            delete f3;
    }

    M8(){
       f3 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) M9* f3;
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
                                                            
                                                                inline void print_message(std::ofstream &fout){
                                                                    fout << "M31->f1: " << f1 << std::endl;
                                                                    fout << "M31->f2: " << f2 << std::endl;
                                                                }
                                                            
                                                                ~M31(){
                                                                }
                                                            
                                                                M31(){
                                                                }
                                                            
                                                            private:
                                                                alignas(8) int64_t f1;
                                                                alignas(8) int64_t f2;
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
                                                        
                                                            inline M31* mutable_f3(){
                                                                f3 = new M31();
                                                                return f3;
                                                            }
                                                            inline M31*& get_f3(){
                                                                return f3;
                                                            }
                                                        
                                                            inline void print_message(std::ofstream &fout){
                                                                fout << "M30->f1: " << f1 << std::endl;
                                                                fout << "M30->f2: " << f2 << std::endl;
                                                                if(f3 != nullptr)
                                                                    f3->print_message(fout);
                                                            }
                                                        
                                                            ~M30(){
                                                                if(f3 != nullptr)
                                                                    delete f3;
                                                            }
                                                        
                                                            M30(){
                                                               f3 = nullptr;
                                                            }
                                                        
                                                        private:
                                                            alignas(8) int64_t f1;
                                                            alignas(8) int64_t f2;
                                                            alignas(8) M31* f3;
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
                                                    
                                                        inline M30* mutable_f3(){
                                                            f3 = new M30();
                                                            return f3;
                                                        }
                                                        inline M30*& get_f3(){
                                                            return f3;
                                                        }
                                                    
                                                        inline void print_message(std::ofstream &fout){
                                                            fout << "M29->f1: " << f1 << std::endl;
                                                            fout << "M29->f2: " << f2 << std::endl;
                                                            if(f3 != nullptr)
                                                                f3->print_message(fout);
                                                        }
                                                    
                                                        ~M29(){
                                                            if(f3 != nullptr)
                                                                delete f3;
                                                        }
                                                    
                                                        M29(){
                                                           f3 = nullptr;
                                                        }
                                                    
                                                    private:
                                                        alignas(8) int64_t f1;
                                                        alignas(8) int64_t f2;
                                                        alignas(8) M30* f3;
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
                                                
                                                    inline M29* mutable_f3(){
                                                        f3 = new M29();
                                                        return f3;
                                                    }
                                                    inline M29*& get_f3(){
                                                        return f3;
                                                    }
                                                
                                                    inline void print_message(std::ofstream &fout){
                                                        fout << "M28->f1: " << f1 << std::endl;
                                                        fout << "M28->f2: " << f2 << std::endl;
                                                        if(f3 != nullptr)
                                                            f3->print_message(fout);
                                                    }
                                                
                                                    ~M28(){
                                                        if(f3 != nullptr)
                                                            delete f3;
                                                    }
                                                
                                                    M28(){
                                                       f3 = nullptr;
                                                    }
                                                
                                                private:
                                                    alignas(8) int64_t f1;
                                                    alignas(8) int64_t f2;
                                                    alignas(8) M29* f3;
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
                                            
                                                inline M28* mutable_f3(){
                                                    f3 = new M28();
                                                    return f3;
                                                }
                                                inline M28*& get_f3(){
                                                    return f3;
                                                }
                                            
                                                inline void print_message(std::ofstream &fout){
                                                    fout << "M27->f1: " << f1 << std::endl;
                                                    fout << "M27->f2: " << f2 << std::endl;
                                                    if(f3 != nullptr)
                                                        f3->print_message(fout);
                                                }
                                            
                                                ~M27(){
                                                    if(f3 != nullptr)
                                                        delete f3;
                                                }
                                            
                                                M27(){
                                                   f3 = nullptr;
                                                }
                                            
                                            private:
                                                alignas(8) int64_t f1;
                                                alignas(8) int64_t f2;
                                                alignas(8) M28* f3;
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
                                            alignas(8) int64_t f2;
                                            alignas(8) M27* f3;
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
                                    
                                        inline M26* mutable_f3(){
                                            f3 = new M26();
                                            return f3;
                                        }
                                        inline M26*& get_f3(){
                                            return f3;
                                        }
                                    
                                        inline void print_message(std::ofstream &fout){
                                            fout << "M25->f1: " << f1 << std::endl;
                                            fout << "M25->f2: " << f2 << std::endl;
                                            if(f3 != nullptr)
                                                f3->print_message(fout);
                                        }
                                    
                                        ~M25(){
                                            if(f3 != nullptr)
                                                delete f3;
                                        }
                                    
                                        M25(){
                                           f3 = nullptr;
                                        }
                                    
                                    private:
                                        alignas(8) int64_t f1;
                                        alignas(8) int64_t f2;
                                        alignas(8) M26* f3;
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
                                
                                    inline M25* mutable_f3(){
                                        f3 = new M25();
                                        return f3;
                                    }
                                    inline M25*& get_f3(){
                                        return f3;
                                    }
                                
                                    inline void print_message(std::ofstream &fout){
                                        fout << "M24->f1: " << f1 << std::endl;
                                        fout << "M24->f2: " << f2 << std::endl;
                                        if(f3 != nullptr)
                                            f3->print_message(fout);
                                    }
                                
                                    ~M24(){
                                        if(f3 != nullptr)
                                            delete f3;
                                    }
                                
                                    M24(){
                                       f3 = nullptr;
                                    }
                                
                                private:
                                    alignas(8) int64_t f1;
                                    alignas(8) int64_t f2;
                                    alignas(8) M25* f3;
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
                                alignas(8) int64_t f1;
                                alignas(8) int64_t f2;
                                alignas(8) M24* f3;
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
                        
                            inline M23* mutable_f3(){
                                f3 = new M23();
                                return f3;
                            }
                            inline M23*& get_f3(){
                                return f3;
                            }
                        
                            inline void print_message(std::ofstream &fout){
                                fout << "M22->f1: " << f1 << std::endl;
                                fout << "M22->f2: " << f2 << std::endl;
                                if(f3 != nullptr)
                                    f3->print_message(fout);
                            }
                        
                            ~M22(){
                                if(f3 != nullptr)
                                    delete f3;
                            }
                        
                            M22(){
                               f3 = nullptr;
                            }
                        
                        private:
                            alignas(8) int64_t f1;
                            alignas(8) int64_t f2;
                            alignas(8) M23* f3;
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
                    
                        inline M22* mutable_f3(){
                            f3 = new M22();
                            return f3;
                        }
                        inline M22*& get_f3(){
                            return f3;
                        }
                    
                        inline void print_message(std::ofstream &fout){
                            fout << "M21->f1: " << f1 << std::endl;
                            fout << "M21->f2: " << f2 << std::endl;
                            if(f3 != nullptr)
                                f3->print_message(fout);
                        }
                    
                        ~M21(){
                            if(f3 != nullptr)
                                delete f3;
                        }
                    
                        M21(){
                           f3 = nullptr;
                        }
                    
                    private:
                        alignas(8) int64_t f1;
                        alignas(8) int64_t f2;
                        alignas(8) M22* f3;
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
                
                    inline M21* mutable_f3(){
                        f3 = new M21();
                        return f3;
                    }
                    inline M21*& get_f3(){
                        return f3;
                    }
                
                    inline void print_message(std::ofstream &fout){
                        fout << "M20->f1: " << f1 << std::endl;
                        fout << "M20->f2: " << f2 << std::endl;
                        if(f3 != nullptr)
                            f3->print_message(fout);
                    }
                
                    ~M20(){
                        if(f3 != nullptr)
                            delete f3;
                    }
                
                    M20(){
                       f3 = nullptr;
                    }
                
                private:
                    alignas(8) int64_t f1;
                    alignas(8) int64_t f2;
                    alignas(8) M21* f3;
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
            
                inline M20* mutable_f3(){
                    f3 = new M20();
                    return f3;
                }
                inline M20*& get_f3(){
                    return f3;
                }
            
                inline void print_message(std::ofstream &fout){
                    fout << "M19->f1: " << f1 << std::endl;
                    fout << "M19->f2: " << f2 << std::endl;
                    if(f3 != nullptr)
                        f3->print_message(fout);
                }
            
                ~M19(){
                    if(f3 != nullptr)
                        delete f3;
                }
            
                M19(){
                   f3 = nullptr;
                }
            
            private:
                alignas(8) int64_t f1;
                alignas(8) int64_t f2;
                alignas(8) M20* f3;
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
        
            inline M19* mutable_f3(){
                f3 = new M19();
                return f3;
            }
            inline M19*& get_f3(){
                return f3;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M18->f1: " << f1 << std::endl;
                fout << "M18->f2: " << f2 << std::endl;
                if(f3 != nullptr)
                    f3->print_message(fout);
            }
        
            ~M18(){
                if(f3 != nullptr)
                    delete f3;
            }
        
            M18(){
               f3 = nullptr;
            }
        
        private:
            alignas(8) int64_t f1;
            alignas(8) int64_t f2;
            alignas(8) M19* f3;
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
    
        inline M18* mutable_f3(){
            f3 = new M18();
            return f3;
        }
        inline M18*& get_f3(){
            return f3;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M17->f1: " << f1 << std::endl;
            fout << "M17->f2: " << f2 << std::endl;
            if(f3 != nullptr)
                f3->print_message(fout);
        }
    
        ~M17(){
            if(f3 != nullptr)
                delete f3;
        }
    
        M17(){
           f3 = nullptr;
        }
    
    private:
        alignas(8) int64_t f1;
        alignas(8) int64_t f2;
        alignas(8) M18* f3;
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

    inline M17* mutable_f3(){
        f3 = new M17();
        return f3;
    }
    inline M17*& get_f3(){
        return f3;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M16->f1: " << f1 << std::endl;
        fout << "M16->f2: " << f2 << std::endl;
        if(f3 != nullptr)
            f3->print_message(fout);
    }

    ~M16(){
        if(f3 != nullptr)
            delete f3;
    }

    M16(){
       f3 = nullptr;
    }

private:
    alignas(8) int64_t f1;
    alignas(8) int64_t f2;
    alignas(8) M17* f3;
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


