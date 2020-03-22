#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;

class menu
{
public :
    void main_menu(void) ;
private :
    void edit_menu(void) ;
} ;



class product
{
        public :
                    
				void add_item(void) ;
                void delete_item(void) ;
                void modify_item(void) ;
                void list_of_item(void) ;
                void purchase(void) ;
        private :
          
		        int last_code(void) ;
                void delete_record(int) ;
                void modify_record(int) ;
                void display_record(int) ;
                int item_found(int) ;
                int recordno(int) ;
                int itemcode ,dd,mm,yy ;
                char itemname[30] ;
                float itemcost;
                int itemleft;
                char slash;
} ;




void menu :: edit_menu(void)
{ 
    system("cls");
	int ch;
	cout<<"\n\n\n\n\t\t\t\t EDIT MENU \n";
	cout<<"\t\t\t==================================================\n\n";
	cout<<"\t\t\t--------------------------------------------------\n";
    cout<<"\t\t\t 1. ADD PRODUCTS"<<"\n";
	cout<<"\t\t\t 2. MODIFY DETAILS "<<"\n";
	cout<<"\t\t\t 3. DELETE ANY MEDECINE DETAILS "<<"\n";
	cout<<"\t\t\t 0. EXIT "<<"\n";
	cout<<"\n\t\t\t ENTER YOUR CHOICE :";
	cin>>ch;
	
	switch (ch)
		{
		case 1:
			{
			    product a;
			    a.add_item();
				break;
			
			}	
		
		
		case 2:
			{
				product a;
				a.modify_item();
				break;
				
			}	
			
		case 3:
			{
				 product a;
				 a.delete_item();
                 
				break;
			
			}	


		case 0:
			{
				main_menu();
				
			}
	
}
	   
}

void menu:: main_menu()
{
	
    int ch;
    do
	{
		system("cls");
			cout<<"\n\n\n\n\t\t\t \t   Pharmacy Management System \n";
	        cout<<"\t\t\t==================================================\n\n";
	        cout<<"\t\t\t--------------------------------------------------\n";
	        cout<<"\n\t\t\t 1: PURCHASE MEDECINE "<<"\n";
            cout<<"\t\t\t 2. LIST OF MEDECINES"<<"\n";
            cout<<"\t\t\t 3. EDIT MEDECINE FILE"<<"\n";
            cout<<"\t\t\t 0: QUIT"<<"\n";
		    cout<<"\n\t\t\t ENTER YOUR CHOICE :";

		    cin>>ch;

		switch (ch)
		{
		case 1:
			{ product a;
			a.purchase();
			 
				break;
			
			}	
		
		
		case 2:
			{ 
			
				 product a;
				 a.list_of_item();
				break;
				
			}	
			
		case 3:
			{
				edit_menu();
				
				break;
			
			}	

	
		case 0:
			{
				exit(0);
				
			}	
        	
		
		}
	}while(ch!=4);

}


