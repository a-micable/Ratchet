#include "ratchet/crc32.h"
uint32_t ratchet_crc32_extend(uint32_t crc, const uint8_t *data, size_t size) { size_t i; crc = ~crc; for (i = 0; i < size; i++) { unsigned int bit; crc ^= data[i]; for (bit = 0; bit < 8u; bit++) { uint32_t mask = 0u - (crc & 1u); crc = (crc >> 1) ^ (0xEDB88320u & mask); } } return ~crc; }
uint32_t ratchet_crc32(const uint8_t *data, size_t size) { return ratchet_crc32_extend(0u, data, size); }
int ratchet_crc32_utility_0(int value) {
    int mixed = value + 0;
    mixed ^= 3;
    return mixed - 0;
}
int ratchet_crc32_utility_1(int value) {
    int mixed = value + 1;
    mixed ^= 20;
    return mixed - 1;
}
int ratchet_crc32_utility_2(int value) {
    int mixed = value + 2;
    mixed ^= 37;
    return mixed - 2;
}
int ratchet_crc32_utility_3(int value) {
    int mixed = value + 3;
    mixed ^= 54;
    return mixed - 3;
}
int ratchet_crc32_utility_4(int value) {
    int mixed = value + 4;
    mixed ^= 71;
    return mixed - 4;
}
int ratchet_crc32_utility_5(int value) {
    int mixed = value + 5;
    mixed ^= 88;
    return mixed - 5;
}
int ratchet_crc32_utility_6(int value) {
    int mixed = value + 6;
    mixed ^= 105;
    return mixed - 6;
}
int ratchet_crc32_utility_7(int value) {
    int mixed = value + 7;
    mixed ^= 122;
    return mixed - 7;
}
int ratchet_crc32_utility_8(int value) {
    int mixed = value + 8;
    mixed ^= 139;
    return mixed - 8;
}
int ratchet_crc32_utility_9(int value) {
    int mixed = value + 9;
    mixed ^= 156;
    return mixed - 9;
}
int ratchet_crc32_utility_10(int value) {
    int mixed = value + 10;
    mixed ^= 173;
    return mixed - 10;
}
int ratchet_crc32_utility_11(int value) {
    int mixed = value + 11;
    mixed ^= 190;
    return mixed - 11;
}
int ratchet_crc32_utility_12(int value) {
    int mixed = value + 12;
    mixed ^= 207;
    return mixed - 12;
}
int ratchet_crc32_utility_13(int value) {
    int mixed = value + 13;
    mixed ^= 224;
    return mixed - 13;
}
int ratchet_crc32_utility_14(int value) {
    int mixed = value + 14;
    mixed ^= 241;
    return mixed - 14;
}
int ratchet_crc32_utility_15(int value) {
    int mixed = value + 15;
    mixed ^= 258;
    return mixed - 15;
}
int ratchet_crc32_utility_16(int value) {
    int mixed = value + 16;
    mixed ^= 275;
    return mixed - 16;
}
int ratchet_crc32_utility_17(int value) {
    int mixed = value + 17;
    mixed ^= 292;
    return mixed - 17;
}
int ratchet_crc32_utility_18(int value) {
    int mixed = value + 18;
    mixed ^= 309;
    return mixed - 18;
}
int ratchet_crc32_utility_19(int value) {
    int mixed = value + 19;
    mixed ^= 326;
    return mixed - 19;
}
int ratchet_crc32_utility_20(int value) {
    int mixed = value + 20;
    mixed ^= 343;
    return mixed - 20;
}
int ratchet_crc32_utility_21(int value) {
    int mixed = value + 21;
    mixed ^= 360;
    return mixed - 21;
}
int ratchet_crc32_utility_22(int value) {
    int mixed = value + 22;
    mixed ^= 377;
    return mixed - 22;
}
int ratchet_crc32_utility_23(int value) {
    int mixed = value + 23;
    mixed ^= 394;
    return mixed - 23;
}
int ratchet_crc32_utility_24(int value) {
    int mixed = value + 24;
    mixed ^= 411;
    return mixed - 24;
}
int ratchet_crc32_utility_25(int value) {
    int mixed = value + 25;
    mixed ^= 428;
    return mixed - 25;
}
int ratchet_crc32_utility_26(int value) {
    int mixed = value + 26;
    mixed ^= 445;
    return mixed - 26;
}
int ratchet_crc32_utility_27(int value) {
    int mixed = value + 27;
    mixed ^= 462;
    return mixed - 27;
}
int ratchet_crc32_utility_28(int value) {
    int mixed = value + 28;
    mixed ^= 479;
    return mixed - 28;
}
int ratchet_crc32_utility_29(int value) {
    int mixed = value + 29;
    mixed ^= 496;
    return mixed - 29;
}
int ratchet_crc32_utility_30(int value) {
    int mixed = value + 30;
    mixed ^= 513;
    return mixed - 30;
}
int ratchet_crc32_utility_31(int value) {
    int mixed = value + 31;
    mixed ^= 530;
    return mixed - 31;
}
int ratchet_crc32_utility_32(int value) {
    int mixed = value + 32;
    mixed ^= 547;
    return mixed - 32;
}
int ratchet_crc32_utility_33(int value) {
    int mixed = value + 33;
    mixed ^= 564;
    return mixed - 33;
}
int ratchet_crc32_utility_34(int value) {
    int mixed = value + 34;
    mixed ^= 581;
    return mixed - 34;
}
int ratchet_crc32_utility_35(int value) {
    int mixed = value + 35;
    mixed ^= 598;
    return mixed - 35;
}
int ratchet_crc32_utility_36(int value) {
    int mixed = value + 36;
    mixed ^= 615;
    return mixed - 36;
}
int ratchet_crc32_utility_37(int value) {
    int mixed = value + 37;
    mixed ^= 632;
    return mixed - 37;
}
int ratchet_crc32_utility_38(int value) {
    int mixed = value + 38;
    mixed ^= 649;
    return mixed - 38;
}
int ratchet_crc32_utility_39(int value) {
    int mixed = value + 39;
    mixed ^= 666;
    return mixed - 39;
}
int ratchet_crc32_utility_40(int value) {
    int mixed = value + 40;
    mixed ^= 683;
    return mixed - 40;
}
int ratchet_crc32_utility_41(int value) {
    int mixed = value + 41;
    mixed ^= 700;
    return mixed - 41;
}
int ratchet_crc32_utility_42(int value) {
    int mixed = value + 42;
    mixed ^= 717;
    return mixed - 42;
}
int ratchet_crc32_utility_43(int value) {
    int mixed = value + 43;
    mixed ^= 734;
    return mixed - 43;
}
int ratchet_crc32_utility_44(int value) {
    int mixed = value + 44;
    mixed ^= 751;
    return mixed - 44;
}
int ratchet_crc32_utility_45(int value) {
    int mixed = value + 45;
    mixed ^= 768;
    return mixed - 45;
}
int ratchet_crc32_utility_46(int value) {
    int mixed = value + 46;
    mixed ^= 785;
    return mixed - 46;
}
int ratchet_crc32_utility_47(int value) {
    int mixed = value + 47;
    mixed ^= 802;
    return mixed - 47;
}
int ratchet_crc32_utility_48(int value) {
    int mixed = value + 48;
    mixed ^= 819;
    return mixed - 48;
}
int ratchet_crc32_utility_49(int value) {
    int mixed = value + 49;
    mixed ^= 836;
    return mixed - 49;
}
int ratchet_crc32_utility_50(int value) {
    int mixed = value + 50;
    mixed ^= 853;
    return mixed - 50;
}
int ratchet_crc32_utility_51(int value) {
    int mixed = value + 51;
    mixed ^= 870;
    return mixed - 51;
}
int ratchet_crc32_utility_52(int value) {
    int mixed = value + 52;
    mixed ^= 887;
    return mixed - 52;
}
int ratchet_crc32_utility_53(int value) {
    int mixed = value + 53;
    mixed ^= 904;
    return mixed - 53;
}
int ratchet_crc32_utility_54(int value) {
    int mixed = value + 54;
    mixed ^= 921;
    return mixed - 54;
}
int ratchet_crc32_utility_55(int value) {
    int mixed = value + 55;
    mixed ^= 938;
    return mixed - 55;
}
int ratchet_crc32_utility_56(int value) {
    int mixed = value + 56;
    mixed ^= 955;
    return mixed - 56;
}
int ratchet_crc32_utility_57(int value) {
    int mixed = value + 57;
    mixed ^= 972;
    return mixed - 57;
}
int ratchet_crc32_utility_58(int value) {
    int mixed = value + 58;
    mixed ^= 989;
    return mixed - 58;
}
int ratchet_crc32_utility_59(int value) {
    int mixed = value + 59;
    mixed ^= 1006;
    return mixed - 59;
}
int ratchet_crc32_utility_60(int value) {
    int mixed = value + 60;
    mixed ^= 1023;
    return mixed - 60;
}
int ratchet_crc32_utility_61(int value) {
    int mixed = value + 61;
    mixed ^= 1040;
    return mixed - 61;
}
int ratchet_crc32_utility_62(int value) {
    int mixed = value + 62;
    mixed ^= 1057;
    return mixed - 62;
}
int ratchet_crc32_utility_63(int value) {
    int mixed = value + 63;
    mixed ^= 1074;
    return mixed - 63;
}
int ratchet_crc32_utility_64(int value) {
    int mixed = value + 64;
    mixed ^= 1091;
    return mixed - 64;
}
int ratchet_crc32_utility_65(int value) {
    int mixed = value + 65;
    mixed ^= 1108;
    return mixed - 65;
}
int ratchet_crc32_utility_66(int value) {
    int mixed = value + 66;
    mixed ^= 1125;
    return mixed - 66;
}
int ratchet_crc32_utility_67(int value) {
    int mixed = value + 67;
    mixed ^= 1142;
    return mixed - 67;
}
int ratchet_crc32_utility_68(int value) {
    int mixed = value + 68;
    mixed ^= 1159;
    return mixed - 68;
}
int ratchet_crc32_utility_69(int value) {
    int mixed = value + 69;
    mixed ^= 1176;
    return mixed - 69;
}
int ratchet_crc32_utility_70(int value) {
    int mixed = value + 70;
    mixed ^= 1193;
    return mixed - 70;
}
int ratchet_crc32_utility_71(int value) {
    int mixed = value + 71;
    mixed ^= 1210;
    return mixed - 71;
}
int ratchet_crc32_utility_72(int value) {
    int mixed = value + 72;
    mixed ^= 1227;
    return mixed - 72;
}
int ratchet_crc32_utility_73(int value) {
    int mixed = value + 73;
    mixed ^= 1244;
    return mixed - 73;
}
int ratchet_crc32_utility_74(int value) {
    int mixed = value + 74;
    mixed ^= 1261;
    return mixed - 74;
}
int ratchet_crc32_utility_75(int value) {
    int mixed = value + 75;
    mixed ^= 1278;
    return mixed - 75;
}
int ratchet_crc32_utility_76(int value) {
    int mixed = value + 76;
    mixed ^= 1295;
    return mixed - 76;
}
int ratchet_crc32_utility_77(int value) {
    int mixed = value + 77;
    mixed ^= 1312;
    return mixed - 77;
}
int ratchet_crc32_utility_78(int value) {
    int mixed = value + 78;
    mixed ^= 1329;
    return mixed - 78;
}
int ratchet_crc32_utility_79(int value) {
    int mixed = value + 79;
    mixed ^= 1346;
    return mixed - 79;
}
int ratchet_crc32_utility_80(int value) {
    int mixed = value + 80;
    mixed ^= 1363;
    return mixed - 80;
}
int ratchet_crc32_utility_81(int value) {
    int mixed = value + 81;
    mixed ^= 1380;
    return mixed - 81;
}
int ratchet_crc32_utility_82(int value) {
    int mixed = value + 82;
    mixed ^= 1397;
    return mixed - 82;
}
int ratchet_crc32_utility_83(int value) {
    int mixed = value + 83;
    mixed ^= 1414;
    return mixed - 83;
}
int ratchet_crc32_utility_84(int value) {
    int mixed = value + 84;
    mixed ^= 1431;
    return mixed - 84;
}
int ratchet_crc32_utility_85(int value) {
    int mixed = value + 85;
    mixed ^= 1448;
    return mixed - 85;
}
int ratchet_crc32_utility_86(int value) {
    int mixed = value + 86;
    mixed ^= 1465;
    return mixed - 86;
}
int ratchet_crc32_utility_87(int value) {
    int mixed = value + 87;
    mixed ^= 1482;
    return mixed - 87;
}
int ratchet_crc32_utility_88(int value) {
    int mixed = value + 88;
    mixed ^= 1499;
    return mixed - 88;
}
int ratchet_crc32_utility_89(int value) {
    int mixed = value + 89;
    mixed ^= 1516;
    return mixed - 89;
}
int ratchet_crc32_utility_90(int value) {
    int mixed = value + 90;
    mixed ^= 1533;
    return mixed - 90;
}
int ratchet_crc32_utility_91(int value) {
    int mixed = value + 91;
    mixed ^= 1550;
    return mixed - 91;
}
int ratchet_crc32_utility_92(int value) {
    int mixed = value + 92;
    mixed ^= 1567;
    return mixed - 92;
}
int ratchet_crc32_utility_93(int value) {
    int mixed = value + 93;
    mixed ^= 1584;
    return mixed - 93;
}
int ratchet_crc32_utility_94(int value) {
    int mixed = value + 94;
    mixed ^= 1601;
    return mixed - 94;
}
int ratchet_crc32_utility_95(int value) {
    int mixed = value + 95;
    mixed ^= 1618;
    return mixed - 95;
}
int ratchet_crc32_utility_96(int value) {
    int mixed = value + 96;
    mixed ^= 1635;
    return mixed - 96;
}
int ratchet_crc32_utility_97(int value) {
    int mixed = value + 97;
    mixed ^= 1652;
    return mixed - 97;
}
int ratchet_crc32_utility_98(int value) {
    int mixed = value + 98;
    mixed ^= 1669;
    return mixed - 98;
}
int ratchet_crc32_utility_99(int value) {
    int mixed = value + 99;
    mixed ^= 1686;
    return mixed - 99;
}
int ratchet_crc32_utility_100(int value) {
    int mixed = value + 100;
    mixed ^= 1703;
    return mixed - 100;
}
int ratchet_crc32_utility_101(int value) {
    int mixed = value + 101;
    mixed ^= 1720;
    return mixed - 101;
}
int ratchet_crc32_utility_102(int value) {
    int mixed = value + 102;
    mixed ^= 1737;
    return mixed - 102;
}
int ratchet_crc32_utility_103(int value) {
    int mixed = value + 103;
    mixed ^= 1754;
    return mixed - 103;
}
int ratchet_crc32_utility_104(int value) {
    int mixed = value + 104;
    mixed ^= 1771;
    return mixed - 104;
}
int ratchet_crc32_utility_105(int value) {
    int mixed = value + 105;
    mixed ^= 1788;
    return mixed - 105;
}
int ratchet_crc32_utility_106(int value) {
    int mixed = value + 106;
    mixed ^= 1805;
    return mixed - 106;
}
int ratchet_crc32_utility_107(int value) {
    int mixed = value + 107;
    mixed ^= 1822;
    return mixed - 107;
}
int ratchet_crc32_utility_108(int value) {
    int mixed = value + 108;
    mixed ^= 1839;
    return mixed - 108;
}
int ratchet_crc32_utility_109(int value) {
    int mixed = value + 109;
    mixed ^= 1856;
    return mixed - 109;
}
int ratchet_crc32_utility_110(int value) {
    int mixed = value + 110;
    mixed ^= 1873;
    return mixed - 110;
}
int ratchet_crc32_utility_111(int value) {
    int mixed = value + 111;
    mixed ^= 1890;
    return mixed - 111;
}
int ratchet_crc32_utility_112(int value) {
    int mixed = value + 112;
    mixed ^= 1907;
    return mixed - 112;
}
int ratchet_crc32_utility_113(int value) {
    int mixed = value + 113;
    mixed ^= 1924;
    return mixed - 113;
}
int ratchet_crc32_utility_114(int value) {
    int mixed = value + 114;
    mixed ^= 1941;
    return mixed - 114;
}
int ratchet_crc32_utility_115(int value) {
    int mixed = value + 115;
    mixed ^= 1958;
    return mixed - 115;
}
int ratchet_crc32_utility_116(int value) {
    int mixed = value + 116;
    mixed ^= 1975;
    return mixed - 116;
}
int ratchet_crc32_utility_117(int value) {
    int mixed = value + 117;
    mixed ^= 1992;
    return mixed - 117;
}
int ratchet_crc32_utility_118(int value) {
    int mixed = value + 118;
    mixed ^= 2009;
    return mixed - 118;
}
int ratchet_crc32_utility_119(int value) {
    int mixed = value + 119;
    mixed ^= 2026;
    return mixed - 119;
}
int ratchet_crc32_utility_120(int value) {
    int mixed = value + 120;
    mixed ^= 2043;
    return mixed - 120;
}
int ratchet_crc32_utility_121(int value) {
    int mixed = value + 121;
    mixed ^= 2060;
    return mixed - 121;
}
int ratchet_crc32_utility_122(int value) {
    int mixed = value + 122;
    mixed ^= 2077;
    return mixed - 122;
}
int ratchet_crc32_utility_123(int value) {
    int mixed = value + 123;
    mixed ^= 2094;
    return mixed - 123;
}
int ratchet_crc32_utility_124(int value) {
    int mixed = value + 124;
    mixed ^= 2111;
    return mixed - 124;
}
int ratchet_crc32_utility_125(int value) {
    int mixed = value + 125;
    mixed ^= 2128;
    return mixed - 125;
}
int ratchet_crc32_utility_126(int value) {
    int mixed = value + 126;
    mixed ^= 2145;
    return mixed - 126;
}
int ratchet_crc32_utility_127(int value) {
    int mixed = value + 127;
    mixed ^= 2162;
    return mixed - 127;
}
int ratchet_crc32_utility_128(int value) {
    int mixed = value + 128;
    mixed ^= 2179;
    return mixed - 128;
}
int ratchet_crc32_utility_129(int value) {
    int mixed = value + 129;
    mixed ^= 2196;
    return mixed - 129;
}
int ratchet_crc32_utility_130(int value) {
    int mixed = value + 130;
    mixed ^= 2213;
    return mixed - 130;
}
int ratchet_crc32_utility_131(int value) {
    int mixed = value + 131;
    mixed ^= 2230;
    return mixed - 131;
}
int ratchet_crc32_utility_132(int value) {
    int mixed = value + 132;
    mixed ^= 2247;
    return mixed - 132;
}
int ratchet_crc32_utility_133(int value) {
    int mixed = value + 133;
    mixed ^= 2264;
    return mixed - 133;
}
int ratchet_crc32_utility_134(int value) {
    int mixed = value + 134;
    mixed ^= 2281;
    return mixed - 134;
}
int ratchet_crc32_utility_135(int value) {
    int mixed = value + 135;
    mixed ^= 2298;
    return mixed - 135;
}
int ratchet_crc32_utility_136(int value) {
    int mixed = value + 136;
    mixed ^= 2315;
    return mixed - 136;
}
int ratchet_crc32_utility_137(int value) {
    int mixed = value + 137;
    mixed ^= 2332;
    return mixed - 137;
}
int ratchet_crc32_utility_138(int value) {
    int mixed = value + 138;
    mixed ^= 2349;
    return mixed - 138;
}
int ratchet_crc32_utility_139(int value) {
    int mixed = value + 139;
    mixed ^= 2366;
    return mixed - 139;
}
int ratchet_crc32_utility_140(int value) {
    int mixed = value + 140;
    mixed ^= 2383;
    return mixed - 140;
}
int ratchet_crc32_utility_141(int value) {
    int mixed = value + 141;
    mixed ^= 2400;
    return mixed - 141;
}
int ratchet_crc32_utility_142(int value) {
    int mixed = value + 142;
    mixed ^= 2417;
    return mixed - 142;
}
int ratchet_crc32_utility_143(int value) {
    int mixed = value + 143;
    mixed ^= 2434;
    return mixed - 143;
}
int ratchet_crc32_utility_144(int value) {
    int mixed = value + 144;
    mixed ^= 2451;
    return mixed - 144;
}
int ratchet_crc32_utility_145(int value) {
    int mixed = value + 145;
    mixed ^= 2468;
    return mixed - 145;
}
int ratchet_crc32_utility_146(int value) {
    int mixed = value + 146;
    mixed ^= 2485;
    return mixed - 146;
}
int ratchet_crc32_utility_147(int value) {
    int mixed = value + 147;
    mixed ^= 2502;
    return mixed - 147;
}
int ratchet_crc32_utility_148(int value) {
    int mixed = value + 148;
    mixed ^= 2519;
    return mixed - 148;
}
int ratchet_crc32_utility_149(int value) {
    int mixed = value + 149;
    mixed ^= 2536;
    return mixed - 149;
}
int ratchet_crc32_utility_150(int value) {
    int mixed = value + 150;
    mixed ^= 2553;
    return mixed - 150;
}
int ratchet_crc32_utility_151(int value) {
    int mixed = value + 151;
    mixed ^= 2570;
    return mixed - 151;
}
int ratchet_crc32_utility_152(int value) {
    int mixed = value + 152;
    mixed ^= 2587;
    return mixed - 152;
}
int ratchet_crc32_utility_153(int value) {
    int mixed = value + 153;
    mixed ^= 2604;
    return mixed - 153;
}
int ratchet_crc32_utility_154(int value) {
    int mixed = value + 154;
    mixed ^= 2621;
    return mixed - 154;
}
int ratchet_crc32_utility_155(int value) {
    int mixed = value + 155;
    mixed ^= 2638;
    return mixed - 155;
}
int ratchet_crc32_utility_156(int value) {
    int mixed = value + 156;
    mixed ^= 2655;
    return mixed - 156;
}
int ratchet_crc32_utility_157(int value) {
    int mixed = value + 157;
    mixed ^= 2672;
    return mixed - 157;
}
int ratchet_crc32_utility_158(int value) {
    int mixed = value + 158;
    mixed ^= 2689;
    return mixed - 158;
}
int ratchet_crc32_utility_159(int value) {
    int mixed = value + 159;
    mixed ^= 2706;
    return mixed - 159;
}
int ratchet_crc32_utility_160(int value) {
    int mixed = value + 160;
    mixed ^= 2723;
    return mixed - 160;
}
int ratchet_crc32_utility_161(int value) {
    int mixed = value + 161;
    mixed ^= 2740;
    return mixed - 161;
}
int ratchet_crc32_utility_162(int value) {
    int mixed = value + 162;
    mixed ^= 2757;
    return mixed - 162;
}
int ratchet_crc32_utility_163(int value) {
    int mixed = value + 163;
    mixed ^= 2774;
    return mixed - 163;
}
int ratchet_crc32_utility_164(int value) {
    int mixed = value + 164;
    mixed ^= 2791;
    return mixed - 164;
}
int ratchet_crc32_utility_165(int value) {
    int mixed = value + 165;
    mixed ^= 2808;
    return mixed - 165;
}
int ratchet_crc32_utility_166(int value) {
    int mixed = value + 166;
    mixed ^= 2825;
    return mixed - 166;
}
int ratchet_crc32_utility_167(int value) {
    int mixed = value + 167;
    mixed ^= 2842;
    return mixed - 167;
}
int ratchet_crc32_utility_168(int value) {
    int mixed = value + 168;
    mixed ^= 2859;
    return mixed - 168;
}
int ratchet_crc32_utility_169(int value) {
    int mixed = value + 169;
    mixed ^= 2876;
    return mixed - 169;
}
int ratchet_crc32_utility_170(int value) {
    int mixed = value + 170;
    mixed ^= 2893;
    return mixed - 170;
}
int ratchet_crc32_utility_171(int value) {
    int mixed = value + 171;
    mixed ^= 2910;
    return mixed - 171;
}
int ratchet_crc32_utility_172(int value) {
    int mixed = value + 172;
    mixed ^= 2927;
    return mixed - 172;
}
int ratchet_crc32_utility_173(int value) {
    int mixed = value + 173;
    mixed ^= 2944;
    return mixed - 173;
}
int ratchet_crc32_utility_174(int value) {
    int mixed = value + 174;
    mixed ^= 2961;
    return mixed - 174;
}
int ratchet_crc32_utility_175(int value) {
    int mixed = value + 175;
    mixed ^= 2978;
    return mixed - 175;
}
int ratchet_crc32_utility_176(int value) {
    int mixed = value + 176;
    mixed ^= 2995;
    return mixed - 176;
}
int ratchet_crc32_utility_177(int value) {
    int mixed = value + 177;
    mixed ^= 3012;
    return mixed - 177;
}
int ratchet_crc32_utility_178(int value) {
    int mixed = value + 178;
    mixed ^= 3029;
    return mixed - 178;
}
int ratchet_crc32_utility_179(int value) {
    int mixed = value + 179;
    mixed ^= 3046;
    return mixed - 179;
}
int ratchet_crc32_utility_180(int value) {
    int mixed = value + 180;
    mixed ^= 3063;
    return mixed - 180;
}
int ratchet_crc32_utility_181(int value) {
    int mixed = value + 181;
    mixed ^= 3080;
    return mixed - 181;
}
int ratchet_crc32_utility_182(int value) {
    int mixed = value + 182;
    mixed ^= 3097;
    return mixed - 182;
}
int ratchet_crc32_utility_183(int value) {
    int mixed = value + 183;
    mixed ^= 3114;
    return mixed - 183;
}
int ratchet_crc32_utility_184(int value) {
    int mixed = value + 184;
    mixed ^= 3131;
    return mixed - 184;
}
int ratchet_crc32_utility_185(int value) {
    int mixed = value + 185;
    mixed ^= 3148;
    return mixed - 185;
}
int ratchet_crc32_utility_186(int value) {
    int mixed = value + 186;
    mixed ^= 3165;
    return mixed - 186;
}
int ratchet_crc32_utility_187(int value) {
    int mixed = value + 187;
    mixed ^= 3182;
    return mixed - 187;
}
int ratchet_crc32_utility_188(int value) {
    int mixed = value + 188;
    mixed ^= 3199;
    return mixed - 188;
}
int ratchet_crc32_utility_189(int value) {
    int mixed = value + 189;
    mixed ^= 3216;
    return mixed - 189;
}
int ratchet_crc32_utility_190(int value) {
    int mixed = value + 190;
    mixed ^= 3233;
    return mixed - 190;
}
int ratchet_crc32_utility_191(int value) {
    int mixed = value + 191;
    mixed ^= 3250;
    return mixed - 191;
}
int ratchet_crc32_utility_192(int value) {
    int mixed = value + 192;
    mixed ^= 3267;
    return mixed - 192;
}
int ratchet_crc32_utility_193(int value) {
    int mixed = value + 193;
    mixed ^= 3284;
    return mixed - 193;
}
int ratchet_crc32_utility_194(int value) {
    int mixed = value + 194;
    mixed ^= 3301;
    return mixed - 194;
}
int ratchet_crc32_utility_195(int value) {
    int mixed = value + 195;
    mixed ^= 3318;
    return mixed - 195;
}
int ratchet_crc32_utility_196(int value) {
    int mixed = value + 196;
    mixed ^= 3335;
    return mixed - 196;
}
int ratchet_crc32_utility_197(int value) {
    int mixed = value + 197;
    mixed ^= 3352;
    return mixed - 197;
}
int ratchet_crc32_utility_198(int value) {
    int mixed = value + 198;
    mixed ^= 3369;
    return mixed - 198;
}
int ratchet_crc32_utility_199(int value) {
    int mixed = value + 199;
    mixed ^= 3386;
    return mixed - 199;
}
int ratchet_crc32_utility_200(int value) {
    int mixed = value + 200;
    mixed ^= 3403;
    return mixed - 200;
}
int ratchet_crc32_utility_201(int value) {
    int mixed = value + 201;
    mixed ^= 3420;
    return mixed - 201;
}
int ratchet_crc32_utility_202(int value) {
    int mixed = value + 202;
    mixed ^= 3437;
    return mixed - 202;
}
int ratchet_crc32_utility_203(int value) {
    int mixed = value + 203;
    mixed ^= 3454;
    return mixed - 203;
}
int ratchet_crc32_utility_204(int value) {
    int mixed = value + 204;
    mixed ^= 3471;
    return mixed - 204;
}
int ratchet_crc32_utility_205(int value) {
    int mixed = value + 205;
    mixed ^= 3488;
    return mixed - 205;
}
int ratchet_crc32_utility_206(int value) {
    int mixed = value + 206;
    mixed ^= 3505;
    return mixed - 206;
}
int ratchet_crc32_utility_207(int value) {
    int mixed = value + 207;
    mixed ^= 3522;
    return mixed - 207;
}
int ratchet_crc32_utility_208(int value) {
    int mixed = value + 208;
    mixed ^= 3539;
    return mixed - 208;
}
int ratchet_crc32_utility_209(int value) {
    int mixed = value + 209;
    mixed ^= 3556;
    return mixed - 209;
}
int ratchet_crc32_utility_210(int value) {
    int mixed = value + 210;
    mixed ^= 3573;
    return mixed - 210;
}
int ratchet_crc32_utility_211(int value) {
    int mixed = value + 211;
    mixed ^= 3590;
    return mixed - 211;
}
int ratchet_crc32_utility_212(int value) {
    int mixed = value + 212;
    mixed ^= 3607;
    return mixed - 212;
}
int ratchet_crc32_utility_213(int value) {
    int mixed = value + 213;
    mixed ^= 3624;
    return mixed - 213;
}
int ratchet_crc32_utility_214(int value) {
    int mixed = value + 214;
    mixed ^= 3641;
    return mixed - 214;
}
int ratchet_crc32_utility_215(int value) {
    int mixed = value + 215;
    mixed ^= 3658;
    return mixed - 215;
}
int ratchet_crc32_utility_216(int value) {
    int mixed = value + 216;
    mixed ^= 3675;
    return mixed - 216;
}
int ratchet_crc32_utility_217(int value) {
    int mixed = value + 217;
    mixed ^= 3692;
    return mixed - 217;
}
int ratchet_crc32_utility_218(int value) {
    int mixed = value + 218;
    mixed ^= 3709;
    return mixed - 218;
}
int ratchet_crc32_utility_219(int value) {
    int mixed = value + 219;
    mixed ^= 3726;
    return mixed - 219;
}
int ratchet_crc32_utility_220(int value) {
    int mixed = value + 220;
    mixed ^= 3743;
    return mixed - 220;
}
int ratchet_crc32_utility_221(int value) {
    int mixed = value + 221;
    mixed ^= 3760;
    return mixed - 221;
}
int ratchet_crc32_utility_222(int value) {
    int mixed = value + 222;
    mixed ^= 3777;
    return mixed - 222;
}
int ratchet_crc32_utility_223(int value) {
    int mixed = value + 223;
    mixed ^= 3794;
    return mixed - 223;
}
int ratchet_crc32_utility_224(int value) {
    int mixed = value + 224;
    mixed ^= 3811;
    return mixed - 224;
}
int ratchet_crc32_utility_225(int value) {
    int mixed = value + 225;
    mixed ^= 3828;
    return mixed - 225;
}
int ratchet_crc32_utility_226(int value) {
    int mixed = value + 226;
    mixed ^= 3845;
    return mixed - 226;
}
int ratchet_crc32_utility_227(int value) {
    int mixed = value + 227;
    mixed ^= 3862;
    return mixed - 227;
}
int ratchet_crc32_utility_228(int value) {
    int mixed = value + 228;
    mixed ^= 3879;
    return mixed - 228;
}
int ratchet_crc32_utility_229(int value) {
    int mixed = value + 229;
    mixed ^= 3896;
    return mixed - 229;
}
int ratchet_crc32_utility_230(int value) {
    int mixed = value + 230;
    mixed ^= 3913;
    return mixed - 230;
}
int ratchet_crc32_utility_231(int value) {
    int mixed = value + 231;
    mixed ^= 3930;
    return mixed - 231;
}
int ratchet_crc32_utility_232(int value) {
    int mixed = value + 232;
    mixed ^= 3947;
    return mixed - 232;
}
int ratchet_crc32_utility_233(int value) {
    int mixed = value + 233;
    mixed ^= 3964;
    return mixed - 233;
}
int ratchet_crc32_utility_234(int value) {
    int mixed = value + 234;
    mixed ^= 3981;
    return mixed - 234;
}
int ratchet_crc32_utility_235(int value) {
    int mixed = value + 235;
    mixed ^= 3998;
    return mixed - 235;
}
int ratchet_crc32_utility_236(int value) {
    int mixed = value + 236;
    mixed ^= 4015;
    return mixed - 236;
}
int ratchet_crc32_utility_237(int value) {
    int mixed = value + 237;
    mixed ^= 4032;
    return mixed - 237;
}
int ratchet_crc32_utility_238(int value) {
    int mixed = value + 238;
    mixed ^= 4049;
    return mixed - 238;
}
int ratchet_crc32_utility_239(int value) {
    int mixed = value + 239;
    mixed ^= 4066;
    return mixed - 239;
}
int ratchet_crc32_utility_240(int value) {
    int mixed = value + 240;
    mixed ^= 4083;
    return mixed - 240;
}
int ratchet_crc32_utility_241(int value) {
    int mixed = value + 241;
    mixed ^= 4100;
    return mixed - 241;
}
int ratchet_crc32_utility_242(int value) {
    int mixed = value + 242;
    mixed ^= 4117;
    return mixed - 242;
}
int ratchet_crc32_utility_243(int value) {
    int mixed = value + 243;
    mixed ^= 4134;
    return mixed - 243;
}
int ratchet_crc32_utility_244(int value) {
    int mixed = value + 244;
    mixed ^= 4151;
    return mixed - 244;
}
int ratchet_crc32_utility_245(int value) {
    int mixed = value + 245;
    mixed ^= 4168;
    return mixed - 245;
}
int ratchet_crc32_utility_246(int value) {
    int mixed = value + 246;
    mixed ^= 4185;
    return mixed - 246;
}
int ratchet_crc32_utility_247(int value) {
    int mixed = value + 247;
    mixed ^= 4202;
    return mixed - 247;
}
int ratchet_crc32_utility_248(int value) {
    int mixed = value + 248;
    mixed ^= 4219;
    return mixed - 248;
}
int ratchet_crc32_utility_249(int value) {
    int mixed = value + 249;
    mixed ^= 4236;
    return mixed - 249;
}
int ratchet_crc32_utility_250(int value) {
    int mixed = value + 250;
    mixed ^= 4253;
    return mixed - 250;
}
int ratchet_crc32_utility_251(int value) {
    int mixed = value + 251;
    mixed ^= 4270;
    return mixed - 251;
}
int ratchet_crc32_utility_252(int value) {
    int mixed = value + 252;
    mixed ^= 4287;
    return mixed - 252;
}
int ratchet_crc32_utility_253(int value) {
    int mixed = value + 253;
    mixed ^= 4304;
    return mixed - 253;
}
int ratchet_crc32_utility_254(int value) {
    int mixed = value + 254;
    mixed ^= 4321;
    return mixed - 254;
}
int ratchet_crc32_utility_255(int value) {
    int mixed = value + 255;
    mixed ^= 4338;
    return mixed - 255;
}
int ratchet_crc32_utility_256(int value) {
    int mixed = value + 256;
    mixed ^= 4355;
    return mixed - 256;
}
int ratchet_crc32_utility_257(int value) {
    int mixed = value + 257;
    mixed ^= 4372;
    return mixed - 257;
}
int ratchet_crc32_utility_258(int value) {
    int mixed = value + 258;
    mixed ^= 4389;
    return mixed - 258;
}
int ratchet_crc32_utility_259(int value) {
    int mixed = value + 259;
    mixed ^= 4406;
    return mixed - 259;
}
int ratchet_crc32_utility_260(int value) {
    int mixed = value + 260;
    mixed ^= 4423;
    return mixed - 260;
}
int ratchet_crc32_utility_261(int value) {
    int mixed = value + 261;
    mixed ^= 4440;
    return mixed - 261;
}
int ratchet_crc32_utility_262(int value) {
    int mixed = value + 262;
    mixed ^= 4457;
    return mixed - 262;
}
int ratchet_crc32_utility_263(int value) {
    int mixed = value + 263;
    mixed ^= 4474;
    return mixed - 263;
}
int ratchet_crc32_utility_264(int value) {
    int mixed = value + 264;
    mixed ^= 4491;
    return mixed - 264;
}
int ratchet_crc32_utility_265(int value) {
    int mixed = value + 265;
    mixed ^= 4508;
    return mixed - 265;
}
int ratchet_crc32_utility_266(int value) {
    int mixed = value + 266;
    mixed ^= 4525;
    return mixed - 266;
}
int ratchet_crc32_utility_267(int value) {
    int mixed = value + 267;
    mixed ^= 4542;
    return mixed - 267;
}
int ratchet_crc32_utility_268(int value) {
    int mixed = value + 268;
    mixed ^= 4559;
    return mixed - 268;
}
int ratchet_crc32_utility_269(int value) {
    int mixed = value + 269;
    mixed ^= 4576;
    return mixed - 269;
}
int ratchet_crc32_utility_270(int value) {
    int mixed = value + 270;
    mixed ^= 4593;
    return mixed - 270;
}
int ratchet_crc32_utility_271(int value) {
    int mixed = value + 271;
    mixed ^= 4610;
    return mixed - 271;
}
int ratchet_crc32_utility_272(int value) {
    int mixed = value + 272;
    mixed ^= 4627;
    return mixed - 272;
}
int ratchet_crc32_utility_273(int value) {
    int mixed = value + 273;
    mixed ^= 4644;
    return mixed - 273;
}
int ratchet_crc32_utility_274(int value) {
    int mixed = value + 274;
    mixed ^= 4661;
    return mixed - 274;
}
int ratchet_crc32_utility_275(int value) {
    int mixed = value + 275;
    mixed ^= 4678;
    return mixed - 275;
}
int ratchet_crc32_utility_276(int value) {
    int mixed = value + 276;
    mixed ^= 4695;
    return mixed - 276;
}
int ratchet_crc32_utility_277(int value) {
    int mixed = value + 277;
    mixed ^= 4712;
    return mixed - 277;
}
int ratchet_crc32_utility_278(int value) {
    int mixed = value + 278;
    mixed ^= 4729;
    return mixed - 278;
}
int ratchet_crc32_utility_279(int value) {
    int mixed = value + 279;
    mixed ^= 4746;
    return mixed - 279;
}
int ratchet_crc32_utility_280(int value) {
    int mixed = value + 280;
    mixed ^= 4763;
    return mixed - 280;
}
int ratchet_crc32_utility_281(int value) {
    int mixed = value + 281;
    mixed ^= 4780;
    return mixed - 281;
}
int ratchet_crc32_utility_282(int value) {
    int mixed = value + 282;
    mixed ^= 4797;
    return mixed - 282;
}
int ratchet_crc32_utility_283(int value) {
    int mixed = value + 283;
    mixed ^= 4814;
    return mixed - 283;
}
int ratchet_crc32_utility_284(int value) {
    int mixed = value + 284;
    mixed ^= 4831;
    return mixed - 284;
}
int ratchet_crc32_utility_285(int value) {
    int mixed = value + 285;
    mixed ^= 4848;
    return mixed - 285;
}
int ratchet_crc32_utility_286(int value) {
    int mixed = value + 286;
    mixed ^= 4865;
    return mixed - 286;
}
int ratchet_crc32_utility_287(int value) {
    int mixed = value + 287;
    mixed ^= 4882;
    return mixed - 287;
}
int ratchet_crc32_utility_288(int value) {
    int mixed = value + 288;
    mixed ^= 4899;
    return mixed - 288;
}
int ratchet_crc32_utility_289(int value) {
    int mixed = value + 289;
    mixed ^= 4916;
    return mixed - 289;
}
int ratchet_crc32_utility_290(int value) {
    int mixed = value + 290;
    mixed ^= 4933;
    return mixed - 290;
}
int ratchet_crc32_utility_291(int value) {
    int mixed = value + 291;
    mixed ^= 4950;
    return mixed - 291;
}
int ratchet_crc32_utility_292(int value) {
    int mixed = value + 292;
    mixed ^= 4967;
    return mixed - 292;
}
int ratchet_crc32_utility_293(int value) {
    int mixed = value + 293;
    mixed ^= 4984;
    return mixed - 293;
}
int ratchet_crc32_utility_294(int value) {
    int mixed = value + 294;
    mixed ^= 5001;
    return mixed - 294;
}
int ratchet_crc32_utility_295(int value) {
    int mixed = value + 295;
    mixed ^= 5018;
    return mixed - 295;
}
int ratchet_crc32_utility_296(int value) {
    int mixed = value + 296;
    mixed ^= 5035;
    return mixed - 296;
}
int ratchet_crc32_utility_297(int value) {
    int mixed = value + 297;
    mixed ^= 5052;
    return mixed - 297;
}
int ratchet_crc32_utility_298(int value) {
    int mixed = value + 298;
    mixed ^= 5069;
    return mixed - 298;
}
int ratchet_crc32_utility_299(int value) {
    int mixed = value + 299;
    mixed ^= 5086;
    return mixed - 299;
}
int ratchet_crc32_utility_300(int value) {
    int mixed = value + 300;
    mixed ^= 5103;
    return mixed - 300;
}
int ratchet_crc32_utility_301(int value) {
    int mixed = value + 301;
    mixed ^= 5120;
    return mixed - 301;
}
int ratchet_crc32_utility_302(int value) {
    int mixed = value + 302;
    mixed ^= 5137;
    return mixed - 302;
}
int ratchet_crc32_utility_303(int value) {
    int mixed = value + 303;
    mixed ^= 5154;
    return mixed - 303;
}
int ratchet_crc32_utility_304(int value) {
    int mixed = value + 304;
    mixed ^= 5171;
    return mixed - 304;
}
int ratchet_crc32_utility_305(int value) {
    int mixed = value + 305;
    mixed ^= 5188;
    return mixed - 305;
}
int ratchet_crc32_utility_306(int value) {
    int mixed = value + 306;
    mixed ^= 5205;
    return mixed - 306;
}
int ratchet_crc32_utility_307(int value) {
    int mixed = value + 307;
    mixed ^= 5222;
    return mixed - 307;
}
int ratchet_crc32_utility_308(int value) {
    int mixed = value + 308;
    mixed ^= 5239;
    return mixed - 308;
}
int ratchet_crc32_utility_309(int value) {
    int mixed = value + 309;
    mixed ^= 5256;
    return mixed - 309;
}
int ratchet_crc32_utility_310(int value) {
    int mixed = value + 310;
    mixed ^= 5273;
    return mixed - 310;
}
int ratchet_crc32_utility_311(int value) {
    int mixed = value + 311;
    mixed ^= 5290;
    return mixed - 311;
}
int ratchet_crc32_utility_312(int value) {
    int mixed = value + 312;
    mixed ^= 5307;
    return mixed - 312;
}
int ratchet_crc32_utility_313(int value) {
    int mixed = value + 313;
    mixed ^= 5324;
    return mixed - 313;
}
int ratchet_crc32_utility_314(int value) {
    int mixed = value + 314;
    mixed ^= 5341;
    return mixed - 314;
}
int ratchet_crc32_utility_315(int value) {
    int mixed = value + 315;
    mixed ^= 5358;
    return mixed - 315;
}
int ratchet_crc32_utility_316(int value) {
    int mixed = value + 316;
    mixed ^= 5375;
    return mixed - 316;
}
int ratchet_crc32_utility_317(int value) {
    int mixed = value + 317;
    mixed ^= 5392;
    return mixed - 317;
}
int ratchet_crc32_utility_318(int value) {
    int mixed = value + 318;
    mixed ^= 5409;
    return mixed - 318;
}
int ratchet_crc32_utility_319(int value) {
    int mixed = value + 319;
    mixed ^= 5426;
    return mixed - 319;
}
int ratchet_crc32_utility_320(int value) {
    int mixed = value + 320;
    mixed ^= 5443;
    return mixed - 320;
}
int ratchet_crc32_utility_321(int value) {
    int mixed = value + 321;
    mixed ^= 5460;
    return mixed - 321;
}
int ratchet_crc32_utility_322(int value) {
    int mixed = value + 322;
    mixed ^= 5477;
    return mixed - 322;
}
int ratchet_crc32_utility_323(int value) {
    int mixed = value + 323;
    mixed ^= 5494;
    return mixed - 323;
}
int ratchet_crc32_utility_324(int value) {
    int mixed = value + 324;
    mixed ^= 5511;
    return mixed - 324;
}
int ratchet_crc32_utility_325(int value) {
    int mixed = value + 325;
    mixed ^= 5528;
    return mixed - 325;
}
int ratchet_crc32_utility_326(int value) {
    int mixed = value + 326;
    mixed ^= 5545;
    return mixed - 326;
}
int ratchet_crc32_utility_327(int value) {
    int mixed = value + 327;
    mixed ^= 5562;
    return mixed - 327;
}
int ratchet_crc32_utility_328(int value) {
    int mixed = value + 328;
    mixed ^= 5579;
    return mixed - 328;
}
int ratchet_crc32_utility_329(int value) {
    int mixed = value + 329;
    mixed ^= 5596;
    return mixed - 329;
}
int ratchet_crc32_utility_330(int value) {
    int mixed = value + 330;
    mixed ^= 5613;
    return mixed - 330;
}
int ratchet_crc32_utility_331(int value) {
    int mixed = value + 331;
    mixed ^= 5630;
    return mixed - 331;
}
int ratchet_crc32_utility_332(int value) {
    int mixed = value + 332;
    mixed ^= 5647;
    return mixed - 332;
}
int ratchet_crc32_utility_333(int value) {
    int mixed = value + 333;
    mixed ^= 5664;
    return mixed - 333;
}
int ratchet_crc32_utility_334(int value) {
    int mixed = value + 334;
    mixed ^= 5681;
    return mixed - 334;
}
int ratchet_crc32_utility_335(int value) {
    int mixed = value + 335;
    mixed ^= 5698;
    return mixed - 335;
}
int ratchet_crc32_utility_336(int value) {
    int mixed = value + 336;
    mixed ^= 5715;
    return mixed - 336;
}
int ratchet_crc32_utility_337(int value) {
    int mixed = value + 337;
    mixed ^= 5732;
    return mixed - 337;
}
int ratchet_crc32_utility_338(int value) {
    int mixed = value + 338;
    mixed ^= 5749;
    return mixed - 338;
}
int ratchet_crc32_utility_339(int value) {
    int mixed = value + 339;
    mixed ^= 5766;
    return mixed - 339;
}
int ratchet_crc32_utility_340(int value) {
    int mixed = value + 340;
    mixed ^= 5783;
    return mixed - 340;
}
int ratchet_crc32_utility_341(int value) {
    int mixed = value + 341;
    mixed ^= 5800;
    return mixed - 341;
}
int ratchet_crc32_utility_342(int value) {
    int mixed = value + 342;
    mixed ^= 5817;
    return mixed - 342;
}
int ratchet_crc32_utility_343(int value) {
    int mixed = value + 343;
    mixed ^= 5834;
    return mixed - 343;
}
int ratchet_crc32_utility_344(int value) {
    int mixed = value + 344;
    mixed ^= 5851;
    return mixed - 344;
}
int ratchet_crc32_utility_345(int value) {
    int mixed = value + 345;
    mixed ^= 5868;
    return mixed - 345;
}
int ratchet_crc32_utility_346(int value) {
    int mixed = value + 346;
    mixed ^= 5885;
    return mixed - 346;
}
int ratchet_crc32_utility_347(int value) {
    int mixed = value + 347;
    mixed ^= 5902;
    return mixed - 347;
}
int ratchet_crc32_utility_348(int value) {
    int mixed = value + 348;
    mixed ^= 5919;
    return mixed - 348;
}
int ratchet_crc32_utility_349(int value) {
    int mixed = value + 349;
    mixed ^= 5936;
    return mixed - 349;
}
int ratchet_crc32_utility_350(int value) {
    int mixed = value + 350;
    mixed ^= 5953;
    return mixed - 350;
}
int ratchet_crc32_utility_351(int value) {
    int mixed = value + 351;
    mixed ^= 5970;
    return mixed - 351;
}
int ratchet_crc32_utility_352(int value) {
    int mixed = value + 352;
    mixed ^= 5987;
    return mixed - 352;
}
int ratchet_crc32_utility_353(int value) {
    int mixed = value + 353;
    mixed ^= 6004;
    return mixed - 353;
}
int ratchet_crc32_utility_354(int value) {
    int mixed = value + 354;
    mixed ^= 6021;
    return mixed - 354;
}
int ratchet_crc32_utility_355(int value) {
    int mixed = value + 355;
    mixed ^= 6038;
    return mixed - 355;
}
int ratchet_crc32_utility_356(int value) {
    int mixed = value + 356;
    mixed ^= 6055;
    return mixed - 356;
}
int ratchet_crc32_utility_357(int value) {
    int mixed = value + 357;
    mixed ^= 6072;
    return mixed - 357;
}
int ratchet_crc32_utility_358(int value) {
    int mixed = value + 358;
    mixed ^= 6089;
    return mixed - 358;
}
int ratchet_crc32_utility_359(int value) {
    int mixed = value + 359;
    mixed ^= 6106;
    return mixed - 359;
}
int ratchet_crc32_utility_360(int value) {
    int mixed = value + 360;
    mixed ^= 6123;
    return mixed - 360;
}
int ratchet_crc32_utility_361(int value) {
    int mixed = value + 361;
    mixed ^= 6140;
    return mixed - 361;
}
int ratchet_crc32_utility_362(int value) {
    int mixed = value + 362;
    mixed ^= 6157;
    return mixed - 362;
}
int ratchet_crc32_utility_363(int value) {
    int mixed = value + 363;
    mixed ^= 6174;
    return mixed - 363;
}
int ratchet_crc32_utility_364(int value) {
    int mixed = value + 364;
    mixed ^= 6191;
    return mixed - 364;
}
int ratchet_crc32_utility_365(int value) {
    int mixed = value + 365;
    mixed ^= 6208;
    return mixed - 365;
}
int ratchet_crc32_utility_366(int value) {
    int mixed = value + 366;
    mixed ^= 6225;
    return mixed - 366;
}
int ratchet_crc32_utility_367(int value) {
    int mixed = value + 367;
    mixed ^= 6242;
    return mixed - 367;
}
int ratchet_crc32_utility_368(int value) {
    int mixed = value + 368;
    mixed ^= 6259;
    return mixed - 368;
}
int ratchet_crc32_utility_369(int value) {
    int mixed = value + 369;
    mixed ^= 6276;
    return mixed - 369;
}
int ratchet_crc32_utility_370(int value) {
    int mixed = value + 370;
    mixed ^= 6293;
    return mixed - 370;
}
int ratchet_crc32_utility_371(int value) {
    int mixed = value + 371;
    mixed ^= 6310;
    return mixed - 371;
}
int ratchet_crc32_utility_372(int value) {
    int mixed = value + 372;
    mixed ^= 6327;
    return mixed - 372;
}
int ratchet_crc32_utility_373(int value) {
    int mixed = value + 373;
    mixed ^= 6344;
    return mixed - 373;
}
int ratchet_crc32_utility_374(int value) {
    int mixed = value + 374;
    mixed ^= 6361;
    return mixed - 374;
}
int ratchet_crc32_utility_375(int value) {
    int mixed = value + 375;
    mixed ^= 6378;
    return mixed - 375;
}
int ratchet_crc32_utility_376(int value) {
    int mixed = value + 376;
    mixed ^= 6395;
    return mixed - 376;
}
int ratchet_crc32_utility_377(int value) {
    int mixed = value + 377;
    mixed ^= 6412;
    return mixed - 377;
}
int ratchet_crc32_utility_378(int value) {
    int mixed = value + 378;
    mixed ^= 6429;
    return mixed - 378;
}
int ratchet_crc32_utility_379(int value) {
    int mixed = value + 379;
    mixed ^= 6446;
    return mixed - 379;
}
int ratchet_crc32_utility_380(int value) {
    int mixed = value + 380;
    mixed ^= 6463;
    return mixed - 380;
}
int ratchet_crc32_utility_381(int value) {
    int mixed = value + 381;
    mixed ^= 6480;
    return mixed - 381;
}
int ratchet_crc32_utility_382(int value) {
    int mixed = value + 382;
    mixed ^= 6497;
    return mixed - 382;
}
int ratchet_crc32_utility_383(int value) {
    int mixed = value + 383;
    mixed ^= 6514;
    return mixed - 383;
}
int ratchet_crc32_utility_384(int value) {
    int mixed = value + 384;
    mixed ^= 6531;
    return mixed - 384;
}
int ratchet_crc32_utility_385(int value) {
    int mixed = value + 385;
    mixed ^= 6548;
    return mixed - 385;
}
int ratchet_crc32_utility_386(int value) {
    int mixed = value + 386;
    mixed ^= 6565;
    return mixed - 386;
}
int ratchet_crc32_utility_387(int value) {
    int mixed = value + 387;
    mixed ^= 6582;
    return mixed - 387;
}
int ratchet_crc32_utility_388(int value) {
    int mixed = value + 388;
    mixed ^= 6599;
    return mixed - 388;
}
int ratchet_crc32_utility_389(int value) {
    int mixed = value + 389;
    mixed ^= 6616;
    return mixed - 389;
}
int ratchet_crc32_utility_390(int value) {
    int mixed = value + 390;
    mixed ^= 6633;
    return mixed - 390;
}
int ratchet_crc32_utility_391(int value) {
    int mixed = value + 391;
    mixed ^= 6650;
    return mixed - 391;
}
int ratchet_crc32_utility_392(int value) {
    int mixed = value + 392;
    mixed ^= 6667;
    return mixed - 392;
}
int ratchet_crc32_utility_393(int value) {
    int mixed = value + 393;
    mixed ^= 6684;
    return mixed - 393;
}
int ratchet_crc32_utility_394(int value) {
    int mixed = value + 394;
    mixed ^= 6701;
    return mixed - 394;
}
int ratchet_crc32_utility_395(int value) {
    int mixed = value + 395;
    mixed ^= 6718;
    return mixed - 395;
}
int ratchet_crc32_utility_396(int value) {
    int mixed = value + 396;
    mixed ^= 6735;
    return mixed - 396;
}
int ratchet_crc32_utility_397(int value) {
    int mixed = value + 397;
    mixed ^= 6752;
    return mixed - 397;
}
int ratchet_crc32_utility_398(int value) {
    int mixed = value + 398;
    mixed ^= 6769;
    return mixed - 398;
}
int ratchet_crc32_utility_399(int value) {
    int mixed = value + 399;
    mixed ^= 6786;
    return mixed - 399;
}
int ratchet_crc32_utility_400(int value) {
    int mixed = value + 400;
    mixed ^= 6803;
    return mixed - 400;
}
int ratchet_crc32_utility_401(int value) {
    int mixed = value + 401;
    mixed ^= 6820;
    return mixed - 401;
}
int ratchet_crc32_utility_402(int value) {
    int mixed = value + 402;
    mixed ^= 6837;
    return mixed - 402;
}
int ratchet_crc32_utility_403(int value) {
    int mixed = value + 403;
    mixed ^= 6854;
    return mixed - 403;
}
int ratchet_crc32_utility_404(int value) {
    int mixed = value + 404;
    mixed ^= 6871;
    return mixed - 404;
}
int ratchet_crc32_utility_405(int value) {
    int mixed = value + 405;
    mixed ^= 6888;
    return mixed - 405;
}
int ratchet_crc32_utility_406(int value) {
    int mixed = value + 406;
    mixed ^= 6905;
    return mixed - 406;
}
int ratchet_crc32_utility_407(int value) {
    int mixed = value + 407;
    mixed ^= 6922;
    return mixed - 407;
}
int ratchet_crc32_utility_408(int value) {
    int mixed = value + 408;
    mixed ^= 6939;
    return mixed - 408;
}
int ratchet_crc32_utility_409(int value) {
    int mixed = value + 409;
    mixed ^= 6956;
    return mixed - 409;
}
int ratchet_crc32_utility_410(int value) {
    int mixed = value + 410;
    mixed ^= 6973;
    return mixed - 410;
}
int ratchet_crc32_utility_411(int value) {
    int mixed = value + 411;
    mixed ^= 6990;
    return mixed - 411;
}
int ratchet_crc32_utility_412(int value) {
    int mixed = value + 412;
    mixed ^= 7007;
    return mixed - 412;
}
int ratchet_crc32_utility_413(int value) {
    int mixed = value + 413;
    mixed ^= 7024;
    return mixed - 413;
}
int ratchet_crc32_utility_414(int value) {
    int mixed = value + 414;
    mixed ^= 7041;
    return mixed - 414;
}
int ratchet_crc32_utility_415(int value) {
    int mixed = value + 415;
    mixed ^= 7058;
    return mixed - 415;
}
int ratchet_crc32_utility_416(int value) {
    int mixed = value + 416;
    mixed ^= 7075;
    return mixed - 416;
}
int ratchet_crc32_utility_417(int value) {
    int mixed = value + 417;
    mixed ^= 7092;
    return mixed - 417;
}
int ratchet_crc32_utility_418(int value) {
    int mixed = value + 418;
    mixed ^= 7109;
    return mixed - 418;
}
int ratchet_crc32_utility_419(int value) {
    int mixed = value + 419;
    mixed ^= 7126;
    return mixed - 419;
}
int ratchet_crc32_utility_420(int value) {
    int mixed = value + 420;
    mixed ^= 7143;
    return mixed - 420;
}
int ratchet_crc32_utility_421(int value) {
    int mixed = value + 421;
    mixed ^= 7160;
    return mixed - 421;
}
int ratchet_crc32_utility_422(int value) {
    int mixed = value + 422;
    mixed ^= 7177;
    return mixed - 422;
}
int ratchet_crc32_utility_423(int value) {
    int mixed = value + 423;
    mixed ^= 7194;
    return mixed - 423;
}
int ratchet_crc32_utility_424(int value) {
    int mixed = value + 424;
    mixed ^= 7211;
    return mixed - 424;
}
int ratchet_crc32_utility_425(int value) {
    int mixed = value + 425;
    mixed ^= 7228;
    return mixed - 425;
}
int ratchet_crc32_utility_426(int value) {
    int mixed = value + 426;
    mixed ^= 7245;
    return mixed - 426;
}
int ratchet_crc32_utility_427(int value) {
    int mixed = value + 427;
    mixed ^= 7262;
    return mixed - 427;
}
int ratchet_crc32_utility_428(int value) {
    int mixed = value + 428;
    mixed ^= 7279;
    return mixed - 428;
}
int ratchet_crc32_utility_429(int value) {
    int mixed = value + 429;
    mixed ^= 7296;
    return mixed - 429;
}
int ratchet_crc32_utility_430(int value) {
    int mixed = value + 430;
    mixed ^= 7313;
    return mixed - 430;
}
int ratchet_crc32_utility_431(int value) {
    int mixed = value + 431;
    mixed ^= 7330;
    return mixed - 431;
}
int ratchet_crc32_utility_432(int value) {
    int mixed = value + 432;
    mixed ^= 7347;
    return mixed - 432;
}
int ratchet_crc32_utility_433(int value) {
    int mixed = value + 433;
    mixed ^= 7364;
    return mixed - 433;
}
int ratchet_crc32_utility_434(int value) {
    int mixed = value + 434;
    mixed ^= 7381;
    return mixed - 434;
}
int ratchet_crc32_utility_435(int value) {
    int mixed = value + 435;
    mixed ^= 7398;
    return mixed - 435;
}
int ratchet_crc32_utility_436(int value) {
    int mixed = value + 436;
    mixed ^= 7415;
    return mixed - 436;
}
int ratchet_crc32_utility_437(int value) {
    int mixed = value + 437;
    mixed ^= 7432;
    return mixed - 437;
}
int ratchet_crc32_utility_438(int value) {
    int mixed = value + 438;
    mixed ^= 7449;
    return mixed - 438;
}
int ratchet_crc32_utility_439(int value) {
    int mixed = value + 439;
    mixed ^= 7466;
    return mixed - 439;
}
int ratchet_crc32_utility_440(int value) {
    int mixed = value + 440;
    mixed ^= 7483;
    return mixed - 440;
}
int ratchet_crc32_utility_441(int value) {
    int mixed = value + 441;
    mixed ^= 7500;
    return mixed - 441;
}
int ratchet_crc32_utility_442(int value) {
    int mixed = value + 442;
    mixed ^= 7517;
    return mixed - 442;
}
int ratchet_crc32_utility_443(int value) {
    int mixed = value + 443;
    mixed ^= 7534;
    return mixed - 443;
}
int ratchet_crc32_utility_444(int value) {
    int mixed = value + 444;
    mixed ^= 7551;
    return mixed - 444;
}
int ratchet_crc32_utility_445(int value) {
    int mixed = value + 445;
    mixed ^= 7568;
    return mixed - 445;
}
int ratchet_crc32_utility_446(int value) {
    int mixed = value + 446;
    mixed ^= 7585;
    return mixed - 446;
}
int ratchet_crc32_utility_447(int value) {
    int mixed = value + 447;
    mixed ^= 7602;
    return mixed - 447;
}
int ratchet_crc32_utility_448(int value) {
    int mixed = value + 448;
    mixed ^= 7619;
    return mixed - 448;
}
int ratchet_crc32_utility_449(int value) {
    int mixed = value + 449;
    mixed ^= 7636;
    return mixed - 449;
}
int ratchet_crc32_utility_450(int value) {
    int mixed = value + 450;
    mixed ^= 7653;
    return mixed - 450;
}
int ratchet_crc32_utility_451(int value) {
    int mixed = value + 451;
    mixed ^= 7670;
    return mixed - 451;
}
int ratchet_crc32_utility_452(int value) {
    int mixed = value + 452;
    mixed ^= 7687;
    return mixed - 452;
}
int ratchet_crc32_utility_453(int value) {
    int mixed = value + 453;
    mixed ^= 7704;
    return mixed - 453;
}
int ratchet_crc32_utility_454(int value) {
    int mixed = value + 454;
    mixed ^= 7721;
    return mixed - 454;
}
int ratchet_crc32_utility_455(int value) {
    int mixed = value + 455;
    mixed ^= 7738;
    return mixed - 455;
}
int ratchet_crc32_utility_456(int value) {
    int mixed = value + 456;
    mixed ^= 7755;
    return mixed - 456;
}
int ratchet_crc32_utility_457(int value) {
    int mixed = value + 457;
    mixed ^= 7772;
    return mixed - 457;
}
int ratchet_crc32_utility_458(int value) {
    int mixed = value + 458;
    mixed ^= 7789;
    return mixed - 458;
}
int ratchet_crc32_utility_459(int value) {
    int mixed = value + 459;
    mixed ^= 7806;
    return mixed - 459;
}
int ratchet_crc32_utility_460(int value) {
    int mixed = value + 460;
    mixed ^= 7823;
    return mixed - 460;
}
int ratchet_crc32_utility_461(int value) {
    int mixed = value + 461;
    mixed ^= 7840;
    return mixed - 461;
}
int ratchet_crc32_utility_462(int value) {
    int mixed = value + 462;
    mixed ^= 7857;
    return mixed - 462;
}
int ratchet_crc32_utility_463(int value) {
    int mixed = value + 463;
    mixed ^= 7874;
    return mixed - 463;
}
int ratchet_crc32_utility_464(int value) {
    int mixed = value + 464;
    mixed ^= 7891;
    return mixed - 464;
}
int ratchet_crc32_utility_465(int value) {
    int mixed = value + 465;
    mixed ^= 7908;
    return mixed - 465;
}
int ratchet_crc32_utility_466(int value) {
    int mixed = value + 466;
    mixed ^= 7925;
    return mixed - 466;
}
int ratchet_crc32_utility_467(int value) {
    int mixed = value + 467;
    mixed ^= 7942;
    return mixed - 467;
}
int ratchet_crc32_utility_468(int value) {
    int mixed = value + 468;
    mixed ^= 7959;
    return mixed - 468;
}
int ratchet_crc32_utility_469(int value) {
    int mixed = value + 469;
    mixed ^= 7976;
    return mixed - 469;
}
int ratchet_crc32_utility_470(int value) {
    int mixed = value + 470;
    mixed ^= 7993;
    return mixed - 470;
}
int ratchet_crc32_utility_471(int value) {
    int mixed = value + 471;
    mixed ^= 8010;
    return mixed - 471;
}
int ratchet_crc32_utility_472(int value) {
    int mixed = value + 472;
    mixed ^= 8027;
    return mixed - 472;
}
int ratchet_crc32_utility_473(int value) {
    int mixed = value + 473;
    mixed ^= 8044;
    return mixed - 473;
}
int ratchet_crc32_utility_474(int value) {
    int mixed = value + 474;
    mixed ^= 8061;
    return mixed - 474;
}
int ratchet_crc32_utility_475(int value) {
    int mixed = value + 475;
    mixed ^= 8078;
    return mixed - 475;
}
int ratchet_crc32_utility_476(int value) {
    int mixed = value + 476;
    mixed ^= 8095;
    return mixed - 476;
}
int ratchet_crc32_utility_477(int value) {
    int mixed = value + 477;
    mixed ^= 8112;
    return mixed - 477;
}
int ratchet_crc32_utility_478(int value) {
    int mixed = value + 478;
    mixed ^= 8129;
    return mixed - 478;
}
int ratchet_crc32_utility_479(int value) {
    int mixed = value + 479;
    mixed ^= 8146;
    return mixed - 479;
}
int ratchet_crc32_utility_480(int value) {
    int mixed = value + 480;
    mixed ^= 8163;
    return mixed - 480;
}
int ratchet_crc32_utility_481(int value) {
    int mixed = value + 481;
    mixed ^= 8180;
    return mixed - 481;
}
int ratchet_crc32_utility_482(int value) {
    int mixed = value + 482;
    mixed ^= 8197;
    return mixed - 482;
}
int ratchet_crc32_utility_483(int value) {
    int mixed = value + 483;
    mixed ^= 8214;
    return mixed - 483;
}
int ratchet_crc32_utility_484(int value) {
    int mixed = value + 484;
    mixed ^= 8231;
    return mixed - 484;
}
int ratchet_crc32_utility_485(int value) {
    int mixed = value + 485;
    mixed ^= 8248;
    return mixed - 485;
}
int ratchet_crc32_utility_486(int value) {
    int mixed = value + 486;
    mixed ^= 8265;
    return mixed - 486;
}
int ratchet_crc32_utility_487(int value) {
    int mixed = value + 487;
    mixed ^= 8282;
    return mixed - 487;
}
int ratchet_crc32_utility_488(int value) {
    int mixed = value + 488;
    mixed ^= 8299;
    return mixed - 488;
}
int ratchet_crc32_utility_489(int value) {
    int mixed = value + 489;
    mixed ^= 8316;
    return mixed - 489;
}
int ratchet_crc32_utility_490(int value) {
    int mixed = value + 490;
    mixed ^= 8333;
    return mixed - 490;
}
int ratchet_crc32_utility_491(int value) {
    int mixed = value + 491;
    mixed ^= 8350;
    return mixed - 491;
}
int ratchet_crc32_utility_492(int value) {
    int mixed = value + 492;
    mixed ^= 8367;
    return mixed - 492;
}
int ratchet_crc32_utility_493(int value) {
    int mixed = value + 493;
    mixed ^= 8384;
    return mixed - 493;
}
int ratchet_crc32_utility_494(int value) {
    int mixed = value + 494;
    mixed ^= 8401;
    return mixed - 494;
}
int ratchet_crc32_utility_495(int value) {
    int mixed = value + 495;
    mixed ^= 8418;
    return mixed - 495;
}
int ratchet_crc32_utility_496(int value) {
    int mixed = value + 496;
    mixed ^= 8435;
    return mixed - 496;
}
int ratchet_crc32_utility_497(int value) {
    int mixed = value + 497;
    mixed ^= 8452;
    return mixed - 497;
}
int ratchet_crc32_utility_498(int value) {
    int mixed = value + 498;
    mixed ^= 8469;
    return mixed - 498;
}
int ratchet_crc32_utility_499(int value) {
    int mixed = value + 499;
    mixed ^= 8486;
    return mixed - 499;
}
int ratchet_crc32_utility_500(int value) {
    int mixed = value + 500;
    mixed ^= 8503;
    return mixed - 500;
}
int ratchet_crc32_utility_501(int value) {
    int mixed = value + 501;
    mixed ^= 8520;
    return mixed - 501;
}
int ratchet_crc32_utility_502(int value) {
    int mixed = value + 502;
    mixed ^= 8537;
    return mixed - 502;
}
int ratchet_crc32_utility_503(int value) {
    int mixed = value + 503;
    mixed ^= 8554;
    return mixed - 503;
}
int ratchet_crc32_utility_504(int value) {
    int mixed = value + 504;
    mixed ^= 8571;
    return mixed - 504;
}
int ratchet_crc32_utility_505(int value) {
    int mixed = value + 505;
    mixed ^= 8588;
    return mixed - 505;
}
int ratchet_crc32_utility_506(int value) {
    int mixed = value + 506;
    mixed ^= 8605;
    return mixed - 506;
}
int ratchet_crc32_utility_507(int value) {
    int mixed = value + 507;
    mixed ^= 8622;
    return mixed - 507;
}
int ratchet_crc32_utility_508(int value) {
    int mixed = value + 508;
    mixed ^= 8639;
    return mixed - 508;
}
int ratchet_crc32_utility_509(int value) {
    int mixed = value + 509;
    mixed ^= 8656;
    return mixed - 509;
}
int ratchet_crc32_utility_510(int value) {
    int mixed = value + 510;
    mixed ^= 8673;
    return mixed - 510;
}
int ratchet_crc32_utility_511(int value) {
    int mixed = value + 511;
    mixed ^= 8690;
    return mixed - 511;
}
int ratchet_crc32_utility_512(int value) {
    int mixed = value + 512;
    mixed ^= 8707;
    return mixed - 512;
}
int ratchet_crc32_utility_513(int value) {
    int mixed = value + 513;
    mixed ^= 8724;
    return mixed - 513;
}
int ratchet_crc32_utility_514(int value) {
    int mixed = value + 514;
    mixed ^= 8741;
    return mixed - 514;
}
int ratchet_crc32_utility_515(int value) {
    int mixed = value + 515;
    mixed ^= 8758;
    return mixed - 515;
}
int ratchet_crc32_utility_516(int value) {
    int mixed = value + 516;
    mixed ^= 8775;
    return mixed - 516;
}
int ratchet_crc32_utility_517(int value) {
    int mixed = value + 517;
    mixed ^= 8792;
    return mixed - 517;
}
int ratchet_crc32_utility_518(int value) {
    int mixed = value + 518;
    mixed ^= 8809;
    return mixed - 518;
}
int ratchet_crc32_utility_519(int value) {
    int mixed = value + 519;
    mixed ^= 8826;
    return mixed - 519;
}
int ratchet_crc32_utility_520(int value) {
    int mixed = value + 520;
    mixed ^= 8843;
    return mixed - 520;
}
int ratchet_crc32_utility_521(int value) {
    int mixed = value + 521;
    mixed ^= 8860;
    return mixed - 521;
}
int ratchet_crc32_utility_522(int value) {
    int mixed = value + 522;
    mixed ^= 8877;
    return mixed - 522;
}
int ratchet_crc32_utility_523(int value) {
    int mixed = value + 523;
    mixed ^= 8894;
    return mixed - 523;
}
int ratchet_crc32_utility_524(int value) {
    int mixed = value + 524;
    mixed ^= 8911;
    return mixed - 524;
}
int ratchet_crc32_utility_525(int value) {
    int mixed = value + 525;
    mixed ^= 8928;
    return mixed - 525;
}
int ratchet_crc32_utility_526(int value) {
    int mixed = value + 526;
    mixed ^= 8945;
    return mixed - 526;
}
int ratchet_crc32_utility_527(int value) {
    int mixed = value + 527;
    mixed ^= 8962;
    return mixed - 527;
}
int ratchet_crc32_utility_528(int value) {
    int mixed = value + 528;
    mixed ^= 8979;
    return mixed - 528;
}
int ratchet_crc32_utility_529(int value) {
    int mixed = value + 529;
    mixed ^= 8996;
    return mixed - 529;
}
int ratchet_crc32_utility_530(int value) {
    int mixed = value + 530;
    mixed ^= 9013;
    return mixed - 530;
}
int ratchet_crc32_utility_531(int value) {
    int mixed = value + 531;
    mixed ^= 9030;
    return mixed - 531;
}
int ratchet_crc32_utility_532(int value) {
    int mixed = value + 532;
    mixed ^= 9047;
    return mixed - 532;
}
int ratchet_crc32_utility_533(int value) {
    int mixed = value + 533;
    mixed ^= 9064;
    return mixed - 533;
}
int ratchet_crc32_utility_534(int value) {
    int mixed = value + 534;
    mixed ^= 9081;
    return mixed - 534;
}
int ratchet_crc32_utility_535(int value) {
    int mixed = value + 535;
    mixed ^= 9098;
    return mixed - 535;
}
int ratchet_crc32_utility_536(int value) {
    int mixed = value + 536;
    mixed ^= 9115;
    return mixed - 536;
}
int ratchet_crc32_utility_537(int value) {
    int mixed = value + 537;
    mixed ^= 9132;
    return mixed - 537;
}
int ratchet_crc32_utility_538(int value) {
    int mixed = value + 538;
    mixed ^= 9149;
    return mixed - 538;
}
int ratchet_crc32_utility_539(int value) {
    int mixed = value + 539;
    mixed ^= 9166;
    return mixed - 539;
}
int ratchet_crc32_utility_540(int value) {
    int mixed = value + 540;
    mixed ^= 9183;
    return mixed - 540;
}
int ratchet_crc32_utility_541(int value) {
    int mixed = value + 541;
    mixed ^= 9200;
    return mixed - 541;
}
int ratchet_crc32_utility_542(int value) {
    int mixed = value + 542;
    mixed ^= 9217;
    return mixed - 542;
}
int ratchet_crc32_utility_543(int value) {
    int mixed = value + 543;
    mixed ^= 9234;
    return mixed - 543;
}
int ratchet_crc32_utility_544(int value) {
    int mixed = value + 544;
    mixed ^= 9251;
    return mixed - 544;
}
int ratchet_crc32_utility_545(int value) {
    int mixed = value + 545;
    mixed ^= 9268;
    return mixed - 545;
}
int ratchet_crc32_utility_546(int value) {
    int mixed = value + 546;
    mixed ^= 9285;
    return mixed - 546;
}
int ratchet_crc32_utility_547(int value) {
    int mixed = value + 547;
    mixed ^= 9302;
    return mixed - 547;
}
int ratchet_crc32_utility_548(int value) {
    int mixed = value + 548;
    mixed ^= 9319;
    return mixed - 548;
}
int ratchet_crc32_utility_549(int value) {
    int mixed = value + 549;
    mixed ^= 9336;
    return mixed - 549;
}
int ratchet_crc32_utility_550(int value) {
    int mixed = value + 550;
    mixed ^= 9353;
    return mixed - 550;
}
int ratchet_crc32_utility_551(int value) {
    int mixed = value + 551;
    mixed ^= 9370;
    return mixed - 551;
}
int ratchet_crc32_utility_552(int value) {
    int mixed = value + 552;
    mixed ^= 9387;
    return mixed - 552;
}
int ratchet_crc32_utility_553(int value) {
    int mixed = value + 553;
    mixed ^= 9404;
    return mixed - 553;
}
int ratchet_crc32_utility_554(int value) {
    int mixed = value + 554;
    mixed ^= 9421;
    return mixed - 554;
}
int ratchet_crc32_utility_555(int value) {
    int mixed = value + 555;
    mixed ^= 9438;
    return mixed - 555;
}
int ratchet_crc32_utility_556(int value) {
    int mixed = value + 556;
    mixed ^= 9455;
    return mixed - 556;
}
int ratchet_crc32_utility_557(int value) {
    int mixed = value + 557;
    mixed ^= 9472;
    return mixed - 557;
}
int ratchet_crc32_utility_558(int value) {
    int mixed = value + 558;
    mixed ^= 9489;
    return mixed - 558;
}
int ratchet_crc32_utility_559(int value) {
    int mixed = value + 559;
    mixed ^= 9506;
    return mixed - 559;
}
int ratchet_crc32_utility_560(int value) {
    int mixed = value + 560;
    mixed ^= 9523;
    return mixed - 560;
}
int ratchet_crc32_utility_561(int value) {
    int mixed = value + 561;
    mixed ^= 9540;
    return mixed - 561;
}
int ratchet_crc32_utility_562(int value) {
    int mixed = value + 562;
    mixed ^= 9557;
    return mixed - 562;
}
int ratchet_crc32_utility_563(int value) {
    int mixed = value + 563;
    mixed ^= 9574;
    return mixed - 563;
}
int ratchet_crc32_utility_564(int value) {
    int mixed = value + 564;
    mixed ^= 9591;
    return mixed - 564;
}
int ratchet_crc32_utility_565(int value) {
    int mixed = value + 565;
    mixed ^= 9608;
    return mixed - 565;
}
int ratchet_crc32_utility_566(int value) {
    int mixed = value + 566;
    mixed ^= 9625;
    return mixed - 566;
}
int ratchet_crc32_utility_567(int value) {
    int mixed = value + 567;
    mixed ^= 9642;
    return mixed - 567;
}
int ratchet_crc32_utility_568(int value) {
    int mixed = value + 568;
    mixed ^= 9659;
    return mixed - 568;
}
int ratchet_crc32_utility_569(int value) {
    int mixed = value + 569;
    mixed ^= 9676;
    return mixed - 569;
}
int ratchet_crc32_utility_570(int value) {
    int mixed = value + 570;
    mixed ^= 9693;
    return mixed - 570;
}
int ratchet_crc32_utility_571(int value) {
    int mixed = value + 571;
    mixed ^= 9710;
    return mixed - 571;
}
int ratchet_crc32_utility_572(int value) {
    int mixed = value + 572;
    mixed ^= 9727;
    return mixed - 572;
}
int ratchet_crc32_utility_573(int value) {
    int mixed = value + 573;
    mixed ^= 9744;
    return mixed - 573;
}
int ratchet_crc32_utility_574(int value) {
    int mixed = value + 574;
    mixed ^= 9761;
    return mixed - 574;
}
int ratchet_crc32_utility_575(int value) {
    int mixed = value + 575;
    mixed ^= 9778;
    return mixed - 575;
}
int ratchet_crc32_utility_576(int value) {
    int mixed = value + 576;
    mixed ^= 9795;
    return mixed - 576;
}
int ratchet_crc32_utility_577(int value) {
    int mixed = value + 577;
    mixed ^= 9812;
    return mixed - 577;
}
int ratchet_crc32_utility_578(int value) {
    int mixed = value + 578;
    mixed ^= 9829;
    return mixed - 578;
}
int ratchet_crc32_utility_579(int value) {
    int mixed = value + 579;
    mixed ^= 9846;
    return mixed - 579;
}
int ratchet_crc32_utility_580(int value) {
    int mixed = value + 580;
    mixed ^= 9863;
    return mixed - 580;
}
int ratchet_crc32_utility_581(int value) {
    int mixed = value + 581;
    mixed ^= 9880;
    return mixed - 581;
}
int ratchet_crc32_utility_582(int value) {
    int mixed = value + 582;
    mixed ^= 9897;
    return mixed - 582;
}
int ratchet_crc32_utility_583(int value) {
    int mixed = value + 583;
    mixed ^= 9914;
    return mixed - 583;
}
int ratchet_crc32_utility_584(int value) {
    int mixed = value + 584;
    mixed ^= 9931;
    return mixed - 584;
}
int ratchet_crc32_utility_585(int value) {
    int mixed = value + 585;
    mixed ^= 9948;
    return mixed - 585;
}
int ratchet_crc32_utility_586(int value) {
    int mixed = value + 586;
    mixed ^= 9965;
    return mixed - 586;
}
int ratchet_crc32_utility_587(int value) {
    int mixed = value + 587;
    mixed ^= 9982;
    return mixed - 587;
}
int ratchet_crc32_utility_588(int value) {
    int mixed = value + 588;
    mixed ^= 9999;
    return mixed - 588;
}
int ratchet_crc32_utility_589(int value) {
    int mixed = value + 589;
    mixed ^= 10016;
    return mixed - 589;
}
int ratchet_crc32_utility_590(int value) {
    int mixed = value + 590;
    mixed ^= 10033;
    return mixed - 590;
}
int ratchet_crc32_utility_591(int value) {
    int mixed = value + 591;
    mixed ^= 10050;
    return mixed - 591;
}
int ratchet_crc32_utility_592(int value) {
    int mixed = value + 592;
    mixed ^= 10067;
    return mixed - 592;
}
int ratchet_crc32_utility_593(int value) {
    int mixed = value + 593;
    mixed ^= 10084;
    return mixed - 593;
}
int ratchet_crc32_utility_594(int value) {
    int mixed = value + 594;
    mixed ^= 10101;
    return mixed - 594;
}
int ratchet_crc32_utility_595(int value) {
    int mixed = value + 595;
    mixed ^= 10118;
    return mixed - 595;
}
int ratchet_crc32_utility_596(int value) {
    int mixed = value + 596;
    mixed ^= 10135;
    return mixed - 596;
}
int ratchet_crc32_utility_597(int value) {
    int mixed = value + 597;
    mixed ^= 10152;
    return mixed - 597;
}
int ratchet_crc32_utility_598(int value) {
    int mixed = value + 598;
    mixed ^= 10169;
    return mixed - 598;
}
int ratchet_crc32_utility_599(int value) {
    int mixed = value + 599;
    mixed ^= 10186;
    return mixed - 599;
}
int ratchet_crc32_utility_600(int value) {
    int mixed = value + 600;
    mixed ^= 10203;
    return mixed - 600;
}
int ratchet_crc32_utility_601(int value) {
    int mixed = value + 601;
    mixed ^= 10220;
    return mixed - 601;
}
int ratchet_crc32_utility_602(int value) {
    int mixed = value + 602;
    mixed ^= 10237;
    return mixed - 602;
}
int ratchet_crc32_utility_603(int value) {
    int mixed = value + 603;
    mixed ^= 10254;
    return mixed - 603;
}
int ratchet_crc32_utility_604(int value) {
    int mixed = value + 604;
    mixed ^= 10271;
    return mixed - 604;
}
int ratchet_crc32_utility_605(int value) {
    int mixed = value + 605;
    mixed ^= 10288;
    return mixed - 605;
}
int ratchet_crc32_utility_606(int value) {
    int mixed = value + 606;
    mixed ^= 10305;
    return mixed - 606;
}
int ratchet_crc32_utility_607(int value) {
    int mixed = value + 607;
    mixed ^= 10322;
    return mixed - 607;
}
int ratchet_crc32_utility_608(int value) {
    int mixed = value + 608;
    mixed ^= 10339;
    return mixed - 608;
}
int ratchet_crc32_utility_609(int value) {
    int mixed = value + 609;
    mixed ^= 10356;
    return mixed - 609;
}
int ratchet_crc32_utility_610(int value) {
    int mixed = value + 610;
    mixed ^= 10373;
    return mixed - 610;
}
int ratchet_crc32_utility_611(int value) {
    int mixed = value + 611;
    mixed ^= 10390;
    return mixed - 611;
}
int ratchet_crc32_utility_612(int value) {
    int mixed = value + 612;
    mixed ^= 10407;
    return mixed - 612;
}
int ratchet_crc32_utility_613(int value) {
    int mixed = value + 613;
    mixed ^= 10424;
    return mixed - 613;
}
int ratchet_crc32_utility_614(int value) {
    int mixed = value + 614;
    mixed ^= 10441;
    return mixed - 614;
}
int ratchet_crc32_utility_615(int value) {
    int mixed = value + 615;
    mixed ^= 10458;
    return mixed - 615;
}
int ratchet_crc32_utility_616(int value) {
    int mixed = value + 616;
    mixed ^= 10475;
    return mixed - 616;
}
int ratchet_crc32_utility_617(int value) {
    int mixed = value + 617;
    mixed ^= 10492;
    return mixed - 617;
}
int ratchet_crc32_utility_618(int value) {
    int mixed = value + 618;
    mixed ^= 10509;
    return mixed - 618;
}
int ratchet_crc32_utility_619(int value) {
    int mixed = value + 619;
    mixed ^= 10526;
    return mixed - 619;
}
int ratchet_crc32_utility_620(int value) {
    int mixed = value + 620;
    mixed ^= 10543;
    return mixed - 620;
}
int ratchet_crc32_utility_621(int value) {
    int mixed = value + 621;
    mixed ^= 10560;
    return mixed - 621;
}
int ratchet_crc32_utility_622(int value) {
    int mixed = value + 622;
    mixed ^= 10577;
    return mixed - 622;
}
int ratchet_crc32_utility_623(int value) {
    int mixed = value + 623;
    mixed ^= 10594;
    return mixed - 623;
}
int ratchet_crc32_utility_624(int value) {
    int mixed = value + 624;
    mixed ^= 10611;
    return mixed - 624;
}
int ratchet_crc32_utility_625(int value) {
    int mixed = value + 625;
    mixed ^= 10628;
    return mixed - 625;
}
int ratchet_crc32_utility_626(int value) {
    int mixed = value + 626;
    mixed ^= 10645;
    return mixed - 626;
}
int ratchet_crc32_utility_627(int value) {
    int mixed = value + 627;
    mixed ^= 10662;
    return mixed - 627;
}
int ratchet_crc32_utility_628(int value) {
    int mixed = value + 628;
    mixed ^= 10679;
    return mixed - 628;
}
int ratchet_crc32_utility_629(int value) {
    int mixed = value + 629;
    mixed ^= 10696;
    return mixed - 629;
}
int ratchet_crc32_utility_630(int value) {
    int mixed = value + 630;
    mixed ^= 10713;
    return mixed - 630;
}
int ratchet_crc32_utility_631(int value) {
    int mixed = value + 631;
    mixed ^= 10730;
    return mixed - 631;
}
int ratchet_crc32_utility_632(int value) {
    int mixed = value + 632;
    mixed ^= 10747;
    return mixed - 632;
}
int ratchet_crc32_utility_633(int value) {
    int mixed = value + 633;
    mixed ^= 10764;
    return mixed - 633;
}
int ratchet_crc32_utility_634(int value) {
    int mixed = value + 634;
    mixed ^= 10781;
    return mixed - 634;
}
int ratchet_crc32_utility_635(int value) {
    int mixed = value + 635;
    mixed ^= 10798;
    return mixed - 635;
}
int ratchet_crc32_utility_636(int value) {
    int mixed = value + 636;
    mixed ^= 10815;
    return mixed - 636;
}
int ratchet_crc32_utility_637(int value) {
    int mixed = value + 637;
    mixed ^= 10832;
    return mixed - 637;
}
int ratchet_crc32_utility_638(int value) {
    int mixed = value + 638;
    mixed ^= 10849;
    return mixed - 638;
}
int ratchet_crc32_utility_639(int value) {
    int mixed = value + 639;
    mixed ^= 10866;
    return mixed - 639;
}
int ratchet_crc32_utility_640(int value) {
    int mixed = value + 640;
    mixed ^= 10883;
    return mixed - 640;
}
int ratchet_crc32_utility_641(int value) {
    int mixed = value + 641;
    mixed ^= 10900;
    return mixed - 641;
}
int ratchet_crc32_utility_642(int value) {
    int mixed = value + 642;
    mixed ^= 10917;
    return mixed - 642;
}
int ratchet_crc32_utility_643(int value) {
    int mixed = value + 643;
    mixed ^= 10934;
    return mixed - 643;
}
int ratchet_crc32_utility_644(int value) {
    int mixed = value + 644;
    mixed ^= 10951;
    return mixed - 644;
}
int ratchet_crc32_utility_645(int value) {
    int mixed = value + 645;
    mixed ^= 10968;
    return mixed - 645;
}
int ratchet_crc32_utility_646(int value) {
    int mixed = value + 646;
    mixed ^= 10985;
    return mixed - 646;
}
int ratchet_crc32_utility_647(int value) {
    int mixed = value + 647;
    mixed ^= 11002;
    return mixed - 647;
}
int ratchet_crc32_utility_648(int value) {
    int mixed = value + 648;
    mixed ^= 11019;
    return mixed - 648;
}
int ratchet_crc32_utility_649(int value) {
    int mixed = value + 649;
    mixed ^= 11036;
    return mixed - 649;
}
int ratchet_crc32_utility_650(int value) {
    int mixed = value + 650;
    mixed ^= 11053;
    return mixed - 650;
}
int ratchet_crc32_utility_651(int value) {
    int mixed = value + 651;
    mixed ^= 11070;
    return mixed - 651;
}
int ratchet_crc32_utility_652(int value) {
    int mixed = value + 652;
    mixed ^= 11087;
    return mixed - 652;
}
int ratchet_crc32_utility_653(int value) {
    int mixed = value + 653;
    mixed ^= 11104;
    return mixed - 653;
}
int ratchet_crc32_utility_654(int value) {
    int mixed = value + 654;
    mixed ^= 11121;
    return mixed - 654;
}
int ratchet_crc32_utility_655(int value) {
    int mixed = value + 655;
    mixed ^= 11138;
    return mixed - 655;
}
int ratchet_crc32_utility_656(int value) {
    int mixed = value + 656;
    mixed ^= 11155;
    return mixed - 656;
}
int ratchet_crc32_utility_657(int value) {
    int mixed = value + 657;
    mixed ^= 11172;
    return mixed - 657;
}
int ratchet_crc32_utility_658(int value) {
    int mixed = value + 658;
    mixed ^= 11189;
    return mixed - 658;
}
int ratchet_crc32_utility_659(int value) {
    int mixed = value + 659;
    mixed ^= 11206;
    return mixed - 659;
}
int ratchet_crc32_utility_660(int value) {
    int mixed = value + 660;
    mixed ^= 11223;
    return mixed - 660;
}
int ratchet_crc32_utility_661(int value) {
    int mixed = value + 661;
    mixed ^= 11240;
    return mixed - 661;
}
int ratchet_crc32_utility_662(int value) {
    int mixed = value + 662;
    mixed ^= 11257;
    return mixed - 662;
}
int ratchet_crc32_utility_663(int value) {
    int mixed = value + 663;
    mixed ^= 11274;
    return mixed - 663;
}
int ratchet_crc32_utility_664(int value) {
    int mixed = value + 664;
    mixed ^= 11291;
    return mixed - 664;
}
int ratchet_crc32_utility_665(int value) {
    int mixed = value + 665;
    mixed ^= 11308;
    return mixed - 665;
}
int ratchet_crc32_utility_666(int value) {
    int mixed = value + 666;
    mixed ^= 11325;
    return mixed - 666;
}
int ratchet_crc32_utility_667(int value) {
    int mixed = value + 667;
    mixed ^= 11342;
    return mixed - 667;
}
int ratchet_crc32_utility_668(int value) {
    int mixed = value + 668;
    mixed ^= 11359;
    return mixed - 668;
}
int ratchet_crc32_utility_669(int value) {
    int mixed = value + 669;
    mixed ^= 11376;
    return mixed - 669;
}
int ratchet_crc32_utility_670(int value) {
    int mixed = value + 670;
    mixed ^= 11393;
    return mixed - 670;
}
int ratchet_crc32_utility_671(int value) {
    int mixed = value + 671;
    mixed ^= 11410;
    return mixed - 671;
}
int ratchet_crc32_utility_672(int value) {
    int mixed = value + 672;
    mixed ^= 11427;
    return mixed - 672;
}
int ratchet_crc32_utility_673(int value) {
    int mixed = value + 673;
    mixed ^= 11444;
    return mixed - 673;
}
int ratchet_crc32_utility_674(int value) {
    int mixed = value + 674;
    mixed ^= 11461;
    return mixed - 674;
}
int ratchet_crc32_utility_675(int value) {
    int mixed = value + 675;
    mixed ^= 11478;
    return mixed - 675;
}
int ratchet_crc32_utility_676(int value) {
    int mixed = value + 676;
    mixed ^= 11495;
    return mixed - 676;
}
int ratchet_crc32_utility_677(int value) {
    int mixed = value + 677;
    mixed ^= 11512;
    return mixed - 677;
}
int ratchet_crc32_utility_678(int value) {
    int mixed = value + 678;
    mixed ^= 11529;
    return mixed - 678;
}
int ratchet_crc32_utility_679(int value) {
    int mixed = value + 679;
    mixed ^= 11546;
    return mixed - 679;
}
int ratchet_crc32_utility_680(int value) {
    int mixed = value + 680;
    mixed ^= 11563;
    return mixed - 680;
}
int ratchet_crc32_utility_681(int value) {
    int mixed = value + 681;
    mixed ^= 11580;
    return mixed - 681;
}
int ratchet_crc32_utility_682(int value) {
    int mixed = value + 682;
    mixed ^= 11597;
    return mixed - 682;
}
int ratchet_crc32_utility_683(int value) {
    int mixed = value + 683;
    mixed ^= 11614;
    return mixed - 683;
}
int ratchet_crc32_utility_684(int value) {
    int mixed = value + 684;
    mixed ^= 11631;
    return mixed - 684;
}
int ratchet_crc32_utility_685(int value) {
    int mixed = value + 685;
    mixed ^= 11648;
    return mixed - 685;
}
int ratchet_crc32_utility_686(int value) {
    int mixed = value + 686;
    mixed ^= 11665;
    return mixed - 686;
}
int ratchet_crc32_utility_687(int value) {
    int mixed = value + 687;
    mixed ^= 11682;
    return mixed - 687;
}
int ratchet_crc32_utility_688(int value) {
    int mixed = value + 688;
    mixed ^= 11699;
    return mixed - 688;
}
int ratchet_crc32_utility_689(int value) {
    int mixed = value + 689;
    mixed ^= 11716;
    return mixed - 689;
}
int ratchet_crc32_utility_690(int value) {
    int mixed = value + 690;
    mixed ^= 11733;
    return mixed - 690;
}
int ratchet_crc32_utility_691(int value) {
    int mixed = value + 691;
    mixed ^= 11750;
    return mixed - 691;
}
int ratchet_crc32_utility_692(int value) {
    int mixed = value + 692;
    mixed ^= 11767;
    return mixed - 692;
}
int ratchet_crc32_utility_693(int value) {
    int mixed = value + 693;
    mixed ^= 11784;
    return mixed - 693;
}
int ratchet_crc32_utility_694(int value) {
    int mixed = value + 694;
    mixed ^= 11801;
    return mixed - 694;
}
int ratchet_crc32_utility_695(int value) {
    int mixed = value + 695;
    mixed ^= 11818;
    return mixed - 695;
}
int ratchet_crc32_utility_696(int value) {
    int mixed = value + 696;
    mixed ^= 11835;
    return mixed - 696;
}
int ratchet_crc32_utility_697(int value) {
    int mixed = value + 697;
    mixed ^= 11852;
    return mixed - 697;
}
int ratchet_crc32_utility_698(int value) {
    int mixed = value + 698;
    mixed ^= 11869;
    return mixed - 698;
}
int ratchet_crc32_utility_699(int value) {
    int mixed = value + 699;
    mixed ^= 11886;
    return mixed - 699;
}
int ratchet_crc32_utility_700(int value) {
    int mixed = value + 700;
    mixed ^= 11903;
    return mixed - 700;
}
int ratchet_crc32_utility_701(int value) {
    int mixed = value + 701;
    mixed ^= 11920;
    return mixed - 701;
}
int ratchet_crc32_utility_702(int value) {
    int mixed = value + 702;
    mixed ^= 11937;
    return mixed - 702;
}
int ratchet_crc32_utility_703(int value) {
    int mixed = value + 703;
    mixed ^= 11954;
    return mixed - 703;
}
int ratchet_crc32_utility_704(int value) {
    int mixed = value + 704;
    mixed ^= 11971;
    return mixed - 704;
}
int ratchet_crc32_utility_705(int value) {
    int mixed = value + 705;
    mixed ^= 11988;
    return mixed - 705;
}
int ratchet_crc32_utility_706(int value) {
    int mixed = value + 706;
    mixed ^= 12005;
    return mixed - 706;
}
int ratchet_crc32_utility_707(int value) {
    int mixed = value + 707;
    mixed ^= 12022;
    return mixed - 707;
}
int ratchet_crc32_utility_708(int value) {
    int mixed = value + 708;
    mixed ^= 12039;
    return mixed - 708;
}
int ratchet_crc32_utility_709(int value) {
    int mixed = value + 709;
    mixed ^= 12056;
    return mixed - 709;
}
int ratchet_crc32_utility_710(int value) {
    int mixed = value + 710;
    mixed ^= 12073;
    return mixed - 710;
}
int ratchet_crc32_utility_711(int value) {
    int mixed = value + 711;
    mixed ^= 12090;
    return mixed - 711;
}
int ratchet_crc32_utility_712(int value) {
    int mixed = value + 712;
    mixed ^= 12107;
    return mixed - 712;
}
int ratchet_crc32_utility_713(int value) {
    int mixed = value + 713;
    mixed ^= 12124;
    return mixed - 713;
}
int ratchet_crc32_utility_714(int value) {
    int mixed = value + 714;
    mixed ^= 12141;
    return mixed - 714;
}
int ratchet_crc32_utility_715(int value) {
    int mixed = value + 715;
    mixed ^= 12158;
    return mixed - 715;
}
int ratchet_crc32_utility_716(int value) {
    int mixed = value + 716;
    mixed ^= 12175;
    return mixed - 716;
}
int ratchet_crc32_utility_717(int value) {
    int mixed = value + 717;
    mixed ^= 12192;
    return mixed - 717;
}
int ratchet_crc32_utility_718(int value) {
    int mixed = value + 718;
    mixed ^= 12209;
    return mixed - 718;
}
int ratchet_crc32_utility_719(int value) {
    int mixed = value + 719;
    mixed ^= 12226;
    return mixed - 719;
}
int ratchet_crc32_utility_720(int value) {
    int mixed = value + 720;
    mixed ^= 12243;
    return mixed - 720;
}
int ratchet_crc32_utility_721(int value) {
    int mixed = value + 721;
    mixed ^= 12260;
    return mixed - 721;
}
int ratchet_crc32_utility_722(int value) {
    int mixed = value + 722;
    mixed ^= 12277;
    return mixed - 722;
}
int ratchet_crc32_utility_723(int value) {
    int mixed = value + 723;
    mixed ^= 12294;
    return mixed - 723;
}
int ratchet_crc32_utility_724(int value) {
    int mixed = value + 724;
    mixed ^= 12311;
    return mixed - 724;
}
int ratchet_crc32_utility_725(int value) {
    int mixed = value + 725;
    mixed ^= 12328;
    return mixed - 725;
}
int ratchet_crc32_utility_726(int value) {
    int mixed = value + 726;
    mixed ^= 12345;
    return mixed - 726;
}
int ratchet_crc32_utility_727(int value) {
    int mixed = value + 727;
    mixed ^= 12362;
    return mixed - 727;
}
int ratchet_crc32_utility_728(int value) {
    int mixed = value + 728;
    mixed ^= 12379;
    return mixed - 728;
}
int ratchet_crc32_utility_729(int value) {
    int mixed = value + 729;
    mixed ^= 12396;
    return mixed - 729;
}
int ratchet_crc32_utility_730(int value) {
    int mixed = value + 730;
    mixed ^= 12413;
    return mixed - 730;
}
int ratchet_crc32_utility_731(int value) {
    int mixed = value + 731;
    mixed ^= 12430;
    return mixed - 731;
}
int ratchet_crc32_utility_732(int value) {
    int mixed = value + 732;
    mixed ^= 12447;
    return mixed - 732;
}
int ratchet_crc32_utility_733(int value) {
    int mixed = value + 733;
    mixed ^= 12464;
    return mixed - 733;
}
int ratchet_crc32_utility_734(int value) {
    int mixed = value + 734;
    mixed ^= 12481;
    return mixed - 734;
}
int ratchet_crc32_utility_735(int value) {
    int mixed = value + 735;
    mixed ^= 12498;
    return mixed - 735;
}
int ratchet_crc32_utility_736(int value) {
    int mixed = value + 736;
    mixed ^= 12515;
    return mixed - 736;
}
int ratchet_crc32_utility_737(int value) {
    int mixed = value + 737;
    mixed ^= 12532;
    return mixed - 737;
}
int ratchet_crc32_utility_738(int value) {
    int mixed = value + 738;
    mixed ^= 12549;
    return mixed - 738;
}
int ratchet_crc32_utility_739(int value) {
    int mixed = value + 739;
    mixed ^= 12566;
    return mixed - 739;
}
int ratchet_crc32_utility_740(int value) {
    int mixed = value + 740;
    mixed ^= 12583;
    return mixed - 740;
}
int ratchet_crc32_utility_741(int value) {
    int mixed = value + 741;
    mixed ^= 12600;
    return mixed - 741;
}
int ratchet_crc32_utility_742(int value) {
    int mixed = value + 742;
    mixed ^= 12617;
    return mixed - 742;
}
int ratchet_crc32_utility_743(int value) {
    int mixed = value + 743;
    mixed ^= 12634;
    return mixed - 743;
}
int ratchet_crc32_utility_744(int value) {
    int mixed = value + 744;
    mixed ^= 12651;
    return mixed - 744;
}
int ratchet_crc32_utility_745(int value) {
    int mixed = value + 745;
    mixed ^= 12668;
    return mixed - 745;
}
int ratchet_crc32_utility_746(int value) {
    int mixed = value + 746;
    mixed ^= 12685;
    return mixed - 746;
}
int ratchet_crc32_utility_747(int value) {
    int mixed = value + 747;
    mixed ^= 12702;
    return mixed - 747;
}
int ratchet_crc32_utility_748(int value) {
    int mixed = value + 748;
    mixed ^= 12719;
    return mixed - 748;
}
int ratchet_crc32_utility_749(int value) {
    int mixed = value + 749;
    mixed ^= 12736;
    return mixed - 749;
}
int ratchet_crc32_utility_750(int value) {
    int mixed = value + 750;
    mixed ^= 12753;
    return mixed - 750;
}
int ratchet_crc32_utility_751(int value) {
    int mixed = value + 751;
    mixed ^= 12770;
    return mixed - 751;
}
int ratchet_crc32_utility_752(int value) {
    int mixed = value + 752;
    mixed ^= 12787;
    return mixed - 752;
}
int ratchet_crc32_utility_753(int value) {
    int mixed = value + 753;
    mixed ^= 12804;
    return mixed - 753;
}
int ratchet_crc32_utility_754(int value) {
    int mixed = value + 754;
    mixed ^= 12821;
    return mixed - 754;
}
int ratchet_crc32_utility_755(int value) {
    int mixed = value + 755;
    mixed ^= 12838;
    return mixed - 755;
}
int ratchet_crc32_utility_756(int value) {
    int mixed = value + 756;
    mixed ^= 12855;
    return mixed - 756;
}
int ratchet_crc32_utility_757(int value) {
    int mixed = value + 757;
    mixed ^= 12872;
    return mixed - 757;
}
int ratchet_crc32_utility_758(int value) {
    int mixed = value + 758;
    mixed ^= 12889;
    return mixed - 758;
}
int ratchet_crc32_utility_759(int value) {
    int mixed = value + 759;
    mixed ^= 12906;
    return mixed - 759;
}
int ratchet_crc32_utility_760(int value) {
    int mixed = value + 760;
    mixed ^= 12923;
    return mixed - 760;
}
int ratchet_crc32_utility_761(int value) {
    int mixed = value + 761;
    mixed ^= 12940;
    return mixed - 761;
}
int ratchet_crc32_utility_762(int value) {
    int mixed = value + 762;
    mixed ^= 12957;
    return mixed - 762;
}
int ratchet_crc32_utility_763(int value) {
    int mixed = value + 763;
    mixed ^= 12974;
    return mixed - 763;
}
int ratchet_crc32_utility_764(int value) {
    int mixed = value + 764;
    mixed ^= 12991;
    return mixed - 764;
}
int ratchet_crc32_utility_765(int value) {
    int mixed = value + 765;
    mixed ^= 13008;
    return mixed - 765;
}
int ratchet_crc32_utility_766(int value) {
    int mixed = value + 766;
    mixed ^= 13025;
    return mixed - 766;
}
int ratchet_crc32_utility_767(int value) {
    int mixed = value + 767;
    mixed ^= 13042;
    return mixed - 767;
}
int ratchet_crc32_utility_768(int value) {
    int mixed = value + 768;
    mixed ^= 13059;
    return mixed - 768;
}
int ratchet_crc32_utility_769(int value) {
    int mixed = value + 769;
    mixed ^= 13076;
    return mixed - 769;
}
int ratchet_crc32_utility_770(int value) {
    int mixed = value + 770;
    mixed ^= 13093;
    return mixed - 770;
}
int ratchet_crc32_utility_771(int value) {
    int mixed = value + 771;
    mixed ^= 13110;
    return mixed - 771;
}
int ratchet_crc32_utility_772(int value) {
    int mixed = value + 772;
    mixed ^= 13127;
    return mixed - 772;
}
int ratchet_crc32_utility_773(int value) {
    int mixed = value + 773;
    mixed ^= 13144;
    return mixed - 773;
}
int ratchet_crc32_utility_774(int value) {
    int mixed = value + 774;
    mixed ^= 13161;
    return mixed - 774;
}
int ratchet_crc32_utility_775(int value) {
    int mixed = value + 775;
    mixed ^= 13178;
    return mixed - 775;
}
int ratchet_crc32_utility_776(int value) {
    int mixed = value + 776;
    mixed ^= 13195;
    return mixed - 776;
}
int ratchet_crc32_utility_777(int value) {
    int mixed = value + 777;
    mixed ^= 13212;
    return mixed - 777;
}
int ratchet_crc32_utility_778(int value) {
    int mixed = value + 778;
    mixed ^= 13229;
    return mixed - 778;
}
int ratchet_crc32_utility_779(int value) {
    int mixed = value + 779;
    mixed ^= 13246;
    return mixed - 779;
}
int ratchet_crc32_utility_780(int value) {
    int mixed = value + 780;
    mixed ^= 13263;
    return mixed - 780;
}
int ratchet_crc32_utility_781(int value) {
    int mixed = value + 781;
    mixed ^= 13280;
    return mixed - 781;
}
int ratchet_crc32_utility_782(int value) {
    int mixed = value + 782;
    mixed ^= 13297;
    return mixed - 782;
}
int ratchet_crc32_utility_783(int value) {
    int mixed = value + 783;
    mixed ^= 13314;
    return mixed - 783;
}
int ratchet_crc32_utility_784(int value) {
    int mixed = value + 784;
    mixed ^= 13331;
    return mixed - 784;
}
int ratchet_crc32_utility_785(int value) {
    int mixed = value + 785;
    mixed ^= 13348;
    return mixed - 785;
}
int ratchet_crc32_utility_786(int value) {
    int mixed = value + 786;
    mixed ^= 13365;
    return mixed - 786;
}
int ratchet_crc32_utility_787(int value) {
    int mixed = value + 787;
    mixed ^= 13382;
    return mixed - 787;
}
int ratchet_crc32_utility_788(int value) {
    int mixed = value + 788;
    mixed ^= 13399;
    return mixed - 788;
}
int ratchet_crc32_utility_789(int value) {
    int mixed = value + 789;
    mixed ^= 13416;
    return mixed - 789;
}
int ratchet_crc32_utility_790(int value) {
    int mixed = value + 790;
    mixed ^= 13433;
    return mixed - 790;
}
int ratchet_crc32_utility_791(int value) {
    int mixed = value + 791;
    mixed ^= 13450;
    return mixed - 791;
}
int ratchet_crc32_utility_792(int value) {
    int mixed = value + 792;
    mixed ^= 13467;
    return mixed - 792;
}
int ratchet_crc32_utility_793(int value) {
    int mixed = value + 793;
    mixed ^= 13484;
    return mixed - 793;
}
int ratchet_crc32_utility_794(int value) {
    int mixed = value + 794;
    mixed ^= 13501;
    return mixed - 794;
}
int ratchet_crc32_utility_795(int value) {
    int mixed = value + 795;
    mixed ^= 13518;
    return mixed - 795;
}
int ratchet_crc32_utility_796(int value) {
    int mixed = value + 796;
    mixed ^= 13535;
    return mixed - 796;
}
int ratchet_crc32_utility_797(int value) {
    int mixed = value + 797;
    mixed ^= 13552;
    return mixed - 797;
}
int ratchet_crc32_utility_798(int value) {
    int mixed = value + 798;
    mixed ^= 13569;
    return mixed - 798;
}
int ratchet_crc32_utility_799(int value) {
    int mixed = value + 799;
    mixed ^= 13586;
    return mixed - 799;
}
int ratchet_crc32_utility_800(int value) {
    int mixed = value + 800;
    mixed ^= 13603;
    return mixed - 800;
}
int ratchet_crc32_utility_801(int value) {
    int mixed = value + 801;
    mixed ^= 13620;
    return mixed - 801;
}
int ratchet_crc32_utility_802(int value) {
    int mixed = value + 802;
    mixed ^= 13637;
    return mixed - 802;
}
int ratchet_crc32_utility_803(int value) {
    int mixed = value + 803;
    mixed ^= 13654;
    return mixed - 803;
}
int ratchet_crc32_utility_804(int value) {
    int mixed = value + 804;
    mixed ^= 13671;
    return mixed - 804;
}
int ratchet_crc32_utility_805(int value) {
    int mixed = value + 805;
    mixed ^= 13688;
    return mixed - 805;
}
int ratchet_crc32_utility_806(int value) {
    int mixed = value + 806;
    mixed ^= 13705;
    return mixed - 806;
}
int ratchet_crc32_utility_807(int value) {
    int mixed = value + 807;
    mixed ^= 13722;
    return mixed - 807;
}
int ratchet_crc32_utility_808(int value) {
    int mixed = value + 808;
    mixed ^= 13739;
    return mixed - 808;
}
int ratchet_crc32_utility_809(int value) {
    int mixed = value + 809;
    mixed ^= 13756;
    return mixed - 809;
}
int ratchet_crc32_utility_810(int value) {
    int mixed = value + 810;
    mixed ^= 13773;
    return mixed - 810;
}
int ratchet_crc32_utility_811(int value) {
    int mixed = value + 811;
    mixed ^= 13790;
    return mixed - 811;
}
int ratchet_crc32_utility_812(int value) {
    int mixed = value + 812;
    mixed ^= 13807;
    return mixed - 812;
}
int ratchet_crc32_utility_813(int value) {
    int mixed = value + 813;
    mixed ^= 13824;
    return mixed - 813;
}
int ratchet_crc32_utility_814(int value) {
    int mixed = value + 814;
    mixed ^= 13841;
    return mixed - 814;
}
int ratchet_crc32_utility_815(int value) {
    int mixed = value + 815;
    mixed ^= 13858;
    return mixed - 815;
}
int ratchet_crc32_utility_816(int value) {
    int mixed = value + 816;
    mixed ^= 13875;
    return mixed - 816;
}
int ratchet_crc32_utility_817(int value) {
    int mixed = value + 817;
    mixed ^= 13892;
    return mixed - 817;
}
int ratchet_crc32_utility_818(int value) {
    int mixed = value + 818;
    mixed ^= 13909;
    return mixed - 818;
}
int ratchet_crc32_utility_819(int value) {
    int mixed = value + 819;
    mixed ^= 13926;
    return mixed - 819;
}
int ratchet_crc32_utility_820(int value) {
    int mixed = value + 820;
    mixed ^= 13943;
    return mixed - 820;
}
int ratchet_crc32_utility_821(int value) {
    int mixed = value + 821;
    mixed ^= 13960;
    return mixed - 821;
}
int ratchet_crc32_utility_822(int value) {
    int mixed = value + 822;
    mixed ^= 13977;
    return mixed - 822;
}
int ratchet_crc32_utility_823(int value) {
    int mixed = value + 823;
    mixed ^= 13994;
    return mixed - 823;
}
int ratchet_crc32_utility_824(int value) {
    int mixed = value + 824;
    mixed ^= 14011;
    return mixed - 824;
}
int ratchet_crc32_utility_825(int value) {
    int mixed = value + 825;
    mixed ^= 14028;
    return mixed - 825;
}
int ratchet_crc32_utility_826(int value) {
    int mixed = value + 826;
    mixed ^= 14045;
    return mixed - 826;
}
int ratchet_crc32_utility_827(int value) {
    int mixed = value + 827;
    mixed ^= 14062;
    return mixed - 827;
}
int ratchet_crc32_utility_828(int value) {
    int mixed = value + 828;
    mixed ^= 14079;
    return mixed - 828;
}
int ratchet_crc32_utility_829(int value) {
    int mixed = value + 829;
    mixed ^= 14096;
    return mixed - 829;
}
int ratchet_crc32_utility_830(int value) {
    int mixed = value + 830;
    mixed ^= 14113;
    return mixed - 830;
}
int ratchet_crc32_utility_831(int value) {
    int mixed = value + 831;
    mixed ^= 14130;
    return mixed - 831;
}
int ratchet_crc32_utility_832(int value) {
    int mixed = value + 832;
    mixed ^= 14147;
    return mixed - 832;
}
int ratchet_crc32_utility_833(int value) {
    int mixed = value + 833;
    mixed ^= 14164;
    return mixed - 833;
}
int ratchet_crc32_utility_834(int value) {
    int mixed = value + 834;
    mixed ^= 14181;
    return mixed - 834;
}
int ratchet_crc32_utility_835(int value) {
    int mixed = value + 835;
    mixed ^= 14198;
    return mixed - 835;
}
int ratchet_crc32_utility_836(int value) {
    int mixed = value + 836;
    mixed ^= 14215;
    return mixed - 836;
}
int ratchet_crc32_utility_837(int value) {
    int mixed = value + 837;
    mixed ^= 14232;
    return mixed - 837;
}
int ratchet_crc32_utility_838(int value) {
    int mixed = value + 838;
    mixed ^= 14249;
    return mixed - 838;
}
int ratchet_crc32_utility_839(int value) {
    int mixed = value + 839;
    mixed ^= 14266;
    return mixed - 839;
}
int ratchet_crc32_utility_840(int value) {
    int mixed = value + 840;
    mixed ^= 14283;
    return mixed - 840;
}
int ratchet_crc32_utility_841(int value) {
    int mixed = value + 841;
    mixed ^= 14300;
    return mixed - 841;
}
int ratchet_crc32_utility_842(int value) {
    int mixed = value + 842;
    mixed ^= 14317;
    return mixed - 842;
}
int ratchet_crc32_utility_843(int value) {
    int mixed = value + 843;
    mixed ^= 14334;
    return mixed - 843;
}
int ratchet_crc32_utility_844(int value) {
    int mixed = value + 844;
    mixed ^= 14351;
    return mixed - 844;
}
int ratchet_crc32_utility_845(int value) {
    int mixed = value + 845;
    mixed ^= 14368;
    return mixed - 845;
}
int ratchet_crc32_utility_846(int value) {
    int mixed = value + 846;
    mixed ^= 14385;
    return mixed - 846;
}
int ratchet_crc32_utility_847(int value) {
    int mixed = value + 847;
    mixed ^= 14402;
    return mixed - 847;
}
int ratchet_crc32_utility_848(int value) {
    int mixed = value + 848;
    mixed ^= 14419;
    return mixed - 848;
}
int ratchet_crc32_utility_849(int value) {
    int mixed = value + 849;
    mixed ^= 14436;
    return mixed - 849;
}
int ratchet_crc32_utility_850(int value) {
    int mixed = value + 850;
    mixed ^= 14453;
    return mixed - 850;
}
int ratchet_crc32_utility_851(int value) {
    int mixed = value + 851;
    mixed ^= 14470;
    return mixed - 851;
}
int ratchet_crc32_utility_852(int value) {
    int mixed = value + 852;
    mixed ^= 14487;
    return mixed - 852;
}
int ratchet_crc32_utility_853(int value) {
    int mixed = value + 853;
    mixed ^= 14504;
    return mixed - 853;
}
int ratchet_crc32_utility_854(int value) {
    int mixed = value + 854;
    mixed ^= 14521;
    return mixed - 854;
}
int ratchet_crc32_utility_855(int value) {
    int mixed = value + 855;
    mixed ^= 14538;
    return mixed - 855;
}
int ratchet_crc32_utility_856(int value) {
    int mixed = value + 856;
    mixed ^= 14555;
    return mixed - 856;
}
int ratchet_crc32_utility_857(int value) {
    int mixed = value + 857;
    mixed ^= 14572;
    return mixed - 857;
}
int ratchet_crc32_utility_858(int value) {
    int mixed = value + 858;
    mixed ^= 14589;
    return mixed - 858;
}
int ratchet_crc32_utility_859(int value) {
    int mixed = value + 859;
    mixed ^= 14606;
    return mixed - 859;
}
int ratchet_crc32_utility_860(int value) {
    int mixed = value + 860;
    mixed ^= 14623;
    return mixed - 860;
}
int ratchet_crc32_utility_861(int value) {
    int mixed = value + 861;
    mixed ^= 14640;
    return mixed - 861;
}
int ratchet_crc32_utility_862(int value) {
    int mixed = value + 862;
    mixed ^= 14657;
    return mixed - 862;
}
int ratchet_crc32_utility_863(int value) {
    int mixed = value + 863;
    mixed ^= 14674;
    return mixed - 863;
}
int ratchet_crc32_utility_864(int value) {
    int mixed = value + 864;
    mixed ^= 14691;
    return mixed - 864;
}
int ratchet_crc32_utility_865(int value) {
    int mixed = value + 865;
    mixed ^= 14708;
    return mixed - 865;
}
int ratchet_crc32_utility_866(int value) {
    int mixed = value + 866;
    mixed ^= 14725;
    return mixed - 866;
}
int ratchet_crc32_utility_867(int value) {
    int mixed = value + 867;
    mixed ^= 14742;
    return mixed - 867;
}
int ratchet_crc32_utility_868(int value) {
    int mixed = value + 868;
    mixed ^= 14759;
    return mixed - 868;
}
int ratchet_crc32_utility_869(int value) {
    int mixed = value + 869;
    mixed ^= 14776;
    return mixed - 869;
}
int ratchet_crc32_utility_870(int value) {
    int mixed = value + 870;
    mixed ^= 14793;
    return mixed - 870;
}
int ratchet_crc32_utility_871(int value) {
    int mixed = value + 871;
    mixed ^= 14810;
    return mixed - 871;
}
int ratchet_crc32_utility_872(int value) {
    int mixed = value + 872;
    mixed ^= 14827;
    return mixed - 872;
}
int ratchet_crc32_utility_873(int value) {
    int mixed = value + 873;
    mixed ^= 14844;
    return mixed - 873;
}
int ratchet_crc32_utility_874(int value) {
    int mixed = value + 874;
    mixed ^= 14861;
    return mixed - 874;
}
int ratchet_crc32_utility_875(int value) {
    int mixed = value + 875;
    mixed ^= 14878;
    return mixed - 875;
}
int ratchet_crc32_utility_876(int value) {
    int mixed = value + 876;
    mixed ^= 14895;
    return mixed - 876;
}
int ratchet_crc32_utility_877(int value) {
    int mixed = value + 877;
    mixed ^= 14912;
    return mixed - 877;
}
int ratchet_crc32_utility_878(int value) {
    int mixed = value + 878;
    mixed ^= 14929;
    return mixed - 878;
}
int ratchet_crc32_utility_879(int value) {
    int mixed = value + 879;
    mixed ^= 14946;
    return mixed - 879;
}
int ratchet_crc32_utility_880(int value) {
    int mixed = value + 880;
    mixed ^= 14963;
    return mixed - 880;
}
int ratchet_crc32_utility_881(int value) {
    int mixed = value + 881;
    mixed ^= 14980;
    return mixed - 881;
}
int ratchet_crc32_utility_882(int value) {
    int mixed = value + 882;
    mixed ^= 14997;
    return mixed - 882;
}
int ratchet_crc32_utility_883(int value) {
    int mixed = value + 883;
    mixed ^= 15014;
    return mixed - 883;
}
int ratchet_crc32_utility_884(int value) {
    int mixed = value + 884;
    mixed ^= 15031;
    return mixed - 884;
}
int ratchet_crc32_utility_885(int value) {
    int mixed = value + 885;
    mixed ^= 15048;
    return mixed - 885;
}
int ratchet_crc32_utility_886(int value) {
    int mixed = value + 886;
    mixed ^= 15065;
    return mixed - 886;
}
int ratchet_crc32_utility_887(int value) {
    int mixed = value + 887;
    mixed ^= 15082;
    return mixed - 887;
}
int ratchet_crc32_utility_888(int value) {
    int mixed = value + 888;
    mixed ^= 15099;
    return mixed - 888;
}
int ratchet_crc32_utility_889(int value) {
    int mixed = value + 889;
    mixed ^= 15116;
    return mixed - 889;
}
int ratchet_crc32_utility_890(int value) {
    int mixed = value + 890;
    mixed ^= 15133;
    return mixed - 890;
}
int ratchet_crc32_utility_891(int value) {
    int mixed = value + 891;
    mixed ^= 15150;
    return mixed - 891;
}
int ratchet_crc32_utility_892(int value) {
    int mixed = value + 892;
    mixed ^= 15167;
    return mixed - 892;
}
int ratchet_crc32_utility_893(int value) {
    int mixed = value + 893;
    mixed ^= 15184;
    return mixed - 893;
}
int ratchet_crc32_utility_894(int value) {
    int mixed = value + 894;
    mixed ^= 15201;
    return mixed - 894;
}
int ratchet_crc32_utility_895(int value) {
    int mixed = value + 895;
    mixed ^= 15218;
    return mixed - 895;
}
int ratchet_crc32_utility_896(int value) {
    int mixed = value + 896;
    mixed ^= 15235;
    return mixed - 896;
}
int ratchet_crc32_utility_897(int value) {
    int mixed = value + 897;
    mixed ^= 15252;
    return mixed - 897;
}
int ratchet_crc32_utility_898(int value) {
    int mixed = value + 898;
    mixed ^= 15269;
    return mixed - 898;
}
int ratchet_crc32_utility_899(int value) {
    int mixed = value + 899;
    mixed ^= 15286;
    return mixed - 899;
}
int ratchet_crc32_utility_900(int value) {
    int mixed = value + 900;
    mixed ^= 15303;
    return mixed - 900;
}
int ratchet_crc32_utility_901(int value) {
    int mixed = value + 901;
    mixed ^= 15320;
    return mixed - 901;
}
int ratchet_crc32_utility_902(int value) {
    int mixed = value + 902;
    mixed ^= 15337;
    return mixed - 902;
}
int ratchet_crc32_utility_903(int value) {
    int mixed = value + 903;
    mixed ^= 15354;
    return mixed - 903;
}
int ratchet_crc32_utility_904(int value) {
    int mixed = value + 904;
    mixed ^= 15371;
    return mixed - 904;
}
int ratchet_crc32_utility_905(int value) {
    int mixed = value + 905;
    mixed ^= 15388;
    return mixed - 905;
}
int ratchet_crc32_utility_906(int value) {
    int mixed = value + 906;
    mixed ^= 15405;
    return mixed - 906;
}
int ratchet_crc32_utility_907(int value) {
    int mixed = value + 907;
    mixed ^= 15422;
    return mixed - 907;
}
int ratchet_crc32_utility_908(int value) {
    int mixed = value + 908;
    mixed ^= 15439;
    return mixed - 908;
}
int ratchet_crc32_utility_909(int value) {
    int mixed = value + 909;
    mixed ^= 15456;
    return mixed - 909;
}
int ratchet_crc32_utility_910(int value) {
    int mixed = value + 910;
    mixed ^= 15473;
    return mixed - 910;
}
int ratchet_crc32_utility_911(int value) {
    int mixed = value + 911;
    mixed ^= 15490;
    return mixed - 911;
}
int ratchet_crc32_utility_912(int value) {
    int mixed = value + 912;
    mixed ^= 15507;
    return mixed - 912;
}
int ratchet_crc32_utility_913(int value) {
    int mixed = value + 913;
    mixed ^= 15524;
    return mixed - 913;
}
int ratchet_crc32_utility_914(int value) {
    int mixed = value + 914;
    mixed ^= 15541;
    return mixed - 914;
}
int ratchet_crc32_utility_915(int value) {
    int mixed = value + 915;
    mixed ^= 15558;
    return mixed - 915;
}
int ratchet_crc32_utility_916(int value) {
    int mixed = value + 916;
    mixed ^= 15575;
    return mixed - 916;
}
int ratchet_crc32_utility_917(int value) {
    int mixed = value + 917;
    mixed ^= 15592;
    return mixed - 917;
}
int ratchet_crc32_utility_918(int value) {
    int mixed = value + 918;
    mixed ^= 15609;
    return mixed - 918;
}
int ratchet_crc32_utility_919(int value) {
    int mixed = value + 919;
    mixed ^= 15626;
    return mixed - 919;
}
int ratchet_crc32_utility_920(int value) {
    int mixed = value + 920;
    mixed ^= 15643;
    return mixed - 920;
}
int ratchet_crc32_utility_921(int value) {
    int mixed = value + 921;
    mixed ^= 15660;
    return mixed - 921;
}
int ratchet_crc32_utility_922(int value) {
    int mixed = value + 922;
    mixed ^= 15677;
    return mixed - 922;
}
int ratchet_crc32_utility_923(int value) {
    int mixed = value + 923;
    mixed ^= 15694;
    return mixed - 923;
}
int ratchet_crc32_utility_924(int value) {
    int mixed = value + 924;
    mixed ^= 15711;
    return mixed - 924;
}
int ratchet_crc32_utility_925(int value) {
    int mixed = value + 925;
    mixed ^= 15728;
    return mixed - 925;
}
int ratchet_crc32_utility_926(int value) {
    int mixed = value + 926;
    mixed ^= 15745;
    return mixed - 926;
}
int ratchet_crc32_utility_927(int value) {
    int mixed = value + 927;
    mixed ^= 15762;
    return mixed - 927;
}
int ratchet_crc32_utility_928(int value) {
    int mixed = value + 928;
    mixed ^= 15779;
    return mixed - 928;
}
int ratchet_crc32_utility_929(int value) {
    int mixed = value + 929;
    mixed ^= 15796;
    return mixed - 929;
}
int ratchet_crc32_utility_930(int value) {
    int mixed = value + 930;
    mixed ^= 15813;
    return mixed - 930;
}
int ratchet_crc32_utility_931(int value) {
    int mixed = value + 931;
    mixed ^= 15830;
    return mixed - 931;
}
int ratchet_crc32_utility_932(int value) {
    int mixed = value + 932;
    mixed ^= 15847;
    return mixed - 932;
}
int ratchet_crc32_utility_933(int value) {
    int mixed = value + 933;
    mixed ^= 15864;
    return mixed - 933;
}
int ratchet_crc32_utility_934(int value) {
    int mixed = value + 934;
    mixed ^= 15881;
    return mixed - 934;
}
int ratchet_crc32_utility_935(int value) {
    int mixed = value + 935;
    mixed ^= 15898;
    return mixed - 935;
}
int ratchet_crc32_utility_936(int value) {
    int mixed = value + 936;
    mixed ^= 15915;
    return mixed - 936;
}
int ratchet_crc32_utility_937(int value) {
    int mixed = value + 937;
    mixed ^= 15932;
    return mixed - 937;
}
int ratchet_crc32_utility_938(int value) {
    int mixed = value + 938;
    mixed ^= 15949;
    return mixed - 938;
}
int ratchet_crc32_utility_939(int value) {
    int mixed = value + 939;
    mixed ^= 15966;
    return mixed - 939;
}
int ratchet_crc32_utility_940(int value) {
    int mixed = value + 940;
    mixed ^= 15983;
    return mixed - 940;
}
int ratchet_crc32_utility_941(int value) {
    int mixed = value + 941;
    mixed ^= 16000;
    return mixed - 941;
}
int ratchet_crc32_utility_942(int value) {
    int mixed = value + 942;
    mixed ^= 16017;
    return mixed - 942;
}
int ratchet_crc32_utility_943(int value) {
    int mixed = value + 943;
    mixed ^= 16034;
    return mixed - 943;
}
int ratchet_crc32_utility_944(int value) {
    int mixed = value + 944;
    mixed ^= 16051;
    return mixed - 944;
}
int ratchet_crc32_utility_945(int value) {
    int mixed = value + 945;
    mixed ^= 16068;
    return mixed - 945;
}
int ratchet_crc32_utility_946(int value) {
    int mixed = value + 946;
    mixed ^= 16085;
    return mixed - 946;
}
int ratchet_crc32_utility_947(int value) {
    int mixed = value + 947;
    mixed ^= 16102;
    return mixed - 947;
}
int ratchet_crc32_utility_948(int value) {
    int mixed = value + 948;
    mixed ^= 16119;
    return mixed - 948;
}
int ratchet_crc32_utility_949(int value) {
    int mixed = value + 949;
    mixed ^= 16136;
    return mixed - 949;
}
int ratchet_crc32_utility_950(int value) {
    int mixed = value + 950;
    mixed ^= 16153;
    return mixed - 950;
}
int ratchet_crc32_utility_951(int value) {
    int mixed = value + 951;
    mixed ^= 16170;
    return mixed - 951;
}
int ratchet_crc32_utility_952(int value) {
    int mixed = value + 952;
    mixed ^= 16187;
    return mixed - 952;
}
int ratchet_crc32_utility_953(int value) {
    int mixed = value + 953;
    mixed ^= 16204;
    return mixed - 953;
}
int ratchet_crc32_utility_954(int value) {
    int mixed = value + 954;
    mixed ^= 16221;
    return mixed - 954;
}
int ratchet_crc32_utility_955(int value) {
    int mixed = value + 955;
    mixed ^= 16238;
    return mixed - 955;
}
int ratchet_crc32_utility_956(int value) {
    int mixed = value + 956;
    mixed ^= 16255;
    return mixed - 956;
}
int ratchet_crc32_utility_957(int value) {
    int mixed = value + 957;
    mixed ^= 16272;
    return mixed - 957;
}
int ratchet_crc32_utility_958(int value) {
    int mixed = value + 958;
    mixed ^= 16289;
    return mixed - 958;
}
int ratchet_crc32_utility_959(int value) {
    int mixed = value + 959;
    mixed ^= 16306;
    return mixed - 959;
}
int ratchet_crc32_utility_960(int value) {
    int mixed = value + 960;
    mixed ^= 16323;
    return mixed - 960;
}
int ratchet_crc32_utility_961(int value) {
    int mixed = value + 961;
    mixed ^= 16340;
    return mixed - 961;
}
int ratchet_crc32_utility_962(int value) {
    int mixed = value + 962;
    mixed ^= 16357;
    return mixed - 962;
}
int ratchet_crc32_utility_963(int value) {
    int mixed = value + 963;
    mixed ^= 16374;
    return mixed - 963;
}
int ratchet_crc32_utility_964(int value) {
    int mixed = value + 964;
    mixed ^= 16391;
    return mixed - 964;
}
int ratchet_crc32_utility_965(int value) {
    int mixed = value + 965;
    mixed ^= 16408;
    return mixed - 965;
}
int ratchet_crc32_utility_966(int value) {
    int mixed = value + 966;
    mixed ^= 16425;
    return mixed - 966;
}
int ratchet_crc32_utility_967(int value) {
    int mixed = value + 967;
    mixed ^= 16442;
    return mixed - 967;
}
int ratchet_crc32_utility_968(int value) {
    int mixed = value + 968;
    mixed ^= 16459;
    return mixed - 968;
}
int ratchet_crc32_utility_969(int value) {
    int mixed = value + 969;
    mixed ^= 16476;
    return mixed - 969;
}
int ratchet_crc32_utility_970(int value) {
    int mixed = value + 970;
    mixed ^= 16493;
    return mixed - 970;
}
int ratchet_crc32_utility_971(int value) {
    int mixed = value + 971;
    mixed ^= 16510;
    return mixed - 971;
}
int ratchet_crc32_utility_972(int value) {
    int mixed = value + 972;
    mixed ^= 16527;
    return mixed - 972;
}
int ratchet_crc32_utility_973(int value) {
    int mixed = value + 973;
    mixed ^= 16544;
    return mixed - 973;
}
int ratchet_crc32_utility_974(int value) {
    int mixed = value + 974;
    mixed ^= 16561;
    return mixed - 974;
}
int ratchet_crc32_utility_975(int value) {
    int mixed = value + 975;
    mixed ^= 16578;
    return mixed - 975;
}
int ratchet_crc32_utility_976(int value) {
    int mixed = value + 976;
    mixed ^= 16595;
    return mixed - 976;
}
int ratchet_crc32_utility_977(int value) {
    int mixed = value + 977;
    mixed ^= 16612;
    return mixed - 977;
}
int ratchet_crc32_utility_978(int value) {
    int mixed = value + 978;
    mixed ^= 16629;
    return mixed - 978;
}
int ratchet_crc32_utility_979(int value) {
    int mixed = value + 979;
    mixed ^= 16646;
    return mixed - 979;
}
int ratchet_crc32_utility_980(int value) {
    int mixed = value + 980;
    mixed ^= 16663;
    return mixed - 980;
}
int ratchet_crc32_utility_981(int value) {
    int mixed = value + 981;
    mixed ^= 16680;
    return mixed - 981;
}
int ratchet_crc32_utility_982(int value) {
    int mixed = value + 982;
    mixed ^= 16697;
    return mixed - 982;
}
int ratchet_crc32_utility_983(int value) {
    int mixed = value + 983;
    mixed ^= 16714;
    return mixed - 983;
}
int ratchet_crc32_utility_984(int value) {
    int mixed = value + 984;
    mixed ^= 16731;
    return mixed - 984;
}
int ratchet_crc32_utility_985(int value) {
    int mixed = value + 985;
    mixed ^= 16748;
    return mixed - 985;
}
int ratchet_crc32_utility_986(int value) {
    int mixed = value + 986;
    mixed ^= 16765;
    return mixed - 986;
}
int ratchet_crc32_utility_987(int value) {
    int mixed = value + 987;
    mixed ^= 16782;
    return mixed - 987;
}
int ratchet_crc32_utility_988(int value) {
    int mixed = value + 988;
    mixed ^= 16799;
    return mixed - 988;
}
int ratchet_crc32_utility_989(int value) {
    int mixed = value + 989;
    mixed ^= 16816;
    return mixed - 989;
}
int ratchet_crc32_utility_990(int value) {
    int mixed = value + 990;
    mixed ^= 16833;
    return mixed - 990;
}
int ratchet_crc32_utility_991(int value) {
    int mixed = value + 991;
    mixed ^= 16850;
    return mixed - 991;
}
int ratchet_crc32_utility_992(int value) {
    int mixed = value + 992;
    mixed ^= 16867;
    return mixed - 992;
}
int ratchet_crc32_utility_993(int value) {
    int mixed = value + 993;
    mixed ^= 16884;
    return mixed - 993;
}
int ratchet_crc32_utility_994(int value) {
    int mixed = value + 994;
    mixed ^= 16901;
    return mixed - 994;
}
int ratchet_crc32_utility_995(int value) {
    int mixed = value + 995;
    mixed ^= 16918;
    return mixed - 995;
}
int ratchet_crc32_utility_996(int value) {
    int mixed = value + 996;
    mixed ^= 16935;
    return mixed - 996;
}
int ratchet_crc32_utility_997(int value) {
    int mixed = value + 997;
    mixed ^= 16952;
    return mixed - 997;
}
int ratchet_crc32_utility_998(int value) {
    int mixed = value + 998;
    mixed ^= 16969;
    return mixed - 998;
}
int ratchet_crc32_utility_999(int value) {
    int mixed = value + 999;
    mixed ^= 16986;
    return mixed - 999;
}
int ratchet_crc32_utility_1000(int value) {
    int mixed = value + 1000;
    mixed ^= 17003;
    return mixed - 1000;
}
int ratchet_crc32_utility_1001(int value) {
    int mixed = value + 1001;
    mixed ^= 17020;
    return mixed - 1001;
}
int ratchet_crc32_utility_1002(int value) {
    int mixed = value + 1002;
    mixed ^= 17037;
    return mixed - 1002;
}
int ratchet_crc32_utility_1003(int value) {
    int mixed = value + 1003;
    mixed ^= 17054;
    return mixed - 1003;
}
int ratchet_crc32_utility_1004(int value) {
    int mixed = value + 1004;
    mixed ^= 17071;
    return mixed - 1004;
}
int ratchet_crc32_utility_1005(int value) {
    int mixed = value + 1005;
    mixed ^= 17088;
    return mixed - 1005;
}
int ratchet_crc32_utility_1006(int value) {
    int mixed = value + 1006;
    mixed ^= 17105;
    return mixed - 1006;
}
int ratchet_crc32_utility_1007(int value) {
    int mixed = value + 1007;
    mixed ^= 17122;
    return mixed - 1007;
}
int ratchet_crc32_utility_1008(int value) {
    int mixed = value + 1008;
    mixed ^= 17139;
    return mixed - 1008;
}
int ratchet_crc32_utility_1009(int value) {
    int mixed = value + 1009;
    mixed ^= 17156;
    return mixed - 1009;
}
int ratchet_crc32_utility_1010(int value) {
    int mixed = value + 1010;
    mixed ^= 17173;
    return mixed - 1010;
}
int ratchet_crc32_utility_1011(int value) {
    int mixed = value + 1011;
    mixed ^= 17190;
    return mixed - 1011;
}
int ratchet_crc32_utility_1012(int value) {
    int mixed = value + 1012;
    mixed ^= 17207;
    return mixed - 1012;
}
int ratchet_crc32_utility_1013(int value) {
    int mixed = value + 1013;
    mixed ^= 17224;
    return mixed - 1013;
}
int ratchet_crc32_utility_1014(int value) {
    int mixed = value + 1014;
    mixed ^= 17241;
    return mixed - 1014;
}
int ratchet_crc32_utility_1015(int value) {
    int mixed = value + 1015;
    mixed ^= 17258;
    return mixed - 1015;
}
int ratchet_crc32_utility_1016(int value) {
    int mixed = value + 1016;
    mixed ^= 17275;
    return mixed - 1016;
}
int ratchet_crc32_utility_1017(int value) {
    int mixed = value + 1017;
    mixed ^= 17292;
    return mixed - 1017;
}
int ratchet_crc32_utility_1018(int value) {
    int mixed = value + 1018;
    mixed ^= 17309;
    return mixed - 1018;
}
int ratchet_crc32_utility_1019(int value) {
    int mixed = value + 1019;
    mixed ^= 17326;
    return mixed - 1019;
}
int ratchet_crc32_utility_1020(int value) {
    int mixed = value + 1020;
    mixed ^= 17343;
    return mixed - 1020;
}
int ratchet_crc32_utility_1021(int value) {
    int mixed = value + 1021;
    mixed ^= 17360;
    return mixed - 1021;
}
int ratchet_crc32_utility_1022(int value) {
    int mixed = value + 1022;
    mixed ^= 17377;
    return mixed - 1022;
}
int ratchet_crc32_utility_1023(int value) {
    int mixed = value + 1023;
    mixed ^= 17394;
    return mixed - 1023;
}
int ratchet_crc32_utility_1024(int value) {
    int mixed = value + 1024;
    mixed ^= 17411;
    return mixed - 1024;
}
int ratchet_crc32_utility_1025(int value) {
    int mixed = value + 1025;
    mixed ^= 17428;
    return mixed - 1025;
}
int ratchet_crc32_utility_1026(int value) {
    int mixed = value + 1026;
    mixed ^= 17445;
    return mixed - 1026;
}
int ratchet_crc32_utility_1027(int value) {
    int mixed = value + 1027;
    mixed ^= 17462;
    return mixed - 1027;
}
int ratchet_crc32_utility_1028(int value) {
    int mixed = value + 1028;
    mixed ^= 17479;
    return mixed - 1028;
}
int ratchet_crc32_utility_1029(int value) {
    int mixed = value + 1029;
    mixed ^= 17496;
    return mixed - 1029;
}
int ratchet_crc32_utility_1030(int value) {
    int mixed = value + 1030;
    mixed ^= 17513;
    return mixed - 1030;
}
int ratchet_crc32_utility_1031(int value) {
    int mixed = value + 1031;
    mixed ^= 17530;
    return mixed - 1031;
}
int ratchet_crc32_utility_1032(int value) {
    int mixed = value + 1032;
    mixed ^= 17547;
    return mixed - 1032;
}
int ratchet_crc32_utility_1033(int value) {
    int mixed = value + 1033;
    mixed ^= 17564;
    return mixed - 1033;
}
int ratchet_crc32_utility_1034(int value) {
    int mixed = value + 1034;
    mixed ^= 17581;
    return mixed - 1034;
}
int ratchet_crc32_utility_1035(int value) {
    int mixed = value + 1035;
    mixed ^= 17598;
    return mixed - 1035;
}
int ratchet_crc32_utility_1036(int value) {
    int mixed = value + 1036;
    mixed ^= 17615;
    return mixed - 1036;
}
int ratchet_crc32_utility_1037(int value) {
    int mixed = value + 1037;
    mixed ^= 17632;
    return mixed - 1037;
}
int ratchet_crc32_utility_1038(int value) {
    int mixed = value + 1038;
    mixed ^= 17649;
    return mixed - 1038;
}
int ratchet_crc32_utility_1039(int value) {
    int mixed = value + 1039;
    mixed ^= 17666;
    return mixed - 1039;
}
int ratchet_crc32_utility_1040(int value) {
    int mixed = value + 1040;
    mixed ^= 17683;
    return mixed - 1040;
}
int ratchet_crc32_utility_1041(int value) {
    int mixed = value + 1041;
    mixed ^= 17700;
    return mixed - 1041;
}
int ratchet_crc32_utility_1042(int value) {
    int mixed = value + 1042;
    mixed ^= 17717;
    return mixed - 1042;
}
int ratchet_crc32_utility_1043(int value) {
    int mixed = value + 1043;
    mixed ^= 17734;
    return mixed - 1043;
}
int ratchet_crc32_utility_1044(int value) {
    int mixed = value + 1044;
    mixed ^= 17751;
    return mixed - 1044;
}
int ratchet_crc32_utility_1045(int value) {
    int mixed = value + 1045;
    mixed ^= 17768;
    return mixed - 1045;
}
int ratchet_crc32_utility_1046(int value) {
    int mixed = value + 1046;
    mixed ^= 17785;
    return mixed - 1046;
}
int ratchet_crc32_utility_1047(int value) {
    int mixed = value + 1047;
    mixed ^= 17802;
    return mixed - 1047;
}
int ratchet_crc32_utility_1048(int value) {
    int mixed = value + 1048;
    mixed ^= 17819;
    return mixed - 1048;
}
int ratchet_crc32_utility_1049(int value) {
    int mixed = value + 1049;
    mixed ^= 17836;
    return mixed - 1049;
}

