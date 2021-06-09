typedef unsigned long uintmax_t;
enum strtol_error {
  LONGINT_OK = 0,
  LONGINT_OVERFLOW = 1,
  LONGINT_INVALID_SUFFIX_CHAR = 2,
  LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
  LONGINT_INVALID = 4
};
typedef enum strtol_error strtol_error;
typedef long intmax_t;
typedef unsigned long size_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;
typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
enum quoting_style {
  literal_quoting_style = 0,
  shell_quoting_style = 1,
  shell_always_quoting_style = 2,
  c_quoting_style = 3,
  escape_quoting_style = 4,
  locale_quoting_style = 5,
  clocale_quoting_style = 6
};
typedef long ptrdiff_t;
typedef unsigned short __u_short;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef __u_short u_short;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __nlink_t nlink_t;
struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
struct stat {
  __dev_t st_dev;
  __ino_t st_ino;
  __nlink_t st_nlink;
  __mode_t st_mode;
  __uid_t st_uid;
  __gid_t st_gid;
  int __pad0;
  __dev_t st_rdev;
  __off_t st_size;
  __blksize_t st_blksize;
  __blkcnt_t st_blocks;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  __syscall_slong_t __glibc_reserved[3];
};
struct dev_ino {
  ino_t st_ino;
  dev_t st_dev;
};
struct cycle_check_state {
  struct dev_ino dev_ino;
  size_t chdir_counter;
  unsigned long magic;
};
struct _ftsent;
struct _ftsent;
struct __anonstruct_FTS_26 {
  struct _ftsent *fts_cur;
  struct _ftsent *fts_child;
  struct _ftsent **fts_array;
  dev_t fts_dev;
  char *fts_path;
  int fts_rfd;
  size_t fts_pathlen;
  int fts_nitems;
  int (*fts_compar)(void const *, void const *);
  int fts_options;
  Hash_table *active_dir_ht;
  struct cycle_check_state *cycle_state;
};
typedef struct __anonstruct_FTS_26 FTS;
struct _ftsent {
  struct _ftsent *fts_cycle;
  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;
  long fts_number;
  void *fts_pointer;
  char *fts_accpath;
  char *fts_path;
  int fts_errno;
  int fts_symfd;
  size_t fts_pathlen;
  ino_t fts_ino;
  dev_t fts_dev;
  nlink_t fts_nlink;
  int fts_level;
  u_short fts_namelen;
  u_short fts_info;
  u_short fts_flags;
  u_short fts_instr;
  struct stat *fts_statp;
  char fts_name[1];
};
typedef struct _ftsent FTSENT;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef long __off64_t;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
struct _IO_FILE {
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[(15UL * sizeof(int) - 4UL * sizeof(void *)) - sizeof(size_t)];
};
typedef int wchar_t;
typedef unsigned int wint_t;
enum __anonenum_arg_type_26 {
  TYPE_NONE = 0,
  TYPE_SCHAR = 1,
  TYPE_UCHAR = 2,
  TYPE_SHORT = 3,
  TYPE_USHORT = 4,
  TYPE_INT = 5,
  TYPE_UINT = 6,
  TYPE_LONGINT = 7,
  TYPE_ULONGINT = 8,
  TYPE_LONGLONGINT = 9,
  TYPE_ULONGLONGINT = 10,
  TYPE_DOUBLE = 11,
  TYPE_LONGDOUBLE = 12,
  TYPE_CHAR = 13,
  TYPE_WIDE_CHAR = 14,
  TYPE_STRING = 15,
  TYPE_WIDE_STRING = 16,
  TYPE_POINTER = 17,
  TYPE_COUNT_SCHAR_POINTER = 18,
  TYPE_COUNT_SHORT_POINTER = 19,
  TYPE_COUNT_INT_POINTER = 20,
  TYPE_COUNT_LONGINT_POINTER = 21,
  TYPE_COUNT_LONGLONGINT_POINTER = 22
};
typedef enum __anonenum_arg_type_26 arg_type;
union __anonunion_a_28 {
  signed char a_schar;
  unsigned char a_uchar;
  short a_short;
  unsigned short a_ushort;
  int a_int;
  unsigned int a_uint;
  long a_longint;
  unsigned long a_ulongint;
  long long a_longlongint;
  unsigned long long a_ulonglongint;
  float a_float;
  double a_double;
  long double a_longdouble;
  int a_char;
  wint_t a_wide_char;
  char const *a_string;
  wchar_t const *a_wide_string;
  void *a_pointer;
  signed char *a_count_schar_pointer;
  short *a_count_short_pointer;
  int *a_count_int_pointer;
  long *a_count_longint_pointer;
  long long *a_count_longlongint_pointer;
};
struct __anonstruct_argument_27 {
  arg_type type;
  union __anonunion_a_28 a;
};
typedef struct __anonstruct_argument_27 argument;
struct __anonstruct_arguments_29 {
  unsigned int count;
  argument *arg;
};
typedef struct __anonstruct_arguments_29 arguments;
struct __anonstruct_char_directive_30 {
  char const *dir_start;
  char const *dir_end;
  int flags;
  char const *width_start;
  char const *width_end;
  int width_arg_index;
  char const *precision_start;
  char const *precision_end;
  int precision_arg_index;
  char conversion;
  int arg_index;
};
typedef struct __anonstruct_char_directive_30 char_directive;
struct __anonstruct_char_directives_31 {
  unsigned int count;
  char_directive *dir;
  unsigned int max_width_length;
  unsigned int max_precision_length;
};
typedef struct __anonstruct_char_directives_31 char_directives;
typedef long __suseconds_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
typedef __gid_t gid_t;
typedef __uid_t uid_t;
struct passwd {
  char *pw_name;
  char *pw_passwd;
  __uid_t pw_uid;
  __gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};
