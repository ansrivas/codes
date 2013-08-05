
#include <stdio.h>
#include <stdlib.h>
#include "indxlook.h"                 

struct tree_node                      /* node in tree */
{
   struct tree_node *l_ptr, *r_ptr;   /* left and right pointers */
   INDEX *data_ptr;                   /* data pointer */
};

typedef struct tree_node TREE_NODE;

void        write_index(char *txtfile, char *ndxfile);
void        save_tree(TREE_NODE * root, FILE *fp);
TREE_NODE  *make_tree(FILE *fp, long *cnt_ptr);
TREE_NODE  *insert_tree(TREE_NODE *root, INDEX *rec_ptr, long *cnt_ptr);
long        bsearch_file(FILE *ifp, long first, long last, char *target);

int main(int argc, char *argv[])
{
      if (argc != 3)
      {
            puts("Usage: INDEX text_file_name index_file_name\n");
            puts("Note: The text file must consist of a number of records "
                 "separated by lines");
            puts("      containing a single period (\".\")");
            return EXIT_FAILURE;
      }
      write_index(argv[1], argv[2]);
      return EXIT_SUCCESS;
}

void write_index(char *txtfile, char *ndxfile)
{
      FILE *afp, *ifp;                    /* types of files       */
      TREE_NODE *root;                    
      static INDEX header = {"!", 0};    

      afp = fopen(txtfile, "r");
      if ((root = make_tree(afp, &header.pos)) != NULL)
      {
            ifp = fopen(ndxfile, "wb");
            fwrite(&header, sizeof(header), 1, ifp);
            save_tree(root, ifp);
            fclose(ifp);
            printf("\n%ld records\n", header.pos);
      }
      fclose(afp);
}


TREE_NODE *make_tree(FILE *fp,            /* file                 */
                     long *cnt_ptr)       /* count of records     */
{
      TREE_NODE *root, *temp_ptr;  
      char line[MAX_LINE];                
      long start_pos = 0;
      INDEX *next_ptr;                    
      Boolean_T new_record = True_, have_mem;

      *cnt_ptr = 0;
      while (start_pos = ftell(fp), have_mem && fgets(line,sizeof(line), fp))
      {
            if (new_record)
            {
                  if ((next_ptr = (INDEX *) malloc(sizeof(INDEX))) != NULL)
                  {
                        strncpy(next_ptr->key, line, MAX_KEY);

                        next_ptr->pos = start_pos;
                        temp_ptr      = insert_tree(root, next_ptr, cnt_ptr);

                        if (temp_ptr)
                              root = temp_ptr;
                  }
                  have_mem = next_ptr && temp_ptr;
            }
            new_record = strcmp(line, END_REC) == 0;
      }
      if (!have_mem)
            fprintf(stderr, "Out of memory. Key: %s\n", line);

      return root;
}


void save_tree(TREE_NODE *root, FILE *fp)
{
      if (root)
      {
            save_tree(root->l_ptr, fp);
            fwrite(root->data_ptr, sizeof(INDEX), 1, fp);
            save_tree(root->r_ptr, fp);
      }
}


TREE_NODE *insert_tree(TREE_NODE *root,         /* pointer to tree      */
                       INDEX *rec_ptr,          /* record to install    */
                       long *cnt_ptr)           /* nodes in tree        */

{
      if (root)
      {
            int cmp = strncmp(rec_ptr->key, root->data_ptr->key, MAX_KEY);

            if (cmp < 0)                        /* left side?           */
                  root->l_ptr = insert_tree(root->l_ptr, rec_ptr, cnt_ptr);
            else if (cmp > 0)                   /* right side           */
                  root->r_ptr = insert_tree(root->r_ptr, rec_ptr, cnt_ptr);
            else  fprintf(stderr, "Duplicate key: %s\n", rec_ptr->key);
      }
      else if (root = (TREE_NODE *) malloc(sizeof(TREE_NODE)), root)
      {
            root->data_ptr = rec_ptr;
            root->l_ptr = root->r_ptr = NULL;
      }
      return root;
}

long bsearch_file(FILE *ifp, long first, long last, char *target)
{
      long pos, mid =(first + last) / 2;
      INDEX next;
      int cmp;

      if (mid < first || fseek(ifp, mid * sizeof(INDEX), 0) != 0 ||
          fread(&next, sizeof(INDEX), 1, ifp) == 0)
      {
            pos = -1;
      }
      else  pos = ((cmp = strncmp(target, next.key, MAX_KEY)) == 0) ?
                  next.pos :
                  ((cmp < 0) ? bsearch_file(ifp, first, mid - 1, target)
                             : bsearch_file(ifp, mid + 1, last, target));
      return pos;
}