void product :: list_of_item(void)
{
    system("cls");
    char ch;
    fstream file ;
    file.open("medicine.txt", ios::in) ;
    file.seekg(0) ;
    int  found = 0 ;
    
    
    cout <<"\n\n\t\t\t\t LIST OF MEDECINES  \n";
    
    while (file.read((char *) this, sizeof(product)))
    {
        
        found = 1 ;
        
        
        cout<<"\n\t ITEM CODE              : ";
        cout <<itemcode ;
        cout<<"\n\n\t ITEM NAME              : ";
        cout <<itemname ;
        cout<<"\n\t ITEM COST (Rs)         : ";
        cout <<itemcost ;
        cout<<"\n\t PACKETS AVAILABLE      : " ;
        cout <<itemleft; 
        cout<<"\n\t EXPIRY DATE (dd/mm/yy) : "; 
		cout<<dd<<slash<<mm<<slash<<yy<<"\n\n\n\t ";
       
    }
    if ( !found )
    {
        
        cout <<"\n\n\n\t Records not found" ;
    }
    
    cout <<"\n\n\t Press z key to continue..." ;
    cin>>ch;
    file.close () ;
}
int product :: last_code(void)
{
    fstream file ;
    file.open("medicine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(product)))
        t = itemcode ;
    file.close() ;
    return t ;
}

void product::add_item()
{
	system("cls");
	    int t_code,valid;
	    char ch;
	    t_code =last_code();
	    t_code++;
	      cout<<"\n\n\n\n\t\t\t\t   ADDITION OF ITEMS \n";
	    
	    do{  z:
		
                
                cout<<"\n\n\t\t ITEM CODE :"<<t_code<<"\n\n";
                cout <<" MEDECINE NAME: " ; cin>>itemname;
              	strupr(itemname) ;
                cout<<" MEDECINE COST (Rs) : "; cin>>itemcost; 
                cout<<" PACKETS AVAILABLE : "; cin>>itemleft;
                cout<<" EXPIRY DATE (dd/mm/yy) :"; cin>>dd>>slash>>mm>>slash>>yy;
				do
                  {        
                    cout <<"\n Do you want to save this record (y/n) : " ;
                    cin>>ch;
                    ch = toupper(ch) ;
                   
                  } while (ch != 'N' && ch != 'Y') ;
			     
				 if (ch == 'Y')
                  {
                    itemcode = t_code ;
                    fstream file ;
                    file.open("medicine.txt", ios::out | ios::app ) ;
                    file.write((char *) this, sizeof(product)) ;
                    file.close() ;
                    t_code++ ;
            
                             
				  if(!file)
                    {
                         cout<<" Error in creating file.."<<endl;
                        goto z;
                    }
                    else
                       cout<<"\n File created successfully."<<endl;
                  }
			       
			        do
                     {
            
                       cout <<"\n\n Do you want to add more records (y/n) : " ;
                        cin>>ch;
                        ch = toupper(ch) ;
                      } while (ch != 'N' && ch != 'Y') ;
	
           }while(ch == 'Y');
}


void product :: display_record(int tcode)
{
    fstream file ;
    file.open("medicine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
        cout<<"\n\t ITEM CODE : ";
        cout <<itemcode ;
        cout<<"\n\n\t ITEM NAME : ";
        cout <<itemname ;
        cout<<"\n\t ITEM COST (Rs) : ";
        cout <<itemcost ;
        cout<<"\n\t PACKETS AVAILABLE : ";
        cout <<itemleft;
        cout<<"\n\t EXPIRY DATE (dd/mm/yy) : "; 
		cout<<dd<<slash<<mm<<slash<<yy<<"\n\n\n\t ";
            
        }
        
    }
    file.close() ;
}
int product :: recordno(int tcode)
{
    fstream file ;
    file.open("medicine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
   double found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
       found++;
        if (itemcode == tcode)
        break;
    
    }
    file.close() ;
    return found;
}

