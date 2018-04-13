#include "defs.h"


schc_field_desc_t[] rule_0 = {
    FIELD_DESCRIPTION(FID_IPV6_VER, 4, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "x06"),
    FIELD_DESCRIPTION(FID_IPV6_DS, 8, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "x00"),
    FIELD_DESCRIPTION(FID_IPV6_FL, 20, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "x00"),
    FIELD_DESCRIPTION(FID_IPV6_LEN, 20, 1, DIR_IND_BI, MO_IGNORE, CDA_COMPUTE_LENGTH, ""),
    FIELD_DESCRIPTION(FID_IPV6_NH, 8, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "x11"),
    FIELD_DESCRIPTION(FID_IPV6_HL, 8, 1, DIR_IND_BI, MO_IGNORE, CDA_NOT_SENT, "\xff"),
    FIELD_DESCRIPTION(FID_IPV6_DEV_PREFIX, 64, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\xFE\x00\x00\x00\x00\x00\x00"),
    FIELD_DESCRIPTION(FID_IPV6_DEV_IID, 64, 1, DIR_IND_BI, MO_IGNORE, CDA_DEV_IID, ""),
    FIELD_DESCRIPTION(FID_IPV6_APP_PREFIX, 64, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\xFE\x00\x00\x00\x00\x00\x00"),
    FIELD_DESCRIPTION(FID_IPV6_APP_IID, 64, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\x00\x00\x00\x00\x00\x00\x00\x01"),
    FIELD_DESCRIPTION(FID_UDP_DP, 16, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\x7B"),
    FIELD_DESCRIPTION(FID_UDP_AP, 16, 1, DIR_IND_BI, MO_EQUAL, CDA_NOT_SENT, "\x7C"),
    FIELD_DESCRIPTION(FID_UDP_LEN, 16, 1, DIR_IND_BI, MO_IGNORE, CDA_COMPUTE_LENGTH, ""),
    FIELD_DESCRIPTION(FID_UDP_CHKS, 16, 1, DIR_IND_BI, MO_IGNORE, CDA_COMPUTE_CHECKSUM, ""),
    END_OF_TABLE
} 

schc_rule_t[] rules={
    {.rule_id=1, .rule=&rule_0, dir=DIR_IND_BI},
    END_OF_TABLE
};

schc_field_desc_t *schc_get_rule_by_id(int rule_id) {
    int i=0;
    while(r=rules[i++].rule_id) {
        if (rules[r].rule_id = rule_id)
            return &rules[r];
    }
    return NULL;
}

int schc_rule_is_uplink(schc_rule_t *rule) {
    return rule->dir ==  DIR_IND_BI || rule->dir == DIR_IND_UP;
}

int schc_rule_is_downlink(int rule_id) {
    return rule->dir ==  DIR_IND_BI || rule->dir == DIR_IND_DOWN;
}