struct group {
  char *gr_name;
  char *gr_passwd;
  __gid_t gr_gid;
  char **gr_mem;
};
typedef void *iconv_t;
struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long tm_gmtoff;
  char const *tm_zone;
};
union __anonunion___value_16 {
  unsigned int __wch;
  char __wchb[4];
};
struct __anonstruct___mbstate_t_15 {
  int __count;
  union __anonunion___value_16 __value;
};
typedef struct __anonstruct___mbstate_t_15 __mbstate_t;
typedef __mbstate_t mbstate_t;
struct numname {
  int num;
  char const name[8];
};
typedef unsigned int md5_uint32;
typedef unsigned long md5_uintptr;
struct sha_ctx {
  md5_uint32 A;
  md5_uint32 B;
  md5_uint32 C;
  md5_uint32 D;
  md5_uint32 E;
  md5_uint32 total[2];
  md5_uint32 buflen;
  char buffer[128];
};
typedef int __clockid_t;
typedef __clockid_t clockid_t;
struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};
struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
};
struct __dirstream;
struct __dirstream;
typedef struct __dirstream DIR;
struct saved_cwd {
  int desc;
  char *name;
};
typedef int __int32_t;
typedef int __pid_t;
struct __exit_status {
  short e_termination;
  short e_exit;
};
struct __anonstruct_ut_tv_27 {
  __int32_t tv_sec;
  __int32_t tv_usec;
};
struct utmpx {
  short ut_type;
  __pid_t ut_pid;
  char ut_line[32];
  char ut_id[4];
  char ut_user[32];
  char ut_host[256];
  struct __exit_status ut_exit;
  __int32_t ut_session;
  struct __anonstruct_ut_tv_27 ut_tv;
  __int32_t ut_addr_v6[4];
  char __glibc_reserved[20];
};
typedef struct utmpx STRUCT_UTMP;
struct tokenbuffer {
  long size;
  char *buffer;
};
typedef struct tokenbuffer token_buffer;
struct quoting_options;
struct quoting_options;
struct quoting_options {
  enum quoting_style style;
  int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
};
struct slotvec {
  size_t size;
  char *val;
};
typedef __off_t off_t;
struct mntent {
  char *mnt_fsname;
  char *mnt_dir;
  char *mnt_type;
  char *mnt_opts;
  int mnt_freq;
  int mnt_passno;
};
struct mount_entry {
  char *me_devname;
  char *me_mountdir;
  char *me_type;
  dev_t me_dev;
  unsigned int me_dummy : 1;
  unsigned int me_remote : 1;
  unsigned int me_type_malloced : 1;
  struct mount_entry *me_next;
};
typedef __mode_t mode_t;
struct mode_change {
  char op;
  char flags;
  mode_t affected;
  mode_t value;
  struct mode_change *next;
};
struct md5_ctx {
  md5_uint32 A;
  md5_uint32 B;
  md5_uint32 C;
  md5_uint32 D;
  md5_uint32 total[2];
  md5_uint32 buflen;
  char buffer[128];
};
struct ptr_list {
  char *dirname_end;
  struct ptr_list *next;
};
struct option {
  char const *name;
  int has_arg;
  int *flag;
  int val;
};
typedef int nl_item;
struct linebuffer {
  size_t size;
  size_t length;
  char *buffer;
};
union __anonunion_id_22 {
  uid_t u;
  gid_t g;
};
struct userid {
  union __anonunion_id_22 id;
  char *name;
  struct userid *next;
};
struct lconv {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};
struct hash_entry {
  void *data;
  struct hash_entry *next;
};
struct hash_tuning {
  float shrink_threshold;
  float shrink_factor;
  float growth_threshold;
  float growth_factor;
  _Bool is_n_buckets;
};
typedef struct hash_tuning Hash_tuning;
struct hash_table {
  struct hash_entry *bucket;
  struct hash_entry const *bucket_limit;
  size_t n_buckets;
  size_t n_buckets_used;
  size_t n_entries;
  Hash_tuning const *tuning;
  size_t (*hasher)(void const *, size_t);
  _Bool (*comparator)(void const *, void const *);
  void (*data_freer)(void *);
  struct hash_entry *free_entry_list;
};
typedef struct timezone *__restrict __timezone_ptr_t;
struct __anonstruct_textint_22 {
  int value;
  int digits;
};
typedef struct __anonstruct_textint_22 textint;
struct __anonstruct_table_23 {
  char const *name;
  int type;
  int value;
};
typedef struct __anonstruct_table_23 table;
struct __anonstruct_parser_control_25 {
  char const *input;
  int day_ordinal;
  int day_number;
  int local_isdst;
  int time_zone;
  int meridian;
  textint year;
  int month;
  int day;
  int hour;
  int minutes;
  int seconds;
  int rel_year;
  int rel_month;
  int rel_day;
  int rel_hour;
  int rel_minutes;
  int rel_seconds;
  int dates_seen;
  int days_seen;
  int local_zones_seen;
  int rels_seen;
  int times_seen;
  int zones_seen;
  table local_time_zone_table[3];
};
typedef struct __anonstruct_parser_control_25 parser_control;
union YYSTYPE {
  int intval;
  textint textintval;
};
typedef union YYSTYPE YYSTYPE;
union yyalloc {
  short yyss;
  YYSTYPE yyvs;
};
typedef signed char yysigned_char;
typedef unsigned int __u_int;
typedef __u_int u_int;
struct Active_dir {
  dev_t dev;
  ino_t ino;
  FTSENT *fts_ent;
};
struct __anonstruct___fsid_t_2 {
  int __val[2];
};
typedef struct __anonstruct___fsid_t_2 __fsid_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsfilcnt_t;
typedef long __fsword_t;
struct fs_usage {
  int fsu_blocksize;
  uintmax_t fsu_blocks;
  uintmax_t fsu_bfree;
  uintmax_t fsu_bavail;
  int fsu_bavail_top_bit_set;
  uintmax_t fsu_files;
  uintmax_t fsu_ffree;
};
struct statfs {
  __fsword_t f_type;
  __fsword_t f_bsize;
  __fsblkcnt_t f_blocks;
  __fsblkcnt_t f_bfree;
  __fsblkcnt_t f_bavail;
  __fsfilcnt_t f_files;
  __fsfilcnt_t f_ffree;
  __fsid_t f_fsid;
  __fsword_t f_namelen;
  __fsword_t f_frsize;
  __fsword_t f_flags;
  __fsword_t f_spare[4];
};
struct exclude;
struct exclude;
struct patopts {
  char const *pattern;
  int options;
};
struct exclude {
  struct patopts *exclude;
  size_t exclude_alloc;
  size_t exclude_count;
};
typedef unsigned int __socklen_t;
typedef unsigned int uint32_t;
typedef uint32_t in_addr_t;
struct in_addr {
  in_addr_t s_addr;
};
struct hostent {
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  int h_length;
  char **h_addr_list;
};
enum backup_type { none = 0, simple = 1, numbered_existing = 2, numbered = 3 };
extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     rpmatch)(char const *response);
extern int getchar_unlocked(void);
extern __attribute__((__nothrow__))
uintmax_t(__attribute__((__leaf__)) strtoumax)(char const *__restrict __nptr,
                                               char **__restrict __endptr,
                                               int __base);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((
    __leaf__)) __assert_fail)(char const *__assertion, char const *__file,
                              unsigned int __line, char const *__function);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1),
                                                          __leaf__))
                                           strchr)(char const *__s, int __c)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) unsigned long(__attribute__((
    __nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr,
                                        char **__restrict __endptr, int __base);
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes);

extern
    __attribute__((__nothrow__)) long(__attribute__((__nonnull__(1), __leaf__))
                                      strtol)(char const *__restrict __nptr,
                                              char **__restrict __endptr,
                                              int __base);
extern __attribute__((__nothrow__))
intmax_t(__attribute__((__leaf__)) strtoimax)(char const *__restrict __nptr,
                                              char **__restrict __endptr,
                                              int __base);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__))
    strndup)(char const *__string, size_t __n) __attribute__((__malloc__));
