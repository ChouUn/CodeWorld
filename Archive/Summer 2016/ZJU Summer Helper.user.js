// ==UserScript==
// @name         ZJU Summer Helper
// @version      0.11
// @description  try to take over the world!
// @icon         http://fateud.com/img/favicon.ico
// @namespace    http://fateud.com/
// @author       ChouUn
// @match        http://10.71.10.99/onlinejudge/*
// @include      http://10.71.10.99/onlinejudge/*
// @updateURL    https://github.com/ChouUn/CodeWorld/raw/master/Archive/Summer%202016/ZJU%20Summer%20Helper.meta.js
// @downloadURL  https://github.com/ChouUn/CodeWorld/raw/master/Archive/Summer%202016/ZJU%20Summer%20Helper.user.js
// @supportURL   https://github.com/ChouUn/CodeWorld/issues
// @grant        none
// @require      http://cdn.bootcss.com/jquery/3.0.0/jquery.min.js
// ==/UserScript==

(function() {
  'use strict';

  var dict = {
    "2621":"李恭荣",
    "2622":"祝融峰",
    "2623":"赵炎",
    "2624":"盛嘉森",
    "2625":"蒋加伦",
    "2626":"潘乾宇",
    "2627":"吴迪奥",
    "2628":"朱文宇",
    "2629":"颜姜哲",
    "2630":"杨嘉诚",
    "2631":"姚弢",
    "2632":"邬立东",
    "2633":"陈哲凡",
    "2634":"吕莉",
    "2635":"管佳一",
    "2636":"金子舒童",
    "2637":"陆凯晨",
    "2638":"胡泽杰",
    "2639":"陈董锴",
    "2640":"张璇",
    "2641":"徐洁岑",
    "2642":"刘征宇",
    "2643":"",
    "2644":"",
    "2645":"",
    "2646":"",
    "2647":"",
    "2648":"",
    "2649":"徐鹏",
    "2650":"王苗苗",
  };
  console.log('[ZSH] ZJU Summer Helper is running.');
  console.log(JSON.stringify(dict));
  $("td>a").each(function() {
    var href = $(this).attr("href");
    var userId = href.substr(-4, 4);
    if (dict[userId] !== undefined && dict[userId] !== null) {
      $("font", this).append("(" + dict[userId] + ")");
    }
  });
})();