#include <iostream>
#include<fstream>
using namespace std;
  ifstream f("numere.txt");
  struct nod {
   int val;
   nod *next;
  };

   void citire_lista (nod *&prim, nod *&ultim)
   {  int n;
    f>>n;
         nod *p;
      int x,i=0;
     while(i<n)
    {   f>>x;
        p=new nod;
        p->val=x;
       p->next=NULL;
       if(prim==NULL)
        prim=ultim=p;
       else
        {  ultim->next=p;
           ultim=p;
        }
       i++;
    }

  cout<<"Citire reusita\n";

   }

   void afisare(nod *&prim)
{
    nod *p;
    p=prim;
    while(p!=NULL)
    {
        cout<<p->val<<"  ";
        p=p->next;

    }
    cout<<"\n";
}


void inversare_lista_metoda1 (nod *&prim, nod *&prim1,nod *&ultim1)
{  nod *p, *q;
   p=prim;

   while(p!=NULL)
   {    q=new nod;
       q->val=p->val;
       if(prim1==NULL)
        {   q->next=NULL;
            prim1=ultim1=q;}
       else
       {  q->next=prim1;
          prim1=q;

       }
       p=p->next;


   }


}

 void inversare_lista_metoda2(nod *&prim, nod *&ultim)
 {
     nod *q, *p,*aux;

       q=ultim;
       while(q!=prim)
       {   p=prim;
         while(p->next!=q)
        p=p->next;

       q->next=p;
       if(q==ultim)
       aux=q;

       q=p;

       }
       q->next=NULL;


 }


 void interclasare_liste(nod *&prim, nod *&prim2, nod *&primc, nod *&ultimc)
 {
     nod *p=prim, *q=prim2, *c;
  cout<<"Interclasare\n";
      while(p!=NULL&&q!=NULL)
      {
          if(p->val<=q->val)
          {
              c=new nod;
              c->val=p->val;
              c->next=NULL;
              if(primc==NULL)
                primc=ultimc=c;
              else
              {
                  ultimc->next=c;
                  ultimc=c;
              }
              p=p->next;
          }
          else
          {
               c=new nod;
              c->val=q->val;
              c->next=NULL;
              if(primc==NULL)
                primc=ultimc=c;
              else
              {
                  ultimc->next=c;
                  ultimc=c;
              }
              q=q->next;

          }



      }


      while(p!=NULL)
      {
           c=new nod;
              c->val=p->val;
              c->next=NULL;
              if(primc==NULL)
                primc=ultimc=c;
              else
              {
                  ultimc->next=c;
                  ultimc=c;
              }
              p=p->next;

      }
      while(q!=NULL)
      {

               c=new nod;
              c->val=q->val;
              c->next=NULL;
              if(primc==NULL)
                primc=ultimc=c;
              else
              {
                  ultimc->next=c;
                  ultimc=c;
              }
              q=q->next;
      }


 }

void creareListe_pare_impare(nod *&primc, nod *&primP, nod *&ultimP, nod *&primI, nod *&ultimI)
{
    nod *p=primc, *par, *imp;
     int i=1;
    while(p!=NULL)
    {
        if(i%2==0)
        {
           par= new nod;
           par->val=p->val;

           par->next=NULL;

           if(primP==NULL)
            {primP=ultimP=par;}
           else
            {ultimP->next=par;
            ultimP=par;}


        }
         else
            if(i%2!=0)
         {
              imp= new nod;
           imp->val=p->val;
           imp->next=NULL;
           if(primI==NULL)
            primI=ultimI=imp;
           else
            {ultimI->next=imp;
            ultimI=imp;}

         }
         p=p->next;
         i++;
    }



}




struct coloane
{
    int x, j;
    struct coloane *next3;

};

struct linii
{
    int i;

    struct linii *next1;
    struct coloane *next2;

};



void citire_matrice(linii *&priml1, linii *&ultiml1, int n, int m)
{
    cout<<"Citire matrice\n";
    linii *l;
    coloane *c;

    int i,j,x;

    for(i=0;i<n;i++)
      {
          int ok=0; struct coloane *ultimc=NULL;
          for(j=0;j<m;j++)
          {
              f>>x;
            if(x!=0&&ok==0)
            {
                 l=new linii;
              l->i=i;
              l->next1=NULL;
              l->next2=NULL;
              if(priml1==NULL)
              priml1=ultiml1=l;
              else
                { ultiml1->next1=l; ultiml1=l;}
              ok=1;

              c=new coloane;
                c->j=j;
                c->x=x;
                c->next3=NULL;

                if(l->next2==NULL)
                    {l->next2=c;
                    ultimc=c;
                      }
                else
                {
                    ultimc->next3=c;
                    ultimc=c;
                }
            }
            else
             if(x!=0)
            {

                c=new coloane;
                c->j=j;
                c->x=x;
                c->next3=NULL;

                if(l->next2==NULL)
                    {l->next2=c;
                    ultimc=c;
                      }
                else
                {
                    ultimc->next3=c;
                    ultimc=c;
                }

            }

        }


      }


}