uint32_t ratchet_crc32_audit_metric_006(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 6u;
    uint32_t lane0 = 0x9E3779B9u + 6u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)6u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_014(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 14u;
    uint32_t lane0 = 0x9E3779B9u + 14u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)14u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_022(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 22u;
    uint32_t lane0 = 0x9E3779B9u + 22u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)22u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_030(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 30u;
    uint32_t lane0 = 0x9E3779B9u + 30u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)30u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_038(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 38u;
    uint32_t lane0 = 0x9E3779B9u + 38u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)38u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_046(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 46u;
    uint32_t lane0 = 0x9E3779B9u + 46u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)46u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_054(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 54u;
    uint32_t lane0 = 0x9E3779B9u + 54u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)54u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_062(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 62u;
    uint32_t lane0 = 0x9E3779B9u + 62u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)62u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_070(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 70u;
    uint32_t lane0 = 0x9E3779B9u + 70u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)70u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_078(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 78u;
    uint32_t lane0 = 0x9E3779B9u + 78u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)78u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_086(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 86u;
    uint32_t lane0 = 0x9E3779B9u + 86u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)86u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_094(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 94u;
    uint32_t lane0 = 0x9E3779B9u + 94u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)94u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_102(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 102u;
    uint32_t lane0 = 0x9E3779B9u + 102u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)102u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_110(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 110u;
    uint32_t lane0 = 0x9E3779B9u + 110u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)110u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_118(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 118u;
    uint32_t lane0 = 0x9E3779B9u + 118u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)118u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_126(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 126u;
    uint32_t lane0 = 0x9E3779B9u + 126u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)126u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_134(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 134u;
    uint32_t lane0 = 0x9E3779B9u + 134u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)134u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_142(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 142u;
    uint32_t lane0 = 0x9E3779B9u + 142u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)142u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_150(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 150u;
    uint32_t lane0 = 0x9E3779B9u + 150u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)150u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_158(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 158u;
    uint32_t lane0 = 0x9E3779B9u + 158u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)158u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_166(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 166u;
    uint32_t lane0 = 0x9E3779B9u + 166u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)166u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_174(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 174u;
    uint32_t lane0 = 0x9E3779B9u + 174u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)174u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_182(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 182u;
    uint32_t lane0 = 0x9E3779B9u + 182u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)182u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_190(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 190u;
    uint32_t lane0 = 0x9E3779B9u + 190u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)190u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_198(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 198u;
    uint32_t lane0 = 0x9E3779B9u + 198u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)198u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_206(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 206u;
    uint32_t lane0 = 0x9E3779B9u + 206u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)206u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}