__attribute__((__noreturn__)) void xalloc_die(void);
extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s)
    __attribute__((__pure__));
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) rpl_free)(void *p);
extern __attribute__((__nothrow__))
ssize_t(__attribute__((__nonnull__(1, 2), __leaf__))
        readlink)(char const *__restrict __path, char *__restrict __buf,
                  size_t __len);
void *xmalloc(size_t n);
extern int nanosleep(struct timespec const *__requested_time,
                     struct timespec *__remaining);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           gettext)(char const *__msgid)
    __attribute__((__format_arg__(1)));
extern void error(int __status, int __errnum, char const *__format, ...);
int volatile exit_failure;

void *xrealloc(void *p, size_t n);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__))
                                           malloc)(size_t __size)
    __attribute__((__malloc__));
extern
    __attribute__((__nothrow__)) void *(__attribute__((__leaf__))
                                        calloc)(size_t __nmemb, size_t __size)
        __attribute__((__malloc__));
extern
    __attribute__((__nothrow__)) void *(__attribute__((__warn_unused_result__,
                                                       __leaf__))
                                        realloc)(void *__ptr, size_t __size);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__))
                                                       abort)(void);
extern __attribute__((__nothrow__)) void *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    memcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern
    __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1),
                                                       __leaf__))
                                        memset)(void *__s, int __c, size_t __n);

