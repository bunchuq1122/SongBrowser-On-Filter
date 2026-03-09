#include <Geode/Geode.hpp>
#include <Geode/modify/MoreSearchLayer.hpp>
#include <Geode/modify/GJSongBrowser.hpp>

using namespace geode::prelude;

class $modify(uh, MoreSearchLayer) {
	bool init() {
		if (!MoreSearchLayer::init()) return false;
		auto menu = m_buttonMenu;
		auto btn = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_musicLibraryBtn_001.png"),
			this,
			menu_selector(uh::onHi)
		);
		btn->setPosition({
			355.f, -222.f
		});
		menu->addChild(btn);
		
		return true;;
	}	
	void onHi(CCObject* s) {
		auto sb = GJSongBrowser::create();
		CCDirector::sharedDirector()->getRunningScene()->addChild(sb, 106);
		sb->showLayer(false);
	}
};
