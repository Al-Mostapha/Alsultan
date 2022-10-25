#pragma once

enum class ECityTargetGroupID {
  GROUP_HALLTOP = 1001000,
  GROUP_WATERFALL = 1001500,
  GROUP_MAINCITY = 1002000,
  GROUP_LOWER_LOW = 1002500,
  GROUP_LOWER = 1003000,
  GROUP_EFFECT = 1004000,
  GROUP_INNER = 1005000,
  GROUP_NPC = 1006000,
  GROUP_OUTER = 1007000,
  GROUP_SHIP = 1008000,
  GROUP_SOLDIERS = 1008500,
  GROUP_WALL = 1010000,
  GROUP_JIANTA = 1011000,
  GROUP_D_EFFECT = 1012000,
  GROUP_NIGHT_COMMON = 1012000,
  GROUP_NIGHT_BUILD = 1013000,
  GROUP_BUILD_SHOW_NAME_BG = 1014000,
  GROUP_BUILD_SHOW_NAME = 1015000,
  GROUP_OTHER = 1100000,
  GROUP_CASTLE_BG = 100000,
  GROUP_CASTLE_B_ACT = 101000,
  GROUP_CASTLE_B_EFFECT = 102000,
  GROUP_CASTLE = 102500,
  GROUP_CASTLE_DH = 103000,
  GROUP_CASTLE_EXTRA = 104000,
  GROUP_CASTLE_TOP_ACT = 105000,
  GROUP_CASTLE_TOP_EFFECT = 106000,
  GROUP_CASTLE_ANIMATION = 107000,
  GROUP_CASTLE_OTHER = 108000,
  GROUP_CASTLE_NIGHT_SKIN = 110000,
  GROUP_CASTLE_NIGHT_ACT = 111000,
  GROUP_CASTLE_NIGHT_B_EFFECT = 112000,
  GROUP_CASTLE_NIGHT_DH = 113000,
  GROUP_CASTLE_NIGHT_TOP_ACT = 114000,
  GROUP_CASTLE_NIGHT_TOP_EFFECT = 115000,
  GROUP_CASTLE_NIGHT_ANIMATION = 116000,
  GROUP_CASTLE_NIGHT_EXTRA = 117000
};

struct ECityTargetZOrder {
  int32 far_bg = -10;
  int32 middle_bg = -5;
  int32 bg = 0;
  int32 banyungong = 3;
  int32 ship = 65;
  int32 waterfall = 4;
  int32 flag = 5;
  int32 activity = 6;
  int32 tree = 7;
  int32 wall = 55;
  int32 jianta_r = 58;
  int32 gate = 64;
  int32 jianta_l = 66;
  int32 inner_build = 2;
  int32 miracle = 56;
  int32 louti_r = 10;
  int32 tree_other = 26;
  int32 lvxing = 29;
  int32 louti_dr = 30;
  int32 louti_dl = 32;
  int32 jianta_btn = 80;
  int32 castle = 50;
  int32 castle_bg = 50;
  int32 castle_b_act = 51;
  int32 castle_b_effect = 52;
  int32 castle_skin = 53;
  int32 castle_dh = 54;
  int32 castle_extra = 55;
  int32 castle_top_act = 56;
  int32 castle_top_effect = 57;
  int32 castle_animation = 58;
  int32 castle_other = 59;
  int32 outer_build = 2;
  int32 xunluo = 60;
  int32 btn_touch = 100;
  int32 lower_wall = 500;
  int32 soldiers = 550;
  int32 drill = 560;
  int32 braveStatue = 570;
  int32 night_layer = 1000;
  int32 night_wall = 1001;
  int32 night_common = 1002;
  int32 night_castle = 1005;
  int32 castle_night_skin = 1005;
  int32 castle_night_act = 1006;
  int32 castle_night_b_effect = 1007;
  int32 castle_night_dh = 1008;
  int32 castle_night_top_act = 1009;
  int32 castle_night_top_effect = 1010;
  int32 castle_night_animation = 1011;
  int32 castle_night_extra = 1012;
  int32 juying = 1500;
  int32 show_nameBg = 11000;
  int32 show_name = 12000;
  int32 other = 9999;
  int32 tips = 10000;
  static ECityTargetZOrder *Get() {
    static ECityTargetZOrder zorder;
    return &zorder;
  }
};