char const xalloc_msg_memory_exhausted[17] = {
    (char const)'m',   (char const)'e', (char const)'m', (char const)'o',
    (char const)'r',   (char const)'y', (char const)' ', (char const)'e',
    (char const)'x',   (char const)'h', (char const)'a', (char const)'u',
    (char const)'s',   (char const)'t', (char const)'e', (char const)'d',
    (char const)'\000'};
__attribute__((__noreturn__)) void xalloc_die(void);
void xalloc_die(void) {
  char *tmp;

  {

    tmp = gettext(xalloc_msg_memory_exhausted);
    error((int)exit_failure, 0, "%s", tmp);
  }
}

extern int gethostname();
__attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                    rpl_getcwd)(char *buf, size_t size);
char *xgetcwd(void);

char const *quote(char const *name);
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format,
                   ...);
extern int vfprintf(FILE *__restrict __s, char const *__restrict __format,
                    __gnuc_va_list __arg);
extern int putc_unlocked(int __c, FILE *__stream);
extern int fputs_unlocked(char const *__restrict __s,
                          FILE *__restrict __stream);

void version_etc_va(FILE *stream, char const *command_name, char const *package,
                    char const *version, va_list authors);
void version_etc(FILE *stream, char const *command_name, char const *package,
                 char const *version, ...);

