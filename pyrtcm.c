#include "libs/rtklib.h"
#include "libs/rtkcmn.h"

void load_data(char *buf, int len, rtcm_t *rtcm) {
    int i, data = 0;
    for (i = 0; i < 4096; i++) {
        data = buf[i];
        if (input_rtcm3(rtcm,(char)data)) break;
    }
}

int main() {
    int i;
    FILE *file = NULL;
    rtcm_t rtk;
    file = fopen("data_type_2", "rb");
    init_rtcm(&rtk);

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    // or 4096
    unsigned char *buf = malloc(fsize);
    fread(buf, fsize, 1, file);
    fclose(file);

    int data = 0;
    for (i = 0; i < 4096; i++) {
        data = buf[i];
        if (input_rtcm3(&rtk,(unsigned char)data)) break;
    }

    // int data=0;
    // for (i=0;i<4096;i++) {
    //     if ((data=fgetc(file))==EOF) return -2;
    //     if (input_rtcm3(&rtk,(unsigned char)data)) break;
    // }
    // input_rtcm3f(&rtk, file);

    printf("msgtype: %s\n", rtk.msgtype);
    printf("ephsat: %d\n", rtk.ephsat);


    obs_t obs;
    obs = rtk.obs;
    printf("observations: %d\n", obs.n);
    for (i = 0; i < obs.n; i++) {
        obsd_t obsd = obs.data[i];
        double ep[6];
        time2epoch(obsd.time, ep);
        printf("%d time: %.0f %.0f %.0f %.0f %.0f %.0f\n", i, ep[0], ep[1], ep[2], ep[3], ep[4], ep[5]);

        printf("%d sat: %u\n", i, obsd.sat);
        printf("%d snr: %d\n", i, obsd.SNR[0]);
    }

    return 0;
}