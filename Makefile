.PHONY: pull-upstream sync-upstream commit help check-git
.DEFAULT_GOAL := help

# Git branch detection
CURRENT_BRANCH := $(shell git rev-parse --abbrev-ref HEAD 2>/dev/null)
UPSTREAM_REMOTE := upstream
ORIGIN_REMOTE := origin
# Detect upstream default branch (main or master) - computed at runtime in sync-upstream

help:
	@echo "Available targets:"
	@echo "  pull-upstream  - Fetch latest changes from upstream and origin remotes"
	@echo "  sync-upstream  - Pull upstream changes and merge into current branch"
	@echo "  commit         - Sync with upstream then commit (use: make commit MESSAGE='your message' [FILES='file1 file2'])"

# Check if we're in a git repository
check-git:
	@if [ ! -d .git ]; then \
		echo "Error: Not in a git repository"; \
		exit 1; \
	fi

# Pull latest changes from upstream remote
pull-upstream: check-git
	@echo "Fetching latest changes from ${UPSTREAM_REMOTE}..."
	@git fetch ${UPSTREAM_REMOTE} || (echo "Warning: Failed to fetch from ${UPSTREAM_REMOTE}" && exit 1)
	@echo "Fetching latest changes from ${ORIGIN_REMOTE}..."
	@git fetch ${ORIGIN_REMOTE} || (echo "Warning: Failed to fetch from ${ORIGIN_REMOTE}" && exit 1)
	@echo "Fetch complete."

# Sync with upstream: merge upstream branch into current branch
sync-upstream: pull-upstream
	@if [ -z "${CURRENT_BRANCH}" ]; then \
		echo "Error: Could not determine current branch"; \
		exit 1; \
	fi
	@UPSTREAM_BRANCH=$$(git symbolic-ref refs/remotes/${UPSTREAM_REMOTE}/HEAD 2>/dev/null | sed "s@^refs/remotes/${UPSTREAM_REMOTE}/@@") || UPSTREAM_BRANCH="main"; \
	echo "Current branch: ${CURRENT_BRANCH}"; \
	echo "Merging ${UPSTREAM_REMOTE}/$${UPSTREAM_BRANCH} into ${CURRENT_BRANCH}..."; \
	if ! git merge ${UPSTREAM_REMOTE}/$${UPSTREAM_BRANCH}; then \
		echo ""; \
		echo "ERROR: Merge conflict detected!"; \
		echo "Please resolve conflicts manually, then run:"; \
		echo "  git add <resolved-files>"; \
		echo "  git commit"; \
		exit 1; \
	fi; \
	echo "Successfully merged upstream changes."

# Commit target that syncs upstream first
commit: sync-upstream
	@if [ -z "${MESSAGE}" ]; then \
		echo "Error: MESSAGE is required."; \
		echo "Usage: make commit MESSAGE='your commit message' [FILES='file1 file2']"; \
		exit 1; \
	fi
	@if [ -n "${FILES}" ]; then \
		echo "Staging files: ${FILES}"; \
		git add ${FILES}; \
	else \
		echo "Staging all modified files..."; \
		git add -A; \
	fi
	@echo "Committing with message: ${MESSAGE}"
	@git commit -m "${MESSAGE}" || \
		(echo "Error: Commit failed. Check if there are changes to commit." && exit 1)
	@echo "Commit successful. Use 'git push' to push changes."