extern __attribute__((__nothrow__)) int
snprintf(char *__restrict __s, size_t __maxlen, char const *__restrict __format,
         ...);
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     utimes)(char const *__file,
                                             struct timeval const *__tvp);
extern __attribute__((__nothrow__)) int
sprintf(char *__restrict __s, char const *__restrict __format, ...);
extern void endpwent(void);
extern struct passwd *getpwnam(char const *__name);
extern void endgrent(void);
extern struct group *getgrgid(__gid_t __gid);
extern struct group *getgrnam(char const *__name);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcpy)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1),
                                                          __leaf__))
                                           strdup)(char const *__s)
    __attribute__((__malloc__));

extern size_t fwrite(void const *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcmp)(char const *__s1, char const *__s2) __attribute__((__pure__));
extern iconv_t iconv_open(char const *__tocode, char const *__fromcode);
extern size_t iconv(iconv_t __cd, char **__restrict __inbuf,
                    size_t *__restrict __inbytesleft,
                    char **__restrict __outbuf,
                    size_t *__restrict __outbytesleft);

extern __attribute__((__nothrow__)) struct tm *(__attribute__((__leaf__))
                                                gmtime)(time_t const *__timer);
extern
    __attribute__((__nothrow__)) struct tm *(__attribute__((__leaf__))
                                             localtime)(time_t const *__timer);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           asctime)(struct tm const *__tp);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           ctime)(time_t const *__timer);
char *base_name(char const *name);
size_t base_len(char const *name);
int strip_trailing_slashes(char *path);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        tolower)(int __c);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        toupper)(int __c);
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__)) strftime)(char *__restrict __s,
                                           size_t __maxsize,
                                           char const *__restrict __format,
                                           struct tm const *__restrict __tp);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        mbsinit)(mbstate_t const *__ps)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__)) mbrlen)(char const *__restrict __s, size_t __n,
                                         mbstate_t *__restrict __ps);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        __libc_current_sigrtmin)(void);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        __libc_current_sigrtmax)(void);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strncmp)(char const *__s1, char const *__s2, size_t __n)
    __attribute__((__pure__));

extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
                             FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        feof_unlocked)(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        ferror_unlocked)(FILE *__stream);

extern
    __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                     settimeofday)(struct timeval const *__tv,
                                                   struct timezone const *__tz);
extern
    __attribute__((__nothrow__)) int(__attribute__((__leaf__)) clock_settime)(
        clockid_t __clock_id, struct timespec const *__tp);
extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
extern int close(int __fd);
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     chdir)(char const *__path);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        fchdir)(int __fd);
extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag, ...);
int save_cwd(struct saved_cwd *cwd);
int restore_cwd(struct saved_cwd const *cwd);
void free_cwd(struct saved_cwd *cwd);

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    stat)(char const *__restrict __file, struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    memcmp)(void const *__s1, void const *__s2, size_t __n)
    __attribute__((__pure__));
int same_name(char const *source, char const *dest);
char *dir_name(char const *path);

