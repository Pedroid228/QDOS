#include "QDOS_HUD.h"
#include "Blueprint/UserWidget.h"
#include "QDOS_Widget/QDOS_Widget.h"

// AQDOS_HUD
//------------------------------------------------------------------------------------------------------------
AQDOS_HUD::AQDOS_HUD()
{
}
//------------------------------------------------------------------------------------------------------------
void AQDOS_HUD::BeginPlay()
{
	UWorld *world = 0;
	APlayerController *player_controller = 0;

	Super::BeginPlay();
	
	check(QDOS_Widget_BP_Class != 0);

	world = GetWorld();
	check(world != 0);

	player_controller = world->GetFirstPlayerController();
	check(player_controller != 0);
	
	QDOS_Widget = CreateWidget<UQDOS_Widget>(world, QDOS_Widget_BP_Class);
	QDOS_Widget->AddToViewport();
	QDOS_Widget->SetVisibility(ESlateVisibility::Visible);
	player_controller->SetShowMouseCursor(true);
}
//------------------------------------------------------------------------------------------------------------
