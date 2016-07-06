// ==UserScript==
// @name         ZJU Summer Helper
// @version      1.11
// @description  try to take over the world!
// @icon         http://fateud.com/img/favicon.ico
// @namespace    http://fateud.com/
// @author       ChouUn
// @match        http://10.71.10.99/onlinejudge/*
// @include      http://10.71.10.99/onlinejudge/*
// @updateURL    https://github.com/ChouUn/CodeWorld/raw/master/Archive/Summer%202016/ZJU%20Summer%20Helper.meta.js
// @downloadURL  https://github.com/ChouUn/CodeWorld/raw/master/Archive/Summer%202016/ZJU%20Summer%20Helper.user.js
// @supportURL   https://github.com/ChouUn/CodeWorld/issues
// @require      http://cdn.bootcss.com/jquery/2.2.4/jquery.min.js
// @require      http://cdn.bootcss.com/underscore.js/1.8.3/underscore-min.js
// @grant        none
// ==/UserScript==

(function() {
  'use strict';

  console.log('[ZSH] ZJU Summer Helper is running.');

  var userid_re = /\/onlinejudge\/showUserStatus.do\?userId=(\d{4})/;
  var score_re = /(\d+) \(\d+\)/;
  var dict = {
    "2621": "李恭荣",
    "2622": "祝融峰",
    "2623": "赵炎",
    "2624": "盛嘉森",
    "2625": "蒋加伦",
    "2626": "潘乾宇",
    "2627": "吴迪奥",
    "2628": "朱文宇",
    "2629": "颜姜哲",
    "2630": "杨嘉诚",
    "2631": "姚弢",
    "2632": "邬立东",
    "2633": "陈哲凡",
    "2634": "吕莉",
    "2635": "管佳一",
    "2636": "金子舒童",
    "2637": "陆凯晨",
    "2638": "胡泽杰",
    "2639": "陈董锴",
    "2640": "张璇",
    "2641": "徐洁岑",
    "2642": "刘征宇",
  };

  $(".problemsetList").add(".list").find("a").filter(function() {
    // check tag <a> have urls of known users
    var href = $(this).attr("href");
    if (!href) return false;
    var result = userid_re.exec(href);
    if (!result) return false;
    var userid = result[1];
    if (!userid) return false;
    var realname = dict[userid];
    if (!realname) return false;

    // write data in tag <a>
    $(this).data("userid", userid);
    return true;
  }).each(function() {
    // inject realname into tag <font>
    var userid = $(this).data("userid"),
        realname = dict[userid];
    $("font", this).append("(" + realname + ")");
    console.log('[ZSH] add realname ' + realname + ' for user ' + userid + ' is succussful.');
  });

  $(".list").each(function() {
    // create problems array
    var arrs = [];
    $("tr:eq(0)", this).each(function() {
      $(".ranklistProblem", this).each(function() {
        arrs.push([]);
      });
    });
    if (arrs.length === 0) return;

    // divide data from rows to cols into arrs
    $("tr:gt(0)", this).each(function() {
      var userid = $(".ranklistUser>a", this).data("userid");
      if (!userid) return;
      $(".ranklistProblem", this).each(function(index) {
        var data = $(this).html();
        if (!data) return;
        var result = score_re.exec(data);
        if (!result) return;
        var score = result[1];
        if (!score) return;
        score = Number(score);
        console.log([index, userid, score, this]);
        arrs[index].push([userid, score, this]);
      });
    });

    // traverse each problem
    _.each(arrs, function(arr, index, list) {
      // group by score and set data "score" of each tag <td>
      var data = _.groupBy(arr, function(element) {
            return element[1];
          }),
          score = 100;
      _.each(data, function(value, key, list) {
        _.each(value, function(element) {
          $(element[2]).data("score", score);
        });
        score = (score > 60 ? score - 5 : score);
      });
    });

    // display all scores
    $("tr:gt(0)", this).each(function() {
      var userid = $(".ranklistUser>a", this).data("userid");
      if (!userid) return;
      // generate a report into console
      var logs = [];
      $(".ranklistProblem", this).each(function(index) {
        var score = $(this).data("score");
        logs.push(score = !score ? 0 : Number(score));
        if (score === 0) return;
        $(this).append(" <b style=\"color: red;\">" + score + "</b>");
      });
      logs.unshift(_.reduce(logs, function(memo, num) { return memo + num; }, 0));
      logs.unshift(dict[userid]);
      console.log(logs);
      $(".ranklistSolved", this).append(" <b style=\"color: red;\">" + logs[1] + "</b>");
    });

  });

})();