int product :: item_found(int tcode)
{
    fstream file ;
    file.open("medicine.txt", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            found++ ;
            break ;
        }
    }
    file.close() ;
    return found ;
}
void product :: delete_record(int tcode)
{
    fstream file ;
    file.open("medicine.txt", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(product)) ;
        if ( file.eof() )
            break ;
        if ( itemcode != tcode )
            temp.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("medicine.txt", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(product)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
    remove("temp.dat");
}

void product :: delete_item(void)
{
	x:
    system("cls");
    char  ch ;
    int t, tcode ;
    

    
    cout <<"\n\n\tEnter Item Code of the item to be deleted or press 0 to see the list :  " ;
    
    cin>>tcode;
  
    if (tcode == 0)
    {
        list_of_item() ;
        
        goto x;
    }
    
   else
   { 
	 if (!item_found(tcode))
     {
        
        cout <<"\n\n\tRecord not found....." ;
        cout <<"\n\n\tPress z key to continue..." ;
        cin>>ch;
     }
    
	else{
	
    display_record(tcode) ;
    do
    {
       
        cout <<"\n \t Do you want to delete this record (y/n) : " ;
        cin>>ch;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        {
        	menu b;
			b.main_menu();
		}
		else
    delete_record(tcode) ;
    
    cout <<"\t Record Deleted" ;
    cout <<"\n\n\t Press z key to continue..." ;
    cin>>ch;
    menu b;
    b.main_menu();
    
}
}
}


void product :: modify_record(int tcode)
{
    int recno ;
    recno = recordno(tcode) ;
    int  t_code,tcost ;
    char ch ,tname[30],slash;
    
    itemcode=tcode;
        cout <<"\n\t ENTER ITEM NAME TO ADD IN THE MENU\n" ;
        
        cout <<"\t Item Name : " ;
        cin>>tname;
        
        strupr(tname) ;
        strcpy(itemname,tname);
        cout <<" \t ENTER ITEM COST TO ADD IN THE MENU \n" ;
        
        cout <<"\t Item Cost : " ;
        cin>>tcost;
        itemcost=tcost;
        cout <<" \t ENTER ITEM QUANTITY TO ADD IN THE MENU \n" ;
        
        cout <<"\t Packets avalilable : " ;
        cin>>itemleft;
        
        cout<<"\t EXPIRY DATE (dd/mm/yy) :"; 
		cin>>dd>>slash>>mm>>slash>>yy;
        
        do
    {
        cout <<"\n  \t Do you want to save this record (y/n) : " ;
       cin>>ch;
        ch = toupper(ch) ;
        
    }
    while (ch != 'N' && ch != 'Y') ;
    if(ch=='Y')
   {
   fstream file ;
    file.open("medicine.txt", ios::out|ios::in|ios::ate  ) ;
    file.seekg(0,ios::beg);
	int location=0;
    location =  (recno- 1) * sizeof(product);
    
    file.seekp(location) ;
    
    file.write((char *) this, sizeof(product)) ;
    file.close();
    display_record(tcode) ;
   
    cout <<"\n\tRecord Modified" ;
    cout <<"\n\n\t Press z key to continue..." ;
    cin>>ch;
}
    menu b;
    b.main_menu();
    cin>>ch;
   
}



    
    
void product :: modify_item(void)
{
	x:
    system("cls");
    char  ch ;
    int t, tcode ;
    

    
    cout <<"\n\n\tEnter Item Code of the item to be updated or press 0 to see the list :  " ;
    
    cin>>tcode;
  
    if (tcode == 0)
    {
        list_of_item() ;
        
        goto x;
    }
    
   else
   { 
	 if (!item_found(tcode))
     {
        
        cout <<"\n\n\tRecord not found....." ;
        cout <<"\n\n\tPress z key to continue..." ;
        cin>>ch;
     }
    
	else{
	
    display_record(tcode) ;
    do
    {
       
        cout <<"Do you want to update this record (y/n) : " ;
        cin>>ch;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        {
        	menu b;
			b.main_menu();
		}
		else
    modify_record(tcode) ;
}
}
}
void product :: purchase ()
{
	x:
    system("cls");
    char  ch ;
    int tcode, tqty,tcost,total ;
    char t_itemname[10];

 do{
  
    cout <<"\n\n\tEnter Item Code of the item to purchase or press 0 to see the list :  " ;

  
    cin>>tcode;
  
    if (tcode == 0)
    {
        list_of_item() ;
        
        goto x;
    }
    
   else
   { 
	 if (!item_found(tcode))
     {
        
        cout <<"\n\n\tRecord not found....." ;
        cout <<"\n\n\tPress z key to continue..." ;
        cin>>ch;
     }
     else{
     		 cout <<"\n \t ENTER QUANTITY TO  PURCHASE \n" ;
    	   cout <<"\t Quantity : " ;
              cin>>tqty ;
              if(itemleft<tqty)
              {
              	cout<<"\n\t NOT ENOUGH STOCK ";
              	cout <<"\n\n\t Press z key to continue..." ;
                 cin>>ch;
                 
                     menu b;
					 b.main_menu();
             }  
               if(itemleft==0)
              {
              	cout<<"\n\t NO  STOCK LEFT ";
              	cout <<"\n\n\t Press z key to continue..." ;
                 cin>>ch;
                 
                     menu b;
					 b.main_menu();
             }  
              
	

     do
     {        display_record(tcode) ;
              cout <<"Do you want to purchase this medicine (y/n) : " ;
              cin>>ch;
              ch = toupper(ch);
	 }while (ch != 'N' && ch != 'Y') ; 
	  
	  if (ch=='Y')
        {  
		  ifstream file;
		  file.open("medicine.txt",ios::in) ;
          file.read((char*)this,sizeof(product));
           while(!file.eof()) 
		   {
		    if (itemcode==tcode)
            {
            tcost=itemcost;
            total = tcost*tqty;
            cout<<"\n\n\t Total cost for the order  is "<<total;
            break;
            }
	       }
		 
            file.close();
		 }
    else{cin>>ch;}
    int  recno = recordno(tcode) ;
    fstream file;
    file.open("medicine.txt",ios::out|ios::in|ios::ate);
    file.seekg(0,ios::beg);
	int location=0;
    location =  (recno- 1) * sizeof(product);
    file.seekp(location) ;
    if(itemcode==tcode)
    {
    	itemleft=itemleft-tqty;
    	file.write((char *) this, sizeof(product)) ;
	}
    
    
    file.close(); 
   
    do
        {
            
         cout <<"\n\n\t Do you want to buy more(y/n) : " ;
        cin>>ch;
          ch = toupper(ch) ;
        } while (ch != 'N' && ch != 'Y') ;
        
        
} 
  
}

}while(ch=='Y');
   
 
}
main()
{
    menu b;

     b.main_menu();
}
