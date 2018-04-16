#ifndef ENUMS_H
#define ENUMS_H
typedef enum {
    FID_IPV6_VER=1,
    FID_IPV6_DS,
    FID_IPV6_FL, 
    FID_IPV6_LEN,
    FID_IPV6_NH,
    FID_IPV6_HL,
    FID_IPV6_DEV_PREFIX,
    FID_IPV6_DEV_IID,
    FID_IPV6_APP_PREFIX,
    FID_IPV6_APP_IID,
    FID_UDP_DP,
    FID_UDP_AP,
    FID_UDP_LEN,
    FID_UDP_CHKS
} schc_fid_t;

typedef enum {
    MO_EQUAL,
    MO_IGNORE,
    MO_MSB_1,
    MO_MSB_2,
    MO_MSB_3,
    MO_MSB_4,
    MO_MSB_5,
    MO_MSB_6,
    MO_MSB_7,
    MO_MSB_8,
    MO_MSB_9,
    MO_MSB_10,
    MO_MSB_11,
    MO_MSB_12,
    MO_MSB_13,
    MO_MSB_14,
    MO_MSB_15,
    MO_MATCH
} schc_mo_t;

typedef enum {
    CDA_NOT_SENT,
    CDA_VALUE_SENT,
    CDA_MAPPING_SENT,
    CDA_LSB_1,
    CDA_LSB_2,
    CDA_LSB_3,
    CDA_LSB_4,
    CDA_LSB_5,
    CDA_LSB_6,
    CDA_LSB_7,
    CDA_LSB_8,
    CDA_LSB_9,
    CDA_LSB_10,
    CDA_LSB_11,
    CDA_LSB_12,
    CDA_LSB_13,
    CDA_LSB_14,
    CDA_LSB_15,
    CDA_COMPUTE_LENGTH,
    CDA_COMPUTE_CHECKSUM,
    CDA_DEV_IID,
    CDA_APP_IID
} schc_cda_t;

typedef enum {
    DIR_IND_UP,
    DIR_IND_DOWN,
    DIR_IND_BI
} schc_dir_ind_t;

typedef struct {
    char *buf;
    size_t size;
} schc_buffer_t;

typedef struct {
    schc_fid_t fid;
    char fl;
    char fp;
    schc_dir_ind_t di;
    char mo;
    char cda;
    char *tv;
    size_t tv_size;
} schc_field_desc_t;

typedef schc_field_desc_t schc_rule_content_t;

typedef struct {
    char rule_id;
    schc_field_desc_t *rule;
    char dir;
} schc_rule_t;

#define FIELD_DESCRIPTION(FID, FL, FP, DI, MO, CDA, TV) \
    {.fid=FID, .fl=FL, .fp=FP, .di=DI, .mo=MO, .cda=CDA, .tv_size=sizeof(TV)-1, .tv=TV}
#define END_OF_TABLE {0}

schc_rule_t *schc_get_rule_by_id(int rule_id);
int schc_rule_is_uplink(schc_rule_t *rule);
int schc_rule_is_downlink(schc_rule_t *rule);

#endif
