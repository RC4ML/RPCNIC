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
    inline void set_req_id(int64_t val){
        req_id = val;
    }
    inline int64_t& get_req_id(){
        return req_id;
    }

    inline void set_first_name(string val){
        first_name = val;
    }
    inline string& get_first_name(){
        return first_name;
    }

    inline void set_last_name(string val){
        last_name = val;
    }
    inline string& get_last_name(){
        return last_name;
    }

    inline void set_username(string val){
        username = val;
    }
    inline string& get_username(){
        return username;
    }

    inline void set_password(string val){
        password = val;
    }
    inline string& get_password(){
        return password;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M1->req_id: " << req_id << std::endl;
        fout << "M1->first_name: " << first_name << std::endl;
        fout << "M1->last_name: " << last_name << std::endl;
        fout << "M1->username: " << username << std::endl;
        fout << "M1->password: " << password << std::endl;
    }

    ~M1(){
    }

    M1(){
    }

private:
    alignas(8) int64_t req_id;
    alignas(8) string first_name;
    alignas(8) string last_name;
    alignas(8) string username;
    alignas(8) string password;
};


class alignas(8) M2 : public M_base
{
public:
    inline void set_req_id(int64_t val){
        req_id = val;
    }
    inline int64_t& get_req_id(){
        return req_id;
    }

    inline void set_username(string val){
        username = val;
    }
    inline string& get_username(){
        return username;
    }

    inline void set_password(string val){
        password = val;
    }
    inline string& get_password(){
        return password;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M2->req_id: " << req_id << std::endl;
        fout << "M2->username: " << username << std::endl;
        fout << "M2->password: " << password << std::endl;
    }

    ~M2(){
    }

    M2(){
    }

private:
    alignas(8) int64_t req_id;
    alignas(8) string username;
    alignas(8) string password;
};


class alignas(8) M3 : public M_base
{
public:
    inline void set_media_id(int64_t val){
        media_id = val;
    }
    inline int64_t& get_media_id(){
        return media_id;
    }

    inline void set_media_type(string val){
        media_type = val;
    }
    inline string& get_media_type(){
        return media_type;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M3->media_id: " << media_id << std::endl;
        fout << "M3->media_type: " << media_type << std::endl;
    }

    ~M3(){
    }

    M3(){
    }

private:
    alignas(8) int64_t media_id;
    alignas(8) string media_type;
};


class alignas(8) M4 : public M_base
{
public:
    inline void set_req_id(int64_t val){
        req_id = val;
    }
    inline int64_t& get_req_id(){
        return req_id;
    }

    inline M3* mutable_medias(){
        medias = new M3();
        return medias;
    }
    inline M3*& get_medias(){
        return medias;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M4->req_id: " << req_id << std::endl;
        if(medias != nullptr)
            medias->print_message(fout);
    }

    ~M4(){
        if(medias != nullptr)
            delete medias;
    }

    M4(){
       medias = nullptr;
    }

private:
    alignas(8) int64_t req_id;
    alignas(8) M3* medias;
};


class alignas(8) M5 : public M_base
{
public:
    enum E1 {
        POST = 0,
        REPOST = 1,
        REPLY = 2,
        DM = 3,
    };
    
    inline void set_req_id(int64_t val){
        req_id = val;
    }
    inline int64_t& get_req_id(){
        return req_id;
    }

    inline void set_username(string val){
        username = val;
    }
    inline string& get_username(){
        return username;
    }

    inline void set_user_id(int64_t val){
        user_id = val;
    }
    inline int64_t& get_user_id(){
        return user_id;
    }

    inline void set_text(string val){
        text = val;
    }
    inline string& get_text(){
        return text;
    }

    inline M3* mutable_medias(){
        medias = new M3();
        return medias;
    }
    inline M3*& get_medias(){
        return medias;
    }

    inline void set_post_type(E1 val){
        post_type = val;
    }
    inline E1& get_post_type(){
        return post_type;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M5->req_id: " << req_id << std::endl;
        fout << "M5->username: " << username << std::endl;
        fout << "M5->user_id: " << user_id << std::endl;
        fout << "M5->text: " << text << std::endl;
        if(medias != nullptr)
            medias->print_message(fout);
        fout << "M5->post_type: " << post_type << std::endl;
    }

    ~M5(){
        if(medias != nullptr)
            delete medias;
    }

    M5(){
       medias = nullptr;
    }

private:
    alignas(8) int64_t req_id;
    alignas(8) string username;
    alignas(8) int64_t user_id;
    alignas(8) string text;
    alignas(8) M3* medias;
    alignas(8) E1 post_type;
};


class alignas(8) M6 : public M_base
{
public:
    class alignas(8) M7 : public M_base
    {
    public:
        enum E1 {
            POST = 0,
            REPOST = 1,
            REPLY = 2,
            DM = 3,
        };
        
        class alignas(8) M8 : public M_base
        {
        public:
            inline void set_user_id(int64_t val){
                user_id = val;
            }
            inline int64_t& get_user_id(){
                return user_id;
            }
        
            inline void set_username(string val){
                username = val;
            }
            inline string& get_username(){
                return username;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M8->user_id: " << user_id << std::endl;
                fout << "M8->username: " << username << std::endl;
            }
        
            ~M8(){
            }
        
            M8(){
            }
        
        private:
            alignas(8) int64_t user_id;
            alignas(8) string username;
        };