extern ssize_t write(int __fd, void const *__buf, size_t __n);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    lstat)(char const *__restrict __file, struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strncpy)(char *__restrict __dest, char const *__restrict __src, size_t __n);
extern void setutxent(void);
extern void endutxent(void);
extern struct utmpx *getutxent(void);
extern int utmpxname(char const *__file);
extern int getc_unlocked(FILE *__stream);

int set_char_quoting(struct quoting_options *o, char c, int i);
size_t quotearg_buffer(char *buffer, size_t buffersize, char const *arg,
                       size_t argsize, struct quoting_options const *o);
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char *quotearg_char(char const *arg, char ch);
char *quotearg_colon(char const *arg);
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__)) __ctype_get_mb_cur_max)(void);
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__))
       mbrtowc)(wchar_t *__restrict __pwc, char const *__restrict __s,
                size_t __n, mbstate_t *__restrict __p);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        iswprint)(wint_t __wc);

static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options);

char const *quote_n(int n, char const *name);

extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1),
                                                          __leaf__))
                                           getenv)(char const *__name);
extern __attribute__((__nothrow__))
time_t(__attribute__((__leaf__)) time)(time_t *__timer);
extern __attribute__((__nothrow__)) long(__attribute__((__leaf__))
                                         sysconf)(int __name);
extern __attribute__((__nothrow__)) void *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    mempcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strstr)(char const *__haystack, char const *__needle)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
FILE *(__attribute__((__leaf__)) setmntent)(char const *__file,
                                            char const *__mode);
extern __attribute__((__nothrow__)) struct mntent *(__attribute__((__leaf__))
                                                    getmntent)(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        endmntent)(FILE *__stream);
struct mode_change *mode_compile(char const *mode_string___0,
                                 unsigned int masked_ops);
mode_t mode_adjust(mode_t oldmode, struct mode_change const *changes);
void mode_free(struct mode_change *changes);
extern __attribute__((__nothrow__))
__mode_t(__attribute__((__leaf__)) umask)(__mode_t __mask);

static void mode_append_entry(struct mode_change **head,
                              struct mode_change **tail,
                              struct mode_change *e) {
  struct mode_change *tmp;

  {

    tmp = e;

    *head = tmp;
  }
}
struct mode_change *mode_compile(char const *mode_string___0,
                                 unsigned int masked_ops) {
  struct mode_change *head;
  struct mode_change *tail;

  mode_t affected_bits;
  mode_t affected_masked;

  struct mode_change *change;
  void *tmp___12;

  {

    {
      {
        ;

        { affected_bits = (mode_t)((4032 | (448 >> 3)) | ((448 >> 3) >> 3)); }
        {
          {
            ;

            {
              tmp___12 = malloc(sizeof(struct mode_change));
              change = (struct mode_change *)tmp___12;
            }
            if ((unsigned long)change == (unsigned long)((void *)0)) {

              return ((struct mode_change *)1);
            }

            affected_masked = affected_bits;

            {
              change->affected = affected_masked;
              change->value = (mode_t)0;

              mode_append_entry(&head, &tail, change);
            }
            {
              {
                ;

                change->value |=
                    (unsigned int)((256 | (256 >> 3)) | ((256 >> 3) >> 3)) &
                    affected_masked;
              };
            }

            ;
          };
        };
      };
    };
    { return (head); }
  }
}
mode_t mode_adjust(mode_t oldmode, struct mode_change const *changes) {
  mode_t newmode;
  mode_t value;

  {
    newmode = oldmode & (unsigned int)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
    {
      {
        ;

        { value = newmode & (unsigned int)changes->value; }

        newmode = (newmode & (unsigned int)(~changes->affected)) | value;
      };
    };
    return (newmode);
  }
}

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcoll)(char const *__s1, char const *__s2) __attribute__((__pure__));

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        wcwidth)(wchar_t __c);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        iswcntrl)(wint_t __wc);
int make_path(char const *argpath, int mode, int parent_mode, uid_t owner,
              gid_t group, int preserve_existing,
              char const *verbose_fmt_string);
