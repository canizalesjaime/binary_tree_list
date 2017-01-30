/***************************************************************************************************************************************
Title  : maintree.cpp
Author : Jaime Canizales 
Created on : December 8, 2016
Modifications : 
Notes : main function takes care of making the programs user interactive

*****************************************************************************************************************************************/

#include "treelist.h"
#include  <iostream>
#include  <string>
#include  <fstream>

using namespace std; 

int main ()
{

   string test = "";
   Contactlist c;
   
      string reader; 
      ifstream input("contactlist");

      if ( input.fail() )
         {
           cerr<<"failed to open contactlist"<<endl;
           return 0;
         }

      string fir, las, tel, em ;
      Name tempName ;
      
      while( !input.eof() )
	   {
	       getline(input, reader, ',');
	       fir = reader;

	       getline(input, reader, ',');
	       las = reader;

	       getline(input, reader, ',');
	       tel = reader;

	      getline(input, reader);
	      em = reader;

	      tempName.set_first(fir);
	      tempName.set_last(las);

	      Contact tempcontact2 ( tempName, tel, em);
	      
	      c.insert( tempcontact2 );
            }
        cout<<"file opened correctly "<<c.size()<<" contacts in file"<<endl;

   while( test != "quit" )
        {
cout<<"Enter the command below you would like to execute, commands are case sensitive so enter them as they appear below :"<<endl;

           cout<<"list"<<endl
               <<"insert"<<endl
               <<"delete"<<endl
               <<"find"<<endl
               <<"save"<<endl
               <<"merge"<<endl
               <<"clear"<<endl
               <<"quit"<<endl;

           getline(cin, test);




             if ( test == "list" )
                 int numberOfContacts = c.display();

             else if ( test == "insert" )
                  {
                     string f, l, Telephone, Email;
                     Name name;

                     cout<<"enter first name :"<<endl;
                     getline(cin, f);

                     cout<<"enter last name :"<<endl;
                     getline(cin, l);

                     cout<<"enter telephone number :"<<endl;
                     getline(cin, Telephone);

                     cout<<"enter email address :"<<endl;
                     getline(cin, Email);
                     
                     name.set_first(f);
                     name.set_last(l); 
                     Contact tempcontact  ( name , Telephone, Email ) ;
                     c.insert ( tempcontact );
                   }

              else if ( test == "delete" )
                  {
                        
                      Name tName;
                      string Fname ;
                      cout<<"enter a first name :"<<endl;
                      getline(cin, Fname);

                      string Lname ;
                      cout<<"enter a last name : "<<endl;
                      getline(cin, Lname);

                       string Telephone ;
                       cout<<"enter a telephone :"<<endl;
                       getline(cin, Telephone);

                       string Email ;
                       cout<<"enter an email :"<<endl;
                       getline(cin, Email);

                       tName.set_first(Fname);
                       tName.set_last(Lname);

                      Contact tempcontact3  ( tName, Telephone, Email );

                      
                      c.remove ( tempcontact3 );
                  }

               else if ( test == "find" )
                  {
                      Name tName;
                      string Fname ;
                      cout<<"enter a first name :"<<endl;
                      getline(cin, Fname);

                      string Lname ;
                      cout<<"enter a last name :"<<endl;
                      getline(cin, Lname);

                       string Telephone ;
                       cout<<"enter a telephone :"<<endl;
                       getline(cin, Telephone);

                       string Email ;
                       cout<<"enter an email :"<<endl;
                       getline(cin, Email);

                       tName.set_first(Fname);
                       tName.set_last(Lname);

                      Contact tempcontact3  ( tName, Telephone, Email );

                      
                      c.find ( tempcontact3 );
                    }
  
                else if ( test == "save" )
                   {
                       ofstream output("contactlist.bkp");     
                       c.save(output);
                   }

                               
                else if ( test == "quit")
                         break;

               else if ( test == "merge" )
                   {
                      string reader, tempFile; 
                      cout<<"Enter file name :"<<endl;
                      getline(cin, tempFile);
                      ifstream input(tempFile.c_str());

                      string fir, las, tel, em ;
                      Name tempName ;
                      
                      while( !input.eof() )
                           {
                               getline(input, reader, ',');
                               fir = reader;

                               getline(input, reader, ',');
                               las = reader;
 
                               getline(input, reader, ',');
                               tel = reader;
 
                              getline(input, reader);
                              em = reader;

                              tempName.set_first(fir);
                              tempName.set_last(las);

                              Contact tempcontact2 ( tempName, tel, em);
                              
                              c.insert( tempcontact2 );
                           }
                              
                    }

            else if ( test == "clear" )
                    {
                       int deleted = c.make_empty();
                    }
                    
  
               else {
                       cerr<<"Incorrect command"<<endl;
                       continue;
                    }

       }
    
    return 0;
}





