#include <SFGUI/Engines/BREW.hpp>
#include <SFGUI/RenderQueue.hpp>
#include <SFGUI/Window.hpp>
#include <SFGUI/Button.hpp>
#include <SFGUI/Entry.hpp>
#include <SFGUI/Scale.hpp>
#include <SFGUI/Scrollbar.hpp>
#include <SFGUI/ScrolledWindow.hpp>
#include <SFGUI/ToggleButton.hpp>
#include <SFGUI/CheckButton.hpp>
#include <SFGUI/ProgressBar.hpp>
#include <SFGUI/Separator.hpp>
#include <SFGUI/Frame.hpp>
#include <SFGUI/Image.hpp>
#include <SFGUI/Notebook.hpp>
#include <SFGUI/Spinner.hpp>
#include <SFGUI/ComboBox.hpp>

#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cmath>

namespace sfg {
namespace eng {

BREW::BREW() :
	Engine()
{
	// Set defaults.
	SetProperty( "*", "Color", sf::Color( 0xc6, 0xcb, 0xc4 ) );
	SetProperty( "*", "FontSize", 12 );
	SetProperty( "*", "FontName", "" ); // Uses SFML's default font when empty.
	SetProperty( "*", "BackgroundColor", sf::Color( 0x46, 0x46, 0x46 ) );
	SetProperty( "*", "BorderColor", sf::Color( 0x66, 0x66, 0x66 ) );
	SetProperty( "*", "BorderColorShift", 0x20 );
	SetProperty( "*", "BorderWidth", 1.f );
	SetProperty( "*", "Padding", 5.f );
	SetProperty( "*", "Thickness", 2.f );

	// Window-specific.
	SetProperty( "Window", "Gap", 10.f );
	SetProperty( "Window", "BorderColor", sf::Color( 0x5a, 0x6a, 0x50 ) );
	SetProperty( "Window", "BorderColorShift", 0 );
	SetProperty( "Window", "TitleBackgroundColor", sf::Color( 0x5a, 0x6a, 0x50 ) );
	SetProperty( "Window", "TitlePadding", 5.f );
	SetProperty( "Window", "HandleSize", 10.f );
	SetProperty( "Window", "ShadowDistance", 3.f );
	SetProperty( "Window", "ShadowAlpha", 100.f );

	// Button-specific.
	SetProperty( "Button", "BackgroundColor", sf::Color( 0x55, 0x57, 0x52 ) );
	SetProperty( "Button", "BorderColor", sf::Color( 0x55, 0x57, 0x52 ) );
	SetProperty( "Button", "Spacing", 5.f );
	SetProperty( "Button:PRELIGHT", "BackgroundColor", sf::Color( 0x65, 0x67, 0x62 ) );
	SetProperty( "Button:PRELIGHT", "Color", sf::Color::White );
	SetProperty( "Button:ACTIVE", "BackgroundColor", sf::Color( 0x55, 0x55, 0x55 ) );
	SetProperty( "Button:ACTIVE", "Color", sf::Color::Black );

	// ToggleButton-specific.
	SetProperty( "ToggleButton", "BackgroundColor", sf::Color( 0x55, 0x57, 0x52 ) );
	SetProperty( "ToggleButton", "BorderColor", sf::Color( 0x55, 0x57, 0x52 ) );
	SetProperty( "ToggleButton", "Padding", 5.f );
	SetProperty( "ToggleButton:PRELIGHT", "BackgroundColor", sf::Color( 0x65, 0x67, 0x62 ) );
	SetProperty( "ToggleButton:PRELIGHT", "Color", sf::Color::White );
	SetProperty( "ToggleButton:ACTIVE", "BackgroundColor", sf::Color( 0x55, 0x55, 0x55 ) );
	SetProperty( "ToggleButton:ACTIVE", "Color", sf::Color::Black );

	// CheckButton-specific.
	SetProperty( "CheckButton", "Spacing", 5.f );
	SetProperty( "CheckButton", "BoxSize", 14.f );
	SetProperty( "CheckButton", "CheckSize", 6.f );
	SetProperty( "CheckButton", "BorderColor", sf::Color( 0x55, 0x57, 0x52 ) );
	SetProperty( "CheckButton", "BackgroundColor", sf::Color( 0x36, 0x36, 0x36 ) );
	SetProperty( "CheckButton", "CheckColor", sf::Color( 0x9e, 0x9e, 0x9e ) );
	SetProperty( "CheckButton:PRELIGHT", "BackgroundColor", sf::Color( 0x46, 0x46, 0x46 ) );
	SetProperty( "CheckButton:ACTIVE", "BackgroundColor", sf::Color( 0x56, 0x56, 0x56 ) );

	// Entry-specific.
	SetProperty( "Entry", "BackgroundColor", sf::Color( 0x5e, 0x5e, 0x5e ) );
	SetProperty( "Entry", "Color", sf::Color::White );

	// Scale-specific.
	SetProperty( "Scale", "SliderColor", sf::Color( 0x68, 0x6a, 0x65 ) );
	SetProperty( "Scale", "SliderLength", 15.f );
	SetProperty( "Scale", "TroughColor", sf::Color( 0x70, 0x70, 0x70 ) );
	SetProperty( "Scale", "TroughWidth", 5.f );

	// Scrollbar-specific.
	SetProperty( "Scrollbar", "SliderColor", sf::Color( 0x68, 0x6a, 0x65 ) );
	SetProperty( "Scrollbar", "TroughColor", sf::Color( 0x70, 0x70, 0x70 ) );
	SetProperty( "Scrollbar", "StepperBackgroundColor", sf::Color( 0x68, 0x6a, 0x65 ) );
	SetProperty( "Scrollbar", "StepperArrowColor", sf::Color( 0xd9, 0xdc, 0xd5 ) );
	SetProperty( "Scrollbar", "StepperSpeed", 10.f );
	SetProperty( "Scrollbar", "StepperRepeatDelay", 300 );
	SetProperty( "Scrollbar", "SliderMinimumLength", 15.f );

	// ScrolledWindow-specific.
	SetProperty( "ScrolledWindow", "ScrollbarWidth", 20.f );
	SetProperty( "ScrolledWindow", "ScrollbarSpacing", 5.f );
	SetProperty( "ScrolledWindow", "BorderColor", sf::Color( 0x55, 0x57, 0x52 ) );

	// ProgressBar-specific.
	SetProperty( "ProgressBar", "BackgroundColor", sf::Color( 0x36, 0x36, 0x36 ) );
	SetProperty( "ProgressBar", "BorderColor", sf::Color( 0x55, 0x57, 0x52 ) );
	SetProperty( "ProgressBar", "BarColor", sf::Color( 0x67, 0x89, 0xab ) );
	SetProperty( "ProgressBar", "BarBorderColor", sf::Color( 0x67, 0x89, 0xab ) );
	SetProperty( "ProgressBar", "BarBorderColorShift", 0x20 );
	SetProperty( "ProgressBar", "BarBorderWidth", 1.f );

	// Separator-specific.
	SetProperty( "Separator", "Color", sf::Color( 0x75, 0x77, 0x72 ) );

	// Frame-specific.
	SetProperty( "Frame", "BorderColor", sf::Color( 0x75, 0x77, 0x72 ) );
	SetProperty( "Frame", "Padding", 7.f );
	SetProperty( "Frame", "LabelPadding", 5.f );

	// Notebook-specific.
	SetProperty( "Notebook", "BorderColor", sf::Color( 0x50, 0x52, 0x4D ) );
	SetProperty( "Notebook", "BackgroundColor", sf::Color( 0x4C, 0x4C, 0x4C ) );
	SetProperty( "Notebook", "BackgroundColorDark", sf::Color( 0x42, 0x42, 0x42 ) );
	SetProperty( "Notebook", "BackgroundColorPrelight", sf::Color( 0x48, 0x48, 0x48 ) );

	// Spinner-specific.
	SetProperty( "Spinner", "CycleDuration", 800.f );
	SetProperty( "Spinner", "Steps", 13 );
	SetProperty( "Spinner", "StoppedAlpha", 47 );

	// ComboBox-specific.
	SetProperty( "ComboBox", "BackgroundColor", sf::Color( 0x55, 0x57, 0x52 ) );
	SetProperty( "ComboBox", "BorderColor", sf::Color( 0x55, 0x57, 0x52 ) );
	SetProperty( "ComboBox", "HighlightedColor", sf::Color( 0x65, 0x67, 0x62 ) );
	SetProperty( "ComboBox", "ArrowColor", sf::Color( 0xc6, 0xcb, 0xc4 ) );
	SetProperty( "ComboBox", "ItemPadding", 4.f );
	SetProperty( "ComboBox:PRELIGHT", "BackgroundColor", sf::Color( 0x65, 0x67, 0x62 ) );
	SetProperty( "ComboBox:ACTIVE", "BackgroundColor", sf::Color( 0x55, 0x55, 0x55 ) );
}

RenderQueue* BREW::CreateBorder( const sf::FloatRect& rect, float border_width, const sf::Color& light_color, const sf::Color& dark_color ) {
	sf::FloatRect rounded_rect(
		std::floor( rect.Left + .5f ),
		std::floor( rect.Top + .5f ),
		std::floor( rect.Width + .5f ),
		std::floor( rect.Height + .5f )
	);

	border_width = std::floor( border_width + .5f );

	RenderQueue* queue( new RenderQueue );
	queue->Add( CreateLine( TOP, sf::Vector2f( rect.Left, rect.Top ), sf::Vector2f( rect.Left + rect.Width, rect.Top ), light_color, border_width ) );
	queue->Add( CreateLine( RIGHT, sf::Vector2f( rect.Left + rect.Width, rect.Top ), sf::Vector2f( rect.Left + rect.Width, rect.Top + rect.Height ), dark_color, border_width ) );
	queue->Add( CreateLine( BOTTOM, sf::Vector2f( rect.Left, rect.Top + rect.Height ), sf::Vector2f( rect.Left + rect.Width, rect.Top + rect.Height ), dark_color, border_width ) );
	queue->Add( CreateLine( LEFT, sf::Vector2f( rect.Left, rect.Top ), sf::Vector2f( rect.Left, rect.Top + rect.Height ), light_color, border_width ) );

	return queue;
}

RenderQueue* BREW::CreateSlider( const sf::FloatRect& rect, sf::Color& background, float border_width, const sf::Color& light_color, const sf::Color& dark_color ) {
	RenderQueue* queue( new RenderQueue );

	// Align rect to pixels
	sf::FloatRect aligned_rect;
	aligned_rect.Left = std::floor( rect.Left + .5f );
	aligned_rect.Top = std::floor( rect.Top + .5f );
	aligned_rect.Width = std::floor( rect.Width + .5f );
	aligned_rect.Height = std::floor( rect.Height + .5f );

	queue->Add( CreateBackground( aligned_rect, background ) );
	queue->Add( CreateBorder( aligned_rect, border_width, light_color, dark_color ) ); // Border

	return queue;
}

RenderQueue* BREW::CreateStepper( const sf::FloatRect& rect, sf::Color& background, float border_width, const sf::Color& light_color, const sf::Color& dark_color, bool pressed ) {
	RenderQueue* queue( new RenderQueue );

	// Align rect to pixels
	sf::FloatRect aligned_rect;
	aligned_rect.Left = std::floor( rect.Left + .5f );
	aligned_rect.Top = std::floor( rect.Top + .5f );
	aligned_rect.Width = std::floor( rect.Width + .5f );
	aligned_rect.Height = std::floor( rect.Height + .5f );

	queue->Add( CreateBackground( aligned_rect, background ) );

	if( pressed ) {
		queue->Add( CreateBorder( aligned_rect, border_width, dark_color, light_color ) );
	}
	else {
		queue->Add( CreateBorder( aligned_rect, border_width, light_color, dark_color ) );
	}

	return queue;
}

sf::Shape* BREW::CreateBackground( const sf::FloatRect& rect, const sf::Color& color ) {
	sf::ConvexShape* shape = new sf::ConvexShape( 4 );
	shape->SetPoint( 0, sf::Vector2f( rect.Left, rect.Top ) );
	shape->SetPoint( 1, sf::Vector2f( rect.Left, rect.Top + rect.Height ) );
	shape->SetPoint( 2, sf::Vector2f( rect.Left + rect.Width, rect.Top + rect.Height ) );
	shape->SetPoint( 3, sf::Vector2f( rect.Left + rect.Width, rect.Top ) );
	shape->SetFillColor( color );
	shape->SetOutlineColor( sf::Color::Transparent );

	return shape;
}

sf::Shape* BREW::CreateLine( Edge where, const sf::Vector2f& from, const sf::Vector2f& to, const sf::Color& color, float thickness ) {
	if( where == RIGHT ) {
		sf::ConvexShape* right( new sf::ConvexShape( 4 ) );
		right->SetFillColor( color );
		right->SetOutlineColor( sf::Color::Transparent );
		right->SetPoint( 0, from );
		right->SetPoint( 1, sf::Vector2f( from.x - thickness, from.y + thickness ) );
		right->SetPoint( 2, sf::Vector2f( to.x - thickness, to.y - thickness ) );
		right->SetPoint( 3, to );
		return right;
	}
	else if( where == BOTTOM ) {
		sf::ConvexShape* bottom( new sf::ConvexShape( 4 ) );
		bottom->SetFillColor( color );
		bottom->SetOutlineColor( sf::Color::Transparent );
		bottom->SetPoint( 0, from );
		bottom->SetPoint( 1, to );
		bottom->SetPoint( 2, sf::Vector2f( to.x - thickness, to.y - thickness ) );
		bottom->SetPoint( 3, sf::Vector2f( from.x + thickness, from.y - thickness ) );
		return bottom;
	}
	else if( where == LEFT ) {
		sf::ConvexShape* left( new sf::ConvexShape( 4 ) );
		left->SetFillColor( color );
		left->SetOutlineColor( sf::Color::Transparent );
		left->SetPoint( 0, from );
		left->SetPoint( 1, to );
		left->SetPoint( 2, sf::Vector2f( to.x + thickness, to.y - thickness ) );
		left->SetPoint( 3, sf::Vector2f( from.x + thickness, from.y + thickness ) );
		return left;
	}
	else if( where == TOP ) {
		sf::ConvexShape* top( new sf::ConvexShape( 4 ) );
		top->SetFillColor( color );
		top->SetOutlineColor( sf::Color::Transparent );
		top->SetPoint( 0, to );
		top->SetPoint( 1, from );
		top->SetPoint( 2, sf::Vector2f( from.x + thickness, from.y + thickness ) );
		top->SetPoint( 3, sf::Vector2f( to.x - thickness, to.y + thickness ) );
		return top;
	}

	return NULL;
}

}
}
