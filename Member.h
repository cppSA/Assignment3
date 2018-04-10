/**
*hidden file of class Member
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
#pragma once
//libraries
#include <iostream>
#include <vector>
using namespace std;

extern int cnt; //global variable for all files

//This class represents a member in the social media/
class Member{
    private:
        int numfollowers;   //num of followers the member has
        int numfollowing;   //num of people the member is following
        vector <Member*> following; //list of people the member is following
        vector <Member*> followers; //list of people that are following the member
    
    public:
        //This is the class constructor. Sets values to 0.
        Member(){
            this->numfollowers=0;
            this->numfollowing=0;
            cnt++;
        }
        //Destructor for a member object
        ~Member(){
            cnt--;
            //First we erase ourselves from the 'followers' of every member we are following.
            for (int i=0; i<this->following.size(); i++)
            {
                this->following[i]->delFollower();
                for (int j=0;j<this->following[i]->followers.size();j++)
                    if (this==this->following[i]->followers[j])
                    {
                        this->following[i]->followers.erase(this->following[i]->followers.begin()+j);
                        break;
                    }
            }
            //Now, we make every member that follows us - unfollow us by decreasing number of following and erasing ourselves from their following list.
            for (int j=0;j<this->followers.size();j++)
            {
                this->followers[j]->numfollowing--;
                for(int i=0;i<this->followers[j]->following.size();i++)
                    if(this==this->followers[j]->following[i])
                    {
                        this->followers[j]->following.erase(this->followers[j]->following.begin()+i);
                        break;
                    }
            }
            //delete
            this->following.clear();
            this->followers.clear();
        }

        void follow(Member &m);
        void unfollow(Member &m);
        int numFollowers();
        int numFollowing();
        static int count();

    private:
        void addFollower();
        void delFollower();
};