int make_dir(char const *dir, char const *dirpath, mode_t mode,
             int *created_dir_p);
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     chmod)(char const *__file,
                                            __mode_t __mode);
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     mkdir)(char const *__path,
                                            __mode_t __mode);
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     chown)(char const *__file, __uid_t __owner,
                                            __gid_t __group);
int make_dir(char const *dir, char const *dirpath, mode_t mode,
             int *created_dir_p) {
  int fail;

  int tmp;

  {
    {
      fail = 0;
      tmp = mkdir(dir, mode);
    }

    return (fail);
  }
}
int make_path(char const *argpath, int mode, int parent_mode, uid_t owner,
              gid_t group, int preserve_existing,
              char const *verbose_fmt_string) {

  int retval;
  char *slash;
  int tmp_mode;

  char *basename_dir;
  char *dirpath;
  mode_t oldmask;
  __mode_t tmp;
  size_t tmp___0;
  void *tmp___1;

  int newly_created_dir;
  int fail;

  int tmp___29;

  int tmp___36;

  {
    { retval = 0; }
    {
      {

        tmp = umask((__mode_t)0);
        oldmask = tmp;
        tmp___0 = strlen(argpath);
        tmp___1 = __builtin_alloca(tmp___0 + 1UL);
        dirpath = (char *)tmp___1;
        strcpy((char * /* __restrict  */)dirpath,
               (char const * /* __restrict  */)argpath);
      }
      { tmp_mode = 448; }

      slash = dirpath;

      {
        while (1) {
          ;
          {
            basename_dir = slash;
            slash = strchr((char const *)slash, '/');
          }
          if ((unsigned long)slash == (unsigned long)((void *)0)) {
            goto while_break___0;
          }

          {
            *slash = (char)'\000';
            fail = make_dir((char const *)basename_dir, (char const *)dirpath,
                            (mode_t)tmp_mode, &newly_created_dir);
          }

          { tmp___29 = chdir((char const *)basename_dir); }

          slash++;
        };
      }
    while_break___0:;

      {
        umask(oldmask);
        tmp___36 = make_dir((char const *)basename_dir, (char const *)dirpath,
                            (mode_t)mode, (int *)((void *)0));
      }
    }

    return (retval);
  }
}

extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__))
                                                       exit)(int __status);
extern int optind;

extern int getopt_long(int ___argc, char *const *___argv,
                       char const *__shortopts, struct option const *__longopts,
                       int *__longind);

extern int fclose(FILE *__stream);
extern FILE *fopen(char const *__restrict __filename,
                   char const *__restrict __modes);
extern int fscanf(FILE *__restrict __stream, char const *__restrict __format,
                  ...);
extern int ungetc(int __c, FILE *__stream);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           nl_langinfo)(nl_item __item);

extern struct passwd *getpwuid(__uid_t __uid);

extern __attribute__((__nothrow__)) struct lconv *(__attribute__((__leaf__))
                                                   localeconv)(void);
extern __attribute__((__nothrow__)) void *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    memmove)(void *__dest, void const *__src, size_t __n);

extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           setlocale)(int __category,
                                                      char const *__locale);
extern void setgrent(void);
extern struct group *getgrent(void);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__))
    gettimeofday)(struct timeval *__restrict __tv, __timezone_ptr_t __tz);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        clock_gettime)(clockid_t __clock_id,
                                                       struct timespec *__tp);

extern char *getcwd(char *buf, size_t size);
__attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                    rpl_getcwd)(char *buf, size_t size);

extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__))
                                     fstat)(int __fd, struct stat *__buf);
extern void(__attribute__((__nonnull__(1, 4)))
            qsort)(void *__base, size_t __nmemb, size_t __size,
                   int (*__compar)(void const *, void const *));
extern char *(__attribute__((__nonnull__(1))) strrchr)(char const *__s, int __c)
    __attribute__((__pure__));
extern int(__attribute__((__nonnull__(1))) dirfd)(DIR *__dirp);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    statfs)(char const *__file, struct statfs *__buf);
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__))
                                         free)(void *__ptr);
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) rpl_free)(void *p);

