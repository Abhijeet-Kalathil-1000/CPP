////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project Name:               Customised Virtual File System (CVFS)
//  Description:                CVFS is a virtual representation/ emulation  of UFS(UNIX File System)
//  Technology used:            Native System Programming using C Language
//  User Interface:             CUI (Command line User Interface)
//  Platform required:          Linux Distributions or Windows
//  Architectural requirement:  Intel 32 bit Processor
//  Hardware requirement:       5MB RAM space
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iostream>

////////////////////////////////////////////////////////////////////////////////////////////////
//     #define directive is used to defining macro 
////////////////////////////////////////////////////////////////////////////////////////////////

#define MAXINODE 5          //Defining INode count

#define READ 1
#define WRITE 2             //Defining file mode

#define MAXFILESIZE 1024    //Defining Max size(1 KB)

#define REGULAR 1       
#define SPECIAL 2           //Defining File type

#define START 0
#define CURRENT 1
#define END 2               //Defining offset 


////////////////////////////////////////////////////////////////////////////////////////////////
//      Data Structures
//      Using typedef for better readablity
////////////////////////////////////////////////////////////////////////////////////////////////

//Structure represents total count of available Inodes & Total Inodes
struct superblock            
{
    int TotalInodes;
    int FreeInodes;
};
typedef struct superblock SUPERBLOCK;
typedef struct superblock *PSUPERBLOCK;


//Structure represents details inside Inode 
struct inode
{
    char FileName[50];
    int InodeNumber;
    int FileSize;
    int FileActualSize;
    int FileType;
    char *Buffer;
    int LinkCount;
    int ReferenceCount;
    int permission; 
    struct inode *next;
};
typedef struct inode INODE;
typedef struct inode *PINODE;
typedef struct inode **PPINODE;


//Structure represents file table 
struct filetable
{
    int readoffset;
    int writeoffset;
    int count;
    int mode;
    PINODE ptrinode;
};
typedef struct filetable FILETABLE;
typedef struct filetable *PFILETABLE;


//Structure represents User file data table
struct ufdt
{
    PFILETABLE ptrfiletable;
};
typedef struct ufdt UFDT;


////////////////////////////////////////////////////////////////////////////////////////////////
//      Global Variables required
////////////////////////////////////////////////////////////////////////////////////////////////

UFDT UFDTArr[MAXINODE];     //file data table array 
SUPERBLOCK SUPERBLOCKobj;   //creating object for superblock
PINODE head = NULL;         //initalizing Head value of Linked List INODE

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      man
//  Input parameters :      Charachter Pointer
//  Return value :          NA
//  Description :           Used to guide user with commands and uses
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         09/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