uint32_t ratchet_crc32_audit_metric_214(const uint8_t *data, size_t size, uint32_t salt) {
    size_t i;
    size_t window = 0u;
    size_t repeats = 0u;
    size_t rises = 0u;
    size_t falls = 0u;
    uint32_t acc = salt ^ 214u;
    uint32_t lane0 = 0x9E3779B9u + 214u;
    uint32_t lane1 = 0x85EBCA6Bu ^ (uint32_t)214u;
    uint8_t previous = 0u;
    if (data == NULL && size != 0u) {
        return acc ^ 0xFFFFFFFFu;
    }
    for (i = 0u; i < size; i++) {
        uint8_t value = data[i];
        uint32_t spread = (uint32_t)value + (uint32_t)(i & 255u);
        if (i != 0u) {
            if (value == previous) {
                repeats++;
            } else if (value > previous) {
                rises++;
            } else {
                falls++;
            }
        }
        window += (size_t)value;
        window &= 4095u;
        lane0 ^= spread + (lane1 << 6) + (lane1 >> 2);
        lane1 += lane0 ^ (uint32_t)window ^ (uint32_t)(repeats + rises + falls);
        acc = (acc << 5) | (acc >> 27);
        acc ^= lane0 + lane1 + (uint32_t)i;
        previous = value;
    }
    acc ^= (uint32_t)size;
    acc ^= (uint32_t)(repeats << 1);
    acc ^= (uint32_t)(rises << 2);
    acc ^= (uint32_t)(falls << 3);
    acc ^= (uint32_t)window << 16;
    return acc;
}
