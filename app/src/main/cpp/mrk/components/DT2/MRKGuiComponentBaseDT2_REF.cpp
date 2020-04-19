#include <cmath>

#include "MRKGuiComponentBaseDT2_REF.h"
#include "../../gui/MRKGUI.h"
#include "../../mono/MRKMonoAPI.h"
#include "../../MRKApplication.h"

namespace MRK {
    namespace Components {
        MRKGuiComponentBaseDT2_REF::MRKGuiComponentBaseDT2_REF(_GUI MRKDisplay *display)
                : MRKGuiComponent(
                display), m_DescWindowTheme(*display->Theme()), m_LogView(this) {
            m_Visible = true;
            m_FreeWdigets.insert(
                    _STD make_pair(WIDGET_TYPE_BUTTON, _STD vector<_GUI MRKGuiBaseWidget *>()));
            m_FreeWdigets.insert(
                    _STD make_pair(WIDGET_TYPE_LABEL, _STD vector<_GUI MRKGuiBaseWidget *>()));
            m_FreeWdigets.insert(
                    _STD make_pair(WIDGET_TYPE_SLIDER, _STD vector<_GUI MRKGuiBaseWidget *>()));
            m_FreeWdigets.insert(
                    _STD make_pair(WIDGET_TYPE_WINDOW, _STD vector<_GUI MRKGuiBaseWidget *>()));
            m_Container = new _GUI MRKGuiBaseWindow(display, _GUI MRK_ANCHOR_MIDDLE_CENTER,
                                                    _MATH Rect(-1010.f, -490.f, 2020.f, 980.f),
                                                    "MRK DT2");
            m_Container->SetDraggable(false);
            m_HackDescriptionLabel = display->RegisterWidget(new _GUI MRKGuiBaseLabel(m_Container,
                                                                                      _GUI MRK_ANCHOR_NONE,
                                                                                      _MATH Rect(
                                                                                              20.f,
                                                                                              880.f,
                                                                                              2020.f,
                                                                                              170.f),
                                                                                      "", 24,
                                                                                      _GUI MRK_ALIGN_LEFT,
                                                                                      _GUI MRKFont::Exo2Regular));
            m_DescWindowTheme.WindowFillFocused = MRKColor(32, 255);
            m_DescriptionWindow = display->RegisterWidget(
                    new _GUI MRKGuiBaseWindow(m_Container, _GUI MRK_ANCHOR_NONE,
                                              _MATH Rect(1030.f, 110.f, 970.f, 870.f), ""));
            m_DescriptionWindow->SetDraggable(false);
            m_DescriptionWindow->SetTheme(&m_DescWindowTheme);
            m_Descriptors = new DescriptorArray[DESCRIPTORS_COUNT]{
                    DescriptorArray{ //bone
                            4,
                            new _STD string[4]{
                                    "Chest",
                                    "Head",
                                    "Arm",
                                    "Leg"
                            }
                    },
                    DescriptorArray{ //dimension
                            2,
                            new _STD string[2]{
                                    "2D",
                                    "3D"
                            }
                    },
                    DescriptorArray{ //colour
                            4,
                            new _STD string[4]{
                                    "Fixed",
                                    "Rainbow",
                                    "Gradient",
                                    "Visibility"
                            }
                    },
                    DescriptorArray{ //pos
                            3,
                            new _STD string[3]{
                                    "[   ^   ]",
                                    "[   -   ]",
                                    "[   .   ]"
                            }
                    },
                    DescriptorArray{
                            2,
                            new _STD string[2]{
                                    "Vertical",
                                    "Horizontal"
                            }
                    },
                    DescriptorArray{
                            2,
                            new _STD string[2]{
                                    "Swipe",
                                    "Manual"
                            }
                    },
                    DescriptorArray{
                            2,
                            new _STD string[2]{
                                    "Fixed health",
                                    "No damage"
                            }
                    },
                    DescriptorArray{
                            2,
                            new _STD string[2]{
                                    "MRK n ShanGo's fresh moves",
                                    "Teleport"
                            }
                    }
            };
            float width = 2020.f / CATEGORY_COUNT;
            m_Categories = new Category[CATEGORY_COUNT]
                    {
                            Category{
                                    "Automation",
                                    display->RegisterWidget(
                                            new _GUI MRKGuiBaseButton(m_Container,
                                                                      _GUI MRK_ANCHOR_NONE,
                                                                      _MATH Rect(0.f, 0.f, width,
                                                                                 100.f),
                                                                      "Automation")),
                                    4,
                                    new Hack[4]{
                                            Hack{
                                                    "Aimbot",
                                                    "Aim at an entity within a specified range",
                                                    4,
                                                    new HackOption[4]{
                                                            HackOption{
                                                                    "AIMBOT",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Range",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseSlider(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    0.f, 1.f))
                                                            },
                                                            HackOption{
                                                                    "Bone",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Chest"))
                                                            },
                                                            HackOption{
                                                                    "Through Walls",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Silent Aimbot",
                                                    "Aim at an entity without changing direction",
                                                    4,
                                                    new HackOption[4]{
                                                            HackOption{
                                                                    "SILENT AIMBOT",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Range",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseSlider(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    0.f, 1.f))
                                                            },
                                                            HackOption{
                                                                    "Bone",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Chest"))
                                                            },
                                                            HackOption{
                                                                    "Through Walls",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Triggerbot",
                                                    "Auto shoot at an entity within specified crosshair radius",
                                                    4,
                                                    new HackOption[4]{
                                                            HackOption{
                                                                    "TRIGGERBOT",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Always shoot at an entity",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Crosshair Radius",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseSlider(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    0.f, 1.f))
                                                            },
                                                            HackOption{
                                                                    "Through Walls",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "360s",
                                                    "Aim at an entity after performing a 360",
                                                    2,
                                                    new HackOption[2]{
                                                            HackOption{
                                                                    "360S",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Time taken per 360",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseSlider(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    0.f, 1.f))
                                                            }
                                                    }
                                            }
                                    }
                            },
                            Category{
                                    "Visuals",
                                    display->RegisterWidget(
                                            new _GUI MRKGuiBaseButton(m_Container,
                                                                      _GUI MRK_ANCHOR_NONE,
                                                                      _MATH Rect(width, 0.f, width,
                                                                                 100.f),
                                                                      "Visuals")),
                                    4,
                                    new Hack[4]{
                                            Hack{
                                                    "Boxes",
                                                    "Draw box boundaries around entities",
                                                    4,
                                                    new HackOption[4]{
                                                            HackOption{
                                                                    "BOXES",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Dimension",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "2D"))
                                                            },
                                                            HackOption{
                                                                    "Color",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Fixed"))
                                                            },
                                                            HackOption{
                                                                    "Highlight automation target",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Disabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Tracers",
                                                    "Draw lines from specified start position to entities",
                                                    4,
                                                    new HackOption[4]{
                                                            HackOption{
                                                                    "LINES",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Position",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "[   .   ]"))
                                                            },
                                                            HackOption{
                                                                    "Color",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Fixed"))
                                                            },
                                                            HackOption{
                                                                    "Highlight automation target",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Disabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Distance",
                                                    "Draw distance labels between entities and local player",
                                                    3,
                                                    new HackOption[3]{
                                                            HackOption{
                                                                    "DISTANCE",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Color",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Fixed"))
                                                            },
                                                            HackOption{
                                                                    "Highlight automation target",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Disabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Health",
                                                    "Draw entities' health",
                                                    3,
                                                    new HackOption[3]{
                                                            HackOption{
                                                                    "HEALTH",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Color",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Gradient"))
                                                            },
                                                            HackOption{
                                                                    "Layout",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Vertical"))
                                                            }
                                                    }
                                            }
                                    }
                            },
                            Category{
                                    "Movement",
                                    display->RegisterWidget(
                                            new _GUI MRKGuiBaseButton(m_Container,
                                                                      _GUI MRK_ANCHOR_NONE,
                                                                      _MATH Rect(width * 2.f, 0.f,
                                                                                 width, 100.f),
                                                                      "Movement")),
                                    5,
                                    new Hack[5]{
                                            Hack{
                                                    "Fly",
                                                    "Increment local player's ypos over time",
                                                    3,
                                                    new HackOption[3]{
                                                            HackOption{
                                                                    "FLY",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Activation",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Swipe"))
                                                            },
                                                            HackOption{
                                                                    "Speed(Affects manual activation only)",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseSlider(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    0.f, 1.f))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Freeze Constraints",
                                                    "Freeze local player's constraints",
                                                    3,
                                                    new HackOption[3]{
                                                            HackOption{
                                                                    "FREEZE CONSTRAINTS",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "X",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Y",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "No Trigger",
                                                    "Disable interactions with environmental objects",
                                                    2,
                                                    new HackOption[2]{
                                                            HackOption{
                                                                    "NO TRIGGER",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Teleport against object",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Free Move",
                                                    "Free move around map",
                                                    2,
                                                    new HackOption[2]{
                                                            HackOption{
                                                                    "FREE MOVE",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Speed",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseSlider(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    0.f, 1.f))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Speed",
                                                    "Set local player's speed",
                                                    2,
                                                    new HackOption[2]{
                                                            HackOption{
                                                                    "SPEED",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Value",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseSlider(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    0.f, 1.f))
                                                            }
                                                    }
                                            }
                                    }
                            },
                            Category{
                                    "Misc",
                                    display->RegisterWidget(
                                            new _GUI MRKGuiBaseButton(m_Container,
                                                                      _GUI MRK_ANCHOR_NONE,
                                                                      _MATH Rect(width * 3.f, 0.f,
                                                                                 width, 100.f),
                                                                      "Misc")),
                                    4,
                                    new Hack[4]{
                                            Hack{
                                                    "Godmode",
                                                    "Invincible",
                                                    3,
                                                    new HackOption[3]{
                                                            HackOption{
                                                                    "GODMODE",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Algorithm",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Fixed health"))
                                                            },
                                                            HackOption{
                                                                    "Health value(Affects fixed health algorithm only)",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseSlider(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    0.f, 1.f))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Masskill",
                                                    "Kill all living entities",
                                                    1,
                                                    new HackOption[1]{
                                                            HackOption{
                                                                    "MASSKILL",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Mess with em",
                                                    "haha",
                                                    2,
                                                    new HackOption[2]{
                                                            HackOption{
                                                                    "MESS WITH EM",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            },
                                                            HackOption{
                                                                    "Mode",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "MRK n ShanGo's fresh moves"))
                                                            }
                                                    }
                                            },
                                            Hack{
                                                    "Make me rich",
                                                    "rich lyf",
                                                    1,
                                                    new HackOption[1]{
                                                            HackOption{
                                                                    "MAKE ME RICH",
                                                                    display->RegisterWidget(
                                                                            new _GUI MRKGuiBaseButton(
                                                                                    m_DescriptionWindow,
                                                                                    _GUI MRK_ANCHOR_NONE,
                                                                                    _MATH Rect(20.f,
                                                                                               0.f,
                                                                                               930.f,
                                                                                               70.f),
                                                                                    "Enabled"))
                                                            }
                                                    }
                                            }
                                    }
                            },
                            Category{
                                    "MRK",
                                    display->RegisterWidget(
                                            new _GUI MRKGuiBaseButtonEx(m_Container,
                                                                        _GUI MRK_ANCHOR_NONE,
                                                                        _MATH Rect(width * 4.f, 0.f,
                                                                                   width, 100.f),
                                                                        "MRK", true, false))
                            }
                    };
            m_SelectedCategory = &m_Categories[0];
            m_SelectedCategory->m_Button->SetForceDown(true);
            for (size_t sz = 0; sz < CATEGORY_COUNT; sz++) {
                Category *current = &m_Categories[sz];
                if (current->m_HackCount > 0)
                    current->m_SelectedHack = &current->m_Hacks[0];
                if (sz == CATEGORY_COUNT - 1) {
                    current->m_Button->SetFontSize(42);
                    current->m_Button->SetFont(_GUI MRKFont::Exo2Bold);
                    current->m_Button->SetCallback([this, current] {
                        m_SelectedCategory->m_Button->SetForceDown(false);
                        for (int i = 0; i < m_SelectedCategory->m_HackCount; i++)
                            (&m_SelectedCategory->m_Hacks[i])->m_Button->SetVisible(false);
                        m_SelectedCategory = current;
                        m_SelectedCategory->m_Button->SetForceDown(true);
                        if (m_SelectedHack) {
                            //clean all options
                            for (size_t i = 0; i < m_SelectedHack->m_OptionCount; i++) {
                                HackOption *option = &m_SelectedHack->m_Options[i];
                                FreeWidget(option->m_WidgetLabel, WIDGET_TYPE_LABEL);
                                if (option->m_Widget)
                                    option->m_Widget->SetVisible(false);
                            }
                            m_SelectedHack->m_Button->SetForceDown(false);
                        }
                        m_DescriptionWindow->SetVisible(false);
                        m_HackDescriptionLabel->SetVisible(false);
                    });
                } else {
                    current->m_Button->SetFontSize(33);
                    current->m_Button->SetFont(_GUI MRKFont::Exo2Regular);
                    current->m_Button->SetCallback([this, current] {
                        m_SelectedCategory->m_Button->SetForceDown(false);
                        for (int i = 0; i < m_SelectedCategory->m_HackCount; i++)
                            (&m_SelectedCategory->m_Hacks[i])->m_Button->SetVisible(false);
                        m_SelectedCategory = current;
                        m_SelectedCategory->m_Button->SetForceDown(true);
                        for (int i = 0; i < m_SelectedCategory->m_HackCount; i++)
                            (&m_SelectedCategory->m_Hacks[i])->m_Button->SetVisible(true);
                        m_DescriptionWindow->SetVisible(true);
                        m_HackDescriptionLabel->SetVisible(true);
                        SelectedHackChanged(m_SelectedCategory->m_SelectedHack);
                    });
                }
            }

            for (size_t i = 0; i < CATEGORY_COUNT; i++) {
                Category *category = &m_Categories[i];
                for (size_t j = 0; j < category->m_HackCount; j++) {
                    Hack *hack = &category->m_Hacks[j];
                    hack->m_Button = display->RegisterWidget(
                            new _GUI MRKGuiBaseButton(m_Container, _GUI MRK_ANCHOR_NONE,
                                                      _MATH Rect(10.f, (j + 1) * 110.f, 990.f,
                                                                 100.f),
                                                      hack->m_Name, 30));
                    for (size_t l = 0; l < hack->m_OptionCount; l++) {
                        HackOption *option = &hack->m_Options[l];
                        switch (option->m_Widget->Id()) {
                            case WIDGET_TYPE_BUTTON: {
                                _GUI MRKGuiBaseButton *button = (_GUI MRKGuiBaseButton *) option->m_Widget;
                                button->SetFontSize(30);
                                if (button->GetText() == "Enabled" ||
                                    button->GetText() == "Disabled") {
                                    button->SetText("Disabled");
                                    //toggle
                                    button->SetCallback([button, i, j, l] {
                                        bool enabled = button->GetText() == "Enabled";
                                        button->SetText(enabled ? "Disabled" : "Enabled");
                                        button->SetForceDown(!enabled);
                                        _MONO SendMessageB(i, j, l, !enabled);
                                    });
                                } else {
                                    DescriptorArray *descriptorArray = FindDescriptor(
                                            button->GetText());
                                    if (!descriptorArray) {
                                        //pipe fault later
                                        break;
                                    }
                                    button->SetCallback([this, button, descriptorArray, i, j, l] {
                                        size_t idx;
                                        button->SetText(
                                                NextDescriptor(descriptorArray, button->GetText(),
                                                               &idx));
                                        _MONO SendMessageI(i, j, l, idx);
                                    });
                                }
                                break;
                            }

                            case WIDGET_TYPE_SLIDER: {
                                _GUI MRKGuiBaseSlider *slider = (_GUI MRKGuiBaseSlider *) option->m_Widget;
                                float min;
                                float max;
                                //_MONO SendMessagePFPF(i, j, l, &min, &max);
                                slider->SetRange(20.f, 100.f);
                                slider->SetCallback([i, j, l](float value) {
                                    _MONO SendMessageF(i, j, l, value);
                                });
                                break;
                            }
                        }
                    }
                    hack->m_Button->SetCallback([this, hack] {
                        SelectedHackChanged(hack);
                    });
                    if (category != m_SelectedCategory)
                        hack->m_Button->SetVisible(false);
                    for (size_t k = 0; k < hack->m_OptionCount; k++)
                        (&hack->m_Options[k])->m_Widget->SetVisible(false);
                }
            }
            m_SelectedHack = 0;
            SelectedHackChanged(&m_SelectedCategory->m_Hacks[0]);
            m_ButtonRect = _MATH Rect(0.f, 0.f, _UTILITY CalculateRelativeWidth(256.f),
                                      _UTILITY CalculateRelativeHeight(256.f));
            m_Display->RegisterTouchCallback([this](MRKTouchEvent &event) {
                if (m_Display->Visible()) {
                    if (m_Container->Rectangle().Contains(event.MousePosition())) {
                        if (m_SelectedCategory == &m_Categories[CATEGORY_COUNT - 1]) {
                            if (event.Type() == MRKTouchEventType::Drag) {
                                if (event.Delta().Y() > 0.f) {
                                    if (m_LogView.ScrollOffset() > 0)
                                        m_LogView.ScrollOffset()--;
                                } else
                                    m_LogView.ScrollOffset()++;
                            }
                        }
                        return;
                    }
                    m_Display->SetVisible(false);
                    return;
                }
                if (event.Type() == MRKTouchEventType::Up &&
                    m_ButtonRect.Contains(event.MousePosition()))
                    m_Display->SetVisible(true);
            });
            m_BuildLabel = new _GUI MRKGuiBaseLabel(display, _GUI MRK_ANCHOR_BOTTOM_LEFT,
                                                    _MATH Rect(5.f, 30.f, 200.f, 30.f),
                                                    MRK_BUILD_VERSION, 22,
                                                    _GUI MRKLabelAlignment::MRK_ALIGN_LEFT,
                                                    _GUI MRKFont::Exo2Bold,
                                                    _GUI MRKLabelFlags::DropShadow);
            //_GUI MRKGuiBaseSlider *slider = new _GUI MRKGuiBaseSlider(display,
            //                                                         _GUI MRK_ANCHOR_MIDDLE_CENTER,
            //                                                         _MATH Rect(0.f, 0.f, 100.f,
            //                                                                    30.f), 50.f, 100.f);
        }

        void MRKGuiComponentBaseDT2_REF::SelectedHackChanged(Hack *newHack) {
            if (newHack == m_SelectedHack || !newHack)
                return;
            if (m_SelectedHack) {
                //clean all options
                for (size_t i = 0; i < m_SelectedHack->m_OptionCount; i++) {
                    HackOption *option = &m_SelectedHack->m_Options[i];
                    //option->m_Widget->SetVisible(false);
                    //option->m_WidgetLabel->SetVisible(false);
                    FreeWidget(option->m_WidgetLabel, WIDGET_TYPE_LABEL);
                    if (option->m_Widget)
                        option->m_Widget->SetVisible(false);
                }
                m_SelectedHack->m_Button->SetForceDown(false);
            }
            m_HackDescriptionLabel->SetText(newHack->m_Description);
            m_SelectedHack = newHack;
            m_SelectedCategory->m_SelectedHack = newHack;
            m_SelectedHack->m_Button->SetForceDown(true);
            //create options
            float nextY = 10.f;
            float yShift = 10.f; //(810.f - (m_SelectedHack->m_OptionCount * 175.f + 10.f)) / 2.f;
            for (size_t i = 0; i < m_SelectedHack->m_OptionCount; i++) {
                HackOption *option = &m_SelectedHack->m_Options[i];
                //label
                //option->m_Widget->SetVisible(true);
                //option->m_WidgetLabel->SetVisible(true);
                _GUI MRKGuiBaseLabel *optLabel = (_GUI MRKGuiBaseLabel *) GetFreeWidget(
                        WIDGET_TYPE_LABEL);
                *optLabel = _GUI MRKGuiBaseLabel(m_DescriptionWindow, _GUI MRK_ANCHOR_NONE,
                                                 _MATH Rect(20.f, nextY + yShift, 930.f, 50.f),
                                                 option->m_Name, 36,
                                                 _GUI MRK_ALIGN_LEFT,
                                                 _GUI MRKFont::Exo2Regular); /*Compiler error if not casted*/
                m_Display->RegisterWidget(optLabel);
                option->m_WidgetLabel = optLabel;
                if (option->m_Widget) {
                    option->m_Widget->SetVisible(true);
                    if (option->m_Widget->Id() == WIDGET_TYPE_SLIDER) {
                        ((_GUI MRKGuiBaseSlider *) option->m_Widget)->SetLiveCallback(
                                [option](float val) {
                                    option->m_WidgetLabel->SetText(
                                            option->m_Name + "(" + _STD to_string(val) + ")");
                                });
                    }
                    option->m_Widget->SetS9Plus_FHDPLUS_Position(
                            _MATH Vector2(20.f, nextY + 75.f + yShift));
                }
                nextY += 175.f;
            }
        }

        _GUI MRKGuiBaseWidget *MRKGuiComponentBaseDT2_REF::GetFreeWidget(WidgetType type) {
            _STD vector<_GUI MRKGuiBaseWidget *> *target = &m_FreeWdigets.at(type);
            if (!target->empty()) {
                _GUI MRKGuiBaseWidget *widget = target->back();
                widget->SetVisible(true);
                target->pop_back();
                return widget;
            }
            //create new widget of type
            _GUI MRKGuiBaseWidget *widget = 0;
            switch (type) {
                case WIDGET_TYPE_BUTTON:
                    widget = new _GUI MRKGuiBaseButton(m_Display, _GUI MRK_ANCHOR_NONE,
                                                       _MATH Rect(), "");
                    break;
                case WIDGET_TYPE_LABEL:
                    widget = new _GUI MRKGuiBaseLabel(m_Display, _GUI MRK_ANCHOR_NONE, _MATH Rect(),
                                                      "");
                    break;
                case WIDGET_TYPE_SLIDER:
                    widget = new _GUI MRKGuiBaseSlider(m_Display, _GUI MRK_ANCHOR_NONE,
                                                       _MATH Rect(), 0.f, 1.f);
                    break;
                case WIDGET_TYPE_WINDOW:
                    widget = new _GUI MRKGuiBaseWindow(m_Display, _GUI MRK_ANCHOR_NONE,
                                                       _MATH Rect(), "");
                    break;
            }
            return widget;
        }

        void
        MRKGuiComponentBaseDT2_REF::FreeWidget(_GUI MRKGuiBaseWidget *widget, WidgetType type) {
            widget->SetVisible(false); //hide
            m_FreeWdigets.at(type).push_back(widget);
        }

        void MRKGuiComponentBaseDT2_REF::GUI(MRKUIcontext *context) {
            if (!m_Display->Visible()) {
                MRKUIBeginPath(context);
                _GUI MRKGUI::Picture(m_ButtonRect, DT2MS_PIC);
                m_BuildLabel->Draw(context);
                return;
            }
            float relH = _UTILITY CalculateRelativeHeight(1080.f);
            float relW = _UTILITY CalculateRelativeWidth(100.f);
            _GUI MRKGUI::Picture(_MATH Rect(0.f, 0.f, relW, relH),
                                 MRK_PIC);
            _GUI MRKGUI::Picture(_MATH Rect(m_Display->Info()->Width - relW, 0.f, relW, relH),
                                 SHANGO_PIC);
            if (m_SelectedCategory == &m_Categories[CATEGORY_COUNT - 1])
                m_LogView.Draw(context);
        }

        MRKGuiComponentBaseDT2_REF::DescriptorArray *
        MRKGuiComponentBaseDT2_REF::FindDescriptor(_STD string s) {
            for (size_t i = 0; i < DESCRIPTORS_COUNT; i++) {
                DescriptorArray *arr = &m_Descriptors[i];
                for (size_t j = 0; j < arr->size; j++) {
                    if (arr->desc[j] == s)
                        return arr;
                }
            }
            return 0;
        }

        _STD string MRKGuiComponentBaseDT2_REF::NextDescriptor(
                MRKGuiComponentBaseDT2_REF::DescriptorArray *array,
                const _STD string now, size_t *_i) {
            int index = -1;
            for (size_t i = 0; i < array->size; i++) {
                if (array->desc[i] == now) {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                return "Invalid Descriptor(" + now + ")";
            index++;
            if (index == array->size)
                index = 0;
            if (_i)
                *_i = _MATH MRKMath::UnSign(index);
            return array->desc[index];
        }

        void MRKGuiComponentBaseDT2_REF::LogView::Draw(MRKUIcontext *ctx) {
            MRKUIBeginPath(ctx);
            MRKUIFillColor(ctx, MRKUIRGBA(0, 0, 0, 128));
            float x = m_Base->m_Container->Position().X() + _UTILITY CalculateRelativeWidth(20.f);
            float y = m_Base->m_Container->Position().Y() + _UTILITY CalculateRelativeHeight(110.f);
            float w = _UTILITY CalculateRelativeWidth(2020.f) -
                      2 * _UTILITY CalculateRelativeWidth(20.f);
            float h = _UTILITY CalculateRelativeHeight(830.f);
            MRKUIRect(ctx, x, y, w, h);
            MRKUIFill(ctx);
            MRKUIFontFace(ctx, _GUI MRKFont::Exo2Bold->FontFaceStr);
            MRKUIFontSize(ctx, _UTILITY CalculateRelativeFont(64));
            MRKUITextAlign(ctx, MRKUI_ALIGN_TOP | MRKUI_ALIGN_LEFT);
            float tx = x + _UTILITY CalculateRelativeWidth(20.f);
            float ty = y + _UTILITY CalculateRelativeHeight(20.f);
            for (int i = 0; i < 3; i++) {
                MRKUIFillColor(ctx, &MRKColor((3 - (i + 1)) * 85, 255));
                MRKUIText(ctx, tx - (i + 1), ty - (i + 1), "Console", 0);
            }
            MRKUIFillColor(ctx, &MRKColor::White);
            MRKUIText(ctx, tx, ty, "Console", 0);
            MRKUIFontSize(ctx, _UTILITY CalculateRelativeFont(21.f));
            ty += _UTILITY CalculateRelativeHeight(80.f);
            MRKUIFontFace(ctx, _GUI MRKFont::Exo2Regular->FontFaceStr);
            unsigned int maxB = (unsigned int) fmin(m_Logs->size(), m_ScrollValue + 30);
            if (m_ScrollValue > maxB - 30)
                m_ScrollValue = maxB - 30;
            for (unsigned int i = m_ScrollValue; i < maxB; i++) {
                MRKLogEntry *entry = &(*m_Logs)[i];
                MRKUIFillColor(ctx, entry->Type == MRK_LOGTYPE_INFO ? &MRKColor::White :
                                    entry->Type == MRK_LOGTYPE_ERROR ? &MRKColor(255, 0, 0, 255)
                                                                     : &MRKColor(255, 255, 0, 255));
                MRKUIText(ctx, tx + _UTILITY CalculateRelativeWidth(10.f), ty,
                          _UTILITY concat("[", entry->Time, "] ",
                                          entry->Type == MRK_LOGTYPE_INFO ? "[INFO] ["
                                                                          : entry->Type ==
                                                                            MRK_LOGTYPE_ERROR
                                                                            ? "[ERROR] ["
                                                                            : "[WARNING] [",
                                          entry->Sender, "]").c_str(), 0);
                MRKUIText(ctx, tx + _UTILITY CalculateRelativeWidth(400.f), ty, entry->Msg.c_str(),
                          0);
                ty += _UTILITY CalculateRelativeFont(21.f);
            }
            MRKUIClosePath(ctx);
        }

        MRKGuiComponentBaseDT2_REF::LogView::LogView(MRKGuiComponentBaseDT2_REF *base) {
            m_Base = base;
            m_Logs = GetRecentLogs();
            m_ScrollValue = 0;
        }

        unsigned int &MRKGuiComponentBaseDT2_REF::LogView::ScrollOffset() {
            return m_ScrollValue;
        }
    }
}