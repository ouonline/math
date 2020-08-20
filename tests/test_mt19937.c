#include <stdio.h>
#include <stdlib.h>
#include "math/mt19937_32.h"
#include "math/mt19937_64.h"

#define N 100
#define SEED 31415926

// generated by std::mt19937
static const uint32_t mt19937_32_res[N] = {
    1769684135, 1686488197, 3036490524, 3195302048, 864035891,
    2777010200, 367583087, 269605543, 336544333, 3306870883,
    1878316287, 2843541197, 1770754732, 3012564753, 2136872996,
    502467336, 3733927210, 2890259286, 2925372433, 3952035597,
    3964455327, 3520754996, 4081491679, 2719923971, 4073099075,
    1276351826, 907616089, 1467987240, 3444730966, 3126043089,
    3091175099, 853233351, 1803467864, 4215829257, 1194910513,
    1322962420, 1600440108, 2325794972, 2654273289, 271468341,
    3916689135, 2199091623, 3224360983, 4227146051, 2554337840,
    729813467, 372963058, 2164922500, 1170749487, 3054466258,
    1303879853, 1956737511, 2515453619, 1191354951, 875577110,
    1740699398, 2523992665, 2950539606, 2257945092, 3653612575,
    1093174978, 2108471921, 2685486390, 564693992, 1065020909,
    173816107, 4152488289, 3761162077, 1493228702, 2381512751,
    893080744, 823411224, 1150959, 2319452032, 2983352780,
    2263531056, 784334438, 606384448, 3688336075, 3840997727,
    1640093814, 1220029968, 1552069916, 1490260181, 1677237600,
    2706245437, 2427731318, 1101141367, 3840936108, 3960123869,
    2329847944, 183578919, 2647510671, 3400704892, 3435289490,
    211870189, 4124834243, 2984727474, 2372405258, 2384327202,
};

// generated by std::mt19937_64
static const uint64_t mt19937_64_res[N] = {
    2837164102331193586ull, 12470051518418854914ull, 13048549720534793657ull, 2122596145720496852ull, 10281884706846819670ull,
    15430134042865878411ull, 1277167910339356689ull, 6908220250349143317ull, 4818564354183686047ull, 1519072142695891647ull,
    14369605221318773127ull, 5783743299609726641ull, 10706591026166113172ull, 4921960195493975390ull, 13201641778813989380ull,
    7668452164193050459ull, 15267751367886747188ull, 15371571658490710949ull, 15320719804390596339ull, 17215434280208729382ull,
    3465815108312306519ull, 5260561135936951167ull, 3069249431363567219ull, 11551007428906894545ull, 10702162834298482541ull,
    15429105394402695496ull, 6696357698971521701ull, 4832551615646270226ull, 8492338540470128042ull, 2456674804119764552ull,
    7520745880282457888ull, 14910673564745865330ull, 237654506792552371ull, 13295027888512336839ull, 17449350975045019813ull,
    17575393052404806364ull, 15502940993210560226ull, 17929108379766537850ull, 9734017941047176726ull, 6040914041278133632ull,
    8405183188272837497ull, 11513524809016911337ull, 18029583055937522375ull, 2264448521259850067ull, 5208886054304926512ull,
    8851678070639141358ull, 9948369812360931310ull, 15526914882542344361ull, 5182362189443894927ull, 4089161667709061881ull,
    2717440923796450999ull, 6067541489667310572ull, 12448316881882609878ull, 126307330082098488ull, 15719611363722823330ull,
    791049959352936468ull, 8038167773533156959ull, 8443805681595667297ull, 2925672210373379052ull, 13504222637602734432ull,
    16501867070783980488ull, 15237377008226217001ull, 10394564528074366168ull, 6110622345083167307ull, 11558205040030356407ull,
    11246994075657288141ull, 14890301217033954981ull, 2343745934627952374ull, 1982082700828187171ull, 7544828296548230828ull,
    119057963640610118ull, 8909582689160180215ull, 6130523372174989959ull, 1168954851543317453ull, 10366275643279713196ull,
    1270194413170201096ull, 13036821229800385621ull, 4325894232999850759ull, 1023888909614255341ull, 1841256143967908032ull,
    7536916877034845027ull, 3467955646138397033ull, 17248900477595325229ull, 17920195238002546245ull, 14786437808524544005ull,
    14492484864070285220ull, 3313253383691494224ull, 16872261680475928485ull, 17167269442677487263ull, 9828114464768187461ull,
    10105814004796742872ull, 17362546420057733598ull, 10704048776386897659ull, 6461416258590461733ull, 12698552924015780252ull,
    5593469754009006379ull, 8169537085001158158ull, 10950579889701346339ull, 15116136389886250460ull, 10179390560504462065ull,
};

static void test_32() {
    struct mt19937_32 st;
    mt19937_init32(&st, SEED);
    for (int i = 0; i < N; ++i) {
        uint32_t v = mt19937_rand32(&st);
        if (v != mt19937_32_res[i]) {
            fprintf(stderr, "mt19937_32 test [%d] failed.\n", i);
            exit(-1);
        }
    }
}

static void test_64() {
    struct mt19937_64 st;
    mt19937_init64(&st, SEED);
    for (int i = 0; i < N; ++i) {
        uint64_t v = mt19937_rand64(&st);
        if (v != mt19937_64_res[i]) {
            fprintf(stderr, "mt19937_64 test [%d] failed.\n", i);
            exit(-1);
        }
    }
}

int main(void) {
    test_32();
    test_64();
    printf("test ok\n");
    return 0;
}
