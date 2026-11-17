#include "i18n.h"

#include <windows.h>

#include <cwchar>

namespace {

struct Entry { const wchar_t* en; const wchar_t* tr; };

// Hebrew. To add a language, add a table and pick it in Table().
const Entry kHebrew[] = {
    { L"off / not connected", L"כבוי / לא מחובר" },
    { L"% (last known)", L"% (ערך אחרון ידוע)" },
    { L"unknown", L"לא ידוע" },
    { L", charging", L", בטעינה" },
    { L", asleep", L", במצב שינה" },
    { L"No devices with battery info found", L"לא נמצאו התקנים עם מידע על סוללה" },
    { L"Low battery", L"סוללה חלשה" },
    { L"%s is at %d%%", L"%s: נשארו %d%%" },
    { L"Point at a device to show, hide or move it", L"הצבע על התקן כדי להציג, להסתיר או להזיז אותו" },
    { L"Show on the taskbar", L"הצג בשורת המשימות" },
    { L"Show in the tray", L"הצג במגש המערכת" },
    { L"Move left", L"הזז שמאלה" },
    { L"Move right", L"הזז ימינה" },
    { L"Move up", L"הזז למעלה" },
    { L"Move down", L"הזז למטה" },
    { L"Hide last known / asleep devices", L"הסתר התקנים במצב שינה או עם ערך אחרון ידוע" },
    { L"Show on the taskbar (icon + percentage)", L"הצג בשורת המשימות (סמל + אחוזים)" },
    { L"Show as tray icons", L"הצג כסמלים במגש המערכת" },
    { L"Background behind taskbar text (for transparent taskbars)", L"רקע מאחורי הטקסט בשורת המשימות (לשורת משימות שקופה)" },
    { L"Show the widget on", L"הצג את הווידג'ט על" },
    { L"All monitors", L"כל המסכים" },
    { L"Main monitor only", L"המסך הראשי בלבד" },
    { L"%s only", L"%s בלבד" },
    { L"Chosen monitor (not connected, shown on main)", L"המסך שנבחר (לא מחובר, מוצג בראשי)" },
    { L"Display ", L"מסך " },
    { L"Other monitor", L"מסך אחר" },
    { L" (left)", L" (משמאל)" },
    { L" (right)", L" (מימין)" },
    { L" (above)", L" (למעלה)" },
    { L" (below)", L" (למטה)" },
    { L"Refresh now", L"רענן עכשיו" },
    { L"Start with Windows", L"הפעל עם Windows" },
    { L"Request support for a device...", L"בקשת תמיכה בהתקן..." },
    { L"Support the project...", L"תמיכה בפרויקט..." },
    { L"Exit", L"יציאה" },
    // Battery levels of devices that only report a coarse level.
    { L"Full", L"מלאה" },
    { L"Good", L"טובה" },
    { L"Medium", L"בינונית" },
    { L"Low", L"חלשה" },
    { L"Critical", L"קריטית" },
    { L"Empty", L"ריקה" },
    // How a device is connected (DeviceStatus::via).
    { L"USB cable", L"כבל USB" },
    { L"2.4 GHz receiver", L"מקלט 2.4GHz" },
    { L"2.4 GHz receiver / USB", L"מקלט 2.4GHz / USB" },
    { L"2.4 GHz receiver or USB", L"מקלט 2.4GHz או USB" },
    { L"USB base station", L"תחנת בסיס USB" },
    { L"Jabra Link dongle", L"מתאם Jabra Link" },
    { L"Logitech receiver", L"מקלט Logitech" },
    { L"Razer receiver", L"מקלט Razer" },
    { L"Corsair receiver", L"מקלט Corsair" },
    { L"Wireless adapter", L"מתאם אלחוטי" },
    { L"UWB base station", L"תחנת בסיס UWB" },
};

LANGID UiLang() { return PRIMARYLANGID(GetUserDefaultUILanguage()); }

}  // namespace

const wchar_t* T(const wchar_t* en) {
    if (UiLang() != LANG_HEBREW) return en;
    for (const auto& e : kHebrew)
        if (!wcscmp(e.en, en)) return e.tr;
    return en;
}

bool UiRtl() {
    LANGID l = UiLang();
    return l == LANG_HEBREW || l == LANG_ARABIC || l == LANG_PERSIAN || l == LANG_URDU;
}
