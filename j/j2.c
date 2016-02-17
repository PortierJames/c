// Based on http://www.jsoftware.com/jwiki/Essays/Incunabulum
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct a {
    long t;
    long r;
    long d[3];
    long p[2];
} *A;

#define DO(n,x) {                               \
        long i=0, _n=(n);                       \
        for(;i<_n;++i) {                        \
            x;                                  \
        }                                       \
    }

long * ma(n) {
    return malloc(n*4);
}

void mv(long *d, long *s, int n) {
    DO(n,d[i]=s[i]);
}

int tr(int r, long * d) {
    long z=1;
    DO(r,z=z*d[i]);
    return z;
}

A ga(int t, int r, long * d) {
    A z = (A)ma(5+tr(r,d));
    z->t = t;
    z->r = r;
    mv(z->d,d,r);
    return z;
}

A iota(A w) {
    long n = *w->p;
    A z = ga(0,1,&n);
    DO(n,z->p[i]=i);
    return z;
}

A plus(A a, A w) {
    long r = w->r;
    long *d = w->d;
    long n = tr(r,d);
    A z = ga(0,r,d);
    DO(n,z->p[i]=a->p[i]+w->p[i]);
    return z;
}

A from(A a, A w) {
    long r = w->r-1;
    long *d = w->d+1;
    long n = tr(r,d);
    A z = ga(w->t,r,d);
    mv(z->p,w->p+(n**a->p),n);
    return z;
}

A box(A w) {
    A z = ga(1,0,0);
    *z->p = (long)w;
    return z;
}

A cat(A a, A w) {
    long an = tr(a->r,a->d);
    long wn = tr(w->r,w->d);
    long n = an+wn;
    A z = ga(w->t,1,&n);
    mv(z->p,a->p,an);
    mv(z->p+an,w->p,wn);
    return z;
}

A find(A a, A w) {
}

A rsh(A a, A w) {
    long r = a->r ? *a->d : 1;
    long n = tr(r,a->p);
    long wn = tr(w->r,w->d);
    A z = ga(w->t,r,a->p);
    mv(z->p,w->p,wn=n>wn?wn:n);
    if(n -= wn)
        mv(z->p+wn,z->p,n);
    return z;
}

A sha(A w) {
    A z=ga(0,1,&w->r);
    mv(z->p,w->d,w->r);
    return z;
}

A id(A w) {
    return w;
}

A size(A w) {
    A z=ga(0,0,0);
    *z->p=w->r ? *w->d : 1;
    return z;
}

void print_integer(i) {
    printf("%d ",i);
}

void newline() {
    printf("\n");
}

pr(w) A w; {
    long r = w->r;
    long *d = w->d;
    long n = tr(r,d);
    DO(r,print_integer(d[i]));
    newline();
    if(w->t)
        DO(n,printf("< "); pr(w->p[i]))
    else
        DO(n,print_integer(w->p[i]));
    newline();
}

char vt[] = "+{~<#,";

A(*vd[])() = {0,plus,from,find,0,rsh,cat};
A(*vm[])() = {0,id,size,iota,box,sha,0};

long st[26];

int qp(int a) {
    return a >= 'a' && a<='z';
}

int qv(int a) {
    return a < 'a';
}

A ex(long *e) {
    long a = *e;
    if(qp(a)) {
        if(e[1] == '=') {
            st[a-'a'] = ex(e+2);
            return st[a-'a'];
        }
        a = st[a-'a'];
    }
    return qv(a) ? (*vm[a])(ex(e+1)) : e[1] ? (*vd[e[1]])(a,ex(e+2)) : (A)a;
}

int noun(int c) {
    if(c<'0' || c>'9')
        return 0;
    A z = ga(0,0,0);
    *z->p = c-'0';
    return z;
}

int verb(int c) {
    long i = 0;
    for(;vt[i];)
        if(vt[i++] == c)
            return i;
    return 0;
}

long * wd(char *s) {
    long a;
    long n = strlen(s);
    long *e = ma(n+1);
    char c;
    DO(n,e[i]=(a=noun(c=s[i]))?a:(a=verb(c))?a:c);
    e[n] = 0;
    return e;
}

int main() {
    char s[99];
    while(fgets(s,98,stdin))
        pr(ex(wd(s)));
}