extern __attribute__((__nothrow__))
FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        fileno)(FILE *__stream);

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcasecmp)(char const *__s1, char const *__s2) __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strncasecmp)(char const *__s1, char const *__s2, size_t __n)
    __attribute__((__pure__));
extern int fnmatch(char const *__pattern, char const *__name, int __flags);
extern int fcntl(int __fd, int __cmd, ...);
size_t dir_len(char const *path);

void close_stdout(void);
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__)) __fpending)(FILE *__fp);

extern struct hostent *gethostbyaddr(void const *__addr, __socklen_t __len,
                                     int __type);
extern struct hostent *gethostbyname(char const *__name);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           inet_ntoa)(struct in_addr __in);
extern __attribute__((__nothrow__)) double(
    __attribute__((__nonnull__(1), __leaf__))
    strtod)(char const *__restrict __nptr, char **__restrict __endptr);

void usage(int status);
extern
    __attribute__((__nothrow__)) long(__attribute__((__nonnull__(1), __leaf__))
                                      pathconf)(char const *__path, int __name);
extern int printf(char const *__restrict __format, ...);
extern char *optarg;
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     atexit)(void (*__func)(void));
extern
    __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                        textdomain)(char const *__domainname);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __leaf__)) bindtextdomain)(char const *__domainname, char const *__dirname);

static int create_parents;
static struct option const longopts[6] = {
    {"mode", 1, (int *)((void *)0), 'm'},
    {"parents", 0, (int *)((void *)0), 'p'},
    {"verbose", 0, (int *)((void *)0), 'v'},
    {"help", 0, (int *)0, -130},
    {"version", 0, (int *)0, -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
void usage(int status) { exit(status); }
int main(int argc, char **argv) {
  mode_t newmode;
  mode_t parent_mode;
  char const *specified_mode;
  char const *verbose_fmt_string;
  int errors;
  int optc;
  char *tmp;

  mode_t umask_value;
  __mode_t tmp___1;
  struct mode_change *change;
  struct mode_change *tmp___2;

  int fail;
  char *dir;

  {
    {
      specified_mode = (char const *)((void *)0);

      errors = 0;
    }
    {
      while (1) {
        ;
        {
          optc = getopt_long(argc, (char *const *)argv, "pm:v", longopts,
                             (int *)((void *)0));
        }
        if (!(optc != -1)) {
          goto while_break;
        }

        if (optc == 112) {
          goto case_112;
        }
        { goto case_109; }

      case_112:
        create_parents = 1;
        goto switch_break;
      case_109:
        specified_mode = (char const *)optarg;

        {
          tmp = gettext("created directory %s");
          verbose_fmt_string = (char const *)tmp;
        }

      switch_break:;
      };
    }
  while_break:;
    if (optind == argc) {

      usage(1);
    }
    {
      newmode = (mode_t)((448 | (448 >> 3)) | ((448 >> 3) >> 3));
      tmp___1 = umask((__mode_t)0);
      umask_value = tmp___1;
      umask(umask_value);
      parent_mode = ((newmode & ~umask_value) | 128U) | 64U;
    }
    if (specified_mode) {
      {
        tmp___2 = mode_compile(specified_mode, 0U);
        change = tmp___2;
      }

      {
        if ((unsigned long)change == (unsigned long)((struct mode_change *)1)) {

          xalloc_die();
        }
      }
      { newmode = mode_adjust(newmode, (struct mode_change const *)change); }
    }
    {
      while (1) {
        ;

        if (!(optind < argc)) {
          goto while_break___0;
        }

        if (create_parents) {

          dir = *(argv + optind);
          fail = make_path((char const *)dir, (int)newmode, (int)parent_mode,
                           (uid_t)-1, (gid_t)-1, 1, verbose_fmt_string);

        } else {

          fail = 1;
        }
        if (fail) {
          errors = 1;
        }
        optind++;
      };
    }
  while_break___0 : { exit(errors); }
  }
}
