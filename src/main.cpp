
#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(LayoutForgeEditor, EditorUI) {
    struct Fields {
        bool generatorOpened = false;
    };

    void onModify(auto& self) {
        (void)self.setHookPriority("EditorUI::init", Priority::Late);
    }

    bool init(LevelEditorLayer* editorLayer) {
        if (!EditorUI::init(editorLayer)) {
            return false;
        }

        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_createBtn_001.png"),
            this,
            menu_selector(LayoutForgeEditor::openGenerator)
        );

        if (button) {
            button->setID("layoutforge-generator"_spr);

            auto menu = CCMenu::create();
            menu->addChild(button);
            menu->setPosition({35.f, 90.f});

            this->addChild(menu);
        }

        return true;
    }

    void openGenerator(CCObject*) {
        FLAlertLayer::create(
            "LayoutForge",
            "LayoutForge is ready to generate layouts!",
            "OK"
        )->show();
    }
};
