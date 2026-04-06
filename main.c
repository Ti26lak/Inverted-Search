/*
Name : Machani Tilak
Reg no :25021_258
Starting Date :12-03-2026
Ending Date : 23-03-2026

Project Name : INVERTED SEARCH
Description : This project demonstrates how to create an inverted index, which is commonly used in search 
engines to map words to the documents.The purpose of storing an index is to optimize speed and performance in finding 
relevant documents for a search query. Without an index, the search engine would scan every document in the corpus, 
which would require considerable time and computing power.

An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its
locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow
fast full text searches, at the cost of increased processing when a document is added to the database. The inverted
file may be the database file itself, rather than its index. It is the most popular data structure used in document
retrieval systems, used on a large scale for example in search engines
*/
#include "types.h"

int main(int argc,char *argv[]){
    slist *head=NULL;
    slist *temp = head;
    hash_t hash[28];

    for(int i = 0; i < 28; i++)
        hash[i].link = NULL;

    // Step 1: Read and validate input files
    if (read_and_validate(argc, argv, &head) == FAILURE){
        printf("File validation failed....\n");
        return 0;
    }

    printf("\nFiles validated and added to linked list successfully.\n");
    int choice;
    char filename[50];
    char backup[50];
    char cont = 'y';

    while(cont == 'y' || cont == 'Y'){
        printf("\n1.Create DATABASE\n");
        printf("2.Display Database\n");
        printf("3.Save DATABASE\n");
        printf("4.Search\n");
        printf("5.Update DATABASE\n");
        printf("6.Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the file name: ");
                scanf("%s", filename);
                create_database(hash, filename);
                break;

            case 2:
                display_database(hash);
                break;

            case 3:
                printf("Enter the file name to save database: ");
                scanf("%s", backup);
                save_database(hash, backup);
                break;
            case 4:
                search_word(hash);
                break;
            case 5: {
                char word[50];
                char file_name[50];

                printf("Enter the word to update: ");
                scanf("%s", word);

                printf("Enter the file name where the word is found: ");
                scanf("%s", file_name);

                int size = 28;  // number of buckets in your hash table

                update_database(hash, size, word, file_name);
                printf("Database updated successfully.\n");
                break;
            }
            
            case 6:
                printf("Exit\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue??? Enter Y/y to continue: ");
        scanf(" %c", &cont);
    }
    return 0;
}