void man(char *name)            //User Manual
{
    //Filter to remove invalid entry
    if(name == NULL)
    {
        return;
    } 
    if(strcmp(name,"create") == 0)
    {
        printf("Description : Used to create new regular file\n");
        printf("Usage : create File_name File_permission\n");
    }
    else if(strcmp(name,"read") == 0)
    {
        printf("Description : Used to read data from regular file\n");
        printf("Usage : read File_name No_Of_Bytes_To_Read\n");
    }
    else if(strcmp(name,"write") == 0)
    {
        printf("Description : Used to write into regaular file\n");
        printf("Usage : write File_name\nAfter this enter the data we want to write\n");
    }
    else if(strcmp(name,"ls") == 0)
    {
        printf("Description : Used to list all information of files\n");
        printf("Usage : ls\n");
    }
    else if(strcmp(name,"stat") == 0)
    {
        printf("Description : Used to display information of file\n");
        printf("Usage : stat File_name\n");
    }
    else if(strcmp(name,"fstat") == 0)
    {
        printf("Description : Used to display information of file\n");
        printf("Usage : stat File_Descriptor\n");
    }
    else if(strcmp(name,"truncate") == 0)
    {
        printf("Description : Used to remove data from file\n");
        printf("Usage : truncate File_name\n");
    }
    else if(strcmp(name,"open") == 0)
    {
        printf("Description : Used to open existing file\n");
        printf("Usage : open File_name mode\n");
    }
    else if(strcmp(name,"close") == 0)
    {
        printf("Description : Used to close opened file\n");
        printf("Usage : close File_name\n");
    }
    else if(strcmp(name,"closeall") == 0)
    {
        printf("Description : Used to close all opened file\n");
        printf("Usage : closeall\n");
    }
    else if(strcmp(name,"lseek") == 0)
    {
        printf("Description : Used to change file offset\n");
        printf("Usage : lseek File_Name ChangeInOffset StartPoint\n");
    }
    else if(strcmp(name,"rm") == 0)
    {
        printf("Description : Used to delete the file\n");
        printf("Usage : rm File_Name\n");
    }
    else
    {
        printf("ERROR : no manual entry available.\n");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      DisplayHelp
//  Input parameters :      NA
//  Return value :          NA
//  Description :           Used to display list of functionalities of CVFS
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         09/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayHelp()
{
    printf("ls : To List out all files\n");
    printf("create : To create new file\n");
    printf("open : To open the file\n");
    printf("read : To Read the contents from file\n");
    printf("write : To Write contents into file\n");
    printf("stat : To Display information of file using name\n");
    printf("fstat : To Display information of file using file descriptor\n");
    printf("truncate : To Remove all data from file\n");
    printf("rm : To Delete the file\n");
    printf("close : To close the file\n");
    printf("closeall : To close all opened files\n");
    printf("man (fucntion_name) : To reach for manual of the fucntion\n");
    printf("clear : To clear console\n");
    printf("exit : To Terminate file system\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      GetFDFromName
//  Input parameters :      Charachter Pointer 
//  Return value :          Integer
//  Description :           Function return file descriptor value
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         09/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int GetFDFromName(char *name)       //Return File Descriptor of the file
{
    int i = 0;

    while(i<MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable != NULL)     //If address in ptrfiletable is not null
        {
            if(strcmp((UFDTArr[i].ptrfiletable->ptrinode->FileName),name) == 0) //Tarvel: Array.pointer(UFDT)->pointer(Filetable)->Filename(Inode)
            {
                break;
            }
        }
        i++;
    }

    if(i == MAXINODE)
    {
        return -1;
    }     
    else          
    {
        return i;
    }  
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      Get_Inode
//  Input parameters :      Charachter Pointer 
//  Return value :          Pointer Structure INODE
//  Description :           Used to check if already new file with same name exisits in inode
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         09/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

PINODE Get_Inode(char *name)
{
    PINODE temp = head;
    int i = 0;

    if(name == NULL)
    {
        return NULL;
    }

    while(temp != NULL)
    {
        if(strcmp(name,temp->FileName) == 0)
        {
            break;
        }
        temp = temp->next;
    }

    return temp;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      CreateDILB
//  Input parameters :      NA 
//  Return value :          NA
//  Description :           Used to create Disk Iniode Lsit Block (DILB)
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         09/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1;          // 1 starts from FD 1 ,if we want exact feel of UFS i should be 3
    PINODE newn = NULL;
    PINODE temp = head;

    while(i <= MAXINODE)
    {
        newn = (PINODE)malloc(sizeof(INODE));

        newn->LinkCount = 0;
        newn->ReferenceCount = 0;
        newn->FileType = 0;
        newn->FileSize = 0;
        newn->Buffer = NULL;
        newn->next = NULL;
        newn->InodeNumber = i;

        if(temp == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp->next = newn;
            temp = temp->next;
        }
        i++;
    }
    //printf("DILB created successfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      InitialiseSuperBlock
//  Input parameters :      NA 
//  Return value :          NA
//  Description :           Used to initialized FreeInodes,TotalInodes & ptrfiletable
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         09/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    int i = 0;
    while(i < MAXINODE)
    {
        UFDTArr[i].ptrfiletable = NULL;
        i++;
    }

    SUPERBLOCKobj.TotalInodes = MAXINODE;
    SUPERBLOCKobj.FreeInodes = MAXINODE;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      CreateFile
//  Input parameters :      Pointer 
//  Return value :          Ieteger
//  Description :           Used to Create file 
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         10/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int CreateFile(char *name,int permission)
{
    int i = 0;
    PINODE temp = head;

    if((name == NULL) || (permission == 0) || (permission > 3))
        return -1;

    if(SUPERBLOCKobj.FreeInodes == 0)
        return -2;

    (SUPERBLOCKobj.FreeInodes)--;

    if(Get_Inode(name) != NULL)
        return -3;

    while(temp != NULL)
    {
        if(temp->FileType == 0)
            break;
        temp = temp->next;
    }

    while(i < MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable == NULL)
            break;
        i++;
    }

    UFDTArr[i].ptrfiletable = (PFILETABLE)malloc(sizeof(FILETABLE));

    UFDTArr[i].ptrfiletable->count = 1;
    UFDTArr[i].ptrfiletable->mode = permission;
    UFDTArr[i].ptrfiletable->readoffset = 0;
    UFDTArr[i].ptrfiletable->writeoffset = 0;

    UFDTArr[i].ptrfiletable->ptrinode = temp;

    strcpy(UFDTArr[i].ptrfiletable->ptrinode->FileName,name);

    UFDTArr[i].ptrfiletable->ptrinode->FileType = REGULAR;
    UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount = 1;
    UFDTArr[i].ptrfiletable->ptrinode->LinkCount = 1;
    UFDTArr[i].ptrfiletable->ptrinode->FileSize = MAXFILESIZE;
    UFDTArr[i].ptrfiletable->ptrinode->FileActualSize = 0;
    UFDTArr[i].ptrfiletable->ptrinode->permission = permission;
    UFDTArr[i].ptrfiletable->ptrinode->Buffer = (char *)malloc(MAXFILESIZE);

    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      rm_File
//  Input parameters :      Charachter Pointer 
//  Return value :          Integer
//  Description :           Used to Delete files that are no more required
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         14/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int rm_File(char *name)
{
    int fd = 0;

    fd = GetFDFromName(name);
    if(fd == -1)
    {
        return -1;
    }

    (UFDTArr[fd].ptrfiletable->ptrinode->LinkCount)--;

    if(UFDTArr[fd].ptrfiletable->ptrinode->LinkCount == 0)
    {
        UFDTArr[fd].ptrfiletable->ptrinode->LinkCount == 0;
    //  free(UFDTArr[fd].ptrfiletable->ptrinode->Buffer);
        free(UFDTArr[fd].ptrfiletable);
    }
    
    UFDTArr[fd].ptrfiletable = NULL;
    (SUPERBLOCKobj.FreeInodes)++;

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      ReadFile
//  Input parameters :      Integer, Charachter Pointer, Integer 
//  Return value :          Integer
//  Description :           Used to Read files in the directory
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         14/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int ReadFile(int fd, char *arr,int isize)
{
    int read_size = 0;

    if(UFDTArr[fd].ptrfiletable == NULL)
    {
        return -1;
    }        

    if(UFDTArr[fd].ptrfiletable->mode != READ && UFDTArr[fd].ptrfiletable->mode != READ+WRITE)
    {
        return -2;
    }      

    if(UFDTArr[fd].ptrfiletable->ptrinode->permission != READ && UFDTArr[fd].ptrfiletable->ptrinode->permission != READ+WRITE)
    {
        return -2;
    }

    if(UFDTArr[fd].ptrfiletable->readoffset == UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize)
    {
        return -3;
    }

    if(UFDTArr[fd].ptrfiletable->ptrinode->FileType != REGULAR)
    {
        return -4;
    }

    read_size = (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) - (UFDTArr[fd].ptrfiletable->readoffset);
    if(read_size < isize)
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->readoffset),read_size);

        UFDTArr[fd].ptrfiletable->readoffset = UFDTArr[fd].ptrfiletable->readoffset + read_size;
    }
    else
    {
        strncpy(arr,(UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->readoffset),isize);

        (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->readoffset) + isize;
    }
    return isize;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      WriteFile
//  Input parameters :      Integer, Charachter Pointer, Integer 
//  Return value :          Integer
//  Description :           Used to Write files in the directory
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         14/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int WriteFile(int fd, char *arr, int isize)
{
    if(((UFDTArr[fd].ptrfiletable->mode) != WRITE) && ((UFDTArr[fd].ptrfiletable->mode) != READ+WRITE))
    {
        return -1;
    }     

    if(((UFDTArr[fd].ptrfiletable->ptrinode->permission) != WRITE) && ((UFDTArr[fd].ptrfiletable->ptrinode->permission) != READ+WRITE))
    {
        return -1;
    }     

    if((UFDTArr[fd].ptrfiletable->writeoffset) == MAXFILESIZE)
    {
        return -2;
    }

    if((UFDTArr[fd].ptrfiletable->ptrinode->FileType) != REGULAR)
    {
        return -3;
    }

    strncpy((UFDTArr[fd].ptrfiletable->ptrinode->Buffer) + (UFDTArr[fd].ptrfiletable->writeoffset), arr, isize);

    (UFDTArr[fd].ptrfiletable->writeoffset) = (UFDTArr[fd].ptrfiletable->writeoffset )+ isize;

    (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) = (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + isize;

    return isize;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      OpenFile
//  Input parameters :      Charachter Pointer, Integer 
//  Return value :          Integer
//  Description :           Used to Open files in the directory
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         14/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int OpenFile(char *name,int mode)
{
    int i = 0;
    PINODE temp = NULL;

    if(name == NULL || mode <=0)
    {
        return -1;
    }

    temp = Get_Inode(name);
    if(temp == NULL)
    {
        return -2;
    }

    if(temp->permission < mode)
    {
        return -3;
    }

    while(i < MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable == NULL)
            break;
        i++;
    }

    UFDTArr[i].ptrfiletable = (PFILETABLE)malloc(sizeof(FILETABLE));
    if(UFDTArr[i].ptrfiletable == NULL)
    {
        return -1;
    }
    UFDTArr[i].ptrfiletable->count = 1;
    UFDTArr[i].ptrfiletable->mode = mode;
    if(mode == READ + WRITE)
    {
        UFDTArr[i].ptrfiletable->readoffset = 0;
        UFDTArr[i].ptrfiletable->writeoffset = 0;
    }
    else if(mode == READ)
    {
        UFDTArr[i].ptrfiletable->readoffset = 0;
    }
    else if(mode == WRITE)
    {
        UFDTArr[i].ptrfiletable->writeoffset = 0;
    }
    UFDTArr[i].ptrfiletable->ptrinode = temp;
    
    (UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount)++;

    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      CloseFileByName
//  Input parameters :      Charachter Pointer 
//  Return value :          Integer
//  Description :           Used to Close files by file name in the directory
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         27/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int CloseFileByName(char *name)
{
    int i = 0;
    
    i = GetFDFromName(name);

    if(i == -1)
    {
        return -1;
    }

    UFDTArr[i].ptrfiletable->readoffset = 0;
    UFDTArr[i].ptrfiletable->writeoffset = 0;
    
    (UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount)--;

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Name of function :      CloseAllFile
//  Input parameters :      NA  
//  Return value :          NA
//  Description :           Used to Close All Files opened in the directory
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         27/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

void CloseAllFile()
{
    int i = 0;

    while(i < MAXINODE)
    {
        if(UFDTArr[i].ptrfiletable != NULL)
        {
            UFDTArr[i].ptrfiletable->readoffset = 0;
            UFDTArr[i].ptrfiletable->writeoffset = 0;
            (UFDTArr[i].ptrfiletable->ptrinode->ReferenceCount)--;

            break;
        }
        i++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Name of function :      LseekFile
//  Input parameters :      Integer, Integer, Integer  
//  Return value :          Integer
//  Description :           Used to change file offset
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         27/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int LseekFile(int fd,int size, int from)
{
    if((fd < 0) || (from > 2))
    {
        return -1;
    }

    if(UFDTArr[fd].ptrfiletable == NULL)
    {
        return -1;
    }

    if((UFDTArr[fd].ptrfiletable->mode == READ) || (UFDTArr[fd].ptrfiletable->mode == READ+WRITE))
    {
        if(from == CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->readoffset) + size) > UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize)
            {
                return -1;
            }

            if(((UFDTArr[fd].ptrfiletable->readoffset) + size) < 0)
            {
                return -1;
            }

            (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->readoffset) + size;
        }
        else if(from == START)
        {
            if(size > (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize))
            {
                return -1;
            }

            if(size < 0)
            {
                return -1;
            }

            (UFDTArr[fd].ptrfiletable->readoffset) == size;
        }
        else if(from == END)
        {
            if((UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + size > MAXFILESIZE)
            {
                return -1;
            }
            if(((UFDTArr[fd].ptrfiletable->readoffset) + size) < 0)
            {
                return -1;
            }
            (UFDTArr[fd].ptrfiletable->readoffset) = (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + size;
        }
    }
    else if(UFDTArr[fd].ptrfiletable->mode == WRITE)
    {
        if(from == CURRENT)
        {
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) > MAXFILESIZE)
            {
                return -1;
            }
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) < 0)
            {
                return -1;
            }
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) < (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize))
            {
                (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) = (UFDTArr[fd].ptrfiletable->writeoffset) + size;          
            }
            
            (UFDTArr[fd].ptrfiletable->writeoffset) = (UFDTArr[fd].ptrfiletable->writeoffset) + size;
        }
        else if(from == START)
        {
            if(size > MAXFILESIZE)
            {
                return -1;
            }
            if(size < 0)
            {
                return -1;
            }
            if(size > (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize))
            {
                (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) = size;
            }
            
            (UFDTArr[fd].ptrfiletable->writeoffset) = size;
        }
        else if(from == END)
        {
            if((UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + size > MAXFILESIZE)
            {
                return -1;
            }
            if(((UFDTArr[fd].ptrfiletable->writeoffset) + size) < 0)
            {
                return -1;
            }
            (UFDTArr[fd].ptrfiletable->writeoffset) = (UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize) + size;
        }
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Name of function :      ls_file
//  Input parameters :      NA
//  Return value :          NA
//  Description :           Used to show all files in Directory
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         27/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

void ls_file()
{
    int i = 0;
    PINODE temp = head;

    if(SUPERBLOCKobj.FreeInodes == MAXINODE)
    {
        printf("ERROR : There are no files\n");
        return;
    }

    printf("\nFile Name\tInode number\tFile size\tLink count\n");
    printf("-------------------------------------------------------------\n");
    while(temp != NULL)
    {
        if(temp->FileType != 0)
        {
            printf("%s\t\t%d\t\t%d\t\t%d\n",temp->FileName,temp->InodeNumber,temp->FileActualSize,temp->LinkCount);
        }
        temp = temp->next;
    }
    printf("-------------------------------------------------------------\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Name of function :      fstat_file
//  Input parameters :      Integer
//  Return value :          Integer
//  Description :           Used to display information of file using file descriptor
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         27/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int fstat_file(int fd)
{
    PINODE temp = head;
    int i = 0;

    if(fd < 0)
    {
        return -1;
    }

    if(UFDTArr[fd].ptrfiletable == NULL)
    {
        return -2;
    }

    temp = UFDTArr[fd].ptrfiletable->ptrinode;

    printf("----------Statistical Information about file----------\n");
    printf("File name : %s\n",temp->FileName);
    printf("Inode Number %d\n",temp->InodeNumber);
    printf("File size : %d\n",temp->FileSize);
    printf("Actual File size : %d\n",temp->FileActualSize);
    printf("Link count : %d\n",temp->LinkCount);
    printf("Reference count: %d\n",temp->ReferenceCount);

    if(temp->permission == 1)
    {
        printf("File Permission : Read only\n");
    }
    else if(temp->permission == 2)
    {
        printf("File Permission : Write only\n");
    }
    if(temp->permission == 3)
    {
        printf("File Permission : Read & Write\n");
    }
    printf("-------------------------------------------------------------\n\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Name of function :      stat_file
//  Input parameters :      Charachter Pointer
//  Return value :          Integer
//  Description :           Used to display information of file using name
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         27/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int stat_file(char *name)
{
    PINODE temp = head;
    int i = 0;

    if(name == NULL)
    {
        return -1;
    }

    while ((temp != NULL))
    {
        if(strcmp(name,temp->FileName) == 0)
        {
            break;
        }
        temp = temp->next;
    }
    
    if(temp == NULL)
    {
        return -2;
    }

    printf("----------Statistical Information about file----------\n");
    printf("File name : %s\n",temp->FileName);
    printf("Inode Number %d\n",temp->InodeNumber);
    printf("File size : %d\n",temp->FileSize);
    printf("Actual File size : %d\n",temp->FileActualSize);
    printf("Link count : %d\n",temp->LinkCount);
    printf("Reference count: %d\n",temp->ReferenceCount);

    if(temp->permission == 1)
    {
        printf("File Permission : Read only\n");
    }
    else if(temp->permission == 2)
    {
        printf("File Permission : Write only\n");
    }
    if(temp->permission == 3)
    {
        printf("File Permission : Read & Write\n");
    }
    printf("-------------------------------------------------------------\n\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Name of function :      stat_file
//  Input parameters :      Charachter Pointer
//  Return value :          Integer
//  Description :           Used to display information of file using name
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         27/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int truncate_File(char *name)
{
    int fd = GetFDFromName(name);
    if(fd == -1)
    {
        return -1;
    }

    memset(UFDTArr[fd].ptrfiletable->ptrinode->Buffer,0,MAXFILESIZE);

    UFDTArr[fd].ptrfiletable->readoffset = 0;
    UFDTArr[fd].ptrfiletable->writeoffset = 0;
    UFDTArr[fd].ptrfiletable->ptrinode->FileActualSize = 0;

}/////////Expects a return value

////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Name of function :      main
//  Input parameters :      NA
//  Return value :          NA
//  Description :           Used to fucntionally use CVFS
//  Author Name :           Abhijeet Saji Kalathil
//  Modified Date :         30/07/2022
//
////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char *ptr = NULL;
    int ret=0,fd=0, count=0;
    char command[4][80],str[80],arr[MAXFILESIZE];

    InitialiseSuperBlock();
    CreateDILB();

    while(1)
    {
        fflush(stdin);

        strcpy(str,"");

        printf("\nCustomized VFS ::> ");
        
        fgets(str,80,stdin);//  scanf("%[^'\n']s",str);

        count = sscanf(str,"%s %s %s %s",command[0],command[1],command[2],command[3]);

        if(count == 1)
        {
            if(strcmp(command[0],"ls") == 0)
            {
                ls_file();
            }
            else if(strcmp(command[0],"closeall") == 0)
            {
                CloseAllFile();
                printf("All files closed successfully\n");
                continue;
            }
            else if(strcmp(command[0],"clear") == 0)
            {
                system("cls");
                continue;
            }
            else if(strcmp(command[0],"help") == 0)
            {
                DisplayHelp();
                continue;
            }
            else if(strcmp(command[0],"exit") == 0)
            {
                printf("Terminating the Customised Virtual File System......\n");
                break;
            }
            else
            {
                printf("\nERROR : Command not found !!!\n");
                continue;
            }
        }
        else if(count == 2)
        {
            if(strcmp(command[0],"stat") == 0)
            {
                ret = stat_file(command[1]);
                if(ret == -1)
                {
                    printf("ERROR : Incorrect parameters\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : There is no such file\n");
                }
                continue;
            }
            else if(strcmp(command[0],"fstat") == 0)
            {
                ret = fstat_file(atoi(command[1]));

                if(ret == -1)
                {
                    printf("ERROR : Incorrect parameters\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : There is no such file\n");
                }
                continue;
            }
            else if(strcmp(command[0],"close") == 0)
            {
                ret = CloseFileByName(command[1]);

                if(ret == -1)
                {
                    printf("ERROR : There is no such file\n");
                }
                continue;
            }
            else if(strcmp(command[0],"rm") == 0)
            {
                ret = rm_File(command[1]);

                if(ret == -1)
                {
                    printf("ERROR : There is no such file\n");
                }
                continue;
            }
            else if(strcmp(command[0],"man") == 0)
            {
                man(command[1]);
            }
            else if(strcmp(command[0],"write") == 0)
            {
                fd = GetFDFromName(command[1]);

                if(fd == -1)
                {
                    printf("ERROR : incorrect parameter\n");
                    continue;
                }
                printf("Enter the data : \n");
                scanf("%[^\n]",arr);

                ret = strlen(arr);

                if(ret == 0)
                {
                    printf("ERROR : Incorrect parameter\n");
                    continue;
                }
                ret = WriteFile(fd,arr,ret);

                if(ret == -1)
                {
                    printf("ERROR : Permission denied\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : There is no sufficient memory to write\n");
                }
                if(ret == -3)
                {
                    printf("ERROR : It is not regular file\n");
                }
            }
            else if(strcmp(command[0],"truncate") == 0)
            {
                ret = truncate_File(command[1]);

                if(ret == -1)
                {
                    printf("ERROR : Incorrect parameter\n");
                }
            }
            else
            {
                printf("\nERROR : Command not found !!!\n");
                continue;
            }
        }
        else if(count == 3)
        {
            if(strcmp(command[0],"create") == 0)
            {
                ret = CreateFile(command[1],atoi(command[2]));

                if(ret >= 0)
                {
                    printf("File is successfully created with file descriptor : %d\n",ret);
                }
                if(ret == -1)
                {
                    printf("ERROR : Incorrect parameter\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : There is no inodes\n");
                }
                if(ret == -3)
                {
                    printf("ERROR : File already exists\n");
                }
                if(ret == -4)
                {
                    printf("ERROR : Memory allocation failure\n");
                }
                continue;
            }
            else if(strcmp(command[0],"open") == 0)
            {
                ret = OpenFile(command[1],atoi(command[2]));

                if(ret >= 0)
                {
                    printf("File is successfully opened with file descriptor : %d\n",ret);
                }
                if(ret == -1)
                {
                    printf("ERROR : Incorrect paramenters\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : File not present\n");
                }
                if(ret == -3)
                {
                    printf("ERROR : Permisson denied\n");
                }
                continue;
            }
            else if(strcmp(command[0],"read") == 0)
            {
                fd = GetFDFromName(command[1]);

                if(fd == -1)
                {
                    printf("ERROR : Incorrect parameter\n");
                    continue;
                }

                ptr = (char *)malloc(sizeof(atoi(command[2]))+1);

                if(ptr == NULL)
                {
                    printf("ERROR : Memory allocation failure\n");
                    continue;
                }

                ret = ReadFile(fd,ptr,atoi(command[2]));

                if(ret == -1)
                {
                    printf("ERROR : File not exisiting\n");
                }
                if(ret == -2)
                {
                    printf("ERROR : Permission denied\n");
                }
                if(ret == -3)
                {
                    printf("ERROR : Reached at end of file\n");
                }
                if(ret == -4)
                {
                    printf("ERROR : It is not regular file\n");
                }
                if(ret == 0)
                {
                    printf("ERROR : File empty\n");
                }
                if(ret > 0)
                {
                    write(2,ptr,ret);
                }
                continue;
            }
            else
            {
                printf("\nERROR : Command not found !!!\n");
                continue;
            }
        }
        else if(count == 4)
        {
            if(strcmp(command[0],"lseek") == 0)
            {
                fd = GetFDFromName(command[1]);

                if(fd == -1)
                {
                    printf("ERROR : Incorrect parameter\n");
                    continue;
                }

                ret = LseekFile(fd,atoi(command[2]),atoi(command[3]));

                if(ret == -1)
                {
                    printf("ERROR : Unable to perfom lseek\n");
                }
            }
            else
            {
                printf("\nERROR : Command not found !!!\n");
                continue;
            }
        }
        else
        {
            printf("\nERROR : Command not found !!!\n");
            continue;
        }
    }
    return 0;
}
