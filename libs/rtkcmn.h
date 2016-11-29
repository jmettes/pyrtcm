extern const double chisqr[100];
extern const double lam[];
extern const prcopt_t prcopt_default;
extern const solopt_t solopt_default;
extern const char *formatstrs[];
#if defined(LAPACK)
void dgemm_(char *,char *,int *,int *,int *,double *,double *,int *,double *,int *,double *,double *,int *);
void dgetrf_(int *,int *,double *,int *,int *,int *);
void dgetri_(int *,double *,int *,int *,double *,int *,int *);
void dgetrs_(char *,int *,int *,double *,int *,int *,double *,int *,int *);
#endif
int satno(int sys,int prn);
int satsys(int sat,int *prn);
int satid2no(const char *id);
void satno2id(int sat,char *id);
unsigned char obs2code(const char *obs);
char *code2obs(unsigned char code);
unsigned int getbitu(const unsigned char *buff,int pos,int len);
int getbits(const unsigned char *buff,int pos,int len);
unsigned int crc32(const unsigned char *buff,int len);
unsigned int crc24q(const unsigned char *buff,int len);
int decode_word(unsigned int word,unsigned char *data);
double *mat(int n,int m);
int *imat(int n,int m);
double *zeros(int n,int m);
double *eye(int n);
double dot(const double *a,const double *b,int n);
double norm(const double *a,int n);
void cross3(const double *a,const double *b,double *c);
int normv3(const double *a,double *b);
void matcpy(double *A,const double *B,int n,int m);
#if defined(LAPACK /* with LAPACK/BLAS or MKL */)
void matmul(const char *tr,int n,int k,int m,double alpha,const double *A,const double *B,double beta,double *C);
#endif
#if !(defined(LAPACK /* with LAPACK/BLAS or MKL */))
void matmul(const char *tr,int n,int k,int m,double alpha,const double *A,const double *B,double beta,double *C);
#endif
#if defined(LAPACK /* with LAPACK/BLAS or MKL */)
int matinv(double *A,int n);
#endif
#if !(defined(LAPACK /* with LAPACK/BLAS or MKL */))
int matinv(double *A,int n);
#endif
#if defined(LAPACK /* with LAPACK/BLAS or MKL */)
int solve(const char *tr,const double *A,const double *Y,int n,int m,double *X);
#endif
#if !(defined(LAPACK /* with LAPACK/BLAS or MKL */))
int solve(const char *tr,const double *A,const double *Y,int n,int m,double *X);
#endif
int lsq(const double *A,const double *y,int n,int m,double *x,double *Q);
int filter(double *x,double *P,const double *H,const double *v,const double *R,int n,int m);
int smoother(const double *xf,const double *Qf,const double *xb,const double *Qb,int n,double *xs,double *Qs);
void matfprint(const double A[],int n,int m,int p,int q,FILE *fp);
void matprint(const double A[],int n,int m,int p,int q);
double str2num(const char *s,int i,int n);
int str2time(const char *s,int i,int n,gtime_t *t);
gtime_t epoch2time(const double *ep);
void time2epoch(gtime_t t,double *ep);
gtime_t gpst2time(int week,double sec);
double time2gpst(gtime_t t,int *week);
gtime_t gst2time(int week,double sec);
double time2gst(gtime_t t,int *week);
gtime_t timeadd(gtime_t t,double sec);
double timediff(gtime_t t1,gtime_t t2);
gtime_t timeget(void);
void timeset(gtime_t t);
gtime_t gpst2utc(gtime_t t);
gtime_t utc2gpst(gtime_t t);
void time2str(gtime_t t,char *s,int n);
char *time_str(gtime_t t,int n);
double time2doy(gtime_t t);
int adjgpsweek(int week);
unsigned int tickget(void);
void sleepms(int ms);
void deg2dms(double deg,double *dms);
double dms2deg(const double *dms);
void ecef2pos(const double *r,double *pos);
void pos2ecef(const double *pos,double *r);
void xyz2enu(const double *pos,double *E);
void ecef2enu(const double *pos,const double *r,double *e);
void enu2ecef(const double *pos,const double *e,double *r);
void covenu(const double *pos,const double *P,double *Q);
void covecef(const double *pos,const double *Q,double *P);
int readpcv(const char *file,pcvs_t *pcvs);
pcv_t *searchpcv(int sat,const char *type,gtime_t time,const pcvs_t *pcvs);
void readpos(const char *file,const char *rcv,double *pos);
void uniqnav(nav_t *nav);
int sortobs(obs_t *obs);
int screent(gtime_t time,gtime_t ts,gtime_t te,double tint);
int readnav(const char *file,nav_t *nav);
int savenav(const char *file,const nav_t *nav);
void freeobs(obs_t *obs);
void freenav(nav_t *nav,int opt);
#if defined(TRACE)
void traceopen(const char *file);
#endif
#if !(defined(TRACE))
void traceopen(const char *file);
#endif
#if defined(TRACE)
void traceclose(void);
#endif
#if !(defined(TRACE))
void traceclose(void);
#endif
#if defined(TRACE)
void tracelevel(int level);
#endif
#if !(defined(TRACE))
void tracelevel(int level);
#endif
#if defined(TRACE)
void trace(int level,const char *format,...);
#endif
#if !(defined(TRACE))
void trace(int level,const char *format,...);
#endif
#if defined(TRACE)
void tracet(int level,const char *format,...);
#endif
#if !(defined(TRACE))
void tracet(int level,const char *format,...);
#endif
#if defined(TRACE)
void tracemat(int level,const double *A,int n,int m,int p,int q);
#endif
#if !(defined(TRACE))
void tracemat(int level,const double *A,int n,int m,int p,int q);
#endif
#if defined(TRACE)
void traceobs(int level,const obsd_t *obs,int n);
#endif
#if !(defined(TRACE))
void traceobs(int level,const obsd_t *obs,int n);
#endif
#if defined(TRACE)
void tracenav(int level,const nav_t *nav);
#endif
#if !(defined(TRACE))
void tracenav(int level,const nav_t *nav);
#endif
#if defined(TRACE)
void tracegnav(int level,const nav_t *nav);
#endif
#if !(defined(TRACE))
void tracegnav(int level,const nav_t *nav);
#endif
#if defined(TRACE)
void tracehnav(int level,const nav_t *nav);
#endif
#if !(defined(TRACE))
void tracehnav(int level,const nav_t *nav);
#endif
#if defined(TRACE)
void tracepeph(int level,const nav_t *nav);
#endif
#if !(defined(TRACE))
void tracepeph(int level,const nav_t *nav);
#endif
#if defined(TRACE)
void tracepclk(int level,const nav_t *nav);
#endif
#if !(defined(TRACE))
void tracepclk(int level,const nav_t *nav);
#endif
#if defined(TRACE)
void traceb(int level,const unsigned char *p,int n);
#endif
#if !(defined(TRACE))
void traceb(int level,const unsigned char *p,int n);
#endif
int execcmd(const char *cmd);
int expath(const char *path,char *paths[],int nmax);
void createdir(const char *path);
int repstr(char *str,const char *pat,const char *rep);
int reppath(const char *path,char *rpath,gtime_t time,const char *rov,const char *base);
int reppaths(const char *path,char *rpath[],int nmax,gtime_t ts,gtime_t te,const char *rov,const char *base);
double satwavelen(int sat,int frq,const nav_t *nav);
double geodist(const double *rs,const double *rr,double *e);
double satazel(const double *pos,const double *e,double *azel);
void dops(int ns,const double *azel,double elmin,double *dop);
double ionmodel(gtime_t t,const double *ion,const double *pos,const double *azel);
double ionmapf(const double *pos,const double *azel);
double ionppp(const double *pos,const double *azel,double re,double hion,double *posp);
double tropmodel(gtime_t time,const double *pos,const double *azel,double humi);
double tropmapf(gtime_t time,const double pos[],const double azel[],double *mapfw);
void antmodel(const pcv_t *pcv,const double *del,const double *azel,double *dant);
void antmodel_s(const pcv_t *pcv,double nadir,double *dant);
void csmooth(obs_t *obs,int ns);
int uncompress(const char *file,char *uncfile);
#if defined(DLL)
int showmsg(char *format,...);
void settspan(gtime_t ts,gtime_t te);
void settime(gtime_t time);
#endif
#if !defined(EXTLEX)
int lexupdatecorr(const lexmsg_t *msg,nav_t *nav,gtime_t *tof);
int lexreadmsg(const char *file,int sel,lex_t *lex);
void lexoutmsg(FILE *fp,const lexmsg_t *msg);
int lexconvbin(int type,const char *infile,const char *outfile);
int lexeph2pos(gtime_t time,int sat,const nav_t *nav,double *rs,double *dts,double *var);
int lexioncorr(gtime_t time,const nav_t *nav,const double *pos,const double *azel,double *delay,double *var);
int input_lexr(raw_t *raw,unsigned char data);
int input_lexrf(raw_t *raw,FILE *fp);
int gen_lexr(const char *msg,unsigned char *buff);
#endif
#if !defined(EXTION)
void read_nvtec(const char *file,nav_t *nav);
void read_ngtec(const char *file,nav_t *nav);
void read_nvtec_bias(const char *file,nav_t *nav);
int ion_ngtec(gtime_t time,const nav_t *nav,int sat,const double *pos,const double *azel,double *delay,double *var);
#endif
#define INTERFACE 0
#define EXPORT_INTERFACE 0
#define LOCAL_INTERFACE 0
#define EXPORT
#define LOCAL static
#define PUBLIC
#define PRIVATE
#define PROTECTED
