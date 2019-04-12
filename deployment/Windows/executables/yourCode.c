#include <stdio.h>
#include <string.h>

typedef long long az_int64_t;
typedef unsigned long long az_uint64_t;
#define I64(x) x ## ll
#define F64 "ll"

#define MAXN (100*1024)

int zlog2( az_uint64_t n )
{
  unsigned int v, num;
  int r = 0;

  if( (v = (unsigned int) (n >> 32)) != 0 )
    r += 32, num = v;
  else
    num = (unsigned int) n;
  if( (v = num >> 16) != 0 ) r += 16, num = v;
  if( (v = num >> 8) != 0 ) r += 8, num = v;
  if( (v = num >> 4) != 0 ) r += 4, num = v;
  if( (v = num >> 2) != 0 ) r += 2, num = v;
  if( (v = num >> 1) != 0 ) r++;

  return r;
}

struct item
{
  struct item *next;
  struct item *hnext;
  az_uint64_t num;
};

struct item storage[MAXN];
int cur;
struct item *hash[MAXN/10];

int has( struct item *item )
{
  int h = (int) (item->num % 10211);
  struct item *cur;
  for( cur = hash[h]; cur != NULL; cur = cur->hnext)
    if( item->num == cur->num ) return 1;
  item->hnext = hash[h];
  hash[h] = item;
  return 0;
}

struct item *basket[64];

void addItem( struct item *item )
{
  if( item->num != 0 )
  {
    int n = zlog2( item->num );
    item->next = basket[n];
    basket[n] = item;
  }
}

az_int64_t bt( int n )
{
  struct item *item;
  az_uint64_t num;

  if( n == 0 ) return (basket[0] == NULL) ? 0 : 1;
  if( basket[n] == NULL ) return bt( n-1 );

  num = basket[n]->num;
  item = basket[n]->next;
  while( item != NULL )
  {
    struct item *next = item->next;
    item->num ^= num;
    addItem( item );
    item = next;
  }

  return 2 * bt( n-1 ) + 1;
}

int main( void )
{
  int t;
  scanf( "%d", &t);
  while( t-- > 0 )
  {
    int i, n;
    az_int64_t ans;
    cur = 0;
    memset( hash, 0, sizeof(hash));
    scanf( "%d", &n);
    for( i = 0; i < 64; ++i) basket[i] = NULL;
    for( i = 0; i < n; ++i)
    {
      struct item *item = &storage[cur];
      az_uint64_t num = 0;
      char line[128], *s;
      scanf( "%s", line);
      for( s = line; *s != '\0'; ++s)
      {
        int c = *s;
        if( c >= 'a' && c <= 'z' )
          c -= 'a';
        else if( c >= 'A' && c <= 'Z' )
          c -= 'A' - 26;
        else
          c -= '0' - 52;
        num ^= I64(1u) << c;
      }
      if( (item->num = num) == 0 ) continue;
      if( !has( item ) ) addItem( item ), cur++;
    }
    if( (ans = bt( 63 ) - cur) < 0 ) ans = 0;
    printf( "%" F64 "d\n", ans);
  }
  return 0;
}
