bool comp(node a, node b)
{
	if (a.x < b.x) return true;
	else if (a.x > b.x) return false;
	return a.y > b.y;
}
