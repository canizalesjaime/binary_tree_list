/*********************************************************************************************************************************
Title  : treelist.cpp
Author : Jaime Canizales 
Created on : December 8, 2016
Modifications : 
Notes : This is the implementation for the name, contact, binary_tree, and contactlist.

**********************************************************************************************************************************/


#include <iostream>
#include <string>
#include "treelist.h"
#include <fstream>

using namespace std;

//the following functions set the first and last name making sure 
Name::Name()
{
}

string Name::first()
{
   return fname;
}

string Name::last()
{
   return lname;
}

void Name::set_first(string fName)
{
     bool success = true;

     if (fName.length() > 0 && fName.length() < 32 )
         {
            for( int i = 0; i < fName.length(); i++ ) 
                {
                    if ( fName[i] < 65 || fName[i] > 122 || fName[i] == 91 || 
                         fName[i] == 92 || fName[i] == 93 || fName[i] == 94 || fName[i] == 95 )
                       {
                           if( fName[i] == 45 )
                               continue ;

                           else {
                                   success = false;
                                   break;
                                 }
                        }
                 }
           }
        if ( success == true && fName.length() < 32 )
            fname = fName;
}

void Name::set_last(string lName)
{     
    bool success = true;

     if ( lName.length() > 0 && lName.length() < 32 )
         {
            for( int i = 0; i < lName.length(); i++ ) 
                {
                    if ( lName[i] < 65 || lName[i] > 122 || lName[i] == 91 || 
                         lName[i] == 92 || lName[i] == 93 || lName[i] == 94 || lName[i] == 95 )
                       {
                           if( lName[i] == 45 )
                               continue ;

                           else {
                                   success = false;
                                   break;
                                 }
                        }
                 }
           }
        if ( success == true && lName.length() < 32 )
            lname = lName;
}
                     
/********************************************************************************************************************************/
//the following functions set the contact information
Contact::Contact ()
  {
      
  }

Contact::Contact (Name person, string tel_num , string email_addr)
  {
      name.set_first(person.first()) ;
      name.set_last(person.last()) ;
      telephone = tel_num;
      email = email_addr;

  }
      

void Contact::set(string fname, string lname, string tel_num, string email_addr)
  {
      name.set_first(fname);
      name.set_last(lname);
      telephone = tel_num;
      email = email_addr;
  }

void Contact::set_name(Name fullname)
  {
      name.set_first(fullname.first()) ;
      name.set_last(fullname.last()) ;
  }

void Contact::set_tel(string tel_num)
  {
     
     bool success = true;
     if ( tel_num.length() < 17 )
        {
            for ( int i = 0; i < tel_num.length(); i++)
                 {
                     if (tel_num[i] < 47 || tel_num[i] > 58 )
                        {
                             success = false ;
                             break;
                        }
                 }
         }
        if( success == true && tel_num.length() < 17 )
            telephone = tel_num;
  }

void Contact::set_email(string email_addr)
{
    bool success = true;
    if(email_addr.length() < 127)
      {
         int i = 0;
         
         while ( email_addr[i] != '@' )
               {
                   if( email_addr[i] == 44) 
                      {
                        success = false;
                        break;
                      }

                  i++;
               }
  
         for(i=i+1; i < email_addr.length() ; i++)
             {
                 if ( email_addr[i] < 45 || email_addr[i] > 122 )
                    { 
                        success = false;
                         break;
                    }
             }
       }              
              

      if( success == true && email_addr.length() < 127)
        email = email_addr;
}

void Contact::get_name(Name &fullname)
  {
     fullname.set_first(name.first());
     fullname.set_last(name.last());
      
  }

void Contact::get_tel(string &tel_num)
  {
      tel_num = telephone;
  }

void Contact::get_email(string &email_addr)
  {
     email_addr = email;
  }
 





/********************************************************************************************************************************/
//The following functions provide necessary binary tree features.

binary_tree::binary_tree()
{
    
}


void binary_tree::set_root_and_size()
{
   root = NULL;
   size = 0;
}

int binary_tree::get_size()
{
    return size;
}

