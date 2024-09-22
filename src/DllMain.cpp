static float prevVal{};

void Set(app::player::PlayerHsmContext* ctx) {
	auto* playerCollision = ctx->playerObject->GetComponent<app::player::GOCPlayerCollider>()->GetPlayerCollision();

	prevVal = playerCollision->qword2C;
	playerCollision->qword2C = 0.2f;
}

void Unset(app::player::PlayerHsmContext* ctx) {
	ctx->playerObject->GetComponent<app::player::GOCPlayerCollider>()->GetPlayerCollision()->qword2C = prevVal;
}

HOOK(void, __fastcall, StateSliding_Enter, 0x140968B40, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int prevState) {
	originalStateSliding_Enter(self, ctx, prevState);
	Set(ctx);
}

HOOK(void, __fastcall, StateSliding_Leave, 0x140969140, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int nextState) {
	Unset(ctx);
	originalStateSliding_Leave(self, ctx, nextState);
}

HOOK(void, __fastcall, StateSquat_Enter, 0x140968FA0, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int prevState) {
	originalStateSquat_Enter(self, ctx, prevState);
	Set(ctx);
}

HOOK(void, __fastcall, StateSquat_Leave, 0x140969200, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int nextState) {
	Unset(ctx);
	originalStateSquat_Leave(self, ctx, nextState);
}

HOOK(void, __fastcall, StateSpin_Enter, 0x140965BB0, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int prevState) {
	originalStateSpin_Enter(self, ctx, prevState);
	Set(ctx);
}

HOOK(void, __fastcall, StateSpin_Leave, 0x140965C90, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int nextState) {
	Unset(ctx);
	originalStateSpin_Leave(self, ctx, nextState);
}

HOOK(void, __fastcall, StateSpinBoost_Enter, 0x140966CA0, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int prevState) {
	originalStateSpinBoost_Enter(self, ctx, prevState);
	Set(ctx);
}

HOOK(void, __fastcall, StateSpinBoost_Leave, 0x140967230, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int nextState) {
	Unset(ctx);
	originalStateSpinBoost_Leave(self, ctx, nextState);
}

HOOK(void, __fastcall, StateSpinDash_Enter, 0x140967B60, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int prevState) {
	originalStateSpinDash_Enter(self, ctx, prevState);
	Set(ctx);
}

HOOK(void, __fastcall, StateSpinDash_Leave, 0x140967D60, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int nextState) {
	Unset(ctx);
	originalStateSpinDash_Leave(self, ctx, nextState);
}

HOOK(void, __fastcall, StateSpinMove_Enter, 0x140968450, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int prevState) {
	originalStateSpinMove_Enter(self, ctx, prevState);
	Set(ctx);
}

HOOK(void, __fastcall, StateSpinMove_Leave, 0x1409685D0, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int nextState) {
	Unset(ctx);
	originalStateSpinMove_Leave(self, ctx, nextState);
}

HOOK(void, __fastcall, StateDropDash_Enter, 0x140956AE0, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int prevState) {
	originalStateDropDash_Enter(self, ctx, prevState);
	Set(ctx);
}

HOOK(void, __fastcall, StateDropDash_Leave, 0x140956CA0, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int nextState) {
	Unset(ctx);
	originalStateDropDash_Leave(self, ctx, nextState);
}

HOOK(void, __fastcall, StateDriftDash_Enter, 0x1409562A0, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int prevState) {
	originalStateDriftDash_Enter(self, ctx, prevState);
	Set(ctx);
}

HOOK(void, __fastcall, StateDriftDash_Leave, 0x140956450, app::player::PlayerStateBase* self, app::player::PlayerHsmContext* ctx, int nextState) {
	Unset(ctx);
	originalStateDriftDash_Leave(self, ctx, nextState);
}

BOOL WINAPI DllMain(_In_ HINSTANCE hInstance, _In_ DWORD reason, _In_ LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		INSTALL_HOOK(StateSliding_Enter);
		INSTALL_HOOK(StateSliding_Leave);
		INSTALL_HOOK(StateSquat_Enter);
		INSTALL_HOOK(StateSquat_Leave);
		INSTALL_HOOK(StateSpin_Enter);
		INSTALL_HOOK(StateSpin_Leave);
		INSTALL_HOOK(StateSpinBoost_Enter);
		INSTALL_HOOK(StateSpinBoost_Leave);
		INSTALL_HOOK(StateSpinDash_Enter);
		INSTALL_HOOK(StateSpinDash_Leave);
		INSTALL_HOOK(StateSpinMove_Enter);
		INSTALL_HOOK(StateSpinMove_Leave);
		INSTALL_HOOK(StateDropDash_Enter);
		INSTALL_HOOK(StateDropDash_Leave);
		INSTALL_HOOK(StateDriftDash_Enter);
		INSTALL_HOOK(StateDriftDash_Leave);
		break;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}
