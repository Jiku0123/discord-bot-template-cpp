# discord-bot-template-cpp

C++ で Discord Bot を作るためのテンプレートです。

- [D++ (DPP)](https://dpp.dev/) : Discord API ライブラリ
- [dotenv-cpp](https://github.com/laserpants/dotenv-cpp) : `.env` の読み込み (CMake の FetchContent で自動取得)

## 必要環境

- C++20 に対応したコンパイラ (GCC / Clang など)
- CMake 3.20 以上
- D++ (DPP)

D++ は `find_package(DPP REQUIRED)` で探すため、事前にインストールしておく必要があります。
インストール方法は [D++ の公式ドキュメント](https://dpp.dev/install.html) を参照してください。

## ディレクトリ構成

```
.
├── CMakeLists.txt
├── debug_build.sh    # Debug ビルド用スクリプト
├── release_build.sh  # Release ビルド用スクリプト
├── .env.example      # 環境変数のサンプル
├── include/
│   └── bot.hpp       # Bot クラスの宣言
└── src/
    ├── main.cpp      # エントリポイント (トークンの読み込み)
    └── bot.cpp       # Bot クラスの実装
```

## 環境変数

プロジェクトのルートに `.env` ファイルを作成し、以下の環境変数を設定してください。
`.env.example` をコピーすると簡単です。

```bash
cp .env.example .env
```

| 変数名 | 必須 | 説明 |
| --- | --- | --- |
| `DISCORD_TOKEN` | ✅ | Discord Bot のトークン。[Discord Developer Portal](https://discord.com/developers/applications) の Bot ページで取得できます。 |

`.env` の例:

```
DISCORD_TOKEN=your_bot_token_here
```

> `.env` にはトークンが含まれるため、`.gitignore` により Git の管理対象外になっています。絶対にコミットしないでください。

## ビルド

用途に合わせて、付属のスクリプトでビルドします。

```bash
./debug_build.sh    # Debug ビルド (開発用)   -> build/debug/
./release_build.sh  # Release ビルド (運用用) -> build/release/
```

| | Debug | Release |
| --- | --- | --- |
| 最適化 | なし | あり |
| デバッグ情報 | あり | なし |
| 用途 | 開発、デバッグ | 本番運用 |

## 実行

`.env` はカレントディレクトリから読み込まれるため、プロジェクトのルートで実行してください。

```bash
./build/debug/Template     # Debug ビルドの場合
./build/release/Template   # Release ビルドの場合
```

起動に成功すると `Discord connected successfully!` と表示されます。
`DISCORD_TOKEN not found` と表示された場合は、`.env` の場所と内容を確認してください。

## Bot の作成手順

1. [Discord Developer Portal](https://discord.com/developers/applications) で New Application を作成する
2. Bot ページでトークンを取得し、`.env` に設定する
3. OAuth2 > URL Generator で `bot` スコープを選び、生成された URL からサーバーに招待する