void afisare_suma_matrici (struct linii *&priml1, struct linii *&priml2 ,int n1, int m1) /// calcul la afisare
{   cout<<"Afisare suma matrici:\n\n";
    struct linii *l1=priml1, *l2=priml2;
   struct coloane *c1, *c2;
    int i,j;

    for(i=0;i<n1;i++)
    {  if(i<l1->i&&i<l2->i)
          { for(j=0;j<m1;j++)
              cout<<"|"<<0<<"|";

          }
          else
          {
               if(i<l1->i)
              {  c2=l2->next2;
                for(j=0;j<m1;j++)
                  if(j==c2->j)
                   {cout<<"|"<<c2->x<<"|"; if(c2->next3!=NULL)c2=c2->next3;}
                   else
                    cout<<"|"<<0<<"|";
                 l2=l2->next1;
                }

                if(i<l2->i)
              {
                  c1=l1->next2;
                for(j=0;j<m1;j++)
                  if(j==c1->j)
                   {cout<<"|"<<c1->x<<"|"; if(c1->next3!=NULL)c1=c1->next3;}
                   else
                    cout<<"|"<<0<<"|";
                    l1=l1->next1;
                }



             if(i==l1->i&&i==l2->i)
             {
                 c1=l1->next2;
               c2=l2->next2;
               for(j=0;j<m1;j++)
               {


                 if(j<c1->j&&j<c2->j)
                    cout<<"|"<<0<<"|";
                  else
                    if(j>c1->j&&j>c2->j)
                           cout<<"|"<<0<<"|";
                   else
                    {
                        if(j<c1->j)
                        {cout<<"|"<<c2->x<<"|"; if(c2->next3!=NULL)c2=c2->next3;}
                      else
                        if(j<c2->j)
                            {cout<<"|"<<c1->x<<"|"; if(c1->next3!=NULL)c1=c1->next3;}
                           else
                           {
                            if(j==c1->j&&j==c2->j)
                             {cout<<"|"<<c1->x+c2->x<<"|";
                               if (c1->next3!=NULL&&c2->next3!=NULL)
                                {c2=c2->next3; c1=c1->next3;}

                               }
                            }
                    }
               }
                l1=l1->next1;
             l2=l2->next1;
             }



          }
          cout<<"\n";
}

}


void afisare_matrice(struct linii *&priml)
{
    cout<<"Itrat\nMatrice:\n";
     struct linii *l;
     struct coloane *c;
    l=priml;

    while(l!=NULL)
    {  c=l->next2;
        while(c!=NULL)
        {  cout<<" | "<<"Linia "<<l->i<<" cu elem "<<c->x<<" | ";
            c=c->next3;
        }
        cout<<"\n";
        l=l->next1;
    }
cout<<"\n";

}

int main()
{
    struct nod *prim=NULL, *ultim=NULL, *prim1=NULL, *ultim1=NULL, *prim2=NULL, *ultim2=NULL, *primc=NULL, *ultimc=NULL, *primP=NULL, *ultimP=NULL, *primI=NULL, *ultimI=NULL;
    struct linii *priml1=NULL, *ultiml1=NULL, *priml2=NULL, *ultiml2=NULL;
     citire_lista(prim,ultim);
     cout<<"Lista 1: ";
     afisare(prim);
     citire_lista(prim2,ultim2);
      cout<<"Lista 2: ";
     afisare(prim2);

     interclasare_liste(prim,prim2,primc,ultimc);
      cout<<"Lista obtinuta prin interclasare: ";
     afisare(primc);

     inversare_lista_metoda1(prim,prim1,ultim1);
      cout<<"Lista inversata met 1: ";
     afisare(prim1);

     inversare_lista_metoda2(prim,ultim);
      cout<<"Lista inversata met 2: ";
     afisare(ultim);

     inversare_lista_metoda2(ultim, prim);
      cout<<"Lista 1 initiala: ";
     afisare(prim);


      creareListe_pare_impare(primc,primP,ultimP,primI,ultimI);
       cout<<"Lista cu elem de pe pozitii pare: ";
      afisare(primP);
       cout<<"Lista cu elem de pe pozitii impare: ";
      afisare(primI);

      cout<<"\n";
      cout<<"\n";
      cout<<"\n";
      int n1,m1,n2,m2;
       f>>n1>>m1;
      citire_matrice(priml1,ultiml1,n1,m1);
      afisare_matrice(priml1);
        f>>n2>>m2;
      citire_matrice(priml2,ultiml2,n2,m2);
      afisare_matrice(priml2);

      afisare_suma_matrici(priml1,priml2,n1,m1);

      cout<<"Final";

    return 0;
}
