/********************************************************************************************************************************

Title  : treelist.h
Author : Jaime Canizales 
Created on : December 7, 2016
Modifications : 
Notes : This header file contains three classes, the name, contact, and contactlist class. also contains a record node(struct)


*********************************************************************************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <fstream>

using namespace std;


// class Name holds the name of a contact and consists of simple and trivial functions. 
class Name 
{

  private :
  string fname;
  string lname;

  public :
  Name ();
  string first();
  string last();
  void set_first(string fName);
  void set_last(string lName);
};



//This class is not documented either because the methods are simple accessors and mutators.
class Contact 
{
  private:
  Name name;
  string telephone;
  string email;
  
  public :
  Contact();
  Contact(Name person, string tel_num, string email_addr);
  void set(string fname, string lname, string tel_num, string email_addr);
  void get_name(Name &fullname);
  void get_tel(string &tel_num);
  void get_email(string &email_addr);
  void set_name(Name fullname);
  void set_tel(string tel_num);
  void set_email(string email_addr);
};
   

 
//this class allows the  class Contact to act as a node.  
typedef class Record* link;
class Record
{
   public:
   Contact node;
   link left;
   link right;
   friend class Contact;

   
   Record();
   Record(Contact contact);
};

//typedef void (*visit_function)(string&);
class binary_tree
{
   private:
   link root;
   int size;

   protected:
   binary_tree();
   void addRecord(link& current, Contact record_to_insert, int& i);
   void set_root_and_size();
   int get_size();
   void real_display(link& current, int& i);
   void real_save(link& current, ofstream& file, int& i);
   void real_find(link& current, Contact record_to_find);
   void real_remove(link& current, Contact record_to_delete);
   link findMin(link current);
   void real_makeEmpty(link &current, int& i);
   void real_find_string(string FNAME, string LNAME, link& current);
   friend class Contactlist;

};
   



class Contactlist:public binary_tree
{
  

    public :
          

/** Constructor: 
 * Creates an empty contact list.
 * @pre  None
 * @post The object is empty.
*/
Contactlist(); 
               

/** size()
 * Returns the total number of contacts in the contact list.
 *
 * @pre         None.
 * @post        None.
 * @returns int The total number of contacts in the contact list.
 */
int size();
               

/** insert(record_to_insert)
 * Inserts a given record into the contact list. If the record is an exact
 * duplicate of an existing record, it will not be added.
 * 
 * @pre     record_to_insert is a valid Contact. If there is not an exact copy 
 *          of record_to_insert already in contact list, then record_to_insert 
 *          is inserted into the list at an unspecified position.
 * @returns int The total number of contacts successfully inserted into the list.
 */
int insert(Contact record);
               //int insert(contactlist contact_list);
               
/** find(output, record_to_find) find(ostream &output, )
 * Writes onto the output stream all contacts that match the non-null fields
 * of record_to_find. 
 *
 * @pre     record_to_find is a valid contact and output is an open ostream.
 * @post    Any contacts whose non-null members match the non-null members of
 *          the record_to_find are appended to the ostream, sorted by last name,
 *          and then first name in case of ties.
 * @returns  int The number of records written to the stream.
 */
int find(Contact record_to_find);
               

/** findname(output, lastname, firstname)
 * Writes onto the output stream all contacts whose last and first names match 
 * the given names.
 *
 * @pre      lastname is a valid name and firstname is a valid name and output
 *           is an open iostream.
 * @post     Any contacts whose first and last names match the given first and 
 *           last names are appended to the ostream.
 * @returns int The number of records written to the stream.
 */
int find(string lastname, string firstname);
               

/** make_empty()
 * Deletes all of the contacts in the contact list. 
 * 
 * @pre     None. 
 * @post    The contact list becomes an empty list.
 * @returns int The number of records deleted.
 */
int make_empty();
               

/** Destructor 
 * Deletes all memory used by the contact list.
 * @pre None
 * @post The list is empty
 * Note that this is not called by any code.
 */
~Contactlist();
               

/** display(output)
 * Outputs the contact list in sorted order by last name, with the first name
 * as the secondary key. The data is spaced on the line so that each data field
 * is  aligned with the one above. The implementation is free to choose the 
 * specific field widths.
 *
 * @pre      The ostream has been opened.
 * @post     The contacts in the contact list are appended to the ostream in
 *           sorted order, by last name, and then by first name in case last
 *           names are identical. If there are two records with identical primary
 *           and secondary key, the telephone number is used as a tertiary
 *           key, and if need be the email address is the quaternary key.
 * @param [inout] ostream output The stream for outputting the contact list.
 * @returns  int The number of records written
 */
int display();
               

/** save()
 * This saves a copy of the current contactlist by writing it to a file named 
 * contactlist.bkp in the current working directory, overwriting any such file 
 * if it already exists. It must have write permission in the working directory.
 *
 * @pre     None. 
 * @post    The contactlist.bkp file in the current working directory contains 
 *          the contents of the current copy of the in-memory contact list. If 
 *          the file existed before, it is replaced. 
 * @returns int The number of contacts written to the file, or -1 if the write 
 *          was not allowed.
 */
int save(ofstream& file);
               


/** remove(record_to_delete)
 * Removes all contacts which match the non-null fields of record_to_delete. 
 * Every contact in the contact list whose members match every non-null member 
 * of record_to_delete is removed from the list.
 * 
 * @pre     record_to_delete is a contact containing at least a non-null last  
 *          name and a non-null first name. 
 * @post    The contact list will contain no contacts which match the non-null 
 *          fields of record_to_delete.
 * @returns int The total number of contacts successfully removed from the list.
 */
int remove(Contact record_to_delete);
}; 
              
#endif

           
