# 🍏 Шпаргалка по автосмене обоев в macOS

Полный набор команд и скриптов для автоматической смены обоев в зависимости от времени суток. Все папки и скрипты настроены локально для пользователя **andrey**.

---

## 📂 Расположение папок с обоями

Для стабильной работы папки с изображениями должны находиться строго в домашней директории:

- **Утренние обои:** `/Users/andrey/Morning_Wallpapers`
- **Ночные обои:** `/Users/andrey/Night_Wallpapers`
q
_Рекомендуемые форматы файлов в папках: `.jpg`, `.jpeg`, `.png`, `.heic`._

---

## 🛠 Управление через Терминал

### 1. Принудительная смена обоев (Тестирование)

Запуск смены обоев вручную в любой момент времени, не дожидаясь наступления 08:00 или 20:00:

```bash
# Включить случайные обои из утренней папки
launchctl start com.user.morningwallpaper

# Включить случайные обои из ночной папки
launchctl start com.user.nightwallpaper
```

### 2. Временное отключение автосмены

Используйте эти команды, если хотите поставить постоянные обои и заблокировать работу планировщика:

```bash
# Отключить утренний таймер
launchctl unload ~/Library/LaunchAgents/com.user.morningwallpaper.plist

# Отключить ночной таймер
launchctl unload ~/Library/LaunchAgents/com.user.nightwallpaper.plist
```

### 3. Включение автосмены обратно

Активация таймеров после их временного отключения:

```bash
# Включить утренний таймер
launchctl load ~/Library/LaunchAgents/com.user.morningwallpaper.plist

# Включить ночной таймер
launchctl load ~/Library/LaunchAgents/com.user.nightwallpaper.plist
```

### 4. Полное удаление автоматизации с компьютера

Команда полностью останавливает службы и удаляет файлы конфигурации из системы:

```bash
launchctl unload ~/Library/LaunchAgents/com.user.morningwallpaper.plist 2>/dev/null
launchctl unload ~/Library/LaunchAgents/com.user.nightwallpaper.plist 2>/dev/null
rm ~/Library/LaunchAgents/com.user.morningwallpaper.plist
rm ~/Library/LaunchAgents/com.user.nightwallpaper.plist
```

---

## 📜 Исходный код файлов конфигурации (.plist)

Данные файлы сохранены в скрытой системной директории `~/Library/LaunchAgents/` и отвечают за фоновую работу планировщика.

### 🌅 Утренний скрипт (Запуск каждый день в 08:00)

Путь к файлу: `~/Library/LaunchAgents/com.user.morningwallpaper.plist`

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://apple.com">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>com.user.morningwallpaper</string>
    <key>ProgramArguments</key>
    <array>
        <string>/bin/bash</string>
        <string>-c</string>
        <string>FOLDER="/Users/andrey/Morning_Wallpapers"; PIC=$(find "$FOLDER" -type f \( -name "*.jpg" -o -name "*.png" -o -name "*.jpeg" -o -name "*.heic" \) | /usr/bin/sort -R | /usr/bin/head -n 1); /usr/bin/osascript -e "tell application \"System Events\" to set picture of every desktop to \"$PIC\""</string>
    </array>
    <key>StartCalendarInterval</key>
    <dict>
        <key>Hour</key>
        <integer>8</integer>
        <key>Minute</key>
        <integer>0</integer>
    </dict>
</dict>
</plist>
```

### 🌌 Ночной скрипт (Запуск каждый день в 20:00)

Путь к файлу: `~/Library/LaunchAgents/com.user.nightwallpaper.plist`

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://apple.com">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>com.user.nightwallpaper</string>
    <key>ProgramArguments</key>
    <array>
        <string>/bin/bash</string>
        <string>-c</string>
        <string>FOLDER="/Users/andrey/Night_Wallpapers"; PIC=$(find "$FOLDER" -type f \( -name "*.jpg" -o -name "*.png" -o -name "*.jpeg" -o -name "*.heic" \) | /usr/bin/sort -R | /usr/bin/head -n 1); /usr/bin/osascript -e "tell application \"System Events\" to set picture of every desktop to \"$PIC\""</string>
    </array>
    <key>StartCalendarInterval</key>
    <dict>
        <key>Hour</key>
        <integer>20</integer>
        <key>Minute</key>
        <integer>0</integer>
    </dict>
</dict>
</plist>
```

---

## ⚙️ Как это работает внутри:

1. `FOLDER="..."` — задает переменную с путем к вашей папке.
2. `find ...` — сканирует указанную папку и находит все поддерживаемые форматы изображений.
3. `sort -R | head -n 1` — перемешивает список найденных картинок и случайным образом выбирает из них одну.
4. `osascript -e ...` — через встроенный язык AppleScript отдает команду системе принудительно установить выбранное изображение на все доступные рабочие столы.