        class alignas(8) M9 : public M_base
        {
        public:
            inline void set_user_id(int64_t val){
                user_id = val;
            }
            inline int64_t& get_user_id(){
                return user_id;
            }
        
            inline void set_username(string val){
                username = val;
            }
            inline string& get_username(){
                return username;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M9->user_id: " << user_id << std::endl;
                fout << "M9->username: " << username << std::endl;
            }
        
            ~M9(){
            }
        
            M9(){
            }
        
        private:
            alignas(8) int64_t user_id;
            alignas(8) string username;
        };


        class alignas(8) M10 : public M_base
        {
        public:
            inline void set_shortened_url(string val){
                shortened_url = val;
            }
            inline string& get_shortened_url(){
                return shortened_url;
            }
        
            inline void set_expanded_url(string val){
                expanded_url = val;
            }
            inline string& get_expanded_url(){
                return expanded_url;
            }
        
            inline void print_message(std::ofstream &fout){
                fout << "M10->shortened_url: " << shortened_url << std::endl;
                fout << "M10->expanded_url: " << expanded_url << std::endl;
            }
        
            ~M10(){
            }
        
            M10(){
            }
        
        private:
            alignas(8) string shortened_url;
            alignas(8) string expanded_url;
        };


        inline void set_post_id(int64_t val){
            post_id = val;
        }
        inline int64_t& get_post_id(){
            return post_id;
        }
    
        inline M8* mutable_creator(){
            creator = new M8();
            return creator;
        }
        inline M8*& get_creator(){
            return creator;
        }
    
        inline void set_req_id(int64_t val){
            req_id = val;
        }
        inline int64_t& get_req_id(){
            return req_id;
        }
    
        inline void set_text(string val){
            text = val;
        }
        inline string& get_text(){
            return text;
        }
    
        inline M9* mutable_user_mentions(){
            user_mentions = new M9();
            return user_mentions;
        }
        inline M9*& get_user_mentions(){
            return user_mentions;
        }
    
        inline M3* mutable_media(){
            media = new M3();
            return media;
        }
        inline M3*& get_media(){
            return media;
        }
    
        inline M10* mutable_urls(){
            urls = new M10();
            return urls;
        }
        inline M10*& get_urls(){
            return urls;
        }
    
        inline void set_timestamp(int64_t val){
            timestamp = val;
        }
        inline int64_t& get_timestamp(){
            return timestamp;
        }
    
        inline void set_post_type(E1 val){
            post_type = val;
        }
        inline E1& get_post_type(){
            return post_type;
        }
    
        inline void print_message(std::ofstream &fout){
            fout << "M7->post_id: " << post_id << std::endl;
            if(creator != nullptr)
                creator->print_message(fout);
            fout << "M7->req_id: " << req_id << std::endl;
            fout << "M7->text: " << text << std::endl;
            if(user_mentions != nullptr)
                user_mentions->print_message(fout);
            if(media != nullptr)
                media->print_message(fout);
            if(urls != nullptr)
                urls->print_message(fout);
            fout << "M7->timestamp: " << timestamp << std::endl;
            fout << "M7->post_type: " << post_type << std::endl;
        }
    
        ~M7(){
            if(creator != nullptr)
                delete creator;
            if(user_mentions != nullptr)
                delete user_mentions;
            if(media != nullptr)
                delete media;
            if(urls != nullptr)
                delete urls;
        }
    
        M7(){
           creator = nullptr;
           user_mentions = nullptr;
           media = nullptr;
           urls = nullptr;
        }
    
    private:
        alignas(8) int64_t post_id;
        alignas(8) M8* creator;
        alignas(8) int64_t req_id;
        alignas(8) string text;
        alignas(8) M9* user_mentions;
        alignas(8) M3* media;
        alignas(8) M10* urls;
        alignas(8) int64_t timestamp;
        alignas(8) E1 post_type;
    };


    inline void set_req_id(int64_t val){
        req_id = val;
    }
    inline int64_t& get_req_id(){
        return req_id;
    }

    inline M7* mutable_post(){
        post = new M7();
        return post;
    }
    inline M7*& get_post(){
        return post;
    }

    inline void print_message(std::ofstream &fout){
        fout << "M6->req_id: " << req_id << std::endl;
        if(post != nullptr)
            post->print_message(fout);
    }

    ~M6(){
        if(post != nullptr)
            delete post;
    }

    M6(){
       post = nullptr;
    }

private:
    alignas(8) int64_t req_id;
    alignas(8) M7* post;
};

M_base* createMessage(int temp_class_id) {
    switch (temp_class_id) {
        case 1:
            return new M1();
        case 2:
            return new M2();
        case 3:
            return new M3();
        case 4:
            return new M4();
        case 5:
            return new M5();
        case 6:
            return new M6();
        case 7:
            return new M6::M7();
        case 8:
            return new M6::M7::M8();
        case 9:
            return new M6::M7::M9();
        case 10:
            return new M6::M7::M10();
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
            return sizeof(M3);
        case 4:
            return sizeof(M4);
        case 5:
            return sizeof(M5);
        case 6:
            return sizeof(M6);
        case 7:
            return sizeof(M6::M7);
        case 8:
            return sizeof(M6::M7::M8);
        case 9:
            return sizeof(M6::M7::M9);
        case 10:
            return sizeof(M6::M7::M10);
        default:
            return 0;
    }
}


