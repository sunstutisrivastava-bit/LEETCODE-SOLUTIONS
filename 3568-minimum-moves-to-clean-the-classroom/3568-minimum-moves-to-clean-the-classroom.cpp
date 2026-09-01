class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int,int>> litter;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0)
            return 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        int totalMask = (1 << k) - 1;

        /*
            visited state:

            cell + mask + energy

            Instead of vector<vector<vector<vector<bool>>>>,
            use one flat vector.
        */

        int cells = m * n;
        int masks = 1 << k;

        long long totalStates = 1LL * cells * masks * (energy + 1);

        vector<bool> visited(totalStates, false);

        auto getID = [&](int r, int c, int mask, int e) {

            return ((long long)(r * n + c) * masks + mask)
                   * (energy + 1) + e;
        };

        struct State {
            short r;
            short c;
            short mask;
            short e;
            int moves;
        };

        queue<State> q;

        q.push({(short)sr, (short)sc, 0, (short)energy, 0});

        visited[getID(sr, sc, 0, energy)] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            State cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int mask = cur.mask;
            int e = cur.e;
            int moves = cur.moves;

            if (mask == totalMask)
                return moves;

            // Can't move without energy
            if (e == 0)
                continue;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {

                    int idx = id[nr][nc];

                    nmask |= (1 << idx);
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                long long stateID = getID(nr, nc, nmask, ne);

                if (!visited[stateID]) {

                    visited[stateID] = true;

                    q.push({
                        (short)nr,
                        (short)nc,
                        (short)nmask,
                        (short)ne,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};