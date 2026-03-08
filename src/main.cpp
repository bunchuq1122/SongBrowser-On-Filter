#include <Geode/Geode.hpp>
#include <Geode/modify/MoreSearchLayer.hpp>
#include <Geode/modify/GJSongBrowser.hpp>

using namespace geode::prelude;

class $modify(uh, MoreSearchLayer) {
	bool init() {
		if (!MoreSearchLayer::init()) return false;
		auto menu = CCMenu::create();
		auto btn = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_musicLibraryBtn_001.png"),
			this,
			menu_selector(uh::onHi)
		);
		menu->addChild(btn);
		auto winSize = CCDirector::sharedDirector()->getWinSize();
		menu->setPosition({
			winSize.width / 2 + 140 , winSize.height / 2 - 90
		});
		menu->setTouchPriority(-600);
		m_mainLayer->addChild(menu);
		return true;;
	}	
	void onHi(CCObject* s) {
		auto sb = GJSongBrowser::create();
		CCDirector::sharedDirector()->getRunningScene()->addChild(sb, 106);
		sb->showLayer(false);
	}
};