void binary_tree::addRecord(link& current, Contact record_to_insert, int& i)
{
   
   Name tempName, tempName2;
   string  tempTelephone, tempEmail;
   string tempEmail2, tempTelephone2;
   

   record_to_insert.get_name(tempName);
   record_to_insert.get_tel(tempTelephone);
   record_to_insert.get_email(tempEmail);

   
   if(current == NULL)
     { 
        current = new Record(record_to_insert);
        i++;
        size++;
        return;
     }


    current->node.get_name(tempName2);
    current->node.get_tel(tempTelephone2);
    current->node.get_email(tempEmail2);

   if( tempName.last() < tempName2.last())
           addRecord(current->left, record_to_insert, i);

   else if( tempName.last() > tempName2.last())
           addRecord(current->right, record_to_insert, i);

   else {
            if( tempName.first() < tempName2.first())
                addRecord(current->left, record_to_insert, i);

            else if(  tempName.first() > tempName2.first())
                    addRecord(current->right, record_to_insert, i);

            else {
                       if( tempTelephone < tempTelephone2)
                          addRecord(current->left, record_to_insert, i);
     
                       else if( tempTelephone > tempTelephone2)
                              addRecord(current->right, record_to_insert, i);

                       else {
                              if( tempEmail < tempEmail2)
                                 addRecord(current->left, record_to_insert, i);
     
                              else if( tempEmail > tempEmail2)
                                    addRecord(current->right, record_to_insert, i);

                              else {
                                     cerr<<"record already exists"<<endl;
                                     return;
                                   }
                            }
                  }
         }

    
}

void binary_tree::real_display(link& current, int& i)
{
          if ( current != NULL)
         {
            real_display(current->left, i);
   
                 string tempEmail2, tempTelephone2;
                 Name tempName2;

                 current->node.get_name(tempName2);
                 current->node.get_tel(tempTelephone2);
                 current->node.get_email(tempEmail2);
               
              
               cout<<tempName2.first()<<"  "
                   <<tempName2.last()<<"  "
                   <<tempTelephone2<<"  "
                   <<tempEmail2<<endl;

               i++;
                   
 
            real_display(current->right, i);
         }

     
}

void binary_tree::real_save(link& current, ofstream& file, int& i)
{
      if ( current != NULL)
         {
            real_save(current->left, file, i);
   
                 string tempEmail2, tempTelephone2;
                 Name tempName2;

                 current->node.get_name(tempName2);
                 current->node.get_tel(tempTelephone2);
                 current->node.get_email(tempEmail2);
               
              
               file<<tempName2.first()<<"  "
                   <<tempName2.last()<<"  "
                   <<tempTelephone2<<"  "
                   <<tempEmail2<<endl;

               i++;
                   
 
            real_save(current->right, file, i);
         }

     
}

void binary_tree::real_find(link& current, Contact record_to_find)
{
      if ( current != NULL)
         {
            real_find(current->left, record_to_find);
   
                 Name tempName, tempName2;
                 string  tempTelephone, tempEmail;
                 string tempEmail2, tempTelephone2;
   

                record_to_find.get_name(tempName);
                record_to_find.get_tel(tempTelephone);
                record_to_find.get_email(tempEmail);
 
                current->node.get_name(tempName2);
                current->node.get_tel(tempTelephone2);
                current->node.get_email(tempEmail2);


            if( ( tempName.last() == tempName2.last() || tempName.last() == "" ) &&
                ( tempName.first() == tempName2.first() || tempName.first() == "") &&
                ( tempTelephone == tempTelephone2 || tempTelephone == "" )        &&
                ( tempEmail == tempEmail2 || tempEmail == ""  )                      )
              {
               cout<<"record found"<<endl
                   <<tempName2.first()<<"  "
                   <<tempName2.last()<<"  "
                   <<tempTelephone2<<"  "
                   <<tempEmail2<<endl;

              }
                   
 
            real_find(current->right, record_to_find);
         }      
  
    
}

