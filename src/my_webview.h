#pragma once

#include "WebView2.h"
#include "fmt/core.h"
#include "fmt/xchar.h"
#include <boost/locale.hpp>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <wrl.h>
#include <wrl/client.h>

using namespace Microsoft::WRL;

inline ComPtr<ICoreWebView2Controller> webviewController;
inline ComPtr<ICoreWebView2> webview;
inline ComPtr<ICoreWebView2_3> webview3;
inline ComPtr<ICoreWebView2Controller2> webviewController2;

inline std::wstring HTMLString = LR"()";
inline std::wstring BodyString = LR"()";
inline std::wstring CandStr = L"";
const std::wstring LocalAssetsPath =
    L"C:\\Users\\SonnyCalcr\\AppData\\Roaming\\PotPlayerMini64\\Capture";

int PrepareWindowHtml();
void UpdateHtmlContentWithJavaScript( //
    ComPtr<ICoreWebView2>,            //
    const std::wstring &              //
);                                    //
void InitWebview(HWND);

inline std::wstring HTMLStringInit = LR"(
<!DOCTYPE html>
<html lang="zh-CN">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Vertical Candidate Window</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      height: 100vh;
      margin: 0;
      overflow: hidden;
      border-radius: 6px;
      background: transparent;

      /* background: aliceblue; */
    }

    .container {
      margin-top: 0px;
      margin-left: 0px;
      background-color: #202020;
      /* background: url("https://appassets/background.jpg"); */
      padding: 2px;
      border-radius: 6px;
      box-shadow: 5px 5px 10px rgba(0, 0, 0, 0.5);
      min-width: 70px;
      width: fit-content;
      /* width: 500px; */
      user-select: none;
      border: 2px solid #9b9b9b2e;
    }

    .row {
      justify-content: space-between;
      padding: 2px;
      padding-right: 12px;
      padding-top: 0;
      padding-bottom: 0;
      margin-top: 2px;
    }

    .cand {
      border-radius: 6px;
    }

    .hover-active .cand:hover {
      background-color: #414141;
    }

    .row-wrapper {
      position: relative;
    }

    .first {
      background-color: #3e3e3eb9;
      border-radius: 6px;
    }

    .first::before {
      content: "";
      position: absolute;
      left: 0;
      top: 50%;
      transform: translateY(-50%);
      height: 16px;
      width: 3px;
      background: linear-gradient(to bottom, #ff7eb3, #ff758c, #ff5a5f);
      border-radius: 8px;
    }

    .text {
      padding-left: 8px;
      color: #e9e8e8;
    }

    .input-container {
      max-width: 60%;
      margin-top: 1rem;
      margin-left: 1rem;
    }

    .chat-input {
      font-family: 'Noto Sans SC', Arial, sans-serif;
      width: 100%;
      min-height: 8rem;
      max-height: 12rem;
      padding: 12px;
      resize: none;
      border: 2px solid #292b2ef1;
      border-radius: 0.75rem;
      font-size: 16px;
      line-height: 1.25;
      box-sizing: border-box;
      background-color: #202020;
      outline: none;
      overflow-y: auto;
      caret-color: #e9e8e8;
      color: #e9e8e8;
    }

    .chat-input:focus {
      border-color: #479e9da0;
    }
  </style>

  <script>
    let a = false;
    document.addEventListener('DOMContentLoaded', function () {
      document.addEventListener('mousemove', function () {
        if (a === true) {
          const container = document.getElementById('container');
          container.classList.add('hover-active');
        }
        a = true;
      });
    });
  </script>
</head>

<body>
  <div class="container" id="container">
    <!--0Anchor-->
    <div class="row pinyin">
      <div class="text">ni</div>
    </div>
    <!--1Anchor-->
    <div class="row-wrapper">
      <div class="row cand first">
        <div class="text">1. 你</div>
      </div>
    </div>
    <!--2Anchor-->
    <div class="row-wrapper">
      <div class="row cand">
        <div class="text">2. 笔</div>
      </div>
    </div>
    <!--3Anchor-->
    <div class="row-wrapper">
      <div class="row cand">
        <div class="text">3. 量</div>
      </div>
    </div>
    <!--4Anchor-->
    <div class="row-wrapper">
      <div class="row cand">
        <div class="text">4. 牛</div>
      </div>
    </div>
    <!--5Anchor-->
    <div class="row-wrapper">
      <div class="row cand">
        <div class="text">5. 仙</div>
      </div>
    </div>
    <!--6Anchor-->
    <div class="row-wrapper">
      <div class="row cand">
        <div class="text">6. 可</div>
      </div>
    </div>
    <!--7Anchor-->
    <div class="row-wrapper">
      <div class="row cand">
        <div class="text">7. 木</div>
      </div>
    </div>
    <!--8Anchor-->
    <div class="row-wrapper">
      <div class="row cand">
        <div class="text">8. 无</div>
      </div>
    </div>
    <!--9Anchor-->
  </div>

  <div class="input-container">
    <textarea class="chat-input" placeholder=""></textarea>
  </div>
</body>

</html>
)";

inline std::wstring BodyStringInit = LR"(
<div class="container" id="container">
  <!--0Anchor-->
  <div class="row pinyin">
    <div class="text">ni</div>
  </div>
  <!--1Anchor-->
  <div class="row-wrapper">
    <div class="row cand first">
      <div class="text">1. 你</div>
    </div>
  </div>
  <!--2Anchor-->
  <div class="row-wrapper">
    <div class="row cand">
      <div class="text">2. 笔</div>
    </div>
  </div>
  <!--3Anchor-->
  <div class="row-wrapper">
    <div class="row cand">
      <div class="text">3. 量</div>
    </div>
  </div>
  <!--4Anchor-->
  <div class="row-wrapper">
    <div class="row cand">
      <div class="text">4. 牛</div>
    </div>
  </div>
  <!--5Anchor-->
  <div class="row-wrapper">
    <div class="row cand">
      <div class="text">5. 仙</div>
    </div>
  </div>
  <!--6Anchor-->
  <div class="row-wrapper">
    <div class="row cand">
      <div class="text">6. 可</div>
    </div>
  </div>
  <!--7Anchor-->
  <div class="row-wrapper">
    <div class="row cand">
      <div class="text">7. 木</div>
    </div>
  </div>
  <!--8Anchor-->
  <div class="row-wrapper">
    <div class="row cand">
      <div class="text">8. 无</div>
    </div>
  </div>
  <!--9Anchor-->
</div>
)";