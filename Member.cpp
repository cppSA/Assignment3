/**
*cpp file of class Member
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//library
#include "Member.h"

    int cnt = 0; //initialize extern variable - in h file
    //returns the number of members in the chat.
    int Member::count(){
       return cnt; 
    }
    
    //Add follower to M and increase by one 'numfollowing' to the member that called the function.
    void Member::follow(Member &m){
        //Here we make sure that this is not a duplicate request
        for (int i=0; i<this->following.size(); i++){
            if (this->following[i]==&m)
            { 
                return;
            }
        }
        //if follower doesn't exist in list, request is accepted
        m.followers.push_back(this);
        this->following.push_back(&m);
        this->numfollowing++;
        m.addFollower();
    }

    //Delete one follower of M and decrease by one 'numfollowing' to the member that called the function.
    void Member::unfollow(Member &m){
        for (int i=0; i<this->following.size(); i++){
            if (this->following[i]==&m){
                this->numfollowing--;
                m.delFollower();
                for (int j=0;j<m.followers.size();j++)
                    if (this==m.followers[j])
                    {
                        m.followers.erase(m.followers.begin()+j);
                        break;
                    }
                this->following.erase(this->following.begin()+i);
            }
        }           
    }

    //Add follower to the member that called this function (private attribute).
    void Member::addFollower(){
        this->numfollowers++;
    }

    //Decrease by one follower the 'numfollowers' attribute of the member that called this function (private attribute), or throw exception if there are none.
    void Member::delFollower(){
        if (this->numfollowers>0){
            this->numfollowers--;
        }
        else{
            throw "Number of followers must be positive.";
        }
    }

    //A get function to the numfollowers atttribute of the memeber that called the function.
    int Member::numFollowers(){
        return this->numfollowers;
    }

    //A get function to the numfollowers atttribute of the memeber that called the function.
    int Member::numFollowing(){
        return this->numfollowing;
    }