void binary_tree::real_remove(link& current, Contact record_to_delete)
{
       Name tempName, tempName2;
   string  tempTelephone, tempEmail;
   string tempEmail2, tempTelephone2;
   

   record_to_delete.get_name(tempName);
   record_to_delete.get_tel(tempTelephone);
   record_to_delete.get_email(tempEmail);

   
   if(current == NULL)
     { 
        current = new Record(record_to_delete);
        
        size++;
        return;
     }


    current->node.get_name(tempName2);
    current->node.get_tel(tempTelephone2);
    current->node.get_email(tempEmail2);

   if( tempName.last() < tempName2.last())
           real_remove(current->left, record_to_delete);

   else if( tempName.last() > tempName2.last())
           real_remove(current->right, record_to_delete);

   else 
         {
            if( tempName.first() < tempName2.first())
                real_remove(current->left, record_to_delete);

            else if(  tempName.first() > tempName2.first())
                    real_remove(current->right, record_to_delete);

            else 
                    {
                       if( tempTelephone < tempTelephone2)
                          real_remove(current->left, record_to_delete);
     
                       else if( tempTelephone > tempTelephone2)
                              real_remove(current->right, record_to_delete);

                       else if ( tempTelephone == tempTelephone2 || tempTelephone ==  "" )
                            {
                              if( tempEmail < tempEmail2 )
                                 real_remove(current->left, record_to_delete);
     
                              else if( tempEmail > tempEmail2 )
                                    real_remove(current->right, record_to_delete);

                              else if (tempEmail == tempEmail2 || tempEmail == "" )
                                  {
                                      if ( current->left == NULL && current->right == NULL)
                                         {
                                            
                                            link tempPtr = findMin(current->right);
                                          
                                            string tempemail3, temptelephone3;
                                            Name nam;

                                            tempPtr->node.get_name(nam);
                                            tempPtr->node.get_tel(temptelephone3);
                                            tempPtr->node.get_email(tempemail3);
                                  
                                            current->node.set_name(nam);
                                            current->node.set_tel(temptelephone3);                       //current == temp
                                            current->node.set_email(tempemail3);

                                            real_remove(current->right, tempPtr->node);
                                          }
                                       else 
                                            {
                                                 link old_node = current;
                                                 
                                                 if(current !=NULL)
                                                   current = current->left;

                                                 else current = current->right;

                                                 delete old_node;
                                                 old_node = NULL;
                                            }
                                        
                                  }
                            }
                  }
         }
       
}

link binary_tree::findMin(link current)
{

   if(current==NULL)
      return NULL;

   if(current->left == NULL)
     return current ;

   return findMin(current->left);
}

void binary_tree::real_makeEmpty(link &current, int& i)
{
   if ( current != NULL)
      {

         real_makeEmpty(current->left, i);
         real_makeEmpty(current->right, i);
         delete current;
         current = NULL;
         i++;
      }
}
 

void binary_tree::real_find_string(string FNAME, string LNAME, link& current)
{
      if ( current != NULL)
         {
            real_find_string(FNAME, LNAME, current->left);
   
                 Name tempName2;
 
                current->node.get_name(tempName2);


            if( LNAME == tempName2.last() && FNAME == tempName2.first()   )
              {
               cout<<"record found"<<endl;
                   
              }
                   
 
            real_find_string(FNAME, LNAME, current->right);
         }      
  
    
}  
   
/*******************************************************************************************************************************/
//functions for contactlist adt


Contactlist::Contactlist()
{
   set_root_and_size(); 
}

int Contactlist::insert(Contact record_to_insert)
{
    int counter = 0;
    addRecord(root, record_to_insert, counter);
    return counter;
}

int Contactlist::display()
{
     
     int counter = 0;
     
     cout<<"*************************************************"<<endl
         <<"CONTACTLIST DISPLAYED BELOW"<<endl
         <<"*************************************************"<<endl<<endl;
     
    real_display(root, counter);

     cout<<endl
         <<"**************************************************"<<endl
         <<counter<<" CONTACTS ARE LISTED ABOVE"<<endl
         <<"**************************************************"<<endl<<endl;

    

     return counter;
     
}

int Contactlist::save(ofstream& file)
{
    int counter = 0;

     real_save(root, file, counter);

     return counter;
}

int Contactlist::size()
{
    int realSize = get_size();
    return realSize;
}

int Contactlist::find(Contact record_to_find)
{
    real_find(root, record_to_find);
}

int Contactlist::remove(Contact record_to_delete)
{
     real_remove(root, record_to_delete);
}

int Contactlist::make_empty()
{
    int counter = 0;
    real_makeEmpty(root, counter);
    return counter;
}

Contactlist::~Contactlist()
{
   int i =0;
   real_makeEmpty(root, i);
} 

int Contactlist::find(string lastname, string firstname)
{
    real_find_string(firstname, lastname, root);
}
   
/***************************************************************************************************************************/
//record class constructor

Record::Record ()
{
}

Record::Record(Contact contact)
{
     string  e, t;
     Name f;
    
     contact.get_name(f);
     contact.get_tel(t);
     contact.get_email(e);

     node.set_name(f);
     node.set_tel(t);
     node.set_email(e);
  
     right = NULL;
     left = NULL;
}    



