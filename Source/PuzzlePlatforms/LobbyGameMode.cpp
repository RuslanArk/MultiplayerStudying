// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

DEFINE_LOG_CATEGORY_STATIC(LogLobbyGameMode, All, All);

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	++NumberOfPlayers;

	if (NumberOfPlayers >= 3)
	{
		UWorld* World = GetWorld();
		if (!World) return;

		bUseSeamlessTravel = true;
		World->ServerTravel("/Game/PuzzlePlatforms/Maps/MainLevel?listen");
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	--NumberOfPlayers;
}
